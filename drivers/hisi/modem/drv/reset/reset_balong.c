/*
 * Copyright (C) Huawei Technologies Co., Ltd. 2012-2015. All rights reserved.
 * foss@huawei.com
 *
 * If distributed as part of the Linux kernel, the following license terms
 * apply:
 *
 * * This program is free software; you can redistribute it and/or modify
 * * it under the terms of the GNU General Public License version 2 and
 * * only version 2 as published by the Free Software Foundation.
 * *
 * * This program is distributed in the hope that it will be useful,
 * * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * * GNU General Public License for more details.
 * *
 * * You should have received a copy of the GNU General Public License
 * * along with this program; if not, write to the Free Software
 * * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Otherwise, the following license terms apply:
 *
 * * Redistribution and use in source and binary forms, with or without
 * * modification, are permitted provided that the following conditions
 * * are met:
 * * 1) Redistributions of source code must retain the above copyright
 * *    notice, this list of conditions and the following disclaimer.
 * * 2) Redistributions in binary form must reproduce the above copyright
 * *    notice, this list of conditions and the following disclaimer in the
 * *    documentation and/or other materials provided with the distribution.
 * * 3) Neither the name of Huawei nor the names of its contributors may
 * *    be used to endorse or promote products derived from this software
 * *    without specific prior written permission.
 *
 * * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/kthread.h>
#include <linux/slab.h>
#include <linux/reboot.h>
#include <linux/delay.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/hisi/hisi_rproc.h>
#include <linux/hisi/hifidrvinterface.h>
#include <product_config.h>
#include <adrv.h>
#include <acore_nv_stru_drv.h>
#include <mdrv_sync.h>
#include <bsp_fiq.h>
#include <bsp_ipc.h>
#include <bsp_icc.h>
#include <bsp_dump.h>
#include <bsp_dsp.h>
#include <bsp_nvim.h>
#include <bsp_hardtimer.h>
#include <bsp_reset.h>
#include <bsp_sec_call.h>
#include <bsp_llt_gcov.h>
#include "../loadm/load_image.h"
#include "reset_balong.h"

/*lint --e{746, 732, 516, 958, 666} */
static unsigned int scbakdata13_offset = 0;
extern int bsp_sync_reset(SYNC_MODULE_E u32Module);
static modem_reset_e modem_reset_fail_id = MODEM_RESET_DRV_ERR;
#define LPM3_RRPOC_ID HISI_RPROC_LPM3_MBX16
#define MODEM_POWER_TIMEOUT  (35000)

struct modem_reset_ctrl g_modem_reset_ctrl = {0};
struct modem_reset_debug g_reset_debug = {0};
extern void ccore_ipc_enable(void);
extern void ccore_ipc_disable(void);
u32 modem_reset_fail_id_get(void)
{
	return (u32)modem_reset_fail_id;
}

void reset_reboot_system(enum RESET_TYPE type)
{
	unsigned long flags = 0;

	bsp_reset_bootflag_set(CCORE_BOOT_NORMAL);

	spin_lock_irqsave(&g_modem_reset_ctrl.action_lock, flags);
	g_modem_reset_ctrl.modem_action = INVALID_MODEM_ACTION;
	spin_unlock_irqrestore(&g_modem_reset_ctrl.action_lock, flags);

	osl_sem_up(&(g_modem_reset_ctrl.action_sem));
}

s32 reset_prepare(enum MODEM_ACTION action)
{
	unsigned long flags = 0;
	u32 current_action = (u32)action;
	u32 global_action = g_modem_reset_ctrl.modem_action;

	if (current_action == global_action)
	{
		return RESET_OK;
	}
	else if (((u32)MODEM_NORMAL != global_action) && ((u32)INVALID_MODEM_ACTION != global_action))
	{
		reset_print_err("action(%d) is doing, abundon action(%d)\n", global_action, action);
		return RESET_ERROR;
	}

	g_reset_debug.main_stage = 0;

	__pm_stay_awake(&(g_modem_reset_ctrl.wake_lock));
	cp_reset_timestamp_dump(RESET_DUMP_PREPARE);
	reset_print_debug("(%d) wake_lock\n", ++g_reset_debug.main_stage);

	spin_lock_irqsave(&g_modem_reset_ctrl.action_lock, flags);
	g_modem_reset_ctrl.modem_action = action;
	spin_unlock_irqrestore(&g_modem_reset_ctrl.action_lock, flags);

	if ((MODEM_POWER_OFF ==  current_action) || (MODEM_RESET ==  current_action))
	{
		ccore_ipc_disable();
	}
	osl_sem_up(&(g_modem_reset_ctrl.task_sem));

	return RESET_OK;/*lint !e454 */
}

extern s32 bsp_dlock_reset_cb(DRV_RESET_CB_MOMENT_E eparam, int usrdata);
extern int cshell_mode_reset_cb(DRV_RESET_CB_MOMENT_E eparam, int usrdata);
extern s32 bsp_rfile_reset_cb(DRV_RESET_CB_MOMENT_E eparam, s32 usrdata);
extern s32 bsp_icc_channel_reset(DRV_RESET_CB_MOMENT_E stage, int usrdata);
extern void ipc_modem_reset_cb(DRV_RESET_CB_MOMENT_E eparam, int usrdata);
extern s32 bsp_mem_ccore_reset_cb(DRV_RESET_CB_MOMENT_E enParam, int userdata);
static inline s32 bsp_loadps_reset_cb(DRV_RESET_CB_MOMENT_E eparam, s32 userdata){return 0;}

s32 icc_channel_reset (DRV_RESET_CB_MOMENT_E stage, int userdata)
{
	s32 ret;

	ret = bsp_icc_channel_reset(stage, userdata);
	if (0 != ret)
	{
		reset_print_err("icc_ns channel reset fail");
		return RESET_ERROR;
	}

	cp_reset_timestamp_dump(RESET_DUMP_SECCALL_RESET_START);
	ret = bsp_sec_call(FUNC_ICC_CHANNEL_RESET, (unsigned int)userdata);
	if (BSP_ERROR == ret)
	{
		reset_print_err("icc_s channel reset fail");
		return RESET_ERROR;
	}
	cp_reset_timestamp_dump(RESET_DUMP_SECCALL_RESET_END);
	reset_print_debug("icc channel reset succeed\n");

	return RESET_OK;
}

s32 drv_reset_cb (DRV_RESET_CB_MOMENT_E stage, int userdata)
{
	s32 ret;

	switch(stage)
	{
		case MDRV_RESET_CB_BEFORE:

			(void)bsp_loadps_reset_cb(stage, 0);

			ret = bsp_rfile_reset_cb(stage, 0);
			if (0 != ret)
			{
				goto fail;
			}

			(void)bsp_mem_ccore_reset_cb(stage, 0);

			break;

		case MDRV_RESET_RESETTING:
			(void)bsp_loadps_reset_cb(stage, 0);

			ipc_modem_reset_cb(stage, 0);
			/* ��C��drv����֮��icc��Ҫ׼���� */
			ccore_msg_switch_on(g_modem_reset_ctrl.multicore_msg_switch, CCORE_STATUS);

			ret = bsp_rfile_reset_cb(stage, 0);
			if (0 != ret)
			{
				goto fail;
			}

			cp_reset_timestamp_dump(RESET_DUMP_SECCALL_ON_START);
			ret = bsp_sec_call(FUNC_ICC_MSG_SWITCH_ON, 0);
			if (BSP_ERROR == ret)
			{
				goto fail;
			}
			cp_reset_timestamp_dump(RESET_DUMP_SECCALL_ON_END);

			break;

		case MDRV_RESET_CB_AFTER:
			(void)bsp_mem_ccore_reset_cb(stage, 0);

			ret = bsp_icc_channel_reset(stage, 0);
			if (0 != ret)
			{
				goto fail;
			}

			(void)bsp_loadps_reset_cb(stage, 0);


			break;

		default:
			break;
	}

	return RESET_OK;

fail:
	reset_print_err("drv cb func run fail, err_code=0x%x\n", ret);
	return RESET_ERROR;
}

s32 invoke_reset_cb(DRV_RESET_CB_MOMENT_E stage)
{
	struct reset_cb_list *p = g_modem_reset_ctrl.list_head;
	s32 ret = RESET_OK;

	reset_print_debug("(%d) @reset %d\n", ++g_reset_debug.main_stage, (u32)stage);

	/*���ݻص��������ȼ������ûص�����*/
    while (NULL != p)
    {
        if (NULL != p->cb_info.cbfun)
        {
            reset_print_debug("%s callback invoked\n", p->cb_info.name);
            cp_reset_invoke_dump(p->cb_info.name);
            ret = p->cb_info.cbfun(stage, p->cb_info.userdata);
            if (RESET_OK != ret)
            {
                if (p->cb_info.priolevel != DRV_RESET_CB_PIOR_IPF)
                    modem_reset_fail_id = MODEM_RESET_NAS_CB_ERR;
                reset_print_err("fail to run cbfunc of %s, at stage%d return %d\n", p->cb_info.name, stage, ret);
                cp_reset_invoke_dump(p->cb_info.name);
                return RESET_ERROR;
            }
        }
        p = p->next;
    }

	return ret;
}

s32 send_sync_msg_to_mcore(u32 reset_info, u32 *ack_val)
{
	s32 ret = 0;
	/*�����modem���ڸ�λ״̬�������AP��IPC*/
	/*ap receive mabx 0,send mbx 13*/
	rproc_msg_t tx_buffer[2] ;
	rproc_msg_t ack_buffer[2] ;
	/*���ͱ�־������LPM3�Ͻ���ʱ����*/
	tx_buffer[0] = (0<<24|9<<16|3<<8);
	tx_buffer[1] = reset_info;
	ret = RPROC_SYNC_SEND(LPM3_RRPOC_ID, tx_buffer, 2, ack_buffer, 2);
	if (ret)
	{
		*ack_val = (u32)-1;
	}
	else
	{
		/* coverity[uninit_use] */
		*ack_val = (u32)ack_buffer[1];
	}
	return ret;
}


s32 send_msg_to_hifi(DRV_RESET_CB_MOMENT_E stage)
{
	s32 ret = RESET_ERROR;
	u32 val = ~0x0;

	cp_reset_timestamp_dump(RESET_DUMP_HIFI_START);
	reset_print_debug("(%d) stage%d,ID_AP_HIFI_CCPU_RESET_REQ=%d\n", ++g_reset_debug.main_stage, (s32)stage, (s32)ID_AP_HIFI_CCPU_RESET_REQ);

	if (MDRV_RESET_CB_BEFORE == stage)
	{
		/*��ϢID*/
        ret = bsp_reset_core_notify(BSP_HIFI, ID_AP_HIFI_CCPU_RESET_REQ, 5000, &val);
        switch(ret)
        {
            case BSP_RESET_NOTIFY_REPLY_OK:
                if(!val)
                {
                    reset_print_debug("(%d) has received the reply from hifi\n", ++g_reset_debug.main_stage);
                }
                else
                {
                    modem_reset_fail_id = MODEM_RESET_HIFI_CB_ERR;
                    reset_print_err("unkown msg from hifi\n");
                    reset_reboot_system(RESET_TYPE_RECV_HIFI_MSG_FAIL);
                }
                break;
            case BSP_RESET_NOTIFY_SEND_FAILED:
                modem_reset_fail_id = MODEM_RESET_HIFI_CB_ERR;
                reset_print_err("send_msg_to_hifi=0x%x fail\n", ret);
                reset_reboot_system(RESET_TYPE_SEND_MSG2_M3_FAIL_BEFORE);
                break;
            case BSP_RESET_NOTIFY_TIMEOUT:
                modem_reset_fail_id = MODEM_RESET_HIFI_CB_ERR;
                reset_print_err("waiting the reply from hifi timeout(%d), but not reboot system!\n", RESET_WAIT_RESP_TIMEOUT);
                break;
            default:
                modem_reset_fail_id = MODEM_RESET_HIFI_CB_ERR;
                reset_print_err("unexpect scenario\n");
                break;
        }
	}

	/* ����б�Ҫ�������׶�Ҳ֪ͨhifi */
	cp_reset_timestamp_dump(RESET_DUMP_HIFI_END);
	return ret;
}

s32 wait_for_ccore_reset_done(u32 timeout)
{
	reset_print_debug("(%d) waiting the reply from modem A9\n", ++g_reset_debug.main_stage);

	if (osl_sem_downtimeout(&(g_modem_reset_ctrl.wait_ccore_reset_ok_sem), msecs_to_jiffies(timeout)))/*lint !e713 */
	{
		reset_print_err("Get response from ccore reset timeout within %d\n", timeout);
	    return RESET_ERROR;
	}

	reset_print_debug("(%d) has received the reply from modem A9\n", ++g_reset_debug.main_stage);
	return RESET_OK;
}

void master_in_idle_timestamp_dump(void)
{
    printk(KERN_ERR "[indedicator   ]0x%-8x [fiq_cnt       ]0x%-8x [fail_cnt     ]0x%-8x [flow_begin   ]0x%-8x\n",
    reset_stamp(STAMP_RESET_BASE_ADDR), reset_stamp(STAMP_RESET_FIQ_COUNT), reset_stamp(STAMP_RESET_IDLE_FAIL_COUNT), reset_stamp(STAMP_RESET_MASTER_ENTER_IDLE));
    printk(KERN_ERR "[nxdsp_inidle  ]0x%-8x [cipher_chn_dis]0x%-8x [cipher_inidle]0x%-8x [cipher_reset ]0x%-8x\n",
    reset_stamp(STAMP_RESET_BBE16_ENTER_IDLE),reset_stamp(STAMP_RESET_CIPHER_DISABLE_CHANNLE), reset_stamp(STAMP_RESET_CIPHER_ENTER_IDLE),reset_stamp(STAMP_RESET_CIPHER_SOFT_RESET));
    printk(KERN_ERR "[edma_reset_in ]0x%-8x [edma_dev_id   ]0x%-8x [edma_clock   ]0x%-8x [edma_stop_bus]0x%-8x\n",
    reset_stamp(STAMP_RESET_EDMA_IN),reset_stamp(STAMP_RESET_EDMA_DEV_NUM), reset_stamp(STAMP_RESET_EDMA_CHECK_CLK), reset_stamp(STAMP_RESET_EDMA_STOP_BUS));
    printk(KERN_ERR "[edma_in_idle  ]0x%-8x [edma_reset_out]0x%-8x [upacc_inidle1]0x%-8x [upacc_inidle2]0x%-8x\n",
    reset_stamp(STAMP_RESET_EDMA_ENTER_IDLE),reset_stamp(STAMP_RESET_EDMA_OUT), reset_stamp(STAMP_RESET_UPACC_ENTER_IDLE_1), reset_stamp(STAMP_RESET_UPACC_ENTER_IDLE_2));
    printk(KERN_ERR "[upacc_inidle3 ]0x%-8x [cicom0_rst    ]0x%-8x [cicom1_rst   ]0x%-8x [ipf_inidle   ]0x%-8x\n",
    reset_stamp(STAMP_RESET_UPACC_ENTER_IDLE_3),reset_stamp(STAMP_RESET_CICOM0_SOFT_RESET), reset_stamp(STAMP_RESET_CICOM1_SOFT_RESET), reset_stamp(STAMP_RESET_IPF_SOFT_RESET));
    printk(KERN_ERR "[ipf_rst       ]0x%-8x [bbp_dma_inidle]0x%-8x [wbbp_mst_stop]0x%-8x [wbbp_slv_stop]0x%-8x\n",
    reset_stamp(STAMP_RESET_IPF_ENTER_IDLE),reset_stamp(STAMP_RESET_BBP_DMA_ENTER_IDLE), reset_stamp(STAMP_RESET_WBBP_MSTER_STOP), reset_stamp(STAMP_RESET_WBBP_SLAVE_STOP));
    printk(KERN_ERR "[wbbp_inidle   ]0x%-8x [bbp_dbg       ]0x%-8x [in_out_idle  ]0x%-8x [flow_end     ]0x%-8x\n",
    reset_stamp(STAMP_RESET_WBBP_ENTER_IDLE),reset_stamp(STAMP_RESET_BBP_DEBUG),reset_stamp(STAMP_RESET_MASTER_INOUT_IDLE),reset_stamp(STAMP_RESET_MASTER_IDLE_QUIT));
    printk(KERN_ERR "[hwspinlock    ]0x%-8x [hdlc_rst      ]0x%-8x [cbbe16_inidle]0x%-8x [nv idle      ]0x%-8x\n",
    reset_stamp(STAMP_RESET_HWSPINLOCK_IDLE),reset_stamp(STAMP_RESET_HDLC_SOFT_RESET),reset_stamp(STAMP_RESET_CBBE16_ENTER_IDLE), reset_stamp(STAMP_RESET_NV_IDLE));
    printk(KERN_ERR "[bbp_harq_idle ]0x%-8x [rsracc in     ]0x%-8x [rsracc step  ]0x%-8x [rsracc out   ]0x%-8x\n",
        reset_stamp(STAMP_RESET_BBP_HARQ_IDLE),reset_stamp(STAMP_RESET_RSRACC_ENTER_IDLE),reset_stamp(STAMP_RESET_RSRACC_STEP),reset_stamp(STAMP_RESET_RSRACC_OUT_IDLE));
    printk(KERN_ERR "[fiq_in_core0  ]0x%-8x [fiq_in_core1  ]0x%-8x [nxdsp reset  ]0x%-8x [cbbe16 reset ]0x%-8x\n",
        reset_stamp(STAMP_RESET_CORE0_INFIQ),reset_stamp(STAMP_RESET_CORE1_INFIQ),reset_stamp(STAMP_RESET_NXDSP_SYSBUS_RESET),reset_stamp(STAMP_RESET_CBBE16_SYSBUS_RESET));
    printk(KERN_ERR "[nx waiti state]0x%-8x [socp mdm reset]0x%-8x\n",
        reset_stamp(STAMP_RESET_NXDSP_WAITI_STATE),reset_stamp(STAMP_RESET_SOCP_MODEM_CHAN_STATE));

    if (g_reset_debug.dump_state == (u32)RESET_DUMP_MAGIC)
    {
        /* coverity[secure_coding] */
        (void)memcpy((void*)g_reset_debug.dump_info.master_addr, (void*)STAMP_RESET_BASE_ADDR, (int)(STAMP_RESET_FIQ_OUT_COUNT - STAMP_RESET_BASE_ADDR + 1));
    }
}

s32 do_power_off(u16 action)
{
	u32 msg = 0;
	s32 ret;
	u32 ack_val = 0xff;

	/* ��������ģʽΪC�˵�����λ */
	bsp_reset_bootflag_set(CCORE_IS_REBOOT);
	g_modem_reset_ctrl.boot_mode = readl((volatile const void *)get_scbakdata13());
	cp_reset_timestamp_dump(RESET_DUMP_POWER_OFF);
	reset_print_debug("(%d) set boot mode:0x%x\n", ++g_reset_debug.main_stage, g_modem_reset_ctrl.boot_mode);

	/* ����ccore */
    (void)bsp_sync_reset(SYNC_MODULE_RESET);
	ret = bsp_ipc_int_send(IPC_CORE_CCORE, g_modem_reset_ctrl.ipc_send_irq_wakeup_ccore);
	if(ret != 0)
	{
		reset_print_err("wakeup ccore failt\n");
	}

	/* ��λǰ������ص� */
	cp_reset_timestamp_dump(RESET_DUMP_CB_BEFORE_START);
	ret = invoke_reset_cb(MDRV_RESET_CB_BEFORE);
	if(ret < 0)
	{
		reset_reboot_system(RESET_TYPE_CB_INVOKE_BEFORE);
		return RESET_ERROR;
	}
	cp_reset_timestamp_dump(RESET_DUMP_CB_BEFORE_END);

	/* ��ֹ�˼�ͨ�� */
	ccore_msg_switch_off(g_modem_reset_ctrl.multicore_msg_switch, CCORE_STATUS);

	cp_reset_timestamp_dump(RESET_DUMP_SECCALL_OFF_START);
	ret = bsp_sec_call(FUNC_ICC_MSG_SWITCH_OFF, 0);
	if (BSP_ERROR == ret)
	{
		cp_reset_timestamp_dump(RESET_DUMP_SECCALL_ERROR);
		reset_print_err("bsp_sec_call fail\n");
	}
	cp_reset_timestamp_dump(RESET_DUMP_SECCALL_OFF_END);

	reset_print_debug("(%d) switch off msg connect:%d\n", ++g_reset_debug.main_stage, g_modem_reset_ctrl.multicore_msg_switch);

	/* ֪ͨhifiֹͣ��modem�������ȴ�hifi������� */
	ret = send_msg_to_hifi(MDRV_RESET_CB_BEFORE);
	if(-1 == ret)
	{
		return RESET_ERROR;
	}

	if (BSP_OK != mdrv_sync_wait(SYNC_MODULE_RESET, msecs_to_jiffies(RESET_WAIT_CCORE_WAKEUP_REPLY_TIMEOUT)))
	{
		reset_print_err("waiting wakeup reply from ccore timeout(%d)!\n", RESET_WAIT_CCORE_WAKEUP_REPLY_TIMEOUT);
	}

	/* ֪ͨmodem master��idle̬,���ȴ�ccore�ظ� */
	if(BSP_OK != bsp_send_cp_fiq(FIQ_RESET))
	{
		reset_print_err("fiq trigger fail\n");
	}

	ret = osl_sem_downtimeout(&(g_modem_reset_ctrl.wait_modem_master_in_idle_sem),
		msecs_to_jiffies(RESET_WAIT_MODEM_IN_IDLE_TIMEOUT));/*lint !e713 */
	/*�ȴ�c�˸����������ռ����*/
	gcov_ccore_save();
	if (ret)
	{
		cp_reset_timestamp_dump(RESET_DUMP_MIDLE_TIMEOUT);
		reset_print_debug("(%d) let modem master in idle timeout\n", ++g_reset_debug.main_stage);
	}
	else
	{
		cp_reset_timestamp_dump(RESET_DUMP_MIDLE_SUCCESS);
		reset_print_debug("(%d) let modem master in idle successfully\n", ++g_reset_debug.main_stage);
	}
	ipc_modem_reset_cb(MDRV_RESET_CB_BEFORE, 0);
	master_in_idle_timestamp_dump();

	/* ֪ͨm3���и�λǰ�������� */
	msg = RESET_INFO_MAKEUP(action, MDRV_RESET_CB_BEFORE); /*lint !e701 */


	/* ��λ�⸴λmodem��ϵͳ */
	ret = send_sync_msg_to_mcore(msg, &ack_val);
	if(ret)
	{
		cp_reset_timestamp_dump(RESET_DUMP_M3_BEFORE_FAIL);
		modem_reset_fail_id = MODEM_RESET_M3_ERR;
		reset_print_err("send_sync_msg_to_mcore(0x%x) before reset fail!\n", ret);
		reset_reboot_system(RESET_TYPE_SEND_MSG2_M3_FAIL_BEFORE);
		return RESET_ERROR;
	}
	else if(RESET_MCORE_BEFORE_RESET_OK != ack_val)
	{
		cp_reset_timestamp_dump(RESET_DUMP_M3_BEFORE_ACK_FAIL);
		modem_reset_fail_id = MODEM_RESET_M3_ERR;
		reset_print_err("cp reset before error probed on m3, ack_val=0x%x\n", ack_val);
		reset_reboot_system(RESET_TYPE_SEND_MSG2_M3_FAIL_BEFORE);
		return RESET_ERROR;
	}
	cp_reset_timestamp_dump(RESET_DUMP_M3_BEFORE_SUCCEED);
	reset_print_debug("(%d) before reset stage has communicated with lpm3 succeed\n", ++g_reset_debug.main_stage);

	return RESET_OK;
}

