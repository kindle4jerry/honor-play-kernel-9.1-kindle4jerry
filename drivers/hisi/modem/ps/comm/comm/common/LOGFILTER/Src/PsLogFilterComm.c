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

/******************************************************************************
   1 ͷ�ļ�����
******************************************************************************/
#include "PsLogFilterInterface.h"
#include "PsLib.h"
#include "PsLogFilterComm.h"





#define    THIS_FILE_ID        PS_FILE_ID_LOG_FILTER_COMM_C

/******************************************************************************
   2 �ⲿ������������
******************************************************************************/

/******************************************************************************
   3 ˽�ж���
******************************************************************************/


/******************************************************************************
   4 ȫ�ֱ�������
******************************************************************************/
PS_OM_LAYER_MSG_REPLACE_STATISTIC_STRU  g_stLayerMsgFilterStatistic = {0,0,0,0}; 


/******************************************************************************
   5 ����ʵ��
******************************************************************************/



VOS_VOID* PS_OM_LocalCpuLayerMsgCommReplace
(
    PS_OM_PER_PID_REG_CTRL_STRU    *pstLocalCpuPerPidCtrl,
    VOS_VOID                                    *pMsg
)
{
    VOS_UINT32                          ulLoop;
    PS_OM_LAYER_MSG_REPLACE_CB          pFilterFun;
    VOS_VOID                           *pResult    = pMsg;


    if (VOS_NULL_PTR == pstLocalCpuPerPidCtrl)
    {
        return pResult;
    }

    /*����ѭ����sendPid��ע��Ĺ��˺���*/
    for (ulLoop = 0; ulLoop < pstLocalCpuPerPidCtrl->usUseCnt; ulLoop++)
    {
        pFilterFun = pstLocalCpuPerPidCtrl->pafuncFilterEntry[ulLoop];
        if (VOS_NULL_PTR!= pFilterFun)
        {
            pResult = pFilterFun((MsgBlock*)pMsg);

            /*��Ϣ�ѱ����ˣ�ֱ���˳�*/
            if (pMsg != pResult)
            {
                g_stLayerMsgFilterStatistic.ulLocalCpuFilterCnt++;
                break;
            }
        }
    }

    return pResult;
}




VOS_VOID* PS_OM_DiffCpuLayerMsgCommReplace
(
    PS_OM_CPU_LAYER_MSG_FILTER_CTRL_STRU       *pstDiffCpuLayerMsgFilter,
    MsgBlock                                   *pRevMsg
)
{
    VOS_UINT32                          ulLoop;
    VOS_UINT32                          ulLoop2;
    PS_OM_LAYER_MSG_REPLACE_CB          pFilterFun;
    VOS_VOID                           *pResult    = pRevMsg;
    PS_OM_PER_PID_REG_CTRL_STRU        *pstDiffCpuPerPidCtrl;



    if (VOS_NULL_PTR == pstDiffCpuLayerMsgFilter)
    {
        return pResult;
    }

    /*��ѭ����ע���sendPid�ĸ�������ѭ����ÿ��sendPid��ע��Ĺ��˺����ĸ���*/
    for (ulLoop = 0; ulLoop < pstDiffCpuLayerMsgFilter->usUseCnt; ulLoop++)
    {
        pstDiffCpuPerPidCtrl = &(pstDiffCpuLayerMsgFilter->pastPerPidMsgFilter[ulLoop]);

        /*��ƥ��sendPid, �ҵ�sendpid��ѭ������ע��Ĺ��˺���*/
        if (pRevMsg->ulSenderPid == pstDiffCpuPerPidCtrl->ulSendPid)
        {
            for (ulLoop2 = 0; ulLoop2 < pstDiffCpuPerPidCtrl->usUseCnt; ulLoop2++)
            {
                pFilterFun = pstDiffCpuPerPidCtrl->pafuncFilterEntry[ulLoop2];
                if (VOS_NULL_PTR != pFilterFun)
                {
                    pResult = pFilterFun(pRevMsg);
                    if (pRevMsg != pResult)
                    {
                        g_stLayerMsgFilterStatistic.ulDiffCpuFilterCnt++;
                        return pResult;
                    }
                }
            }
        }
    }

    return pResult;
}


VOS_VOID* PS_OM_CpuLayerMsgCommReplace
(
    VOS_VOID                                    *pMsg,
    PS_OM_LAYER_MSG_REPLACE_CTRL_STRU           *pstLayerMsgReplaceCtrl
)
{

    MsgBlock                           *pRevMsg;
    VOS_UINT16                          usSendPid;
    VOS_VOID                           *pResult    = pMsg;
    PS_OM_PER_PID_REG_CTRL_STRU        *pstLocalCpuPerPidCtrl;
    PS_OM_CPU_LAYER_MSG_FILTER_CTRL_STRU    *pstDiffCpuLayerMsgFilter;


    if ((VOS_NULL_PTR == pMsg) || (VOS_NULL_PTR == pstLayerMsgReplaceCtrl))
    {
        return pMsg;
    }

    pRevMsg = (MsgBlock *)pMsg;
    /*�ǿ�˲����Ϣ����*/
    if (pstLayerMsgReplaceCtrl->ucLocalCpuId == VOS_GET_CPU_ID(pRevMsg->ulSenderPid))
    {
        usSendPid = (VOS_UINT16)(pRevMsg->ulSenderPid);
        pstLocalCpuPerPidCtrl = &(pstLayerMsgReplaceCtrl->stLocalCpuLayerMsgFilter.pastPerPidMsgFilter[usSendPid]);
        pResult = PS_OM_LocalCpuLayerMsgCommReplace(pstLocalCpuPerPidCtrl, pMsg);
    }

    /*��˲����Ϣ����*/
    else
    {
        pstDiffCpuLayerMsgFilter = &(pstLayerMsgReplaceCtrl->stDiffCpuLayerMsgFilter);
        pResult = PS_OM_DiffCpuLayerMsgCommReplace(pstDiffCpuLayerMsgFilter, pRevMsg);
    }

    return pResult;
}




VOS_UINT32 PS_OM_LayerMsgReplaceMemExpand
(
    VOS_UINT32                                  ulSendPid,
    VOS_UINT16                                  usElementSize,
    VOS_UINT16                                  usExpandCnt,
    VOS_UINT16                                 *pusElementCnt,
    VOS_VOID                                  **ppStartAddr
)
{
    VOS_UINT32                              ulNewAllocLen;
    VOS_UINT32                              ulOldAllocLen;
    VOS_UINT32                              ulNewElementCnt;
    VOS_UINT32                              ulOldElementCnt;
    VOS_VOID                               *pNewAddr;
    VOS_VOID                               *pOldAddr;

    ulOldElementCnt     = *pusElementCnt;
    ulNewElementCnt     = (usExpandCnt + ulOldElementCnt);
    ulNewAllocLen       = (usElementSize * ulNewElementCnt);
    pNewAddr            = (PS_OM_PER_PID_REG_CTRL_STRU *)VOS_MemAlloc(ulSendPid, DYNAMIC_MEM_PT, ulNewAllocLen);

    if (VOS_NULL_PTR == pNewAddr)
    {
        return VOS_ERR;
    }
    VOS_MemSet_s(pNewAddr, ulNewAllocLen, 0x0, ulNewAllocLen);

    pOldAddr = *(ppStartAddr);
    if (VOS_NULL_PTR != pOldAddr)
    {
        ulOldAllocLen   = (usElementSize * ulOldElementCnt);
        VOS_MemCpy_s(pNewAddr, ulOldAllocLen, pOldAddr, ulOldAllocLen);
        VOS_MemFree(ulSendPid, pOldAddr);
    }

    *ppStartAddr    = pNewAddr;
    *pusElementCnt  = (VOS_UINT16)ulNewElementCnt;

    return VOS_OK;
}


