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

#ifndef __RNIC_MNTN_H__
#define __RNIC_MNTN_H__

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "vos.h"
#include "TafDiagComm.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 �궨��
*****************************************************************************/
#define RNIC_MNTN_COMM_MOUDLE_ID         (DIAG_GEN_MODULE(MODEM_ID_0, DIAG_MODE_COMM))

/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/


/*****************************************************************************
  4 ȫ�ֱ�������
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

/*****************************************************************************
 �ṹ����  : RNIC_MNTN_COMM_HEADER_STRU
 �ṹ˵��  : RNIC��ά�ɲ⹫��ͷ�ṹ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucVer;
    VOS_UINT8                           ucReserved;

    VOS_UINT16                          usReserved0;
    VOS_UINT16                          usReserved1;
    VOS_UINT16                          usReserved2;

} RNIC_MNTN_COMM_HEADER_STRU;

/*****************************************************************************
 �ṹ����  : RNIC_MNTN_UL_PKT_STATS_STRU
 �ṹ˵��  : ���б���ͳ����Ϣ�ϱ��ṹ
*****************************************************************************/
typedef struct
{
    RNIC_MNTN_COMM_HEADER_STRU          stCommHeader;

    VOS_UINT8                           ucRmNetId;
    VOS_UINT8                           aucReserved0;
    VOS_UINT8                           aucReserved1;
    VOS_UINT8                           aucReserved2;
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

} RNIC_MNTN_UL_PKT_STATS_STRU;

/*****************************************************************************
 �ṹ����  : RNIC_MNTN_DL_PKT_STATS_STRU
 �ṹ˵��  : ���б���ͳ����Ϣ�ϱ��ṹ
*****************************************************************************/
typedef struct
{
    RNIC_MNTN_COMM_HEADER_STRU          stCommHeader;

    VOS_UINT8                           ucRmNetId;
    VOS_UINT8                           aucReserved0;
    VOS_UINT8                           aucReserved1;
    VOS_UINT8                           aucReserved2;
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

    VOS_UINT32                          ulDlNapiPollQueDiscardPktNum;           /* RNIC��������������NAPI Poll buffer����ʱ��������������޳��������������� */
    VOS_UINT32                          ulDlNapiWeight;                         /* RNIC��������NAPI Weightֵ */
    VOS_UINT32                          ulDlNapiRecvPktNum;                     /* RNIC��������NAPIÿ����յı����� */

} RNIC_MNTN_DL_PKT_STATS_STRU;


/*****************************************************************************
  8 UNION����
*****************************************************************************/


/*****************************************************************************
  9 OTHERS����
*****************************************************************************/


/*****************************************************************************
  10 ��������
*****************************************************************************/
VOS_VOID RNIC_MNTN_TransReport(
    VOS_UINT32                          ulMsgId,
    VOS_VOID                           *pData,
    VOS_UINT32                          ulLen
);
VOS_VOID RNIC_MNTN_ReportAllStatsInfo(VOS_UINT8 ucRmNetId);


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

#endif /* end of RnicMntn.h */
