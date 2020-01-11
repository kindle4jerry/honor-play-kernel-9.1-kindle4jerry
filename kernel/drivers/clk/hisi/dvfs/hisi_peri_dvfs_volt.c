/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#include <linux/module.h>
#include <linux/delay.h>
#include <linux/io.h>
#include <linux/err.h>
#include <linux/slab.h>
#include <linux/spinlock.h>
#include <linux/hwspinlock.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_device.h>
#include "../hisi-clk-mailbox.h"
#include "peri_volt_internal.h"
#ifdef CONFIG_HISI_PERI_VOLT_HW_VOTE
#include <linux/hisi/hisi_hw_vote.h>
#endif

enum {
	HS_PMCTRL,
};

enum {
	PERI_VOLT_0 = 0,
	PERI_VOLT_1,
	PERI_VOLT_2,
	PERI_VOLT_3,
};

#define SC_SCBAKDATA24_ADDR		0x46C
#define AVS_BITMASK_FLAG		28
#define PERIVOLT_POLL_HWLOCK 			19
#define HWLOCK_TIMEOUT				1000
#define PMCTRL_PERI_CTRL4_VDD_MASK		0x30000000
#define PMCTRL_PERI_CTRL4_TEMPERATURE_MASK		0xC000000
#define PMCTRL_PERI_CTRL4_VDD_SHIFT		28
#define PMCTRL_PERI_CTRL4_TEMPERATURE_SHIFT		26
#define PMCTRL_PERI_CTRL4_ON_OFF_MASK		0xC0000000
#define USB_POLL_ID				28
#define LPM3_CMD_CLOCK_EN                       0x000D0002
/*#define LPM3_CMD_CLOCK_DIS                      0x000D0102*/
#define FAST_AVS_ID                             13
#define NORMAL_TEMPRATURE		0
static struct hwspinlock        *peri_poll_hwlock;
static int count;

struct perivolt {
	void __iomem    *pmctrl;
	spinlock_t      lock;
};
static struct perivolt perivolt = {
	.lock = __SPIN_LOCK_UNLOCKED(perivolt.lock),
};
static void __iomem *perivolt_get_base(struct device_node *np);

#ifdef CONFIG_HISI_PERI_VOLT_HW_VOTE
#define PERI_DVFS_HW_VOTE_CH_NAME     "peri-volt"
#define PERI_DVFS_HW_VOTE_CH_SRC      "vote-src-1"
#define PERI_DVFS_HW_VOTE_VOTE_FLAG   "peri_dvfs_hw_vote_flag"
#define PERI_DVFS_HW_VOTE_RATIO       (1000)
#define PERI_DVFS_DVFS_ID_SHIFT       (8)
#define PERI_DVFS_AVS_ID_SHIFT        (4)
#define PERI_DVFS_HW_VOTE_MASK        (0x7FFF)
static struct hvdev *peri_dvfs_hvdev = NULL;
static unsigned int get_perivolt_hv_value(unsigned int dvfs_id, unsigned int avs_id, unsigned int volt)
{
	unsigned int hv_val = 0;

	/* field_name   bit_range   val_range
	 *   volt         [ 3:0]       0~15
	 *   avs_id       [ 7:4]       0~15
	 *   dvfs_id      [14:8]      0~127
	 */
	hv_val = ((dvfs_id << PERI_DVFS_DVFS_ID_SHIFT) | (avs_id << PERI_DVFS_AVS_ID_SHIFT) | volt);
	/* make sure that hv_value NOT exceed to 0x7FFF */
	hv_val = (hv_val & PERI_DVFS_HW_VOTE_MASK);
	/* hisi_hv_set_freq interface requirement: should multiply ratio(=1000) */
	hv_val = (hv_val * PERI_DVFS_HW_VOTE_RATIO);
	pr_debug("[%s] dvfs_id: %u, avs_id: %u volt: %u, hv_val: %u\n", __func__,
			dvfs_id, avs_id, volt, hv_val);

	return hv_val;
}
static int peri_dvfs_hw_vote(struct peri_volt_poll *pvp, unsigned int target_volt)
{
	int ret = 0;
	unsigned int last_hv_val = 0;
	unsigned int hv_val = 0;
	unsigned int new_hv_val = 0;
	unsigned int hv_result = 0;

	if (IS_ERR_OR_NULL(peri_dvfs_hvdev)) {
		pr_err("[%s] peri dvfs hw vote device is nul!\n", __func__);
		return -EINVAL;
	}

	/* get old hw vote */
	ret = hisi_hv_get_freq(peri_dvfs_hvdev, &last_hv_val);
	if (ret) {
		pr_err("[%s] get last peri_hw_vote volt fail!\n", __func__);
	}

	/* peri_volt hw vote */
	hv_val = get_perivolt_hv_value(pvp->dev_id, pvp->perivolt_avs_ip, target_volt);
	ret = hisi_hv_set_freq(peri_dvfs_hvdev, hv_val);
	if (ret) {
		pr_err("[%s] set peri_hw_vote volt fail!\n", __func__);
		return ret;
	}

	/* get hw vote readback */
	ret = hisi_hv_get_freq(peri_dvfs_hvdev, &new_hv_val);
	if (ret) {
		pr_err("[%s] get last peri_hw_vote volt fail!\n", __func__);
	}

	/* get hw vote finally result */
	ret = hisi_hv_get_result(peri_dvfs_hvdev, &hv_result);
	if (ret) {
		pr_err("[%s] get last peri_hw_vote volt fail!\n", __func__);
	}

	pr_debug("[%s] pvp_id:%d, last_hv_val: %d, hv_val: %d, hv_val_rb: %d, hv_result: %d\n",
			__func__, pvp->dev_id, last_hv_val, hv_val, new_hv_val, hv_result);

	return ret;
}
#endif

#ifdef CONFIG_HISI_PERI_FAST_AVS
static int peri_fast_avs(struct peri_volt_poll *pvp, unsigned int target_volt)
{
	int ret = 0;
	u32 val = 0;
	u32 fast_avs_cmd[LPM3_CMD_LEN] = {LPM3_CMD_CLOCK_EN, FAST_AVS_ID};

	if (target_volt > PERI_VOLT_0) {
		val = (readl(pvp->addr_0) & PMCTRL_PERI_CTRL4_VDD_MASK);
		val = val >> PMCTRL_PERI_CTRL4_VDD_SHIFT;
		if (val < target_volt) {
			ret = hisi_clkmbox_send_msg(fast_avs_cmd);
			if (ret < 0) {
				pr_err("[%s]fail to send fast avs msg to LPM3!\n",
					__func__);
			}
		}
	}
	return ret;
}
#endif

#ifdef CONFIG_HISI_PERI_AVS_IPC_NOTIFY
static int peri_avs_ipc_notify_m3(struct peri_volt_poll *pvp, unsigned int target_volt)
{
	int ret = 0;
	u32 val = 0;
	u32 avs_ipc_cmd[LPM3_CMD_LEN] = {LPM3_CMD_CLOCK_EN, FAST_AVS_ID};
	/*send ipc for avs ip do not care scene*/
	if (pvp->perivolt_avs_ip) {
		ret = hisi_clkmbox_send_msg(avs_ipc_cmd);
		if (ret < 0) {
			pr_err("[%s]fail to notify LPM3 for avs ip !\n",
				__func__);
		}
		return ret;
	}

	/*volt up: send ipc immediately
	 *volt down:volt will be change 5ms later by ddr dvfs
	 */
	if (target_volt > PERI_VOLT_0) {
		val = (readl(pvp->addr_0) & PMCTRL_PERI_CTRL4_VDD_MASK);
		val = val >> PMCTRL_PERI_CTRL4_VDD_SHIFT;
		if (val < target_volt) {
			ret = hisi_clkmbox_send_msg(avs_ipc_cmd);
			if (ret < 0) {
				pr_err("[%s]fail to notify LPM3 for non-avs  ip!\n",
					__func__);
			}
		}
	}
	return ret;
}

#ifdef CONFIG_HISI_PERI_VOLT_HW_VOTE
static int peri_avs_hv_notify_m3(struct peri_volt_poll *pvp, unsigned int target_volt)
{
	int ret = 0;

	/* DVFS(AVS) hw vote */
	ret = peri_dvfs_hw_vote(pvp, target_volt);
	if (ret) {
		pr_err("[%s] peri dvfs hw volt fail!\n", __func__);
		return ret;
	}

	return ret;
}
#endif /*CONFIG_HISI_PERI_VOLT_HW_VOTE*/

static int peri_avs_notify_m3(struct peri_volt_poll *pvp, unsigned int target_volt)
{
	int ret = 0;

#ifdef CONFIG_HISI_PERI_VOLT_HW_VOTE
	if (!IS_ERR_OR_NULL(peri_dvfs_hvdev)) {
		ret = peri_avs_hv_notify_m3(pvp, target_volt);
		return ret;
	}
#endif
	ret = peri_avs_ipc_notify_m3(pvp, target_volt);

	return ret;
}
#endif /*CONFIG_HISI_PERI_AVS_IPC_NOTIFY*/

