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
  1 ͷ�ļ�����
*****************************************************************************/
#include "AtCmdMiscProc.h"
#include "AtSndMsg.h"
#include "ATCmdProc.h"
#include "dms_core.h"
#include "AtDataProc.h"
#include "CssAtInterface.h"

extern TAF_MMA_USER_SET_PRIO_RAT_ENUM_U8 AT_GetSysCfgPrioRat(
    TAF_MMA_SYS_CFG_PARA_STRU          *pstSysCfgExSetPara
);

/*****************************************************************************
    Э��ջ��ӡ��㷽ʽ�µ�.C�ļ��궨��
*****************************************************************************/
#define    THIS_FILE_ID                 PS_FILE_ID_AT_CMD_MISC_PROC_C

/*****************************************************************************
  2 ȫ�ֱ�������
*****************************************************************************/


/*****************************************************************************
  3 ����ʵ��
*****************************************************************************/


VOS_UINT32 AT_SetActiveModem(VOS_UINT8 ucIndex)
{
    TAF_NV_DSDS_ACTIVE_MODEM_MODE_STRU  stMode;
    AT_MTA_MODEM_CAP_UPDATE_REQ_STRU    stAtMtaModemCapUpdate;

    TAF_MEM_SET_S(&stAtMtaModemCapUpdate, (VOS_UINT32)sizeof(AT_MTA_MODEM_CAP_UPDATE_REQ_STRU), 0x00, (VOS_UINT32)sizeof(AT_MTA_MODEM_CAP_UPDATE_REQ_STRU));

    /* ����������� */
    if (gucAtParaIndex != 1)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    TAF_MEM_SET_S(&stMode, sizeof(stMode), 0x00, sizeof(stMode));
    stMode.enActiveModem = (TAF_NV_ACTIVE_MODEM_MODE_ENUM_UINT8)gastAtParaList[0].ulParaValue;

    /* дNV, ����AT_OK */
    if (NV_OK != TAF_ACORE_NV_WRITE(MODEM_ID_0, en_NV_Item_DSDS_Active_Modem_Mode, &stMode, sizeof(stMode)))
    {
        AT_ERR_LOG("AT_SetActiveModem(): en_NV_Item_DSDS_Active_Modem_Mode NV Write Fail!");
        return AT_ERROR;
    }

    /* ������NV��֪ͨAT->MTA->RRM�����еײ�ƽ̨�������� */
    /* AT������MTA����Ϣ�ṹ��ֵ */
    stAtMtaModemCapUpdate.enModemCapUpdateType = AT_MTA_MODEM_CAP_UPDATE_TYPE_ACTIVE_MODEM;

    /* ������Ϣ��C�˴��� */
    if (AT_SUCCESS != AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                             0,
                                             ID_AT_MTA_MODEM_CAP_UPDATE_REQ,
                                             &stAtMtaModemCapUpdate,
                                             (VOS_UINT32)sizeof(AT_MTA_MODEM_CAP_UPDATE_REQ_STRU),
                                             I0_UEPS_PID_MTA))
    {
        AT_WARN_LOG("AT_SetActiveModem(): Snd MTA Req Failed!");

        return AT_ERROR;
    }

    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_MODEM_CAP_UPDATE_SET;

    return AT_WAIT_ASYNC_RETURN;
}




VOS_UINT32 AT_SetLteLowPowerPara(VOS_UINT8 ucIndex)
{
    AT_MTA_LOW_POWER_CONSUMPTION_SET_REQ_STRU       stPowerConsumption;
    VOS_UINT32                                      ulRst;

    TAF_MEM_SET_S(&stPowerConsumption, sizeof(stPowerConsumption), 0x00, sizeof(AT_MTA_LOW_POWER_CONSUMPTION_SET_REQ_STRU));

    /* ������� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ������������ȷ */
    if (1 != gucAtParaIndex)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ����Ϊ�� */
    if(0 == gastAtParaList[0].usParaLen)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    switch(gastAtParaList[0].ulParaValue)
    {
        case 0:
            stPowerConsumption.enLteLowPowerFlg = AT_MTA_LTE_LOW_POWER_NORMAL;
            break;

        case 1:
            stPowerConsumption.enLteLowPowerFlg = AT_MTA_LTE_LOW_POWER_LOW;
            break;

        default:
            return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ���Ϳ����Ϣ��C��, ���õ͹��� */
    ulRst = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                   gastAtClientTab[ucIndex].opId,
                                   ID_AT_MTA_LTE_LOW_POWER_SET_REQ,
                                   &stPowerConsumption,
                                   sizeof(stPowerConsumption),
                                   I0_UEPS_PID_MTA);

    if (TAF_SUCCESS != ulRst)
    {
        AT_WARN_LOG("AT_SetLteLowPowerPara: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

    /* ����ATģ��ʵ���״̬Ϊ�ȴ��첽���� */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_LTE_LOW_POWER_CONSUMPTION_SET;

    return AT_WAIT_ASYNC_RETURN;
}


VOS_INT32 AT_GetIsmCoexParaValue(VOS_UINT8 *pucBegain, VOS_UINT8 **ppEnd)
{
    VOS_UINT32 ulTotal      = 0;
    VOS_INT32  lRstTotal    = 0;
    VOS_UINT32 ulRst;
    VOS_UINT8 *pucEnd;
    VOS_UINT32 ulFlag       = 0;

    pucEnd = pucBegain;

    while((' ' != *pucEnd) && ('\0' != *pucEnd))
    {
        pucEnd++;
    }

    if('-' == *pucBegain)
    {
        ulFlag = 1;
        pucBegain++;
    }

    ulRst = atAuc2ul(pucBegain, (VOS_UINT16)(pucEnd - pucBegain), &ulTotal);

    if(AT_SUCCESS != ulRst)
    {
        lRstTotal = AT_COEX_INVALID;
    }
    else
    {
        *ppEnd      = (pucEnd + 1);
        lRstTotal   = (VOS_INT32)(ulFlag ? (0 - ulTotal):ulTotal);
    }

    return lRstTotal;
}


VOS_UINT32 AT_CheckIsmCoexParaValue(VOS_INT32 ulVal, VOS_UINT32 ulParaNum)
{
    VOS_UINT32                          ulRst = AT_SUCCESS;

    switch(ulParaNum)
    {
        case AT_COEX_PARA_COEX_ENABLE:
            if((AT_COEX_PARA_COEX_ENABLE_MIN > ulVal)
            || (AT_COEX_PARA_COEX_ENABLE_MAX < ulVal))
            {
                ulRst = AT_FAILURE;
            }
            break;
        case AT_COEX_PARA_TX_BEGIN:
            if((AT_COEX_PARA_TX_BEGIN_MIN > ulVal)
            || (AT_COEX_PARA_TX_BEGIN_MAX < ulVal))
            {
                ulRst = AT_FAILURE;
            }
            break;
        case AT_COEX_PARA_TX_END:
            if((AT_COEX_PARA_TX_END_MIN > ulVal)
            || (AT_COEX_PARA_TX_END_MAX < ulVal))
            {
                ulRst = AT_FAILURE;
            }
            break;
        case AT_COEX_PARA_TX_POWER:
            if((AT_COEX_PARA_TX_POWER_MIN > ulVal)
            || (AT_COEX_PARA_TX_POWER_MAX < ulVal))
            {
                ulRst = AT_FAILURE;
            }
            break;
        case AT_COEX_PARA_RX_BEGIN:
            if((AT_COEX_PARA_RX_BEGIN_MIN > ulVal)
            || (AT_COEX_PARA_RX_BEGIN_MAX < ulVal))
            {
                ulRst = AT_FAILURE;
            }
            break;
        case AT_COEX_PARA_RX_END:
            if((AT_COEX_PARA_RX_END_MIN > ulVal)
            || (AT_COEX_PARA_RX_END_MAX < ulVal))
            {
                ulRst = AT_FAILURE;
            }
            break;
        default:
            ulRst = AT_FAILURE;
            break;

    }

    return ulRst;
}


VOS_VOID AT_SetL4AIsmCoexParaValue(AT_MTA_LTE_WIFI_COEX_SET_REQ_STRU stIsmCoex, L4A_ISMCOEX_REQ_STRU *pstReqToL4A, VOS_UINT8 ucIndex)
{
    VOS_UINT32                          i;

    pstReqToL4A->stCtrl.ulClientId = gastAtClientTab[ucIndex].usClientId;;
    pstReqToL4A->stCtrl.ulOpId     = 0;
    pstReqToL4A->stCtrl.ulPid      = WUEPS_PID_AT;

    for(i = 0; i < AT_MTA_ISMCOEX_BANDWIDTH_NUM; i++)
    {
        pstReqToL4A->astCoex[i].ulFlag      = (VOS_UINT32)stIsmCoex.astCoexPara[i].enCfg;
        pstReqToL4A->astCoex[i].ulTXBegin   = (VOS_UINT32)stIsmCoex.astCoexPara[i].usTxBegin;
        pstReqToL4A->astCoex[i].ulTXEnd     = (VOS_UINT32)stIsmCoex.astCoexPara[i].usTxEnd;
        pstReqToL4A->astCoex[i].lTXPower    = (VOS_INT32)stIsmCoex.astCoexPara[i].sTxPower;
        pstReqToL4A->astCoex[i].ulRXBegin   = (VOS_UINT32)stIsmCoex.astCoexPara[i].usRxBegin;
        pstReqToL4A->astCoex[i].ulRXEnd     = (VOS_UINT32)stIsmCoex.astCoexPara[i].usRxEnd;
    }

    return;
}


VOS_UINT32 AT_SetIsmCoexPara(VOS_UINT8 ucIndex)
{
    AT_MTA_LTE_WIFI_COEX_SET_REQ_STRU               stIsmCoex;
    L4A_ISMCOEX_REQ_STRU                            stReqToL4A = {0};
    VOS_UINT32                                      ulRst,ulRet;
    VOS_UINT32                                      i, j;
    VOS_INT32                                       ret;
    VOS_UINT16                                     *pusVal;                     /* ��Ҫ�洢��ֵָ�� */
    VOS_UINT8                                      *pucCur;                     /* �����ַ���ʱ�ĵ�ǰָ�� */
    VOS_UINT8                                      *pucPara;                    /* �����ַ���ͷָ�� */

    TAF_MEM_SET_S(&stIsmCoex, sizeof(stIsmCoex), 0x00, sizeof(AT_MTA_LTE_WIFI_COEX_SET_REQ_STRU));

    /* ������� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* �������� */
    if (AT_MTA_ISMCOEX_BANDWIDTH_NUM != gucAtParaIndex)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }


    for(i = 0; i < AT_MTA_ISMCOEX_BANDWIDTH_NUM; i++)
    {
        pucCur = gastAtParaList[i].aucPara;
        stIsmCoex.astCoexPara[i].enCoexBWType = (AT_MTA_COEX_BW_TYPE_ENUM_UINT16)i;
        pusVal = &(stIsmCoex.astCoexPara[i].enCfg);

        for(j = 0; j < sizeof(AT_MTA_COEX_PARA_STRU)/sizeof(VOS_UINT16) - 2; j++)
        {
            pucPara = pucCur;
            ret = AT_GetIsmCoexParaValue(pucPara, &pucCur);

            if(AT_COEX_INVALID == ret)
            {
                return AT_CME_INCORRECT_PARAMETERS;
            }

            if (AT_FAILURE == AT_CheckIsmCoexParaValue(ret, j))
            {
                return AT_CME_INCORRECT_PARAMETERS;
            }

           *pusVal = (VOS_UINT16)ret;
            pusVal++;
        }
    }

    stIsmCoex.usCoexParaNum     = AT_MTA_ISMCOEX_BANDWIDTH_NUM;
    stIsmCoex.usCoexParaSize    = sizeof(stIsmCoex.astCoexPara);

    AT_SetL4AIsmCoexParaValue(stIsmCoex, &stReqToL4A, ucIndex);

    /* ������Ϣ��L4A */
    ulRet = atSendL4aDataMsg(gastAtClientTab[ucIndex].usClientId,
                             I0_MSP_L4_L4A_PID,
                             ID_MSG_L4A_ISMCOEXSET_REQ,
                             (VOS_VOID*)(&stReqToL4A),
                             sizeof(stReqToL4A));

    /* ���Ϳ����Ϣ��C�� */
    ulRst = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                   gastAtClientTab[ucIndex].opId,
                                   ID_AT_MTA_LTE_WIFI_COEX_SET_REQ,
                                   &stIsmCoex,
                                   sizeof(stIsmCoex),
                                   I0_UEPS_PID_MTA);
    if (TAF_SUCCESS != ulRet)
    {
        AT_WARN_LOG("AT_SetIsmCoexPara: atSendDataMsg fail.");
    }

    if (TAF_SUCCESS != ulRst)
    {
        AT_WARN_LOG("AT_SetIsmCoexPara: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

    /* ����ATģ��ʵ���״̬Ϊ�ȴ��첽���� */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_LTE_WIFI_COEX_SET;

    return AT_WAIT_ASYNC_RETURN;
}


VOS_UINT32 AT_QryIsmCoexPara(VOS_UINT8 ucIndex)
{
    VOS_UINT32                                      ulRst;

    if(AT_CMD_OPT_READ_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_ERROR;
    }

    /* ���Ϳ����Ϣ��C��, ��ѯISMCOEX�б����� */
    ulRst = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                   gastAtClientTab[ucIndex].opId,
                                   ID_AT_MTA_LTE_WIFI_COEX_QRY_REQ,
                                   VOS_NULL_PTR,
                                   0,
                                   I0_UEPS_PID_MTA);

    if (TAF_SUCCESS != ulRst)
    {
        AT_WARN_LOG("AT_QryIsmCoexPara: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

    /* ����ATģ��ʵ���״̬Ϊ�ȴ��첽���� */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_LTE_WIFI_COEX_QRY;

    return AT_WAIT_ASYNC_RETURN;
}


VOS_UINT32 AT_RcvMtaLteLowPowerSetCnf(
    VOS_VOID                           *pMsg
)
{
    AT_MTA_MSG_STRU                            *pRcvMsg         = VOS_NULL_PTR;
    MTA_AT_RESULT_CNF_STRU                     *pstMtaCnf       = VOS_NULL_PTR;
    VOS_UINT32                                  ulResult;
    VOS_UINT8                                   ucIndex;

    /* ��ʼ�� */
    pRcvMsg             = (AT_MTA_MSG_STRU *)pMsg;
    pstMtaCnf           = (MTA_AT_RESULT_CNF_STRU *)pRcvMsg->aucContent;
    ulResult            = AT_OK;
    ucIndex             = 0;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaLteLowPowerSetCnf : WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaLteLowPowerSetCnf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_LTE_LOW_POWER_CONSUMPTION_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaLteLowPowerSetCnf : Current Option is not AT_CMD_LTE_LOW_POWER_CONSUMPTION_SET.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    gstAtSendData.usBufLen = 0;

    if (VOS_OK != pstMtaCnf->enResult)
    {
        ulResult = AT_ERROR;
    }

    /* ������ */
    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}


VOS_UINT32 AT_RcvMtaIsmCoexSetCnf(
    VOS_VOID                           *pMsg
)
{
    AT_MTA_MSG_STRU                            *pRcvMsg         = VOS_NULL_PTR;
    MTA_AT_RESULT_CNF_STRU                     *pstCnf          = VOS_NULL_PTR;
    VOS_UINT32                                  ulResult;
    VOS_UINT8                                   ucIndex;

    /* ��ʼ�� */
    pRcvMsg             = (AT_MTA_MSG_STRU *)pMsg;
    pstCnf              = (MTA_AT_RESULT_CNF_STRU *)pRcvMsg->aucContent;
    ulResult            = AT_OK;
    ucIndex             = 0;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaIsmCoexSetCnf : WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaIsmCoexSetCnf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_LTE_WIFI_COEX_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaIsmCoexSetCnf : Current Option is not AT_CMD_LTE_WIFI_COEX_SET.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    gstAtSendData.usBufLen = 0;

    if (VOS_OK != pstCnf->enResult)
    {
        ulResult = AT_ERROR;
    }

    /* ������ */
    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}


VOS_UINT32 AT_RcvL4AIsmCoexSetCnf(
    VOS_VOID                           *pMsg
)
{
    return VOS_OK;
}



VOS_UINT32 AT_RcvMtaIsmCoexQryCnf(
    VOS_VOID                           *pMsg
)
{
    AT_MTA_MSG_STRU                            *pRcvMsg         = VOS_NULL_PTR;
    MTA_AT_LTE_WIFI_COEX_QRY_CNF_STRU          *pstCnf          = VOS_NULL_PTR;
    VOS_UINT32                                  ulResult;
    VOS_UINT32                                  i;
    VOS_UINT8                                   ucIndex;

    /* ��ʼ�� */
    pRcvMsg             = (AT_MTA_MSG_STRU *)pMsg;
    pstCnf              = (MTA_AT_LTE_WIFI_COEX_QRY_CNF_STRU *)pRcvMsg->aucContent;
    ulResult            = AT_OK;
    ucIndex             = 0;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaIsmCoexQryCnf : WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaIsmCoexQryCnf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_LTE_WIFI_COEX_QRY != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaIsmCoexQryCnf : Current Option is not AT_CMD_LTE_WIFI_COEX_QRY.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    gstAtSendData.usBufLen = 0;

    gstAtSendData.usBufLen += (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                    (TAF_CHAR *)pgucAtSndCodeAddr,
                                                    (TAF_CHAR *)pgucAtSndCodeAddr,
                                                    "%s:",
                                                    g_stParseContext[ucIndex].pstCmdElement->pszCmdName);

    for(i = 0; i < AT_MTA_ISMCOEX_BANDWIDTH_NUM; i++)
    {
        gstAtSendData.usBufLen += (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                        (VOS_CHAR *)pgucAtSndCodeAddr,
                                                        (VOS_CHAR*)pgucAtSndCodeAddr + gstAtSendData.usBufLen,
                                                        " %d %d %d %d %d %d,",
                                                        pstCnf->astCoexPara[i].enCfg,
                                                        pstCnf->astCoexPara[i].usTxBegin,
                                                        pstCnf->astCoexPara[i].usTxEnd,
                                                        pstCnf->astCoexPara[i].sTxPower,
                                                        pstCnf->astCoexPara[i].usRxBegin,
                                                        pstCnf->astCoexPara[i].usRxEnd);
    }

    gstAtSendData.usBufLen--;

    /* ������ */
    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}


VOS_UINT32 AT_ProLCaCfgPara(
    AT_MTA_CA_CFG_SET_REQ_STRU                     *pstCaCfgReq
)
{
    VOS_UINT32                              ulParaIndex;
    VOS_UINT32                              i;

    /* �������Ϊʹ�ܣ�ֻ��Ҫһ������ */
    if (1 == gastAtParaList[0].ulParaValue)
    {
        pstCaCfgReq->ucCaActFlag = (VOS_UINT8)gastAtParaList[0].ulParaValue;
        return AT_OK;
    }
    /* �������Ϊȥʹ�ܣ�������Ҫ������������ */
    if ( (3 > gucAtParaIndex)
      || (0 == gastAtParaList[1].usParaLen)
      || (0 == gastAtParaList[2].usParaLen))
    {
        AT_WARN_LOG("AT_ProLCaCfgPara: para num is error or para len is 0.");
        return AT_ERROR;
    }

    /* band numֵ��band�����Բ��� */
    if ((gucAtParaIndex - AT_MTA_BAND_INFO_OFFSET) != gastAtParaList[2].ulParaValue)
    {
        AT_WARN_LOG("AT_ProLCaCfgPara: para num is error.");
        return AT_ERROR;
    }

    pstCaCfgReq->ucCaActFlag            = (VOS_UINT8)gastAtParaList[0].ulParaValue;
    pstCaCfgReq->stCaInfo.ucCaA2Flg     = ((VOS_UINT8)gastAtParaList[1].ulParaValue) & (0x01);
    pstCaCfgReq->stCaInfo.ucCaA4Flg     = (((VOS_UINT8)gastAtParaList[1].ulParaValue) & (0x02)) >> 1;
    pstCaCfgReq->stCaInfo.ucCaCqiFlg    = (((VOS_UINT8)gastAtParaList[1].ulParaValue) & (0x04)) >> 2;
    pstCaCfgReq->stCaInfo.usBandNum     = (VOS_UINT16)gastAtParaList[2].ulParaValue;

    for (i = 0; i < pstCaCfgReq->stCaInfo.usBandNum; i++)
    {
        ulParaIndex = AT_MTA_BAND_INFO_OFFSET + i;

        if (AT_FAILURE == At_AsciiNum2HexString(gastAtParaList[ulParaIndex].aucPara, &(gastAtParaList[ulParaIndex].usParaLen)))
        {
            return AT_ERROR;
        }

        if ((AT_MTA_BAND_INFO_LEN / 2) != gastAtParaList[ulParaIndex].usParaLen)
        {
            AT_WARN_LOG("AT_ProLCaCfgPara: para len is error.");
            return AT_ERROR;
        }

        TAF_MEM_CPY_S(&(pstCaCfgReq->stCaInfo.astBandInfo[i]),
                      (VOS_SIZE_T)sizeof(pstCaCfgReq->stCaInfo.astBandInfo[i]),
                      gastAtParaList[ulParaIndex].aucPara,
                      gastAtParaList[ulParaIndex].usParaLen);
    }

    return AT_OK;
}


VOS_UINT32 AT_SetLCaCfgPara(VOS_UINT8 ucIndex)
{
    AT_MTA_CA_CFG_SET_REQ_STRU                      stCaCfgReq;
    VOS_UINT32                                      ulRst;

    TAF_MEM_SET_S(&stCaCfgReq, sizeof(stCaCfgReq), 0x00, sizeof(AT_MTA_CA_CFG_SET_REQ_STRU));

    /* ������� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ������������ȷ */
    if ( (1 > gucAtParaIndex)
      || (11 < gucAtParaIndex))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ����Ϊ�� */
    if (0 == gastAtParaList[0].usParaLen)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ������Ч�Լ�� */
    if (AT_ERROR == AT_ProLCaCfgPara(&stCaCfgReq))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ���Ϳ����Ϣ��C��, ���õ͹��� */
    ulRst = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                   gastAtClientTab[ucIndex].opId,
                                   ID_AT_MTA_LTE_CA_CFG_SET_REQ,
                                   &stCaCfgReq,
                                   sizeof(stCaCfgReq),
                                   I0_UEPS_PID_MTA);

    if (TAF_SUCCESS != ulRst)
    {
        AT_WARN_LOG("AT_SetLCaCfgPara: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

    /* ����ATģ��ʵ���״̬Ϊ�ȴ��첽���� */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_LTE_CA_CFG_SET;

    return AT_WAIT_ASYNC_RETURN;
}


VOS_UINT32 AT_RcvMtaLteCaCfgSetCnf(
    VOS_VOID                           *pMsg
)
{
    AT_MTA_MSG_STRU                                *pRcvMsg         = VOS_NULL_PTR;
    MTA_AT_RESULT_CNF_STRU                         *pstMtaCnf       = VOS_NULL_PTR;
    VOS_UINT32                                      ulResult;
    VOS_UINT8                                       ucIndex;

    /* ��ʼ�� */
    pRcvMsg             = (AT_MTA_MSG_STRU *)pMsg;
    pstMtaCnf           = (MTA_AT_RESULT_CNF_STRU *)pRcvMsg->aucContent;
    ulResult            = AT_OK;
    ucIndex             = 0;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaLteCaCfgSetCnf : WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaLteCaCfgSetCnf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_LTE_CA_CFG_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaLteCaCfgSetCnf : Current Option is not AT_CMD_LTE_CA_CFG_SET.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    gstAtSendData.usBufLen = 0;

    if (VOS_OK != pstMtaCnf->enResult)
    {
        ulResult = AT_ERROR;
    }
    else
    {
        ulResult = AT_OK;
    }

    /* ������ */
    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}


VOS_UINT32 AT_QryLCaCellExPara(VOS_UINT8 ucIndex)
{
    VOS_UINT32                                      ulRst;

    if(AT_CMD_OPT_READ_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_ERROR;
    }

    /* ���Ϳ����Ϣ��C��, ��ѯLCACELLEX�б����� */
    ulRst = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                   gastAtClientTab[ucIndex].opId,
                                   ID_AT_MTA_LTE_CA_CELLEX_QRY_REQ,
                                   VOS_NULL_PTR,
                                   0,
                                   I0_UEPS_PID_MTA);

    if (TAF_SUCCESS != ulRst)
    {
        AT_WARN_LOG("AT_QryLCaCellExPara: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

    /* ����ATģ��ʵ���״̬Ϊ�ȴ��첽���� */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_LTE_CA_CELLEX_QRY;

    return AT_WAIT_ASYNC_RETURN;
}


VOS_UINT32 AT_RcvMtaLteCaCellExQryCnf(
    VOS_VOID                           *pMsg
)
{
    AT_MTA_MSG_STRU                            *pRcvMsg         = VOS_NULL_PTR;
    MTA_AT_CA_CELL_INFO_CNF_STRU               *pstCnf          = VOS_NULL_PTR;
    VOS_UINT32                                  ulResult;
    VOS_UINT32                                  i;
    VOS_UINT8                                   ucIndex;

    /* ��ʼ�� */
    pRcvMsg             = (AT_MTA_MSG_STRU *)pMsg;
    pstCnf              = (MTA_AT_CA_CELL_INFO_CNF_STRU *)pRcvMsg->aucContent;
    ulResult            = AT_OK;
    ucIndex             = 0;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaLteCaCellExQryCnf : WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaLteCaCellExQryCnf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_LTE_CA_CELLEX_QRY != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaLteCaCellExQryCnf : Current Option is not AT_CMD_LTE_CA_CELLEX_QRY.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    gstAtSendData.usBufLen = 0;

    if (MTA_AT_RESULT_NO_ERROR != pstCnf->enResult)
    {
        ulResult = AT_ERROR;
    }
    else
    {
        ulResult = AT_OK;

        pstCnf->ulTotalCellNum = (pstCnf->ulTotalCellNum < MTA_AT_CA_MAX_CELL_NUM) ?
                                  pstCnf->ulTotalCellNum : MTA_AT_CA_MAX_CELL_NUM;

        for (i = 0; i < pstCnf->ulTotalCellNum; i++)
        {
            gstAtSendData.usBufLen += (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                            (VOS_CHAR *)pgucAtSndCodeAddr,
                                                            (VOS_CHAR*)pgucAtSndCodeAddr + gstAtSendData.usBufLen,
                                                            "%s: %d,%d,%d,%d,%d,%d,%d,%d",
                                                            g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                                            pstCnf->astCellInfo[i].ucCellIndex,
                                                            pstCnf->astCellInfo[i].ucUlConfigured,
                                                            pstCnf->astCellInfo[i].ucDlConfigured,
                                                            pstCnf->astCellInfo[i].ucActived,
                                                            pstCnf->astCellInfo[i].ucLaaScellFlg,
                                                            pstCnf->astCellInfo[i].usBandInd,
                                                            pstCnf->astCellInfo[i].enBandWidth,
                                                            pstCnf->astCellInfo[i].ulEarfcn);
            if (i != pstCnf->ulTotalCellNum - 1)
            {
                gstAtSendData.usBufLen += (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                            (VOS_CHAR *)pgucAtSndCodeAddr,
                                                            (VOS_CHAR*)pgucAtSndCodeAddr + gstAtSendData.usBufLen,
                                                            "%s",
                                                            gaucAtCrLf);
            }
        }
    }

    /* ������ */
    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}


VOS_UINT32 AT_RcvMtaLteCaCellExInfoNtf(
    VOS_VOID                           *pMsg
)
{
    VOS_UINT8                           ucIndex;
    AT_MTA_MSG_STRU                    *pstMtaMsg           = VOS_NULL_PTR;
    MTA_AT_CA_CELL_INFO_NTF_STRU       *pstCaCellInfoNtf    = VOS_NULL_PTR;
    VOS_UINT32                          i;

    /* ��ʼ����Ϣ���� */
    ucIndex             = 0;
    pstMtaMsg           = (AT_MTA_MSG_STRU*)pMsg;
    pstCaCellInfoNtf    = (MTA_AT_CA_CELL_INFO_NTF_STRU*)pstMtaMsg->aucContent;

    /* ͨ��ClientId��ȡucIndex */
    if ( AT_FAILURE == At_ClientIdToUserId(pstMtaMsg->stAppCtrl.usClientId, &ucIndex) )
    {
        AT_WARN_LOG("AT_RcvMtaLteCaCellExInfoNtf: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    gstAtSendData.usBufLen = 0;

    for (i = 0; i < pstCaCellInfoNtf->ulTotalCellNum; i++)
    {
        gstAtSendData.usBufLen += (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                        (VOS_CHAR *)pgucAtSndCodeAddr,
                                                        (VOS_CHAR*)pgucAtSndCodeAddr + gstAtSendData.usBufLen,
                                                        "%s%s%d,%d,%d,%d,%d,%d,%d,%d,%d",
                                                        gaucAtCrLf,
                                                        gastAtStringTab[AT_STRING_LCACELLEX].pucText,
                                                        pstCaCellInfoNtf->ulTotalCellNum,
                                                        pstCaCellInfoNtf->astCellInfo[i].ucCellIndex,
                                                        pstCaCellInfoNtf->astCellInfo[i].ucUlConfigured,
                                                        pstCaCellInfoNtf->astCellInfo[i].ucDlConfigured,
                                                        pstCaCellInfoNtf->astCellInfo[i].ucActived,
                                                        pstCaCellInfoNtf->astCellInfo[i].ucLaaScellFlg,
                                                        pstCaCellInfoNtf->astCellInfo[i].usBandInd,
                                                        pstCaCellInfoNtf->astCellInfo[i].enBandWidth,
                                                        pstCaCellInfoNtf->astCellInfo[i].ulEarfcn);

        if (i == pstCaCellInfoNtf->ulTotalCellNum - 1)
        {
            gstAtSendData.usBufLen += (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                        (VOS_CHAR *)pgucAtSndCodeAddr,
                                                        (VOS_CHAR*)pgucAtSndCodeAddr + gstAtSendData.usBufLen,
                                                        "%s",
                                                        gaucAtCrLf);
        }
    }

    At_SendResultData(ucIndex, pgucAtSndCodeAddr, gstAtSendData.usBufLen);

    return VOS_OK;
}



VOS_UINT32 AT_SetLcaCellRptCfgPara(VOS_UINT8 ucIndex)
{
    AT_MTA_CA_CELL_SET_REQ_STRU    stCACellType;
    VOS_UINT32                     ulRst;

    TAF_MEM_SET_S(&stCACellType, sizeof(stCACellType), 0x00, sizeof(AT_MTA_CA_CELL_SET_REQ_STRU));

    /* ������� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* �������������ȼ�� */
    if ( (1 != gucAtParaIndex)
      || (0 == gastAtParaList[0].usParaLen))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    stCACellType.blEnableType = gastAtParaList[0].ulParaValue;

    /* ���Ϳ����Ϣ��C�� */
    ulRst = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                   gastAtClientTab[ucIndex].opId,
                                   ID_AT_MTA_LTE_CA_CELL_RPT_CFG_SET_REQ,
                                   &stCACellType,
                                   sizeof(stCACellType),
                                   I0_UEPS_PID_MTA);

    if (TAF_SUCCESS != ulRst)
    {
        AT_WARN_LOG("AT_SetLcaCellRptCfgPara: AT_SetLcaCellRptCfgPara fail.");
        return AT_ERROR;
    }

    /* ����ATģ��ʵ���״̬Ϊ�ȴ��첽���� */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_LCACELLRPTCFG_SET;

    return AT_WAIT_ASYNC_RETURN;
}


VOS_UINT32 AT_RcvMtaCACellSetCnf(
    VOS_VOID                           *pMsg
)
{
    AT_MTA_MSG_STRU                                *pRcvMsg         = VOS_NULL_PTR;
    MTA_AT_CA_CELL_SET_CNF_STRU                    *pstMtaCnf       = VOS_NULL_PTR;
    VOS_UINT32                                      ulResult;
    VOS_UINT8                                       ucIndex;

    /* ��ʼ�� */
    pRcvMsg             = (AT_MTA_MSG_STRU *)pMsg;
    pstMtaCnf           = (MTA_AT_CA_CELL_SET_CNF_STRU *)pRcvMsg->aucContent;
    ulResult            = AT_OK;
    ucIndex             = 0;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaCACellSetCnf : WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaCACellSetCnf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_LCACELLRPTCFG_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaCACellSetCnf : Current Option is not AT_CMD_LCACELLRPTCFG_SET.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    gstAtSendData.usBufLen = 0;

    if (VOS_OK != pstMtaCnf->enResult)
    {
        ulResult = AT_ERROR;
    }
    else
    {
        ulResult = AT_OK;
    }

    /* ������ */
    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}


VOS_UINT32 AT_QryLcaCellRptCfgPara(VOS_UINT8 ucIndex)
{
    VOS_UINT32                                      ulRst;

    if(AT_CMD_OPT_READ_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_ERROR;
    }

    /* ���Ϳ����Ϣ��C��, ��ѯLCACELLRPTCFG�б����� */
    ulRst = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                   gastAtClientTab[ucIndex].opId,
                                   ID_AT_MTA_LTE_CA_CELL_RPT_CFG_QRY_REQ,
                                   VOS_NULL_PTR,
                                   0,
                                   I0_UEPS_PID_MTA);

    if (TAF_SUCCESS != ulRst)
    {
        AT_WARN_LOG("AT_QryLcaCellRptCfgPara: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

    /* ����ATģ��ʵ���״̬Ϊ�ȴ��첽���� */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_LCACELLRPTCFG_QRY;

    return AT_WAIT_ASYNC_RETURN;
}


VOS_UINT32 AT_RcvMtaCACellQryCnf(
    VOS_VOID                           *pMsg
)
{
    AT_MTA_MSG_STRU                                *pRcvMsg         = VOS_NULL_PTR;
    MTA_AT_CA_CELL_QRY_CNF_STRU                    *pstMtaCnf       = VOS_NULL_PTR;
    VOS_UINT32                                      ulResult;
    VOS_UINT8                                       ucIndex;

    /* ��ʼ�� */
    pRcvMsg             = (AT_MTA_MSG_STRU *)pMsg;
    pstMtaCnf           = (MTA_AT_CA_CELL_QRY_CNF_STRU *)pRcvMsg->aucContent;
    ulResult            = AT_OK;
    ucIndex             = 0;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaCACellQryCnf : WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaCACellQryCnf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_LCACELLRPTCFG_QRY != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaCACellQryCnf : Current Option is not AT_CMD_LCACELLRPTCFG_QRY.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    gstAtSendData.usBufLen = 0;

    if (VOS_OK != pstMtaCnf->enResult)
    {
        ulResult = AT_ERROR;
    }
    else
    {
        gstAtSendData.usBufLen += (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                        (TAF_CHAR *)pgucAtSndCodeAddr,
                                                        (TAF_CHAR *)pgucAtSndCodeAddr,
                                                        "%s: %d",
                                                        g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                                        pstMtaCnf->blEnableType);
    }

    /* ������ */
    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}


VOS_UINT32 AT_SetFineTimeReqPara(VOS_UINT8 ucIndex)
{
    AT_MTA_FINE_TIME_SET_REQ_STRU      stFineTimeType;
    VOS_UINT32                     ulRst;

    TAF_MEM_SET_S(&stFineTimeType, sizeof(stFineTimeType), 0x00, sizeof(AT_MTA_FINE_TIME_SET_REQ_STRU));

    /* ������� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ����������� */
    if (1 != gucAtParaIndex)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    if (0 == gastAtParaList[0].usParaLen)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    stFineTimeType.ucFineTimeType = (VOS_UINT8)gastAtParaList[0].ulParaValue;

    /* ���Ϳ����Ϣ��C�� */
    ulRst = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                   gastAtClientTab[ucIndex].opId,
                                   ID_AT_MTA_LTE_FINE_TIME_SET_REQ,
                                   &stFineTimeType,
                                   sizeof(stFineTimeType),
                                   I0_UEPS_PID_MTA);

    if (TAF_SUCCESS != ulRst)
    {
        AT_WARN_LOG("AT_SetFineTimeReqPara: AT_SetFineTimeReqPara fail.");
        return AT_ERROR;
    }

    /* ����ATģ��ʵ���״̬Ϊ�ȴ��첽���� */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_LTE_FINE_TIME_SET;

    return AT_WAIT_ASYNC_RETURN;
}


VOS_UINT32 AT_RcvMtaFineTimeSetCnf(
    VOS_VOID                           *pMsg
)
{
    AT_MTA_MSG_STRU                                *pRcvMsg         = VOS_NULL_PTR;
    MTA_AT_FINE_TIME_SET_CNF_STRU                  *pstMtaCnf       = VOS_NULL_PTR;
    VOS_UINT32                                      ulResult;
    VOS_UINT8                                       ucIndex;

    /* ��ʼ�� */
    pRcvMsg             = (AT_MTA_MSG_STRU *)pMsg;
    pstMtaCnf           = (MTA_AT_FINE_TIME_SET_CNF_STRU *)pRcvMsg->aucContent;
    ulResult            = AT_OK;
    ucIndex             = 0;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaFineTimeSetCnf : WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaFineTimeSetCnf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_LTE_FINE_TIME_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaFineTimeSetCnf : Current Option is not AT_CMD_LTE_FINE_TIME_SET.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    gstAtSendData.usBufLen = 0;

    if (VOS_OK != pstMtaCnf->enResult)
    {
        ulResult = AT_ERROR;
    }
    else
    {
        ulResult = AT_OK;
    }

    /* ������ */
    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}


VOS_UINT32 AT_RcvMtaSibFineTimeNtf(
    VOS_VOID                           *pstMsg
)
{
    AT_MTA_MSG_STRU                    *pstRcvMsg          = VOS_NULL_PTR;
    MTA_AT_SIB_FINE_TIME_IND_STRU      *pstSibFineTime     = VOS_NULL_PTR;
    VOS_UINT8                           ucIndex;


    /* ��ʼ����Ϣ���� */
    pstRcvMsg           = (AT_MTA_MSG_STRU *)pstMsg;
    pstSibFineTime      = (MTA_AT_SIB_FINE_TIME_IND_STRU *)pstRcvMsg->aucContent;
    ucIndex             = 0;

    /* ͨ��ClientId��ȡucIndex */
    if ( AT_FAILURE == At_ClientIdToUserId(pstRcvMsg->stAppCtrl.usClientId, &ucIndex) )
    {
        AT_WARN_LOG("AT_RcvMtaSibFineTimeNtf: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaSibFineTimeNtf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    gstAtSendData.usBufLen = 0;

    if (VOS_OK != pstSibFineTime->enResult)
    {
        /* ������ */
        At_FormatResultData(ucIndex, AT_ERROR);
    }
    else
    {
        /* "^FINETIMEINFO: */
        gstAtSendData.usBufLen += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                             (VOS_CHAR *)pgucAtSndCodeAddr,
                                                             (VOS_CHAR *)pgucAtSndCodeAddr + gstAtSendData.usBufLen,
                                                             "%s%s%d,%d,%d,%d,%s,%s",
                                                             gaucAtCrLf,
                                                             gastAtStringTab[AT_STRING_FINETIMEINFO].pucText,
                                                             pstSibFineTime->enRat,
                                                             pstSibFineTime->sTa,
                                                             pstSibFineTime->lSinr,
                                                             pstSibFineTime->enState,
                                                             pstSibFineTime->aucUtcTime,
                                                             pstSibFineTime->aucUtcTimeOffset);

        if(VOS_TRUE == pstSibFineTime->ucLeapSecondValid)
        {
            gstAtSendData.usBufLen += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                             (VOS_CHAR *)pgucAtSndCodeAddr,
                                                             (VOS_CHAR *)pgucAtSndCodeAddr + gstAtSendData.usBufLen,
                                                             ",%d%s",
                                                             pstSibFineTime->sLeapSecond,
                                                             gaucAtCrLf);
        }
        else
        {
            gstAtSendData.usBufLen += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                            (VOS_CHAR *)pgucAtSndCodeAddr,
                                                            (VOS_CHAR *)pgucAtSndCodeAddr + gstAtSendData.usBufLen,
                                                            "%s",
                                                            gaucAtCrLf);
        }

        /* ������ */
        At_SendResultData(ucIndex, pgucAtSndCodeAddr, gstAtSendData.usBufLen);
    }

    return VOS_OK;

}


VOS_UINT32 AT_RcvMtaLppFineTimeNtf(
    VOS_VOID                           *pstMsg
)
{
    AT_MTA_MSG_STRU                    *pstRcvMsg          = VOS_NULL_PTR;
    MTA_AT_LPP_FINE_TIME_IND_STRU      *pstLppFineTime     = VOS_NULL_PTR;
    VOS_UINT8                           ucIndex;

    /* ��ʼ����Ϣ���� */
    pstRcvMsg           = (AT_MTA_MSG_STRU *)pstMsg;
    pstLppFineTime      = (MTA_AT_LPP_FINE_TIME_IND_STRU *)pstRcvMsg->aucContent;
    ucIndex             = 0;

    /* ͨ��ClientId��ȡucIndex */
    if ( AT_FAILURE == At_ClientIdToUserId(pstRcvMsg->stAppCtrl.usClientId, &ucIndex) )
    {
        AT_WARN_LOG("AT_RcvMtaLppFineTimeNtf: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaLppFineTimeNtf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    gstAtSendData.usBufLen = 0;

    if (VOS_OK != pstLppFineTime->enResult)
    {
        /* ������ */
        At_FormatResultData(ucIndex, AT_ERROR);
    }
    else
    {
        /* "^SFN: */
        gstAtSendData.usBufLen += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                           (VOS_CHAR *)pgucAtSndCodeAddr,
                                           (VOS_CHAR *)pgucAtSndCodeAddr + gstAtSendData.usBufLen,
                                           "%s%s%d%s",
                                           gaucAtCrLf,
                                           gastAtStringTab[AT_STRING_SFN].pucText,
                                           pstLppFineTime->usSysFn,
                                           gaucAtCrLf);
        /* ������ */
        At_SendResultData(ucIndex, pgucAtSndCodeAddr, gstAtSendData.usBufLen);
    }


    return VOS_OK;

}


VOS_UINT32 AT_SetCenfsPara(VOS_UINT8 ucIndex)
{
    AT_MTA_UNSOLICITED_RPT_SET_REQ_STRU stAtCmd;
    VOS_UINT32                          ulResult;

    TAF_MEM_SET_S(&stAtCmd, sizeof(stAtCmd), 0x00, sizeof(stAtCmd));

    /* ������� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* �������� */
    if (gucAtParaIndex > 1)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ����Ϊ�� */
    if (0 == gastAtParaList[0].usParaLen)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    stAtCmd.enReqType       = AT_MTA_SET_CENFS_RPT_TYPE;
    stAtCmd.u.ucCenfsRptFlg = (VOS_UINT8)gastAtParaList[0].ulParaValue;

    /* ��MTA���������ϱ������������� */
    ulResult = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                      0,
                                      ID_AT_MTA_UNSOLICITED_RPT_SET_REQ,
                                      &stAtCmd,
                                      sizeof(AT_MTA_UNSOLICITED_RPT_SET_REQ_STRU),
                                      I0_UEPS_PID_MTA);

    if (TAF_SUCCESS != ulResult)
    {
        AT_WARN_LOG("AT_SetCenfsPara: AT_FillAndSndAppReqMsg Failed!");
        return AT_ERROR;
    }

    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_UNSOLICITED_RPT_SET;

    return AT_WAIT_ASYNC_RETURN;
}


VOS_UINT32 AT_QryCenfsPara(VOS_UINT8 ucIndex)
{
    VOS_UINT32                          ulResult;

    /* ������� */
    if (AT_CMD_OPT_READ_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ��MTA���������ϱ������������� */
    ulResult = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                      0,
                                      ID_AT_MTA_EPS_NETWORK_QRY_REQ,
                                      VOS_NULL_PTR,
                                      0,
                                      I0_UEPS_PID_MTA);

    if (TAF_SUCCESS != ulResult)
    {
        AT_WARN_LOG("AT_QryCenfsPara: AT_FillAndSndAppReqMsg Failed!");
        return AT_ERROR;
    }

    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_CENFS_QRY;

    return AT_WAIT_ASYNC_RETURN;
}


VOS_UINT16 AT_PrintEpsNetworkInfo(
    MTA_AT_EPS_NETWORK_INFO_STRU       *pstEpsNetworkInfo,
    VOS_UINT8                           bCrlfFlg
)
{
    VOS_UINT32                          ulLoop;
    VOS_UINT16                          usLength;

    usLength = 0;

    /* ^CENFS: <plmn>,<IE> */
    if (VOS_TRUE == bCrlfFlg)
    {
        usLength = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                          (VOS_CHAR *)pgucAtSndCodeAddr,
                                          (VOS_CHAR *)pgucAtSndCodeAddr,
                                          "%s",
                                          gaucAtCrLf);
    }

    usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                       (VOS_CHAR *)pgucAtSndCodeAddr,
                                       (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                       "^CENFS: %X%X%X",
                                       (0x0F00 & pstEpsNetworkInfo->ulMcc) >> 8,
                                       (0x00F0 & pstEpsNetworkInfo->ulMcc) >> 4,
                                       (0x000F & pstEpsNetworkInfo->ulMcc));

    if ( 0x000F == (0x000F & pstEpsNetworkInfo->ulMnc) )
    {
        usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                           (VOS_CHAR *)pgucAtSndCodeAddr,
                                           (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                           "%X%X,\"",
                                           (0x0F00 & pstEpsNetworkInfo->ulMnc) >> 8,
                                           (0x00F0 & pstEpsNetworkInfo->ulMnc) >> 4);
    }
    else
    {
        usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                           (VOS_CHAR *)pgucAtSndCodeAddr,
                                           (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                           "%X%X%X,\"",
                                           (0x0F00 & pstEpsNetworkInfo->ulMnc) >> 8,
                                           (0x00F0 & pstEpsNetworkInfo->ulMnc) >> 4,
                                           (0x000F & pstEpsNetworkInfo->ulMnc));
    }

    for (ulLoop = 0; ulLoop < pstEpsNetworkInfo->ucLength; ulLoop++)
    {
        usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                           (VOS_CHAR *)pgucAtSndCodeAddr,
                                           (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                           "%02X",
                                           pstEpsNetworkInfo->aucEpsNetwork[ulLoop]);
    }

    usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                       (VOS_CHAR *)pgucAtSndCodeAddr,
                                       (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                       "\"");

    if (VOS_TRUE == bCrlfFlg)
    {
        usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                           (VOS_CHAR *)pgucAtSndCodeAddr,
                                           (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                           "%s",
                                           gaucAtCrLf);
    }

    return usLength;
}


VOS_UINT32 AT_RcvMtaEpsNetworkInfoInd(
    VOS_VOID                           *pMsg
)
{
    AT_MTA_MSG_STRU                    *pRcvMsg     = VOS_NULL_PTR;
    MTA_AT_EPS_NETWORK_INFO_STRU       *pstMtaInd   = VOS_NULL_PTR;
    VOS_UINT8                           ucIndex;

    /* ��ʼ�� */
    pRcvMsg             = (AT_MTA_MSG_STRU *)pMsg;
    pstMtaInd           = (MTA_AT_EPS_NETWORK_INFO_STRU *)pRcvMsg->aucContent;
    ucIndex             = 0;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaEpsNetworkInfoInd: WARNING: AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    /* ��ӡ��������ϱ���� */
    gstAtSendData.usBufLen = AT_PrintEpsNetworkInfo(pstMtaInd, VOS_TRUE);

    /* ������ */
    At_SendResultData(ucIndex, pgucAtSndCodeAddr, gstAtSendData.usBufLen);

    return VOS_OK;
}


VOS_UINT32 AT_RcvMtaEpsNetworkQryCnf(
    VOS_VOID                           *pMsg
)
{
    AT_MTA_MSG_STRU                    *pRcvMsg     = VOS_NULL_PTR;
    MTA_AT_EPS_NETWORK_QRY_CNF_STRU    *pstMtaCnf   = VOS_NULL_PTR;
    VOS_UINT32                          ulResult;
    VOS_UINT8                           ucIndex;

    /* ��ʼ�� */
    pRcvMsg             = (AT_MTA_MSG_STRU *)pMsg;
    pstMtaCnf           = (MTA_AT_EPS_NETWORK_QRY_CNF_STRU *)pRcvMsg->aucContent;
    ulResult            = AT_OK;
    ucIndex             = 0;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaEpsNetworkQryCnf: WARNING: AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    /* ��ѯ������ͨ���ǹ㲥 */
    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaEpsNetworkQryCnf: AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_CENFS_QRY != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaEpsNetworkQryCnf: Current Option is not AT_CMD_CENFS_QRY.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    if (MTA_AT_RESULT_NO_ERROR != pstMtaCnf->enResult)
    {
        ulResult                = AT_ConvertMtaResult(pstMtaCnf->enResult);
        gstAtSendData.usBufLen  = 0;
    }
    else
    {
        ulResult                = AT_OK;

        /* ��ӡ��������� */
        gstAtSendData.usBufLen  = AT_PrintEpsNetworkInfo(&pstMtaCnf->stEpsNetworkInfo, VOS_FALSE);
    }

    /* ������ */
    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}




VOS_UINT32 AT_SetLogEnablePara(VOS_UINT8 ucIndex)
{
    /* ������� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ����������� */
    if (1 != gucAtParaIndex)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    if(0 == gastAtParaList[0].usParaLen)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* AT����1��ʾ����ץȡmodemlog������0��ʾ������ץȡmodemlog */
    if (1 == gastAtParaList[0].ulParaValue)
    {
        /* ����ΪFALSE��ʾ����ץMODEM LOG */
        DMS_SET_PRINT_MODEM_LOG_TYPE(VOS_FALSE);
    }
    else
    {
        /* ����ΪTRUE��ʾ������ץMODEM LOG */
        DMS_SET_PRINT_MODEM_LOG_TYPE(VOS_TRUE);
    }

    return AT_OK;
}


VOS_UINT32 AT_QryLogEnable(VOS_UINT8 ucIndex)
{
    VOS_UINT16                          usLength;
    VOS_UINT32                          ulEnableFlag;

    /* ������� */
    if (AT_CMD_OPT_READ_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    usLength                            = 0;

    if (VOS_FALSE == DMS_GET_PRINT_MODEM_LOG_TYPE())
    {
        /* DMS��ǰ����ץMODEM LOG������enableΪTRUE */
        ulEnableFlag = VOS_TRUE;
    }
    else
    {
        /* DMS��ǰ������ץMODEM LOG������enableΪFALSE */
        ulEnableFlag = VOS_FALSE;
    }

    usLength  = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                       (VOS_CHAR*)pgucAtSndCodeAddr,
                                       (VOS_CHAR*)pgucAtSndCodeAddr,
                                       "%s: ",
                                       g_stParseContext[ucIndex].pstCmdElement->pszCmdName);

    usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                       (VOS_CHAR*)pgucAtSndCodeAddr,
                                       (VOS_CHAR*)pgucAtSndCodeAddr + usLength,
                                       "%d",
                                       ulEnableFlag);

    gstAtSendData.usBufLen = usLength;

    return AT_OK;
}




VOS_VOID AT_StopSimlockDataWriteTimer(VOS_UINT8  ucIndex)
{
    AT_SIMLOCKDATAWRITEEX_CMD_PROC_CTX *pstSimlockWriteExCtx;
    VOS_UINT32                          ulTimerName;
    VOS_UINT32                          ulTempIndex;

    pstSimlockWriteExCtx = AT_GetSimLockWriteExCmdCtxAddr();

    ulTempIndex  = (VOS_UINT32)ucIndex;
    ulTimerName  = AT_SIMLOCKWRITEEX_TIMER;
    ulTimerName |= AT_INTERNAL_PROCESS_TYPE;
    ulTimerName |= (ulTempIndex<<12);

    if (VOS_NULL_PTR != pstSimlockWriteExCtx)
    {
        (VOS_VOID)AT_StopRelTimer(ulTimerName, &(pstSimlockWriteExCtx->hSimLockWriteExProtectTimer));
    }

    return;
}

VOS_UINT32  AT_ProcSimlockWriteExData(
    VOS_UINT8                          *pucSimLockData,
    VOS_UINT16                          usParaLen
)
{
    AT_SIMLOCKDATAWRITEEX_CMD_PROC_CTX *pstSimlockWriteExCtx;
    VOS_UINT8                          *pTempData                  = VOS_NULL_PTR;
    VOS_UINT16                          usTotalLen;

    if ((VOS_NULL_PTR == pucSimLockData)
     || (0 == usParaLen))
    {
        AT_ERR_LOG("AT_ProcSimlockWriteExData: NULL Pointer");

        return AT_CME_INCORRECT_PARAMETERS;
    }

    pstSimlockWriteExCtx = AT_GetSimLockWriteExCmdCtxAddr();

    /* ��ǰ��һ���µ����ù��̣��յ����ǵ�һ��AT���� */
    if (VOS_NULL_PTR == pstSimlockWriteExCtx->pucData)
    {
        /*lint -save -e830*/
        pstSimlockWriteExCtx->pucData = (VOS_UINT8 *)PS_MEM_ALLOC(WUEPS_PID_AT, (VOS_UINT32)usParaLen);
        /*lint -restore */
        /* �����ڴ�ʧ�ܣ�ֱ�ӷ��� */
        if (VOS_NULL_PTR == pstSimlockWriteExCtx->pucData)
        {
            AT_ERR_LOG("AT_ProcSimlockWriteExData: first data, Alloc mem fail");

            return AT_CME_MEMORY_FAILURE;
        }

        TAF_MEM_CPY_S(pstSimlockWriteExCtx->pucData, usParaLen, pucSimLockData, usParaLen);

        pstSimlockWriteExCtx->usSimlockDataLen = usParaLen;
    }
    else
    {
        /* ��ǰ�����յ���һ��AT�����Ҫƴ������ */
        usTotalLen = usParaLen + pstSimlockWriteExCtx->usSimlockDataLen;
        /*lint -save -e516*/
        pTempData  = (VOS_UINT8 *)PS_MEM_ALLOC(WUEPS_PID_AT, usTotalLen);
        /*lint -restore */
        /* �����ڴ�ʧ�ܣ�ֱ�ӷ��� */
        if (VOS_NULL_PTR == pTempData)
        {
            AT_ERR_LOG("AT_ProcSimlockWriteExData: Non-first data, Alloc mem fail");

            return AT_CME_MEMORY_FAILURE;
        }

        TAF_MEM_CPY_S(pTempData, usTotalLen, pstSimlockWriteExCtx->pucData, pstSimlockWriteExCtx->usSimlockDataLen);
        TAF_MEM_CPY_S((pTempData + pstSimlockWriteExCtx->usSimlockDataLen), usTotalLen, pucSimLockData, usParaLen);
        /*lint -save -e830*/
        PS_MEM_FREE(WUEPS_PID_AT, pstSimlockWriteExCtx->pucData);
        /*lint -restore */
        pstSimlockWriteExCtx->usSimlockDataLen = usTotalLen;
        pstSimlockWriteExCtx->pucData          = pTempData;
    }

    return AT_SUCCESS;


}

VOS_UINT32 AT_SaveSimlockDataIntoCtx(
    AT_SIMLOCK_WRITE_EX_PARA_STRU *pstSimlockWriteExPara,
    VOS_UINT8                      ucIndex,
    VOS_UINT8                      ucNetWorkFlg)
{
    AT_SIMLOCKDATAWRITEEX_CMD_PROC_CTX                     *pstSimlockWriteExCtx;
    VOS_UINT8                                              *pucSimLockData;
    VOS_UINT8                                              *pucHmac;
    VOS_UINT32                                              ulResult;
    VOS_UINT32                                              ulLayer;
    VOS_UINT32                                              ulTotal;
    VOS_UINT32                                              ulCurIndex;
    VOS_UINT16                                              usSimLockDataLen;
    VOS_UINT16                                              usHmacLen;
    VOS_UINT8                                               ucParaNum;

    /* ������ʼ�� */
    ulLayer           = pstSimlockWriteExPara->ulLayer;
    ulTotal           = pstSimlockWriteExPara->ulTotal;
    ulCurIndex        = pstSimlockWriteExPara->ulIndex;
    usSimLockDataLen  = pstSimlockWriteExPara->usSimLockDataLen;
    usHmacLen         = pstSimlockWriteExPara->usHmacLen;
    ucParaNum         = pstSimlockWriteExPara->ucParaNum;
    pucSimLockData    = pstSimlockWriteExPara->pucSimLockData;
    pucHmac           = pstSimlockWriteExPara->pucHmac;

    pstSimlockWriteExCtx = AT_GetSimLockWriteExCmdCtxAddr();

    /* ��ǰ�������ù����У���һ���յ������� */
    if (VOS_FALSE == pstSimlockWriteExCtx->ucSettingFlag)
    {
        if (1 != ulCurIndex)
        {
            AT_WARN_LOG1("AT_SaveSimlockDataIntoCtx: Invalid ulCurrIndex", pstSimlockWriteExPara->ulIndex);

            return AT_CME_INCORRECT_PARAMETERS;
        }

        /* ���ַ�������ת��Ϊ������������ */
        ulResult = AT_ProcSimlockWriteExData(pucSimLockData, usSimLockDataLen);

        if (AT_SUCCESS != ulResult)
        {
            AT_WARN_LOG1("AT_SaveSimlockDataIntoCtx: AT_ProcSimlockWriteExData fail %d", ulResult);

            return ulResult;
        }

        pstSimlockWriteExCtx->ucNetWorkFlg  = ucNetWorkFlg;
        pstSimlockWriteExCtx->ucClientId    = ucIndex;
        pstSimlockWriteExCtx->ucTotalNum    = (VOS_UINT8)ulTotal;
        pstSimlockWriteExCtx->ucCurIdx      = (VOS_UINT8)ulCurIndex;
        pstSimlockWriteExCtx->ucLayer       = (VOS_UINT8)ulLayer;
        pstSimlockWriteExCtx->ucSettingFlag = VOS_TRUE;
    }
    else
    {
        /* ����ͬһ���û��·� */
        if (ucNetWorkFlg != pstSimlockWriteExCtx->ucNetWorkFlg)
        {
            AT_WARN_LOG2("AT_SaveSimlockDataIntoCtx: ucNetWorkFlg error, PreNetWorkFlg %d, CurNetWorkFlg %d", ucNetWorkFlg, pstSimlockWriteExCtx->ucNetWorkFlg);

            AT_ClearSimLockWriteExCtx();
            AT_StopSimlockDataWriteTimer(ucIndex);

            return AT_CME_INCORRECT_PARAMETERS;
        }

        /* ������ͬһ��ͨ���·����� */
        if (ucIndex != pstSimlockWriteExCtx->ucClientId)
        {
            AT_WARN_LOG2("AT_SaveSimlockDataIntoCtx: port error, ucIndex %d, ucClientId %d", ucIndex, pstSimlockWriteExCtx->ucClientId);

            AT_ClearSimLockWriteExCtx();
            AT_StopSimlockDataWriteTimer(ucIndex);

            return AT_CME_INCORRECT_PARAMETERS;
        }

        /* ��ǰ�Ѿ��������У���ǰ�·���Layer��֮ǰ֮ǰ�·���Layer��ͬ */
        if ((VOS_UINT8)ulLayer != pstSimlockWriteExCtx->ucLayer)
        {
            AT_WARN_LOG2("AT_SaveSimlockDataIntoCtx: Layer %d wrong, %d", ulLayer, pstSimlockWriteExCtx->ucLayer);

            AT_ClearSimLockWriteExCtx();
            AT_StopSimlockDataWriteTimer(ucIndex);

            return AT_CME_INCORRECT_PARAMETERS;
        }

        /* ��ǰ�Ѿ��������У���ǰ�·���total��֮ǰ֮ǰ�·���total��ͬ */
        if ((VOS_UINT8)ulTotal != pstSimlockWriteExCtx->ucTotalNum)
        {
            AT_WARN_LOG2("AT_SaveSimlockDataIntoCtx: total %d wrong, %d", ulTotal, pstSimlockWriteExCtx->ucTotalNum);

            AT_ClearSimLockWriteExCtx();
            AT_StopSimlockDataWriteTimer(ucIndex);

            return AT_CME_INCORRECT_PARAMETERS;
        }

        /* ��ǰ�·���Index����֮ǰ�·�Index+1 */
        if ((VOS_UINT8)ulCurIndex != (pstSimlockWriteExCtx->ucCurIdx + 1))
        {
            AT_WARN_LOG2("AT_SaveSimlockDataIntoCtx: CurIndex %d wrong, %d", ulCurIndex, pstSimlockWriteExCtx->ucCurIdx);

            AT_ClearSimLockWriteExCtx();
            AT_StopSimlockDataWriteTimer(ucIndex);

            return AT_CME_INCORRECT_PARAMETERS;
        }

        /* ���ַ�������ת��Ϊ���� */
        ulResult = AT_ProcSimlockWriteExData(pucSimLockData, usSimLockDataLen);

        if (AT_SUCCESS != ulResult)
        {
            AT_WARN_LOG1("AT_SaveSimlockDataIntoCtx: AT_ProcSimlockWriteExData fail %d", ulResult);

            AT_ClearSimLockWriteExCtx();
            AT_StopSimlockDataWriteTimer(ucIndex);

            return ulResult;
        }

        /* ����CurrIndex */
        pstSimlockWriteExCtx->ucCurIdx      = (VOS_UINT8)ulCurIndex;
    }

    /* �����������Ϊ5������5������copy��ȫ�ֱ��������֮ǰ������HMAC������֮ǰ������ */
    if ((5 == ucParaNum) && (AT_SET_SIMLOCK_DATA_HMAC_LEN == usHmacLen))
    {
        TAF_MEM_CPY_S(pstSimlockWriteExCtx->aucHmac, AT_SET_SIMLOCK_DATA_HMAC_LEN, pucHmac, usHmacLen);
        pstSimlockWriteExCtx->ucHmacLen = (VOS_UINT8)usHmacLen;
    }

    return AT_OK;
}

VOS_UINT32 AT_CheckSimlockDataWriteExPara(
    AT_SIMLOCK_WRITE_EX_PARA_STRU *pstSimlockWriteExPara
)
{

    /* �涨��layerȡֵΪ0,1,2,3,4,255 */
    if ((4 < pstSimlockWriteExPara->ulLayer) && (255 != pstSimlockWriteExPara->ulLayer))
    {
        AT_WARN_LOG1("AT_CheckSimlockDataWriteExPara: invalid layer value:", pstSimlockWriteExPara->ulLayer);
        return VOS_ERR;
    }

    /* �涨��ulIndexȡֵΪ1-255 */
    if ((0 == pstSimlockWriteExPara->ulIndex) || (255 < pstSimlockWriteExPara->ulIndex))
    {
        AT_WARN_LOG1("AT_CheckSimlockDataWriteExPara: invalid ulIndex value:", pstSimlockWriteExPara->ulIndex);
        return VOS_ERR;
    }

    /* �涨��ulTotalȡֵΪ1-255 */
    if ((0 == pstSimlockWriteExPara->ulTotal) || (255 < pstSimlockWriteExPara->ulTotal))
    {
        AT_WARN_LOG1("AT_CheckSimlockDataWriteExPara: invalid ulTotal value:", pstSimlockWriteExPara->ulTotal);
        return VOS_ERR;
    }

    /* IndexҪС��total */
    if (pstSimlockWriteExPara->ulIndex > pstSimlockWriteExPara->ulTotal)
    {
        AT_WARN_LOG2("AT_CheckSimlockDataWriteExPara: Index bigger than total", pstSimlockWriteExPara->ulIndex, pstSimlockWriteExPara->ulTotal);

        return VOS_ERR;
    }

    /* �涨һ��д���simlockdata���ݲ�����1400���ַ� */
    if (AT_SIMLOCKDATA_PER_WRITE_MAX_LEN < pstSimlockWriteExPara->usSimLockDataLen)
    {
        AT_WARN_LOG1("AT_CheckSimlockDataWriteExPara: SimLockData is too long:", pstSimlockWriteExPara->usSimLockDataLen);
        return VOS_ERR;
    }

    return VOS_OK;

}


VOS_UINT32 AT_SetSimlockDataWriteExPara(
    AT_SIMLOCK_WRITE_EX_PARA_STRU *pstSimlockWriteExPara,
    VOS_UINT8                      ucIndex,
    VOS_UINT8                      ucNetWorkFlg
)
{
    AT_SIMLOCKDATAWRITEEX_CMD_PROC_CTX                     *pstSimlockWriteExCtx;
    DRV_AGENT_SIMLOCKWRITEEX_SET_REQ_STRU                  *pstSimlockWriteExSetReq;
    VOS_UINT32                                              ulTimerName;
    VOS_UINT32                                              ulTempIndex;
    VOS_UINT32                                              ulResult;
    VOS_UINT32                                              ulLength;
    VOS_UINT16                                              usHmacLen;

    pstSimlockWriteExCtx = AT_GetSimLockWriteExCmdCtxAddr();

    if (VOS_OK != AT_CheckSimlockDataWriteExPara(pstSimlockWriteExPara))
    {
        if (VOS_FALSE == pstSimlockWriteExCtx->ucSettingFlag)
        {
            AT_ClearSimLockWriteExCtx();
            AT_StopSimlockDataWriteTimer(ucIndex);
        }

        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ���������浽ȫ�ֱ���  */
    ulResult = AT_SaveSimlockDataIntoCtx(pstSimlockWriteExPara, ucIndex, ucNetWorkFlg);

    if (AT_OK != ulResult)
    {
        return ulResult;
    }

    /* �����δ�������ݣ���������ʱ�����ظ�OK */
    if (pstSimlockWriteExCtx->ucCurIdx < pstSimlockWriteExCtx->ucTotalNum)
    {
        /* ֹͣ��һ���ڵĶ�ʱ����������ʱ�� */
        AT_StopSimlockDataWriteTimer(ucIndex);

        ulTempIndex  = (VOS_UINT32)ucIndex;
        ulTimerName  = AT_SIMLOCKWRITEEX_TIMER;
        ulTimerName |= AT_INTERNAL_PROCESS_TYPE;
        ulTimerName |= (ulTempIndex<<12);

        (VOS_VOID)AT_StartRelTimer(&(pstSimlockWriteExCtx->hSimLockWriteExProtectTimer),
                                   AT_SIMLOCK_WRITE_EX_PROTECT_TIMER_LEN,
                                   ulTimerName,
                                   0, VOS_RELTIMER_NOLOOP);

        return AT_OK;
    }
    else
    {
        /* �Ѿ����������ݣ���Simlock_Dataת������ */
        ulResult = At_AsciiNum2HexString(pstSimlockWriteExCtx->pucData, &(pstSimlockWriteExCtx->usSimlockDataLen));
        if (AT_SUCCESS != ulResult)
        {
            AT_WARN_LOG2("AT_SetSimlockDataWriteExPara: At_AsciiNum2HexString fail ulResult: %d ulParaLen: %d",
                         ulResult,
                         pstSimlockWriteExCtx->usSimlockDataLen);

            AT_ClearSimLockWriteExCtx();
            AT_StopSimlockDataWriteTimer(ucIndex);

            return AT_CME_INCORRECT_PARAMETERS;
        }

        /* �Ѿ����������ݣ���HMACת������ */
        usHmacLen = pstSimlockWriteExCtx->ucHmacLen;
        ulResult = At_AsciiNum2HexString(pstSimlockWriteExCtx->aucHmac, &usHmacLen);

        pstSimlockWriteExCtx->ucHmacLen = (VOS_UINT8)usHmacLen;

        if ((AT_SUCCESS != ulResult)
         || (DRV_AGENT_HMAC_DATA_LEN != pstSimlockWriteExCtx->ucHmacLen))
        {
            AT_WARN_LOG2("AT_SetSimlockDataWriteExPara: At_AsciiNum2HexString fail ulResult: %d ulParaLen: %d",
                         ulResult,
                         pstSimlockWriteExCtx->ucHmacLen);

            AT_ClearSimLockWriteExCtx();
            AT_StopSimlockDataWriteTimer(ucIndex);

            return AT_CME_INCORRECT_PARAMETERS;
        }

        ulLength = sizeof(DRV_AGENT_SIMLOCKWRITEEX_SET_REQ_STRU) + pstSimlockWriteExCtx->usSimlockDataLen - 4;
        pstSimlockWriteExSetReq = (DRV_AGENT_SIMLOCKWRITEEX_SET_REQ_STRU *)PS_MEM_ALLOC(WUEPS_PID_AT, ulLength);

        if (VOS_NULL_PTR == pstSimlockWriteExSetReq)
        {
            AT_WARN_LOG("AT_SetSimlockDataWriteExPara: alloc mem fail.");

            AT_ClearSimLockWriteExCtx();
            AT_StopSimlockDataWriteTimer(ucIndex);

            return AT_CME_MEMORY_FAILURE;
        }

        pstSimlockWriteExSetReq->ulHmacLen = pstSimlockWriteExCtx->ucHmacLen;
        TAF_MEM_CPY_S(pstSimlockWriteExSetReq->aucHmac,
                      sizeof(pstSimlockWriteExSetReq->aucHmac),
                      pstSimlockWriteExCtx->aucHmac,
                      pstSimlockWriteExCtx->ucHmacLen);

        pstSimlockWriteExSetReq->ulSimlockDataLen = pstSimlockWriteExCtx->usSimlockDataLen;
        TAF_MEM_CPY_S(pstSimlockWriteExSetReq->aucSimlockData,
                      pstSimlockWriteExCtx->usSimlockDataLen,
                      pstSimlockWriteExCtx->pucData,
                      pstSimlockWriteExCtx->usSimlockDataLen);

        /* ��¼�ܹ�д��Ĵ����������һ��д��ʱ��index */
        pstSimlockWriteExSetReq->ulTotal = pstSimlockWriteExCtx->ucTotalNum;

        /* ��¼�Ƿ��������·��ı�ʶ */
        pstSimlockWriteExSetReq->ucNetWorkFlg = pstSimlockWriteExCtx->ucNetWorkFlg;
        pstSimlockWriteExSetReq->ucLayer      = pstSimlockWriteExCtx->ucLayer;

        AT_ClearSimLockWriteExCtx();
        AT_StopSimlockDataWriteTimer(ucIndex);

        /* ת���ɹ�, ���Ϳ����Ϣ��C��, ���ò��߹�Կ */
        ulResult = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                          gastAtClientTab[ucIndex].opId,
                                          DRV_AGENT_SIMLOCKWRITEEX_SET_REQ,
                                          pstSimlockWriteExSetReq,
                                          ulLength,
                                          I0_WUEPS_PID_DRV_AGENT);
        /*lint -save -e516*/
        PS_MEM_FREE(WUEPS_PID_AT, pstSimlockWriteExSetReq);
        /*lint -restore */
        if (TAF_SUCCESS != ulResult)
        {
            AT_WARN_LOG("AT_SetSimlockDataWriteExPara: AT_FillAndSndAppReqMsg fail.");

            return AT_ERROR;
        }

        /* ����SIMLOCKDATAWRITEEX���⴦����Ҫ�ֶ�������ʱ��*/
        if (AT_SUCCESS != At_StartTimer(AT_SET_PARA_TIME, ucIndex))
        {
            AT_WARN_LOG("AT_SetSimlockDataWriteExPara: At_StartTimer fail.");

            return AT_ERROR;
        }

        g_stParseContext[ucIndex].ucClientStatus = AT_FW_CLIENT_STATUS_PEND;

        /* ����ATģ��ʵ���״̬Ϊ�ȴ��첽���� */
        gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_SIMLOCKDATAWRITEEX_SET;

        return AT_WAIT_ASYNC_RETURN;
    }
}


VOS_UINT32 AT_ParseSimlockDataWriteExParaValue(
    VOS_UINT8                          *pucData,
    AT_SIMLOCK_WRITE_EX_PARA_STRU      *pstSimlockWriteExPara,
    VOS_UINT16                          usPos,
    VOS_UINT16                          usLen
)
{
    VOS_UINT16                          ausCommPos[4] = {0};
    VOS_UINT32                          ulFirstParaVal;
    VOS_UINT32                          ulSecParaVal;
    VOS_UINT32                          ulThirdParaVal;
    VOS_UINT16                          usLoop;
    VOS_UINT16                          usFirstParaLen;
    VOS_UINT16                          usSecondParaLen;
    VOS_UINT16                          usThirdParaLen;
    VOS_UINT16                          usFourthParaLen;
    VOS_UINT16                          usFifthParaLen;
    VOS_UINT16                          usCommaCnt;
    VOS_UINT8                           ucParaNum;

    usCommaCnt          = 0;
    usFourthParaLen     = 0;
    usFifthParaLen      = 0;
    ulFirstParaVal      = 0;
    ulSecParaVal        = 0;
    ulThirdParaVal      = 0;
    ucParaNum           = 0;

    /* ��ȡ�����еĶ���λ�ú͸��� */
    for ( usLoop = usPos; usLoop < usLen; usLoop++ )
    {
        if (',' == *(pucData + usLoop))
        {
            /* ��¼�¶��ŵ�λ�� */
            if (4 > usCommaCnt)
            {
                ausCommPos[usCommaCnt] = usLoop + 1;
            }
            usCommaCnt++;
        }
    }

    /* �����Ÿ�������4����AT����������ʧ�� */
    if ((4 != usCommaCnt) && (3 != usCommaCnt))
    {
        AT_WARN_LOG("AT_ParseSimlockDataWriteExParaValue: Num of Para is  Invalid!");
        return VOS_ERR;
    }

    /* ��������ĳ��� */
    usFirstParaLen  = (ausCommPos[0] - usPos) - (VOS_UINT16)VOS_StrNLen(",", AT_CONST_NUM_2);
    usSecondParaLen = (ausCommPos[1] - ausCommPos[0]) - (VOS_UINT16)VOS_StrNLen(",", AT_CONST_NUM_2);
    usThirdParaLen  = (ausCommPos[2] - ausCommPos[1]) - (VOS_UINT16)VOS_StrNLen(",", AT_CONST_NUM_2);

    /* ������ŵĸ���Ϊ3����ô�����ĸ���Ϊ4��������ŵĸ���Ϊ4����ô�����ĸ���Ϊ5 */
    if (3== usCommaCnt)
    {
        usFourthParaLen = usLen - ausCommPos[2];
        ucParaNum       = 4;
    }
    else
    {
        usFourthParaLen = (ausCommPos[3] - ausCommPos[2]) - (VOS_UINT16)VOS_StrNLen(",", AT_CONST_NUM_2);
        usFifthParaLen  = usLen - ausCommPos[3];
        ucParaNum       = 5;
    }

    /* ��ȡ��һ������ֵ */
    if (AT_FAILURE == atAuc2ul(pucData + usPos, usFirstParaLen, &ulFirstParaVal))
    {
        AT_WARN_LOG("AT_ParseSimlockDataWriteExParaValue: ulFirstParaVal value invalid");
        return VOS_ERR;
    }

    /* ��ȡ�ڶ�������ֵ */
    if (AT_FAILURE == atAuc2ul(pucData + ausCommPos[0], usSecondParaLen, &ulSecParaVal))
    {
        AT_WARN_LOG("AT_ParseSimlockDataWriteExParaValue: ulSecParaVal value invalid");
        return VOS_ERR;
    }

    /* ��ȡ����������ֵ */
    if (AT_FAILURE == atAuc2ul(pucData + ausCommPos[1], usThirdParaLen, &ulThirdParaVal))
    {
        AT_WARN_LOG("AT_ParseSimlockDataWriteExParaValue: ulThirdParaVal value invalid");
        return VOS_ERR;
    }

    pstSimlockWriteExPara->ucParaNum        = ucParaNum;
    pstSimlockWriteExPara->ulLayer          = ulFirstParaVal;
    pstSimlockWriteExPara->ulIndex          = ulSecParaVal;
    pstSimlockWriteExPara->ulTotal          = ulThirdParaVal;
    pstSimlockWriteExPara->usSimLockDataLen = usFourthParaLen;
    pstSimlockWriteExPara->pucSimLockData   = pucData + ausCommPos[2];

    /* ���������������5 */
    if (5 == ucParaNum)
    {
        pstSimlockWriteExPara->usHmacLen    = usFifthParaLen;
        pstSimlockWriteExPara->pucHmac      = pucData + ausCommPos[3];
    }

    return VOS_OK;
}

VOS_UINT32 AT_HandleSimLockDataWriteExCmd(
    VOS_UINT8                           ucIndex,
    VOS_UINT8                          *pucData,
    VOS_UINT16                          usLen
)
{
    VOS_UINT8                          *pucDataPara;
    AT_PARSE_CMD_NAME_TYPE_STRU         stAtCmdName;
    AT_SIMLOCK_WRITE_EX_PARA_STRU       stSimlockWriteExPara;
    VOS_UINT32                          ulResult;
    VOS_UINT16                          usCmdlen;
    VOS_UINT16                          usPos;
    VOS_UINT16                          usLength;
    VOS_INT8                            cRet;

    TAF_MEM_SET_S(&stAtCmdName, sizeof(stAtCmdName), 0x00, sizeof(stAtCmdName));

    /* �ֲ�������ʼ�� */
    usCmdlen             = (VOS_UINT16)VOS_StrNLen("AT^SIMLOCKDATAWRITEEX=", AT_CONST_NUM_23);

    /* ͨ����� */
    if (VOS_FALSE == AT_IsApPort(ucIndex))
    {
        return AT_FAILURE;
    }

    /* ���Ȳ����������������С���� AT^SIMLOCKDATAWRITEEX=1,1,1,  ���ںź�6���ַ� */
    if ((usCmdlen + 6) > usLen)
    {
        return AT_FAILURE;
    }
    /*lint -save -e516*/
    pucDataPara = (VOS_UINT8*)PS_MEM_ALLOC(WUEPS_PID_AT, usCmdlen);
    /*lint -restore */
    if (VOS_NULL_PTR == pucDataPara)
    {
        AT_ERR_LOG("AT_HandleSimLockDataWriteExCmd: pucDataPara Memory malloc failed!");
        return AT_FAILURE;
    }

    /*�������������������Ƚ�ʹ��*/
    TAF_MEM_CPY_S(pucDataPara, usCmdlen, pucData, usCmdlen);

    /* AT����ͷ�ַ�ת��д */
    At_UpString(pucDataPara, usCmdlen);

    /* ��������ַ���ͷ������"AT^SIMLOCKDATAWRITEEX="ֱ�ӷ���AT_FAILURE */
    cRet = VOS_StrNiCmp((VOS_CHAR *)pucDataPara, "AT^SIMLOCKDATAWRITEEX=", usCmdlen);
    if (0 != cRet)
    {
        PS_MEM_FREE(WUEPS_PID_AT, pucDataPara);
        return AT_FAILURE;
    }

    AT_SaveCmdElementInfo(ucIndex, (VOS_UINT8*)"^SIMLOCKDATAWRITEEX", AT_EXTEND_CMD_TYPE);

    /* ��ȡ����(����������ǰ׺AT)���Ƽ����� */
    usPos = (VOS_UINT16)VOS_StrNLen("AT", AT_CONST_NUM_3);

    stAtCmdName.usCmdNameLen = (VOS_UINT16)VOS_StrNLen("^SIMLOCKDATAWRITEEX", AT_CONST_NUM_23);
    TAF_MEM_CPY_S(stAtCmdName.aucCmdName,
                  sizeof(stAtCmdName.aucCmdName),
                  (pucData + usPos),
                  stAtCmdName.usCmdNameLen);
    stAtCmdName.aucCmdName[stAtCmdName.usCmdNameLen] = '\0';
    usPos += stAtCmdName.usCmdNameLen;

    usPos += (VOS_UINT16)VOS_StrNLen("=", AT_CONST_NUM_2);

    /* �ֲ�������ʼ�� */
    TAF_MEM_SET_S(&stSimlockWriteExPara, sizeof(stSimlockWriteExPara), 0x00, sizeof(stSimlockWriteExPara));
    stSimlockWriteExPara.pucSimLockData   = VOS_NULL_PTR;
    stSimlockWriteExPara.pucHmac          = VOS_NULL_PTR;

    if (VOS_OK != AT_ParseSimlockDataWriteExParaValue(pucData, &stSimlockWriteExPara,usPos, usLen))
    {
        PS_MEM_FREE(WUEPS_PID_AT, pucDataPara);
        At_FormatResultData(ucIndex, AT_CME_INCORRECT_PARAMETERS);
        AT_ClearSimLockWriteExCtx();
        AT_StopSimlockDataWriteTimer(ucIndex);

        gstAtSendData.usBufLen  = 0;
        At_FormatResultData(ucIndex, AT_ERROR);

        return AT_SUCCESS;
    }

     /* �����������ͣ��������ͺͲ������� */
    g_stATParseCmd.ucCmdOptType = AT_CMD_OPT_SET_PARA_CMD;
    gucAtCmdFmtType = AT_EXTEND_CMD_TYPE;

    printk(KERN_ERR "\n AT_HandleSimLockDataWriteExCmd enter \n");

    ulResult = AT_SetSimlockDataWriteExPara(&stSimlockWriteExPara, ucIndex, VOS_FALSE);

    /* ��Ӵ�ӡ ^SIMLOCKDATAWRITEEX:<index>���� */
    usLength = 0;

    if (AT_WAIT_ASYNC_RETURN != ulResult)
    {
        if (AT_OK == ulResult)
        {
            printk(KERN_ERR "\n AT_HandleSimLockDataWriteExCmd return OK \n");

            usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                               (VOS_CHAR *)pgucAtSndCodeAddr,
                                               (VOS_CHAR *)pgucAtSndCodeAddr,
                                               "%s:%d",
                                               "^SIMLOCKDATAWRITEEX",
                                               stSimlockWriteExPara.ulIndex);
        }

        gstAtSendData.usBufLen  = usLength;
        At_FormatResultData(ucIndex, ulResult);
    }

    PS_MEM_FREE(WUEPS_PID_AT, pucDataPara);
    return AT_SUCCESS;
}


VOS_UINT32 AT_RcvDrvAgentSimlockWriteExSetCnf(VOS_VOID *pMsg)
{
    DRV_AGENT_MSG_STRU                         *pRcvMsg;
    DRV_AGENT_SIMLOCKWRITEEX_SET_CNF_STRU      *pstEvent;
    VOS_UINT32                                  ulResult;
    VOS_UINT16                                  usLength;
    VOS_UINT8                                   ucIndex;

    printk(KERN_ERR "\n AT_RcvDrvAgentSimlockWriteExSetCnf enter\n");

    /* ��ʼ����Ϣ���� */
    pRcvMsg         = (DRV_AGENT_MSG_STRU *)pMsg;
    pstEvent        = (DRV_AGENT_SIMLOCKWRITEEX_SET_CNF_STRU *)pRcvMsg->aucContent;
    ucIndex         = 0;

    /* ͨ��ClientId��ȡucIndex */
    if ( AT_FAILURE == At_ClientIdToUserId(pstEvent->stAtAppCtrl.usClientId, &ucIndex) )
    {
        AT_WARN_LOG("AT_RcvDrvAgentSimlockWriteExSetCnf: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvDrvAgentSimlockWriteExSetCnf: AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* �жϵ�ǰ���������Ƿ�ΪAT_CMD_SIMLOCKWRITEEX_SET */
    if ( AT_CMD_SIMLOCKDATAWRITEEX_SET != gastAtClientTab[ucIndex].CmdCurrentOpt )
    {
        AT_WARN_LOG("AT_RcvDrvAgentSimlockWriteExSetCnf: CmdCurrentOpt ERR.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    usLength = 0;

    /* �жϲ�ѯ�����Ƿ�ɹ� */
    if ( DRV_AGENT_PERSONALIZATION_NO_ERROR == pstEvent->enResult )
    {
        /* ������ý�� */
        usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                           (VOS_CHAR *)pgucAtSndCodeAddr,
                                           (VOS_CHAR *)pgucAtSndCodeAddr,
                                           "%s:%d",
                                           g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                           pstEvent->ulTotal);
        ulResult    = AT_OK;
    }
    else
    {
        /* �쳣���, ת�������� */
        ulResult    = AT_PERSONALIZATION_ERR_BEGIN + pstEvent->enResult;
    }

    gstAtSendData.usBufLen  = usLength;

    /* ����AT_FormATResultDATa���������� */
    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}

VOS_UINT32 AT_SimLockDataReadExPara(VOS_UINT8 ucIndex)
{
    DRV_AGENT_SIMLOCKDATAREADEX_READ_REQ_STRU stSimLockDataReadExReq;
    VOS_UINT32                                ulResult;

    printk(KERN_ERR "\n AT_SimLockDataReadExPara enter\n");

    /* �ֲ�������ʼ�� */
    TAF_MEM_SET_S(&stSimLockDataReadExReq, sizeof(stSimLockDataReadExReq), 0x00, sizeof(stSimLockDataReadExReq));

    /* ͨ����� */
    if (VOS_FALSE == AT_IsApPort(ucIndex))
    {
        AT_WARN_LOG("AT_SimLockDataReadExPara: It Is not Ap Port.");
        return AT_ERROR;
    }

    /* ������� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        AT_WARN_LOG("AT_SimLockDataReadExPara: ucCmdOptType is not AT_CMD_OPT_SET_PARA_CMD.");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ������������ */
    if (2 != gucAtParaIndex)
    {
        AT_WARN_LOG("AT_SimLockDataReadExPara: gucAtParaIndex ERR.");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* �����ĳ��Ȳ���Ϊ0 */
    if (0 == gastAtParaList[0].usParaLen)
    {
        AT_WARN_LOG("AT_SimLockDataReadExPara: gastAtParaList[0].usParaLen err.");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    stSimLockDataReadExReq.ucLayer = (VOS_UINT8)gastAtParaList[0].ulParaValue;
    stSimLockDataReadExReq.ucIndex = (VOS_UINT8)gastAtParaList[1].ulParaValue;

    ulResult = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                      gastAtClientTab[ucIndex].opId,
                                      DRV_AGENT_SIMLOCKDATAREADEX_READ_REQ,
                                      &stSimLockDataReadExReq,
                                      (VOS_UINT32)sizeof(stSimLockDataReadExReq),
                                      I0_WUEPS_PID_DRV_AGENT);
    if (TAF_SUCCESS != ulResult)
    {
        AT_WARN_LOG("AT_SimLockDataReadExPara: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

    /* ����ATģ��ʵ���״̬Ϊ�ȴ��첽���� */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_SIMLOCKDATAREADEX_READ_SET;

    return AT_WAIT_ASYNC_RETURN;

}


VOS_UINT32 AT_RcvDrvAgentSimlockDataReadExReadCnf(VOS_VOID *pMsg)
{
    DRV_AGENT_MSG_STRU                         *pRcvMsg;
    DRV_AGENT_SIMLOCKDATAREADEX_READ_CNF_STRU  *pstEvent;
    VOS_UINT32                                  ulResult;
    VOS_UINT32                                  ulLoop;
    VOS_UINT16                                  usLength;
    VOS_UINT8                                   ucIndex;

    printk(KERN_ERR "\n AT_RcvDrvAgentSimlockDataReadExReadCnf enter\n");

    /* ��ʼ����Ϣ���� */
    usLength = 0;
    ucIndex  = AT_BROADCAST_CLIENT_INDEX_MODEM_0;
    pRcvMsg  = (DRV_AGENT_MSG_STRU *)pMsg;
    pstEvent = (DRV_AGENT_SIMLOCKDATAREADEX_READ_CNF_STRU *)pRcvMsg->aucContent;

    ulResult = pstEvent->ulResult;

    /* ͨ��ClientId��ȡucIndex */
    if ( AT_FAILURE == At_ClientIdToUserId(pstEvent->stAtAppCtrl.usClientId,&ucIndex) )
    {
        AT_WARN_LOG("AT_RcvDrvAgentSimlockDataReadExReadCnf: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvDrvAgentSimlockDataReadExReadCnf: AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* �жϵ�ǰ���������Ƿ�ΪAT_CMD_SIMLOCKDATAREADEX_READ_SET */
    if ( AT_CMD_SIMLOCKDATAREADEX_READ_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvDrvAgentSimlockDataReadExReadCnf: CmdCurrentOpt ERR.");
        return VOS_ERR;
    }

    /* �жϲ�ѯ�����Ƿ�ɹ� */
    if ( DRV_AGENT_PERSONALIZATION_NO_ERROR == pstEvent->ulResult)
    {
        /* ������ý�� */
        ulResult    = AT_OK;

        /* ���<layer>,<index>,<total>��ӡ */
        usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                           (VOS_CHAR *)pgucAtSndCodeAddr,
                                           (VOS_CHAR *)pgucAtSndCodeAddr,
                                            "%s:%d,%d,%d,",
                                            g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                            pstEvent->ucLayer,
                                            pstEvent->ucIndex,
                                            pstEvent->ucTotal);

        /* ���<simlock_data>��ӡ */
        for (ulLoop = 0; ulLoop < pstEvent->ulDataLen; ulLoop++)
        {
            usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                              (VOS_CHAR *)pgucAtSndCodeAddr,
                                              (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                               "%02x",
                                               pstEvent->aucData[ulLoop]);
        }
    }
    else
    {
        /* �쳣���, ת�������� */
        ulResult    = AT_PERSONALIZATION_ERR_BEGIN + pstEvent->ulResult;
    }

    gstAtSendData.usBufLen = usLength;

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    /* ����AT_FormATResultDATa���������� */
    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;

}


VOS_UINT32 AT_SetActPdpStubPara(VOS_UINT8 ucIndex)
{
    VOS_UINT8                           ucFlag;

    /* ������� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ����������� */
    if (2 != gucAtParaIndex)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    if((0 == gastAtParaList[0].usParaLen)
    || (0 == gastAtParaList[1].usParaLen))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ��ȡ���õı�־ */
    ucFlag = (VOS_UINT8)gastAtParaList[1].ulParaValue;

    /* ����MODEM ID���ò�ͬ��׮���� */
    if (0 == gastAtParaList[0].ulParaValue)
    {
        AT_SetPcuiPsCallFlag(ucFlag, AT_CLIENT_TAB_APP_INDEX);
    }
    else if (1 == gastAtParaList[0].ulParaValue)
    {
        AT_SetCtrlPsCallFlag(ucFlag, AT_CLIENT_TAB_APP_INDEX);
    }
    else if (2 == gastAtParaList[0].ulParaValue)
    {
    
   AT_SetPcui2PsCallFlag(ucFlag, AT_CLIENT_TAB_APP_INDEX);
    }
    else
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    return AT_OK;
}


VOS_UINT32 AT_SetNVCHKPara(VOS_UINT8 ucIndex)
{
    VOS_UINT8           ucLoopIndex;

    /* ������� */
    if ( AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType )
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* �������� */
    if ( 1 != gucAtParaIndex )
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* δ�������ж� */
    if(0 == gastAtParaList[0].usParaLen)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* �����ȫ����飬��ѭ�����ȫ��CRC */
    if ( 0 == gastAtParaList[0].ulParaValue)
    {
        for( ucLoopIndex = 0; ucLoopIndex < 3; ucLoopIndex++ )
        {
            if ( 0 != mdrv_nv_check_factorynv( ucLoopIndex ) )
            {
                return AT_ERROR;
            }
        }

        return AT_OK;
    }

    /* �������0��Ϊ��������0Ϊ�쳣 */
    if ( 0 == mdrv_nv_check_factorynv( gastAtParaList[0].ulParaValue - 1 ))
    {
        return AT_OK;
    }
    else
    {
        return AT_ERROR;
    }

}




VOS_UINT32 AT_RcvMtaAfcClkInfoCnf(
    VOS_VOID                           *pMsg
)
{
    VOS_UINT8                                   ucIndex;
    AT_MTA_MSG_STRU                            *pstMtaMsg    = VOS_NULL_PTR;
    MTA_AT_QRY_AFC_CLK_FREQ_XOCOEF_CNF_STRU    *pstAfcCnf    = VOS_NULL_PTR;
    VOS_UINT32                                  ulRet;

    pstMtaMsg = (AT_MTA_MSG_STRU*)pMsg;

    pstAfcCnf = (MTA_AT_QRY_AFC_CLK_FREQ_XOCOEF_CNF_STRU*)pstMtaMsg->aucContent;

    /* ��ʼ����Ϣ���� */
    ucIndex             = 0;
    ulRet               = AT_OK;

     /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pstMtaMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaAfcClkInfoCnf : WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaAfcClkInfoCnf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_AFCCLKINFO_QRY != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaAfcClkInfoCnf : Current Option is not AT_CMD_AFCCLKINFO_QRY.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    gstAtSendData.usBufLen = 0;

    if (MTA_AT_RESULT_NO_ERROR != pstAfcCnf->enResult)
    {
        ulRet = AT_ERROR;
    }
    else
    {
        gstAtSendData.usBufLen = (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                    (VOS_CHAR *)pgucAtSndCodeAddr,
                                                    (VOS_CHAR*)pgucAtSndCodeAddr,
                                                    "%s: %u,%d,%d,%d,%u,%u,%u,%u,%u,%u,%u,%u",
                                                    g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                                    pstAfcCnf->enStatus,
                                                    pstAfcCnf->lDeviation,
                                                    pstAfcCnf->sCoeffStartTemp,
                                                    pstAfcCnf->sCoeffEndTemp,
                                                    pstAfcCnf->aulCoeffMantissa[0],
                                                    pstAfcCnf->aulCoeffMantissa[1],
                                                    pstAfcCnf->aulCoeffMantissa[2],
                                                    pstAfcCnf->aulCoeffMantissa[3],
                                                    pstAfcCnf->ausCoeffExponent[0],
                                                    pstAfcCnf->ausCoeffExponent[1],
                                                    pstAfcCnf->ausCoeffExponent[2],
                                                    pstAfcCnf->ausCoeffExponent[3]);
    }

    /* ������ */
    At_FormatResultData(ucIndex, ulRet);

    return VOS_OK;

}




VOS_UINT32 AT_SetSecureStatePara(VOS_UINT8 ucIndex)
{
    VOS_INT                                 iRst;

    /* ������� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
       return AT_CME_INCORRECT_PARAMETERS;
    }

    /* �����Ϸ��Լ�� */
    if ( (1 != gucAtParaIndex)
      || (0 == gastAtParaList[0].usParaLen) )
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ���õ����ṩ�Ľӿ�ʵ�����ò��� */
    iRst = mdrv_efuse_ioctl(MDRV_EFUSE_IOCTL_CMD_SET_SECURESTATE,
                            (VOS_INT)gastAtParaList[0].ulParaValue,
                            VOS_NULL_PTR,
                            0);

    /* ���ݵ���ӿڷ��صĽ���������ý�� */
    /* ������1ʱ�����ظ�����,����0ʱ���óɹ�,�����������ʧ�� */
    if (AT_EFUSE_REPEAT == iRst)
    {
        return AT_ERROR;
    }
    else if (AT_EFUSE_OK == iRst)
    {
        return AT_OK;
    }
    else
    {
        AT_WARN_LOG("AT_SetSecureStatePara : Set Secure state req failed.");
    }

    return AT_CME_UNKNOWN;
}


VOS_UINT32 AT_SetKcePara(VOS_UINT8 ucIndex)
{
    VOS_UINT32                              ulResult;
    VOS_INT                                 iRst;

    /* ������� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
       return AT_CME_INCORRECT_PARAMETERS;
    }

    /* �����Ϸ��Լ�� */
    if ( (1 != gucAtParaIndex)
      || (AT_KCE_PARA_LEN != gastAtParaList[0].usParaLen) )
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* Asciiת�ֽ��� */
    ulResult = At_AsciiNum2HexString(gastAtParaList[0].aucPara, &gastAtParaList[0].usParaLen);

    if ( (AT_SUCCESS != ulResult)
      || (AT_DRV_KCE_LEN != gastAtParaList[0].usParaLen) )
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ���õ����ṩ�Ľӿ�ʵ�����ò��� */
    iRst = mdrv_efuse_ioctl(MDRV_EFUSE_IOCTL_CMD_SET_KCE,
                            0,
                            gastAtParaList[0].aucPara,
                            (VOS_INT)gastAtParaList[0].usParaLen);

    /* ���ݵ���ӿڷ��صĽ���������ý�� */
    /* ������1ʱ�����ظ�����,����0ʱ���óɹ�,�����������ʧ�� */
    if (AT_EFUSE_REPEAT == iRst)
    {
        return AT_ERROR;
    }
    else if (AT_EFUSE_OK == iRst)
    {
        return AT_OK;
    }
    else
    {
        AT_WARN_LOG("AT_SetSecureStatePara : Set KCE req failed.");
    }

    return AT_CME_UNKNOWN;
}


VOS_UINT32 AT_QrySecureStatePara(VOS_UINT8 ucIndex)
{
    VOS_INT                             iResult;
    VOS_UINT16                          usLength;

    /* ������� */
    if (AT_CMD_OPT_READ_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    usLength = 0;

    /* ���õ����ṩ�Ľ�ڲ�ѯ */
    iResult = mdrv_efuse_ioctl(MDRV_EFUSE_IOCTL_CMD_GET_SECURESTATE,
                               0,
                               VOS_NULL_PTR,
                               0);

    /* �����쳣��ѯ��� */
    /* ��ѯʧ�� */
    if (AT_SECURE_STATE_NOT_SET > iResult)
    {
        return AT_ERROR;
    }

    /* ��ѯ����쳣 */
    if (AT_SECURE_STATE_RMA < iResult)
    {
        return AT_CME_UNKNOWN;
    }

    /* ��ӡ��� */
    usLength = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                     (VOS_CHAR *)pgucAtSndCodeAddr,
                                     (VOS_CHAR *)pgucAtSndCodeAddr,
                                     "%s: %d",
                                     g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                     iResult);

    gstAtSendData.usBufLen = usLength;
    return AT_OK;
}


VOS_UINT32 AT_QrySocidPara(VOS_UINT8 ucIndex)
{
    VOS_INT                                 iResult;
    VOS_UINT16                              usLength;
    VOS_UINT8                               aucSocid[AT_DRV_SOCID_LEN];
    VOS_UINT32                              i;

    /* �ֲ�������ʼ�� */
    TAF_MEM_SET_S(aucSocid, sizeof(aucSocid), 0x00, AT_DRV_SOCID_LEN);
    usLength = 0;

    /* ������� */
    if (AT_CMD_OPT_READ_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }



    /* ���õ����ṩ�Ľ�ڲ�ѯ */

    iResult = mdrv_efuse_ioctl(MDRV_EFUSE_IOCTL_CMD_GET_SOCID,
                               0,
                               aucSocid,
                               AT_DRV_SOCID_LEN);

    /* �����쳣��ѯ��� */
    if (AT_EFUSE_OK != iResult)
    {
        return AT_ERROR;
    }

    /* ������ */
    usLength = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                     (VOS_CHAR *)pgucAtSndCodeAddr,
                                     (VOS_CHAR *)pgucAtSndCodeAddr,
                                     "%s: ",
                                     g_stParseContext[ucIndex].pstCmdElement->pszCmdName);

    /* ��16����������� */
    for (i = 0; i < AT_DRV_SOCID_LEN; i++)
    {
        usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                          (VOS_CHAR *)pgucAtSndCodeAddr,
                                          (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                          "%02X",
                                          aucSocid[i]);
    }

    gstAtSendData.usBufLen = usLength;
    return AT_OK;
}



VOS_UINT32 AT_SetPdmCtrlPara(VOS_UINT8 ucIndex)
{
    AT_HPA_PDM_CTRL_REQ_STRU                *pstMsg;

    /* ������� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* �������� */
    if ( 4 != gucAtParaIndex)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    if ( (0 == gastAtParaList[0].usParaLen)
      || (0 == gastAtParaList[1].usParaLen)
      || (0 == gastAtParaList[2].usParaLen)
      || (0 == gastAtParaList[3].usParaLen) )
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    if (AT_TMODE_FTM != g_stAtDevCmdCtrl.ucCurrentTMode)
    {
        return AT_DEVICE_MODE_ERROR;
    }
    /*lint -save -e516 */
    pstMsg   = (AT_HPA_PDM_CTRL_REQ_STRU *)AT_ALLOC_MSG_WITH_HDR( sizeof(AT_HPA_PDM_CTRL_REQ_STRU) );
    /*lint -restore */
    if (VOS_NULL_PTR == pstMsg)
    {
        AT_WARN_LOG("AT_SetPdmCtrlPara: alloc msg fail!");
        return AT_ERROR;
    }

    /* ��д��Ϣͷ */
    AT_CFG_MSG_HDR( pstMsg, DSP_PID_WPHY, ID_AT_HPA_PDM_CTRL_REQ );

    pstMsg->usMsgID                             = ID_AT_HPA_PDM_CTRL_REQ;
    pstMsg->usRsv                               = 0;
    pstMsg->usPdmRegValue                       = ( VOS_UINT16 )gastAtParaList[0].ulParaValue;
    pstMsg->usPaVbias                           = ( VOS_UINT16 )gastAtParaList[1].ulParaValue;
    pstMsg->usPaVbias2                          = ( VOS_UINT16 )gastAtParaList[2].ulParaValue;
    pstMsg->usPaVbias3                          = ( VOS_UINT16 )gastAtParaList[3].ulParaValue;

    if (VOS_OK != PS_SEND_MSG(WUEPS_PID_AT, pstMsg))
    {
        AT_WARN_LOG("AT_SetPdmCtrlPara: Send msg fail!");
        return AT_ERROR;
    }

    gastAtClientTab[ucIndex].CmdCurrentOpt      = AT_CMD_PDM_CTRL;                /*���õ�ǰ����ģʽ */
    g_stAtDevCmdCtrl.ucIndex                    = ucIndex;

    return AT_WAIT_ASYNC_RETURN;                                                /* �ȴ��첽�¼����� */
}


VOS_UINT32 AT_SetCtzuPara(VOS_UINT8 ucIndex)
{
    /* ������� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ����������� */
    if (1 != gucAtParaIndex)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    if(0 == gastAtParaList[0].usParaLen)
    {
        g_ulCtzuFlag = 0;
    }
    else
    {
        g_ulCtzuFlag = gastAtParaList[0].ulParaValue;
    }

    return AT_OK;
}


VOS_UINT32 AT_QryCtzuPara(VOS_UINT8 ucIndex)
{
    VOS_UINT16                           usLength;

    /* ������� */
    if (AT_CMD_OPT_READ_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    usLength = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                     (VOS_CHAR *)pgucAtSndCodeAddr,
                                     (VOS_CHAR *)pgucAtSndCodeAddr,
                                     "%s: %d",
                                     g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                     g_ulCtzuFlag);

    gstAtSendData.usBufLen = usLength;

    return AT_OK;
}


VOS_UINT32 AT_SetEvdoSysEvent(VOS_UINT8 ucIndex)
{
    AT_MTA_EVDO_SYS_EVENT_SET_REQ_STRU  stSysEvent;
    VOS_UINT32                          ulRslt;

    TAF_MEM_SET_S(&stSysEvent, sizeof(stSysEvent), 0x00, sizeof(AT_MTA_EVDO_SYS_EVENT_SET_REQ_STRU));

    /* ����״̬��� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ����������Ϊ1�����ַ������ȴ���10, 4294967295 = 0xffffffff*/
    if ((1 != gucAtParaIndex)
     || (10 < gastAtParaList[0].usParaLen))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    stSysEvent.ulDoSysEvent = gastAtParaList[0].ulParaValue;

    ulRslt = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                    gastAtClientTab[ucIndex].opId,
                                    ID_AT_MTA_EVDO_SYS_EVENT_SET_REQ,
                                    &stSysEvent,
                                    sizeof(stSysEvent),
                                    I0_UEPS_PID_MTA);

    if (TAF_SUCCESS == ulRslt)
    {
        gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_EVDO_SYS_EVENT_SET;

        /* ������������״̬ */
        return AT_WAIT_ASYNC_RETURN;
    }
    else
    {
        AT_WARN_LOG("AT_SetEvdoSysEvent: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

}


VOS_UINT32 AT_SetDoSigMask(VOS_UINT8 ucIndex)
{
    AT_MTA_EVDO_SIG_MASK_SET_REQ_STRU   stSigMask;
    VOS_UINT32                          ulRslt;

    TAF_MEM_SET_S(&stSigMask, sizeof(stSigMask), 0x00, sizeof(AT_MTA_EVDO_SIG_MASK_SET_REQ_STRU));

    /* ����״̬��� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ����������Ϊ1�����ַ������ȴ���10, 4294967295 = 0xffffffff*/
    if ((1 != gucAtParaIndex)
     || (10 < gastAtParaList[0].usParaLen))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    stSigMask.ulDoSigMask = gastAtParaList[0].ulParaValue;

    ulRslt = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                    gastAtClientTab[ucIndex].opId,
                                    ID_AT_MTA_EVDO_SIG_MASK_SET_REQ,
                                    &stSigMask,
                                    sizeof(stSigMask),
                                    I0_UEPS_PID_MTA);

    if (TAF_SUCCESS == ulRslt)
    {
        gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_EVDO_SIG_MASK_SET;

        /* ������������״̬ */
        return AT_WAIT_ASYNC_RETURN;
    }
    else
    {
        AT_WARN_LOG("AT_SetDoSigMask: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

}


VOS_UINT32 AT_RcvMtaEvdoSysEventSetCnf(
    VOS_VOID                           *pMsg
)
{
    AT_MTA_MSG_STRU                            *pRcvMsg         = VOS_NULL_PTR;
    MTA_AT_RESULT_CNF_STRU                     *pstCnf          = VOS_NULL_PTR;
    VOS_UINT32                                  ulResult;
    VOS_UINT8                                   ucIndex;

    /* ��ʼ�� */
    pRcvMsg             = (AT_MTA_MSG_STRU *)pMsg;
    pstCnf              = (MTA_AT_RESULT_CNF_STRU *)pRcvMsg->aucContent;
    ulResult            = AT_OK;
    ucIndex             = 0;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaEvdoSysEventSetCnf : WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaEvdoSysEventSetCnf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_EVDO_SYS_EVENT_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaEvdoSysEventSetCnf : Current Option is not AT_CMD_LTE_WIFI_COEX_QRY.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    /* ��ʽ��AT^MEID����� */
    gstAtSendData.usBufLen = 0;

    if (pstCnf->enResult != MTA_AT_RESULT_NO_ERROR)
    {
        ulResult = AT_ERROR;
    }
    else
    {
        ulResult = AT_OK;
    }

    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}


VOS_UINT32 AT_RcvMtaEvdoSigMaskSetCnf(
    VOS_VOID                           *pMsg
)
{
    AT_MTA_MSG_STRU                            *pRcvMsg         = VOS_NULL_PTR;
    MTA_AT_RESULT_CNF_STRU                     *pstCnf          = VOS_NULL_PTR;
    VOS_UINT32                                  ulResult;
    VOS_UINT8                                   ucIndex;

    /* ��ʼ�� */
    pRcvMsg             = (AT_MTA_MSG_STRU *)pMsg;
    pstCnf              = (MTA_AT_RESULT_CNF_STRU *)pRcvMsg->aucContent;
    ulResult            = AT_OK;
    ucIndex             = 0;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaEvdoSigMaskSetCnf : WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaEvdoSigMaskSetCnf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_EVDO_SIG_MASK_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaEvdoSigMaskSetCnf : Current Option is not AT_CMD_LTE_WIFI_COEX_QRY.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    /* ��ʽ��AT^MEID����� */
    gstAtSendData.usBufLen = 0;

    if (pstCnf->enResult != MTA_AT_RESULT_NO_ERROR)
    {
        ulResult = AT_ERROR;
    }
    else
    {
        ulResult = AT_OK;
    }

    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;

}


VOS_UINT32 AT_RcvMtaEvdoRevARLinkInfoInd(
    VOS_VOID                           *pMsg
)
{
    VOS_UINT8                                               ucIndex;
    AT_MTA_MSG_STRU                                        *pstMtaMsg       = VOS_NULL_PTR;
    MTA_AT_EVDO_REVA_RLINK_INFO_IND_STRU                   *pstRlinkInfo    = VOS_NULL_PTR;
    VOS_UINT8                                              *pucData;
    VOS_UINT32                                              ulDataLen;
    VOS_UINT32                                              ulRslt;

    /* ��ʼ����Ϣ���� */
    ucIndex             = 0;
    pstMtaMsg           = (AT_MTA_MSG_STRU*)pMsg;
    pstRlinkInfo        = (MTA_AT_EVDO_REVA_RLINK_INFO_IND_STRU*)pstMtaMsg->aucContent;

    /* ͨ��ClientId��ȡucIndex */
    if ( AT_FAILURE == At_ClientIdToUserId(pstMtaMsg->stAppCtrl.usClientId, &ucIndex) )
    {
        AT_WARN_LOG("AT_RcvMtaEvdoRevARLinkInfoInd: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    ulDataLen               = pstRlinkInfo->ulParaLen * sizeof(VOS_UINT8) * 2 + 3;
    /*lint -save -e516 */
    pucData                 = (VOS_UINT8 *)PS_MEM_ALLOC(WUEPS_PID_AT, ulDataLen);
    /*lint -restore */
    if (VOS_NULL_PTR == pucData)
    {
        AT_WARN_LOG("AT_RcvMtaEvdoRevARLinkInfoInd(): mem alloc Fail!");
        return VOS_ERR;
    }

    TAF_MEM_SET_S(pucData, ulDataLen, 0x00, ulDataLen);
    pucData[ulDataLen - 1]  = '\0';

    ulRslt = AT_HexToAsciiString(pstRlinkInfo->aucContent, &pucData[1], (TAF_UINT16)pstRlinkInfo->ulParaLen);

    pucData[0]              = '"';
    pucData[ulDataLen - 2]  = '"';

    if (ulRslt != AT_OK)
    {
        AT_WARN_LOG("AT_RcvMtaEvdoRevARLinkInfoInd: WARNING: Hex to Ascii trans fail!");

        PS_MEM_FREE(WUEPS_PID_AT, pucData);

        return VOS_ERR;
    }

    gstAtSendData.usBufLen = 0;
    gstAtSendData.usBufLen = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                    (VOS_CHAR *)pgucAtSndCodeAddr,
                                                    (VOS_CHAR *)pgucAtSndCodeAddr,
                                                    "%s^DOREVARLINK: %d,%s%s",
                                                    gaucAtCrLf,
                                                    pstRlinkInfo->ulParaLen * 2,
                                                    pucData,
                                                    gaucAtCrLf);

    At_SendResultData(ucIndex, pgucAtSndCodeAddr, gstAtSendData.usBufLen);

    PS_MEM_FREE(WUEPS_PID_AT, pucData);

    return VOS_OK;
}


VOS_UINT32 AT_RcvMtaEvdoSigExEventInd(
    VOS_VOID                           *pMsg
)
{
    VOS_UINT8                           ucIndex;
    AT_MTA_MSG_STRU                    *pstMtaMsg       = VOS_NULL_PTR;
    MTA_AT_EVDO_SIG_EXEVENT_IND_STRU   *pstSigExEvent   = VOS_NULL_PTR;
    VOS_UINT8                          *pucData;
    VOS_UINT32                          ulDataLen;
    VOS_UINT32                          ulRslt;

    /* ��ʼ����Ϣ���� */
    ucIndex             = 0;
    pstMtaMsg           = (AT_MTA_MSG_STRU*)pMsg;
    pstSigExEvent       = (MTA_AT_EVDO_SIG_EXEVENT_IND_STRU*)pstMtaMsg->aucContent;

    /* ͨ��ClientId��ȡucIndex */
    if ( AT_FAILURE == At_ClientIdToUserId(pstMtaMsg->stAppCtrl.usClientId, &ucIndex) )
    {
        AT_WARN_LOG("AT_RcvMtaEvdoSigExEventInd: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    ulDataLen               = pstSigExEvent->ulParaLen * sizeof(VOS_UINT8) * 2 + 3;
    /*lint -save -e516 */
    pucData                 = (VOS_UINT8 *)PS_MEM_ALLOC(WUEPS_PID_AT, ulDataLen);
    /*lint -restore */
    if (VOS_NULL_PTR == pucData)
    {
        AT_WARN_LOG("AT_RcvMtaEvdoSigExEventInd(): mem alloc Fail!");
        return VOS_ERR;
    }

    TAF_MEM_SET_S(pucData, ulDataLen, 0x00, ulDataLen);
    pucData[ulDataLen - 1]  = '\0';

    ulRslt = AT_HexToAsciiString(pstSigExEvent->aucContent, &pucData[1], (TAF_UINT16)pstSigExEvent->ulParaLen);

    pucData[0]              = '"';
    pucData[ulDataLen - 2]  = '"';

    if (ulRslt != AT_OK)
    {
        AT_WARN_LOG("AT_RcvMtaEvdoSigExEventInd: WARNING: Hex to Ascii trans fail!");

        PS_MEM_FREE(WUEPS_PID_AT, pucData);

        return VOS_ERR;
    }

    gstAtSendData.usBufLen = 0;
    gstAtSendData.usBufLen = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                    (VOS_CHAR *)pgucAtSndCodeAddr,
                                                    (VOS_CHAR *)pgucAtSndCodeAddr,
                                                    "%s^DOSIGEXEVENT: %d,%s%s",
                                                    gaucAtCrLf,
                                                    pstSigExEvent->ulParaLen * 2,
                                                    pucData,
                                                    gaucAtCrLf);

    PS_MEM_FREE(WUEPS_PID_AT, pucData);

    At_SendResultData(ucIndex, pgucAtSndCodeAddr, gstAtSendData.usBufLen);

    return VOS_OK;
}


VOS_UINT32 AT_RcvMtaNoCardModeSetCnf(
    VOS_VOID                           *pMsg
)
{
    AT_MTA_MSG_STRU                    *pRcvMsg = VOS_NULL_PTR;
    MTA_AT_RESULT_CNF_STRU             *pstCnf  = VOS_NULL_PTR;
    VOS_UINT32                          ulResult;
    VOS_UINT8                           ucIndex;

    /* ��ʼ�� */
    pRcvMsg             = (AT_MTA_MSG_STRU *)pMsg;
    pstCnf              = (MTA_AT_RESULT_CNF_STRU *)pRcvMsg->aucContent;
    ulResult            = AT_OK;
    ucIndex             = 0;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaNoCardModeSetCnf : WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaNoCardModeSetCnf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_NOCARDMODE_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaNoCardModeSetCnf : Current Option is not AT_CMD_NOCARDMODE_SET.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    /* ��ʽ��AT^CNOCARDMODE����� */
    gstAtSendData.usBufLen = 0;

    if (pstCnf->enResult != MTA_AT_RESULT_NO_ERROR)
    {
        ulResult = AT_ERROR;
    }
    else
    {
        ulResult = AT_OK;
    }

    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}


VOS_UINT32 AT_RcvMtaNoCardModeQryCnf(
    VOS_VOID                           *pMsg
)
{
    AT_MTA_MSG_STRU                    *pRcvMsg         = VOS_NULL_PTR;
    MTA_AT_NO_CARD_MODE_QRY_CNF_STRU   *pstMtaCnf       = VOS_NULL_PTR;
    VOS_UINT32                          ulResult;
    VOS_UINT8                           ucIndex;

    /* ��ʼ�� */
    pRcvMsg             = (AT_MTA_MSG_STRU *)pMsg;
    pstMtaCnf           = (MTA_AT_NO_CARD_MODE_QRY_CNF_STRU *)pRcvMsg->aucContent;
    ulResult            = AT_OK;
    ucIndex             = 0;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaNoCardModeQryCnf : WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaNoCardModeQryCnf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_NOCARDMODE_QRY != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaNoCardModeQryCnf : Current Option is not AT_CMD_NOCARDMODE_QRY.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    gstAtSendData.usBufLen = 0;

    if (VOS_OK != pstMtaCnf->enResult)
    {
        ulResult = AT_ERROR;
    }
    else
    {
        gstAtSendData.usBufLen = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                    (VOS_CHAR *)pgucAtSndCodeAddr,
                                                    (VOS_CHAR *)pgucAtSndCodeAddr,
                                                     "%s: %d",
                                                     g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                                     pstMtaCnf->ulEnableFlag);
    }

    /* ������ */
    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}




VOS_UINT32 AT_SetFratIgnitionPara(VOS_UINT8 ucIndex)
{
    VOS_UINT32                          ulRst;
    AT_MTA_FRAT_IGNITION_ENUM_UNIT8     enFratIgnitionSta;

    /* ������� */
    if ( AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType )
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ������Ŀ��� */
    if (gucAtParaIndex != 1)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ucFratIgnitionSta ȡֵ���� */
    if ((gastAtParaList[0].ulParaValue >= AT_MTA_FRAT_IGNITION_STATT_BUTT)
     || (0 == gastAtParaList[0].usParaLen))
    {
        AT_WARN_LOG1("AT_SetFratIgnitionPara: para err", gastAtParaList[0].ulParaValue);
        return AT_CME_INCORRECT_PARAMETERS;
    }

    enFratIgnitionSta = (AT_MTA_FRAT_IGNITION_ENUM_UNIT8)gastAtParaList[0].ulParaValue;

    /* ������Ϣ ID_AT_MTA_FRAT_IGNITION_SET_REQ ��MTA��������Ϣ������(VOS_UINT8)gastAtParaList[0].ulParaValue */
    ulRst = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                   0,
                                   ID_AT_MTA_FRAT_IGNITION_SET_REQ,
                                   (VOS_VOID *)&enFratIgnitionSta,
                                   sizeof(enFratIgnitionSta),
                                   I0_UEPS_PID_MTA);

    if (TAF_SUCCESS == ulRst)
    {
        gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_FRATIGNITION_SET;
        return AT_WAIT_ASYNC_RETURN;
    }
    else
    {
        AT_WARN_LOG("AT_SetFratIgnitionPara: send ReqMsg fail");
        return AT_ERROR;
    }
}


VOS_UINT32 AT_CheckLineIndexListBsPara(VOS_VOID)
{
    VOS_UINT32                          ulLoop;

    /* ��ȡЯ��BS1��BS2��BS3�����ܳ���,BS1�ǵ�4����������gastAtParaList[3]������BS1�����Ϣ */
    for (ulLoop = 3; ulLoop < gucAtParaIndex; ulLoop++)
    {
        /* ��������BS1������BS2������BS3���ڿն����߳��ȴ���500��ֱ�ӷ��ش���
           ����AT^LINEINDEXlIST=255,"00.00.001",0,,BS2 (����BS1���ڿն�,����Ϊ0),
           AT^LINEINDEXlIST=255,"00.00.001",0,BS1,     (����BS2���ڿն�,����Ϊ0) */
        if ((0 == gastAtParaList[ulLoop].usParaLen)
         || (AT_CMD_LINE_INDEX_LIST_BS_MAX_LENGTH < gastAtParaList[ulLoop].usParaLen))
        {
            AT_ERR_LOG("AT_CheckLineIndexListBsPara: input BS format is error");

            return AT_CME_INCORRECT_PARAMETERS;
        }

    }
    return AT_SUCCESS;
}


VOS_UINT32 AT_CheckLineIndexListPara(VOS_VOID)
{
    /* ������������ȷ,3~6������ */
    if((6 < gucAtParaIndex)
    || (3 > gucAtParaIndex))
    {
       AT_ERR_LOG("AT_CheckLineIndexListPara:number of parameter error.");

       return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ����������Ȳ��� */
    if ((0 == gastAtParaList[0].usParaLen)
     || (AT_CSS_CLOUD_LINE_VERSION_LEN != gastAtParaList[1].usParaLen)
     || (0 == gastAtParaList[2].usParaLen))
    {
        AT_ERR_LOG("AT_CheckLineIndexListPara:para len error.");

        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ���������������·������Ϣ����������С�ڵ���3�� */
    if ((AT_CSS_LINE_INDEX_LIST_ADD == gastAtParaList[2].ulParaValue)
     && (3 >= gucAtParaIndex))
    {
       AT_ERR_LOG("AT_CheckLineIndexListPara:too little para when add line index list.");

       return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ���������������·������Ϣ��BS1����С��0 */
    if ((AT_CSS_LINE_INDEX_LIST_ADD == gastAtParaList[2].ulParaValue)
     && (0 == gastAtParaList[3].usParaLen))
    {
       AT_ERR_LOG("AT_CheckLineIndexListPara:BS1 length is 0 when add line index list.");

       return AT_CME_INCORRECT_PARAMETERS;
    }

    /* �����ɾ�����е���ͨ�Ÿ���������Ϣ������ҪЯ��BS1��BS2��BS3����length����Ϊ0 */
    if ((AT_CSS_LINE_INDEX_LIST_DELETE_ALL == gastAtParaList[2].ulParaValue)
     && (3 < gucAtParaIndex))
    {
       AT_ERR_LOG("AT_CheckLineIndexListPara:too mang para when delete all line index list.");

       return AT_CME_INCORRECT_PARAMETERS;
    }

    /* �����BS��ʽ����ȷ���������ڿն���BS�ܳ��Ȳ�����length���� */
    if (AT_SUCCESS != AT_CheckLineIndexListBsPara())
    {
        AT_ERR_LOG("AT_CheckLineIndexListPara:input BS para is error.");

        return AT_CME_INCORRECT_PARAMETERS;
    }

    return AT_SUCCESS;
}


VOS_UINT32 AT_CheckLineDetailBsPara(VOS_VOID)
{
    VOS_UINT32                          ulLoop;

    /* ��ȡЯ��BS1��BS2��BS3�����ܳ���,BS1�ǵ�4����������gastAtParaList[3]������BS1�����Ϣ */
    for (ulLoop = 3; ulLoop < gucAtParaIndex; ulLoop++)
    {
        /* ��������BS1������BS2������BS3���ڿն����߳��ȴ���500��ֱ�ӷ��ش���
           ����AT^LINEINDEXlIST=255,"00.00.001",0,,BS2 (����BS1���ڿն�,����Ϊ0),
           AT^LINEINDEXlIST=255,"00.00.001",0,BS1,     (����BS2���ڿն�,����Ϊ0) */
        if ((0 == gastAtParaList[ulLoop].usParaLen)
         || (AT_CMD_LINE_DETAIL_BS_MAX_LENGTH < gastAtParaList[ulLoop].usParaLen))
        {
            AT_ERR_LOG("AT_CheckLineIndexListBsPara: input BS format is error");

            return AT_CME_INCORRECT_PARAMETERS;
        }
    }
    return AT_SUCCESS;
}


VOS_UINT32 AT_CheckLineDetailPara(VOS_VOID)
{
    /* ������������ȷ,3~6������ */
    if((6 < gucAtParaIndex)
    || (3 > gucAtParaIndex))
    {
       AT_ERR_LOG("AT_CheckLineDetailPara:number of parameter error.");

       return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ����������Ȳ��� */
    if ((0 == gastAtParaList[0].usParaLen)
     || (AT_CSS_CLOUD_LINE_VERSION_LEN != gastAtParaList[1].usParaLen)
     || (0 == gastAtParaList[2].usParaLen))
    {
        AT_ERR_LOG("AT_CheckLineDetailPara:para len error.");

        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ���������������·������Ϣ����������С��3�� */
    if ((AT_CSS_LINE_DETAIL_ADD == gastAtParaList[2].ulParaValue)
     && (3 >= gucAtParaIndex))
    {
       AT_ERR_LOG("AT_CheckLineDetailPara:too little para when add line index list.");

       return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ���������������·������Ϣ��BS1����С��0 */
    if ((AT_CSS_LINE_DETAIL_ADD == gastAtParaList[2].ulParaValue)
     && (0 == gastAtParaList[3].usParaLen))
    {
       AT_ERR_LOG("AT_CheckLineDetailPara:BS1 length is 0 when add line index list.");

       return AT_CME_INCORRECT_PARAMETERS;
    }

    /* �����ɾ�����е���ͨ�Ÿ���������Ϣ������ҪЯ��BS1��BS2��BS3����length����Ϊ0 */
    if ((AT_CSS_LINE_DETAIL_DELETE_ALL == gastAtParaList[2].ulParaValue)
     && (3 < gucAtParaIndex))
    {
       AT_ERR_LOG("AT_CheckLineDetailPara:too mang para when delete all line index list.");

       return AT_CME_INCORRECT_PARAMETERS;
    }

    /* �����BS��ʽ����ȷ���������ڿն���BS�ܳ��Ȳ�����length���� */
    if (AT_SUCCESS != AT_CheckLineDetailBsPara())
    {
        AT_ERR_LOG("AT_CheckLineDetailPara:input BS para is error.");

        return AT_CME_INCORRECT_PARAMETERS;
    }

    return AT_SUCCESS;
}


VOS_UINT32 AT_SetLineIndexListPara(
    VOS_UINT8                           ucIndex
)
{
    AT_CSS_LINE_INDEX_LIST_SET_REQ_STRU                    *pstMsg = VOS_NULL_PTR;
    VOS_UINT32                                              ulBufLen;
    VOS_UINT32                                              ulBsLen;
    VOS_UINT32                                              ulResult;
    VOS_UINT32                                              ulLoop;
    VOS_UINT32                                              ulDeltaLen;
    MODEM_ID_ENUM_UINT16                                    enModemId;
    VOS_UINT32                                              ulRet;

    enModemId = MODEM_ID_0;
    ulRet = AT_GetModemIdFromClient(ucIndex, &enModemId);
    if (VOS_OK != ulRet)
    {
        AT_ERR_LOG("AT_SetMccFreqPara: Get modem id fail.");
        return AT_ERROR;
    }

    /* �������ͼ�� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        AT_ERR_LOG("AT_SetLineIndexListPara:Cmd Opt Type is wrong.");

        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ������� */
    ulResult = AT_CheckLineIndexListPara();
    if (AT_SUCCESS != ulResult)
    {
        AT_ERR_LOG("AT_SetLineIndexListPara:check line index list para error.");

        return ulResult;
    }

    ulBsLen  = gastAtParaList[3].usParaLen + gastAtParaList[4].usParaLen + gastAtParaList[5].usParaLen;
    ulBufLen = sizeof(AT_CSS_LINE_INDEX_LIST_SET_REQ_STRU);

    if (4 < ulBsLen)
    {
        ulBufLen += ulBsLen - 4;
    }

    /* ������Ϣ��AT_CSS_LINE_INDEX_LIST_SET_REQ_STRU */
    pstMsg = (AT_CSS_LINE_INDEX_LIST_SET_REQ_STRU *)AT_ALLOC_MSG_WITH_HDR(ulBufLen);

    /* �ڴ�����ʧ�ܣ����� */
    if (VOS_NULL_PTR == pstMsg)
    {
        AT_ERR_LOG("AT_SetLineIndexListPara:memory alloc fail.");

        return AT_ERROR;
    }

    TAF_MEM_SET_S((VOS_INT8 *)pstMsg + VOS_MSG_HEAD_LENGTH,
                  (VOS_SIZE_T)ulBufLen - VOS_MSG_HEAD_LENGTH,
                  0x00,
                  (VOS_SIZE_T)ulBufLen - VOS_MSG_HEAD_LENGTH);

    /* ��д��Ϣͷ */
    AT_CFG_MSG_HDR(pstMsg, PS_PID_CSS, ID_AT_CSS_LINE_INDEX_LIST_SET_REQ);

    /* ��д��Ϣ���� */
    pstMsg->usClientId                  = gastAtClientTab[ucIndex].usClientId;
    pstMsg->ucSeq                       = (VOS_UINT8)gastAtParaList[0].ulParaValue;
    pstMsg->usModemId                   = enModemId;

    TAF_MEM_CPY_S(pstMsg->aucVersionId,
                  sizeof(pstMsg->aucVersionId),
                  gastAtParaList[1].aucPara,
                  gastAtParaList[1].usParaLen);

    pstMsg->enOperateType               = (VOS_UINT8)gastAtParaList[2].ulParaValue;
    pstMsg->ulLineIndexListBuffLen      = ulBsLen;

    ulDeltaLen = 0;
    for (ulLoop = 3; ulLoop < 6; ulLoop++)
    {
        if (0 < gastAtParaList[ulLoop].usParaLen)
        {
            /* BS��󳤶���AT_CMD_LINE_INDEX_LIST_BS_MAX_LENGTH */
            TAF_MEM_CPY_S(pstMsg->aucLineIndexListBuff + ulDeltaLen,
                          (ulBsLen - ulDeltaLen),
                          gastAtParaList[ulLoop].aucPara,
                          gastAtParaList[ulLoop].usParaLen);
            ulDeltaLen =  ulDeltaLen + gastAtParaList[ulLoop].usParaLen;
        }
        else
        {
            break;
        }
    }

    /* ������Ϣ��������������״̬ */
    AT_SEND_MSG(pstMsg);

    /* ���õ�ǰ�������� */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_LINEINDEXLIST_SET;

    return AT_WAIT_ASYNC_RETURN;
}


VOS_UINT32 AT_SetLineDetailPara(
    VOS_UINT8                           ucIndex
)
{
    AT_CSS_LINE_DETAIL_SET_REQ_STRU    *pstMsg = VOS_NULL_PTR;
    VOS_UINT32                          ulBufLen;
    VOS_UINT32                          ulBsLen;
    VOS_UINT32                          ulResult;
    VOS_UINT32                          ulLoop;
    VOS_UINT32                          ulDeltaLen;
    MODEM_ID_ENUM_UINT16                enModemId;
    VOS_UINT32                          ulRet;

    enModemId = MODEM_ID_0;
    ulRet = AT_GetModemIdFromClient(ucIndex, &enModemId);

    if (VOS_OK != ulRet)
    {
        AT_ERR_LOG("AT_SetMccFreqPara: Get modem id fail.");
        return AT_ERROR;
    }

    /* �������ͼ�� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        AT_ERR_LOG("AT_SetLineDetailPara:Cmd Opt Type is wrong.");

        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ������� */
    ulResult = AT_CheckLineDetailPara();
    if (AT_SUCCESS != ulResult)
    {
        AT_ERR_LOG("AT_SetLineDetailPara:check line index list para error.");

        return ulResult;
    }

    ulBsLen  = gastAtParaList[3].usParaLen + gastAtParaList[4].usParaLen + gastAtParaList[5].usParaLen;
    ulBufLen = sizeof(AT_CSS_LINE_DETAIL_SET_REQ_STRU);

    if (4 < ulBsLen)
    {
        ulBufLen += ulBsLen - 4;
    }

    /* ������Ϣ��AT_CSS_LINE_DETAIL_SET_REQ_STRU */
    pstMsg = (AT_CSS_LINE_DETAIL_SET_REQ_STRU *)AT_ALLOC_MSG_WITH_HDR(ulBufLen);

    /* �ڴ�����ʧ�ܣ����� */
    if (VOS_NULL_PTR == pstMsg)
    {
        AT_ERR_LOG("AT_SetLineDetailPara:memory alloc fail.");

        return AT_ERROR;
    }

    TAF_MEM_SET_S((VOS_INT8 *)pstMsg + VOS_MSG_HEAD_LENGTH,
                  (VOS_SIZE_T)ulBufLen - VOS_MSG_HEAD_LENGTH,
                  0x00,
                  (VOS_SIZE_T)ulBufLen - VOS_MSG_HEAD_LENGTH);

    /* ��д��Ϣͷ */
    AT_CFG_MSG_HDR(pstMsg, PS_PID_CSS, ID_AT_CSS_LINE_DETAIL_SET_REQ);

    /* ��д��Ϣ���� */
    pstMsg->usModemId                   = enModemId;
    pstMsg->usClientId                  = gastAtClientTab[ucIndex].usClientId;
    pstMsg->ucSeq                       = (VOS_UINT8)gastAtParaList[0].ulParaValue;

    TAF_MEM_CPY_S(pstMsg->aucVersionId,
                  sizeof(pstMsg->aucVersionId),
                  gastAtParaList[1].aucPara,
                  gastAtParaList[1].usParaLen);

    pstMsg->enOperateType            = (VOS_UINT8)gastAtParaList[2].ulParaValue;
    pstMsg->ulLineDetailBuffLen      = ulBsLen;

    ulDeltaLen = 0;
    for (ulLoop = 3; ulLoop < 6; ulLoop++)
    {
        if (0 < gastAtParaList[ulLoop].usParaLen)
        {
            /* BS��󳤶���AT_CMD_LINE_INDEX_LIST_BS_MAX_LENGTH */
            TAF_MEM_CPY_S(pstMsg->aucLineDetailBuff + ulDeltaLen,
                          (ulBsLen - ulDeltaLen),
                          gastAtParaList[ulLoop].aucPara,
                          gastAtParaList[ulLoop].usParaLen);
            ulDeltaLen =  ulDeltaLen + gastAtParaList[ulLoop].usParaLen;
        }
        else
        {
            break;
        }
    }

    /* ������Ϣ��������������״̬ */
    AT_SEND_MSG(pstMsg);

    /* ���õ�ǰ�������� */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_LINEDETAIL_SET;

    return AT_WAIT_ASYNC_RETURN;
}


VOS_UINT32 AT_QryLineIndexListPara(
    VOS_UINT8                           ucIndex
)
{
    AT_CSS_LINE_INDEX_LIST_QUERY_REQ_STRU                  *pstMsg = VOS_NULL_PTR;
    MODEM_ID_ENUM_UINT16                                    enModemId;
    VOS_UINT32                                              ulRet;

    enModemId = MODEM_ID_0;

    ulRet = AT_GetModemIdFromClient(ucIndex, &enModemId);
    if (VOS_OK != ulRet)
    {
        AT_ERR_LOG("AT_SetMccFreqPara: Get modem id fail.");
        return AT_ERROR;
    }

    /* ������� */
    if (AT_CMD_OPT_READ_CMD != g_stATParseCmd.ucCmdOptType)
    {
        AT_ERR_LOG("AT_QryLineIndexListPara: Invalid Cmd Type");

        return AT_ERROR;
    }

    /* Allocating memory for message */
    /*lint -save -e516 */
    pstMsg = (AT_CSS_LINE_INDEX_LIST_QUERY_REQ_STRU *)AT_ALLOC_MSG_WITH_HDR(sizeof(AT_CSS_LINE_INDEX_LIST_QUERY_REQ_STRU));
    /*lint -restore */

    if (VOS_NULL_PTR == pstMsg)
    {
        AT_ERR_LOG("AT_QryLineIndexListPara: Mem Alloc failed");

        return AT_ERROR;
    }

    TAF_MEM_SET_S(((VOS_UINT8 *)pstMsg + VOS_MSG_HEAD_LENGTH),
                  (VOS_SIZE_T)(sizeof(AT_CSS_LINE_INDEX_LIST_QUERY_REQ_STRU) - VOS_MSG_HEAD_LENGTH),
                  0x00,
                  (VOS_SIZE_T)(sizeof(AT_CSS_LINE_INDEX_LIST_QUERY_REQ_STRU) - VOS_MSG_HEAD_LENGTH));

    /* ��д��Ϣͷ */
    AT_CFG_MSG_HDR(pstMsg, PS_PID_CSS, ID_AT_CSS_LINE_INDEX_LIST_QUERY_REQ);
    pstMsg->usModemId           = enModemId;
    pstMsg->usClientId          = gastAtClientTab[ucIndex].usClientId;

    AT_SEND_MSG(pstMsg);

    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_LINEINDEXLIST_QRY;

    return AT_WAIT_ASYNC_RETURN;
}

VOS_UINT32 AT_TimeParaYTDCheck(AT_MTA_MODEM_TIME_STRU *pstAtMtaModemTime)
{
    VOS_UINT8                           aucBuffer[AT_GET_MODEM_TIME_BUFF_LEN];

    /* ������������VER���Ȳ���ȷ */
    if (AT_MODEM_YTD_LEN != gastAtParaList[0].usParaLen)
    {
       AT_ERR_LOG("AT_TimeParaYTDCheck: length of YTD parameter is error.");
       return VOS_ERR;
    }

    /* ���ո�ʽ YYYY/MM/DD ���������գ����жϸ�ʽ����Χ */
    if ((gastAtParaList[0].aucPara[4] != '/')
     || (gastAtParaList[0].aucPara[7] != '/'))
    {
        AT_ERR_LOG("AT_TimeParaYTDCheck: The date formats parameter is error.");
        return VOS_ERR;
    }

    TAF_MEM_SET_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), 0x00, (VOS_SIZE_T)sizeof(aucBuffer));
    TAF_MEM_CPY_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), gastAtParaList[0].aucPara, AT_MODEM_YEAR_LEN);
    pstAtMtaModemTime->lYear = (VOS_INT32)AT_AtoI(aucBuffer);

    if ((pstAtMtaModemTime->lYear > AT_MODEM_YEAR_MAX)
     || (pstAtMtaModemTime->lYear < AT_MODEM_YEAR_MIN))
    {
        AT_ERR_LOG("AT_TimeParaYTDCheck: The parameter of year is out of range");
        return VOS_ERR;
    }

    TAF_MEM_SET_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), 0x00, (VOS_SIZE_T)sizeof(aucBuffer));
    TAF_MEM_CPY_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), &gastAtParaList[0].aucPara[5], AT_MODEM_MONTH_LEN);
    pstAtMtaModemTime->lMonth = (VOS_INT32)AT_AtoI(aucBuffer);

    if ((pstAtMtaModemTime->lMonth > AT_MODEM_MONTH_MAX)
     || (pstAtMtaModemTime->lMonth < AT_MODEM_MONTH_MIN))
    {
        AT_ERR_LOG("AT_TimeParaYTDCheck: The parameter of month is out of range");
        return VOS_ERR;
    }

    TAF_MEM_SET_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), 0x00, (VOS_SIZE_T)sizeof(aucBuffer));
    TAF_MEM_CPY_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), &gastAtParaList[0].aucPara[8], AT_MODEM_DATE_LEN);
    pstAtMtaModemTime->lDay = (VOS_INT32)AT_AtoI(aucBuffer);

    if ((pstAtMtaModemTime->lDay > AT_MODEM_DAY_MAX)
     || (pstAtMtaModemTime->lDay < AT_MODEM_DAY_MIN))
    {
        AT_ERR_LOG("AT_TimeParaYTDCheck: The parameter of day is out of range");
        return VOS_ERR;
    }

    return VOS_OK;
}


VOS_UINT32 AT_TimeParaTimeCheck(AT_MTA_MODEM_TIME_STRU *pstAtMtaModemTime)
{
    VOS_UINT8                           aucBuffer[AT_GET_MODEM_TIME_BUFF_LEN];

    if (AT_MODEM_TIME_LEN != gastAtParaList[1].usParaLen)
    {
       AT_ERR_LOG("AT_TimeParaTimeCheck: length of time parameter is error.");
       return VOS_ERR;
    }

    /* ���ո�ʽ HH:MM:SS ����ʱ�䣬���жϸ�ʽ����Χ */
    if ((gastAtParaList[1].aucPara[2] != ':')
     || (gastAtParaList[1].aucPara[5] != ':'))
    {
        AT_ERR_LOG("AT_TimeParaTimeCheck: The time formats parameter is error.");
        return VOS_ERR;
    }

    TAF_MEM_SET_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), 0x00, (VOS_SIZE_T)sizeof(aucBuffer));
    TAF_MEM_CPY_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), gastAtParaList[1].aucPara, AT_MODEM_HOUR_LEN);
    pstAtMtaModemTime->lHour = (VOS_INT32)AT_AtoI(aucBuffer);

    if ((pstAtMtaModemTime->lHour > AT_MODEM_HOUR_MAX)
     || (pstAtMtaModemTime->lHour < AT_MODEM_HOUR_MIN))
    {
        AT_ERR_LOG("AT_TimeParaTimeCheck: The parameter of hour is out of range");
        return VOS_ERR;
    }

    TAF_MEM_SET_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), 0x00, (VOS_SIZE_T)sizeof(aucBuffer));
    TAF_MEM_CPY_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), &gastAtParaList[1].aucPara[3], AT_MODEM_MIN_LEN);
    pstAtMtaModemTime->lMin = (VOS_INT32)AT_AtoI(aucBuffer);

    if ((pstAtMtaModemTime->lMin > AT_MODEM_MIN_MAX)
     || (pstAtMtaModemTime->lMin < AT_MODEM_MIN_MIN))
    {
        AT_ERR_LOG("AT_TimeParaTimeCheck: The parameter of min is out of range");
        return VOS_ERR;
    }

    TAF_MEM_SET_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), 0x00, (VOS_SIZE_T)sizeof(aucBuffer));
    TAF_MEM_CPY_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), &gastAtParaList[1].aucPara[6], AT_MODEM_SEC_LEN);
    pstAtMtaModemTime->lSec = (VOS_INT32)AT_AtoI(aucBuffer);

    if ((pstAtMtaModemTime->lSec > AT_MODEM_SEC_MAX)
     || (pstAtMtaModemTime->lSec < AT_MODEM_SEC_MIN))
    {
        AT_ERR_LOG("AT_TimeParaTimeCheck: The parameter of second is out of range");
        return VOS_ERR;
    }

    return VOS_OK;
}


VOS_UINT32 AT_TimeParaZoneCheck(AT_MTA_MODEM_TIME_STRU *pstAtMtaModemTime)
{
    VOS_UINT8                           aucBuffer[AT_GET_MODEM_TIME_BUFF_LEN];

    if ( (0                          == gastAtParaList[2].usParaLen)
      || (AT_GET_MODEM_TIME_BUFF_LEN <= gastAtParaList[2].usParaLen) )
    {
        AT_ERR_LOG1("AT_TimeParaZoneCheck: length of zone parameter is wrong.", gastAtParaList[2].usParaLen);
        return VOS_ERR;
    }

    TAF_MEM_SET_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), 0x00, (VOS_SIZE_T)sizeof(aucBuffer));
    TAF_MEM_CPY_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), gastAtParaList[2].aucPara, gastAtParaList[2].usParaLen);

    /* ʱ����Χ��[-12, 12] */
    if (VOS_ERR == AT_AtoInt(aucBuffer, &pstAtMtaModemTime->lZone))
    {
        return VOS_ERR;
    }

    if ((pstAtMtaModemTime->lZone > AT_MODEM_ZONE_MAX)
    ||  (pstAtMtaModemTime->lZone < AT_MODEM_ZONE_MIN))
    {
        AT_ERR_LOG("AT_TimeParaZoneCheck: The parameter of zone is out of range.");
        return VOS_ERR;
    }

    return VOS_OK;
}


VOS_UINT32 AT_SetModemTimePara(VOS_UINT8 ucIndex)
{
    AT_MTA_MODEM_TIME_STRU              stAtMtaModemTime;
    VOS_UINT32                          ulRst;

    /* ������� */
    if ( AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType )
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ������Ŀ��� */
    if (gucAtParaIndex != 3)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ������ʽ��� */
    TAF_MEM_SET_S(&stAtMtaModemTime, (VOS_SIZE_T)sizeof(stAtMtaModemTime), 0x00, (VOS_SIZE_T)sizeof(stAtMtaModemTime));

    /* ��������� */
    if (VOS_ERR == AT_TimeParaYTDCheck(&stAtMtaModemTime))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ���ʱ��*/
    if (VOS_ERR == AT_TimeParaTimeCheck(&stAtMtaModemTime))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ���ʱ�� */
    if (VOS_ERR == AT_TimeParaZoneCheck(&stAtMtaModemTime))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ������Ϣ ID_AT_MTA_MODEM_TIME_SET_REQ ��MTA��������Ϣ������ stAtMtaModemTime */
    ulRst = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                   0,
                                   ID_AT_MTA_MODEM_TIME_SET_REQ,
                                   (VOS_VOID *)&stAtMtaModemTime,
                                   (VOS_SIZE_T)sizeof(stAtMtaModemTime),
                                   I0_UEPS_PID_MTA);

    if (TAF_SUCCESS == ulRst)
    {
        gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_MODEM_TIME_SET;
        return AT_WAIT_ASYNC_RETURN;
    }
    else
    {
        AT_WARN_LOG("AT_SetModemTimePara: send ReqMsg fail");
        return AT_ERROR;
    }
}


VOS_UINT32 AT_SetPhyComCfgPara(VOS_UINT8 ucIndex)
{
    AT_MTA_PHY_COM_CFG_SET_REQ_STRU     stPhyComCfg;
    VOS_UINT32                          ulResult;

    /* �ֲ�������ʼ�� */
    TAF_MEM_SET_S(&stPhyComCfg, (VOS_SIZE_T)sizeof(stPhyComCfg), 0x00, (VOS_SIZE_T)sizeof(AT_MTA_PHY_COM_CFG_SET_REQ_STRU));

    /* ������� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        AT_WARN_LOG("AT_SetPhyComCfg : Current Option is not AT_CMD_OPT_SET_PARA_CMD.");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* �жϲ������� */
    if ((gucAtParaIndex < 3) || (gucAtParaIndex > 5))
    {
        /* ������������ */
        AT_WARN_LOG("AT_SetPhyComCfg : Current Number wrong.");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ��Ϣ��ֵ */
    stPhyComCfg.usCmdType               = (VOS_UINT16)gastAtParaList[0].ulParaValue;
    stPhyComCfg.usRatBitmap             = (VOS_UINT16)gastAtParaList[1].ulParaValue;
    stPhyComCfg.ulPara1                 = gastAtParaList[2].ulParaValue;

    if (4 == gucAtParaIndex)
    {
        stPhyComCfg.ulPara2             = gastAtParaList[3].ulParaValue;
    }
    else
    {
        stPhyComCfg.ulPara2             = gastAtParaList[3].ulParaValue;
        stPhyComCfg.ulPara3             = gastAtParaList[4].ulParaValue;
    }

    /* ������Ϣ��MTA */
    ulResult = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                      gastAtClientTab[ucIndex].opId,
                                      ID_AT_MTA_PHY_COM_CFG_SET_REQ,
                                      &stPhyComCfg,
                                      (VOS_SIZE_T)sizeof(stPhyComCfg),
                                      I0_UEPS_PID_MTA);

    /* ����ʧ�� */
    if (TAF_SUCCESS != ulResult)
    {
        AT_WARN_LOG("AT_SetPhyComCfg: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

    /* ���ͳɹ������õ�ǰ����ģʽ */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_PHY_COM_CFG_SET;
    g_stAtDevCmdCtrl.ucIndex               = ucIndex;

    /* �ȴ��첽����ʱ�䷵�� */
    return AT_WAIT_ASYNC_RETURN;
}


VOS_UINT32 AT_RcvMtaPhyComCfgSetCnf(VOS_VOID *pMsg)
{
    AT_MTA_MSG_STRU                    *pstRcvMsg       = VOS_NULL_PTR;
    MTA_AT_PHY_COM_CFG_SET_CNF_STRU    *pstPhyComCfgCnf = VOS_NULL_PTR;
    VOS_UINT8                           ucIndex;

    /*��ʼ���ֲ�����*/
    pstRcvMsg                           = (AT_MTA_MSG_STRU *)pMsg;
    pstPhyComCfgCnf                     = (MTA_AT_PHY_COM_CFG_SET_CNF_STRU *)pstRcvMsg->aucContent;
    ucIndex                             = 0;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pstRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaPhyComCfgSetCnf: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaPhyComCfgSetCnf: AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* �жϵ�ǰ���������Ƿ�ΪAT_CMD_PHY_COM_CFG_SET */
    if (AT_CMD_PHY_COM_CFG_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaPhyComCfgSetCnf: NOT CURRENT CMD OPTION!");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    gstAtSendData.usBufLen = 0;

    /* ��ʽ���ϱ����� */
    if (MTA_AT_RESULT_NO_ERROR != pstPhyComCfgCnf->enResult)
    {
        /* ������ *AT_ERROR */
        At_FormatResultData(ucIndex, AT_ERROR);
    }
    else
    {
        /* ������ *AT_OK */
        At_FormatResultData(ucIndex, AT_OK);
    }

    return VOS_OK;
}



VOS_UINT32 AT_GetValidSamplePara(
    AT_MTA_SET_SAMPLE_REQ_STRU          *stAtCmd
)
{
    VOS_INT32                          lTemp;

    /* ������� */
    if(AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ������������4��������AT_CME_INCORRECT_PARAMETERS */
    if (4 < gucAtParaIndex)
    {
        AT_WARN_LOG("AT_GetValidNetScanPara: At Para Num Error.");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ��1����������Ϊ0������AT_CME_INCORR ECT_PARAMETERS */
    if (0 == gastAtParaList[0].usParaLen)
    {
        AT_WARN_LOG("AT_GetValidNetScanPara: para0 Length = 0");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    stAtCmd->usReqType = (VOS_UINT16)gastAtParaList[0].ulParaValue;

    if (0 == gastAtParaList[1].usParaLen)
    {
        stAtCmd->usTempRange = AT_TEMP_ZONE_DEFAULT;
    }
    else
    {
        stAtCmd->usTempRange = (VOS_UINT16)gastAtParaList[1].ulParaValue;
    }

    if (0 == gastAtParaList[2].usParaLen)
    {
        stAtCmd->sPpmOffset = 0;
    }
    else
    {
        lTemp      = 0;
        
        if (VOS_ERR == AT_AtoInt(gastAtParaList[2].aucPara, &lTemp))
        {
            AT_ERR_LOG("AT_GetValidNetScanPara: para2 err");
            return AT_CME_INCORRECT_PARAMETERS;
        }
        
        stAtCmd->sPpmOffset = (VOS_INT16)lTemp;      
    }

    if (0 == gastAtParaList[3].usParaLen)
    {
        stAtCmd->sTimeOffset = 0;
    }
    else
    {
        lTemp      = 0;
        
        if (VOS_ERR == AT_AtoInt(gastAtParaList[3].aucPara, &lTemp))
        {
            AT_ERR_LOG("AT_GetValidNetScanPara: para3 err");
            return AT_CME_INCORRECT_PARAMETERS;
        }

        stAtCmd->sTimeOffset = (VOS_INT16)lTemp;
    }

    return AT_OK;

}




VOS_UINT32 AT_SetSamplePara(VOS_UINT8 ucIndex)
{
    AT_MTA_SET_SAMPLE_REQ_STRU          stAtCmd;
    VOS_UINT32                          ulResult;
    MODEM_ID_ENUM_UINT16                enModemId;
    VOS_UINT32                          ulRet;

    TAF_MEM_SET_S(&stAtCmd, sizeof(stAtCmd), 0x00, sizeof(AT_MTA_SET_SAMPLE_REQ_STRU));

    enModemId = MODEM_ID_0;
    ulRet     = AT_GetModemIdFromClient(ucIndex, &enModemId);
    if (VOS_OK != ulRet)
    {
        AT_ERR_LOG("AT_SetSamplePara: Get modem id fail.");
        return AT_ERROR;
    }

    if (enModemId != MODEM_ID_0)
    {
        AT_ERR_LOG("AT_SetSamplePara: MODEM_ID ERROR");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    ulRet    = AT_GetValidSamplePara(&stAtCmd);
    
    if (AT_OK != ulRet)
    {
        AT_ERR_LOG("AT_SetSamplePara: AT_GetValidNetScanPara Failed");
        return ulRet;
    }

    ulResult = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                      0,
                                      ID_AT_MTA_SET_SAMPLE_REQ,
                                      &stAtCmd,
                                      sizeof(AT_MTA_SET_SAMPLE_REQ_STRU),
                                      I0_UEPS_PID_MTA);

    if (AT_SUCCESS != ulResult)
    {
        AT_WARN_LOG("AT_SetSamplePara: AT_FillAndSndAppReqMsg Failed!");
        return AT_ERROR;
    }
    
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_SAMPLE_SET;
    
    return AT_WAIT_ASYNC_RETURN;
}


VOS_UINT32 AT_RcvMtaSetSampleCnf(VOS_VOID *pMsg)
{
    AT_MTA_MSG_STRU                        *pstRcvMsg               = VOS_NULL_PTR;
    MTA_AT_SET_SAMPLE_CNF_STRU             *pstSetCnf               = VOS_NULL_PTR;
    VOS_UINT32                              ulResult;
    VOS_UINT8                               ucIndex;

    /* ��ʼ�� */
    pstRcvMsg                 = (AT_MTA_MSG_STRU *)pMsg;
    pstSetCnf                 = (MTA_AT_SET_SAMPLE_CNF_STRU *)pstRcvMsg->aucContent;
    ulResult                  = AT_OK;
    ucIndex                   = 0;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pstRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaSetSampleCnf : WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    /* �ж��Ƿ�Ϊ�㲥 */
    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaSetSampleCnf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_SAMPLE_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaSetSampleCnf : Current Option is not AT_CMD_SAMPLE_SET.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);
    gstAtSendData.usBufLen = 0;

    if (MTA_AT_RESULT_NO_ERROR == pstSetCnf->enResult)
    {
        ulResult = AT_OK;
    }
    else
    {
        ulResult = AT_ERROR;
    }

    At_FormatResultData(ucIndex, ulResult);
    
    return VOS_OK;
}




VOS_UINT32 AT_SetRxTestModePara(VOS_UINT8 ucIndex)
{
    AT_MTA_SET_RXTESTMODE_REQ_STRU      stRxTestModeCfg;
    VOS_UINT32                          ulRst;

    TAF_MEM_SET_S(&stRxTestModeCfg, (VOS_SIZE_T)sizeof(stRxTestModeCfg), 0x00, (VOS_SIZE_T)sizeof(AT_MTA_SET_RXTESTMODE_REQ_STRU));

    /* ������� */
    if ( AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType )
    {
        AT_WARN_LOG("AT_SetRxTestModePara : Current Option is not AT_CMD_OPT_SET_PARA_CMD.");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ������������ȷ */
    if ( 1 != gucAtParaIndex )
    {
        AT_WARN_LOG("AT_SetRxTestModePara : The number of input parameters is error.");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ����Ϊ�� */
    if( 0 == gastAtParaList[0].usParaLen )
    {
        AT_WARN_LOG("AT_SetRxTestModePara : The number of input parameters is zero.");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    stRxTestModeCfg.enCfg  = (VOS_UINT8)gastAtParaList[0].ulParaValue;

    /* ���Ϳ����Ϣ��C��, ������������ģʽ */
    ulRst = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                   gastAtClientTab[ucIndex].opId,
                                   ID_AT_MTA_RX_TEST_MODE_SET_REQ,
                                   &stRxTestModeCfg,
                                   (VOS_SIZE_T)sizeof(stRxTestModeCfg),
                                   I0_UEPS_PID_MTA);

    if (TAF_SUCCESS != ulRst)
    {
        AT_WARN_LOG("AT_SetRxTestModePara: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

    /* ����ATģ��ʵ���״̬Ϊ�ȴ��첽���� */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_RXTESTMODE_SET;

    return AT_WAIT_ASYNC_RETURN;
}


VOS_UINT32 AT_RcvMtaSetRxTestModeCnf(VOS_VOID *pMsg)
{
    AT_MTA_MSG_STRU                    *pstRcvMsg;
    MTA_AT_SET_RXTESTMODE_CNF_STRU     *pstSetCnf;
    VOS_UINT8                           ucIndex;
    VOS_UINT32                          ulResult;

    /* ��ʼ�� */
    pstRcvMsg    = (AT_MTA_MSG_STRU *)pMsg;
    pstSetCnf    = (MTA_AT_SET_RXTESTMODE_CNF_STRU *)pstRcvMsg->aucContent;
    ucIndex      = 0;
    ulResult     = AT_ERROR;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pstRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaSetRxTestModeCnf : WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaSetRxTestModeCnf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_RXTESTMODE_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaSetRxTestModeCnf : Current Option is not AT_CMD_RXTESTMODE_SET.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    /* ��ʽ������� */
    gstAtSendData.usBufLen = 0;

    if (MTA_AT_RESULT_NO_ERROR == pstSetCnf->enResult)
    {
        ulResult = AT_OK;
    }

    At_FormatResultData(ucIndex, ulResult);
    return VOS_OK;
}


VOS_UINT32 AT_SetMipiWrParaEx(VOS_UINT8 ucIndex)
{
    AT_MTA_MIPI_WREX_REQ_STRU           stMipiWrEx;
    VOS_UINT32                          ulResult;

    /* �ֲ�������ʼ�� */
    TAF_MEM_SET_S(&stMipiWrEx, (VOS_SIZE_T)sizeof(stMipiWrEx), 0x00, (VOS_SIZE_T)sizeof(AT_MTA_MIPI_WREX_REQ_STRU));

    /* ������� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        AT_WARN_LOG("AT_SetMipiWrParaEx : Current Option is not AT_CMD_OPT_SET_PARA_CMD.");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ������������ */
    if (6 != gucAtParaIndex)
    {
        AT_WARN_LOG("AT_SetMipiWrParaEx : Current Number wrong.");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* extend_flag Ϊ 0 */
    if (0 == gastAtParaList[0].ulParaValue)
    {
        /* byte_cnt �����Ϊ1 ���� reg_addr ����0-31֮��,��ֵ����0XFF,ֱ�ӷ��ش��� */
        if ((1 != gastAtParaList[4].ulParaValue)
         || (gastAtParaList[3].ulParaValue > 31)
         || (gastAtParaList[5].ulParaValue > 0xFF))
        {
            AT_WARN_LOG("AT_SetMipiWrParaEx : extend_flag is 0, byte_cnt or reg_addr or value wrong.");
            return AT_CME_INCORRECT_PARAMETERS;
        }

        stMipiWrEx.ulExtendFlag         = gastAtParaList[0].ulParaValue;
        stMipiWrEx.ulMipiId             = gastAtParaList[1].ulParaValue;
        stMipiWrEx.ulSlaveId            = gastAtParaList[2].ulParaValue;
        stMipiWrEx.ulRegAddr            = gastAtParaList[3].ulParaValue;
        stMipiWrEx.ulByteCnt            = gastAtParaList[4].ulParaValue;
        stMipiWrEx.ulValue              = gastAtParaList[5].ulParaValue;
    }
    /* extend_flag Ϊ 1 */
    else if (1 == gastAtParaList[0].ulParaValue)
    {
        /* reg_addr ����0-255֮��, ֱ�ӷ��ش��� */
        if ((1 == gastAtParaList[4].ulParaValue)
         && (gastAtParaList[5].ulParaValue > 0xFF))
        {
            AT_WARN_LOG("AT_SetMipiWrParaEx : extend_flag is 1, byte_cnt is 1, value wrong.");
            return AT_CME_INCORRECT_PARAMETERS;
        }

        if ((2 == gastAtParaList[4].ulParaValue)
         && (gastAtParaList[5].ulParaValue > 0xFFFF))
        {
            AT_WARN_LOG("AT_SetMipiWrParaEx : extend_flag is 1, byte_cnt is 2, value wrong.");
            return AT_CME_INCORRECT_PARAMETERS;
        }

        if (gastAtParaList[3].ulParaValue > 255)
        {
            AT_WARN_LOG("AT_SetMipiWrParaEx : extend_flag is 1, reg_addr wrong.");
            return AT_CME_INCORRECT_PARAMETERS;
        }

        stMipiWrEx.ulExtendFlag         = gastAtParaList[0].ulParaValue;
        stMipiWrEx.ulMipiId             = gastAtParaList[1].ulParaValue;
        stMipiWrEx.ulSlaveId            = gastAtParaList[2].ulParaValue;
        stMipiWrEx.ulRegAddr            = gastAtParaList[3].ulParaValue;
        stMipiWrEx.ulByteCnt            = gastAtParaList[4].ulParaValue;
        stMipiWrEx.ulValue              = gastAtParaList[5].ulParaValue;
    }
    else
    {
        AT_WARN_LOG("AT_SetMipiWrParaEx : extend_flag wrong.");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ������Ϣ��MTA */
    ulResult = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                      gastAtClientTab[ucIndex].opId,
                                      ID_AT_MTA_MIPI_WREX_REQ,
                                      &stMipiWrEx,
                                      (VOS_SIZE_T)sizeof(stMipiWrEx),
                                      I0_UEPS_PID_MTA);

    /* ����ʧ�� */
    if (TAF_SUCCESS != ulResult)
    {
        AT_WARN_LOG("AT_SetMipiWrParaEx: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

    /* ���ͳɹ������õ�ǰ����ģʽ */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_MIPI_WREX;
    g_stAtDevCmdCtrl.ucIndex               = ucIndex;

    /* �ȴ��첽����ʱ�䷵�� */
    return AT_WAIT_ASYNC_RETURN;
}


VOS_UINT32 AT_RcvMtaMipiWrEXCnf(VOS_VOID *pMsg)
{
    AT_MTA_MSG_STRU                    *pstRcvMsg      = VOS_NULL_PTR;
    MTA_AT_MIPI_WREX_CNF_STRU          *pstMipiWrEXCnf = VOS_NULL_PTR;
    VOS_UINT8                           ucIndex;

    /* ��ʼ���ֲ����� */
    pstRcvMsg                           = (AT_MTA_MSG_STRU *)pMsg;
    pstMipiWrEXCnf                      = (MTA_AT_MIPI_WREX_CNF_STRU *)pstRcvMsg->aucContent;
    ucIndex                             = 0;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pstRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaMiPiWrEXCnf: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaMiPiWrEXCnf: AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* �жϵ�ǰ���������Ƿ�ΪAT_CMD_MIPI_WREX */
    if (AT_CMD_MIPI_WREX != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaMiPiWrEXCnf: NOT CURRENT CMD OPTION!");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    /* ��ʽ���ϱ����� */
    if (MTA_AT_RESULT_NO_ERROR != pstMipiWrEXCnf->enResult)
    {
        /* ������ *AT_ERROR */
        gstAtSendData.usBufLen = 0;
        At_FormatResultData(ucIndex, AT_ERROR);
    }
    else
    {
        /* ������ *AT_OK */
        gstAtSendData.usBufLen = 0;
        At_FormatResultData(ucIndex, AT_OK);
    }

    return VOS_OK;
}


VOS_UINT32 AT_SetMipiRdParaEx(VOS_UINT8 ucIndex)
{
    AT_MTA_MIPI_RDEX_REQ_STRU           stMipiRdEx;
    VOS_UINT32                          ulResult;

    /* �ֲ�������ʼ�� */
    TAF_MEM_SET_S(&stMipiRdEx, (VOS_SIZE_T)sizeof(stMipiRdEx), 0x00, (VOS_SIZE_T)sizeof(AT_MTA_MIPI_RDEX_REQ_STRU));

    /* ������� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        AT_WARN_LOG("AT_SetMipiRdParaEx : Current Option is not AT_CMD_OPT_SET_PARA_CMD.");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ������������ */
    if ( (5 != gucAtParaIndex)
      && (6 != gucAtParaIndex))
    {
        AT_WARN_LOG("AT_SetMipiRdParaEx : Current Numbers Wrong.");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* extend_flag Ϊ 0 */
    if (0 == gastAtParaList[0].ulParaValue)
    {
        /* byte_cnt �����Ϊ1 ���� reg_addr ����0-31֮��, ֱ�ӷ��ش��� */
        if ((1 != gastAtParaList[4].ulParaValue)
         || (gastAtParaList[3].ulParaValue > 31))
        {
            AT_WARN_LOG("AT_SetMipiRdParaEx : extend_flag is 0, byte_cnt or reg_addr wrong.");
            return AT_CME_INCORRECT_PARAMETERS;
        }
    }
    /* extend_flag Ϊ 1 */
    else if (1 == gastAtParaList[0].ulParaValue)
    {
        /* reg_addr ����0-255֮��, ֱ�ӷ��ش��� */
        if (gastAtParaList[3].ulParaValue > 255)
        {
            AT_WARN_LOG("AT_SetMipiRdParaEx : extend_flag is 1, reg_addr wrong.");
            return AT_CME_INCORRECT_PARAMETERS;
        }
    }
    else
    {
        AT_WARN_LOG("AT_SetMipiRdParaEx : extend_flag wrong.");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    stMipiRdEx.ulExtendFlag         = gastAtParaList[0].ulParaValue;
    stMipiRdEx.ulMipiId             = gastAtParaList[1].ulParaValue;
    stMipiRdEx.ulSlaveId            = gastAtParaList[2].ulParaValue;
    stMipiRdEx.ulRegAddr            = gastAtParaList[3].ulParaValue;
    stMipiRdEx.ulByteCnt            = gastAtParaList[4].ulParaValue;
    if (6 == gucAtParaIndex)
    {
        stMipiRdEx.ulSpeedType      = gastAtParaList[5].ulParaValue;
    }
    else
    {
        /* Ϊ�˼���֮ǰ�İ汾���ò���Ĭ�Ͽ��Բ������ȫ�ٽ���READ���� */
        stMipiRdEx.ulSpeedType      = 1;
    }

    /* ������Ϣ��MTA */
    ulResult = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                      gastAtClientTab[ucIndex].opId,
                                      ID_AT_MTA_MIPI_RDEX_REQ,
                                      &stMipiRdEx,
                                      (VOS_SIZE_T)sizeof(stMipiRdEx),
                                      I0_UEPS_PID_MTA);

    /* ����ʧ�� */
    if (TAF_SUCCESS != ulResult)
    {
        AT_WARN_LOG("AT_SetMipiRdParaEx: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

    /* ���ͳɹ������õ�ǰ����ģʽ */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_MIPI_RDEX;
    g_stAtDevCmdCtrl.ucIndex               = ucIndex;

    /* �ȴ��첽����ʱ�䷵�� */
    return AT_WAIT_ASYNC_RETURN;
}


VOS_UINT32 AT_RcvMtaMipiRdEXCnf(VOS_VOID *pMsg)
{
    AT_MTA_MSG_STRU                    *pstRcvMsg      = VOS_NULL_PTR;
    MTA_AT_MIPI_RDEX_CNF_STRU          *pstMiPiRdEXCnf = VOS_NULL_PTR;
    VOS_UINT16                          ulLength;
    VOS_UINT8                           ucIndex;

    /* ��ʼ���ֲ����� */
    pstRcvMsg                           = (AT_MTA_MSG_STRU *)pMsg;
    pstMiPiRdEXCnf                      = (MTA_AT_MIPI_RDEX_CNF_STRU *)pstRcvMsg->aucContent;
    ucIndex                             = 0;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pstRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaMiPiRdEXCnf: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaMiPiRdEXCnf: AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* �жϵ�ǰ���������Ƿ�ΪAT_CMD_MIPI_WREX */
    if (AT_CMD_MIPI_RDEX != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaMiPiRdEXCnf: NOT CURRENT CMD OPTION!");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    /* ��ʽ���ϱ����� */
    if (MTA_AT_RESULT_NO_ERROR != pstMiPiRdEXCnf->enResult)
    {
        /* ������ *AT_ERROR */
        gstAtSendData.usBufLen = 0;
        At_FormatResultData(ucIndex, AT_ERROR);
    }
    else
    {
        /* ������ *AT_OK */
        ulLength = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                          (VOS_CHAR *)pgucAtSndCodeAddr,
                                          (VOS_CHAR *)pgucAtSndCodeAddr,
                                          "%s:%d",
                                          g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                          pstMiPiRdEXCnf->ulValue);
        gstAtSendData.usBufLen = ulLength;
        At_FormatResultData(ucIndex, AT_OK);
    }

    return VOS_OK;
}


VOS_UINT32 AT_SetCrrconnPara(VOS_UINT8 ucIndex)
{
    AT_MTA_SET_CRRCONN_REQ_STRU         stSetCrrconn;
    VOS_UINT32                          ulRst;

    TAF_MEM_SET_S(&stSetCrrconn, sizeof(stSetCrrconn), 0x00, sizeof(AT_MTA_SET_CRRCONN_REQ_STRU));

    /* ������� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ������������ȷ */
    if (1 != gucAtParaIndex)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ����Ϊ�� */
    if (0 == gastAtParaList[0].usParaLen)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ������ֵ */
    stSetCrrconn.enEnable = (AT_MTA_CFG_ENUM_UINT8)gastAtParaList[0].ulParaValue;

    /* ���Ϳ����Ϣ��C�ˣ�����CRRCONN�����ϱ����� */
    ulRst = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                   gastAtClientTab[ucIndex].opId,
                                   ID_AT_MTA_CRRCONN_SET_REQ,
                                   &stSetCrrconn,
                                   sizeof(stSetCrrconn),
                                   I0_UEPS_PID_MTA);
    if (TAF_SUCCESS != ulRst)
    {
        AT_WARN_LOG("AT_SetCrrconnPara: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_CRRCONN_SET;

    return AT_WAIT_ASYNC_RETURN;
}


VOS_UINT32 AT_QryCrrconnPara(VOS_UINT8 ucIndex)
{
    VOS_UINT32                          ulResult;

    if(AT_CMD_OPT_READ_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_ERROR;
    }

    /* AT ��MTA ���Ͳ�ѯ������Ϣ */
    ulResult = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                      gastAtClientTab[ucIndex].opId,
                                      ID_AT_MTA_CRRCONN_QRY_REQ,
                                      VOS_NULL_PTR,
                                      0,
                                      I0_UEPS_PID_MTA);

    if (TAF_SUCCESS != ulResult)
    {
        AT_WARN_LOG("AT_QryCrrconnPara: send Msg fail.");
        return AT_ERROR;
    }

    /* ���õ�ǰ�������� */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_CRRCONN_QRY;

    return AT_WAIT_ASYNC_RETURN;
}


VOS_UINT32 AT_RcvMtaSetCrrconnCnf(
    VOS_VOID                        *pMsg
)
{
    AT_MTA_MSG_STRU                    *pstRcvMsg;
    MTA_AT_SET_CRRCONN_CNF_STRU        *pstSetCnf;
    VOS_UINT32                          ulResult;
    VOS_UINT8                           ucIndex;

    /* ��ʼ�� */
    pstRcvMsg    = (AT_MTA_MSG_STRU *)pMsg;
    pstSetCnf    = (MTA_AT_SET_CRRCONN_CNF_STRU *)pstRcvMsg->aucContent;
    ucIndex      = 0;
    ulResult     = AT_ERROR;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pstRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaSetCrrconnCnf : WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaSetCrrconnCnf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_CRRCONN_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaSetCrrconnCnf : Current Option is not AT_CMD_CRRCONN_SET.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    /* ��ʽ������� */
    gstAtSendData.usBufLen = 0;

    if (MTA_AT_RESULT_NO_ERROR == pstSetCnf->enResult)
    {
        ulResult = AT_OK;
    }

    At_FormatResultData(ucIndex, ulResult);
    return VOS_OK;
}


VOS_UINT32 AT_RcvMtaQryCrrconnCnf(
    VOS_VOID                        *pMsg
)
{
    /* ����ֲ����� */
    AT_MTA_MSG_STRU                  *pstMtaMsg         = VOS_NULL_PTR;
    MTA_AT_QRY_CRRCONN_CNF_STRU      *pstQryCrrconnCnf  = VOS_NULL_PTR;
    VOS_UINT32                        ulResult;
    VOS_UINT8                         ucIndex;

    /* ��ʼ����Ϣ���� */
    pstMtaMsg           = (AT_MTA_MSG_STRU*)pMsg;
    pstQryCrrconnCnf    = (MTA_AT_QRY_CRRCONN_CNF_STRU*)pstMtaMsg->aucContent;

    /* ͨ��ClientId��ȡucIndex */
    if (AT_FAILURE == At_ClientIdToUserId(pstMtaMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaQryCrrconnCnf: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaQryCrrconnCnf: WARNING:AT_BROADCAST_INDEX!");
        return VOS_ERR;
    }

    /* �жϵ�ǰ���������Ƿ�ΪAT_CMD_CRRCONN_QRY */
    if (AT_CMD_CRRCONN_QRY != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaQryCrrconnCnf: WARNING:Not AT_CMD_CRRCONN_QRY!");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    /* �жϲ�ѯ�����Ƿ�ɹ� */
    if (MTA_AT_RESULT_NO_ERROR == pstQryCrrconnCnf->enResult)
    {
        ulResult                = AT_OK;
        gstAtSendData.usBufLen  = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                            (VOS_CHAR*)pgucAtSndCodeAddr,
                                            (VOS_CHAR*)pgucAtSndCodeAddr,
                                            "%s: %d,%d,%d,%d",
                                            g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                            pstQryCrrconnCnf->enEnable,
                                            pstQryCrrconnCnf->ucStatus0,
                                            pstQryCrrconnCnf->ucStatus1,
                                            pstQryCrrconnCnf->ucStatus2);
    }
    else
    {
        ulResult                = AT_ERROR;
        gstAtSendData.usBufLen  = 0;
    }

    /* ����AT_FormatResultData���������� */
    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}


VOS_UINT32 AT_RcvMtaCrrconnStatusInd(
    VOS_VOID                           *pMsg
)
{
    AT_MTA_MSG_STRU                    *pstMtaMsg           = VOS_NULL_PTR;
    MTA_AT_CRRCONN_STATUS_IND_STRU     *pstCrrconnStatusInd = VOS_NULL_PTR;
    VOS_UINT8                           ucIndex;

    /* ��ʼ����Ϣ���� */
    ucIndex                = 0;
    pstMtaMsg              = (AT_MTA_MSG_STRU *)pMsg;
    pstCrrconnStatusInd    = (MTA_AT_CRRCONN_STATUS_IND_STRU *)pstMtaMsg->aucContent;

    /* ͨ��ClientId��ȡucIndex */
    if (AT_FAILURE == At_ClientIdToUserId(pstMtaMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaCrrconnStatusInd: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    gstAtSendData.usBufLen  = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                            (VOS_CHAR*)pgucAtSndCodeAddr,
                                            (VOS_CHAR*)pgucAtSndCodeAddr,
                                            "%s^CRRCONN: %d,%d,%d%s",
                                            gaucAtCrLf,
                                            pstCrrconnStatusInd->ucStatus0,
                                            pstCrrconnStatusInd->ucStatus1,
                                            pstCrrconnStatusInd->ucStatus2,
                                            gaucAtCrLf);

    At_SendResultData(ucIndex, pgucAtSndCodeAddr, gstAtSendData.usBufLen);

    return VOS_OK;
}


VOS_UINT32 AT_SetVtrlqualrptPara(VOS_UINT8 ucIndex)
{
    AT_MTA_SET_VTRLQUALRPT_REQ_STRU     stSetVtrlqualrpt;
    VOS_UINT32                          ulRst;

    TAF_MEM_SET_S(&stSetVtrlqualrpt, sizeof(stSetVtrlqualrpt), 0x00, sizeof(AT_MTA_SET_VTRLQUALRPT_REQ_STRU));

    /* ������� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ������������ȷ */
    if (2 != gucAtParaIndex)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ����Ϊ�� */
    if ((0 == gastAtParaList[0].usParaLen)
     || (0 == gastAtParaList[1].usParaLen))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ������ֵ */
    stSetVtrlqualrpt.ulEnable       = gastAtParaList[0].ulParaValue;
    stSetVtrlqualrpt.ulThreshold    = gastAtParaList[1].ulParaValue;

    /* ���Ϳ����Ϣ��C�� */
    ulRst = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                   gastAtClientTab[ucIndex].opId,
                                   ID_AT_MTA_VTRLQUALRPT_SET_REQ,
                                   &stSetVtrlqualrpt,
                                   (VOS_SIZE_T)sizeof(stSetVtrlqualrpt),
                                   I0_UEPS_PID_MTA);
    if (TAF_SUCCESS != ulRst)
    {
        AT_WARN_LOG("AT_SetVtrlqualrptPara: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_VTRLQUALRPT_SET;

    return AT_WAIT_ASYNC_RETURN;
}


VOS_UINT32 AT_RcvMtaSetVtrlqualrptCnf(
    VOS_VOID                        *pMsg
)
{
    AT_MTA_MSG_STRU                    *pstRcvMsg;
    MTA_AT_SET_VTRLQUALRPT_CNF_STRU    *pstSetCnf;
    VOS_UINT32                          ulResult;
    VOS_UINT8                           ucIndex;

    /* ��ʼ�� */
    pstRcvMsg    = (AT_MTA_MSG_STRU *)pMsg;
    pstSetCnf    = (MTA_AT_SET_VTRLQUALRPT_CNF_STRU *)pstRcvMsg->aucContent;
    ucIndex      = 0;
    ulResult     = AT_ERROR;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pstRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaSetVtrlqualrptCnf : WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaSetVtrlqualrptCnf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_VTRLQUALRPT_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaSetVtrlqualrptCnf : Current Option is not AT_CMD_VTRLQUALRPT_SET.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    /* ��ʽ������� */
    gstAtSendData.usBufLen = 0;

    if (MTA_AT_RESULT_NO_ERROR == pstSetCnf->enResult)
    {
        ulResult = AT_OK;
    }

    At_FormatResultData(ucIndex, ulResult);
    return VOS_OK;
}


VOS_UINT32 AT_RcvMtaRlQualityInfoInd(
    VOS_VOID                           *pMsg
)
{
    AT_MTA_MSG_STRU                    *pstMtaMsg           = VOS_NULL_PTR;
    MTA_AT_RL_QUALITY_INFO_IND_STRU    *pstRlQualityInfoInd = VOS_NULL_PTR;
    VOS_UINT8                           ucIndex;

    /* ��ʼ����Ϣ���� */
    ucIndex                = 0;
    pstMtaMsg              = (AT_MTA_MSG_STRU *)pMsg;
    pstRlQualityInfoInd    = (MTA_AT_RL_QUALITY_INFO_IND_STRU *)pstMtaMsg->aucContent;

    /* ͨ��ClientId��ȡucIndex */
    if (AT_FAILURE == At_ClientIdToUserId(pstMtaMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaRlQualityInfoInd: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    gstAtSendData.usBufLen  = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                            (VOS_CHAR*)pgucAtSndCodeAddr,
                                            (VOS_CHAR*)pgucAtSndCodeAddr,
                                            "%s^LTERLQUALINFO: %d,%d,%d,%d%s",
                                            gaucAtCrLf,
                                            pstRlQualityInfoInd->sRsrp,
                                            pstRlQualityInfoInd->sRsrq,
                                            pstRlQualityInfoInd->sRssi,
                                            pstRlQualityInfoInd->usBler,
                                            gaucAtCrLf);

    At_SendResultData(ucIndex, pgucAtSndCodeAddr, gstAtSendData.usBufLen);

    return VOS_OK;
}


VOS_UINT32 AT_RcvMtaVideoDiagInfoRpt(
    VOS_VOID                           *pMsg
)
{
    AT_MTA_MSG_STRU                    *pstMtaMsg           = VOS_NULL_PTR;
    MTA_AT_VIDEO_DIAG_INFO_RPT_STRU    *pstVideoDiagInfoRpt = VOS_NULL_PTR;
    VOS_UINT8                           ucIndex;

    /* ��ʼ����Ϣ���� */
    ucIndex                = 0;
    pstMtaMsg              = (AT_MTA_MSG_STRU *)pMsg;
    pstVideoDiagInfoRpt    = (MTA_AT_VIDEO_DIAG_INFO_RPT_STRU *)pstMtaMsg->aucContent;

    /* ͨ��ClientId��ȡucIndex */
    if (AT_FAILURE == At_ClientIdToUserId(pstMtaMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaVideoDiagInfoRpt: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    gstAtSendData.usBufLen  = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                            (VOS_CHAR*)pgucAtSndCodeAddr,
                                            (VOS_CHAR*)pgucAtSndCodeAddr,
                                            "%s^LPDCPINFORPT: %u,%u,%u,%u%s",
                                            gaucAtCrLf,
                                            pstVideoDiagInfoRpt->ulCurrBuffTime,
                                            pstVideoDiagInfoRpt->ulCurrBuffPktNum,
                                            pstVideoDiagInfoRpt->ulMacUlThrput,
                                            pstVideoDiagInfoRpt->ulMaxBuffTime,
                                            gaucAtCrLf);

    At_SendResultData(ucIndex, pgucAtSndCodeAddr, gstAtSendData.usBufLen);

    return VOS_OK;
}



VOS_UINT32 AT_SetEccCfgPara(VOS_UINT8 ucIndex)
{
    AT_MTA_SET_ECC_CFG_REQ_STRU         stSetEccCfgReq;
    VOS_UINT32                          ulResult;

    /* �ֲ�������ʼ�� */
    TAF_MEM_SET_S(&stSetEccCfgReq, sizeof(stSetEccCfgReq), 0x00, sizeof(stSetEccCfgReq));

    /* ������Ч�Լ�� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        AT_WARN_LOG("AT_CheckErrcCapCfgPara: At Cmd Opt Set Para Error.");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ��������ӦΪ2�������򷵻�AT_CME_INCORRECT_PARAMETERS */
    if (2 != gucAtParaIndex)
    {
        AT_WARN_LOG("AT_CheckErrcCapCfgPara: At Para Num Error.");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ��1���������Ȳ�Ϊ0�����򷵻�AT_CME_INCORR ECT_PARAMETERS */
    if ((0 == gastAtParaList[0].usParaLen)
     || (0 == gastAtParaList[1].usParaLen))
    {
        AT_WARN_LOG("AT_CheckErrcCapCfgPara: Length = 0");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ���ṹ�� */
    stSetEccCfgReq.ulEccEnable = (PS_BOOL_ENUM_UINT8)gastAtParaList[0].ulParaValue;
    stSetEccCfgReq.ulRptPeriod = gastAtParaList[1].ulParaValue;

    ulResult = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                      gastAtClientTab[ucIndex].opId,
                                      ID_AT_MTA_ECC_CFG_SET_REQ,
                                      (VOS_VOID*)&stSetEccCfgReq,
                                      sizeof(AT_MTA_SET_ECC_CFG_REQ_STRU),
                                      I0_UEPS_PID_MTA);

    if (TAF_SUCCESS == ulResult)
    {
        gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_ECCCFG_SET;
        return AT_WAIT_ASYNC_RETURN;
    }

    return AT_ERROR;
}


VOS_UINT32 AT_ProcCclkTimeParaYMDAuxMode(
    VOS_UINT8                           ucYearLen,
    VOS_INT32                          *plYear,
    VOS_INT32                          *plMonth,
    VOS_INT32                          *plDay
)
{
    VOS_UINT8                           aucBuffer[AT_GET_MODEM_TIME_BUFF_LEN];

    /* ���ո�ʽ "(yy/yyyy)/mm/dd,hh:mm:ss(+/-)zz"�����жϷ�Χ */

    /* ���(yy/yyyy) */
    TAF_MEM_SET_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), 0x00, (VOS_SIZE_T)sizeof(aucBuffer));
    TAF_MEM_CPY_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), gastAtParaList[0].aucPara, ucYearLen);

    if (VOS_ERR == AT_AtoInt(aucBuffer, plYear))
    {
        AT_ERR_LOG("AT_ProcCclkTimeParaYMDAuxMode: The parameter of year is err");
        return VOS_ERR;
    }

    if (AT_MODEM_DEFALUT_AUX_MODE_YEAR_LEN == ucYearLen)
    {
        if ((*plYear > AT_MODEM_DEFALUT_AUX_MODE_YEAR_MAX)
         || (*plYear < AT_MODEM_DEFALUT_AUX_MODE_YEAR_MIN))
        {
            AT_ERR_LOG("AT_ProcCclkTimeParaYMDAuxMode: The parameter of year is out of range");
            return VOS_ERR;
        }
    }
    else
    {
        if ((*plYear > AT_MODEM_YEAR_MAX)
         || (*plYear < AT_MODEM_YEAR_MIN))
        {
            AT_ERR_LOG("AT_ProcCclkTimeParaYMDAuxMode: The parameter of year is out of range");
            return VOS_ERR;
        }
    }

    /* ���mm */
    TAF_MEM_SET_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), 0x00, (VOS_SIZE_T)sizeof(aucBuffer));
    TAF_MEM_CPY_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), &gastAtParaList[0].aucPara[ucYearLen + 1], AT_MODEM_MONTH_LEN);

    if (VOS_ERR == AT_AtoInt(aucBuffer, plMonth))
    {
        AT_ERR_LOG("AT_ProcCclkTimeParaYMDAuxMode: The parameter of month is err");
        return VOS_ERR;
    }

    if ((*plMonth > AT_MODEM_MONTH_MAX)
     || (*plMonth < AT_MODEM_MONTH_MIN))
    {
        AT_ERR_LOG("AT_ProcCclkTimeParaYMDAuxMode: The parameter of month is out of range");
        return VOS_ERR;
    }

    /* ���dd */
    TAF_MEM_SET_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), 0x00, (VOS_SIZE_T)sizeof(aucBuffer));
    TAF_MEM_CPY_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), &gastAtParaList[0].aucPara[ucYearLen + 4], AT_MODEM_DATE_LEN);

    if (VOS_ERR == AT_AtoInt(aucBuffer, plDay))
    {
        AT_ERR_LOG("AT_ProcCclkTimeParaYMDAuxMode: The parameter of day is err");
        return VOS_ERR;
    }

    if ((*plDay > AT_MODEM_DAY_MAX)
     || (*plDay < AT_MODEM_DAY_MIN))
    {
        AT_ERR_LOG("AT_ProcCclkTimeParaYMDAuxMode: The parameter of day is out of range");
        return VOS_ERR;
    }

    return VOS_OK;
}


VOS_UINT32 AT_ProcCclkTimeParaHMSAuxMode(
    VOS_UINT8                           ucYearLen,
    VOS_INT32                          *plHour,
    VOS_INT32                          *plMin,
    VOS_INT32                          *plSec
)
{
    VOS_UINT8                           aucBuffer[AT_GET_MODEM_TIME_BUFF_LEN];

    /* ���ո�ʽ "(yy/yyyy)/mm/dd,hh:mm:ss(+/-)zz"�����жϷ�Χ */

    /* ���hh */
    TAF_MEM_SET_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), 0x00, (VOS_SIZE_T)sizeof(aucBuffer));
    TAF_MEM_CPY_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), &gastAtParaList[0].aucPara[ucYearLen + 7], AT_MODEM_HOUR_LEN);

    if (VOS_ERR == AT_AtoInt(aucBuffer, plHour))
    {
        AT_ERR_LOG("AT_ProcCclkTimeParaHMSAuxMode: The parameter of hour is err");
        return VOS_ERR;
    }

    if ((*plHour > AT_MODEM_HOUR_MAX)
     || (*plHour < AT_MODEM_HOUR_MIN))
    {
        AT_ERR_LOG("AT_ProcCclkTimeParaHMSAuxMode: The parameter of hour is out of range");
        return VOS_ERR;
    }

    /* ���mm */
    TAF_MEM_SET_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), 0x00, (VOS_SIZE_T)sizeof(aucBuffer));
    TAF_MEM_CPY_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), &gastAtParaList[0].aucPara[ucYearLen + 10], AT_MODEM_MIN_LEN);

    if (VOS_ERR == AT_AtoInt(aucBuffer, plMin))
    {
        AT_ERR_LOG("AT_ProcCclkTimeParaHMSAuxMode: The parameter of min is err");
        return VOS_ERR;
    }

    if ((*plMin > AT_MODEM_MIN_MAX)
     || (*plMin < AT_MODEM_MIN_MIN))
    {
        AT_ERR_LOG("AT_ProcCclkTimeParaHMSAuxMode: The parameter of min is out of range");
        return VOS_ERR;
    }

    /* ���ss */
    TAF_MEM_SET_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), 0x00, (VOS_SIZE_T)sizeof(aucBuffer));
    TAF_MEM_CPY_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), &gastAtParaList[0].aucPara[ucYearLen + 13], AT_MODEM_SEC_LEN);

    if (VOS_ERR == AT_AtoInt(aucBuffer, plSec))
    {
        AT_ERR_LOG("AT_ProcCclkTimeParaHMSAuxMode: The parameter of sec is err");
        return VOS_ERR;
    }

    if ((*plSec > AT_MODEM_SEC_MAX)
     || (*plSec < AT_MODEM_SEC_MIN))
    {
        AT_ERR_LOG("AT_ProcCclkTimeParaHMSAuxMode: The parameter of sec is out of range");
        return VOS_ERR;
    }

    return VOS_OK;
}


VOS_UINT32 AT_ProcCclkTimeParaZoneAuxMode(
    VOS_UINT8                           ucYearLen,
    VOS_INT32                          *plZone
)
{
    VOS_UINT8                           aucBuffer[AT_GET_MODEM_TIME_BUFF_LEN];

    /* ���ո�ʽ "(yy/yyyy)/mm/dd,hh:mm:ss(+/-)zz"�����жϷ�Χ */

    /* ���(+/-)zz */
    TAF_MEM_SET_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), 0x00, (VOS_SIZE_T)sizeof(aucBuffer));

    if (gastAtParaList[0].aucPara[ucYearLen + 15] == '-')
    {
        TAF_MEM_CPY_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), &gastAtParaList[0].aucPara[ucYearLen + 15], AT_MODEM_ZONE_LEN);
    }
    else
    {
        TAF_MEM_CPY_S(aucBuffer, (VOS_SIZE_T)sizeof(aucBuffer), &gastAtParaList[0].aucPara[ucYearLen + 16], AT_MODEM_ZONE_LEN - 1);
    }

    if (VOS_ERR == AT_AtoInt(aucBuffer, plZone))
    {
        AT_ERR_LOG("AT_ProcCclkTimeParaZoneAuxMode: The parameter of zone is err");
        return VOS_ERR;
    }

    if ((*plZone > AT_MODEM_TIME_ZONE_MAX)
     || (*plZone < AT_MODEM_TIME_ZONE_MIN))
    {
        AT_ERR_LOG("AT_ProcCclkTimeParaZoneAuxMode: The parameter of zone is out of range");
        return VOS_ERR;
    }

    return VOS_OK;
}



VOS_UINT32 AT_ProcCclkTimeParaAuxMode(
    VOS_UINT8                       ucIndex,
    VOS_UINT8                       ucYearLen
)
{
    VOS_INT32                           lSec;
    VOS_INT32                           lMin;
    VOS_INT32                           lHour;
    VOS_INT32                           lDay;
    VOS_INT32                           lMonth;
    VOS_INT32                           lYear;
    VOS_INT32                           lZone;
    AT_MODEM_NET_CTX_STRU              *pstNetCtx = VOS_NULL_PTR;

    lSec    = 0;
    lMin    = 0;
    lHour   = 0;
    lDay    = 0;
    lMonth  = 0;
    lYear   = 0;
    lZone   = 0;

    /* ���ո�ʽ "(yy/yyyy)/mm/dd,hh:mm:ss(+/-)zz"�����жϷ�Χ */

    /* ���(yy/yyyy)/mm/dd */
    if (VOS_ERR == AT_ProcCclkTimeParaYMDAuxMode(ucYearLen, &lYear, &lMonth, &lDay))
    {
        return VOS_ERR;
    }

    /* ���hh:mm:ss */
    if (VOS_ERR == AT_ProcCclkTimeParaHMSAuxMode(ucYearLen, &lHour, &lMin, &lSec))
    {
        return VOS_ERR;
    }

    /* ���(+/-)zz */
    if (VOS_ERR == AT_ProcCclkTimeParaZoneAuxMode(ucYearLen, &lZone))
    {
        return VOS_ERR;
    }

    pstNetCtx = AT_GetModemNetCtxAddrFromClientId(ucIndex);

    if (AT_MODEM_DEFALUT_AUX_MODE_YEAR_LEN == ucYearLen)
    {
        pstNetCtx->stTimeInfo.stUniversalTimeandLocalTimeZone.ucYear = (VOS_UINT8)lYear;
    }
    else
    {
        pstNetCtx->stTimeInfo.stUniversalTimeandLocalTimeZone.ucYear = (VOS_UINT8)(lYear % 100);
    }

    pstNetCtx->stTimeInfo.stUniversalTimeandLocalTimeZone.ucMonth   = (VOS_UINT8)lMonth;
    pstNetCtx->stTimeInfo.stUniversalTimeandLocalTimeZone.ucDay     = (VOS_UINT8)lDay;
    pstNetCtx->stTimeInfo.stUniversalTimeandLocalTimeZone.ucHour    = (VOS_UINT8)lHour;
    pstNetCtx->stTimeInfo.stUniversalTimeandLocalTimeZone.ucMinute  = (VOS_UINT8)lMin;
    pstNetCtx->stTimeInfo.stUniversalTimeandLocalTimeZone.ucSecond  = (VOS_UINT8)lSec;
    pstNetCtx->stTimeInfo.stUniversalTimeandLocalTimeZone.cTimeZone = (VOS_INT8)lZone;
    pstNetCtx->stTimeInfo.cLocalTimeZone                            = (VOS_INT8)lZone;

    pstNetCtx->stTimeInfo.ucIeFlg = pstNetCtx->stTimeInfo.ucIeFlg | NAS_MM_INFO_IE_UTLTZ;

    return VOS_OK;
}



VOS_UINT32 AT_SetCclkPara(VOS_UINT8 ucIndex)
{
    AT_MODEM_NET_CTX_STRU                  *pstNetCtx = VOS_NULL_PTR;
    VOS_UINT8                               ucYearLen;

    /* ������� */
    if ( AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType )
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ������Ŀ��� */
    if (gucAtParaIndex != 1)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    pstNetCtx = AT_GetModemNetCtxAddrFromClientId(ucIndex);

    if (1 == pstNetCtx->stCsdfCfg.ucAuxMode)
    {
        /* "yy/mm/dd,hh:mm:ss(+/-)zz" */
        ucYearLen = AT_MODEM_DEFALUT_AUX_MODE_YEAR_LEN;
    }
    else
    {
        /* "yyyy/mm/dd,hh:mm:ss(+/-)zz" */
        ucYearLen = AT_MODEM_OTHER_AUX_MODE_YEAR_LEN;
    }

    /* �������Ȳ���ȷ */
    if ((AT_MODEM_AUX_MODE_EXCEPT_YEAR_TIME_LEN + ucYearLen) != gastAtParaList[0].usParaLen)
    {
       AT_ERR_LOG("AT_SetCclkPara: length of parameter is error.");
       return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ���ո�ʽ "(yy/yyyy)/mm/dd,hh:mm:ss(+/-)zz"�����жϸ�ʽ */
    if ( (gastAtParaList[0].aucPara[ucYearLen] != '/')
      || (gastAtParaList[0].aucPara[ucYearLen + 3] != '/')
      || (gastAtParaList[0].aucPara[ucYearLen + 6] != ',')
      || (gastAtParaList[0].aucPara[ucYearLen + 9] != ':')
      || (gastAtParaList[0].aucPara[ucYearLen + 12] != ':')
      || ( (gastAtParaList[0].aucPara[ucYearLen + 15] != '+')
        && (gastAtParaList[0].aucPara[ucYearLen + 15] != '-')))
    {
        AT_ERR_LOG("AT_SetCclkPara: The date formats parameter is error.");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    if (VOS_ERR == AT_ProcCclkTimeParaAuxMode(ucIndex, ucYearLen))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    return AT_OK;
}


VOS_UINT32 AT_SetDsdsStatePara(
    VOS_UINT8                           ucIndex
)
{
    MODEM_ID_ENUM_UINT16                enModemId;

    enModemId = MODEM_ID_0;

    if (VOS_OK != AT_GetModemIdFromClient(ucIndex, &enModemId))
    {
        AT_ERR_LOG("AT_SetDsdsStatePara: Get modem id fail.");
        return AT_ERROR;
    }

    if (MODEM_ID_0 != enModemId)
    {
        return AT_ERROR;
    }

    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    if (1 != gucAtParaIndex)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    if (0 == gastAtParaList[0].usParaLen)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    if (VOS_TRUE == TAF_MMA_SetDsdsStateReq(WUEPS_PID_AT,
                            gastAtClientTab[ucIndex].usClientId,
                            gastAtParaList[0].ulParaValue))
    {
        /* ���õ�ǰ�������� */
        gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_DSDS_STATE_SET;
        return AT_WAIT_ASYNC_RETURN;    /* ������������״̬ */
    }
    else
    {
        return AT_ERROR;
    }
}


VOS_UINT32 AT_RcvMmaDsdsStateSetCnf(
    VOS_VOID                           *pstMsg
)
{
    TAF_MMA_DSDS_STATE_SET_CNF_STRU    *pstDsdsStateSetCnf = VOS_NULL_PTR;
    VOS_UINT8                           ucIndex = 0;
    VOS_UINT32                          ulResult;

    pstDsdsStateSetCnf = (TAF_MMA_DSDS_STATE_SET_CNF_STRU *)pstMsg;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pstDsdsStateSetCnf->stCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMmaDsdsStateSetCnf : WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMmaDsdsStateSetCnf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_DSDS_STATE_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMmaDsdsStateSetCnf : Current Option is not AT_CMD_CIND_SET.");
        return VOS_ERR;
    }

    AT_STOP_TIMER_CMD_READY(ucIndex);

    if (VOS_TRUE == pstDsdsStateSetCnf->ulRslt)
    {
        ulResult = AT_OK;
    }
    else
    {
        ulResult = AT_ERROR;
    }

    gstAtSendData.usBufLen = 0;

    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}


VOS_UINT32 AT_RcvMmaDsdsStateNotify(
    VOS_VOID                           *pstMsg
)
{
    TAF_MMA_DSDS_STATE_NOTIFY_STRU     *pstDsdsStateNotify;
    MODEM_ID_ENUM_UINT16                enModemId;
    VOS_UINT8                           ucIndex;
    VOS_UINT16                          usLength;

    /* ��ʼ����Ϣ���� */
    ucIndex             = 0;
    usLength            = 0;
    pstDsdsStateNotify  = (TAF_MMA_DSDS_STATE_NOTIFY_STRU *)pstMsg;

    /* ͨ��ClientId��ȡucIndex */
    if ( AT_FAILURE == At_ClientIdToUserId(pstDsdsStateNotify->usClientId, &ucIndex) )
    {
        AT_WARN_LOG("AT_RcvMmaDsdsStateNotify: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (VOS_OK != AT_GetModemIdFromClient(ucIndex, &enModemId))
    {
        AT_ERR_LOG("AT_RcvMmaDsdsStateNotify: Get modem id fail.");
        return VOS_ERR;
    }

    usLength += (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                       (TAF_CHAR *)pgucAtSndCodeAddr,
                                       (TAF_CHAR *)pgucAtSndCodeAddr + usLength,
                                       "%s%s%d%s",
                                       gaucAtCrLf,
                                       gastAtStringTab[AT_STRING_DSDSSTATE].pucText,
                                       pstDsdsStateNotify->ucSupportDsds3,
                                       gaucAtCrLf);

    gstAtSendData.usBufLen = usLength;

    At_SendResultData(ucIndex, pgucAtSndCodeAddr, usLength);

    return VOS_OK;
}


VOS_UINT32 AT_SetGameModePara(
    VOS_UINT8                           ucIndex
)
{
    MODEM_ID_ENUM_UINT16                enModemId;
    AT_MTA_COMM_GAME_MODE_SET_REQ_STRU  stAtCmd;

    enModemId = MODEM_ID_0;

    if (VOS_OK != AT_GetModemIdFromClient(ucIndex, &enModemId))
    {
        AT_ERR_LOG("AT_SetGameModePara: Get modem id fail.");
        return AT_ERROR;
    }

    if (MODEM_ID_0 != enModemId)
    {
        AT_ERR_LOG("enModemId isn't MODEM 0");
        return AT_ERROR;
    }

    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    if (1 != gucAtParaIndex)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    if (0 == gastAtParaList[0].usParaLen)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    TAF_MEM_SET_S(&stAtCmd, sizeof(stAtCmd), 0x00, sizeof(stAtCmd));
    stAtCmd.ucGameMode = gastAtParaList[0].ulParaValue;

    if (TAF_SUCCESS == AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                           0,
                           ID_AT_MTA_GAME_MODE_SET_REQ,
                           &stAtCmd,
                           sizeof(AT_MTA_COMM_GAME_MODE_SET_REQ_STRU),
                           I0_UEPS_PID_MTA))
    {
        /* ���õ�ǰ�������� */
        gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_GAME_MODE_SET;
        return AT_WAIT_ASYNC_RETURN;    /* ������������״̬ */
    }
    else
    {
        return AT_ERROR;
    }
}



VOS_UINT32 AT_SetSmsDomainPara(VOS_UINT8 ucIndex)
{
    AT_MTA_SMS_DOMAIN_SET_REQ_STRU  stSmsDomain;
    VOS_UINT32                      ulRst;

    TAF_MEM_SET_S(&stSmsDomain, sizeof(stSmsDomain), 0x00, sizeof(AT_MTA_SMS_DOMAIN_SET_REQ_STRU));

    /* ������� */
    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* �������������ȼ�� */
    if ( (1 != gucAtParaIndex)
      || (0 == gastAtParaList[0].usParaLen))
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    stSmsDomain.enSmsDomain = (AT_MTA_SMS_DOMAIN_ENUM_UINT8)gastAtParaList[0].ulParaValue;

    /* ���Ϳ����Ϣ��C�� */
    ulRst = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                   gastAtClientTab[ucIndex].opId,
                                   ID_AT_MTA_SMS_DOMAIN_SET_REQ,
                                   &stSmsDomain,
                                   sizeof(stSmsDomain),
                                   I0_UEPS_PID_MTA);

    if (TAF_SUCCESS != ulRst)
    {
        AT_WARN_LOG("AT_SetSmsDomainPara: AT_FillAndSndAppReqMsg fail.");
        return AT_ERROR;
    }

    /* ����ATģ��ʵ���״̬Ϊ�ȴ��첽���� */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_SMSDOMAIN_SET;

    return AT_WAIT_ASYNC_RETURN;
}


VOS_UINT32 AT_RcvMtaSmsDomainSetCnf(
    VOS_VOID                           *pMsg
)
{
    AT_MTA_MSG_STRU                                *pRcvMsg         = VOS_NULL_PTR;
    MTA_AT_SMS_DOMAIN_SET_CNF_STRU                 *pstMtaCnf       = VOS_NULL_PTR;
    VOS_UINT32                                      ulResult;
    VOS_UINT8                                       ucIndex;

    /* ��ʼ�� */
    pRcvMsg             = (AT_MTA_MSG_STRU *)pMsg;
    pstMtaCnf           = (MTA_AT_SMS_DOMAIN_SET_CNF_STRU *)pRcvMsg->aucContent;
    ulResult            = AT_OK;
    ucIndex             = 0;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaSmsDomainSetCnf : WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaSmsDomainSetCnf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_SMSDOMAIN_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaSmsDomainSetCnf : Current Option is not AT_CMD_SMSDOMAIN_SET.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    gstAtSendData.usBufLen = 0;

    if (VOS_OK != pstMtaCnf->enResult)
    {
        ulResult = AT_ERROR;
    }
    else
    {
        ulResult = AT_OK;
    }

    /* ������ */
    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}


VOS_UINT32 AT_QrySmsDomainPara(VOS_UINT8 ucIndex)
{
    VOS_UINT32                          ulResult;

    if(AT_CMD_OPT_READ_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_ERROR;
    }

    /* AT ��MTA ���Ͳ�ѯ������Ϣ */
    ulResult = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                      gastAtClientTab[ucIndex].opId,
                                      ID_AT_MTA_SMS_DOMAIN_QRY_REQ,
                                      VOS_NULL_PTR,
                                      0,
                                      I0_UEPS_PID_MTA);

    if (TAF_SUCCESS != ulResult)
    {
        AT_WARN_LOG("AT_SetSmsDomainPara: AT_QrySmsDomainPara fail.");
        return AT_ERROR;
    }

    /* ����ATģ��ʵ���״̬Ϊ�ȴ��첽���� */
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_SMSDOMAIN_QRY;

    return AT_WAIT_ASYNC_RETURN;
}


VOS_UINT32 AT_RcvMtaSmsDomainQryCnf(
    VOS_VOID                        *pMsg
)
{
    /* ����ֲ����� */
    AT_MTA_MSG_STRU                  *pstMtaMsg         = VOS_NULL_PTR;
    MTA_AT_SMS_DOMAIN_QRY_CNF_STRU   *pstQryCnf         = VOS_NULL_PTR;
    VOS_UINT32                        ulResult;
    VOS_UINT8                         ucIndex;

    /* ��ʼ����Ϣ���� */
    pstMtaMsg           = (AT_MTA_MSG_STRU*)pMsg;
    pstQryCnf           = (MTA_AT_SMS_DOMAIN_QRY_CNF_STRU*)pstMtaMsg->aucContent;

    /* ͨ��ClientId��ȡucIndex */
    if (AT_FAILURE == At_ClientIdToUserId(pstMtaMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaSmsDomainQryCnf: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaSmsDomainQryCnf: WARNING:AT_BROADCAST_INDEX!");
        return VOS_ERR;
    }

    /* �жϵ�ǰ���������Ƿ�ΪAT_CMD_SMSDOMAIN_QRY */
    if (AT_CMD_SMSDOMAIN_QRY != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaSmsDomainQryCnf: WARNING:Not AT_CMD_SMSDOMAIN_QRY!");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    /* �жϲ�ѯ�����Ƿ�ɹ� */
    if (MTA_AT_RESULT_NO_ERROR == pstQryCnf->enResult)
    {
        ulResult                = AT_OK;
        gstAtSendData.usBufLen  = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                            (VOS_CHAR*)pgucAtSndCodeAddr,
                                            (VOS_CHAR*)pgucAtSndCodeAddr,
                                            "%s: %d",
                                            g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                            pstQryCnf->enSmsDomain);
    }
    else
    {
        ulResult                = AT_ERROR;
        gstAtSendData.usBufLen  = 0;
    }

    /* ����AT_FormatResultData���������� */
    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}


VOS_UINT32 AT_ConvertWs46RatOrderPara(
    VOS_UINT8                           ucClientId,
    TAF_MMA_SYS_CFG_PARA_STRU          *pstSysCfgSetPara
)
{
    TAF_MMA_MULTIMODE_RAT_CFG_STRU     *pstRatOrder = VOS_NULL_PTR;
    MODEM_ID_ENUM_UINT16                enModemId;
    VOS_UINT32                          ulRst;

    enModemId = MODEM_ID_0;
    pstRatOrder = &(pstSysCfgSetPara->stMultiModeRatCfg);

    ulRst = AT_GetModemIdFromClient(ucClientId, &enModemId);
    if (VOS_OK != ulRst)
    {
        AT_ERR_LOG1("AT_ConvertWs46RatOrderPara:Get ModemID From ClientID fail,ClientID:", ucClientId);
        return AT_ERROR;
    }

    AT_SetDefaultRatPrioList(enModemId, pstRatOrder, VOS_TRUE);

    pstSysCfgSetPara->enUserPrio = AT_GetSysCfgPrioRat(pstSysCfgSetPara);

    return AT_OK;
}



VOS_UINT32 AT_SetWs46Para(VOS_UINT8 ucIndex)
{
    TAF_MMA_SYS_CFG_PARA_STRU           stSysCfgSetPara;
    VOS_UINT32                          ulRst;
    AT_MODEM_NET_CTX_STRU              *pstNetCtx = VOS_NULL_PTR;

    TAF_MEM_SET_S(&stSysCfgSetPara, sizeof(stSysCfgSetPara), 0x00, sizeof(TAF_MMA_SYS_CFG_PARA_STRU));

    pstNetCtx = AT_GetModemNetCtxAddrFromClientId(ucIndex);

    ulRst = AT_OK;

    if (AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* �������� */
    if (gucAtParaIndex > 1)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    ulRst = AT_ConvertWs46RatOrderPara(ucIndex,
                                       &stSysCfgSetPara);

    if (AT_OK != ulRst)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* stSysCfgSetPara����������ֵ */
    if (AT_ROAM_FEATURE_ON == pstNetCtx->ucRoamFeature)
    {
        stSysCfgSetPara.enRoam = TAF_MMA_ROAM_UNCHANGE;
    }
    else
    {
        stSysCfgSetPara.enRoam = AT_ROAM_FEATURE_OFF_NOCHANGE;
    }

    stSysCfgSetPara.enSrvDomain         = TAF_MMA_SERVICE_DOMAIN_NOCHANGE;
    stSysCfgSetPara.stGuBand.ulBandLow  = TAF_PH_BAND_NO_CHANGE;
    stSysCfgSetPara.stGuBand.ulBandHigh = 0;

    TAF_MEM_SET_S(&(stSysCfgSetPara.stLBand),
                  sizeof(stSysCfgSetPara.stLBand),
                  0x00,
                  sizeof(TAF_USER_SET_LTE_PREF_BAND_INFO_STRU));
    stSysCfgSetPara.stLBand.aulBandInfo[0] = TAF_PH_BAND_NO_CHANGE;

    /* ִ��������� */
    if (VOS_TRUE == TAF_MMA_SetSysCfgReq(WUEPS_PID_AT, gastAtClientTab[ucIndex].usClientId, 0, &stSysCfgSetPara))
    {
        gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_WS46_SET;

        /* ������������״̬ */
        return AT_WAIT_ASYNC_RETURN;
    }
    else
    {
        return AT_ERROR;
    }
}


VOS_UINT32 AT_QryWs46Para(VOS_UINT8 ucIndex)
{
    if (VOS_TRUE == TAF_MMA_QrySyscfgReq(WUEPS_PID_AT,
                                         gastAtClientTab[ucIndex].usClientId,
                                         0))
    {
        gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_WS46_QRY;             /*���õ�ǰ����ģʽ */
        return AT_WAIT_ASYNC_RETURN;                                            /* �ȴ��첽�¼����� */
    }
    else
    {
        return AT_ERROR;
    }
}


VOS_UINT32 AT_TestWs46Para( VOS_UINT8 ucIndex )
{
    gstAtSendData.usBufLen = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                       (VOS_CHAR *)pgucAtSndCodeAddr,
                                       (VOS_CHAR *)pgucAtSndCodeAddr,
                                       "(12,22,25,28,29,30,31)"
                             );

    return AT_OK;
}



VOS_UINT32 AT_SetGpsLocSetPara(VOS_UINT8 ucIndex)
{
    AT_MTA_GPSLOCSET_SET_REQ_STRU       stAtCmd;
    VOS_UINT32                          ulResult;

    TAF_MEM_SET_S(&stAtCmd, sizeof(stAtCmd), 0x00, sizeof(AT_MTA_GPSLOCSET_SET_REQ_STRU));

    /* ������� */
    if(AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ��������������1��������AT_CME_INCORRECT_PARAMETERS */
    if (1 != gucAtParaIndex)
    {
        AT_WARN_LOG("AT_SetGpsLocSetPara: At Para Num Error.");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ��1����������Ϊ0������AT_CME_INCORRECT_PARAMETERS */
    if (0 == gastAtParaList[0].usParaLen)
    {
        AT_WARN_LOG("AT_SetGpsLocSetPara: para0 Length = 0");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    stAtCmd.ulLocationPermitFlag = gastAtParaList[0].ulParaValue;

    ulResult = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                      0,
                                      ID_AT_MTA_GPS_LOCSET_SET_REQ,
                                      &stAtCmd,
                                      sizeof(AT_MTA_GPSLOCSET_SET_REQ_STRU),
                                      I0_UEPS_PID_MTA);

    if (AT_SUCCESS != ulResult)
    {
        AT_WARN_LOG("AT_SetGpsLocSetPara: AT_FillAndSndAppReqMsg Failed!");
        return AT_ERROR;
    }
    
    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_GPSLOCSET_SET;
    
    return AT_WAIT_ASYNC_RETURN;
}



VOS_UINT32 AT_RcvMtaGpsLocSetCnf(VOS_VOID *pMsg)
{
    AT_MTA_MSG_STRU                        *pstRcvMsg               = VOS_NULL_PTR;
    MTA_AT_GPSLOCSET_SET_CNF_STRU          *pstSetCnf               = VOS_NULL_PTR;
    VOS_UINT32                              ulResult;
    VOS_UINT8                               ucIndex;

    /* ��ʼ�� */
    pstRcvMsg                 = (AT_MTA_MSG_STRU *)pMsg;
    pstSetCnf                 = (MTA_AT_GPSLOCSET_SET_CNF_STRU *)pstRcvMsg->aucContent;
    ulResult                  = AT_OK;
    ucIndex                   = 0;

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pstRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaGpsLocSetCnf : WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    /* �ж��Ƿ�Ϊ�㲥 */
    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaGpsLocSetCnf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_GPSLOCSET_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaGpsLocSetCnf : Current Option is not AT_CMD_GPSLOCSET_SET.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);
    gstAtSendData.usBufLen = 0;

    ulResult = AT_ConvertMtaResult(pstSetCnf->enResult);

    At_FormatResultData(ucIndex, ulResult);
    
    return VOS_OK;
}





VOS_VOID AT_PrintCclkTime(
    VOS_UINT8                           ucIndex,
    TIME_ZONE_TIME_STRU                *pstTimeZoneTime,
    MODEM_ID_ENUM_UINT16                enModemId
)
{
    TIME_ZONE_TIME_STRU                *pstTimeZone = VOS_NULL_PTR;
    AT_MODEM_NET_CTX_STRU              *pstNetCtx = VOS_NULL_PTR;
    VOS_UINT32                          ulYear;
    
    pstTimeZone = pstTimeZoneTime;

    pstNetCtx = AT_GetModemNetCtxAddrFromModemId(enModemId);

    if (1 == pstNetCtx->stCsdfCfg.ucAuxMode)
    {
        /* "yy/mm/dd,hh:mm:ss(+/-)zz" */
        ulYear = pstTimeZone->ucYear;
    }
    else
    {
        /* "yyyy/mm/dd,hh:mm:ss(+/-)zz" */
        if (pstTimeZone->ucYear > AT_GMT_TIME_DEFAULT)
        {
            ulYear = 1900 + pstTimeZone->ucYear;
        }
        else
        {
            ulYear = 2000 + pstTimeZone->ucYear;
        }
    }
   
    gstAtSendData.usBufLen = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                        (VOS_CHAR *)pgucAtSndCodeAddr,
                                        (VOS_CHAR *)pgucAtSndCodeAddr,
                                        "%s: \"%02d/%02d/%02d,%02d:%02d:%02d",
                                        g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                        ulYear,
                                        pstTimeZone->ucMonth,
                                        pstTimeZone->ucDay,
                                        pstTimeZone->ucHour,
                                        pstTimeZone->ucMinute,
                                        pstTimeZone->ucSecond);

    if (pstTimeZone->cTimeZone >= 0)
    {
        gstAtSendData.usBufLen += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
            (VOS_CHAR *)pgucAtSndCodeAddr,
            (VOS_CHAR *)pgucAtSndCodeAddr + gstAtSendData.usBufLen,
            "+%02d\"",
            pstTimeZone->cTimeZone);

    }
    else
    {
        gstAtSendData.usBufLen += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
            (VOS_CHAR *)pgucAtSndCodeAddr,
            (VOS_CHAR *)pgucAtSndCodeAddr + gstAtSendData.usBufLen,
            "-%02d\"",
            -(pstTimeZone->cTimeZone));

    }

    return;
}


VOS_UINT32 AT_RcvMtaCclkQryCnf(VOS_VOID *pMsg)
{
    AT_MTA_MSG_STRU                        *pstRcvMsg               = VOS_NULL_PTR;
    MTA_AT_CCLK_QRY_CNF_STRU               *pstQryCnf               = VOS_NULL_PTR;
    AT_MODEM_NET_CTX_STRU                  *pstNetCtx               = VOS_NULL_PTR;
    VOS_UINT32                              ulResult;
    VOS_UINT8                               ucIndex;
    MODEM_ID_ENUM_UINT16                    enModemId;
    TIME_ZONE_TIME_STRU                     stTime;;

    /* ��ʼ�� */
    TAF_MEM_SET_S(&stTime, sizeof(stTime), 0x00, sizeof(stTime));
    pstRcvMsg                 = (AT_MTA_MSG_STRU *)pMsg;
    pstQryCnf                 = (MTA_AT_CCLK_QRY_CNF_STRU *)pstRcvMsg->aucContent;
    ulResult                  = AT_OK;
    ucIndex                   = 0;
    
    ulResult = AT_GetModemIdFromClient(ucIndex, &enModemId);
    if (VOS_OK != ulResult)
    {
        AT_ERR_LOG("AT_RcvMtaCclkQryCnf: Get modem id fail.");
        return VOS_ERR;
    }

    pstNetCtx = AT_GetModemNetCtxAddrFromModemId(enModemId);

    /* ͨ��clientid��ȡindex */
    if (AT_FAILURE == At_ClientIdToUserId(pstRcvMsg->stAppCtrl.usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaCclkQryCnf : WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    /* �ж��Ƿ�Ϊ�㲥 */
    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvMtaCclkQryCnf : AT_BROADCAST_INDEX.");
        return VOS_ERR;
    }

    /* ��ǰAT�Ƿ��ڵȴ�������� */
    if (AT_CMD_CCLK_QRY != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvMtaCclkQryCnf : Current Option is not AT_CMD_CCLK_QRY.");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);
    gstAtSendData.usBufLen = 0;

    /* �жϲ�ѯ�����Ƿ�ɹ� */
    if (MTA_AT_RESULT_NO_ERROR == pstQryCnf->enResult)
    {
        ulResult                = AT_OK;
        stTime                  = pstQryCnf->stTime;
        
        pstNetCtx->stTimeInfo.stUniversalTimeandLocalTimeZone.ucYear    = pstQryCnf->stTime.ucYear;
        pstNetCtx->stTimeInfo.stUniversalTimeandLocalTimeZone.ucMonth   = pstQryCnf->stTime.ucMonth;
        pstNetCtx->stTimeInfo.stUniversalTimeandLocalTimeZone.ucDay     = pstQryCnf->stTime.ucDay;
        pstNetCtx->stTimeInfo.stUniversalTimeandLocalTimeZone.ucHour    = pstQryCnf->stTime.ucHour;
        pstNetCtx->stTimeInfo.stUniversalTimeandLocalTimeZone.ucMinute  = pstQryCnf->stTime.ucMinute;
        pstNetCtx->stTimeInfo.stUniversalTimeandLocalTimeZone.ucSecond  = pstQryCnf->stTime.ucSecond;
        pstNetCtx->stTimeInfo.stUniversalTimeandLocalTimeZone.cTimeZone = pstQryCnf->stTime.cTimeZone;
        pstNetCtx->stTimeInfo.ucIeFlg                                  |= NAS_MM_INFO_IE_UTLTZ;
        
        AT_PrintCclkTime(ucIndex, &stTime, enModemId);
    }
    else
    {
        ulResult                = AT_ERROR;
    }

    At_FormatResultData(ucIndex, ulResult);
    
    return VOS_OK;
}





VOS_UINT32 AT_SetPseudBtsPara(VOS_UINT8 ucIndex)
{
    AT_MTA_SET_PSEUDBTS_REQ_STRU        stAtCmd;
    VOS_UINT32                          ulRet;

    TAF_MEM_SET_S(&stAtCmd, sizeof(stAtCmd), 0x00, sizeof(AT_MTA_SET_PSEUDBTS_REQ_STRU));

     /* ������� */
    if(AT_CMD_OPT_SET_PARA_CMD != g_stATParseCmd.ucCmdOptType)
    {
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ��������������2��������AT_CME_INCORRECT_PARAMETERS */
    if (2 != gucAtParaIndex)
    {
        AT_WARN_LOG("AT_SetPseudBtsPara: At Para Num Error.");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    /* ��1����������Ϊ0������AT_CME_INCORR ECT_PARAMETERS */
    if ( (0 == gastAtParaList[0].usParaLen)
      || (0 == gastAtParaList[1].usParaLen))
    {
        AT_WARN_LOG("AT_SetPseudBtsPara: para Length = 0");
        return AT_CME_INCORRECT_PARAMETERS;
    }

    stAtCmd.ucPseudRat         = (VOS_UINT8)gastAtParaList[0].ulParaValue;
    stAtCmd.ucPseudBtsQryType  = (VOS_UINT8)gastAtParaList[1].ulParaValue;

    ulRet = AT_FillAndSndAppReqMsg(gastAtClientTab[ucIndex].usClientId,
                                  0,
                                  ID_AT_MTA_PSEUDBTS_SET_REQ,
                                  &stAtCmd,
                                  sizeof(AT_MTA_SET_PSEUDBTS_REQ_STRU),
                                  I0_UEPS_PID_MTA);

    if (AT_SUCCESS != ulRet)
    {
        AT_WARN_LOG("AT_SetPseudBtsPara: AT_FillAndSndAppReqMsg Failed!");
        return AT_ERROR;
    }

    gastAtClientTab[ucIndex].CmdCurrentOpt = AT_CMD_PSEUDBTS_SET;

    return AT_WAIT_ASYNC_RETURN;

}


VOS_UINT32 AT_RcvMtaPseudBtsIdentInd(VOS_VOID *pMsg)
{
    AT_MTA_MSG_STRU                     *pstMtaMsg                  = VOS_NULL_PTR;
    MTA_AT_PSEUD_BTS_IDENT_IND_STRU     *pstPseudBtsIdentInd        = VOS_NULL_PTR;
    VOS_UINT8                            ucIndex;

    pstMtaMsg                    = (AT_MTA_MSG_STRU*)pMsg;
    pstPseudBtsIdentInd          = (MTA_AT_PSEUD_BTS_IDENT_IND_STRU *)pstMtaMsg->aucContent;

    /* ͨ��ClientId��ȡucIndex */
    if ( AT_FAILURE == At_ClientIdToUserId(pstMtaMsg->stAppCtrl.usClientId, &ucIndex) )
    {
        AT_WARN_LOG("AT_RcvMtaPseudBtsIdentInd: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    gstAtSendData.usBufLen = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                   (VOS_CHAR *)pgucAtSndCodeAddr,
                                                   (VOS_CHAR *)pgucAtSndCodeAddr,
                                                   "%s%s: %d%s",
                                                   gaucAtCrLf,
                                                   gastAtStringTab[AT_STRING_PSEUDBTS].pucText,
                                                   pstPseudBtsIdentInd->ulPseudBtsType,
                                                   gaucAtCrLf);

    At_SendResultData(ucIndex, pgucAtSndCodeAddr, gstAtSendData.usBufLen);

    return VOS_OK;
}


