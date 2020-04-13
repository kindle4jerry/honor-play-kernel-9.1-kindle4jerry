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

#ifndef _SCM_IND_DST_H_
#define _SCM_IND_DST_H_

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include <mdrv.h>
#include <mdrv_diag_system.h>
#include <osl_types.h>
#include <bsp_dump.h>
#include <asm/dma-mapping.h>
#include <linux/dma-mapping.h>
#include <asm/io.h>
#include <linux/gfp.h>
#include <linux/mm.h>
#include "scm_ind_src.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif

#define SCM_CODER_DST_IND_SIZE      (2*1024*1024)   /* �����ϱ�����Ŀ��ͨ���ռ��С */
#define SCM_CODER_DST_THRESHOLD     (4)             /* ����Ŀ��ͨ����ֵ����λKB */

#define SCM_CODER_DST_GTHRESHOLD    ((4*1024) + 8 + 128)    /* ����Դͨ���ٲ���ֵ + DMAһ����С�����ֽ� */

/************������LPS��*********************/
#define EN_NV_ID_POWER_ON_LOG_SWITCH    (0xD33B)

/*****************************************************************************
 �ṹ��    : ����log�����Ƿ��

 �ṹ˵��  : cPowerOnlogC��cPowerOnlogA��Ϊ1���˹��ܲ���Ч
*****************************************************************************/
typedef struct
{
    /* C�˵Ŀ���log�Ƿ��*/
    s8                            cPowerOnlogC;

    /* AP�Ŀ���log�Ƿ��,Ĭ��Ϊ0����A��linux�ں˳�ʼ��ʱ����SOCP��50M�Ƿ�����޸Ĵ�NV��ֵ:���ڣ���ֵ�ᱻ�޸�Ϊ1�����򣬱���0���� */
    s8                            cPowerOnlogA;
    s8                            cSpare1;
    s8                            cSpare2;
}NV_POWER_ON_LOG_SWITCH_STRU;

/* ͨ���������ݺ����ݳ��� */
typedef void (*SCM_CODERDESTFUCN)(u8 *pucData, u8 *pucPHYData, u32 ulSize);

typedef struct
{
    SCM_CHANNEL_INIT_ENUM_U32   enInitState;    /* ͨ����ʼ��״̬����ʼ�����Զ��޸� */
    SOCP_CODER_DST_ENUM_U32     enChannelID;    /* ����Ŀ��ͨ��ID���̶����� */
    u32                         ulBufLen;       /* ����Ŀ��ͨ�����ݿռ��С */
    u32                         ulThreshold;    /* ����Ŀ��ͨ����ֵ */
    u32                         ulTimeoutMode;  /* ����Ŀ��ͨ����ʱ����*/
    u8                          *pucBuf;        /* ����Ŀ��ͨ�����ݿռ�ָ�� */
    u8                          *pucBufPHY;
    SCM_CODERDESTFUCN           pfunc;          /* ����Ŀ��ͨ�����ݴ���ص����� */
}SCM_CODER_DEST_CFG_STRU;

u32 scm_malloc_ind_dst_buff(void);
u32 scm_ind_dst_buff_init(void);
u32 scm_rls_ind_dst_buff(u32 ulReadSize);
unsigned long scm_ind_dst_buff_phy_to_virt(u8 * phyAddr);
u32 scm_ind_dst_channel_init(void);
void scm_send_ind_data_to_udi(u8 *pucVirData, u8 *pucPHYData, u32 ulDataLen);
void scm_reg_ind_coder_dst_send_fuc(void);
void  scm_set_power_on_log(void);
int scm_ind_dst_read_cb(unsigned int u32ChanID);
u32 scm_ind_get_dst_buff_size(void);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif


