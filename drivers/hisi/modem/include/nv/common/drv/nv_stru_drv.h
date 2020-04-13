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


#ifndef __DRV_NV_DEF_H__
#define __DRV_NV_DEF_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#include "nv_id_drv.h"

#ifndef __u8_defined
#define __u8_defined
typedef signed char          s8;
typedef unsigned char        u8;
typedef signed short         s16;
typedef unsigned short       u16;
typedef signed int           s32;
typedef unsigned int         u32;
typedef signed long long     s64;
typedef unsigned long long   u64;
#endif

/*****************************************************************************
 �ṹ��    : nv_protocol_base_type
 �ṹ˵��  : nv_protocol_base_type�ṹ ID= en_NV_Item_Modem_Log_Path 148
            MBB��̬ modem log·��������������������̬��modem log·����
*****************************************************************************/
/*NV ID = 50018*/
#pragma pack(push)
#pragma pack(1)
    typedef struct
    {
        s32        nvStatus;
        s8         nv_version_info[30];
    }NV_SW_VER_STRU;
#pragma pack(pop)

/*NV ID  = 0xd10b*/

typedef struct ST_PWC_SWITCH_STRU_S {

    /*����NV���ڵ͹��ĵ�������ƣ�������ЩBIT��ʱδ�ã�������ʱ�������Ϊ׼ȷ������*/
    u32 deepsleep  :1; /*bit0*/
    u32 lightsleep :1; /*bit1*/
    u32 dfs        :1; /*bit2*/
    u32 hifi       :1; /*bit3*/
    u32 drxAbb     :1; /*bit4*/
    u32 drxZspCore :1; /*bit5*/
    u32 drxZspPll  :1; /*bit6*/
    u32 drxWLBbpPll  :1; /*bit7*/
    u32 drxGBbpPll   :1; /*bit8*/
    u32 drxRf      :1; /*bit9*/
    u32 drxPa      :1; /*bit10*/
    u32 drxGuBbpPd   :1; /*bit11*/
    u32 drxDspPd     :1; /*bit12*/
    u32 drxLBbpPd    :1; /*bit13*/
    u32 drxPmuEco    :1; /*bit14*/
    u32 drxPeriPd    :1; /*bit15*/
    u32 l2cache_mntn  :1; /*bit16*/
    u32 bugChk     :1; /*bit17*/
    u32 pmuSwitch     :1; /*bit18*/
    u32 drxLdsp      :1;  /*bit 19*/
    u32 matserTDSpd  :1; /*bit20*/
    u32 tdsClk    :1;  /*bit21*/
    u32 slaveTDSpd   :1; /*bit22*/
    u32 slow         :1;/*bit23*/
    u32 ccpu_hotplug_suspend      :1;/*bit24 �˷����κ�ʱ�����γ���cpu��suspend��������ʱ�ϳ�*/
    u32 ccpu_hotplug_crg      :1;/*bit25 �˷����κ�ʱ�����κ˽���l1cache��remove smp��������ʱ�ж̣����ǵ͹���˯��ʱ��Ҫ�Ȱѱ��γ���cpu����*/
    u32 ccpu_tickless          :1;/*bit26 ccpu tickless*/
    u32 sleep_monitor_time  :4; /*bit27-30*/
    u32 reserved    :1; /*bit31*/

    /*����NV����DEBUG���µ�Ϳ�����*/
    u32 drx_pa_pd        :1; /*bit0 ���ڿ���PA�����µ�*/
    u32 drx_rfic_pd      :1; /*bit1 ���ڿ���RFIC�����µ�*/
    u32 drx_rfclk_pd     :1; /*bit2 ���ڿ���RFIC CLK�����µ�*/
    u32 drx_fem_pd       :1; /*bit3 ���ڿ���FEM�����µ�*/
    u32 drx_cbbe16_pd    :1; /*bit4 ���ڿ���CBBE16�����µ�*/
    u32 drx_bbe16_pd     :1; /*bit5 ���ڿ���BBE16�����µ�*/
    u32 drx_abb_pd       :1; /*bit6 ���ڿ���ABB�����µ�*/
    u32 drx_bbp_init     :1; /*bit7 ���ڿ���BBPĬ�Ͻ��ӵ�ȫ������*/
    u32 drx_bbppwr_pd    :1; /*bit8 ���ڿ���BBP��Դ�е����µ�*/
    u32 drx_bbpclk_pd    :1; /*bit9 ���ڿ���BBPʱ���еĿ�����*/
    u32 drx_bbp_pll      :1; /*bit10 ���ڿ���BBP_PLL�Ŀ�����*/
    u32 drx_cbbe16_pll   :1; /*bit11 ���ڿ���CBBE16_PLL�Ŀ�����*/
    u32 drx_bbe16_pll    :1; /*bit12 ���ڿ���BBE16_PLL�Ŀ�����*/
    u32 drx_bbp_reserved :1; /*bit13 bbpԤ��*/
    u32 drx_abb_gpll     :1; /*bit14 ���ڿ���ABB_GPLL�Ŀ�����*/
    u32 drx_abb_scpll    :1; /*bit15 ���ڿ���ABB_SCPLL�Ŀ�����*/
    u32 drx_abb_reserved1:1;
    u32 drx_abb_reserved2:1;
    u32 reserved2        :14; /*bit18-31 δ��*/
}ST_PWC_SWITCH_STRU;

/*NV ID = 0xd10c*/
typedef struct ST_PWC_DFS_STRU_S {
    u32 CcpuUpLimit;
    u32 CcpuDownLimit;
    u32 CcpuUpNum;
    u32 CcpuDownNum;
    u32 AcpuUpLimit;
    u32 AcpuDownLimit;
    u32 AcpuUpNum;
    u32 AcpuDownNum;
    u32 DFSTimerLen;
    u32 DFSHifiLoad;
    u32 Strategy;/*ʹ�ú��ֲ���bit0:1->200ms���ؼ��,bit0:0->4s���ؼ��;bit1:1/0��/�رո���DDR��Ƶ*/
    u32 DFSDdrUpLimit;
    u32 DFSDdrDownLimit;
    u32 DFSDdrprofile;
    u32 reserved;
}ST_PWC_DFS_STRU;

/*ID=0xd111 begin */
typedef struct
{
    u32 dump_switch    : 2; /* 00: excdump, 01: usbdump, 1x: no dump */
    u32 ARMexc         : 1; /* 2 ARM�쳣��⿪��*/
    u32 stackFlow      : 1; /* 3 ��ջ�����⿪��*/
    u32 taskSwitch     : 1; /* 4 �����л���¼����*/
    u32 intSwitch      : 1; /* 5 �жϼ�¼����*/
    u32 intLock        : 1; /* 6 ���жϼ�¼����*/
    u32 appRegSave1    : 1; /* 7 �Ĵ�����1��¼���� */
    u32 appRegSave2    : 1; /* 8 �Ĵ�����2��¼����*/
    u32 appRegSave3    : 1; /* 9 �Ĵ�����3��¼����*/
    u32 commRegSave1   : 1; /* 10 �Ĵ�����1��¼���� */
    u32 commRegSave2   : 1; /* 11 �Ĵ�����2��¼����*/
    u32 commRegSave3   : 1; /* 12 �Ĵ�����3��¼����*/
    u32 sysErrReboot   : 1; /* 13 systemError��λ����*/
    u32 reset_log      : 1; /* 14 ǿ�Ƽ�¼���أ���δʹ��*/
    u32 fetal_err      : 1; /* 15 ǿ�Ƽ�¼���أ���δʹ��*/
    u32 log_ctrl       : 2; /* bsp_trsce �������*/
    u32 dumpTextClip   : 1; /* ddr����ʱtext�βü�����*/
    u32 reserved1      : 13;
} DUMP_CFG_STRU;

