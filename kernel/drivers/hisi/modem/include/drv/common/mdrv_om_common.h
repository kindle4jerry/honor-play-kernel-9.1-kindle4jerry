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

#ifndef _MDRV_OM_COMMON_H_
#define _MDRV_OM_COMMON_H_

#ifdef _cplusplus
extern "C"
{
#endif

#define MODID_SUBSYS    32
#define MODID_MODULE    28
#define MODID_CORE      24
#define MODID_RESV      18
#define MODID_ERRORCODE 16

typedef enum modem_subsys
{
    SYS_DRV     = 0,  
    SYS_PAM     = 1,
    SYS_GUCNAS  = 2,   
    SYS_GUCAS   = 3,     
    SYS_GUCPHY  = 4,    
    SYS_TLPS    = 5,   
    SYS_TLPHY   = 6,
    SYS_5GNAS,
    SYS_5GAS,
    SYS_5GPHY,
   
}MODEM_SUBSYS;

typedef enum modem_module
{
    /*DRV*/
    MODULE_BSP = 0,
    MODULE_MSP = 1,

    /*PAM*/
    MODULE_OSA = 0,
    MODULE_OAM = 1,

    /*GUCNAS*/
    MODULE_GUNAS = 0,
    MODULE_CNAS = 1,

    /*GUCAS*/
    MODULE_GUL2  =0,
    MODULE_CTTF = 1,
    MODULE_GUWAS = 2,
    MODULE_CAS  = 3,
    MODULE_CPROC = 4,
    MODULE_GUGAS = 5,

    /*GUCPHY*/
    MODULE_GUPHY = 0,
    MODULE_CPHY = 1,

    /*TLPS*/
    MODULE_TLNAS =0, 
    MODULE_TLAS = 1,

    /*TLPHY*/
    MODULE_TLPHY = 0,
   
}MODEM_MODULE;

typedef enum cpu_core
{
#if defined(__OS_RTOSCK__) ||defined(__OS_RTOSCK_SMP__)
    CORE_ARM = 0,
#elif defined(__KERNEL__)||defined(__FASTBOOT__)
    CORE_ARM = 1,
#elif defined(__CMSIS_RTOS)
    CORE_ARM = 2,
#endif
    CORE_TLDSP = 3,
    CORE_XDSP =4,
}CPU_CORE;

#define OM_MODID_HEAD(__subsys,__module,__core)   ((__subsys)<< MODID_MODULE)| ((__module) << MODID_CORE)|((__core) << MODID_RESV)

/*DRV*/
#define DRV_BSP_MODID_HEAD              OM_MODID_HEAD(SYS_DRV,MODULE_BSP,CORE_ARM)
#define DRV_MSP_MODID_HEAD              OM_MODID_HEAD(SYS_DRV,MODULE_MSP,CORE_ARM)

/*PAM*/
#define PAM_OSA_MODID_HEAD              OM_MODID_HEAD(SYS_PAM,MODULE_OSA,CORE_ARM)
#define PAM_OAM_MODID_HEAD              OM_MODID_HEAD(SYS_PAM,MODULE_OAM,CORE_ARM)

/*GUCNAS*/
#define GUCNAS_GUNAS_MODID_HEAD         OM_MODID_HEAD(SYS_GUCNAS,MODULE_GUNAS,CORE_ARM)
#define GUCNAS_CNAS_MODID_HEAD          OM_MODID_HEAD(SYS_GUCNAS,MODULE_CNAS,CORE_ARM)

/*GUCAS*/
#define GUCAS_GUL2_MODID_HEAD           OM_MODID_HEAD(SYS_GUCAS,MODULE_GUL2,CORE_ARM)
#define GUCAS_CTTF_MODID_HEAD           OM_MODID_HEAD(SYS_GUCAS,MODULE_CTTF,CORE_ARM)
#define GUCAS_GUWAS_MODID_HEAD          OM_MODID_HEAD(SYS_GUCAS,MODULE_GUWAS,CORE_ARM)
#define GUCAS_CAS_MODID_HEAD            OM_MODID_HEAD(SYS_GUCAS,MODULE_CAS,CORE_ARM)
#define GUCAS_CPROC_MODID_HEAD          OM_MODID_HEAD(SYS_GUCAS,MODULE_CPROC,CORE_ARM)
#define GUCAS_GUGAS_MODID_HEAD          OM_MODID_HEAD(SYS_GUCAS,MODULE_GUGAS,CORE_ARM)

/*GUCPHY*/
#define GUCPHY_GUPHY_MODID_HEAD         OM_MODID_HEAD(SYS_GUCPHY,MODULE_GUPHY,CORE_ARM)
#define GUCPHY_CPHY_MODID_HEAD          OM_MODID_HEAD(SYS_GUCPHY,MODULE_CPHY,CORE_XDSP)

/*TLPS*/
#define TLPS_TLNAS_MODID_HEAD           OM_MODID_HEAD(SYS_TLPS,MODULE_TLNAS,CORE_ARM)
#define TLPS_TLAS_MODID_HEAD            OM_MODID_HEAD(SYS_TLPS,MODULE_TLAS,CORE_ARM)

/*TLPHY*/
#define TLPHY_PHY_MODID_HEAD            OM_MODID_HEAD(SYS_TLPHY,MODULE_TLPHY,CORE_TLDSP)


/* field id����ֻ������ӣ�������ɾ����ö�ٶ���ɾ��֮��idֵ��Ҫ�����������id��Ҫ����ɾ��id */
/* ���AP�µ�field���ŵ�OM_AP_FIELD_END֮ǰ�����CP�µ�field���ŵ�OM_CP_FIELD_END֮ǰ */
enum OM_FIELD_ID_ENUM
{
    OM_AP_FIELD_BEGIN   = (0x01200000),
    OM_AP_OSA           = (OM_AP_FIELD_BEGIN),
    OM_AP_DIAG          = (OM_AP_FIELD_BEGIN + 1),
    OM_AP_FIELD_END,

    OM_CP_FIELD_BEGIN   = (0x02200000),
    OM_CP_OSA           = (OM_CP_FIELD_BEGIN),
    OM_CP_MSP_SLEEP     = (OM_CP_FIELD_BEGIN + 1),
    OM_CP_TLPS          = (OM_CP_FIELD_BEGIN + 2),
    OM_CP_FTM_MNTN      = (OM_CP_FIELD_BEGIN + 3),  
    OM_CP_GUAS          = (OM_CP_FIELD_BEGIN + 4),
    OM_CP_DIAG          = (OM_CP_FIELD_BEGIN + 5),  
    OM_CP_GUNAS         = (OM_CP_FIELD_BEGIN + 6),
    OM_CP_CPROC         = (OM_CP_FIELD_BEGIN + 7),
    OM_CP_CAS           = (OM_CP_FIELD_BEGIN + 8),
    OM_CP_CNAS          = (OM_CP_FIELD_BEGIN + 9),
    OM_CP_MSCC          = (OM_CP_FIELD_BEGIN + 10),
    OM_CP_CTTF          = (OM_CP_FIELD_BEGIN + 11),
    OM_CP_USIMM0        = (OM_CP_FIELD_BEGIN + 12),
    OM_CP_USIMM1        = (OM_CP_FIELD_BEGIN + 13),
    OM_CP_TLPS1         = (OM_CP_FIELD_BEGIN + 14),
    OM_CP_GUPHY         = (OM_CP_FIELD_BEGIN + 15),
    OM_CP_RFDSP         = (OM_CP_FIELD_BEGIN + 16),
    OM_CP_GUCSLEEP         = (OM_CP_FIELD_BEGIN + 17),
    OM_CP_FIELD_END,
};
enum
{
    DUMP_OUT_VOICE = 0,
    DUMP_IN_VOICE = 1,
    DUMP_VOICE_BUTT,
};
typedef int dump_handle;
typedef void (*dump_hook)(void);

/*****************************************************************************
 * �� �� ��  : mdrv_om_system_error
 * ��������  : ����쳣��¼�ӿڣ�����쳣�ļ���¼֮��������λ���塣
 * �������  : modId:   ��λԭ��
 *             arg1:    �û��Զ������1
 *             arg2:    �û��Զ������2
 *             arg3:    �û��Զ������3��
 *                       bufָ�룬dump������Զ�������dump�ڴ棬
 *                       ��dump�ļ��е�field���û�������ʾ��
 *             arg3Length:  arg��ָbuf�ĳ�����󳤶�max_len(v7Ϊ4k��v8Ϊ1k)
 *                       ����max_lenֻ������ʼmax_len����
 * �������  : �ޡ�
 * �� �� ֵ  : �ޡ�
 *****************************************************************************/
void mdrv_om_system_error(int modId, int arg1, int arg2, char * arg3, int arg3Length);

/*****************************************************************************
 * �� �� ��  : mdrv_om_register_field
 * ��������  : ��¼�쳣��λ��Ϣ�ĵ�ַ���뺯�����ýӿ�����������ڴ��д�������ݣ�
 *             ��system_error��ʱ��ᱣ�浽dump�ļ���Ӧ��field�����С�
 * �������  : field_id :   ����buffer��Ӧ��field id
 *             field_name:  field���ƣ������ڽ�����������ʾ��
 *             virt_addr:   �Դ���ַע��������ַ�����Ϊ�գ���ʾ��dump�����ڴ档
 *             phy_addr:    �Դ���ַע��������ַ
 *             length:      ����buffer�ĳ���
 *             version:     ����buffer�İ汾��
 *
 * �������  : NULL:  ����bufʧ��
 *
 * �� �� ֵ  : �ޡ�
 *****************************************************************************/
unsigned char* mdrv_om_register_field(unsigned int field_id, char * field_name, void * virt_addr,
                            void * phy_addr, unsigned int length, unsigned short version);

/*****************************************************************************
 * �� �� ��  : mdrv_om_get_field_addr
 * ��������  : ��ȡfield_id��Ӧ��dump�ڴ�������ַ���ɿ��ʹ��
 *
 * �������  : field_id: ͨ��mdrv_om_register_field�ӿ���dump�����ڴ��ID
 *
 * �������  : ��
 *
 * �� �� ֵ  : >0   �ɹ�������field�����ַ
 *             0    ʧ��
 *
 *****************************************************************************/
unsigned char * mdrv_om_get_field_addr(unsigned int field_id);

/*****************************************************************************
 * �� �� ��  : mdrv_om_get_field_phy_addr
 * ��������  : ��ȡfield_id��Ӧ��dump�ڴ�������ַ���ɿ��ʹ��
 *
 * �������  : field_id: ͨ��mdrv_om_register_field�ӿ���dump�����ڴ��ID
 *
 * �������  : ��
 *
 * �� �� ֵ  : >0   �ɹ�������field�����ַ
 *             0    ʧ��
 *
 *****************************************************************************/
unsigned char * mdrv_om_get_field_phy_addr(unsigned int field_id);

/*****************************************************************************
 * �� �� ��  : mdrv_om_register_callback
 * ��������  : DUMP������ע�ắ����dumpģ���ṩע��ӿڣ�����ģ��ע�ᴦ������
 * system_error��ʱ������ε���ִ��ע������Ĵ�������
 *
 * �������  : name :   �쳣ע���ģ������
 *             pFunc:   ϵͳ�쳣ʱ�Ļص�����
 *
 * �������  : ��
 *
 * �� �� ֵ     : >0  �ɹ�������ע������
 *        -1, DUMP_HANDLE_INVALID  ʧ��
 *
 *****************************************************************************/
dump_handle mdrv_om_register_callback(char * name, dump_hook pFunc);

/*****************************************************************************
  �� �� ��  : mdrv_om_unregister_callback
  ��������  : ɾ��DUMP���Ӻ�����

  �������  : handle :   mdrv_om_register_callbackע���ȡ���ľ��

  �������  : ��

  �� �� ֵ     : 0  �ɹ�
  -1   ʧ��

 *****************************************************************************/
 int mdrv_om_unregister_callback(dump_handle handle);


#ifdef _cplusplus
}
#endif
#endif


