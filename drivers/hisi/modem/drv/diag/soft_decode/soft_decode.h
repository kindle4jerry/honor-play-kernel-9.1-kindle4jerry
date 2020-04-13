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

#ifndef _SCM_SOFTDECODE_H_
#define _SCM_SOFTDECODE_H_

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include <osl_types.h>
#include <osl_spinlock.h>
#include <osl_sem.h>
#include "hdlc.h"
#include "ring_buffer.h"


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif

/**************************************************************************
  2 �궨��
**************************************************************************/
#define SCM_DATA_RCV_BUFFER_SIZE    (100*1024)      /* SCM���ݽ���buffer��С */
#define SCM_DATA_RCV_PKT_SIZE       (8*1024)        /* SCM���ݽ���PKT��С */

#define soft_decode_printf(fmt, ...) \
    bsp_trace(BSP_LOG_LEVEL_ERROR, BSP_MODU_DIAG_SYSTEM, "[soft decode]:<%s %d> "fmt, __FUNCTION__,__LINE__, ##__VA_ARGS__)


/**************************************************************************
  3 ö�ٶ���
**************************************************************************/

/**************************************************************************
  4 �ṹ�嶨��
**************************************************************************/

/*****************************************************************************
�ṹ��    : SCM_DATE_RCV_CTRL_STRU
�ṹ˵��  : SCM���ݽ��յĿ��ƽṹ
*****************************************************************************/
typedef struct
{
    osl_sem_id                      SmID;
    OM_RING_ID                      rngOmRbufId;
    char                            *pucBuffer;
}SCM_DATA_RCV_CTRL_STRU;
 

/*****************************************************************************
�ṹ��    : SCM_MAINTENANCE_INFO_STRU
�ṹ˵��  : SCM�����ģ���ά�ɲ���Ϣ��¼�ṹ
*****************************************************************************/
typedef struct
{
    u32                          ulDataLen; /* ���ջ������ݳ��� */
    u32                          ulNum;     /* ���ջ������ݴ��� */
}SCM_MAINTENANCE_INFO_STRU;

typedef struct
{
    u32                          ulSemCreatErr;
    u32                          ulSemGiveErr;
    u32                          ulRingBufferCreatErr;
    u32                          ulTaskIdErr;
    u32                          ulBufferNotEnough;
    u32                          ulRingBufferFlush;
    u32                          ulRingBufferPutErr;
}SCM_SOFTDECODE_RB_INFO_STRU;


/*****************************************************************************
�ṹ��    : OM_ACPU_PC_UE_SUC_STRU
�ṹ˵��  : OMģ���������տ�ά�ɲ���Ϣ��¼�ṹ
*****************************************************************************/
typedef struct
{
    SCM_SOFTDECODE_RB_INFO_STRU         stRbInfo;
    SCM_MAINTENANCE_INFO_STRU           stPutInfo;
    SCM_MAINTENANCE_INFO_STRU           stGetInfo;
    SCM_MAINTENANCE_INFO_STRU           stHdlcDecapData;
    u32                          ulFrameDecapErr;
    u32                          ulHdlcInitErr;
    u32                          ulDataTypeErr;
    u32                          ulCpmRegLogicRcvSuc;
}SCM_SOFTDECODE_INFO_STRU;

extern SCM_SOFTDECODE_INFO_STRU   g_stScmSoftDecodeInfo;
/**************************************************************************
  6 ��������
**************************************************************************/


u32 SCM_SoftDecodeCfgDataRcv(u8 *pucBuffer, u32 ulLen);
u32 SCM_SoftDecodeDataRcv(u8 *pucBuffer, u32 ulLen);
int SCM_SoftDecodeCfgRcvTaskInit(void);
int SCM_SoftDecodeCfgRcvSelfTask(void* para);
void scm_soft_decode_init(void);
u32 SCM_SoftDecodeAcpuRcvData(OM_HDLC_STRU *pstHdlcCtrl, u8 *pucData, u32 ulLen);
u32 SCM_SoftDecodeCfgHdlcInit(OM_HDLC_STRU *pstHdlc);
void SCM_SoftDecodeInfoShow(void);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif


