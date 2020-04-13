

/*****************************************************************************
  1 ͷ�ļ�����
*****************************************************************************/
#include "AtCmdCssProc.h"
#include "ATCmdProc.h"
#include "PsCommonDef.h"
#include "AtEventReport.h"


#define    THIS_FILE_ID                 PS_FILE_ID_AT_CMD_CSS_PROC_C

/*****************************************************************************
  2 ȫ�ֱ�������
*****************************************************************************/
/*AT��CSSģ�����Ϣ������ָ��*/
const AT_CSS_MSG_PRO_FUNC_STRU g_astAtCssMsgTab[] =
{
    /* ��ϢID */                            /* ��Ϣ������ */
    {ID_CSS_AT_MCC_INFO_SET_CNF,              AT_RcvCssMccInfoSetCnf},
    {ID_CSS_AT_MCC_VERSION_INFO_CNF,          AT_RcvCssMccVersionQryCnf},
    {ID_CSS_AT_QUERY_MCC_INFO_NOTIFY,         AT_RcvCssMccNotify},

    {ID_CSS_AT_BLACK_CELL_LIST_SET_CNF,       AT_RcvCssBlackCellListSetCnf},
    {ID_CSS_AT_BLACK_CELL_LIST_QUERY_CNF,     AT_RcvCssBlackCellListQryCnf},
    {ID_CSS_AT_BLACK_CELL_MCC_NOTIFY,         AT_RcvCssBlackCellMccNotify},

    {ID_CSS_AT_LINE_INDEX_LIST_SET_CNF,       AT_RcvCssLineIndexListSetCnf},
    {ID_CSS_AT_LINE_INDEX_LIST_QUERY_CNF,     AT_RcvCssLineIndexListQryCnf},
    {ID_CSS_AT_LINE_DETAIL_SET_CNF,           AT_RcvCssLineDetailSetCnf},
    {ID_CSS_AT_LINE_PLMN_NOTIFY,              AT_RcvCssLinePlmnNotify},
    {ID_CSS_AT_LINE_INDEX_NOTIFY,             AT_RcvCssLineIndexNotify},


};

/*****************************************************************************
  3 ����ʵ��
*****************************************************************************/

VOS_VOID AT_ProcCssMsg(
    CssAtInterface_MSG                 *pstMsg
)
{
    VOS_UINT32                          i;
    VOS_UINT32                          ulMsgCnt;
    VOS_UINT32                          ulMsgId;
    VOS_UINT32                          ulRst;

    /*��g_astAtProcMsgFromImsaTab�л�ȡ��Ϣ����*/
    ulMsgCnt = sizeof(g_astAtCssMsgTab)/sizeof(AT_CSS_MSG_PRO_FUNC_STRU);

    /*����Ϣ���л�ȡMSG ID*/
    ulMsgId  = pstMsg->stMsgData.ulMsgId;

    /*g_astAtProcMsgFromCssTab���������Ϣ�ַ�*/
    for (i = 0; i < ulMsgCnt; i++)
    {
        if (g_astAtCssMsgTab[i].ulMsgId == ulMsgId)
        {
            ulRst = g_astAtCssMsgTab[i].pProcMsgFunc(pstMsg);

            if (VOS_ERR == ulRst)
            {
                AT_ERR_LOG("AT_ProcCssMsg: Msg Proc Err!");
            }

            return;
        }
    }

    /*û���ҵ�ƥ�����Ϣ*/
    if (ulMsgCnt == i)
    {
        AT_ERR_LOG("AT_ProcCssMsg: Msg Id is invalid!");
    }

    return;
}


VOS_UINT32 AT_RcvCssMccInfoSetCnf(
    VOS_VOID                           *pstMsg
)
{
    /* ����ֲ����� */
    CSS_AT_MCC_INFO_SET_CNF_STRU       *pstMccInfoSetCnf    = VOS_NULL_PTR;
    VOS_UINT8                           ucIndex;
    VOS_UINT32                          ulResult;
    VOS_UINT32                          ulRetVal;

    /* ��ʼ����Ϣ���� */
    ucIndex          = 0;
    ulRetVal         = VOS_ERR;
    ulResult         = AT_ERROR;
    pstMccInfoSetCnf = (CSS_AT_MCC_INFO_SET_CNF_STRU *)pstMsg;

    /* ͨ��ClientId��ȡucIndex */
    if (AT_FAILURE == At_ClientIdToUserId(pstMccInfoSetCnf->usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvCssMccInfoSetCnf: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvCssMccInfoSetCnf: WARNING:AT_BROADCAST_INDEX!");
        return VOS_ERR;
    }

    /* �жϵ�ǰ���������Ƿ�ΪAT_CMD_MCCFREQ_SET */
    if (AT_CMD_MCCFREQ_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvCssMccInfoSetCnf: WARNING:Not AT_CMD_MCCFREQ_SET!");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    /* �жϲ�ѯ�����Ƿ�ɹ� */
    if (VOS_OK == pstMccInfoSetCnf->ulResult)
    {
        ulResult    = AT_OK;
        ulRetVal    = VOS_OK;
    }

    gstAtSendData.usBufLen = 0;

    /* ����At_FormatResultData���������� */
    At_FormatResultData(ucIndex, ulResult);

    return ulRetVal;
}



VOS_UINT32 AT_RcvCssMccVersionQryCnf(
    VOS_VOID                           *pstMsg
)
{
    /* ����ֲ����� */
    CSS_AT_MCC_VERSION_INFO_CNF_STRU   *pstMccVersionInfoCnf    = VOS_NULL_PTR;
    VOS_UINT8                           aucVersionId[MCC_INFO_VERSION_LEN+1] = {0};
    VOS_UINT8                           ucIndex;
    VOS_UINT32                          ulResult;

    /* ��ʼ����Ϣ���� */
    ucIndex     = 0;
    pstMccVersionInfoCnf = (CSS_AT_MCC_VERSION_INFO_CNF_STRU *)pstMsg;

    /* ͨ��ClientId��ȡucIndex */
    if ( AT_FAILURE == At_ClientIdToUserId(pstMccVersionInfoCnf->usClientId, &ucIndex) )
    {
        AT_WARN_LOG("AT_RcvCssMccVersionQryCnf: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvCssMccVersionQryCnf: WARNING:AT_BROADCAST_INDEX!");
        return VOS_ERR;
    }

    /* �жϵ�ǰ���������Ƿ�ΪAT_CMD_MCCFREQ_QRY */
    if ( AT_CMD_MCCFREQ_QRY != gastAtClientTab[ucIndex].CmdCurrentOpt )
    {
        AT_WARN_LOG("AT_RcvCssMccVersionQryCnf: WARNING:Not AT_CMD_MCCFREQ_QRY!");
        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    /* ����Version String */
    TAF_MEM_CPY_S(aucVersionId, sizeof(aucVersionId), pstMccVersionInfoCnf->aucVersionId, MCC_INFO_VERSION_LEN);

    /* �жϲ�ѯ�����Ƿ�ɹ� */
    gstAtSendData.usBufLen= (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                   (VOS_CHAR *)pgucAtSndCodeAddr,
                                                   (VOS_CHAR *)pgucAtSndCodeAddr,
                                                   "%s: %s",
                                                   g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                                   (VOS_CHAR *)aucVersionId);

    ulResult = AT_OK;

    /* ����At_FormatResultData���������� */
    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}




VOS_UINT32 AT_RcvCssMccNotify(
    VOS_VOID                           *pstMsg
)
{
    /* ����ֲ����� */
    VOS_UINT8                           ucIndex;
    VOS_UINT8                           i;
    VOS_UINT8                           aucMccStr[AT_CSS_MAX_MCC_ID_NUM*AT_MCC_PLUS_COMMA_LENGTH] = {0};
    VOS_UINT8                           aucVersionId[MCC_INFO_VERSION_LEN+1] = {0};
    CSS_AT_QUERY_MCC_INFO_NOTIFY_STRU  *pstCssMccNty    = VOS_NULL_PTR;

    /* ��ʼ����Ϣ���� */
    ucIndex      = 0;
    pstCssMccNty = (CSS_AT_QUERY_MCC_INFO_NOTIFY_STRU *)pstMsg;

    /* ͨ��ClientId��ȡucIndex */
    if ( AT_FAILURE == At_ClientIdToUserId(pstCssMccNty->usClientId, &ucIndex) )
    {
        AT_WARN_LOG("AT_RcvCssMccNotify: WARNING:AT INDEX NOT FOUND!");
        return VOS_ERR;
    }

    /* MCC�������� */
    if ((0 == pstCssMccNty->ulMccNum)
     || (AT_CSS_MAX_MCC_ID_NUM < pstCssMccNty->ulMccNum))
    {
        AT_WARN_LOG("AT_RcvCssMccNotify: WARNING:INVALID MCC NUM!");
        return VOS_ERR;
    }

    /* �����ϱ���Ril��MCC�ַ��� */
    for (i = 0; i < pstCssMccNty->ulMccNum; i++)
    {
        aucMccStr[AT_MCC_PLUS_COMMA_LENGTH*i]   = (pstCssMccNty->astMccId[i].aucMcc[0] & 0x0f) + '0';
        aucMccStr[AT_MCC_PLUS_COMMA_LENGTH*i+1] = ((pstCssMccNty->astMccId[i].aucMcc[0] & 0xf0) >> 4) + '0';
        aucMccStr[AT_MCC_PLUS_COMMA_LENGTH*i+2] = (pstCssMccNty->astMccId[i].aucMcc[1] & 0x0f) + '0';
        aucMccStr[AT_MCC_PLUS_COMMA_LENGTH*i+3] = ',';
    }

    /* �ַ��������� */
    aucMccStr[(VOS_UINT8)(pstCssMccNty->ulMccNum)*AT_MCC_PLUS_COMMA_LENGTH-1] = 0;

    /* ����Version String */
    TAF_MEM_CPY_S(aucVersionId, sizeof(aucVersionId), pstCssMccNty->aucVersionId, MCC_INFO_VERSION_LEN);

    gstAtSendData.usBufLen = (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                                    (VOS_CHAR *)pgucAtSndCodeAddr,
                                                    (VOS_CHAR *)pgucAtSndCodeAddr,
                                                    "%s%s %s,%s%s",
                                                    gaucAtCrLf,
                                                    gastAtStringTab[AT_STRING_MCC].pucText,
                                                    (VOS_CHAR *)aucVersionId,
                                                    (VOS_CHAR *)aucMccStr,
                                                    gaucAtCrLf);

    At_SendResultData(ucIndex, pgucAtSndCodeAddr, gstAtSendData.usBufLen);

    return VOS_OK;
}


VOS_UINT32 AT_RcvCssBlackCellListSetCnf(
    VOS_VOID                           *pstMsg
)
{
    /* ����ֲ����� */
    CSS_AT_BLACK_CELL_LIST_SET_CNF_STRU                    *pstCssSetCnf    = VOS_NULL_PTR;
    VOS_UINT32                                              ulResult;
    VOS_UINT8                                               ucIndex;

    /* ��ʼ����Ϣ���� */
    pstCssSetCnf = (CSS_AT_BLACK_CELL_LIST_SET_CNF_STRU *)pstMsg;

    ucIndex      = 0;

    /* ͨ��ClientId��ȡucIndex */
    if (AT_FAILURE == At_ClientIdToUserId(pstCssSetCnf->usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvCssBlackCellListSetCnf: WARNING:AT INDEX NOT FOUND!");

        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvCssBlackCellListSetCnf: WARNING:AT_BROADCAST_INDEX!");

        return VOS_ERR;
    }

    /* �жϵ�ǰ���������Ƿ�ΪAT_CMD_CLOUDBLACKLIST_SET */
    if (AT_CMD_BLACKCELLLIST_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvCssBlackCellListSetCnf: WARNING:Not AT_CMD_BLACKCELLLIST_SET!");

        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    ulResult = AT_ERROR;

    if (VOS_OK == pstCssSetCnf->ulResult)
    {
        ulResult    = AT_OK;
    }

    gstAtSendData.usBufLen = 0;

    /* ����At_FormatResultData���������� */
    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}


VOS_UINT32 AT_RcvCssBlackCellListQryCnf(
    VOS_VOID                           *pstMsg
)
{
    CSS_AT_BLACK_CELL_LIST_QUERY_CNF_STRU                  *pstCssQryCnf           = VOS_NULL_PTR;
    VOS_UINT8                                               aucVersionId[AT_CSS_BLACK_CELL_LIST_VERSION_LEN + 1];
    VOS_UINT32                                              ulMcc;
    VOS_UINT32                                              ulLoop;
    VOS_UINT16                                              usLength;
    VOS_UINT8                                               ucIndex;

    /* ��ʼ����Ϣ���� */
    pstCssQryCnf = (CSS_AT_BLACK_CELL_LIST_QUERY_CNF_STRU *)pstMsg;

    ucIndex   = 0;

    /* ͨ��ClientId��ȡucIndex */
    if ( AT_FAILURE == At_ClientIdToUserId(pstCssQryCnf->usClientId, &ucIndex) )
    {
        AT_WARN_LOG("AT_RcvCssBlackCellListQryCnf: WARNING:AT INDEX NOT FOUND!");

        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvCssBlackCellListQryCnf: WARNING:AT_BROADCAST_INDEX!");

        return VOS_ERR;
    }

    /* �жϵ�ǰ���������Ƿ�ΪAT_CMD_CLOUDBLACKLIST_QRY */
    if ( AT_CMD_BLACKCELLLIST_QRY != gastAtClientTab[ucIndex].CmdCurrentOpt )
    {
        AT_WARN_LOG("AT_RcvCssBlackCellListQryCnf: WARNING:Not AT_CMD_BLACKCELLLIST_QRY!");

        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    /* MCC�������� */
    if (AT_CSS_MAX_MCC_ID_NUM < pstCssQryCnf->stMccInfo.ulMccNum)
    {
        AT_WARN_LOG("AT_RcvCssBlackCellListQryCnf: WARNING:INVALID MCC NUM!");

        At_FormatResultData(ucIndex, AT_ERROR);

        return VOS_ERR;
    }

    /* �����ϱ���Ril��Version */
    TAF_MEM_SET_S(aucVersionId, sizeof(aucVersionId), 0, sizeof(aucVersionId));
    TAF_MEM_CPY_S(aucVersionId, sizeof(aucVersionId), pstCssQryCnf->aucVersionId, sizeof(pstCssQryCnf->aucVersionId));

    usLength = 0;

    usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                       (VOS_CHAR *)pgucAtSndCodeAddr,
                                       (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                       "%s: \"%s\"",
                                       g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                       aucVersionId);

    /* �����ϱ���Ril��MCC�ַ��� */
    for (ulLoop = 0; ulLoop < pstCssQryCnf->stMccInfo.ulMccNum; ulLoop++)
    {
        ulMcc = 0;

        AT_ConvertNasMccToBcdType(pstCssQryCnf->stMccInfo.aulMcc[ulLoop], &ulMcc);

        usLength += (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                           (TAF_CHAR *)pgucAtSndCodeAddr,
                                           (TAF_CHAR *)pgucAtSndCodeAddr + usLength,
                                           ",%x%x%x",
                                           (ulMcc & 0x0f00)>>8,
                                           (ulMcc & 0xf0)>>4,
                                           (ulMcc & 0x0f));
    }

    gstAtSendData.usBufLen = usLength;

    At_FormatResultData(ucIndex, AT_OK);

    return VOS_OK;
}


VOS_UINT32 AT_RcvCssBlackCellMccNotify(
    VOS_VOID                           *pstMsg
)
{
    /* ����ֲ����� */
    CSS_AT_BLACK_CELL_MCC_NOTIFY_STRU  *pstCssNty = VOS_NULL_PTR;
    VOS_UINT8                           aucVersionId[AT_CSS_BLACK_CELL_LIST_VERSION_LEN + 1];
    VOS_UINT32                          ulMcc;
    VOS_UINT32                          ulLoop;
    VOS_UINT16                          usLength;
    VOS_UINT8                           ucIndex;

    /* ��ʼ����Ϣ���� */
    pstCssNty = (CSS_AT_BLACK_CELL_MCC_NOTIFY_STRU *)pstMsg;

    ucIndex   = 0;

    /* ͨ��ClientId��ȡucIndex */
    if ( AT_FAILURE == At_ClientIdToUserId(pstCssNty->usClientId, &ucIndex) )
    {
        AT_WARN_LOG("AT_RcvCssBlackCellMccNotify: WARNING:AT INDEX NOT FOUND!");

        return VOS_ERR;
    }

    /* MCC�������� */
    if ((0 == pstCssNty->stMccInfo.ulMccNum)
     || (AT_CSS_MAX_MCC_ID_NUM < pstCssNty->stMccInfo.ulMccNum))
    {
        AT_WARN_LOG("AT_RcvCssBlackCellMccNotify: WARNING:INVALID MCC NUM!");

        return VOS_ERR;
    }

    /* �����ϱ���Ril��Version */
    TAF_MEM_SET_S(aucVersionId, sizeof(aucVersionId), 0, sizeof(aucVersionId));
    TAF_MEM_CPY_S(aucVersionId, sizeof(aucVersionId), pstCssNty->aucVersionId, sizeof(pstCssNty->aucVersionId));

    usLength = 0;

    usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                       (VOS_CHAR *)pgucAtSndCodeAddr,
                                       (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                       "%s%s\"%s\"",
                                       gaucAtCrLf,
                                       gastAtStringTab[AT_STRING_BLACK_CELL_MCC].pucText,
                                       aucVersionId);

    /* �����ϱ���Ril��MCC�ַ��� */
    for (ulLoop = 0; ulLoop < pstCssNty->stMccInfo.ulMccNum; ulLoop++)
    {
        ulMcc = 0;

        AT_ConvertNasMccToBcdType(pstCssNty->stMccInfo.aulMcc[ulLoop], &ulMcc);

        usLength += (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                           (TAF_CHAR *)pgucAtSndCodeAddr,
                                           (TAF_CHAR *)pgucAtSndCodeAddr + usLength,
                                           ",%x%x%x",
                                           (ulMcc & 0x0f00)>>8,
                                           (ulMcc & 0xf0)>>4,
                                           (ulMcc & 0x0f));
    }

    usLength += (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                      (TAF_CHAR *)pgucAtSndCodeAddr,
                                      (TAF_CHAR *)pgucAtSndCodeAddr + usLength,
                                      "%s",
                                      gaucAtCrLf);

    gstAtSendData.usBufLen = usLength;

    At_SendResultData(ucIndex, pgucAtSndCodeAddr, gstAtSendData.usBufLen);

    return VOS_OK;
}


VOS_UINT32 AT_RcvCssLineIndexListSetCnf(
    VOS_VOID                           *pstMsg
)
{
    /* ����ֲ����� */
    CSS_AT_LINE_INDEX_LIST_SET_CNF_STRU                    *pstCssSetCnf    = VOS_NULL_PTR;
    VOS_UINT32                                              ulResult;
    VOS_UINT8                                               ucIndex;

    /* ��ʼ����Ϣ���� */
    pstCssSetCnf = (CSS_AT_LINE_INDEX_LIST_SET_CNF_STRU *)pstMsg;

    ucIndex      = 0;

    /* ͨ��ClientId��ȡucIndex */
    if (AT_FAILURE == At_ClientIdToUserId(pstCssSetCnf->usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvCssLineIndexListSetCnf: WARNING:AT INDEX NOT FOUND!");

        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvCssLineIndexListSetCnf: WARNING:AT_BROADCAST_INDEX!");

        return VOS_ERR;
    }

    /* �жϵ�ǰ���������Ƿ�ΪAT_CMD_LINEINDEXLIST_SET */
    if (AT_CMD_LINEINDEXLIST_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvCssLineIndexListSetCnf: WARNING:Not AT_CMD_LINEINDEXLIST_SET!");

        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    ulResult = AT_ERROR;

    if (VOS_OK == pstCssSetCnf->ulResult)
    {
        ulResult    = AT_OK;
    }

    gstAtSendData.usBufLen = 0;

    /* ����At_FormatResultData���������� */
    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}


VOS_UINT32 AT_RcvCssLineIndexListQryCnf(
    VOS_VOID                           *pstMsg
)
{
    CSS_AT_LINE_INDEX_LIST_QUERY_CNF_STRU                  *pstCssQryCnf = VOS_NULL_PTR;
    VOS_UINT32                                              ulMcc;
    VOS_UINT32                                              ulMnc;
    VOS_UINT16                                              usLength;
    VOS_UINT8                                               aucVersionId[AT_CSS_CLOUD_LINE_VERSION_LEN + 1];
    VOS_UINT8                                               ucIndex;

    /* ��ʼ����Ϣ���� */
    pstCssQryCnf = (CSS_AT_LINE_INDEX_LIST_QUERY_CNF_STRU *)pstMsg;

    ucIndex = 0;
    ulMcc   = 0xFFFFFFFF;
    ulMnc   = 0xFFFFFFFF;

    /* ͨ��ClientId��ȡucIndex */
    if ( AT_FAILURE == At_ClientIdToUserId(pstCssQryCnf->usClientId, &ucIndex) )
    {
        AT_WARN_LOG("AT_RcvCssLineIndexListQryCnf: WARNING:AT INDEX NOT FOUND!");

        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvCssLineIndexListQryCnf: WARNING:AT_BROADCAST_INDEX!");

        return VOS_ERR;
    }

    /* �жϵ�ǰ���������Ƿ�ΪAT_CMD_CLOUDBLACKLIST_QRY */
    if ( AT_CMD_LINEINDEXLIST_QRY != gastAtClientTab[ucIndex].CmdCurrentOpt )
    {
        AT_WARN_LOG("AT_RcvCssLineIndexListQryCnf: WARNING:Not AT_CMD_LINEINDEXLIST_QRY!");

        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    usLength = 0;
    /* ����result  */
    usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                       (TAF_CHAR *)pgucAtSndCodeAddr,
                                       (TAF_CHAR *)pgucAtSndCodeAddr + usLength,
                                       "%s: %d",
                                       g_stParseContext[ucIndex].pstCmdElement->pszCmdName,
                                       pstCssQryCnf->ulResult);

    if (VOS_TRUE == pstCssQryCnf->ulResult)
    {
        AT_ConvertNasMccToBcdType(pstCssQryCnf->stRplmnInfo.ulMcc, &ulMcc);
        AT_ConvertNasMncToBcdType(pstCssQryCnf->stRplmnInfo.ulMnc, &ulMnc);

        /* �����ϱ���Ril��RPLMN */
        usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                           (TAF_CHAR *)pgucAtSndCodeAddr,
                                           (TAF_CHAR *)pgucAtSndCodeAddr + usLength,
                                           ",\"%x%x%x",
                                           (ulMcc & 0x0f00)>>8,
                                           (ulMcc & 0xf0)>>4,
                                           (ulMcc & 0x0f));

        if (0x0f00 == (ulMnc & 0x0f00))
        {
            usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                               (TAF_CHAR *)pgucAtSndCodeAddr,
                                               (TAF_CHAR *)pgucAtSndCodeAddr + usLength,
                                               "%x%x\",",
                                               (ulMnc & 0xf0)>>4,
                                               (ulMnc & 0x0f));
        }
        else
        {
            usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                               (TAF_CHAR *)pgucAtSndCodeAddr,
                                               (TAF_CHAR *)pgucAtSndCodeAddr + usLength,
                                               "%x%x%x\",",
                                               (ulMnc & 0x0f00)>>8,
                                               (ulMnc & 0xf0)>>4,
                                               (ulMnc & 0x0f));
        }


        /* �����ϱ���Ril��Version */
        TAF_MEM_SET_S(aucVersionId, sizeof(aucVersionId), 0, sizeof(aucVersionId));
        TAF_MEM_CPY_S(aucVersionId, sizeof(aucVersionId), pstCssQryCnf->aucVersionId, sizeof(pstCssQryCnf->aucVersionId));

        usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                           (VOS_CHAR *)pgucAtSndCodeAddr,
                                           (VOS_CHAR *)pgucAtSndCodeAddr + usLength,
                                           "\"%s\"",
                                           aucVersionId);
    }

    gstAtSendData.usBufLen = usLength;

    At_FormatResultData(ucIndex, AT_OK);

    return VOS_OK;
}


VOS_UINT32 AT_RcvCssLineDetailSetCnf(
    VOS_VOID                           *pstMsg
)
{
    /* ����ֲ����� */
    CSS_AT_LINE_DETAIL_SET_CNF_STRU                        *pstCssSetCnf    = VOS_NULL_PTR;
    VOS_UINT32                                              ulResult;
    VOS_UINT8                                               ucIndex;

    /* ��ʼ����Ϣ���� */
    pstCssSetCnf = (CSS_AT_LINE_DETAIL_SET_CNF_STRU *)pstMsg;

    ucIndex      = 0;

    /* ͨ��ClientId��ȡucIndex */
    if (AT_FAILURE == At_ClientIdToUserId(pstCssSetCnf->usClientId, &ucIndex))
    {
        AT_WARN_LOG("AT_RcvCssLineIndexListSetCnf: WARNING:AT INDEX NOT FOUND!");

        return VOS_ERR;
    }

    if (AT_IS_BROADCAST_CLIENT_INDEX(ucIndex))
    {
        AT_WARN_LOG("AT_RcvCssLineIndexListSetCnf: WARNING:AT_BROADCAST_INDEX!");

        return VOS_ERR;
    }

    /* �жϵ�ǰ���������Ƿ�ΪAT_CMD_LINEDETAIL_SET */
    if (AT_CMD_LINEDETAIL_SET != gastAtClientTab[ucIndex].CmdCurrentOpt)
    {
        AT_WARN_LOG("AT_RcvCssLineIndexListSetCnf: WARNING:Not AT_CMD_LINEDETAIL_SET!");

        return VOS_ERR;
    }

    /* ��λAT״̬ */
    AT_STOP_TIMER_CMD_READY(ucIndex);

    ulResult = AT_ERROR;

    if (VOS_OK == pstCssSetCnf->ulResult)
    {
        ulResult    = AT_OK;
    }

    gstAtSendData.usBufLen = 0;

    /* ����At_FormatResultData���������� */
    At_FormatResultData(ucIndex, ulResult);

    return VOS_OK;
}


VOS_UINT32 AT_RcvCssLinePlmnNotify(
    VOS_VOID                           *pstMsg
)
{
    /* ����ֲ����� */
    CSS_AT_LINE_PLMN_NOTIFY_STRU       *pstCssNty = VOS_NULL_PTR;
    VOS_UINT32                          ulMcc     = 0xFFFFFFFF;
    VOS_UINT32                          ulMnc     = 0xFFFFFFFF;
    VOS_UINT16                          usLength;
    VOS_UINT8                           ucIndex;

    /* ��ʼ����Ϣ���� */
    pstCssNty = (CSS_AT_LINE_PLMN_NOTIFY_STRU *)pstMsg;

    ucIndex   = 0;

    /* ͨ��ClientId��ȡucIndex */
    if ( AT_FAILURE == At_ClientIdToUserId(pstCssNty->usClientId, &ucIndex) )
    {
        AT_WARN_LOG("AT_RcvCssLinePlmnNotify: WARNING:AT INDEX NOT FOUND!");

        return VOS_ERR;
    }

    AT_ConvertNasMccToBcdType(pstCssNty->stRplmnInfo.ulMcc, &ulMcc);
    AT_ConvertNasMncToBcdType(pstCssNty->stRplmnInfo.ulMnc, &ulMnc);

    usLength = 0;

    /* �����ϱ���Ril��RPLMN */
    usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                       (TAF_CHAR *)pgucAtSndCodeAddr,
                                       (TAF_CHAR *)pgucAtSndCodeAddr + usLength,
                                       "%s%s\"%x%x%x",
                                       gaucAtCrLf,
                                       gastAtStringTab[AT_STRING_LINE_RPLMN].pucText,
                                       (ulMcc & 0x0f00)>>8,
                                       (ulMcc & 0xf0)>>4,
                                       (ulMcc & 0x0f));

    if (0x0f00 == (ulMnc & 0x0f00))
    {
        usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                           (TAF_CHAR *)pgucAtSndCodeAddr,
                                           (TAF_CHAR *)pgucAtSndCodeAddr + usLength,
                                           "%x%x\"",
                                           (ulMnc & 0xf0)>>4,
                                           (ulMnc & 0x0f));
    }
    else
    {
        usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                           (TAF_CHAR *)pgucAtSndCodeAddr,
                                           (TAF_CHAR *)pgucAtSndCodeAddr + usLength,
                                           "%x%x%x\"",
                                           (ulMnc & 0x0f00)>>8,
                                           (ulMnc & 0xf0)>>4,
                                           (ulMnc & 0x0f));
    }

    usLength += (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                      (TAF_CHAR *)pgucAtSndCodeAddr,
                                      (TAF_CHAR *)pgucAtSndCodeAddr + usLength,
                                      "%s",
                                      gaucAtCrLf);

    gstAtSendData.usBufLen = usLength;

    At_SendResultData(ucIndex, pgucAtSndCodeAddr, gstAtSendData.usBufLen);

    return VOS_OK;
}


VOS_UINT32 AT_RcvCssLineIndexNotify(
    VOS_VOID                           *pstMsg
)
{
    /* ����ֲ����� */
    CSS_AT_LINE_INDEX_NOTIFY_STRU      *pstCssNty = VOS_NULL_PTR;
    VOS_UINT32                          ulMcc     = 0xFFFFFFFF;
    VOS_UINT32                          ulMnc     = 0xFFFFFFFF;
    VOS_UINT16                          usLength;
    VOS_UINT8                           ucIndex;
    VOS_UINT16                          usLoop;

    /* ��ʼ����Ϣ���� */
    pstCssNty = (CSS_AT_LINE_INDEX_NOTIFY_STRU *)pstMsg;

    ucIndex   = 0;

    /* ͨ��ClientId��ȡucIndex */
    if ( AT_FAILURE == At_ClientIdToUserId(pstCssNty->usClientId, &ucIndex) )
    {
        AT_WARN_LOG("AT_RcvCssLineIndexNotify: WARNING:AT INDEX NOT FOUND!");

        return VOS_ERR;
    }

    if ( 0 == pstCssNty->usLineNum)
    {
        AT_WARN_LOG("AT_RcvCssLineIndexNotify: WARNING:line num is 0!");

        return VOS_ERR;
    }

    AT_ConvertNasMccToBcdType(pstCssNty->stPlmnId.ulMcc, &ulMcc);
    AT_ConvertNasMncToBcdType(pstCssNty->stPlmnId.ulMnc, &ulMnc);

    usLength = 0;

    /* �����ϱ���Ril��RPLMN */
    usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                       (TAF_CHAR *)pgucAtSndCodeAddr,
                                       (TAF_CHAR *)pgucAtSndCodeAddr + usLength,
                                       "%s%s\"%x%x%x",
                                       gaucAtCrLf,
                                       gastAtStringTab[AT_STRING_LINE_INDEX].pucText,
                                       (ulMcc & 0x0f00)>>8,
                                       (ulMcc & 0xf0)>>4,
                                       (ulMcc & 0x0f));

    if (0x0f00 == (ulMnc & 0x0f00))
    {
        usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                           (TAF_CHAR *)pgucAtSndCodeAddr,
                                           (TAF_CHAR *)pgucAtSndCodeAddr + usLength,
                                           "%x%x\"",
                                           (ulMnc & 0xf0)>>4,
                                           (ulMnc & 0x0f));
    }
    else
    {
        usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                           (TAF_CHAR *)pgucAtSndCodeAddr,
                                           (TAF_CHAR *)pgucAtSndCodeAddr + usLength,
                                           "%x%x%x\"",
                                           (ulMnc & 0x0f00)>>8,
                                           (ulMnc & 0xf0)>>4,
                                           (ulMnc & 0x0f));
    }

    /* CSS����usLineNum�������AT_CSS_PLMN_MAX_LINE_NUM��������ڣ��Ͱ�AT_CSS_TACLAC_MAX_LINE_NUM�������� */
    for (usLoop = 0; ((usLoop < pstCssNty->usLineNum) && (usLoop < AT_CSS_TACLAC_MAX_LINE_NUM)); usLoop++)
    {
        usLength += (VOS_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                       (TAF_CHAR *)pgucAtSndCodeAddr,
                                       (TAF_CHAR *)pgucAtSndCodeAddr + usLength,
                                       ",%d",
                                       pstCssNty->ausLineIndexList[usLoop]);
    }

    usLength += (TAF_UINT16)At_sprintf(AT_CMD_MAX_LEN,
                                      (TAF_CHAR *)pgucAtSndCodeAddr,
                                      (TAF_CHAR *)pgucAtSndCodeAddr + usLength,
                                      "%s",
                                      gaucAtCrLf);

    gstAtSendData.usBufLen = usLength;

    At_SendResultData(ucIndex, pgucAtSndCodeAddr, gstAtSendData.usBufLen);

    return VOS_OK;
}