typedef struct
{
    union
    {
        u32         uintValue;
        DUMP_CFG_STRU   Bits;
    } dump_cfg;

    u32 appRegAddr1;    /* ACORE����Ĵ������ַ1*/
    u32 appRegSize1;    /* ACORE����Ĵ����鳤��1*/
    u32 appRegAddr2;    /* ACORE����Ĵ������ַ2*/
    u32 appRegSize2;    /* ACORE����Ĵ����鳤��2*/
    u32 appRegAddr3;    /* ACORE����Ĵ������ַ3*/
    u32 appRegSize3;    /* ACORE����Ĵ����鳤��3*/

    u32 commRegAddr1;   /* CCORE����Ĵ������ַ1*/
    u32 commRegSize1;   /* CCORE����Ĵ����鳤��1*/
    u32 commRegAddr2;   /* CCORE����Ĵ������ַ2*/
    u32 commRegSize2;   /* CCORE����Ĵ����鳤��2*/
    u32 commRegAddr3;   /* CCORE����Ĵ������ַ3*/
    u32 commRegSize3;   /* CCORE����Ĵ����鳤��3*/

    u32 traceOnstartFlag;           /* 0:��������Trace, ��0:����������Trace */
    u32 traceCoreSet;               /* 0:�ɼ�A��Trace, 1:�ɼ�C��Trace, 2:�ɼ�˫��Trace */
    u32 busErrFlagSet;             /* 0:���������������߹�������, ��0:�������������߹������� */
} NV_DUMP_STRU;
/*ID=0xd111 end */

/*NV ID = 0xd115 start*/
typedef struct {
    u32 index;           /*Ӳ���汾����ֵ(��汾��1+��汾��2)�����ֲ�ͬ��Ʒ*/
    u32 hwIdSub;        /*Ӳ���Ӱ汾�ţ����ֲ�Ʒ�Ĳ�ͬ�İ汾*/
    char  name[32];           /*�ڲ���Ʒ��*/
    char    namePlus[32];       /*�ڲ���Ʒ��PLUS*/
    char    hwVer[32];          /*Ӳ���汾����*/
    char    dloadId[32];        /*������ʹ�õ�����*/
    char    productId[32];      /*�ⲿ��Ʒ��*/
}PRODUCT_INFO_NV_STRU;

/* product support module nv define */
typedef struct
{
    u32 sdcard      : 1;//1: support; 0: not support
    u32 charge      : 1;
    u32 wifi        : 1;
    u32 oled        : 1;
    u32 hifi        : 1;
    u32 onoff       : 1;
    u32 hsic        : 1;
    u32 localflash  : 1;
    u32 reserved    : 24;
} DRV_MODULE_SUPPORT_STRU;

/*���ؼƵ�ѹ������У׼����*/
typedef struct
{
    u32 v_offset_a;         /* ��ѹУ׼���Բ��� */
    s32 v_offset_b;         /* ��ѹУ׼����ƫ��*/
    u32 c_offset_a;         /* ����У׼���Բ��� */
    s32 c_offset_b;         /* ����У׼����ƫ�� */
}COUL_CALI_NV_TYPE;

/*E5���ڸ���*/
typedef struct
{
    u32 wait_usr_sele_uart : 1;//[bit 0-0]1: await user's command for a moment; 0: do not wait
    u32 a_core_uart_num    : 2;//[bit 1-2]the number of uart used by a core
    u32 c_core_uart_num    : 2;//[bit 3-4]the number of uart used by c core
    u32 m_core_uart_num    : 2;//[bit 5-6]the number of uart used by m core
    u32 a_shell            : 1;//[bit 7-7]0:ashell is not used; 1:ashell is used
    u32 c_shell            : 1;//[bit 8-8]0:cshell is not used; 1:cshell is used
    u32 uart_at            : 1;//[bit 9-9]uart at control
    u32 extendedbits       : 22;//[b00]1:open cshell_auart; 0:close
}DRV_UART_SHELL_FLAG;

typedef struct
{
    u32 wdt_enable;
    u32 wdt_timeout;
    u32 wdt_keepalive_ctime;
    u32 wdt_suspend_timerout;
    u32 wdt_reserve;
}DRV_WDT_INIT_PARA_STRU;

/* pm om���� NV�� = 0xd145 */
typedef struct
{
    u32 mem_ctrl:1;       /* ����bitλ:ʹ���������͵�memory */
    u32 reserved:31;      /* ����bitλ:���� */
    u8  log_threshold[4]; /* acore/ccore/mcore����д�ļ��ķ�ֵ, ��ֵ��ʾ�ٷֱ� */
    u8  mod_sw[8];        /* ����ģ��log���ܿ��ƿ��� */
}DRV_PM_OM_CFG_STRU;

/* watchpoint = 0xd148 begin */
typedef struct
{
    u32 enable;     /* ʹ�ܱ�־��0��ȥʹ�ܣ�1��ʹ�ܣ� ����ñ�־Ϊȥʹ�ܣ����ý�ֱ�Ӻ��� */
    u32 type;       /* �������: 1������2��д��3����д */
    u32 start_addr; /* �����ʼ��ַ */
    u32 end_addr;   /* ��ؽ�����ַ */
}WATCHPOINT_CFG;

typedef struct
{
    WATCHPOINT_CFG  ap_cfg[4];  /* A�����ã����֧��4��watchpoint */
    WATCHPOINT_CFG  cp_cfg[4];  /* A�����ã����֧��4��watchpoint */
}DRV_WATCHPOINT_CFG_STRU;
/* watchpoint = 0xd148 end */

typedef struct
{
    u32 DialupEnableCFG;
    u32 DialupACShellCFG;
}DRV_DIALUP_HSUART_STRU;

/* TEST support module nv define */
typedef struct
{
    u32 lcd         : 1;//1: support; 0: not support
    u32 emi         : 1;
    u32 pwm         : 1;
    u32 i2c         : 1;
    u32 leds        : 1;
    u32 reserved    : 27;
} DRV_MODULE_TEST_STRU;

typedef struct
{
    u32 ulResumeMode;       /*��NV���ݳ��ִ���ʱ�Ĵ���ʽ,1:����ģʽ,2:�û�ģʽ*/
}NV_SELF_CTRL_STRU;

/*0xd158*/
typedef struct
{
    u32 pmu_enable_cfg;     /*pmu �򿪹رտ���nv*/
    u32 protocol_sel;       /*pmu ssi spmiЭ��ѡ��*/
    u32 reserved;
}DRV_PMU_CFG_STRU;

/*0xd168*/
typedef struct
{
    u32 ap_enable:1;        /*AP coresight enable flag*/
    u32 cp_enable:1;        /*CP coresight enable flag*/
    u32 ap_store :1;        /*AP coresight store flag*/
    u32 cp_store :1;        /*CP coresight store flag*/
    u32 reserved :28;
}DRV_CORESIGHT_CFG_STRU;

typedef struct
{
    u8 normalwfi_flag;
    u8 deepsleep_flag;
    u8 buck3off_flag;
    u8 peridown_flag;
    u32 deepsleep_Tth;
    u32 TLbbp_Tth;
}DRV_NV_PM_TYPE;

typedef struct
{
    u32 enPortNum;         /* ά��ʹ�õ�����ͨ������ */
}DIAG_CHANNLE_PORT_CFG_STRU;

typedef struct {
    u32 iqi_enable:1;      /*0 iqi���Թر� 1 iqi���Դ�*/
    u32 serial_enable:1;   /*serial ���� 1�� 0 �ر�*/
    //u32 debug_enable:1;    /*debug����ʹ��*/
    u32 reservd:30;
}DRV_IQI_CFG_STRU;
#ifndef LPHY_UT_MODE//lint !e553
typedef struct convert_table
{
    s32 temperature;
    u16 code;
    u16 reserved;
} convert_table;
#define XO_TBL_SIZE 166
typedef struct xo_convert_table_array
{
    convert_table convert_table[XO_TBL_SIZE];
} xo_convert_table_array;
#define PA_TBL_SIZE 32
typedef struct pa_convert_table_array
{
    convert_table convert_table[PA_TBL_SIZE];
} pa_convert_table_array;
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