s32 do_power_on(u16 action)
{
	u32 msg = 0;
	s32 ret;
	u32 ack_val = 0xff;
	u32 i;

	/* clear icc channel */
	ret = icc_channel_reset(MDRV_RESET_RESETTING, 0);
	if(ret != RESET_OK)
	{
		reset_reboot_system(RESET_TYPE_CB_INVOKE_RESTING);
		return RESET_ERROR;
	}

	/* C�˺�dsp������� */
	/* ����ִ�������3�Σ�ֱ��ÿ�ζ�������λϵͳ */
	cp_reset_timestamp_dump(RESET_DUMP_LOAD_IMAGE_START);
	for (i=0; i<RESET_RETRY_TIMES; i++)
	{
		ret = bsp_load_modem_images();
		if (ret == 0)
			break;
		else
			reset_print_err("Retry %d times to load modem image also failed\n", i);
	}
	if(ret < 0)
	{
		modem_reset_fail_id = MODEM_RESET_LOAD_SEC_IMAGE_ERR;
		reset_reboot_system(RESET_TYPE_LOAD_MODEM_IMG_FAIL);
		return RESET_ERROR;
	}
	cp_reset_timestamp_dump(RESET_DUMP_LOAD_IMAGE_END);

	/* ֪ͨm3���и�λ����ش��� */
	msg = RESET_INFO_MAKEUP(action, (u32)MDRV_RESET_RESETTING); /*lint !e701 */

	ret = send_sync_msg_to_mcore(msg, &ack_val);
	if(ret)
	{
		cp_reset_timestamp_dump(RESET_DUMP_M3_ING_FAIL);
		modem_reset_fail_id = MODEM_RESET_M3_ERR;
		reset_print_err("send_sync_msg_to_mcore(0x%x) at resting stage fail!\n", ret);
		reset_reboot_system(RESET_TYPE_SEND_MSG2_M3_FAIL_RESTING);
		return RESET_ERROR;
	}
	else if(RESET_MCORE_RESETING_OK != ack_val)
	{
		cp_reset_timestamp_dump(RESET_DUMP_M3_ING_ACK_FAIL);
		modem_reset_fail_id = MODEM_RESET_M3_ERR;
		reset_print_err("modem unreset fail on m3, ack_val=0x%x\n", ack_val);
		reset_reboot_system(RESET_TYPE_RECV_WRONG_MSG_FROM_M3_RESTING);
		return RESET_ERROR;
	}
	cp_reset_timestamp_dump(RESET_DUMP_M3_ING_SUCCESS);
	reset_print_debug("(%d) at reseting stage has communicated with lpm3 succeed\n", ++g_reset_debug.main_stage);

	/* ��λ����ش���:��C����Ҫ������ģ���ڴ˽׶�׼���� */
	if ((MODEM_POWER_ON == action) || (MODEM_RESET == action))
	{
		ccore_ipc_enable();
	}
	ret = drv_reset_cb(MDRV_RESET_RESETTING, 0);
	if(ret < 0)
	{
		reset_reboot_system(RESET_TYPE_CB_INVOKE_RESTING);
		return RESET_ERROR;
	}

	cp_reset_timestamp_dump(RESET_DUMP_CP_STARTUP);
	ret = wait_for_ccore_reset_done(RESET_WAIT_CCPU_STARTUP_TIMEOUT);
	if(ret < 0)
	{
		cp_reset_timestamp_dump(RESET_DUMP_CP_STARTUP_TIMEOUT);
		reset_reboot_system(RESET_TYPE_WAIT_CCORE_RELAY_TIMEOUT);
		return RESET_ERROR;
	}


	/* ��λ����ش��� */
	cp_reset_timestamp_dump(RESET_DUMP_CB_AFTER_START);
	ret = invoke_reset_cb(MDRV_RESET_CB_AFTER);
	if(ret < 0)
	{
		reset_reboot_system(RESET_TYPE_CB_INVOKE_AFTER);
		return RESET_ERROR;
	}
	cp_reset_timestamp_dump(RESET_DUMP_CB_AFTER_END);

	/* ��λ��֪ͨM3������ش��� */
	msg = RESET_INFO_MAKEUP(action, MDRV_RESET_CB_AFTER); /*lint !e701 */

	ret = send_sync_msg_to_mcore(msg, &ack_val);
	if(ret)
	{
		cp_reset_timestamp_dump(RESET_DUMP_M3_AFTER_FAIL);
		modem_reset_fail_id = MODEM_RESET_M3_ERR;
		reset_print_err("send_sync_msg_to_mcore(0x%x) after reset stage fail!\n", ret);
		reset_reboot_system(RESET_TYPE_SEND_MSG2_M3_FAIL_AFTER);
		return RESET_ERROR;
	}
	else if(RESET_MCORE_AFTER_RESET_OK != ack_val)
	{
		cp_reset_timestamp_dump(RESET_DUMP_M3_AFTER_ACK_FAIL);
		modem_reset_fail_id = MODEM_RESET_M3_ERR;
		reset_print_err("after reset handle failed on m3, ack_val=0x%x, fail!\n", ack_val);
		reset_reboot_system(RESET_TYPE_RECV_WRONG_MSG_FROM_M3_AFTER);
		return RESET_ERROR;
	}
	cp_reset_timestamp_dump(RESET_DUMP_M3_AFTER_SUCCESS);
	reset_print_debug("(%d) after reset stage has communicated with lpm3 succeed\n", ++g_reset_debug.main_stage);

	/* ������ģʽ�û���ͨģʽ */
	bsp_reset_bootflag_set(CCORE_BOOT_NORMAL);

	return RESET_OK;
}

s32 do_reset(u16 action)
{
	s32 ret;

	ret = do_power_off(action);
	if(ret < 0)
	{
		return RESET_ERROR;
	}

	ret = do_power_on(action);
	if(ret < 0)
	{
		return RESET_ERROR;
	}

	return RESET_OK;
}

int modem_reset_task(void *arg)
{
	u16 action = 0;
	unsigned long flags = 0;

	/* coverity[no_escape] */
	for( ; ;)
	{
		osl_sem_down(&(g_modem_reset_ctrl.task_sem));
		action = (u16)g_modem_reset_ctrl.modem_action;
		reset_print_debug("(%d)has taken task_sem, action=%d\n", ++g_reset_debug.main_stage, action);

		if (MODEM_POWER_OFF == action)
		{
			(void)do_power_off(action);
		}
		else if (MODEM_POWER_ON == action)
		{
			(void)do_power_on(action);
		}
		else if (MODEM_RESET == action)
		{
			(void)do_reset(action);
			reset_print_err("reset count: %d\n", ++g_modem_reset_ctrl.reset_cnt);
		}
		if (action == g_modem_reset_ctrl.modem_action)
		{
			spin_lock_irqsave(&g_modem_reset_ctrl.action_lock, flags);
			g_modem_reset_ctrl.modem_action = MODEM_NORMAL;
			spin_unlock_irqrestore(&g_modem_reset_ctrl.action_lock, flags);
		}

		osl_sem_up(&(g_modem_reset_ctrl.action_sem));
		__pm_relax(&(g_modem_reset_ctrl.wake_lock));/*lint !e455 */

		cp_reset_timestamp_dump(RESET_DUMP_END);
		g_modem_reset_ctrl.exec_time = get_timer_slice_delta(g_modem_reset_ctrl.exec_time, bsp_get_slice_value());
		reset_print_debug("execute done, elapse time %d\n", g_modem_reset_ctrl.exec_time);
	}

}

struct reset_cb_list *sort_list_insert(struct reset_cb_list *list, struct reset_cb_list *node)
{
	struct reset_cb_list *head = list;
    struct reset_cb_list *curr = list;
    struct reset_cb_list *tail = list;

    if (NULL == list || NULL == node)
    {
        return NULL;
    }
    while (NULL != curr)
    {
        /* ��С����, �����ȼ����� */
        if (curr->cb_info.priolevel > node->cb_info.priolevel)
        {
            if (head == curr)
            {
                node->next = curr;
                head = node;
            }
            else
            {
                tail->next = node;
                node->next = curr;
            }
            break;
        }
        tail = curr;
        curr = curr->next;
    }
    if (NULL == curr)
    {
        tail->next = node;
    }
    return head;
}

struct reset_cb_list *do_cb_func_register(struct reset_cb_list * list_head, const char* func_name, pdrv_reset_cbfun func, int user_data, int prior)
{
    struct reset_cb_list *cb_func_node = NULL;
	u32 name_len = 0;

    if (!func_name || !func || (prior < RESET_CBFUNC_PRIO_LEVEL_LOWT || prior > RESET_CBFUNC_PRIO_LEVEL_HIGH))
    {
        reset_print_err("register fail, name:%s, cbfun=%pK, prio=%d\n", func_name,  func, prior);
        return list_head;
    }

    cb_func_node = (struct reset_cb_list *)kmalloc(sizeof(struct reset_cb_list), GFP_KERNEL);
    if (cb_func_node)
    {
		name_len = (u32)min((u32)DRV_RESET_MODULE_NAME_LEN, (u32)strlen(func_name));
		/* coverity[secure_coding] */
		memset((void*)cb_func_node, 0, (sizeof(struct reset_cb_list)));
		/* coverity[secure_coding] */
		memcpy((void*)cb_func_node->cb_info.name, (void*)func_name, (int)name_len);
		cb_func_node->cb_info.priolevel = prior;
		cb_func_node->cb_info.userdata = user_data;
		cb_func_node->cb_info.cbfun = func;
    }
	else
	{
		reset_print_err("malloc fail\n");
		return list_head;
	}

	if (!list_head)
    {
        list_head = cb_func_node;
    }
	else
    {
        list_head = sort_list_insert(list_head, cb_func_node);
    }
	++g_modem_reset_ctrl.list_use_cnt;

    return list_head;
}

void modem_reset_do_work(struct work_struct *work)
{
	reset_print_debug("\n");
	g_modem_reset_ctrl.exec_time = bsp_get_slice_value();
	if (1 == g_modem_reset_ctrl.in_suspend_state)
	{
		if (!wait_for_completion_timeout(&(g_modem_reset_ctrl.suspend_completion), HZ*10))
		{
			machine_restart("system halt"); /* ��systemError */
			return;
		}
	}
	reset_prepare(MODEM_RESET);
}

void modem_power_off_do_work(struct work_struct *work)
{
	reset_print_debug("\n");
	if (1 == g_modem_reset_ctrl.in_suspend_state)
	{
		if (!wait_for_completion_timeout(&(g_modem_reset_ctrl.suspend_completion), HZ*10))
		{
			machine_restart("system halt"); /* todo: �Ƿ���Ҫ����system_error */
			return;
		}
	}
	reset_prepare(MODEM_POWER_OFF);
}

s32 reset_pm_notify(struct notifier_block *notify_block,
                    unsigned long mode, void *reset_unused)
{
    switch (mode)
	{
    case PM_HIBERNATION_PREPARE:
    case PM_SUSPEND_PREPARE:
        g_modem_reset_ctrl.in_suspend_state = 1;
        break;

    case PM_POST_SUSPEND:
    case PM_POST_HIBERNATION:
    case PM_POST_RESTORE:
        complete(&(g_modem_reset_ctrl.suspend_completion));
        g_modem_reset_ctrl.in_suspend_state = 0;
        break;
	default:
		break;
    }

    return 0;
}

void reset_feature_on(u32 sw)
{
	g_modem_reset_ctrl.nv_config.is_feature_on = (sw? 1: 0);
}

void reset_ril_on(u32 sw)
{
	g_modem_reset_ctrl.nv_config.is_connected_ril = (sw? 1: 0);
}

void reset_ctrl_debug_show(void)
{
	reset_print_err("in_suspend_state: 0x%x\n", g_modem_reset_ctrl.in_suspend_state);
	reset_print_err("reset_cnt       : 0x%x\n", g_modem_reset_ctrl.reset_cnt);
	reset_print_err("nv.feature_on   : 0x%x\n", g_modem_reset_ctrl.nv_config.is_feature_on);
	reset_print_err("nv.ril_flag     : 0x%x\n", g_modem_reset_ctrl.nv_config.is_connected_ril);
	reset_print_err("state           : 0x%x\n", g_modem_reset_ctrl.state);
}

void modem_power_on_do_work(struct work_struct *work)
{
	reset_print_debug("\n");
	if (1 == g_modem_reset_ctrl.in_suspend_state)
	{
		if (!wait_for_completion_timeout(&(g_modem_reset_ctrl.suspend_completion), HZ*10))
		{
			machine_restart("system halt");
			return;
		}
	}
	if(bsp_reset_is_successful(MODEM_POWER_TIMEOUT))
		reset_prepare(MODEM_POWER_ON);
}

void reset_ipc_isr_idle(u32 data)
{
	reset_print_debug("\n");
	osl_sem_up(&(g_modem_reset_ctrl.wait_modem_master_in_idle_sem));
}

void reset_ipc_isr_reboot(u32 data)
{
	reset_print_debug("\n");
	osl_sem_up(&(g_modem_reset_ctrl.wait_ccore_reset_ok_sem));
}

