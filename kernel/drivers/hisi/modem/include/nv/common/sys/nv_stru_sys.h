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


#ifndef __SYS_NV_DEF_H__
#define __SYS_NV_DEF_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#include "nv_id_sys.h"

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

#define NV_ITEM_IMEI_SIZE 16

typedef struct
{
    u8                           aucImei[NV_ITEM_IMEI_SIZE];
}IMEI_STRU;

/*****************************************************************************
 �ṹ��    : RESUME_FLAG_STRU
 �ṹ˵��  : RESUME_FLAG�ṹ
*****************************************************************************/
typedef struct
{
    u16   usResumeFlag; /*Range:[0, 1]*/
}RESUME_FLAG_STRU;

/*****************************************************************************
 �ṹ��    : LED_CONTROL_NV_STRU
 �ṹ˵��  : LED_CONTROL_NV�ṹ ID=7
*****************************************************************************/
typedef struct
{
    u8   ucLedColor;      /*��ɫ����ɫ����ӦLED_COLOR��ֵ*/
    u8   ucTimeLength;    /*�����ó�����ʱ�䳤�ȣ���λ100ms*/
}LED_CONTROL_NV_STRU;

/*****************************************************************************
 �ṹ��    : LED_CONTROL_STRU
 �ṹ˵��  : LED_CONTROL�ṹ
*****************************************************************************/
typedef struct
{
    LED_CONTROL_NV_STRU   stLED[10];
}LED_CONTROL_STRU;

/*****************************************************************************
 �ṹ��    : LED_CONTROL_STRU_ARRAY
 �ṹ˵��  : ��ɫ��״̬���е�Ԫ�ṹ
*****************************************************************************/
typedef struct
{
    LED_CONTROL_STRU    stLED_Control[32];
}LED_CONTROL_STRU_ARRAY;

typedef struct
{
    u16 major_ver;
    u16 minor_ver;
}NV_VERSION_NO_STRU;

/*****************************************************************************
 �ṹ��    : USIM_TEMP_SENSOR_TABLE
 �ṹ˵��  : USIM_TEMP_SENSOR_TABLE�ṹ
*****************************************************************************/
typedef struct
{
    s16   Temperature;
    u16   Voltage;
}USIM_TEMP_SENSOR_TABLE;

/*****************************************************************************
 �ṹ��    : USIM_TEMP_SENSOR_TABLE_STRU
 �ṹ˵��  : USIM_TEMP_SENSOR_TABLE�ṹ
*****************************************************************************/
typedef struct
{
    USIM_TEMP_SENSOR_TABLE UsimTempSensorTable[19];
}USIM_TEMP_SENSOR_TABLE_STRU;

/*****************************************************************************
 �ṹ��    : NV_AT_SHELL_OPEN_FLAG_STRU
 �ṹ˵��  : NV_AT_SHELL_OPEN_FLAG�ṹ ID=33
*****************************************************************************/
typedef struct
{
    u32    NV_AT_SHELL_OPEN_FLAG;
}NV_AT_SHELL_OPEN_FLAG_STRU;

/*****************************************************************************
 �ṹ��    : NV_NPNP_CONFIG_INFO
 �ṹ˵��  : NV_NPNP_CONFIG_INFO ID=67
*****************************************************************************/
typedef struct
{
    u32 npnp_open_flag;                           /* NPNP ����һ��NV����, 0Ϊδ����������ʹ��, 1Ϊ��������ʹ�� */
    u32 npnp_enable_flag;                         /* NPNP ���Զ���NV��, 0Ϊ����δʹ��, 1Ϊ����ʹ��             */
}NV_NPNP_CONFIG_INFO;

/*****************************************************************************
 �ṹ��    : NV_FACTORY_INFO_I_STRU
 �ṹ˵��  : NV_FACTORY_INFO_I�ṹ ID=114
*****************************************************************************/
#define NV_FACTORY_INFO_I_SIZE    (78)
typedef struct
{
    u8 aucFactoryInfo[NV_FACTORY_INFO_I_SIZE];
}NV_FACTORY_INFO_I_STRU;

/*****************************************************************************
 �ṹ��    : NV_SCI_CFG_STRU
 �ṹ˵��  : NV_SCI_CFG�ṹ ID=128
*****************************************************************************/
typedef struct
{
    u32 value;
} NV_SCI_CFG_STRU;


typedef struct
{
    u8 ucAlmStatus; /* �澯״̬,Ĭ��0:close;1:open  */
    u8 ucAlmLevel;  /* ����&�澯����*/
    u8 aucReportBitMap[2];
}NV_ID_ERR_LOG_CTRL_INFO_STRU;


typedef struct
{
    u32                          ulAlarmid;        /* �澯��ʶ */
    u32                          ulAlarmidDetail;  /* �澯����ԣ�32bit��ÿ��bit����һ������ԣ�0����͸�������޹� */
}OM_ALARM_ID_DETAIL_STRU;


typedef struct
{
    OM_ALARM_ID_DETAIL_STRU          astOmAlarmidRelationship[40]; /* Ԥ��40�� */
}NV_ALARM_ID_RELATIONSHIP_STRU;


typedef struct
{
    u32                          ulFTMDetail; /* ����ģʽ����ԣ�32bit��ÿ��bit����һ������ԣ�0����͸�������޹� */
}NV_ID_FTM_DETAIL_STRU;

/*****************************************************************************
 �ṹ��    : NV_THERMAL_TSENSOR_CONFIG_STRU
 �ṹ˵��  : NV_THERMAL_TSENSOR_CONFIG�ṹ ID=9213
*****************************************************************************/
typedef struct
{
    u32       enable;
    u32       lagvalue0;
    u32       lagvalue1;
    u32       thresvalue0;
    u32       thresvalue1;
    u32       rstthresvalue0;
    u32       rstthresvalue1;
    u32       alarmcount1;
    u32       alarmcount2;
    u32       resumecount;
    u32       acpumaxfreq;
    u32       gpumaxfreq;
    u32       ddrmaxfreq;
    u32       reserved[4];
}NV_THERMAL_TSENSOR_CONFIG_STRU;


/*****************************************************************************
 �ṹ��    : NV_THERMAL_BAT_CONFIG_STRU
 �ṹ˵��  : NV_THERMAL_BAT_CONFIG�ṹ ID=9214
*****************************************************************************/
typedef struct
{
    u16       enable;
    u16       hkadcid;
    s16       highthres;
    u16       highcount;
    s16       lowthres;
    u16       lowcount;
    u32       reserved[2];

}NV_THERMAL_BAT_CONFIG_STRU;

/*****************************************************************************
 �ṹ��    : NV_THERMAL_HKADC_CONFIG
 �ṹ˵��  : NV_THERMAL_HKADC_CONFIG�ṹ ID=9232
*****************************************************************************/
typedef struct
{
    u16 hkadc[32];
}NV_KADC_CHANNEL_CFG_STRU;

typedef struct
{
    u32   outconfig;
    u16   outperiod;
    u16   convertlistlen;
    u32   reserved[2];
}NV_THERMAL_HKADC_CONFIG;

/*****************************************************************************
 �ṹ��    : NV_THERMAL_HKADC_CONFIG_STRU
 �ṹ˵��  : NV_THERMAL_HKADC_CONFIG�ṹ ID=9215
*****************************************************************************/
typedef struct
{
    NV_THERMAL_HKADC_CONFIG   hkadcCfg[14];
}NV_THERMAL_HKADC_CONFIG_STRU;

/*****************************************************************************
 �ṹ��    : NV_KADC_PHYTOLOGICAL_CONFIGTCXO_CFG_STRU
 �ṹ˵��  : NV_KADC_PHYTOLOGICAL_CONFIGTCXO_CFG�ṹ ID=9216
*****************************************************************************/
typedef struct
{
    u16 hkadc[14];
}NV_KADC_PHYTOLOGICAL_CONFIGTCXO_CFG_STRU;

/*****************************************************************************
 �ṹ��    : NV_TCXO_CFG_STRU
 �ṹ˵��  : NV_TCXO_CFG�ṹ ID=9217
*****************************************************************************/
typedef struct
{
    u32 tcxo_cfg;
}NV_TCXO_CFG_STRU;


typedef struct
{
    u8  enUartEnableCfg;
    u8  uartRsv[3];
}NV_UART_SWITCH_STRU;

/*****************************************************************************
 �ṹ��    : NV_HUAWEI_PCCW_HS_HSPA_BLUE_STRU
 �ṹ˵��  : NV_HUAWEI_PCCW_HS_HSPA_BLUE�ṹ ID=50032
*****************************************************************************/
typedef struct
{
    u32  NVhspa_hs_blue; /*Range:[0,3]*/
}NV_HUAWEI_PCCW_HS_HSPA_BLUE_STRU;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif

