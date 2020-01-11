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


/*****************************************************************************
  1 Include HeadFile
*****************************************************************************/
#include "diag_common.h"
#include "diag_cfg.h"
#include "diag_msgmsp.h"
#include "diag_msgphy.h"
#include "diag_api.h"
#include "diag_debug.h"
#include "msp_errno.h"
#include "nv_stru_drv.h"
#include "nv_stru_lps.h"
#include <mdrv.h>
#include <mdrv_diag_system.h>
#include "soc_socp_adapter.h"



#define    THIS_FILE_ID        MSP_FILE_ID_DIAG_CFG_C

/*****************************************************************************
  2 Declare the Global Variable
*****************************************************************************/
#define DIAG_CFG_PRINT_MODULE_NUM              (44)

VOS_UINT32 g_ulDiagCfgInfo = 0;

VOS_UINT8 g_ALayerSrcModuleCfg[VOS_CPU_ID_1_PID_BUTT - VOS_PID_CPU_ID_1_DOPRAEND] = {0};
VOS_UINT8 g_CLayerSrcModuleCfg[VOS_CPU_ID_0_PID_BUTT - VOS_PID_CPU_ID_0_DOPRAEND] = {0};

VOS_UINT8 g_ALayerDstModuleCfg[VOS_CPU_ID_1_PID_BUTT - VOS_PID_CPU_ID_1_DOPRAEND] = {0};
VOS_UINT8 g_CLayerDstModuleCfg[VOS_CPU_ID_0_PID_BUTT - VOS_PID_CPU_ID_0_DOPRAEND] = {0};

VOS_UINT8 g_EventModuleCfg[DIAG_CFG_PID_NUM] = {0};

VOS_UINT8 g_PrintModuleCfg[DIAG_CFG_PID_NUM] = {0};
VOS_UINT32 g_PrintTotalCfg = DIAG_CFG_PRINT_TOTAL_MODULE_SWT_NOT_USE;
DIAG_CFG_LOG_CAT_CFG_STRU g_stMsgCfg = {0};

VOS_UINT32 g_ulDiagDfsCtrl = 0;

HTIMER          g_DebugTimer;

/*****************************************************************************
  3 Function
*****************************************************************************/


VOS_VOID diag_CfgResetAllSwt(VOS_VOID)
{
    VOS_ULONG    ulLockLevel;


    /*��ղ�俪��״̬*/
    (VOS_VOID)VOS_MemSet_s(g_ALayerSrcModuleCfg, (VOS_UINT32)sizeof(g_ALayerSrcModuleCfg), 0, (VOS_UINT32)sizeof(g_ALayerSrcModuleCfg));
    (VOS_VOID)VOS_MemSet_s(g_CLayerSrcModuleCfg, (VOS_UINT32)sizeof(g_CLayerSrcModuleCfg), 0, (VOS_UINT32)sizeof(g_CLayerSrcModuleCfg));
    (VOS_VOID)VOS_MemSet_s(g_ALayerDstModuleCfg, (VOS_UINT32)sizeof(g_ALayerDstModuleCfg), 0, (VOS_UINT32)sizeof(g_ALayerDstModuleCfg));
    (VOS_VOID)VOS_MemSet_s(g_CLayerDstModuleCfg, (VOS_UINT32)sizeof(g_CLayerDstModuleCfg), 0, (VOS_UINT32)sizeof(g_CLayerDstModuleCfg));

    /* Ϊ����ԭTL�����EVENT���ػ��ƣ�Ĭ�ϰ�����EVENT�ӿ��ض�����Ϊ�� */
    (VOS_VOID)VOS_MemSet_s(g_EventModuleCfg, (VOS_UINT32)sizeof(g_EventModuleCfg), 0x1, (VOS_UINT32)sizeof(g_EventModuleCfg));

    /*��մ�ӡ����״̬*/
    (VOS_VOID)VOS_MemSet_s(g_PrintModuleCfg, (VOS_UINT32)sizeof(g_PrintModuleCfg), 0, (VOS_UINT32)sizeof(g_PrintModuleCfg));

    /*��մ�ӡ�ܿ���״̬*/
    g_PrintTotalCfg = DIAG_CFG_PRINT_TOTAL_MODULE_SWT_NOT_USE;

    /*�����Ϣ���˿���״̬*/
    (VOS_VOID)VOS_MemSet_s(&g_stMsgCfg, (VOS_UINT32)sizeof(g_stMsgCfg), 0, (VOS_UINT32)sizeof(g_stMsgCfg));

    VOS_SpinLockIntLock(&g_DiagLogPktNum.ulPrintLock, ulLockLevel);
    g_DiagLogPktNum.ulPrintNum = 0;
    VOS_SpinUnlockIntUnlock(&g_DiagLogPktNum.ulPrintLock, ulLockLevel);

    VOS_SpinLockIntLock(&g_DiagLogPktNum.ulTransLock, ulLockLevel);
    g_DiagLogPktNum.ulTransNum = 0;
    VOS_SpinUnlockIntUnlock(&g_DiagLogPktNum.ulTransLock, ulLockLevel);

    VOS_SpinLockIntLock(&g_DiagLogPktNum.ulEventLock, ulLockLevel);
    g_DiagLogPktNum.ulEventNum = 0;
    VOS_SpinUnlockIntUnlock(&g_DiagLogPktNum.ulEventLock, ulLockLevel);


    VOS_SpinLockIntLock(&g_DiagLogPktNum.ulAirLock, ulLockLevel);
    g_DiagLogPktNum.ulAirNum = 0;
    VOS_SpinUnlockIntUnlock(&g_DiagLogPktNum.ulAirLock, ulLockLevel);

    VOS_SpinLockIntLock(&g_DiagLogPktNum.ulVoLTELock, ulLockLevel);
    g_DiagLogPktNum.ulVoLTENum = 0;
    VOS_SpinUnlockIntUnlock(&g_DiagLogPktNum.ulVoLTELock, ulLockLevel);

    VOS_SpinLockIntLock(&g_DiagLogPktNum.ulTraceLock, ulLockLevel);
    g_DiagLogPktNum.ulTraceNum = 0;
    VOS_SpinUnlockIntUnlock(&g_DiagLogPktNum.ulTraceLock, ulLockLevel);

    VOS_SpinLockIntLock(&g_DiagLogPktNum.ulUserLock, ulLockLevel);
    g_DiagLogPktNum.ulUserNum = 0;
    VOS_SpinUnlockIntUnlock(&g_DiagLogPktNum.ulUserLock, ulLockLevel);

    return;
}

VOS_UINT32 diag_CfgSetGlobalBitValue(VOS_UINT32* pstDiagGlobal,ENUM_DIAG_CFG_BIT_U32 enBit,ENUM_DIAG_CFG_SWT_U8 enSwtich)
{
    /*����Ϊopen 1ʱ����Ҫʹ��|�����ø�bit Ϊ1*/
    if(DIAG_CFG_SWT_OPEN == enSwtich)
    {
        *pstDiagGlobal |=  ((VOS_UINT)1 << enBit);
    }
    /*����Ϊclose 0ʱ����Ҫʹ��&�����ø�bit Ϊ0*/
    else if(DIAG_CFG_SWT_CLOSE == enSwtich)
    {
        *pstDiagGlobal &= ~((VOS_UINT)1 << enBit);
    }
    else
    {
        return ERR_MSP_INVALID_PARAMETER;
    }
    return ERR_MSP_SUCCESS;
}