static int hisi_peri_set_volt(struct peri_volt_poll *pvp, unsigned int volt)
{
	unsigned int val = 0;
	int ret = 0;
#ifdef CONFIG_HISI_CLK_LOW_TEMPERATURE_JUDGE_BY_VOLT
	int temprature = 0;
#endif

	if (hwspin_lock_timeout((struct hwspinlock *)pvp->priv,
					HWLOCK_TIMEOUT)) {
		pr_err("pvp hwspinlock timout!\n");
		return -ENOENT;
	}

#ifdef CONFIG_HISI_CLK_LOW_TEMPERATURE_JUDGE_BY_VOLT
	/*read pmctrl 0x350 bit 27:26,value of bit 27:26 is
	 *	 not 0: low temprature
	 *	 0: normal temprature
	 */
	if(PERI_VOLT_3 == volt){
		temprature = readl(pvp->addr_0);
		temprature &= PMCTRL_PERI_CTRL4_TEMPERATURE_MASK;
		temprature = temprature >> PMCTRL_PERI_CTRL4_TEMPERATURE_SHIFT;
		if(NORMAL_TEMPRATURE != temprature){
			if(pvp->dev_id != USB_POLL_ID){
				hwspin_unlock((struct hwspinlock *)pvp->priv);
				pr_err("low temprature and set volt fail!\n");
				return -EPERM;
			}else{
				/* low temprature usb set 0.75V */
				volt = PERI_VOLT_2;
			}
		}

	}
#endif

    if(volt <= PERI_VOLT_3){
		val = readl(pvp->addr);
		val &= (~(pvp->bitsmask));
		val |= (volt << pvp->bitsshift);
		writel(val, pvp->addr);
    }else{
		hwspin_unlock((struct hwspinlock *)pvp->priv);
		return -EINVAL;
    }

#ifdef CONFIG_HISI_PERI_FAST_AVS
	/*fast avs*/
	if (!(readl(pvp->addr_0) & PMCTRL_PERI_CTRL4_ON_OFF_MASK))
		ret = peri_fast_avs(pvp, volt);
#endif

#ifdef CONFIG_HISI_PERI_AVS_IPC_NOTIFY
	if(pvp->perivolt_avs_ip){
		/*clear avs status*/
		val = readl(pvp->sysreg_base + SC_SCBAKDATA24_ADDR);
		val = val & (~BIT(AVS_BITMASK_FLAG));
		writel(val, pvp->sysreg_base + SC_SCBAKDATA24_ADDR);
	}
	/*avs send ipc to notify lpm3*/
	ret = peri_avs_notify_m3(pvp, volt);
#endif
	hwspin_unlock((struct hwspinlock *)pvp->priv);

	return ret;
}

static int hisi_peri_get_temprature(struct peri_volt_poll *pvp)
{
	unsigned int temprature = 0;
	int ret = 0;

	if (hwspin_lock_timeout((struct hwspinlock *)pvp->priv,
					HWLOCK_TIMEOUT)) {
		pr_err("pvp hwspinlock timout!\n");
		return -ENOENT;//lint !e570
	}
	temprature = readl(pvp->addr_0);
	temprature &= PMCTRL_PERI_CTRL4_TEMPERATURE_MASK;
	temprature = temprature >> PMCTRL_PERI_CTRL4_TEMPERATURE_SHIFT;
	if(NORMAL_TEMPRATURE == temprature) {
		ret = 0;
	} else {
		ret = -1;
	}

	hwspin_unlock((struct hwspinlock *)pvp->priv);
	return ret;
}

static unsigned int hisi_peri_get_volt(struct peri_volt_poll *pvp)
{
	unsigned int ret = 0;

	if (hwspin_lock_timeout((struct hwspinlock *)pvp->priv,
					HWLOCK_TIMEOUT)) {
		pr_err("pvp hwspinlock timout!\n");
		return -ENOENT;//lint !e570
	}
	ret = readl(pvp->addr_0);
	ret &= PMCTRL_PERI_CTRL4_VDD_MASK;
	ret = ret >> PMCTRL_PERI_CTRL4_VDD_SHIFT;
	WARN_ON(ret > PERI_VOLT_3);

	hwspin_unlock((struct hwspinlock *)pvp->priv);

	return ret;
}