VOS_UINT32 PS_OM_OnePidFilterFuncCommReg
(
    VOS_UINT32                                  ulSendPid,
    PS_OM_LAYER_MSG_REPLACE_CB                  pFunc,
    PS_OM_CPU_LAYER_MSG_FILTER_CTRL_STRU       *pstCpuFilter,
    PS_OM_PER_PID_REG_CTRL_STRU                *pstPidFilter
)
{
    VOS_UINT32                                  ulResult;

    if ((VOS_NULL_PTR == pstCpuFilter) || (VOS_NULL_PTR == pstPidFilter))
    {
        return VOS_ERR;
    }

    /* ��Pid�±���ע��Ĺ��˻ص��ӿ��ڴ治�㣬�Ƚ����ڴ���չ�����������װ������һ���߼� */
    if (pstPidFilter->usUseCnt == pstPidFilter->usMaxCnt)
    {
        ulResult = PS_OM_LayerMsgReplaceMemExpand(ulSendPid,
                                                  sizeof(PS_OM_LAYER_MSG_REPLACE_CB),
                                                  8,
                                                  &(pstPidFilter->usMaxCnt),
                                                  (VOS_VOID**)&(pstPidFilter->pafuncFilterEntry));
        if (VOS_OK != ulResult)
        {
            return VOS_ERR;
        }
    }

    /* ִ�е�����ʱһ��OK, ע����Ӧָ�벢�޸����Ӽ����ֶ� */
    if (0 == pstPidFilter->usUseCnt)
    {
        pstPidFilter->ulSendPid = ulSendPid;
        pstCpuFilter->usUseCnt++;
    }
    pstPidFilter->pafuncFilterEntry[pstPidFilter->usUseCnt] = pFunc;
    pstPidFilter->usUseCnt++;

    return VOS_OK;
}


VOS_UINT32 PS_OM_LocalLayerMsgReplaceFuncCommReg
(
    PS_OM_LAYER_MSG_REPLACE_CB                 pFunc,
    PS_OM_LAYER_MSG_REPLACE_CTRL_STRU         *pstLayerMsgReplaceCtrl,
    VOS_UINT32                                 ulSendPid
)
{
    VOS_UINT16                                  usPidIdx;
    VOS_UINT32                                  ulResult;
    PS_OM_CPU_LAYER_MSG_FILTER_CTRL_STRU       *pstLocalCpuFilter;
    PS_OM_PER_PID_REG_CTRL_STRU                *pstLocalPidFilter;

    pstLocalCpuFilter = &(pstLayerMsgReplaceCtrl->stLocalCpuLayerMsgFilter);

    /* ���ڲ����Ϣ��������ֻ����һ�Σ���Pid���������룬������չ */
    if (0 == pstLocalCpuFilter->usUseCnt)
    {
        ulResult = PS_OM_LayerMsgReplaceMemExpand(ulSendPid,
                                                  sizeof(PS_OM_PER_PID_REG_CTRL_STRU),
                                                  pstLayerMsgReplaceCtrl->usLocalCpuMaxPidCnt,
                                                  &(pstLocalCpuFilter->usMaxCnt),
                                                  (VOS_VOID**)&(pstLocalCpuFilter->pastPerPidMsgFilter));
        if (VOS_OK != ulResult)
        {
            return VOS_ERR;
        }
    }

    usPidIdx    = (VOS_UINT16)ulSendPid;
    /* �±걣�� */
    if (usPidIdx >= pstLocalCpuFilter->usMaxCnt)
    {
        return VOS_ERR;
    }

    pstLocalPidFilter = &(pstLocalCpuFilter->pastPerPidMsgFilter[usPidIdx]);

    ulResult = PS_OM_OnePidFilterFuncCommReg(ulSendPid, pFunc, pstLocalCpuFilter, pstLocalPidFilter);

    return ulResult;
}




VOS_UINT32 PS_OM_DiffCpuLayerMsgReplaceFuncCommReg
(
    PS_OM_LAYER_MSG_REPLACE_CB                  pFunc,
    PS_OM_LAYER_MSG_REPLACE_CTRL_STRU          *pstLayerMsgReplaceCtrl,
    VOS_UINT32                                  ulSendPid
)
{
    VOS_UINT32                                  ulLoop;
    VOS_UINT32                                  ulResult;
    PS_OM_CPU_LAYER_MSG_FILTER_CTRL_STRU       *pstDiffCpuFilter;
    PS_OM_PER_PID_REG_CTRL_STRU                *pstDiffPidFilter = VOS_NULL_PTR;

    pstDiffCpuFilter = &(pstLayerMsgReplaceCtrl->stDiffCpuLayerMsgFilter);

    /* �����Ϣ������Pid���٣���������ѭ�����ҷ��� */
    for (ulLoop = 0; ulLoop < pstDiffCpuFilter->usUseCnt; ulLoop++)
    {
        if (ulSendPid == pstDiffCpuFilter->pastPerPidMsgFilter[ulLoop].ulSendPid)
        {
            pstDiffPidFilter = &(pstDiffCpuFilter->pastPerPidMsgFilter[ulLoop]);
            break;
        }
    }

    /* �Ƚ����ڴ���չ�����������װ������һ���߼� */
    if ((VOS_NULL_PTR == pstDiffPidFilter))
    {
        if (pstDiffCpuFilter->usMaxCnt == pstDiffCpuFilter->usUseCnt)
        {
            ulResult = PS_OM_LayerMsgReplaceMemExpand(ulSendPid,
                sizeof(PS_OM_PER_PID_REG_CTRL_STRU),
                20,
                &(pstDiffCpuFilter->usMaxCnt),
                (VOS_VOID**)&(pstDiffCpuFilter->pastPerPidMsgFilter));
            if (VOS_OK != ulResult)
            {
                return VOS_ERR;
            }
        }

        pstDiffPidFilter = &(pstDiffCpuFilter->pastPerPidMsgFilter[pstDiffCpuFilter->usUseCnt]);
    }

    ulResult = PS_OM_OnePidFilterFuncCommReg(ulSendPid, pFunc, pstDiffCpuFilter, pstDiffPidFilter);

    return ulResult;
}


VOS_UINT32 PS_OM_LayerMsgReplaceCBCommReg
(
    PS_OM_LAYER_MSG_REPLACE_CTRL_STRU          *pstLayerMsgCtrl,
    VOS_UINT32                                  ulSendPid,
    PS_OM_LAYER_MSG_REPLACE_CB                  pFunc
)
{
    VOS_UINT32                      ulResult;

    /*��κϷ��Լ�顢PID��Χ���*/
    if ((VOS_NULL_PTR == pstLayerMsgCtrl) || (VOS_NULL_PTR == pFunc))
    {
        g_stLayerMsgFilterStatistic.ulRegFailCnt++;
        return VOS_ERR;
    }

    /* ���ڲ����Ϣ���˻ص�ע�ᴦ�� */
    if (pstLayerMsgCtrl->ucLocalCpuId == VOS_GET_CPU_ID(ulSendPid))
    {
        ulResult = PS_OM_LocalLayerMsgReplaceFuncCommReg(pFunc, pstLayerMsgCtrl, ulSendPid);
    }

    else/* ��˲����Ϣ���˻ص�ע�ᴦ�� */
    {
        ulResult = PS_OM_DiffCpuLayerMsgReplaceFuncCommReg(pFunc, pstLayerMsgCtrl, ulSendPid);
    }
    if (VOS_OK == ulResult)
    {
        g_stLayerMsgFilterStatistic.ulRegSuccCnt++;
    }
    else
    {
        g_stLayerMsgFilterStatistic.ulRegFailCnt++;
    }

    return ulResult;
}