u32 bsp_reset_is_feature_on(void)
{
	return g_modem_reset_ctrl.nv_config.is_feature_on;
}

u32 bsp_reset_is_connect_ril(void)
{
	return g_modem_reset_ctrl.nv_config.is_connected_ril;
}

int bsp_cp_reset(void)
{
	if (0 == g_modem_reset_ctrl.state)
	{
		reset_print_err("reset is not init\n");
		return -1;
	}

	cp_reset_timestamp_dump(RESET_DUMP_START);
	if (g_reset_debug.dump_state == (u32)RESET_DUMP_MAGIC)
	{
		g_reset_debug.dump_info.invoke_addr = (char *)((unsigned long)g_reset_debug.dump_info.base_addr + CP_RESET_DUMP_INVOKE_OFFSET);
	}
	reset_print_debug("\n");
	if (g_modem_reset_ctrl.nv_config.is_feature_on)
	{
		queue_work(g_modem_reset_ctrl.reset_wq, &(g_modem_reset_ctrl.work_reset));
		return 0;
	}
	else
	{
		reset_print_err("reset fearute is off\n");
		return -1;
	}
}

void bsp_modem_power_off(void)
{
	reset_print_debug("\n");;
	if (g_modem_reset_ctrl.nv_config.is_feature_on)
	{
		queue_work(g_modem_reset_ctrl.reset_wq, &(g_modem_reset_ctrl.work_power_off));
	}
	else
	{
		reset_print_err("reset fearute is off\n");
	}
}

void bsp_modem_power_on(void)
{
	reset_print_debug("\n");;
	if (g_modem_reset_ctrl.nv_config.is_feature_on)
	{
		queue_work(g_modem_reset_ctrl.reset_wq, &(g_modem_reset_ctrl.work_power_on));
	}
	else
	{
		reset_print_err("reset fearute is off\n");
	}
}

s32 bsp_reset_cb_func_register(const char *name, pdrv_reset_cbfun func, int user_data, int prior)
{
	u32 use_cnt = 0;
	struct reset_cb_list *head = g_modem_reset_ctrl.list_head;

	use_cnt = g_modem_reset_ctrl.list_use_cnt;
	g_modem_reset_ctrl.list_head = do_cb_func_register(head, name, func, user_data, prior);
	if (use_cnt == g_modem_reset_ctrl.list_use_cnt)
	{
		return RESET_ERROR;
	}

    return RESET_OK;
}

struct modem_reset_ctrl *bsp_reset_control_get(void)
{
	return &g_modem_reset_ctrl;
}

s32 bsp_reset_ccpu_status_get(void)
{
	enum RESET_MULTICORE_CHANNEL_STATUS channel_status = CCORE_STATUS;

	if (0 == g_modem_reset_ctrl.state)
	{
		return 1;
	}
	else
	{
		return (g_modem_reset_ctrl.multicore_msg_switch & channel_status) ? 1 : 0;
	}
}

u32 bsp_reset_is_successful(u32 timeout_ms)
{
    s32 ret;
    ret = osl_sem_downtimeout(&(g_modem_reset_ctrl.action_sem), msecs_to_jiffies(timeout_ms));/*lint !e713 */
    if (ret != 0)
    {
        return 0;
    }

    return (MODEM_NORMAL == g_modem_reset_ctrl.modem_action);
}

unsigned long get_scbakdata13(void)
{
	return ((unsigned long)bsp_sysctrl_addr_byindex(sysctrl_ao) + scbakdata13_offset);
}

int __init reset_of_node_init(void)
{
	struct device_node *node = NULL;
	int ret = RESET_OK;

	node = of_find_compatible_node(NULL, NULL, "hisilicon,cp_reset_app");
	if (!node)
	{
		reset_print_err("dts node not found!\n");
		return RESET_ERROR;
	}

	ret = of_property_read_u32(node, "scbakdata13", &scbakdata13_offset);
	if(ret)
	{
		reset_print_err("read scbakdata13 from dts is failed,ret = %d!\n", ret);
		return RESET_ERROR;
	}

	return RESET_OK;
}

int __init bsp_reset_init(void)
{
	s32 ret;

	if (RESET_OK != reset_of_node_init())
	{
		reset_print_err("reset_of_node_init fail!\n");
		return RESET_ERROR;
	}

	/* coverity[secure_coding] */
	memset(&(g_modem_reset_ctrl), 0, sizeof(g_modem_reset_ctrl));
	/* coverity[secure_coding] */
	memset(&g_reset_debug, 0, sizeof(g_reset_debug));
	g_reset_debug.print_sw = 1;

	/* NV�����Ƿ�򿪵�����λ�����Լ���RIL�ĶԽ� */
	if(BSP_OK != bsp_nvm_read(NV_ID_DRV_CCORE_RESET, (u8*)&(g_modem_reset_ctrl.nv_config), sizeof(DRV_CCORE_RESET_STRU)))
	{
		reset_print_err("nv read fail, use default value\n");
	}


	bsp_reset_bootflag_set(CCORE_BOOT_NORMAL);

	/* ����acore��ccore֮��ͨ��״̬���ñ�ʶ */
	g_modem_reset_ctrl.multicore_msg_switch = 1;
	g_modem_reset_ctrl.modem_action = MODEM_NORMAL;

	osl_sem_init(0, &g_modem_reset_ctrl.action_sem);
	osl_sem_init(0, &g_modem_reset_ctrl.task_sem);
	osl_sem_init(0, &g_modem_reset_ctrl.wait_mcore_reply_sem);
	osl_sem_init(0, &g_modem_reset_ctrl.wait_mcore_reply_reseting_sem);
	osl_sem_init(0, &g_modem_reset_ctrl.wait_hifi_reply_sem);
	osl_sem_init(0, &g_modem_reset_ctrl.wait_ccore_reset_ok_sem);
	osl_sem_init(0, &g_modem_reset_ctrl.wait_modem_master_in_idle_sem);

	wakeup_source_init(&g_modem_reset_ctrl.wake_lock, "modem_reset wake");
	spin_lock_init(&g_modem_reset_ctrl.action_lock);

    g_modem_reset_ctrl.task = kthread_run(modem_reset_task,  NULL, "modem_reset");
	if(!g_modem_reset_ctrl.task)
	{
		reset_print_err("create modem_reset thread fail!\n");
		return RESET_ERROR;
	}

	ret = bsp_reset_cb_func_register("drv", drv_reset_cb, 0, DRV_RESET_CB_PIOR_ALL);
	if(ret !=  RESET_OK)
	{
		reset_print_err("register drv reset callback fail!\n");
		return RESET_ERROR;
	}

	init_completion(&(g_modem_reset_ctrl.suspend_completion));
	g_modem_reset_ctrl.pm_notify.notifier_call = reset_pm_notify;
	register_pm_notifier(&g_modem_reset_ctrl.pm_notify);

	g_modem_reset_ctrl.reset_wq = create_singlethread_workqueue("reset_wq");
	if(!g_modem_reset_ctrl.reset_wq)
	{
		reset_print_err("create reset wq fail!\n");
		system_error(DRV_ERRNO_MODEM_RST_FAIL, 0, 0, NULL, 0);
	}
	INIT_WORK(&(g_modem_reset_ctrl.work_reset), modem_reset_do_work);
	INIT_WORK(&(g_modem_reset_ctrl.work_power_off), modem_power_off_do_work);
	INIT_WORK(&(g_modem_reset_ctrl.work_power_on), modem_power_on_do_work);

	g_modem_reset_ctrl.ipc_recv_irq_idle = IPC_ACPU_INT_SRC_CCPU_RESET_IDLE;
	g_modem_reset_ctrl.ipc_recv_irq_reboot = IPC_ACPU_INT_SRC_CCPU_RESET_SUCC;
	g_modem_reset_ctrl.ipc_send_irq_wakeup_ccore = IPC_CCPU_INT_SRC_ACPU_RESET;
	if (bsp_ipc_int_connect(g_modem_reset_ctrl.ipc_recv_irq_idle, (voidfuncptr)reset_ipc_isr_idle, 0))
	{
		reset_print_err("connect idle ipc fail!\n");
		return RESET_ERROR;
	}
	if (bsp_ipc_int_enable(g_modem_reset_ctrl.ipc_recv_irq_idle))
	{
		reset_print_err("enable idle ipc fail!\n");
		return RESET_ERROR;
	}

	if (bsp_ipc_int_connect(g_modem_reset_ctrl.ipc_recv_irq_reboot, (voidfuncptr)reset_ipc_isr_reboot, 0))
	{
		reset_print_err("connect reboot ipc fail!\n");
		return RESET_ERROR;
	}
	if (bsp_ipc_int_enable(g_modem_reset_ctrl.ipc_recv_irq_reboot))
	{
		reset_print_err("enable reboot ipc fail!\n");
		return RESET_ERROR;
	}

	g_reset_debug.dump_info.base_addr = (void *)bsp_dump_register_field(DUMP_MODEMAP_CPRESET, "CP_RESET", 0, 0, CP_RESET_DUMP_SIZE, 0);
	if (NULL == g_reset_debug.dump_info.base_addr)
	{
		reset_print_err("get dump addr error,reset init continue.\n");
	}
	else
	{
		g_reset_debug.dump_info.file_head = (struct reset_dump_header *)g_reset_debug.dump_info.base_addr;/*lint !e826: (Info -- Suspicious pointer-to-pointer conversion (area too small))*/
		g_reset_debug.dump_info.file_head->magic    = (u32)RESET_DUMP_MAGIC;
		g_reset_debug.dump_info.file_head->len      = CP_RESET_DUMP_SIZE;
		g_reset_debug.dump_info.file_head->version  = 1;
		g_reset_debug.dump_info.file_head->nv_config= g_modem_reset_ctrl.nv_config;

		g_reset_debug.dump_info.entry_tbl = (u32 *)((unsigned long)g_reset_debug.dump_info.base_addr + (unsigned long)sizeof(struct reset_dump_header));
		g_reset_debug.dump_info.invoke_addr = (char *)((unsigned long)g_reset_debug.dump_info.base_addr + CP_RESET_DUMP_INVOKE_OFFSET);
		g_reset_debug.dump_info.master_addr = (char *)((unsigned long)g_reset_debug.dump_info.base_addr + CP_RESET_DUMP_MASTER_OFFSET);

		/* coverity[CONSTANT_EXPRESSION_RESULT] */
		if ((RESET_DUMP_MOD_ID_MAX*4 > CP_RESET_DUMP_INVOKE_OFFSET)
			||((STAMP_RESET_FIQ_OUT_COUNT - STAMP_RESET_BASE_ADDR + 1) > (CP_RESET_DUMP_SIZE - CP_RESET_DUMP_MASTER_OFFSET)))/*lint !e587 */
		{
			reset_print_err("dump base info too oversize, please check.\n");
			g_reset_debug.dump_state = 0;
		}
		else
		{
			g_reset_debug.dump_state = (u32)RESET_DUMP_MAGIC;
		}
	}

	g_modem_reset_ctrl.state = 1;

	reset_print_err("ok\n");

	return 0;
}

EXPORT_SYMBOL(bsp_cp_reset); /*lint !e19 */
EXPORT_SYMBOL(bsp_reset_is_successful); /*lint !e19 */
EXPORT_SYMBOL(modem_reset_fail_id_get); /*lint !e19 */
EXPORT_SYMBOL(reset_reboot_system); /*lint !e19 */
EXPORT_SYMBOL(bsp_modem_power_off); /*lint !e19 */
EXPORT_SYMBOL(bsp_modem_power_on); /*lint !e19 */
EXPORT_SYMBOL(bsp_reset_control_get); /*lint !e19 */
EXPORT_SYMBOL(bsp_reset_ccore_is_reboot); /*lint !e19 */
EXPORT_SYMBOL(get_scbakdata13); /*lint !e19 */
EXPORT_SYMBOL(reset_pm_notify); /*lint !e19 */
EXPORT_SYMBOL(reset_feature_on); /*lint !e19 */
EXPORT_SYMBOL(reset_ril_on); /*lint !e19 */
EXPORT_SYMBOL(reset_ctrl_debug_show); /*lint !e19 */
EXPORT_SYMBOL(bsp_reset_is_connect_ril); /*lint !e19 */
EXPORT_SYMBOL(bsp_reset_is_feature_on); /*lint !e19 */

module_init(bsp_reset_init); /*lint !e19*/