static unsigned int hisi_peri_poll_stat(struct peri_volt_poll *pvp)
{
	unsigned int ret0, ret1 = 0;

	if (hwspin_lock_timeout((struct hwspinlock *)pvp->priv,
					HWLOCK_TIMEOUT)) {
		pr_err("pvp hwspinlock timout!\n");
		return -ENOENT;//lint !e570
	}
	ret0 = readl(pvp->addr_0);
	ret0 &= (~(PMCTRL_PERI_CTRL4_VDD_MASK | PMCTRL_PERI_CTRL4_ON_OFF_MASK));
	ret1 = readl(pvp->addr);
	ret1 &= 0xFFFFFFFF;
	ret1 &= ret0;

	hwspin_unlock((struct hwspinlock *)pvp->priv);
	return ret1;
}

static void hisi_peri_dvfs_init(struct peri_volt_poll *pvp, unsigned int endis)
{
	if (count)
		return;
	if (hwspin_lock_timeout((struct hwspinlock *)pvp->priv,
					HWLOCK_TIMEOUT)) {
		pr_err("pvp hwspinlock timout!\n");
		return;
	}
	if (0 == endis) {
		/*maintain*/
	}
	hwspin_unlock((struct hwspinlock *)pvp->priv);
	count++;
}

static struct peri_volt_ops hisi_peri_volt_ops = {
	.set_volt = hisi_peri_set_volt,
	.get_volt = hisi_peri_get_volt,
	.recalc_volt = hisi_peri_get_volt,
	.get_poll_stat = hisi_peri_poll_stat,
	.get_temperature = hisi_peri_get_temprature,
	.init = hisi_peri_dvfs_init,
};

static void peri_volt_poll_init(struct device_node *np)
{
	struct peri_volt_poll *pvolt;
	const char *poll_name;
	void __iomem *reg_base;
	u32 pdata[2] = {0};
	u32 ctrl4_reg = 0;
	u32 perivolt_id = 0;
	u32 perivolt_avs_ip = 0;
	int ret = 0;
	struct device_node *dev_np;

	reg_base = perivolt_get_base(np);
	if (!reg_base) {
		pr_err("[%s] fail to get reg_base!\n", __func__);
		return;
	}
	if (of_property_read_string(np, "perivolt-output-names", &poll_name)) {
		pr_err("[%s] %s node doesn't have output-names property!\n",
			 __func__, np->name);
		return;
	}
	if (of_property_read_u32_array(np, "perivolt-poll-reg", &pdata[0], 2)) {
		pr_err("[%s] %s node doesn't have perivolt-poll-reg property!\n",
			 __func__, np->name);
		return;
	}
	if (of_property_read_u32(np, "perivolt-poll-lpmcu", &ctrl4_reg)) {
		pr_err("[%s] %s node doesn't have perivolt-poll-lpmcu property!\n",
			 __func__, np->name);
		return;
	}
	if (of_property_read_u32_array(np, "perivolt-poll-id", &perivolt_id, 1)) {
		pr_err("[%s] %s node doesn't have perivolt-poll-id property\n",
			 __func__, np->name);
	}
	if (of_property_read_u32(np, "perivolt-avs-ip", &perivolt_avs_ip))
		perivolt_avs_ip = 0;
	pvolt = kzalloc(sizeof(struct peri_volt_poll), GFP_KERNEL);
	if (!pvolt) {
		pr_err("[%s] fail to alloc pvolt!\n", __func__);
		return;
	}
	pvolt->name = kstrdup(poll_name, GFP_KERNEL);
	pvolt->dev_id = perivolt_id;
	pvolt->perivolt_avs_ip = perivolt_avs_ip;
	pvolt->addr = reg_base + pdata[0];
	pvolt->addr_0 = reg_base + ctrl4_reg;
	dev_np = of_find_compatible_node(NULL, NULL, "hisilicon,sysctrl");
	pvolt->sysreg_base = of_iomap(dev_np, 0);
	pvolt->bitsmask = pdata[1];
	pvolt->bitsshift = ffs(pdata[1]) - 1;
	pvolt->ops = &hisi_peri_volt_ops;
	pvolt->volt = PERI_VOLT_0;
	pvolt->flags = PERI_GET_VOLT_NOCACHE;
	pvolt->priv = peri_poll_hwlock;
	pvolt->stat = 0;
	ret = perivolt_register(NULL, pvolt);
	if (ret) {
		pr_err("[%s] fail to reigister pvp %s!\n",
			__func__, poll_name);
		goto err_pvp;
	}
	pr_info("[%s] peri dvfs node:%s\n", __func__, poll_name);
err_pvp:
	kfree(pvolt);
	pvolt = NULL;
	return;
}