VOS_UINT32 diag_AirCfgProc (VOS_UINT8* pstReq)
{
    VOS_UINT32 ret;
    DIAG_CMD_LOG_CAT_AIR_REQ_STRU* pstAirSwtReq = NULL;
    DIAG_CMD_LOG_CAT_AIR_CNF_STRU stAirSwtCnf = {0};
    MSP_DIAG_CNF_INFO_STRU stDiagInfo = {0};
    DIAG_FRAME_INFO_STRU *pstDiagHead;
    ENUM_DIAG_CFG_SWT_U8 enLSwitch;
    VOS_UINT32 ulLen;
    DIAG_MSG_A_TRANS_C_STRU *pstInfo;

    /* ����log�ϱ������У��ڹ����·�AirCfg����ʱ���Ŵ����������log�ϱ� */
    if(DIAG_IS_POLOG_ON)
    {
        /* �յ��տڿ��ػָ�Ϊ�����Ŀ��ؿ����ϱ� */
        g_ulDiagCfgInfo &= (~DIAG_CFG_POWERONLOG);

        mdrv_socp_send_data_manager(SOCP_CODER_DST_OM_IND, SOCP_DEST_DSM_ENABLE);
    }

    pstDiagHead  = (DIAG_FRAME_INFO_STRU*)(pstReq);
    mdrv_diag_PTR(EN_DIAG_PTR_AIR_CFG_PROC, 1, pstDiagHead->ulCmdId, 0);

    if(pstDiagHead->ulMsgLen < sizeof(DIAG_CMD_LOG_CAT_AIR_REQ_STRU ) + sizeof(MSP_DIAG_DATA_REQ_STRU))
    {
        diag_error("rec data len error, head->msglen:0x%x\n", pstDiagHead->ulMsgLen);
        ret = ERR_MSP_INVALID_PARAMETER;
        goto DIAG_ERROR;
    }

    pstAirSwtReq = (DIAG_CMD_LOG_CAT_AIR_REQ_STRU*)(pstReq + DIAG_MESSAGE_DATA_HEADER_LEN);

    /*����LT�տڿ���ֵ*/
    enLSwitch = DIAG_GET_CFG_SWT(pstAirSwtReq->ulSwitch);
    ret = diag_CfgSetGlobalBitValue(&g_ulDiagCfgInfo,DIAG_CFG_LT_AIR_BIT,enLSwitch);
    if(ERR_MSP_SUCCESS == ret)
    {
        DIAG_MSG_ACORE_CFG_PROC(ulLen, pstDiagHead, pstInfo, ret);
        return ret;
    }

DIAG_ERROR:

    DIAG_MSG_COMMON_PROC(stDiagInfo, stAirSwtCnf, pstDiagHead);

    stDiagInfo.ulMsgType    = DIAG_MSG_TYPE_MSP;

    stAirSwtCnf.ulRc = ret;

    ret = DIAG_MsgReport(&stDiagInfo, &stAirSwtCnf, (VOS_UINT32)sizeof(stAirSwtCnf));
    mdrv_diag_PTR(EN_DIAG_PTR_AIR_CFG_FAIL_CNF, 1, pstDiagHead->ulCmdId, ret);

    return ret;
}



VOS_UINT32 diag_CfgSetLayerSwt(DIAG_CMD_LOG_CAT_LAYER_REQ_STRU* pstLayerReq, VOS_UINT32 ulCfgSize)
{

    VOS_UINT32 j;
    VOS_UINT32 ulOffset = 0;
    ENUM_DIAG_CFG_SWT_U8 enSwitch = 0;

    if((0 == ulCfgSize)||(0 !=ulCfgSize %sizeof(DIAG_CMD_LOG_CAT_LAYER_REQ_STRU)))
    {
        return  ERR_MSP_INVALID_PARAMETER;
    }

    /* ����ĳCategory�Ŀ����������б����Ҷ�Ӧ���������������*/
    for(j = 0 ; j< ulCfgSize /sizeof(DIAG_CMD_LOG_CAT_LAYER_REQ_STRU);j++)
    {
        enSwitch = DIAG_GET_CFG_SWT((pstLayerReq + j)->ulSwitch);

        if(DIAG_CFG_LAYER_MODULE_IS_ACORE((pstLayerReq + j)->ulModuleId))
        {
            ulOffset = DIAG_CFG_LAYER_MODULE_ACORE_OFFSET((pstLayerReq + j)->ulModuleId);

            if( DIAG_CMD_LAYER_MOD_SRC == (pstLayerReq + j)->ulIsDestModule)
            {
                g_ALayerSrcModuleCfg[ulOffset] = (VOS_UINT8)enSwitch;
            }
            else
            {
                g_ALayerDstModuleCfg[ulOffset] = (VOS_UINT8)enSwitch;
            }
        }
        else if(DIAG_CFG_LAYER_MODULE_IS_CCORE((pstLayerReq + j)->ulModuleId ))
        {
            ulOffset = DIAG_CFG_LAYER_MODULE_CCORE_OFFSET((pstLayerReq + j)->ulModuleId);

            if( DIAG_CMD_LAYER_MOD_SRC == (pstLayerReq + j)->ulIsDestModule)
            {
                g_CLayerSrcModuleCfg[ulOffset] = (VOS_UINT8)enSwitch;
            }
            else
            {
                g_CLayerDstModuleCfg[ulOffset] = (VOS_UINT8)enSwitch;
            }
        }
    }

    return ERR_MSP_SUCCESS;
}



VOS_UINT32 diag_LayerCfgProc (VOS_UINT8* pstReq)
{
    VOS_UINT32 ret;
    DIAG_FRAME_INFO_STRU *pstDiagHead = NULL;
    DIAG_CMD_LOG_CAT_LAYER_REQ_STRU* pstLayerSwtReq = NULL;
    DIAG_CMD_LOG_CAT_LAYER_CNF_STRU stLayerSwtCnf = {0};
    MSP_DIAG_CNF_INFO_STRU stDiagInfo = {0};
    VOS_UINT32 ulLen;
    DIAG_MSG_A_TRANS_C_STRU *pstInfo;

    pstDiagHead = (DIAG_FRAME_INFO_STRU*)(pstReq);

    mdrv_diag_PTR(EN_DIAG_PTR_LAYER_CFG_PROC, 1, pstDiagHead->ulCmdId, 0);

    if(pstDiagHead->ulMsgLen < sizeof(MSP_DIAG_DATA_REQ_STRU))
    {
        diag_error("rec data len error, u32DataLen:0x%x\n", pstDiagHead->ulMsgLen);
        ret = ERR_MSP_INVALID_PARAMETER;
        goto DIAG_ERROR;
    }

    pstLayerSwtReq = (DIAG_CMD_LOG_CAT_LAYER_REQ_STRU*)(pstReq + DIAG_MESSAGE_DATA_HEADER_LEN);

    /*���ò��ģ�鿪�ص�ȫ�ֱ�����*/
    ret = diag_CfgSetLayerSwt(pstLayerSwtReq, (VOS_UINT32)(pstDiagHead->ulMsgLen - sizeof(MSP_DIAG_DATA_REQ_STRU)));
    if(ERR_MSP_SUCCESS == ret)
    {
        DIAG_MSG_ACORE_CFG_PROC(ulLen, pstDiagHead, pstInfo, ret);
        return ret;
    }

DIAG_ERROR:

    DIAG_MSG_COMMON_PROC(stDiagInfo, stLayerSwtCnf, pstDiagHead);

    stDiagInfo.ulMsgType    = DIAG_MSG_TYPE_MSP;

    stLayerSwtCnf.ulRc = ret;

    ret = DIAG_MsgReport(&stDiagInfo, &stLayerSwtCnf, (VOS_UINT32)sizeof(stLayerSwtCnf));

    mdrv_diag_PTR(EN_DIAG_PTR_LAYER_CFG_FAIL_CNF, 1, pstDiagHead->ulCmdId, ret);

    return ret;
}



VOS_UINT32 diag_EventCfgProc(VOS_UINT8* pstReq)
{
    DIAG_CMD_LOG_CAT_EVENT_REQ_STRU* pstEvtSwtReq = NULL;
    DIAG_CMD_LOG_CAT_EVENT_CNF_STRU stEvtSwtCnf = {0};
    MSP_DIAG_CNF_INFO_STRU stDiagInfo = {0};
    DIAG_FRAME_INFO_STRU *pstDiagHead = NULL;
    VOS_UINT32 ret;
    VOS_UINT32 i, pid;
    ENUM_DIAG_CFG_SWT_U8 enSwitch;
    VOS_UINT32 ulLen;
    DIAG_MSG_A_TRANS_C_STRU *pstInfo;

    pstDiagHead = (DIAG_FRAME_INFO_STRU*)pstReq;
    mdrv_diag_PTR(EN_DIAG_PTR_EVENT_CFG_PROC, 1, pstDiagHead->ulCmdId, 0);

    if(pstDiagHead->ulMsgLen < sizeof(MSP_DIAG_DATA_REQ_STRU) + sizeof(DIAG_CMD_LOG_CAT_EVENT_REQ_STRU))
    {
        diag_error("rec data len error, u32DataLen:0x%x\n", pstDiagHead->ulMsgLen);
        ret = ERR_MSP_INVALID_PARAMETER;
        goto DIAG_ERROR;
    }

    pstEvtSwtReq = (DIAG_CMD_LOG_CAT_EVENT_REQ_STRU*)(pstReq + DIAG_MESSAGE_DATA_HEADER_LEN);

    if(pstDiagHead->ulMsgLen < sizeof(MSP_DIAG_DATA_REQ_STRU) + sizeof(DIAG_CMD_LOG_CAT_EVENT_REQ_STRU) + sizeof(VOS_UINT32) * pstEvtSwtReq->ulCount)
    {
        diag_error("rec data len error, u32DataLen:0x%x, switch count:0x%x\n", pstDiagHead->ulMsgLen, pstEvtSwtReq->ulCount);
        ret = ERR_MSP_INVALID_PARAMETER;
        goto DIAG_ERROR;
    }

    enSwitch = (ENUM_DIAG_CFG_SWT_U8)pstEvtSwtReq->ulSwt;

    /* �򿪺͹رն������ù̶���ģ�飬ֻ���ܿ����Ǵ�ʱ�����õ���ģ�� */
    if(enSwitch)
    {
        for(i = 0; i < pstEvtSwtReq->ulCount; i++)
        {
            pid = DIAG_EVENT_MODID(pstEvtSwtReq->aulModuleId[i]);
            if(DIAG_CFG_MODULE_IS_INVALID(pid))
            {
                continue;
            }

            g_EventModuleCfg[pid - VOS_PID_DOPRAEND] = DIAG_EVENT_SWT(pstEvtSwtReq->aulModuleId[i]);
        }
    }

    ret = diag_CfgSetGlobalBitValue(&g_ulDiagCfgInfo, DIAG_CFG_EVENT_BIT, enSwitch);
    if(ERR_MSP_SUCCESS == ret)
    {
        DIAG_MSG_ACORE_CFG_PROC(ulLen, pstDiagHead, pstInfo, ret);
        return ret;
    }

DIAG_ERROR:
    DIAG_MSG_COMMON_PROC(stDiagInfo, stEvtSwtCnf, pstDiagHead);

    stDiagInfo.ulMsgType    = DIAG_MSG_TYPE_MSP;

    stEvtSwtCnf.ulRc = ret;

    ret = DIAG_MsgReport(&stDiagInfo, &stEvtSwtCnf, sizeof(stEvtSwtCnf));
    mdrv_diag_PTR(EN_DIAG_PTR_EVENT_CFG_FAIL_CNF, 1, pstDiagHead->ulCmdId, ret);
    return ret;
}


VOS_UINT32 diag_CfgSetMsgSwt(DIAG_CMD_LOG_CAT_CFG_REQ_STRU *pstCatCfgReq,VOS_UINT32 ulCfgSize)
{
    VOS_UINT32 i = 0,j;
    ENUM_DIAG_CFG_SWT_U8 enSwitch =0;
    VOS_UINT32 ulRst = ERR_MSP_INVALID_PARAMETER;
    DIAG_CFG_LOG_CAT_MSG_CFG_STRU *pstItemCfg =NULL;

    /*�������*/
    if((0 == ulCfgSize)||(0 !=ulCfgSize % sizeof(DIAG_CMD_LOG_CAT_CFG_REQ_STRU)))
    {
        DIAG_DEBUG_SDM_FUN(EN_DIAG_DEBUG_MSG_ERR, ulCfgSize, 0, 0);
        return ERR_MSP_DIAG_CMD_SIZE_INVALID;
    }

    for(j = 0 ; j< ulCfgSize /sizeof(DIAG_CMD_LOG_CAT_CFG_REQ_STRU);j++)
    {

        /*��֧�ֲ����ϢCATEGORY����*/
        if(DIAG_CMD_LOG_CATETORY_LAYER_ID != (pstCatCfgReq + j)->ulCategory)
        {
            DIAG_DEBUG_SDM_FUN(EN_DIAG_DEBUG_MSG_ERR, (pstCatCfgReq + j)->ulCategory, 0, 1);
            return ERR_MSP_NOT_SUPPORT;
        }
    }


    /* ����ĳCategory�Ŀ����������б����Ҷ�Ӧ���������������*/   /* [false alarm]:����Fortify */
    /* coverity[unreachable] */
    for(j = 0 ; j< ulCfgSize /sizeof(DIAG_CMD_LOG_CAT_CFG_REQ_STRU);j++)
    {
        enSwitch = DIAG_GET_CFG_SWT((pstCatCfgReq + j)->ulSwitch);

        for(i = 0; i < g_stMsgCfg.ulCfgCnt; i++)
        {
            pstItemCfg = (g_stMsgCfg.astMsgCfgList + i);

            if((pstCatCfgReq + j)->ulId == pstItemCfg->ulId)
            {
                pstItemCfg->ulSwt = enSwitch;
                ulRst = ERR_MSP_SUCCESS;
                break;
            }
        }
        if(i >= g_stMsgCfg.ulCfgCnt)
        {
            /*Ŀǰ��һ��֧��DIAG_CFG_CAT_CFG_NUM����Ϣ����*/
            if((g_stMsgCfg.ulCfgCnt < DIAG_CFG_CAT_CFG_NUM))
            {
                pstItemCfg = g_stMsgCfg.astMsgCfgList + g_stMsgCfg.ulCfgCnt;

                pstItemCfg->ulId  = (pstCatCfgReq + j)->ulId;
                pstItemCfg->ulSwt = enSwitch;

                g_stMsgCfg.ulCfgCnt++;
                ulRst = ERR_MSP_SUCCESS;
            }
            else
            {
                DIAG_DEBUG_SDM_FUN(EN_DIAG_DEBUG_MSG_ERR, g_stMsgCfg.ulCfgCnt, 0, 3);
                return ERR_MSP_INVALID_PARAMETER;
            }
        }
    }

    return ulRst;

}


VOS_UINT32 diag_MsgCfgProc(VOS_UINT8* pstReq)
{
    DIAG_CMD_LOG_CAT_CFG_CNF_STRU stCatSwtCnf = {0};
    MSP_DIAG_CNF_INFO_STRU stDiagInfo = {0};
    DIAG_CMD_LOG_CAT_CFG_REQ_STRU* pstCatCfgReq = NULL;
    VOS_UINT32 ret;
    DIAG_FRAME_INFO_STRU *pstDiagHead = NULL;
    VOS_UINT32 ulLen;
    DIAG_MSG_A_TRANS_C_STRU *pstInfo;

    pstDiagHead = (DIAG_FRAME_INFO_STRU*)(pstReq);
    mdrv_diag_PTR(EN_DIAG_PTR_MSG_CFG_PROC, 1, pstDiagHead->ulCmdId, 0);

    if(pstDiagHead->ulMsgLen < sizeof(MSP_DIAG_DATA_REQ_STRU))
    {
        diag_printf("rec data len error, u32DataLen:0x%x\n", pstDiagHead->ulMsgLen);
        ret = ERR_MSP_INVALID_PARAMETER;
        goto DIAG_ERROR;
    }

    pstCatCfgReq = (DIAG_CMD_LOG_CAT_CFG_REQ_STRU*)(pstReq + DIAG_MESSAGE_DATA_HEADER_LEN);

    /*������Ϣ���˿��ص�ȫ�ֱ�����*/
    ret = diag_CfgSetMsgSwt(pstCatCfgReq, (VOS_UINT32)(pstDiagHead->ulMsgLen - sizeof(MSP_DIAG_DATA_REQ_STRU)));
    if(ERR_MSP_SUCCESS == ret)
    {
        DIAG_MSG_ACORE_CFG_PROC(ulLen, pstDiagHead, pstInfo, ret);
        return ret;
    }

DIAG_ERROR:

    DIAG_MSG_COMMON_PROC(stDiagInfo, stCatSwtCnf, pstDiagHead);

    stDiagInfo.ulMsgType = DIAG_MSG_TYPE_MSP;

    stCatSwtCnf.ulRc = ret;

    ret = DIAG_MsgReport(&stDiagInfo, &stCatSwtCnf, (VOS_UINT32)sizeof(stCatSwtCnf));
    mdrv_diag_PTR(EN_DIAG_PTR_MSG_CFG_FAIL_CNF, 1, pstDiagHead->ulCmdId, ret);
    return ret;

}



VOS_UINT32 diag_CfgSetPrintSwt(DIAG_CMD_LOG_CAT_PRINT_REQ_STRU* pstPrintReq, VOS_UINT32 ulCfgSize)
{
    VOS_UINT32 j = 0;
    VOS_UINT8 ucLevelFilter = 0;


    if ((0 == ulCfgSize)||(0 != ulCfgSize % sizeof(DIAG_CMD_LOG_CAT_PRINT_REQ_STRU)))
    {
        return ERR_MSP_INVALID_PARAMETER;
    }

    /* ���ߵ�LEVELֵת����MSP���ش洢��LEVELֵ */
    /*
        TOOL        <->     MSP     <->     PS
        0x40000000  <->     0x40    <->     1 (ERROR);
        0x20000000  <->     0x20    <->     2 (WARNING);
        0x10000000  <->     0x10    <->     3 (NORMAL);
        0x08000000  <->     0x08    <->     4 (INFO)
    */

    if(DIAG_CFG_PRINT_TOTAL_MODULE == pstPrintReq->ulModuleId)
    {
        /*����PRINTʱ������������ģ������*/
         (VOS_VOID)VOS_MemSet_s(g_PrintModuleCfg,(VOS_UINT32)sizeof(g_PrintModuleCfg),0,sizeof(g_PrintModuleCfg));

        /*���ô�ӡ�ܿ���*/
        ucLevelFilter = DIAG_GET_PRINT_CFG_SWT(pstPrintReq->ulLevelFilter);
        g_PrintTotalCfg = ucLevelFilter;
    }
    else
    {
        /* ����PRINT�ܿ���0xFFģ��*/
        g_PrintTotalCfg = DIAG_CFG_PRINT_TOTAL_MODULE_SWT_NOT_USE;

        /* ����ĳCategory�Ŀ����������б����Ҷ�Ӧ���������������*/
        for(j = 0 ; j< ulCfgSize /sizeof(DIAG_CMD_LOG_CAT_PRINT_REQ_STRU);j++)
        {
            if(DIAG_CFG_MODULE_IS_INVALID((VOS_INT32)((pstPrintReq + j)->ulModuleId )))
            {
                /* TODO:����¼ */
                //ret = ERR_MSP_INVALID_PARAMETER;
                continue;
            }

            ucLevelFilter = DIAG_GET_PRINT_CFG_SWT((pstPrintReq +j)->ulLevelFilter);

            g_PrintModuleCfg[(pstPrintReq +j)->ulModuleId - VOS_PID_DOPRAEND] = ucLevelFilter;
        }
    }
    return ERR_MSP_SUCCESS;
}



VOS_UINT32 diag_PrintCfgProc(VOS_UINT8* pstReq)
{
    VOS_UINT32 ret;
    DIAG_FRAME_INFO_STRU *pstDiagHead = NULL;
    DIAG_CMD_LOG_CAT_PRINT_REQ_STRU* pstPrintSwtReq = NULL;
    DIAG_CMD_LOG_CAT_PRINT_CNF_STRU stPrintSwtCnf = {0};
    MSP_DIAG_CNF_INFO_STRU stDiagInfo = {0};
    VOS_UINT32 ulLen;
    DIAG_MSG_A_TRANS_C_STRU *pstInfo;

    pstDiagHead = (DIAG_FRAME_INFO_STRU*)(pstReq);

    mdrv_diag_PTR(EN_DIAG_PTR_PRINT_CFG_PROC, 1, pstDiagHead->ulCmdId, 0);

    if(pstDiagHead->ulMsgLen < sizeof(MSP_DIAG_DATA_REQ_STRU))
    {
        diag_error("rec data len error, u32DataLen:0x%x\n", pstDiagHead->ulMsgLen);
        ret = ERR_MSP_INVALID_PARAMETER;
        goto DIAG_ERROR;
    }

    pstPrintSwtReq = (DIAG_CMD_LOG_CAT_PRINT_REQ_STRU*)(pstReq + DIAG_MESSAGE_DATA_HEADER_LEN);

    /*���ô�ӡ���ص�ȫ�ֱ�����*/
    ret = diag_CfgSetPrintSwt(pstPrintSwtReq, (VOS_UINT32)(pstDiagHead->ulMsgLen - sizeof(MSP_DIAG_DATA_REQ_STRU)));
    if(ERR_MSP_SUCCESS == ret)
    {
        DIAG_MSG_ACORE_CFG_PROC(ulLen, pstDiagHead, pstInfo, ret);
        return ret;
    }

DIAG_ERROR:

    DIAG_MSG_COMMON_PROC(stDiagInfo, stPrintSwtCnf, pstDiagHead);

    stDiagInfo.ulMsgType    = DIAG_MSG_TYPE_MSP;

    stPrintSwtCnf.ulRc = ret;

    ret = DIAG_MsgReport(&stDiagInfo, &stPrintSwtCnf, (VOS_UINT32)sizeof(stPrintSwtCnf));

    mdrv_diag_PTR(EN_DIAG_PTR_PRINT_CFG_FAIL_CNF, 1, pstDiagHead->ulCmdId, ret);

    return ret;
}



VOS_UINT64 diag_GetFrameTime(VOS_VOID)
{
    VOS_UINT32 ultimelow = 0;
    VOS_UINT32 ultimehigh= 0;
    VOS_UINT64 ulFrameCount = 0;
    VOS_INT32 ret;

    ret = mdrv_timer_get_accuracy_timestamp(&ultimehigh, &ultimelow);
    if(ERR_MSP_SUCCESS != ret)
    {
       ulFrameCount = 0;
    }
    else
    {
        ulFrameCount = ((VOS_UINT64)ultimehigh << 32) | ((VOS_UINT64)ultimelow);
    }
    return ulFrameCount;
}

/*****************************************************************************
 Function Name   : diag_GetTimeStampInitValue
 Description     : �ú�������hidis��ȡ������TL��Gu��ʱ�����ʼֵ����
 Input           : pstReq ����������
 Output          : None
 Return          : VOS_UINT32

    2.c64416         2014-11-18  �����µ���ϼܹ�
*****************************************************************************/
VOS_UINT32 diag_GetTimeStampInitValue(VOS_UINT8* pstReq)
{
    VOS_UINT ret = ERR_MSP_SUCCESS;
    MSP_DIAG_CNF_INFO_STRU stDiagInfo = {0};
    DIAG_TIMESTAMP_CNF_STRU timestampCnf = {0};
    DIAG_FRAME_INFO_STRU *pstDiagHead = NULL;

    pstDiagHead = (DIAG_FRAME_INFO_STRU*)(pstReq);

    mdrv_diag_PTR(EN_DIAG_PTR_GET_TIME_STAMP, 1, pstDiagHead->ulCmdId, 0);

    DIAG_MSG_COMMON_PROC(stDiagInfo, timestampCnf, pstDiagHead);

    stDiagInfo.ulMsgType = DIAG_MSG_TYPE_MSP;

    timestampCnf.ulGuTimeStampInitValue = mdrv_timer_get_normal_timestamp();
    timestampCnf.ulTLTimeStampInitValue = diag_GetFrameTime();
    timestampCnf.ulErrcode              = ret;

    /*�����FW�ظ�*/
    ret = DIAG_MsgReport(&stDiagInfo, &timestampCnf, (VOS_UINT32)sizeof(timestampCnf));
    mdrv_diag_PTR(EN_DIAG_PTR_GET_TIME_STAMP_CNF, 1, pstDiagHead->ulCmdId, ret);
    return (VOS_UINT32)ret;
}



