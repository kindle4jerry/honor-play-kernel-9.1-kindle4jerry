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

#ifndef __MDRV_DIAG_SYSTEM_H__
#define __MDRV_DIAG_SYSTEM_H__
#ifdef __cplusplus
extern "C"
{
#endif

#include "mdrv_socp_common.h"
#include "mdrv_diag_system_common.h"

#ifdef DIAG_SYSTEM_5G
#define SCM_CODER_SRC_LOM_CNF                       (SOCP_CODER_SRC_ACPU_CNF)
#define SCM_CODER_SRC_LOM_IND                       (SOCP_CODER_SRC_ACPU_IND)
#else
#define SCM_CODER_SRC_LOM_CNF                       (SOCP_CODER_SRC_LOM_CNF1)
#define SCM_CODER_SRC_LOM_IND                       (SOCP_CODER_SRC_LOM_IND1)
#endif

#define DIAG_CODER_SRC_CNF_PADDR       (DIAG_CODER_SRC_ACORE_CNF_PADDR)
#define DIAG_CODER_SRC_CNF_LENGTH      (DIAG_CODER_SRC_ACORE_CNF_LENGTH)

#define DIAG_CODER_SRC_IND_PADDR       (DIAG_CODER_SRC_ACORE_IND_PADDR)
#define DIAG_CODER_SRC_IND_LENGTH      (DIAG_CODER_SRC_ACORE_IND_LENGTH)


enum
{
    CPM_AT_COMM,
    CPM_OM_IND_COMM,        /* OM��ά�ɲ�˿� */
    CPM_OM_CFG_COMM,        /* OM���ö˿� */
    CPM_DIAG_COMM,
    CPM_PCVOICE_COMM,
    CPM_COMM_BUTT
};
typedef unsigned int  CPM_LOGIC_PORT_ENUM_UINT32;


typedef struct
{
    unsigned int                      ulUSBWriteNum1;
    unsigned int                      ulUSBWriteNum2;
    unsigned int                      ulUSBWriteCBNum;
    unsigned int                      ulUSBWriteMaxTime;
    unsigned int                      ulUSBINNum;
    unsigned int                      ulUSBINTime;
    unsigned int                      ulUSBOutNum;
    unsigned int                      ulUSBOutTime;
    unsigned int                      ulUSBStateErrNum;
    unsigned int                      ulUSBStateErrTime;
    unsigned int                      ulUSBWriteErrTime;
    unsigned int                      ulUSBWriteErrNum;
    unsigned int                      ulUSBWriteErrValue;
    unsigned int                      ulUSBWriteErrLen;

    unsigned int                      ulUSBOpenNum;
    unsigned int                      ulUSBOpenSlice;
    unsigned int                      ulUSBOpenOkNum;
    unsigned int                      ulUSBOpenOkSlice;
    unsigned int                      ulUSBOpenOk2Num;
    unsigned int                      ulUSBOpenOk2Slice;
    unsigned int                      ulUSBCloseNum;
    unsigned int                      ulUSBCloseSlice;
    unsigned int                      ulUSBCloseOkNum;
    unsigned int                      ulUSBCloseOkSlice;

    unsigned int                      ulUSBIndPseudoSyncFailNum;
    unsigned int                      ulUSBIndPseudoSyncFailSlice;
    unsigned int                      ulUSBCnfPseudoSyncFailNum;
    unsigned int                      ulUSBCnfPseudoSyncFailSlice;
    unsigned int                      ulUSBUdiHandleErr;
    unsigned int                      ulUSBUdiHandleReadGetBufferErr;
    unsigned int                      ulUSBUdiCommRcvNullPtrErr;
    unsigned int                      ulUSBUdiHandleReadBufferFreeErr;
    unsigned int                      ulUSBRcvPktNum;
    unsigned int                      ulUSBRcvPktByte;

}OM_ACPU_PORT_INFO;

typedef struct
{
    unsigned int                          ulSocpCBParaErrNum;
    unsigned int                          ulUSBSendNum;
    unsigned int                          ulUSBSendLen;
    unsigned int                          ulUSBSendRealLen;
    unsigned int                          ulUSBSendErrNum;
    unsigned int                          ulUSBSendErrLen;
    unsigned int                          ulUSBSendCBAbnormalNum;
    unsigned int                          ulUSBSendCBAbnormalLen;

    unsigned int                          ulOmGetVirtErr;
    unsigned int                          ulOmGetVirtSendLen;
    unsigned int                          ulOmDiscardNum;
    unsigned int                          ulOmDiscardLen;
    unsigned int                          ulSocpReadDoneErrNum;
    unsigned int                          ulSocpReadDoneErrLen;
}OM_SOCP_CHANNEL_DEBUG_INFO;

#define OM_PORT_HANDLE_NUM      (5) /*OM_PORT_HANDLE_NUM = OM_PORT_HANDLE_BUTT*/
/*���ڼ�¼��ǰOMͨ������Ϣ*/
typedef struct
{
    OM_SOCP_CHANNEL_DEBUG_INFO          stIndDebugInfo;
    OM_SOCP_CHANNEL_DEBUG_INFO          stCnfDebugInfo;
    OM_ACPU_PORT_INFO                   astPortInfo[OM_PORT_HANDLE_NUM];
    unsigned int                          ulInvaldChannel;
}OM_ACPU_DEBUG_INFO;
/* ���ڼ�¼VCOM������Ϣ */
typedef struct
{
    unsigned int                          ulVCOMSendSn;
    unsigned int                          ulVCOMSendNum;
    unsigned int                          ulVCOMSendLen;
    unsigned int                          ulVCOMSendErrNum;
    unsigned int                          ulVCOMSendErrLen;
    unsigned int                          ulMaxTimeLen;           /* ����д�ӿڻ��ѵ����ʱ�� */

    unsigned int                          ulVCOMRcvSn;
    unsigned int                          ulVCOMRcvNum;
    unsigned int                          ulVCOMRcvLen;
    unsigned int                          ulVCOMRcvErrNum;
    unsigned int                          ulVCOMRcvErrLen;
}OM_VCOM_DEBUG_INFO;

/* mntn info ***********************************************************************/
typedef enum
{
    EN_DIAG_DST_LOST_BRANCH,            /* ��ǰʱ��η�֧ʧ�ܴ��� */

    EN_DIAG_DST_LOST_CPMWR,             /* ��ǰʱ���CPMдʧ�ܴ��� */

    EN_DIAG_DST_LOST_CPMCB,             /* ��ǰʱ���CPMд�ص�ʧ�ܴ��� */

    EN_DIAG_DST_LOST_MAX
}DIAG_LOST_DST_ID_ENUM;

typedef struct
{
    unsigned int      ulChannelId;        /* ͨ���� */
    char     chanName[16];       /*ͨ����*/
    unsigned int      ulLeftSize;         /*ͨ��ʣ��buf��С*/
    unsigned int      ulDeltaTime;        /*���ϴ��ϱ���ʱ����*/

    unsigned int      ulDeltaLostTimes;   /*�ϱ�ʱ����ڵĶ�����*/
    unsigned int      ulDeltaLostLen;     /*�ϱ�ʱ����ڶ������ݳ���*/

    unsigned int      aulCurFailNum[EN_DIAG_DST_LOST_MAX];    /* ��ǰʱ����ڶ����ĸ������ */
    unsigned int      aulCurFailLen[EN_DIAG_DST_LOST_MAX];    /* ��ǰʱ����ڶ����������ݳ��� */

    unsigned int      ulDeltaOverFlowCnt;         /* �ϱ�ʱ�����ͨ��������� */
    unsigned int      ulDeltaPartOverFlowCnt;     /* �ϱ�ʱ�����ͨ��80%������� */

    unsigned int      ulDeltaSocpLen;             /* �ϱ�ʱ�����ڴ�socp��ȡ�������ݳ��� */

    unsigned int      ulDeltaUSBLen;              /* �ϱ�ʱ�����ڷ��͸�USB�����ֽ��� */
    unsigned int      ulDeltaUSBOKLen;            /* �ϱ�ʱ�����ڷ��͸�USB���سɹ������ֽ��� */
    unsigned int      ulDeltaUSBFreeLen;          /* �ϱ�ʱ������USB�ص��ͷŵ����ֽ��� */
    unsigned int      ulDeltaUSBFailLen;          /* �ϱ�ʱ���д��USBʧ�ܵ����ֽ��� */

    unsigned int      ulDeltaVcomLen;             /* �ϱ�ʱ�����ڷ��͸�Vcom�����ֽ��� */
    unsigned int      ulDeltaVcomFailLen;         /* �ϱ�ʱ������Vcomд��ʧ�ܵ����ֽ��� */
    unsigned int      ulDeltaVcomSucessLen;       /* �ϱ�ʱ������Vcomд��ɹ������ֽ��� */

    unsigned int      ulDeltaSocketLen;           /* �ϱ�ʱ�����ڷ��͸�Socket�����ֽ��� */
    unsigned int      ulDeltaSocketSucessLen;     /* �ϱ�ʱ������Socketд��ɹ������ֽ��� */
    unsigned int      ulDeltaSocketFailLen;       /* �ϱ�ʱ������Socketд��ɹ������ֽ��� */

    unsigned int      ulDeltaSocpIntToPortTime;     /* �ϱ�ʱ����ڴ�socp�ϱ��жϿ�ʼ�����ø��˿ڷ��͵�ʱ���ܺ� */

    unsigned int      ulDeltaUsbSendTime;         /* �ϱ�ʱ����ڷ��͸�USBռ�õ�ʱ���ܺ� */
    unsigned int      ulDeltaVcomSendTime;        /* �ϱ�ʱ����ڷ��͸�Vcomռ�õ�ʱ���ܺ� */
    unsigned int      ulDeltaSockSendTime;        /* �ϱ�ʱ����ڷ��͸�Socketռ�õ�ʱ���ܺ� */

    unsigned int      ulThrputPhy;               /* ����ͨ�������� */
    unsigned int      ulThrputCb;                /* �ص������� */

    unsigned int      aulReserve[12];              /* Ԥ�� */

    unsigned int      aulToolreserve[12];         /* ������Ԥ����64���ֽڣ������ڹ�������ʾ���ߵ�ά����Ϣ */
}DIAG_MNTN_DST_INFO_STRU;



typedef unsigned int (*PPM_DisconnectTLPortFuc)(void);
typedef unsigned int (*CPM_RCV_FUNC)(unsigned char *pucData, unsigned int ulLen);
/* ͨ���������ݡ����ݳ��ȡ��ؾ����ݡ��ؾ����ݳ��� */
typedef void (*SCM_DECODERDESTFUCN)(SOCP_DECODER_DST_ENUM_U32 enChanID,unsigned char *pucData, unsigned int ulSize, unsigned char *pucRBData, unsigned int ulRBSize);

void mdrv_PPM_RegDisconnectCb(PPM_DisconnectTLPortFuc cb);
void mdrv_scm_reg_ind_coder_dst_send_fuc(void);
unsigned int mdrv_CPM_ComSend(CPM_LOGIC_PORT_ENUM_UINT32 enLogicPort, unsigned char *pucVirData, unsigned char *pucPHYData, unsigned int ulLen);
void mdrv_CPM_LogicRcvReg(CPM_LOGIC_PORT_ENUM_UINT32 enLogicPort, CPM_RCV_FUNC pRcvFunc);
unsigned int mdrv_PPM_LogPortSwitch(unsigned int  ulPhyPort, unsigned int ulEffect);
unsigned int mdrv_PPM_QueryLogPort(unsigned int  *pulLogPort);
unsigned int mdrv_SCM_RegDecoderDestProc(SOCP_DECODER_DST_ENUM_U32 enChanlID, SCM_DECODERDESTFUCN func);
void mdrv_report_dst_mntn(void);
void mdrv_diag_get_dst_mntn_info(DIAG_MNTN_DST_INFO_STRU * dst_mntn);
void mdrv_diag_reset_dst_mntn_info(void);
void mdrv_scm_set_power_on_log(void);

#ifdef __cplusplus
}
#endif
#endif