PERIVOLT_OF_DECLARE(hisi_perivolt, "hisilicon,soc-peri-volt", peri_volt_poll_init)

static const struct of_device_id perivolt_of_match[] = {
	{ .compatible = "hisilicon,soc-peri-dvfs", .data = (void *)HS_PMCTRL, },
    {},/*lint !e785 */
};
static void __iomem *perivolt_get_base(struct device_node *np)
{
	struct device_node *parent;
	const struct of_device_id *match;
	void __iomem *ret = NULL;

	parent = of_get_parent(np);
	if (!parent) {
		pr_err("[%s] node %s doesn't have parent node!\n", __func__, np->name);
		goto out;
	}
	match = of_match_node(perivolt_of_match, parent);
	if (!match) {
		pr_err("[%s] parent node %s doesn't match!\n", __func__, parent->name);
		goto out;
	}
	switch ((uintptr_t)match->data) {
	case HS_PMCTRL:
	if (!perivolt.pmctrl) {
		ret = of_iomap(parent, 0);
		WARN_ON(!ret);
		perivolt.pmctrl = ret;
	} else {
		ret = perivolt.pmctrl;
	}
	break;
	default:
		pr_err("[%s] cannot find the match node!\n", __func__);
		ret = NULL;
	}
out:
	return ret;
}

extern struct of_device_id __perivolt_of_table[];

static const struct of_device_id __perivolt_of_table_sentinel
	__used __section(__perivolt_of_table_end);

static int hisi_peri_volt_poll_probe(struct platform_device *pdev)
{
	struct device_node *np;
	struct device_node *parent = pdev->dev.of_node;
	const struct of_device_id *matches = NULL;
	of_perivolt_init_cb_t perivolt_init_cb = NULL;

#ifdef CONFIG_HISI_PERI_VOLT_HW_VOTE
	if (of_property_read_bool(parent, PERI_DVFS_HW_VOTE_VOTE_FLAG)) {
		peri_dvfs_hvdev = hisi_hvdev_register(&pdev->dev,
					PERI_DVFS_HW_VOTE_CH_NAME, PERI_DVFS_HW_VOTE_CH_SRC);
		if (IS_ERR_OR_NULL(peri_dvfs_hvdev)) {
			pr_err("[%s] pvp request hw vote device failed!\n", __func__);
			return -ENODEV;
		}
	}
#endif

	peri_poll_hwlock = hwspin_lock_request_specific(PERIVOLT_POLL_HWLOCK);
	if (NULL == peri_poll_hwlock) {
		pr_err("pvp request hwspin lock failed !\n");
		return -ENODEV;
	}
	count = 0;
	matches = __perivolt_of_table;

	for_each_child_of_node(parent, np) {
		const struct of_device_id *match = of_match_node(matches, np);
		perivolt_init_cb = match->data;//lint !e158
		perivolt_init_cb(np);
	}

	platform_set_drvdata(pdev, NULL);
	pr_info("[%s] sucess!\n", __func__);
	return 0;
}

static int hisi_peri_volt_poll_remove(struct platform_device *pdev)
{
#ifdef CONFIG_HISI_PERI_VOLT_HW_VOTE
	if (!IS_ERR_OR_NULL(peri_dvfs_hvdev) && hisi_hvdev_remove(peri_dvfs_hvdev) != 0) {
		pr_err("[%s] remove hw vote device failed!\n", __func__);
	}
#endif
	return 0;
}

static struct of_device_id hisi_pvp_of_match[] = {
	{ .compatible = "hisilicon,soc-peri-dvfs" },
	{ },
};
MODULE_DEVICE_TABLE(of, hisi_pvp_of_match);

static struct platform_driver hisi_peri_volt_poll_driver = {
	.probe		= hisi_peri_volt_poll_probe,
	.remove		= hisi_peri_volt_poll_remove,
	.driver		= {
		.name	= "hisi_perivolt",
		.owner	= THIS_MODULE,
		.of_match_table	= of_match_ptr(hisi_pvp_of_match),
	},
};

static int __init hisi_peri_volt_poll_init(void)
{
	return platform_driver_register(&hisi_peri_volt_poll_driver);
}
fs_initcall(hisi_peri_volt_poll_init);

MODULE_LICENSE("GPL v2");
