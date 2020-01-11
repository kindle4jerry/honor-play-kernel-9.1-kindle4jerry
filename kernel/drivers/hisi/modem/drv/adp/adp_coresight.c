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

#include <product_config.h>

#include <osl_types.h>
#include <osl_cache.h>
#include <linux/fs.h>
#include <linux/delay.h>
#include <nv_stru_drv.h>
#include <of.h>
#include <bsp_om_enum.h>
#include <bsp_coresight.h>
#include <bsp_dump.h>
#include <bsp_slice.h>
#include <bsp_nvim.h>
#include <bsp_rfile.h>
#include <bsp_version.h>


#define CPU_NUMS                         (4)



#define BIT(nr)                         (1UL << (nr))
#define BVAL(val, n)                    (((val) & BIT(n)) >> n)

#define CS_ETM_LOCK(addr)                       \
do {                                    \
    writel(0x0, addr+MDM_CORESIGHT_LAR);            \
} while (0)
#define CS_ETM_UNLOCK(addr)                     \
do {                                    \
    writel(MDM_CORESIGHT_UNLOCK,addr+MDM_CORESIGHT_LAR);   \
} while (0)

struct mdmcp_coresight_device_info
{
    void* tmc_base;
    unsigned long tmc_phy;
    struct coresight_etb_data_head_info * etb_buf;
    const char* tmc_name;
    void* debug_base;
    void* debug_buffer;
    u32   debug_length;
    u32   index;
};
struct mdmcp_coresight_device_info g_mdmcp_coresight[CPU_NUMS];


static void* get_mdmcp_etb_buf(u32 cpu)
{
    void* addr;
    switch(cpu){
        case 0:
            addr   = (void*)bsp_dump_get_field_addr(CP_TRACE_ID(0));
            break;
        case 1:
            addr   = (void*)bsp_dump_get_field_addr(CP_TRACE_ID(1));
            break;
        case 2:
            addr   = (void*)bsp_dump_get_field_addr(CP_TRACE_ID(2));
            break;
        case 3:
            addr   = (void*)bsp_dump_get_field_addr(CP_TRACE_ID(3));
            break;
        default:
            return NULL;
    }
    return addr;
}

static void mdmcp_coresight_etb_store(u32 cpu)
{
    void*     tmc_base;
    void*     etb_buf;
    u32       reg_value;
    u32       i;
    u32*      data;
    u32       len;

    if(!g_mdmcp_coresight[cpu].tmc_base)
        return;
    if(g_mdmcp_coresight[cpu].etb_buf)
        etb_buf = g_mdmcp_coresight[cpu].etb_buf;
    else{
        etb_buf = get_mdmcp_etb_buf(cpu);
        if(!etb_buf){
            printk(KERN_ERR"get modem cp cpu%d dump buf failed!\n",cpu);
            return;
        }
        g_mdmcp_coresight[cpu].etb_buf = etb_buf;
    }
    tmc_base = g_mdmcp_coresight[cpu].tmc_base;

    if(*(u32*)etb_buf == CORESIGHT_MAGIC_NUM)
    {
        printk(KERN_ERR"modem cp cpu%d etb data has store finished,no need to store again!\n",(int)cpu);
        return;
    }

    /*��cpu�Ƿ��Ѿ��Ȳ��*/
    if(*(u32*)etb_buf == CORESIGHT_HOTPLUG_MAGICNUM)
    {
        printk(KERN_ERR"modem cp cpu%d has powerdown or hotplug,no need to store data!\n",(int)cpu);
        return;
    }


    /* unlock etb, ����ETF_LOCK_ACCESS */
    writel(0xC5ACCE55, tmc_base + 0xFB0);

    /* stop etb, ����ETF_FORMAT_FLUSH_CTRL */
    reg_value = (u32)readl(tmc_base + 0x304);
    /* FFCR StopOnFl */
    reg_value |= 1 << 12;
    /* FFCR FlushMem */
    reg_value |= 1 << 6;
    writel(reg_value, tmc_base + 0x304);

    len = (u32)readl(tmc_base+0x4)*4;

    for(i=0; i<10000; i++)
    {
        /* read etb status, ��ȡETF_STATUS */
        reg_value = (u32)readl(tmc_base + 0x304);
        /* bit2ΪTMCReadyָʾλ */
        if(0 != ((reg_value & (1 << 6)) >> 6))
        {
            break;
        }
        udelay(10);/*lint !e747 !e774 !e778*/
    }
    if(i >= 10000)
    {
        printk(KERN_ERR"ETF_STATUS register is not ready\n");
    }
    /* �ȴ�TMCReady */
    for(i=0; i<10000; i++)
    {
        /* read etb status, ��ȡETF_STATUS */
        reg_value = (u32)readl(tmc_base + 0xc);
        /* bit2ΪTMCReadyָʾλ */
        if(0 != (reg_value & 0x4))/*lint !e774*/
        {
            break;
        }
        udelay(10);/*lint !e747 !e774 !e778*/
    }

    /* ��ʱ�ж� */
    if(i >= 10000)
    {
        printk(KERN_ERR"save etb time out\n");
    }

    /* ����etb���� */
    memset((void *)etb_buf, 0x0, (unsigned long)len);
    /* lint --e{124}*/
    data = (u32*)(etb_buf + 8);/*lint !e124*/
    for(i=0; i<len/4; i++)
    {
        /* read etb, ��ȡETF_RAM_RD_DATA */
        reg_value = (u32)readl(tmc_base + 0x10);
        *data = reg_value;
        data++;
        if(reg_value == 0xffffffff)
        {
            break;
        }
    }

    /* 0-3�ֽڴ�ű�ʶ�� */
    *((u32 *)etb_buf) = (u32)CORESIGHT_MAGIC_NUM;
    /* 4-7���ֽڴ��ETB���ݳ��� */
    *((u32 *)etb_buf + 1) = i*4;

    /* lock etb, ����ETF_LOCK_ACCESS */
    writel(0x1, tmc_base + 0xFB0);

    printk(KERN_ERR"%s store success 0x%pK!\n",g_mdmcp_coresight[cpu].tmc_name,tmc_base);
}

static int mdmcp_coresight_tmc_probe(struct device_node* dev_node)
{
    u32 cpu_index=0;
    int ret;
    unsigned int phy_addr = 0;
    unsigned long sz;

    ret = of_property_read_u32(dev_node,"cpu_index",&cpu_index);
    if(ret){
        printk(KERN_ERR"read cpu_index failed,use default value! ret = %d\n",ret);
        cpu_index = 0;
    }

    if(!g_mdmcp_coresight[cpu_index].tmc_base){
        g_mdmcp_coresight[cpu_index].tmc_base = (void*)of_iomap(dev_node,0);
        sz = 1;
        (void)of_property_read_u32_array(dev_node, "reg",&phy_addr, sz);
        g_mdmcp_coresight[cpu_index].tmc_phy = phy_addr;
    }
    else
        printk(KERN_ERR"cpu %d have init before,cpu index may be error!\n",cpu_index);

    g_mdmcp_coresight[cpu_index].etb_buf = get_mdmcp_etb_buf(cpu_index);

    ret = of_property_read_string(dev_node,"coresight-name",&(g_mdmcp_coresight[cpu_index].tmc_name));
    if(ret)
        printk(KERN_ERR"read name failed! ret = %d\n",ret);

    return 0;
}

static void mdmcp_cpudebug_store(u32 cpu)
{
    int size = 0;
    int i = 0;
    u32 value = 0;
    u32* debug_base = (u32*)g_mdmcp_coresight[cpu].debug_base;
    u32* debug_buffer = (u32*)g_mdmcp_coresight[cpu].debug_buffer;

    if(!debug_buffer)
        debug_buffer = (u32*)bsp_dump_get_field_addr(DUMP_CP_DEBUGREG_CPU+cpu);

    if(debug_base && debug_buffer){
        size = g_mdmcp_coresight[cpu].debug_length / 4;

        for(i=0;i<size;i++){
            value = (u32)readl(debug_base);
            *debug_buffer = value;
            debug_base ++;
            debug_buffer ++;
        }
        cache_sync();
    }
    return;
}

static int mdmcp_cpudebug_probe(struct device_node* dev_node)
{
    u32 cpu_index=0;
    int ret;
    u32 length = 0;
    u32 phy_addr = 0;

    ret = of_property_read_u32(dev_node,"cpu_index",&cpu_index);
    if(ret){
        printk(KERN_ERR"mdmcp_cpudebug_probe,read cpu_index failed ret = %d\n",ret);
        return -1;
    }
    if(cpu_index >= CPU_NUMS){
        printk(KERN_ERR"mdmcp_cpudebug_probe,cpu_index value error cpu_index = 0x%x\n",cpu_index);
        return -1;
    }
    ret = of_property_read_u32_index(dev_node, "reg", 1, &length);
    if(ret){
        printk(KERN_ERR"mdmcp_cpudebug_probe,read register length failed ret = %d\n",ret);
        return -1;
    }
    ret = of_property_read_u32_index(dev_node, "reg", 0, &phy_addr);
    if(ret){
        printk(KERN_ERR"mdmcp_cpudebug_probe,read register base failed ret = %d\n",ret);
        return -1;
    }
    if( length && phy_addr){
        g_mdmcp_coresight[cpu_index].index = cpu_index;
        g_mdmcp_coresight[cpu_index].debug_base = (void*)ioremap(phy_addr, length);
        g_mdmcp_coresight[cpu_index].debug_buffer = (void*)bsp_dump_get_field_addr(DUMP_CP_DEBUGREG_CPU+cpu_index);
        g_mdmcp_coresight[cpu_index].debug_length = length;
    }
    else{
        printk(KERN_ERR"mdmcp_cpudebug_probe,lenght or phy addr error %d,0x%x\n",length,phy_addr);
        return -1;
    }
    return 0;

}

static struct of_device_id coresight_match[] = {
    {
        .name       = "coresight-tmc",
        .compatible = "arm,coresight-tmc,cp"
    },/*lint !e785*/
    {
        .name       = "cpu-debug",
        .compatible = "arm,r8,cpu_debug"
    },/*lint !e785*/
    {}/*lint !e785*/
};

int mdmcp_coresight_init(void)
{
    struct device_node * node;
    struct device_node * child;

    /*parse tmc node*/
    node = of_find_compatible_node(NULL, NULL, coresight_match[0].compatible);
    if(!node)
    {
        printk(KERN_ERR"can not find %s node!\n",coresight_match[0].compatible);
        return -1;
    }
    for_each_child_of_node(node, child)
    {
        mdmcp_coresight_tmc_probe(child);
    }
    node = of_find_compatible_node(NULL, NULL, coresight_match[1].compatible);
    if(node)
    {
        for_each_child_of_node(node, child)
        {
            mdmcp_cpudebug_probe(child);
        }
    }
    else
    {
        printk(KERN_ERR"can not find %s node!\n",coresight_match[1].compatible);
    }

    printk(KERN_ERR"mdmcp_coresight_init ok\n");

    return 0;

}
/*lint --e{528}*/
late_initcall(mdmcp_coresight_init);/*lint !e528*/


int bsp_coresight_stop_cp(void)
{
    int cpu;
    DRV_CORESIGHT_CFG_STRU cs_cfg = {0,};

    memset(&cs_cfg,0,sizeof(cs_cfg));

    if(bsp_nvm_read(NV_ID_DRV_CORESIGHT, (u8 *)&cs_cfg, (u32)sizeof(DRV_CORESIGHT_CFG_STRU)))
    {
        printk(KERN_ERR"read nv %d fail\n", NV_ID_DRV_CORESIGHT);
        return -1;
    }
    if(!cs_cfg.cp_enable)
    {
        printk(KERN_ERR"modem cp trace not enable\n");
        return 0;
    }

    for(cpu=0 ; cpu<CPU_NUMS ; cpu++)
    {
        mdmcp_coresight_etb_store((u32)cpu);
        mdmcp_cpudebug_store((u32)cpu);
    }

    return 0;
}

void bsp_coresight_save_cp_etb(char* dir_name)
{
    char file_name[256] = {0,};
    void* data = NULL;
    DRV_CORESIGHT_CFG_STRU cs_cfg = {0,};
    int cpu;
    int fd;
    int ret;


    if(bsp_nvm_read(NV_ID_DRV_CORESIGHT, (u8 *)&cs_cfg, (u32)sizeof(DRV_CORESIGHT_CFG_STRU)))
    {
        printk(KERN_ERR"read nv %d fail\n", NV_ID_DRV_CORESIGHT);
        return;
    }
    if(!cs_cfg.cp_store)
    {
        printk(KERN_ERR"modem cp trace not enable store\n");
        return;
    }

    for(cpu = 0; cpu < CPU_NUMS; cpu++)
    {
        memset(file_name, 0, sizeof(file_name));
        /*modem etb�����ֻ��汾����Ҫ�ϴ�apr��վ��cpu0 ���������ܼ�������*/
        if(cpu == 0)
            snprintf(file_name, sizeof(file_name), "%smodem_etb.bin", dir_name);
        else
            snprintf(file_name, sizeof(file_name), "%smodem_etb%d.bin", dir_name,cpu);

        data = get_mdmcp_etb_buf((u32)cpu);
        if(!data)
            continue;

        fd = bsp_open(file_name, O_CREAT|O_RDWR|O_SYNC, 0660);
        if(fd<0)
            continue;

        ret = bsp_write((u32)fd,data,(u32)DUMP_CP_UTRACE_SIZE);
        if(ret != DUMP_CP_UTRACE_SIZE){
            printk(KERN_ERR"write modem cp cpu%d etb data error,ret = 0x%x\n",cpu,ret);
        }
        ret = bsp_close((u32)fd);
        if(ret)
            printk(KERN_ERR"close file error ,ret = 0x%x\n",ret);
        printk(KERN_ERR" %s save success!\n",file_name);
    }
    return;
}


