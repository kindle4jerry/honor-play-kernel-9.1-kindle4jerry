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


#ifndef __OM_HSIC_PPM_H__
#define __OM_HSIC_PPM_H__

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include <mdrv.h>
#include <mdrv_diag_system.h>
#include <osl_types.h>
#include <osl_sem.h>


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(push)
#pragma pack(4)

/*****************************************************************************
  2 �궨��
*****************************************************************************/


/*******************************************************************************
  3 ö�ٶ���
*******************************************************************************/

enum OM_HSIC_PORT_STATUS_ENUM
{
    OM_HSIC_PORT_STATUS_OFF      = 0,       /* HSIC��GU��OM��δ������ */
    OM_HSIC_PORT_STATUS_ON,                 /* HSIC��GU��OM���ѹ����� */
    OM_HSIC_PORT_STATUS_BUTT
};
typedef u32 OM_HSIC_PORT_STATUS_ENUM_UINT32;


/*****************************************************************************
  4 �ṹ�嶨��
*****************************************************************************/


/*****************************************************************************
  4 ��������
*****************************************************************************/
void   PPM_HsicIndWriteDataCB(u8* pucVirData, u8* pucPhyData, s32 lLen);

void   PPM_HsicCfgReadDataCB(void);

void   PPM_HsicCfgWriteDataCB(u8* pucVirData, u8* pucPhyData, s32 lLen);

void   PPM_HsicCfgPortOpen(void);

void   PPM_HsicIndPortOpen(void);

void   PPM_HsicIndPortClose(void);

void   PPM_HsicCfgPortClose(void);

u32 PPM_HsicIndSendData(u8 *pucVirAddr, u8 *pucPhyAddr, u32 ulDataLen);

u32 PPM_HsicCfgSendData(u8 *pucVirAddr, u8 *pucPhyAddr, u32 ulDataLen);

void   PPM_HsicIndStatusCB(ACM_EVT_E enPortState);

void   PPM_HsicCfgStatusCB(ACM_EVT_E enPortState);

void   PPM_HsicPortInit(void);

void   PPM_HsicConnectProc(void);

void   PPM_HsicDisconnectProc(void);

/*****************************************************************************
  5 ȫ�ֱ�������
*****************************************************************************/


/*****************************************************************************
  6 OTHERS����
*****************************************************************************/




#pragma pack(pop)

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of OmCommonPpm.h*/

