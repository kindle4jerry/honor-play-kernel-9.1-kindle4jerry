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

#ifndef __RNICDEBUG_H__
#define __RNICDEBUG_H__

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "vos.h"
#include "PsCommonDef.h"
#include "product_config.h"
#include "RnicLinuxInterface.h"
#include "msp_diag_comm.h"
#include "RnicCtx.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 �궨��
*****************************************************************************/

#define RNIC_DBG_NET_TX_RMNETID_ERR_NUM(n)          (g_stRnicMntnStats.ulNetTxRmNetIdErrNum += (n))
#define RNIC_DBG_SPE_TX_PORTID_ERR_NUM(n)           (g_stRnicMntnStats.ulSpeTxPortIdErrNum += (n))

/* ����ͳ����Ϣ */
#define  RNIC_DBG_RECV_UL_IPV4_PKT_NUM(n, index)       (g_astRnicStats[index].ulUlRecvIpv4PktNum += (n))
#define  RNIC_DBG_RECV_UL_IPV6_PKT_NUM(n, index)       (g_astRnicStats[index].ulUlRecvIpv6PktNum += (n))
#define  RNIC_DBG_RECV_UL_IPV4V6_PKT_NUM(n, index)     (g_astRnicStats[index].ulUlRecvIpv4v6PktNum += (n))
#define  RNIC_DBG_RECV_UL_UNDIAL_PKT_NUM(n, index)     (g_astRnicStats[index].ulUlRecvUndiaPktNum += (n))
#define  RNIC_DBG_SEND_UL_PKT_NUM(n, index)            (g_astRnicStats[index].ulUlSendPktNum += (n))
#define  RNIC_DBG_SEND_UL_PKT_FAIL_NUM(n, index)       (g_astRnicStats[index].ulUlSendPktFailNum += (n))
#define  RNIC_DBG_UL_RECV_IPV4_BROADCAST_NUM(n, index) (g_astRnicStats[index].ulUlIpv4BrdcstPktNum += (n))
#define  RNIC_DBG_UL_CHANGE_IMMZC_FAIL_NUM(n, index)   (g_astRnicStats[index].ulUlImmzcFailPktNum += (n))
#define  RNIC_DBG_UL_RMV_MAC_HDR_FAIL_NUM(n, index)    (g_astRnicStats[index].ulUlRmvMacHdrFailPktNum += (n))
#define  RNIC_DBG_NETCAED_UL_DISCARD_NUM(n, index)     (g_astRnicStats[index].ulUlNetCardDiscardNum += (n))
#define  RNIC_DBG_FLOW_CTRL_UL_DISCARD_NUM(n, index)   (g_astRnicStats[index].ulUlFlowCtrlDiscardNum += (n))
#define  RNIC_DBG_RECV_UL_ERR_PKT_NUM(n, index)        (g_astRnicStats[index].ulUlRecvErrPktNum += (n))
#define  RNIC_DBG_RAB_ID_ERR_NUM(n, index)             (g_astRnicStats[index].ulUlRabIdErr += (n))
#define  RNIC_DBG_SEND_APP_DIALUP_SUCC_NUM(n, index)   (g_astRnicStats[index].ulUlSendAppDialUpSucc += (n))
#define  RNIC_DBG_SEND_APP_DIALUP_FAIL_NUM(n, index)   (g_astRnicStats[index].ulUlSendAppDialUpFail += (n))
#define  RNIC_DBG_SEND_APP_DIALDOWN_SUCC_NUM(n, index) (g_astRnicStats[index].ulUlSendAppDialDownSucc += (n))
#define  RNIC_DBG_SEND_APP_DIALDOWN_FAIL_NUM(n, index) (g_astRnicStats[index].ulUlSendAppDialDownFail += (n))
#define  RNIC_DBG_NET_ID_UL_DISCARD_NUM(n, index)      (g_astRnicStats[index].ulUlNetIdDiscardNum += (n))
#define  RNIC_DBG_MODEM_ID_UL_DISCARD_NUM(n, index)    (g_astRnicStats[index].ulUlModemIdDiscardNum += (n))
#define  RNIC_DBG_PDN_ID_ERR_NUM(n, index)             (g_astRnicStats[index].ulUlPdnIdErr += (n))

/* ����ͳ����Ϣ */
#define  RNIC_DBG_RECV_DL_IPV4_PKT_NUM(n, index)       (g_astRnicStats[index].ulDlRecvIpv4PktNum += (n))
#define  RNIC_DBG_RECV_DL_IPV6_PKT_NUM(n, index)       (g_astRnicStats[index].ulDlRecvIpv6PktNum += (n))
#define  RNIC_DBG_SEND_DL_PKT_NUM(n, index)            (g_astRnicStats[index].ulDlSendPktNum += (n))
#define  RNIC_DBG_SEND_DL_PKT_FAIL_NUM(n, index)       (g_astRnicStats[index].ulDlSendPktFailNum += (n))
#define  RNIC_DBG_RECV_DL_BIG_PKT_NUM(n, index)        (g_astRnicStats[index].ulDlRecvBigPktNum += (n))
#define  RNIC_DBG_DISCARD_DL_PKT_NUM(n, index)         (g_astRnicStats[index].ulDlDiscardPktNum += (n))
#define  RNIC_DBG_ADD_DL_MACHEAD_FAIL_NUM(n, index)    (g_astRnicStats[index].ulDlAddMacHdFailNum += (n))
#define  RNIC_DBG_NETCAED_DL_DISCARD_NUM(n, index)     (g_astRnicStats[index].ulDlNetCardDiscardNum += (n))
#define  RNIC_DBG_RECV_DL_ERR_PKT_NUM(n, index)        (g_astRnicStats[index].ulDlRecvErrPktNum += (n))
#define  RNIC_DBG_NETID_DL_DISCARD_NUM(n, index)       (g_astRnicStats[index].ulDlNetIdDiscardNum += (n))

#define  RNIC_DBG_GET_NAPI_POLL_QUE_DISCARD_PKT_NUM(index)      (g_astRnicStats[index].ulDlNapiPollQueDiscardPktNum)
#define  RNIC_DBG_SET_NAPI_POLL_QUE_DISCARD_PKT_NUM(n, index)   (g_astRnicStats[index].ulDlNapiPollQueDiscardPktNum += (n))

#define RNIC_DBG_SET_SEM_INIT_FLAG(flag)               (g_astRnicStats[0].ulSemInitFlg = (flag))
#define RNIC_DBG_SAVE_BINARY_SEM_ID(sem_id)            (g_astRnicStats[0].hBinarySemId = (sem_id))
#define RNIC_DBG_CREATE_BINARY_SEM_FAIL_NUM(n)         (g_astRnicStats[0].ulCreateBinarySemFailNum += (n))
#define RNIC_DBG_LOCK_BINARY_SEM_FAIL_NUM(n)           (g_astRnicStats[0].ulLockBinarySemFailNum += (n))
#define RNIC_DBG_SAVE_LAST_BIN_SEM_ERR_RSLT(rslt)      (g_astRnicStats[0].ulLastBinarySemErrRslt = (rslt))
#define RNIC_DBG_SAVE_CCPU_RESET_SUCCESS_NUM(n)        (g_astRnicStats[0].ulResetSucessNum += (n))

#define RNIC_DBG_IMSA_PORT_RANGE_NUM_ERR_NUM(n)        (g_stRnicMntnStats.ulImsPortRangeNumErrNum += (n))
#define RNIC_DBG_BIND_PID_WRITE_LEN_ERR_NUM(n)         (g_stRnicMntnStats.ulBindPidWriteLenErrNum += (n))
#define RNIC_DBG_BIND_PID_WRITE_CPY_ERR_NUM(n)         (g_stRnicMntnStats.ulBindPidWriteCpyErrNum += (n))
#define RNIC_DBG_BIND_PID_WRITE_PID_ERR_NUM(n)         (g_stRnicMntnStats.ulBindPidWritePidErrNum += (n))
#define RNIC_DBG_BIND_PID_READ_CPY_ERR_NUM(n)          (g_stRnicMntnStats.ulBindPidReadCpyErrNum += (n))
#define RNIC_DBG_IMSA_SIP_PORT_RANGE_NUM_ERR_NUM(n)    (g_stRnicMntnStats.ulImsSipPortRangeNumErrNum += (n))

#define RNIC_DBG_PRINT_UL_DATA(skb) \
            if (VOS_TRUE == g_ulRnicPrintUlDataFlg) \
            { \
                RNIC_ShowDataFromIpStack(skb); \
            }

#if (VOS_OS_VER == VOS_LINUX)
#define RNIC_DEV_ERR_PRINTK(pcString)     printk(KERN_ERR "%s", pcString);
#else
#define RNIC_DEV_ERR_PRINTK(pcString)     PS_PRINTF("%s", pcString);
#endif


/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/

/*****************************************************************************
  5 ��Ϣͷ����
*****************************************************************************/


/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/


/*****************************************************************************
  7 STRUCT����
*****************************************************************************/

typedef struct
{
    VOS_UINT32                          ulNetTxRmNetIdErrNum;
    VOS_UINT32                          ulSpeTxPortIdErrNum;

    VOS_UINT32                          ulImsPortRangeNumErrNum;                /* IMS�˿������������� */
    VOS_UINT32                          ulBindPidWriteLenErrNum;                /* bind_pid�ڵ�д�������ȴ������ */
    VOS_UINT32                          ulBindPidWriteCpyErrNum;                /* bind_pid�ڵ�д��������������� */
    VOS_UINT32                          ulBindPidWritePidErrNum;                /* bind_pid�ڵ�д����pid�ַ���������� */
    VOS_UINT32                          ulBindPidReadCpyErrNum;                 /* bind_pid�ڵ����������������� */
    VOS_UINT32                          ulImsSipPortRangeNumErrNum;             /* IMS SIP�˿������������� */

} RNIC_MNTN_STATS_STRU;


typedef struct
{
    /* ����ͳ����Ϣ */
    VOS_UINT32                          ulUlRecvIpv4PktNum;                     /* RNIC�յ�����IPV4���ݵĸ��� */
    VOS_UINT32                          ulUlRecvIpv6PktNum;                     /* RNIC�յ�����IPV6���ݵĸ��� */
    VOS_UINT32                          ulUlRecvIpv4v6PktNum;                   /* IPV4V6���ͼ���ʱRNIC�յ��������ݵĸ���(IPV4��IPV6) */
    VOS_UINT32                          ulUlRecvUndiaPktNum;                    /* RNICδ����ʱ�յ��������ݵĸ��� */
    VOS_UINT32                          ulUlSendPktNum;                         /* RNIC���з��͸�ADS���ݵĸ��� */
    VOS_UINT32                          ulUlSendPktFailNum;                     /* RNIC��ADS������������ʧ�ܵĸ��� */
    VOS_UINT32                          ulUlIpv4BrdcstPktNum;                   /* RNICδ���Ϻ�ǰ�����յ�IPV4�㲥���ĸ��� */
    VOS_UINT32                          ulUlImmzcFailPktNum;                    /* RNIC����ת��ΪIMM_ZCʧ�ܵĸ��� */
    VOS_UINT32                          ulUlRmvMacHdrFailPktNum;                /* RNIC����ȥ��MACͷʧ�ܵĸ��� */
    VOS_UINT32                          ulUlNetCardDiscardNum;                  /* RNIC����˽�����ݴ��󶪵��������ݰ��ĸ��� */
    VOS_UINT32                          ulUlFlowCtrlDiscardNum;                 /* RNIC�������ض����������ݰ��ĸ��� */
    VOS_UINT32                          ulUlRecvErrPktNum;                      /* RNIC�յ��������ݰ��ĸ���(��ipv4��ipv6��) */
    VOS_UINT32                          ulUlSendAppDialUpSucc;                  /* RNIC�ɹ��ϱ�APP���貦�� */
    VOS_UINT32                          ulUlSendAppDialUpFail;                  /* RNIC�ϱ�APP���貦��ʧ�� */
    VOS_UINT32                          ulUlSendAppDialDownSucc;                /* RNIC�ɹ��ϱ�APP�Ͽ����� */
    VOS_UINT32                          ulUlSendAppDialDownFail;                /* RNIC�ϱ�APP�Ͽ�����ʧ�� */
    VOS_UINT32                          ulUlRabIdErr;                           /* Rab id���� */
    VOS_UINT32                          ulUlNetIdDiscardNum;                    /* RNIC����ID���󶪵��������ݰ��ĸ��� */
    VOS_UINT32                          ulUlModemIdDiscardNum;                  /* RNIC Modem ID���󶪵��������ݰ��ĸ��� */

    /* ����ͳ����Ϣ */
    VOS_UINT32                          ulDlRecvIpv4PktNum;                     /* RNIC�յ�����IPV4���ݵĸ��� */
    VOS_UINT32                          ulDlRecvIpv6PktNum;                     /* RNIC�յ�����IPV6���ݵĸ��� */
    VOS_UINT32                          ulDlSendPktNum;                         /* RNIC�����������ݵĸ��� */
    VOS_UINT32                          ulDlSendPktFailNum;                     /* RNIC������������ʧ�ܵĸ��� */
    VOS_UINT32                          ulDlRecvBigPktNum;                      /* RNIC�յ��������ݰ�����MTU�ĸ��� */
    VOS_UINT32                          ulDlDiscardPktNum;                      /* RNIC����δ����������ݸ��� */
    VOS_UINT32                          ulDlAddMacHdFailNum;                    /* RNIC���м�MACͷʧ�ܵĸ��� */
    VOS_UINT32                          ulDlNetCardDiscardNum;                  /* RNIC����˽�����ݴ��󶪵��������ݰ��ĸ��� */
    VOS_UINT32                          ulDlRecvErrPktNum;                      /* RNIC�յ��������ݰ��ĸ���(��ipv4��ipv6��) */
    VOS_UINT32                          ulDlNetIdDiscardNum;                    /* RNIC����ID���󶪵��������ݰ��ĸ��� */
    VOS_UINT8                           aucReserved[4];

    /* ����NAPI+GROͳ����Ϣ */
    VOS_UINT32                          ulDlNapiPollQueDiscardPktNum;           /* RNIC��������������NAPI Poll buffer����ʱ��������������޳��������������� */

    /* ��λ�ź�����Ϣ */
    VOS_SEM                             hBinarySemId;                           /* �������ź���ID */
    VOS_UINT32                          ulSemInitFlg;                           /* ��ʼ����ʶ, VOS_TRUE: �ɹ�; VOS_FALSE: ʧ�� */
    VOS_UINT32                          ulCreateBinarySemFailNum;               /* �����������ź���ʧ�ܴ��� */
    VOS_UINT32                          ulLockBinarySemFailNum;                 /* ���������ź���ʧ�ܴ��� */
    VOS_UINT32                          ulLastBinarySemErrRslt;                 /* ���һ�����������ź���ʧ�ܽ�� */
    VOS_UINT32                          ulResetSucessNum;                       /* C�˸�λ�ɹ��Ĵ��� */

    VOS_UINT32                          ulUlPdnIdErr;                           /* Pdn id���� */
}RNIC_STATS_INFO_STRU;


typedef struct
{
    VOS_UINT8                           ucTotlaCnt;
    VOS_UINT8                           ucModemTypeErrCnt;
    VOS_UINT8                           ucRmNetIdErrCnt;
    VOS_UINT8                           ucModemIdErrCnt;
    VOS_UINT8                           ucPdnIdErrCnt;
    VOS_UINT8                           ucRabIdErrCnt;
    VOS_UINT8                           ucRmnetStatusErrCnt;
    VOS_UINT8                           ucIpTypeErrCnt;
    VOS_UINT8                           ucSendErrCnt;
    VOS_UINT8                           ucSuccCnt;
}RNIC_RMNET_CONFIG_CHECK_INFO_STRU;


/*****************************************************************************
  8 ȫ�ֱ�������
*****************************************************************************/

extern RNIC_MNTN_STATS_STRU                    g_stRnicMntnStats;
extern RNIC_STATS_INFO_STRU                    g_astRnicStats[];
extern RNIC_RMNET_CONFIG_CHECK_INFO_STRU       g_stRnicRmnetConfigCheckInfo;
extern VOS_UINT32                              g_ulRnicPrintUlDataFlg;
extern VOS_UINT32                              g_ulRnicPrintDlDataFlg;
extern VOS_UINT32                              g_ulRnicNapiPollQueLen[RNIC_NET_ID_MAX_NUM];

/*****************************************************************************
  8 UNION����
*****************************************************************************/


/*****************************************************************************
  9 OTHERS����
*****************************************************************************/


/*****************************************************************************
  10 ��������
*****************************************************************************/

VOS_VOID RNIC_ShowDataFromIpStack(
    struct sk_buff                     *pstSkb
);

VOS_VOID RNIC_ShowResetStats(VOS_VOID);
VOS_VOID RNIC_Help(VOS_VOID);
VOS_VOID RNIC_ShowDLProcStats(VOS_UINT8 ucRmNetId);
VOS_VOID RNIC_ShowImsPortsBindStats(VOS_VOID);
#if (FEATURE_ON == FEATURE_RNIC_NAPI_GRO)
VOS_VOID RNIC_ShowNapiInfo(VOS_UINT8 ucRmNetId);
#endif

#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of AdsTest.h */

