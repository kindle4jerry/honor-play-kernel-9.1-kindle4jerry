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
#include  "PsTypeDef.h"
#include  "PsCommonDef.h"
#include  "MnErrorCode.h"
#include  "MnMsgApi.h"
#include  "MnMsgTs.h"
#include "TafStdlib.h"



/*****************************************************************************
  2 ��������
*****************************************************************************/
#define    THIS_FILE_ID        PS_FILE_ID_MNMSG_DECODE_C

/*�����Ű������ŵ�������*/
#define MSG_LONG_MSG_VOLUME                                 255
/*��ͨ����UD����󳤶�*/
#define MSG_MAX_NORM_MSG_LEN                                153

/*****************************************************************************
  3 ���Ͷ���
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucFirstMsgSeqNum;
    VOS_UINT8                           ucMr;
    VOS_UINT16                          usMr;
    VOS_BOOL                            b8bitConcatMsg;
}MN_MSG_CONCENTRATE_MSG_ATTR;

/*****************************************************************************
  4 �궨��
*****************************************************************************/
/*****************************************************************************
  5 ����ʵ��
*****************************************************************************/


/* MN_BcdToAsciiCode��MN_BcdNumberToAscii��MN_MSG_BcdAddrToAscii������TafStdlib.c�� */



VOS_UINT32 MN_MSG_BcdAddrToAscii(
    MN_MSG_BCD_ADDR_STRU                *pstBcdAddr,
    MN_MSG_ASCII_ADDR_STRU              *pstAsciiAddr
)
{
    VOS_UINT32                          ulRet;

    if ((VOS_NULL_PTR == pstBcdAddr)
     || (VOS_NULL_PTR == pstAsciiAddr))
    {
        MN_WARN_LOG("MN_MSG_BcdAddrToAscii: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }

    pstAsciiAddr->enNumType = ((pstBcdAddr->addrType >> 4) & 0x07);
    pstAsciiAddr->enNumPlan = (pstBcdAddr->addrType & 0x0f);
    if((pstBcdAddr->aucBcdNum[pstBcdAddr->ucBcdLen - 1] & 0xF0) != 0xF0)
    {
        pstAsciiAddr->ulLen = pstBcdAddr->ucBcdLen * 2;
    }
    else
    {
        pstAsciiAddr->ulLen = (pstBcdAddr->ucBcdLen * 2) - 1;
    }

    if (pstAsciiAddr->ulLen > MN_MAX_ASCII_ADDRESS_NUM)
    {
        MN_WARN_LOG("MN_MSG_BcdAddrToAscii: length of number is invalid.");
        return MN_ERR_INVALIDPARM;
    }

    ulRet = TAF_STD_ConvertBcdNumberToAscii(pstBcdAddr->aucBcdNum, pstBcdAddr->ucBcdLen, (VOS_CHAR *)pstAsciiAddr->aucAsciiNum);
    if (MN_ERR_NO_ERROR == ulRet)
    {
        return MN_ERR_NO_ERROR;
    }
    else
    {
        return MN_ERR_INVALIDPARM;
    }
}


LOCAL VOS_UINT32 MSG_DecodeTimeStamp(
    const VOS_UINT8                     *pucTimeStamp,
    MN_MSG_TIMESTAMP_STRU               *pstTimeStamp,
    VOS_UINT32                          *pulLen
)
{
    VOS_BOOL                            bNegativeFlag       = VOS_FALSE;
    VOS_UINT8                           ucTimeZone;
    VOS_UINT8                           ucAbsTimeZone;
    VOS_UINT32                          ulRet;
    VOS_UINT8                           ucDateInvalidType;

    if ((VOS_NULL_PTR == pucTimeStamp)
     || (VOS_NULL_PTR == pstTimeStamp)
     || (VOS_NULL_PTR == pulLen))
    {
        MN_ERR_LOG("MSG_DecodeTimeStamp: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }

    MN_MSG_REVERSE_BCD(pstTimeStamp->ucYear, pucTimeStamp[0]);
    MN_MSG_REVERSE_BCD(pstTimeStamp->ucMonth, pucTimeStamp[1]);
    MN_MSG_REVERSE_BCD(pstTimeStamp->ucDay, pucTimeStamp[2]);
    MN_MSG_REVERSE_BCD(pstTimeStamp->ucHour, pucTimeStamp[3]);
    MN_MSG_REVERSE_BCD(pstTimeStamp->ucMinute, pucTimeStamp[4]);
    MN_MSG_REVERSE_BCD(pstTimeStamp->ucSecond, pucTimeStamp[5]);

    ulRet = MN_MSG_ChkDate(pstTimeStamp, &ucDateInvalidType);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        MN_WARN_LOG("MSG_DecodeTimeStamp: Date is invalid.");
    }

    if (0 != (MN_MSG_TIMESTAMP_SIGN_MASK & pucTimeStamp[6]))
    {
        bNegativeFlag = VOS_TRUE;
        /*��ʱ�����ű�־λBIT3��0*/
        ucAbsTimeZone  = pucTimeStamp[6] ^ MN_MSG_TIMESTAMP_SIGN_MASK;
    }
    else
    {
        ucAbsTimeZone = pucTimeStamp[6];
    }

    ulRet = TAF_STD_ConvertBcdToDeciDigit(ucAbsTimeZone, VOS_TRUE, &ucTimeZone);
    if ((MN_ERR_NO_ERROR != ulRet)
     || (ucTimeZone > MN_MSG_MAX_TIMEZONE_VALUE))
    {
        MN_WARN_LOG("MSG_DecodeTimeStamp: Time zone is invalid.");
    }

    pstTimeStamp->cTimezone = (VOS_INT8)ucTimeZone;
    if (VOS_TRUE == bNegativeFlag)
    {
        pstTimeStamp->cTimezone *= (-1);
    }

    *pulLen = MN_MSG_ABSOLUTE_TIMESTAMP_LEN;
    return MN_ERR_NO_ERROR;
}



VOS_UINT32  MSG_ConvertBcdNumberToAscii(
    const VOS_UINT8                    *pucBcdNumber,
    VOS_UINT8                           ucBcdLen,
    VOS_CHAR                           *pcAsciiNumber
)
{
    VOS_CHAR                            cAsciiNumber;
    VOS_UINT8                           ucLoop;
    VOS_UINT8                           ucLen;
    VOS_UINT8                           ucBcdCode;
    VOS_UINT32                          ulRet;

    if ((VOS_NULL_PTR == pucBcdNumber)
     || (VOS_NULL_PTR == pcAsciiNumber))
    {
        return MN_ERR_NULLPTR;
    }

    /*��������ַ�����ȥ����Ч��0XFF����*/
    while (ucBcdLen > 1)
    {
        if (0xFF == pucBcdNumber[ucBcdLen - 1])
        {
            ucBcdLen--;
        }
        else
        {
            break;
        }
    }

    /*�ж�pucBcdAddress��ָ����ַ��������һ���ֽڵĸ�λ�Ƿ�Ϊ1111��
    ����ǣ�˵������λ��Ϊ����������Ϊż��*/
    if ((pucBcdNumber[ucBcdLen - 1] & 0xF0) == 0xF0)
    {
        ucLen = (VOS_UINT8)((ucBcdLen * 2) - 1);
    }
    else
    {
        ucLen = (VOS_UINT8)(ucBcdLen * 2);
    }

    /*��������*/

    for (ucLoop = 0; ucLoop < ucLen; ucLoop++)
    {
        /*�жϵ�ǰ�����������λ���뻹��ż��λ���룬��0��ʼ����ż��*/
        if (1 == (ucLoop % 2))
        {
            /*���������λ���룬��ȡ��4λ��ֵ*/
            ucBcdCode = ((pucBcdNumber[(ucLoop / 2)] >> 4) & 0x0F);
        }
        else
        {
            /*�����ż��λ���룬��ȡ��4λ��ֵ*/
            ucBcdCode = (pucBcdNumber[(ucLoop / 2)] & 0x0F);
        }

        /* ������������ת����Ascii����ʽ, ��Ч���ֵ�ַ�F���ַ���0����� */
    	cAsciiNumber = 0;

        ulRet = TAF_STD_ConvertBcdCodeToAscii(ucBcdCode, &cAsciiNumber);
		if (MN_ERR_NO_ERROR != ulRet)
		{
			if (MN_ERR_INVALID_BCD != ulRet)
			{
				return ulRet;
			}

			MN_WARN_LOG("MSG_ConvertBcdNumberToAscii: The BCD number is invalid.");
			cAsciiNumber    = '0';
		}

		pcAsciiNumber[ucLoop] = cAsciiNumber;

	}

    pcAsciiNumber[ucLoop] = '\0';      /*�ַ���ĩβΪ0*/

    return MN_ERR_NO_ERROR;
}


VOS_UINT32 MN_MSG_DecodeAddress(
    const VOS_UINT8                     *pucAddr,
    VOS_BOOL                            bRpAddr,
    MN_MSG_ASCII_ADDR_STRU              *pstAsciiAddr,
    VOS_UINT32                          *pulLen
)
{
    VOS_UINT32                          ulRet;
    VOS_UINT32                          ulPos               = 0;
    VOS_UINT8                           ucBcdLen;

    if ((VOS_NULL_PTR == pulLen)
     || (VOS_NULL_PTR == pucAddr)
     || (VOS_NULL_PTR == pstAsciiAddr))
    {
        MN_ERR_LOG("MN_MSG_DecodeAddress: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }

    TAF_MEM_SET_S(pstAsciiAddr, sizeof(MN_MSG_ASCII_ADDR_STRU), 0x00, sizeof(MN_MSG_ASCII_ADDR_STRU));
    /*3GPP 24011 RP DATA (Network to Mobile Station)*/
    if (VOS_TRUE == bRpAddr)
    {
        /*�ӳ�����ȥ���������ͼ��������͵ĳ���(1 OCTET)*/
        ucBcdLen                = pucAddr[ulPos++];
        /*��ַ����Ϊ0ֱ�ӷ���*/
        if (0 == ucBcdLen)
        {
            *pulLen = ulPos;
            return MN_ERR_NO_ERROR;
        }
        ucBcdLen -= 1;

        if ((0 == ucBcdLen)
         || (ucBcdLen > MN_MSG_MAX_BCD_NUM_LEN))
        {
            MN_WARN_LOG("MN_MSG_DecodeAddress:Invalid RP-ADDR.");
            return MN_ERR_CLASS_SMS_INVALID_SCADDR;
        }

        if ((pucAddr[(VOS_ULONG)((ulPos + 1) + (ucBcdLen - (VOS_UINT8)1))] & 0xF0) != 0xF0)
        {
            pstAsciiAddr->ulLen = ucBcdLen * 2;
        }
        else
        {
            pstAsciiAddr->ulLen = (ucBcdLen * 2) - 1;
        }
    }
    else
    {
        pstAsciiAddr->ulLen     = pucAddr[ulPos++];
        if (0 == pstAsciiAddr->ulLen)
        {
            pstAsciiAddr->enNumPlan = pucAddr[ulPos] &  0x0f;
            pstAsciiAddr->enNumType = (pucAddr[ulPos] >> 4) &  0x07;
            *pulLen = ulPos + 1;
            return MN_ERR_NO_ERROR;
        }

        ucBcdLen                = (VOS_UINT8)((pstAsciiAddr->ulLen + 1)/2);
    }

    if ((0 == ucBcdLen)
     || (ucBcdLen > MN_MSG_MAX_BCD_NUM_LEN))
    {
        MN_WARN_LOG("MN_MSG_DecodeAddress: invalid address length.");
        return MN_ERR_CLASS_SMS_INVALID_ADDRLEN;
    }

    pstAsciiAddr->enNumPlan = pucAddr[ulPos] &  0x0f;
    pstAsciiAddr->enNumType = (pucAddr[ulPos] >> 4) &  0x07;

    /*��������,���żƻ�������Ч�Լ��*/
    ulRet = MN_ChkNumPlan(pstAsciiAddr->enNumPlan);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        MN_WARN_LOG("MN_MSG_DecodeAddress: Numbering plan is invalid");
        return ulRet;
    }
    ulRet = MN_ChkNumType(pstAsciiAddr->enNumType);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        MN_WARN_LOG("MN_MSG_DecodeAddress: Number type is invalid");
        return ulRet;
    }

    ulPos++;
    if ((VOS_TRUE != bRpAddr)
     && (MN_MSG_TON_ALPHANUMERIC == pstAsciiAddr->enNumType))
    {
        ulRet = TAF_STD_UnPack7Bit(&(pucAddr[ulPos]),
                                   pstAsciiAddr->ulLen,
                                   0,
                                   pstAsciiAddr->aucAsciiNum);
        if (VOS_OK != ulRet)
        {
            ulRet = MN_ERR_CLASS_INVALID_TP_ADDRESS;
        }
        else
        {
            ulRet = MN_ERR_NO_ERROR;
        }

        pstAsciiAddr->ulLen = (pstAsciiAddr->ulLen * 4)/7;
    }
    else
    {
        ulRet = TAF_STD_ConvertBcdNumberToAscii(&(pucAddr[ulPos]),
                                    ucBcdLen,
                                    (VOS_CHAR *)pstAsciiAddr->aucAsciiNum);
		if (MN_ERR_INVALID_BCD == ulRet)
		{
			ulRet = MSG_ConvertBcdNumberToAscii(&(pucAddr[ulPos]),
                                                    ucBcdLen,
                                                    (VOS_CHAR *)pstAsciiAddr->aucAsciiNum);
		}
    }
    *pulLen = 2 + ucBcdLen;

    return ulRet;
}


VOS_UINT32 MN_MSG_DecodeValidPeriod(
    MN_MSG_VALID_PERIOD_ENUM_U8         enVpf,
    const VOS_UINT8                     *pucValidPeriod,
    MN_MSG_VALID_PERIOD_STRU            *pstValidPeriod,
    VOS_UINT32                          *pulLen
)
{
    VOS_UINT32                          ulRet               = MN_ERR_NO_ERROR;

    if ((VOS_NULL_PTR == pulLen)
     || (VOS_NULL_PTR == pucValidPeriod)
     || (VOS_NULL_PTR == pstValidPeriod))
    {
        MN_ERR_LOG("MN_MSG_DecodeValidPeriod: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }

    switch (enVpf)
    {
        case MN_MSG_VALID_PERIOD_NONE:
            *pulLen = 0;
            break;
        case MN_MSG_VALID_PERIOD_RELATIVE:
            *pulLen = 1;
            pstValidPeriod->u.ucOtherTime = pucValidPeriod[0];
            /* MN_MSG_DecodeRelatTime(pucValidPeriod[0], &pstValidPeriod->u.stAbsoluteTime); */
            break;
        case MN_MSG_VALID_PERIOD_ABSOLUTE:
            ulRet = MSG_DecodeTimeStamp((VOS_UINT8 *)pucValidPeriod,
                                        &(pstValidPeriod->u.stAbsoluteTime),
                                        pulLen);
            break;
        default:
            MN_WARN_LOG("MN_MSG_DecodeValidPeriod: invalid VP flag.");
            ulRet = MN_ERR_CLASS_SMS_INVALID_VPF;
            break;
    }
    pstValidPeriod->enValidPeriod = enVpf;

    return ulRet;
}


LOCAL VOS_UINT32 MSG_DecodeUdhConcat8(
    const VOS_UINT8                     ucUdhlMax,
    const VOS_UINT8                    *pucUdh,
    MN_MSG_UDH_CONCAT_8_STRU           *pstConcatenatedSms,
    VOS_UINT8                          *pucIeiLen
)
{
    VOS_UINT8                           ucPos               = 1;
    VOS_UINT8                           ucIeiLen            = 0;

    if ((VOS_NULL_PTR == pucUdh)
     || (VOS_NULL_PTR == pstConcatenatedSms)
     || (VOS_NULL_PTR == pucIeiLen))
    {
        MN_ERR_LOG("MSG_DecodeUdhConcat8: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }

    if ((MN_MSG_UDH_CONCAT_8_IEL + MN_MSG_IE_HEAD_LEN) > ucUdhlMax)
    {
        MN_WARN_LOG("MSG_DecodeUdhConcat8: invalid length.");
        return MN_ERR_CLASS_INVALID_TP_UD;
    }

    ucIeiLen                        = pucUdh[ucPos++];
    if (MN_MSG_UDH_CONCAT_8_IEL != ucIeiLen)
    {
        MN_WARN_LOG("MSG_DecodeUdhConcat8: invalid IE length.");
        return MN_ERR_CLASS_INVALID_TP_UD;
    }

    pstConcatenatedSms->ucMr        = pucUdh[ucPos++];
    pstConcatenatedSms->ucTotalNum  = pucUdh[ucPos++];
    pstConcatenatedSms->ucSeqNum    = pucUdh[ucPos++];

    ucIeiLen += 2;

    *pucIeiLen = ucIeiLen;
    return MN_ERR_NO_ERROR;
}


LOCAL VOS_UINT32 MSG_DecodeUdhSpecialSms(
    const VOS_UINT8                     ucUdhlMax,
    const VOS_UINT8                    *pucUdh,
    MN_MSG_UDH_SPECIAL_SMS_STRU        *pstSpecialSms,
    VOS_UINT8                          *pucIeiLen
)
{
    VOS_UINT8                           ucPos               = 1;
    VOS_UINT8                           ucIeiLen            = 0;

    if ((VOS_NULL_PTR == pucUdh)
     || (VOS_NULL_PTR == pstSpecialSms)
     || (VOS_NULL_PTR == pucIeiLen))
    {
        MN_ERR_LOG("MSG_DecodeUdhSpecialSms: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }

    if ((MN_MSG_UDH_SPECIAL_SM_IEL + MN_MSG_IE_HEAD_LEN) > ucUdhlMax)
    {
        MN_WARN_LOG("MSG_DecodeUdhSpecialSms: invalid length.");
        return MN_ERR_CLASS_INVALID_TP_UD;
    }

    ucIeiLen = pucUdh[ucPos++];
    if (MN_MSG_UDH_SPECIAL_SM_IEL != ucIeiLen)
    {
        MN_WARN_LOG("MSG_DecodeUdhSpecialSms: invalid IE length.");
        return MN_ERR_CLASS_INVALID_TP_UD;
    }
    if (0 != (pucUdh[ucPos] & 0x80))
    {
        pstSpecialSms->enMsgWaiting = MN_MSG_MSG_WAITING_STORE;
    }
    else
    {
        pstSpecialSms->enMsgWaiting = MN_MSG_MSG_WAITING_DISCARD;
    }
    pstSpecialSms->enProfileId      = (pucUdh[ucPos] >> 5) & 0x03;
    pstSpecialSms->enExtMsgInd      = (pucUdh[ucPos] >> 2) & 0x07;
    pstSpecialSms->enMsgWaitingKind = pucUdh[ucPos] & 0x03;
    ucPos++;
    pstSpecialSms->ucMsgCount       = pucUdh[ucPos++];

    ucIeiLen += 2;

    *pucIeiLen = ucIeiLen;

    return MN_ERR_NO_ERROR;
}

/*
MSG_DecodeUdhAppPort_8
MSG_DecodeUdhAppPort_16
MSG_DecodeUdhSmscCtrl
MSG_DecodeUdhSourceInd
MSG_DecodeUdhUserDefSound
MSG_DecodeUdhPreDefAnim
MSG_DecodeUdhTextFormat
MSG_DecodeUdhSmallAnim
MSG_DecodeUdhLargePic
MSG_DecodeUdhSmallPic
MSG_DecodeUdhVarPic
MSG_DecodeUdhUserPrompt
MSG_DecodeUdhRfc822
MSG_DecodeEo
MSG_DecodeReo
MSG_DecodeCc
MSG_DecodeObjDistrInd
MSG_DecodeHyperLinkFormat
MSG_DecodeReplyAddress
MN_MSG_UnpackSmWithOutUdh
MSG_DecodeWvgObj
MSG_DecodeUdhConcat16

*/


LOCAL VOS_UINT32 MSG_DecodeUdhOther(
    const VOS_UINT8                     ucUdhlMax,
    const VOS_UINT8                    *pucUdh,
    MN_MSG_UDH_OTHER_STRU              *pstOther,
    VOS_UINT8                          *pucIeiLen
)
{
    VOS_UINT8                           ucPos;
    VOS_UINT8                           ucIeiLen            = 0;

    if ((VOS_NULL_PTR == pucUdh)
     || (VOS_NULL_PTR == pstOther)
     || (VOS_NULL_PTR == pucIeiLen))
    {
        MN_ERR_LOG("MSG_DecodeUdhOther: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }

    ucPos = 0;

    pstOther->enUdhType = pucUdh[ucPos];
    ucPos++;

    ucIeiLen            = pucUdh[ucPos];

    if ((ucIeiLen + MN_MSG_IE_HEAD_LEN) > MN_MSG_UDH_OTHER_SIZE)
    {
        MN_WARN_LOG("MSG_DecodeUdhOther: invalid length.");
        return MN_ERR_CLASS_INVALID_TP_UD;
    }

    if ((ucIeiLen + MN_MSG_IE_HEAD_LEN) > ucUdhlMax)
    {
        MN_WARN_LOG("MSG_DecodeUdhOther: invalid IE length.");
        return MN_ERR_CLASS_INVALID_TP_UD;
    }

    pstOther->ucLen                 = ucIeiLen;
    TAF_MEM_CPY_S(pstOther->aucData, sizeof(pstOther->aucData), (pucUdh + 2), pstOther->ucLen);

    ucIeiLen += 2;

    *pucIeiLen = ucIeiLen;

    return MN_ERR_NO_ERROR;
}


LOCAL VOS_UINT32  MSG_DecodeUdh(
    const VOS_UINT8                     *pucUdh,
    VOS_UINT8                           ucUdhl,
    VOS_UINT8                           *pucNumofHeaders,
    MN_MSG_USER_HEADER_TYPE_STRU        *pstUserDataHeader
)
{
    VOS_UINT32                          ulLen;
    VOS_UINT8                           ucIeiLen;
    VOS_UINT32                          ulRet;
    VOS_UINT8                           ucWaitDecodeLen;

    if ((VOS_NULL_PTR == pucUdh)
     || (VOS_NULL_PTR == pucNumofHeaders)
     || (VOS_NULL_PTR == pstUserDataHeader))
    {
        MN_ERR_LOG("MSG_DecodeUdh: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }

    ulLen            = 0;
    ucWaitDecodeLen  = ucUdhl;
    *pucNumofHeaders = 0;

    while (ulLen < ucUdhl)
    {
        if (*pucNumofHeaders >= MN_MSG_MAX_UDH_NUM)
        {
            MN_WARN_LOG("MSG_DecodeUdh: UDH number is overflow.");
            return MN_ERR_CLASS_INVALID_TP_UD;
        }
        ucWaitDecodeLen = ucUdhl - (VOS_UINT8)ulLen;
        if (ucWaitDecodeLen < MN_MSG_IE_HEAD_LEN)
        {
            MN_WARN_LOG("MSG_DecodeUdh: IE length is invalid.");
            return MN_ERR_CLASS_INVALID_TP_UD;
        }
        pstUserDataHeader->enHeaderID = pucUdh[ulLen];
        switch (pstUserDataHeader->enHeaderID)
        {
            case MN_MSG_UDH_CONCAT_8:
                ulRet = MSG_DecodeUdhConcat8(ucWaitDecodeLen,
                                             &pucUdh[ulLen],
                                             &pstUserDataHeader->u.stConcat_8,
                                             &ucIeiLen);
                break;
            case MN_MSG_UDH_SPECIAL_SM:
                ulRet = MSG_DecodeUdhSpecialSms(ucWaitDecodeLen,
                                                &pucUdh[ulLen],
                                                &pstUserDataHeader->u.stSpecial_Sms,
                                                &ucIeiLen);
                break;
            /*
            MN_MSG_UDH_CONCAT_16
            MN_MSG_UDH_PORT_8
            MN_MSG_UDH_PORT_16
            MN_MSG_UDH_SMSC_CTRL
            MN_MSG_UDH_TEXT_FORMATING
            MN_MSG_UDH_PRE_DEF_SOUND
            MN_MSG_UDH_SOURCE
            MN_MSG_UDH_USER_DEF_SOUND
            MN_MSG_UDH_PRE_DEF_ANIM
            MN_MSG_UDH_LARGE_ANIM
            MN_MSG_UDH_SMALL_ANIM
            MN_MSG_UDH_LARGE_PIC
            MN_MSG_UDH_SMALL_PIC
            MN_MSG_UDH_VAR_PIC
            MN_MSG_UDH_USER_PROMPT
            MN_MSG_UDH_RFC822
            MN_MSG_UDH_EO
            MN_MSG_UDH_REO
            MN_MSG_UDH_OBJ_DISTR_IND
            MN_MSG_UDH_HYPERLINK_FORMAT
            MN_MSG_UDH_REPLY_ADDR
            MN_MSG_UDH_CHAR_SIZE_WVG_OBJ
            MN_MSG_UDH_STD_WVG_OBJ
            */
            default:
                ulRet = MSG_DecodeUdhOther(ucWaitDecodeLen,
                                           &pucUdh[ulLen],
                                           &pstUserDataHeader->u.stOther,
                                           &ucIeiLen);
                break;

        }

        if (MN_ERR_NO_ERROR != ulRet)
        {
            return ulRet;
        }

        if ((0 == ucIeiLen)
         || (ucIeiLen > (MN_MSG_UINT8_MAX - ulLen)))
        {
            MN_WARN_LOG("MSG_DecodeUdh: IE length is overflow.");
            return MN_ERR_CLASS_INVALID_TP_UD;
        }

        ulLen += ucIeiLen;


        (*pucNumofHeaders)++;
        pstUserDataHeader++;

    }
    return MN_ERR_NO_ERROR;

}


LOCAL VOS_UINT32 MN_MSG_UnpackSmWithOutUdh(
    const MN_MSG_DCS_CODE_STRU          *pstDcsInfo,
    VOS_UINT8                           *pucUserData,
    VOS_UINT8                           *pucUnpackedSm
)
{
    VOS_UINT32                          ulRet;
    VOS_UINT8                           ucUdl;
    VOS_UINT32                          ulPos;

    ulPos = 0;
    ucUdl = pucUserData[ulPos];
    ulPos++;
    /*decode SM, Refer to 23040 9.2.3.16*/
    if ((MN_MSG_MSG_CODING_7_BIT == pstDcsInfo->enMsgCoding)
     && (VOS_TRUE != pstDcsInfo->bCompressed))
    {
        ulRet = TAF_STD_UnPack7Bit(&pucUserData[ulPos],
                                   ucUdl,
                                   0,
                                   pucUnpackedSm);

        if (VOS_OK != ulRet)
        {
            ulRet = MN_ERR_CLASS_INVALID_TP_UD;
        }
        else
        {
            ulRet = MN_ERR_NO_ERROR;
        }
    }
    else
    {
        TAF_MEM_CPY_S(pucUnpackedSm, MN_MSG_MAX_LEN, &pucUserData[ulPos], ucUdl);
        ulRet = MN_ERR_NO_ERROR;
    }

    return ulRet;

}


LOCAL VOS_UINT32 MN_MSG_UpackSmWithUdh(
    const MN_MSG_DCS_CODE_STRU         *pstDcsInfo,
    VOS_UINT8                          *pucUserData,
    VOS_BOOL                            bLongMsg,
    VOS_VOID                           *pUserData
)
{
    MN_MSG_USER_DATA_STRU              *pstUserData;
    MN_MSG_LONG_USER_DATA_STRU         *pstLongMsgUserData;
    VOS_UINT32                          ulRet;
    VOS_UINT32                          ulPos;
    VOS_UINT8                           ucUdhl;
    VOS_UINT8                           ucUdl;
    VOS_UINT8                           ucFillBit;
    VOS_UINT8                           *pucNumofHeaders;
    MN_MSG_USER_HEADER_TYPE_STRU        *pstUserDataHeader;
    VOS_UINT8                           *pucUnpackedSm;
    VOS_UINT32                          *pulLen;

    if (VOS_TRUE == bLongMsg)
    {
        pstLongMsgUserData = (MN_MSG_LONG_USER_DATA_STRU *)pUserData;
        pucNumofHeaders    = &pstLongMsgUserData->ucNumofHeaders;
        pstUserDataHeader  = pstLongMsgUserData->astUserDataHeader;
        pucUnpackedSm      = pstLongMsgUserData->pucOrgData;
        pulLen             = &pstLongMsgUserData->ulLen;
    }
    else
    {
        pstUserData        = (MN_MSG_USER_DATA_STRU *)pUserData;
        pucNumofHeaders    = &pstUserData->ucNumofHeaders;
        pstUserDataHeader  = pstUserData->astUserDataHeader;
        pucUnpackedSm      = pstUserData->aucOrgData;
        pulLen             = &pstUserData->ulLen;
    }

    ulPos   = 0;
    ucUdl   = pucUserData[ulPos++];
    ucUdhl  = pucUserData[ulPos++];
    ulRet   = MSG_DecodeUdh(&(pucUserData[ulPos]),
                            ucUdhl,
                            pucNumofHeaders,
                            pstUserDataHeader);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        return ulRet;
    }

    /*�������������±�����UDHL UDH֮�� */
    ulPos += ucUdhl;

    /*decode SM, Refer to 23040 9.2.3.16*/
    if ((MN_MSG_MSG_CODING_7_BIT == pstDcsInfo->enMsgCoding)
     && (VOS_TRUE != pstDcsInfo->bCompressed))
    {
        ucFillBit = (7 - (((ucUdhl + 1) * 8) % 7)) % 7;
        if (ucUdl < ((((ucUdhl + 1) * 8) + 6)/7))
        {
            MN_WARN_LOG("MN_MSG_UpackSmWithUdh: udhl is invalid.");
            return MN_ERR_CLASS_SMS_MSGLEN_OVERFLOW;
        }
        *pulLen = ucUdl - ((((ucUdhl + 1) * 8) + 6)/7);
        ulRet = TAF_STD_UnPack7Bit(&(pucUserData[ulPos]),
                                   *pulLen,
                                   ucFillBit,
                                   pucUnpackedSm);
        if (VOS_OK != ulRet)
        {
            ulRet = MN_ERR_CLASS_INVALID_TP_UD;
        }
        else
        {
            ulRet = MN_ERR_NO_ERROR;
        }
    }
    else
    {

        if ((ucUdhl + 1) > ucUdl)
        {
            return MN_ERR_CLASS_SMS_MSGLEN_OVERFLOW;
        }

        *pulLen = ucUdl - (ucUdhl + 1);

        TAF_MEM_CPY_S(pucUnpackedSm,
                   MN_MSG_MAX_LEN,
                   &(pucUserData[ulPos]),
                   *pulLen);
        ulRet = MN_ERR_NO_ERROR;
    }

    return ulRet;
}


LOCAL VOS_UINT32 MSG_DecodeUserData_ForUsimMsg(
    VOS_BOOL                            bUserDataHeaderInd,
    const MN_MSG_DCS_CODE_STRU          *pstDcsInfo,
    VOS_UINT8                           *pucUserData,
    MN_MSG_LONG_USER_DATA_STRU          *pstUserData
)
{
    VOS_UINT32                          ulRet;
    VOS_UINT32                          ulPos               = 0;
    VOS_UINT8                           ucUdl;

    if ((VOS_NULL_PTR == pstDcsInfo)
     || (VOS_NULL_PTR == pucUserData)
     || (VOS_NULL_PTR == pstUserData))
    {
        MN_ERR_LOG("MSG_DecodeUserData_ForUsimMsg: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }

    pstUserData->ucNumofHeaders = 0;
    TAF_MEM_SET_S(pstUserData->astUserDataHeader,
                          sizeof(pstUserData->astUserDataHeader),
                          0x00,
                          (VOS_SIZE_T)(sizeof(MN_MSG_USER_HEADER_TYPE_STRU) * MN_MSG_MAX_UDH_NUM));
    ucUdl  = pucUserData[ulPos];
    if (0 == ucUdl)
    {
        pstUserData->ulLen = 0;
        return MN_ERR_NO_ERROR;
    }

    if (VOS_TRUE == bUserDataHeaderInd)
    {
        ulRet = MN_MSG_UpackSmWithUdh(pstDcsInfo,
                                      &(pucUserData[ulPos]),
                                      VOS_TRUE,
                                      (VOS_VOID *)pstUserData);
    }
    else
    {
        /*decode SM, Refer to 23040 9.2.3.16*/
        pstUserData->ulLen = ucUdl;
		
        ulRet = MN_MSG_UnpackSmWithOutUdh(pstDcsInfo,
                                          &(pucUserData[ulPos]),
                                          pstUserData->pucOrgData);

    }

    return ulRet;
}


VOS_UINT32 MN_MSG_Decode_UsimMsg(
    VOS_UINT8                           *pucData,
    VOS_UINT32                          ulLen,
    MN_MSG_SUBMIT_LONG_STRU             *pstLongSubmit
)
{
    VOS_UINT32                          ulRet               = MN_ERR_NO_ERROR;
    VOS_UINT32                          ulPos               = 0;
    VOS_UINT32                          ulDaLen;
    VOS_UINT32                          ulVpLen;
    MN_MSG_LONG_USER_DATA_STRU          *pstLongUserData;

    if ((VOS_NULL_PTR == pucData)
    || (VOS_NULL_PTR == pstLongSubmit))
    {
        MN_ERR_LOG("MN_MSG_Decode_UsimMsg: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }

    /*b7  b6   b5   b4   b3  b2  b1  b0
      RP  UDHI SRR  VPF      RD  MTI
      0   0    0    2        1   2
      TP MTI TP RD TP VPF TP RP TP UDHI TP SRR*/
    /*TP MTI ignore 23040 9.2.3.1 ��дbit0bit1:MIT     0011 0001 */

    /*TP RD  23040 9.2.3.25*/
    MSG_GET_TP_RD(pstLongSubmit->bRejectDuplicates, pucData[ulPos]);
    /*TP VPF 23040 9.2.3.3*/
    MSG_GET_TP_VPF(pstLongSubmit->stValidPeriod.enValidPeriod, pucData[ulPos]);
    /*TP RP  23040 9.2.3.17*/
    MSG_GET_TP_RP(pstLongSubmit->bReplayPath, pucData[ulPos]);
    /*TP UDHI23040 9.2.3.23*/
    MSG_GET_TP_UDHI(pstLongSubmit->bUserDataHeaderInd, pucData[ulPos]);
    /*TP SRR 23040 9.2.3.5*/
    MSG_GET_TP_SRR(pstLongSubmit->bStaRptReq, pucData[ulPos]);
    ulPos++;

    /*TP MR*/
    pstLongSubmit->ucMr = pucData[ulPos++];

    /*TP DA* Refer to 9.1.2.5*/
    ulRet = MN_MSG_DecodeAddress(&(pucData[ulPos]),
                                 VOS_FALSE,
                                 &(pstLongSubmit->stDestAddr),
                                 &ulDaLen);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        MN_WARN_LOG("MN_MSG_Decode_UsimMsg: Fail to MN_MSG_DecodeAddress.");
        return ulRet;
    }
    ulPos += ulDaLen;

    /*TP PID*/
    pstLongSubmit->enPid = pucData[ulPos++];

    /*TP DCS 23038 4 */
    ulRet = MN_MSG_DecodeDcs(pucData[ulPos],
                                                  &(pstLongSubmit->stDcs));
    if (MN_ERR_NO_ERROR != ulRet)
    {
        MN_WARN_LOG("MN_MSG_Decode_UsimMsg: Fail to MN_MSG_DecodeDcs..");
        return ulRet;
    }
    ulPos ++;

    /*TP VP*/
    ulRet = MN_MSG_DecodeValidPeriod(pstLongSubmit->stValidPeriod.enValidPeriod,
                                     &(pucData[ulPos]),
                                     &(pstLongSubmit->stValidPeriod),
                                     & ulVpLen);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        MN_WARN_LOG("MN_MSG_Decode_UsimMsg: Fail to MN_MSG_DecodeValidPeriod.");
        return ulRet;
    }
    ulPos += ulVpLen;

    /*UDL UD*/
    pstLongUserData = &(pstLongSubmit->stLongUserData);
    ulRet = MSG_DecodeUserData_ForUsimMsg(pstLongSubmit->bUserDataHeaderInd,
                                          &(pstLongSubmit->stDcs),
                                          (VOS_UINT8 *)&(pucData[ulPos]),
                                          pstLongUserData);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        MN_NORM_LOG("MN_MSG_Decode_UsimMsg: Fail to MSG_DecodeUserData_ForUsimMsg.");
        return ulRet;
    }

    return MN_ERR_NO_ERROR;
}


LOCAL VOS_UINT32 MSG_DecodeUserData(
    VOS_BOOL                            bUserDataHeaderInd,
    const MN_MSG_DCS_CODE_STRU          *pstDcsInfo,
    VOS_UINT8                           *pucUserData,
    MN_MSG_USER_DATA_STRU               *pstUserData
)
{
    VOS_UINT32                          ulRet;
    VOS_UINT32                          ulPos               = 0;
    VOS_UINT8                           ucUdl;

    if ((VOS_NULL_PTR == pstDcsInfo)
     || (VOS_NULL_PTR == pucUserData)
     || (VOS_NULL_PTR == pstUserData))
    {
        MN_ERR_LOG("MSG_DecodeUserData: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }

    ucUdl  = pucUserData[ulPos];
    if (0 == ucUdl)
    {
        pstUserData->ulLen = 0;
        return MN_ERR_NO_ERROR;
    }

    /*UDL������Ч�Լ��*/
    if ((MN_MSG_MSG_CODING_7_BIT == pstDcsInfo->enMsgCoding)
     && (VOS_TRUE != pstDcsInfo->bCompressed))
    {
        if (ucUdl > MN_MSG_MAX_7_BIT_LEN)
        {
            MN_WARN_LOG("MSG_DecodeUserData: udl is invalid.");
            return MN_ERR_CLASS_SMS_MSGLEN_OVERFLOW;
        }
    }
    else
    {
        if (ucUdl > MN_MSG_MAX_8_BIT_LEN)
        {
            MN_WARN_LOG("MSG_DecodeUserData: udl is invalid.");
            return MN_ERR_CLASS_SMS_MSGLEN_OVERFLOW;
        }
    }

    if (VOS_TRUE == bUserDataHeaderInd)
    {
        ulRet = MN_MSG_UpackSmWithUdh(pstDcsInfo,
                                      &(pucUserData[ulPos]),
                                      VOS_FALSE,
                                      (VOS_VOID *)pstUserData);
        if (MN_ERR_NO_ERROR == ulRet)
        {
            return ulRet;
        }
        else
        {
            TAF_MEM_SET_S(pstUserData, sizeof(MN_MSG_USER_DATA_STRU), 0x00, sizeof(MN_MSG_USER_DATA_STRU));
        }
    }

    /*decode SM, Refer to 23040 9.2.3.16*/
    pstUserData->ulLen = ucUdl;
	
    ulRet = MN_MSG_UnpackSmWithOutUdh(pstDcsInfo,
                                      &(pucUserData[ulPos]),
                                      pstUserData->aucOrgData);


    return ulRet;
}


LOCAL VOS_UINT32   MSG_DecodeDeliver(
    const MN_MSG_RAW_TS_DATA_STRU       *pstSmsRawDataInfo,
    MN_MSG_DELIVER_STRU                 *pstSmsDeliverInfo
)
{
    VOS_UINT32                          ulPos               = 0;
    VOS_UINT32                          ulOaLen;
    VOS_UINT32                          ulRet;
    VOS_UINT32                          ulSctsLen;

    if ((VOS_NULL_PTR == pstSmsRawDataInfo)
     || (VOS_NULL_PTR == pstSmsDeliverInfo))
    {
        MN_ERR_LOG("MSG_DecodeDeliver: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }

    TAF_MEM_SET_S(pstSmsDeliverInfo, sizeof(MN_MSG_DELIVER_STRU), 0x00, sizeof(MN_MSG_DELIVER_STRU));

    /*decode fo:TP MTI TP MMS TP RP TP UDHI TP SRI*/
    MSG_GET_TP_MMS(pstSmsDeliverInfo->bMoreMsg, pstSmsRawDataInfo->aucData[ulPos]);
    MSG_GET_TP_RP(pstSmsDeliverInfo->bReplayPath, pstSmsRawDataInfo->aucData[ulPos]);
    MSG_GET_TP_UDHI(pstSmsDeliverInfo->bUserDataHeaderInd, pstSmsRawDataInfo->aucData[ulPos]);
    MSG_GET_TP_SRI(pstSmsDeliverInfo->bStaRptInd, pstSmsRawDataInfo->aucData[ulPos]);

    ulPos++;

    /*decode TP OA:*/
    ulRet = MN_MSG_DecodeAddress(&(pstSmsRawDataInfo->aucData[ulPos]),
                                 VOS_FALSE,
                                 &(pstSmsDeliverInfo->stOrigAddr),
                                 &ulOaLen);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        return ulRet;
    }
    ulPos += ulOaLen;

    /*decode TP PID*/
    pstSmsDeliverInfo->enPid = pstSmsRawDataInfo->aucData[ulPos++];

    /*decode TP DCS*/
    ulRet = MN_MSG_DecodeDcs(pstSmsRawDataInfo->aucData[ulPos],
                             &pstSmsDeliverInfo->stDcs);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        return ulRet;
    }
    ulPos++;

    /*decode TP SCTS*/
    ulRet = MSG_DecodeTimeStamp((VOS_UINT8 *)&(pstSmsRawDataInfo->aucData[ulPos]),
                                &(pstSmsDeliverInfo->stTimeStamp),
                                &ulSctsLen);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        MN_WARN_LOG("MSG_DecodeDeliver: Invalid SCTS.");
        return ulRet;
    }
    ulPos += ulSctsLen;/*TAF_SMS_SCTS_LEN 7*/

    /*decode TP UDL TP UD*/
    ulRet = MSG_DecodeUserData(pstSmsDeliverInfo->bUserDataHeaderInd,
                               &(pstSmsDeliverInfo->stDcs),
                               (VOS_UINT8 *)&(pstSmsRawDataInfo->aucData[ulPos]),
                               &(pstSmsDeliverInfo->stUserData));

    return ulRet;
}



LOCAL VOS_UINT32   MSG_DecodeDeliverRptAck(
    const MN_MSG_RAW_TS_DATA_STRU       *pstSmsRawDataInfo,
    MN_MSG_DELIVER_RPT_ACK_STRU         *pstSmsDeliverRptAckInfo
)
{
    VOS_UINT32                          ulPos               = 0;
    VOS_UINT32                          ulRet               = MN_ERR_NO_ERROR;

    if ((VOS_NULL_PTR == pstSmsRawDataInfo)
     || (VOS_NULL_PTR == pstSmsDeliverRptAckInfo))
    {
        MN_ERR_LOG("MSG_DecodeDeliverRptAck: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }

    TAF_MEM_SET_S(pstSmsDeliverRptAckInfo, sizeof(MN_MSG_DELIVER_RPT_ACK_STRU), 0x00, sizeof(MN_MSG_DELIVER_RPT_ACK_STRU));


    /*TP MTI ignore  TP-UDHI  */
    MSG_GET_TP_UDHI(pstSmsDeliverRptAckInfo->bUserDataHeaderInd, pstSmsRawDataInfo->aucData[ulPos++]);

    /*    TP PI  9.2.3.27 BIT   2       1       0             */
    /*                          TP UDL  TP DCS  TP PID        */

    pstSmsDeliverRptAckInfo->ucParaInd  = pstSmsRawDataInfo->aucData[ulPos++];

    /*TP PID*/
    if (0 != (pstSmsDeliverRptAckInfo->ucParaInd & MN_MSG_TP_PID_MASK))
    {
        pstSmsDeliverRptAckInfo->enPid      = pstSmsRawDataInfo->aucData[ulPos++];
    }
    /*  TP DCS*/
    if (0 != (pstSmsDeliverRptAckInfo->ucParaInd & MN_MSG_TP_DCS_MASK))
    {
        ulRet = MN_MSG_DecodeDcs(pstSmsRawDataInfo->aucData[ulPos],
                                 &(pstSmsDeliverRptAckInfo->stDcs));
        if (MN_ERR_NO_ERROR != ulRet)
        {
            return ulRet;
        }
        ulPos++;
    }
    else
    {
        TAF_MEM_SET_S(&(pstSmsDeliverRptAckInfo->stDcs),
                    sizeof(pstSmsDeliverRptAckInfo->stDcs),
                    0x00,
                    sizeof(pstSmsDeliverRptAckInfo->stDcs));
        pstSmsDeliverRptAckInfo->stDcs.enMsgCoding = MN_MSG_MSG_CODING_7_BIT;
    }

    /*TP UD TP UDL;*/
    if (0 != (pstSmsDeliverRptAckInfo->ucParaInd & MN_MSG_TP_UDL_MASK))
    {
        ulRet = MSG_DecodeUserData(pstSmsDeliverRptAckInfo->bUserDataHeaderInd,
                                   &(pstSmsDeliverRptAckInfo->stDcs),
                                   (VOS_UINT8 *)&(pstSmsRawDataInfo->aucData[ulPos]),
                                   &(pstSmsDeliverRptAckInfo->stUserData));
    }

    return ulRet;

}


LOCAL VOS_UINT32   MSG_DecodeDeliverRptErr(
    const MN_MSG_RAW_TS_DATA_STRU       *pstSmsRawDataInfo ,
    MN_MSG_DELIVER_RPT_ERR_STRU         *pstSmsDeliverRptErrInfo
)
{
    VOS_UINT32                          ulPos               = 0;
    VOS_UINT32                          ulRet               = MN_ERR_NO_ERROR;

    if ((VOS_NULL_PTR == pstSmsRawDataInfo)
     || (VOS_NULL_PTR == pstSmsDeliverRptErrInfo))
    {
        MN_ERR_LOG("MSG_DecodeDeliverRptErr: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }

    TAF_MEM_SET_S(pstSmsDeliverRptErrInfo, sizeof(MN_MSG_DELIVER_RPT_ERR_STRU), 0x00, sizeof(MN_MSG_DELIVER_RPT_ERR_STRU));


    /*TP MTI ignore  TP-UDHI  */
    MSG_GET_TP_UDHI(pstSmsDeliverRptErrInfo->bUserDataHeaderInd, pstSmsRawDataInfo->aucData[ulPos++]);

    /*TP FCS*/
    pstSmsDeliverRptErrInfo->enFailCause = pstSmsRawDataInfo->aucData[ulPos++];

    /*    TP PI  9.2.3.27 BIT   2       1       0             */
    /*                          TP UDL  TP DCS  TP PID        */
    pstSmsDeliverRptErrInfo->ucParaInd = pstSmsRawDataInfo->aucData[ulPos++];

    /*TP PID*/
    if (0 != (pstSmsDeliverRptErrInfo->ucParaInd & MN_MSG_TP_PID_MASK))
    {
        pstSmsDeliverRptErrInfo->enPid = pstSmsRawDataInfo->aucData[ulPos++];
    }
    /*  TP DCS*/
    if (0 != (pstSmsDeliverRptErrInfo->ucParaInd & MN_MSG_TP_DCS_MASK))
    {
        ulRet = MN_MSG_DecodeDcs(pstSmsRawDataInfo->aucData[ulPos],
                                 &pstSmsDeliverRptErrInfo->stDcs);
        if (MN_ERR_NO_ERROR != ulRet)
        {
            return ulRet;
        }
        ulPos++;
    }
    else
    {
        TAF_MEM_SET_S(&(pstSmsDeliverRptErrInfo->stDcs),
                   sizeof(pstSmsDeliverRptErrInfo->stDcs),
                   0x00,
                   sizeof(pstSmsDeliverRptErrInfo->stDcs));
        pstSmsDeliverRptErrInfo->stDcs.enMsgCoding = MN_MSG_MSG_CODING_7_BIT;
    }

    /*TP UD TP UDL;*/
    if (0 != (pstSmsDeliverRptErrInfo->ucParaInd & MN_MSG_TP_UDL_MASK))
    {
        ulRet = MSG_DecodeUserData(pstSmsDeliverRptErrInfo->bUserDataHeaderInd,
                                   &(pstSmsDeliverRptErrInfo->stDcs),
                                   (VOS_UINT8 *)&(pstSmsRawDataInfo->aucData[ulPos]),
                                   &(pstSmsDeliverRptErrInfo->stUserData));
    }

    return ulRet;
}


LOCAL VOS_UINT32   MSG_DecodeStaRpt(
    const MN_MSG_RAW_TS_DATA_STRU       *pstSmsRawDataInfo ,
    MN_MSG_STA_RPT_STRU                 *pstSmsStatusRptInfo
)
{
    VOS_UINT32                          ulRet               = MN_ERR_NO_ERROR;
    VOS_UINT32                          ulPos               = 0;
    VOS_UINT32                          ulRaLen;
    VOS_UINT32                          ulSctsLen;
    VOS_UINT32                          ulDtLen;

    if ((VOS_NULL_PTR == pstSmsRawDataInfo)
     || (VOS_NULL_PTR == pstSmsStatusRptInfo))
    {
        MN_ERR_LOG("MSG_DecodeStaRpt: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }

    TAF_MEM_SET_S(pstSmsStatusRptInfo, sizeof(MN_MSG_STA_RPT_STRU), 0x00, sizeof(MN_MSG_STA_RPT_STRU));

    /*TP MTI ignore TP UDHI TP MMS TP SRQ*/
    MSG_GET_TP_UDHI(pstSmsStatusRptInfo->bUserDataHeaderInd, pstSmsRawDataInfo->aucData[ulPos]);
    MSG_GET_TP_MMS(pstSmsStatusRptInfo->bMoreMsg, pstSmsRawDataInfo->aucData[ulPos]);
    MSG_GET_TP_SRQ(pstSmsStatusRptInfo->bStaRptQualCommand, pstSmsRawDataInfo->aucData[ulPos]);
    ulPos++;

    /*TP MR*/
    pstSmsStatusRptInfo->ucMr = pstSmsRawDataInfo->aucData[ulPos++];

    /*TP RA 2 12o*/
    ulRet = MN_MSG_DecodeAddress(&(pstSmsRawDataInfo->aucData[ulPos]),
                                 VOS_FALSE,
                                 &(pstSmsStatusRptInfo->stRecipientAddr),
                                 &ulRaLen);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        return ulRet;
    }
    ulPos += ulRaLen;

    /*TP SCTS 7o Parameter identifying time when the SC received the previously sent SMS SUBMIT*/
    ulRet = MSG_DecodeTimeStamp((VOS_UINT8 *)&(pstSmsRawDataInfo->aucData[ulPos]),
                                &(pstSmsStatusRptInfo->stTimeStamp),
                                &ulSctsLen);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        return ulRet;
    }
    ulPos += ulSctsLen;

    /*TP DT Parameter identifying the time associated with a particular TP ST outcome*/
    ulRet = MSG_DecodeTimeStamp((VOS_UINT8 *)&(pstSmsRawDataInfo->aucData[ulPos]),
                                &(pstSmsStatusRptInfo->stDischargeTime),
                                &ulDtLen);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        return ulRet;
    }
    ulPos += ulDtLen;

    /*TP ST*/
    pstSmsStatusRptInfo->enStatus = pstSmsRawDataInfo->aucData[ulPos++];

    if (ulPos >= pstSmsRawDataInfo->ulLen)
    {
        return MN_ERR_NO_ERROR;
    }

    /*    TP PI  9.2.3.27 BIT   2       1       0             */
    /*                          TP UDL  TP DCS  TP PID        */
    pstSmsStatusRptInfo->ucParaInd = pstSmsRawDataInfo->aucData[ulPos++];

    /*TP PID*/
    if (0 != (pstSmsStatusRptInfo->ucParaInd & MN_MSG_TP_PID_MASK))
    {
        pstSmsStatusRptInfo->enPid = pstSmsRawDataInfo->aucData[ulPos++];
    }
    /*  TP DCS*/
    if (0 != (pstSmsStatusRptInfo->ucParaInd & MN_MSG_TP_DCS_MASK))
    {
        ulRet = MN_MSG_DecodeDcs(pstSmsRawDataInfo->aucData[ulPos],
                                 &pstSmsStatusRptInfo->stDcs);
        if (MN_ERR_NO_ERROR != ulRet)
        {
            MN_WARN_LOG("MSG_DecodeStaRpt: invalid DCS.");
            return MN_ERR_NO_ERROR;
        }
        ulPos++;
    }
    else
    {
        TAF_MEM_SET_S(&(pstSmsStatusRptInfo->stDcs),
                   sizeof(pstSmsStatusRptInfo->stDcs),
                   0x00,
                   sizeof(pstSmsStatusRptInfo->stDcs));
        pstSmsStatusRptInfo->stDcs.enMsgCoding = MN_MSG_MSG_CODING_7_BIT;
    }

    /*TP UD TP UDL;*/
    if (0 != (pstSmsStatusRptInfo->ucParaInd & MN_MSG_TP_UDL_MASK))
    {
        ulRet = MSG_DecodeUserData(pstSmsStatusRptInfo->bUserDataHeaderInd,
                                   &(pstSmsStatusRptInfo->stDcs),
                                   (VOS_UINT8 *)&(pstSmsRawDataInfo->aucData[ulPos]),
                                   &(pstSmsStatusRptInfo->stUserData));
        if (MN_ERR_NO_ERROR != ulRet)
        {
            MN_WARN_LOG("MSG_DecodeStaRpt: invalid UDL or UD.");
            return MN_ERR_NO_ERROR;
        }
    }

    return ulRet;
}



LOCAL VOS_UINT32   MSG_DecodeCommand(
    const MN_MSG_RAW_TS_DATA_STRU       *pstSmsRawDataInfo,
    MN_MSG_COMMAND_STRU                 *pstSmsCommandInfo
)
{
    VOS_UINT32                          ulRet               = MN_ERR_NO_ERROR;
    VOS_UINT32                          ulPos               = 0;
    VOS_UINT32                          ulAddrLen;

    if ((VOS_NULL_PTR == pstSmsRawDataInfo)
     || (VOS_NULL_PTR == pstSmsCommandInfo))
    {
        MN_ERR_LOG("MSG_DecodeCommand: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }

    TAF_MEM_SET_S(pstSmsCommandInfo, sizeof(MN_MSG_COMMAND_STRU), 0x00, sizeof(MN_MSG_COMMAND_STRU));

    /*TP MTI TP UDHI TP SRR */
    MSG_GET_TP_UDHI(pstSmsCommandInfo->bUserDataHeaderInd, pstSmsRawDataInfo->aucData[ulPos]);
    MSG_GET_TP_SRR(pstSmsCommandInfo->bStaRptReq, pstSmsRawDataInfo->aucData[ulPos]);
    ulPos++;

    /*TP MR*/
    pstSmsCommandInfo->ucMr = pstSmsRawDataInfo->aucData[ulPos++];

    /*TP PID*/
    pstSmsCommandInfo->enPid = pstSmsRawDataInfo->aucData[ulPos++];

    /*TP CT*/
    pstSmsCommandInfo->enCmdType = pstSmsRawDataInfo->aucData[ulPos++];

    /*TP MN*/
    pstSmsCommandInfo->ucMsgNumber = pstSmsRawDataInfo->aucData[ulPos++];

    /*TP DA*/
    ulRet = MN_MSG_DecodeAddress(&(pstSmsRawDataInfo->aucData[ulPos]),
                                 VOS_FALSE,
                                 &(pstSmsCommandInfo->stDestAddr),
                                 &ulAddrLen);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        return ulRet;
    }
    ulPos += ulAddrLen;

    /*TP CDL*/
    pstSmsCommandInfo->ucCommandDataLen = pstSmsRawDataInfo->aucData[ulPos++];
    /*TP CD*/
    if (0 == pstSmsCommandInfo->ucCommandDataLen)
    {
        return MN_ERR_NO_ERROR;
    }

    if (pstSmsCommandInfo->ucCommandDataLen > MN_MSG_MAX_COMMAND_DATA_LEN)
    {
        return MN_ERR_CLASS_SMS_MSGLEN_OVERFLOW;
    }
    if (pstSmsCommandInfo->ucCommandDataLen > MN_MSG_MAX_COMMAND_DATA_LEN)
    {
        pstSmsCommandInfo->ucCommandDataLen = MN_MSG_MAX_COMMAND_DATA_LEN;
    }
    TAF_MEM_CPY_S(pstSmsCommandInfo->aucCmdData,
               sizeof(pstSmsCommandInfo->aucCmdData),
               &pstSmsRawDataInfo->aucData[ulPos],
               pstSmsCommandInfo->ucCommandDataLen);

    return ulRet;
}


LOCAL VOS_UINT32   MSG_DecodeSubmit(
    const MN_MSG_RAW_TS_DATA_STRU       *pstSmsRawDataInfo,
    MN_MSG_SUBMIT_STRU                  *pstSmsSubmitInfo
)
{
    VOS_UINT32                          ulRet               = MN_ERR_NO_ERROR;
    VOS_UINT32                          ulPos               = 0;
    VOS_UINT32                          ulDaLen;
    VOS_UINT32                          ulVpLen;

    if ((VOS_NULL_PTR == pstSmsRawDataInfo)
     || (VOS_NULL_PTR == pstSmsSubmitInfo))
    {
        MN_ERR_LOG("MSG_DecodeSubmit: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }

    TAF_MEM_SET_S(pstSmsSubmitInfo, sizeof(MN_MSG_SUBMIT_STRU), 0x00, sizeof(MN_MSG_SUBMIT_STRU));
    /*b7  b6   b5   b4   b3  b2  b1  b0
      RP  UDHI SRR  VPF      RD  MTI
      0   0    0    2        1   2
      TP MTI TP RD TP VPF TP RP TP UDHI TP SRR*/
    /*TP MTI ignore 23040 9.2.3.1 ��дbit0bit1:MIT     0011 0001 */

    /*TP RD  23040 9.2.3.25*/
    MSG_GET_TP_RD(pstSmsSubmitInfo->bRejectDuplicates, pstSmsRawDataInfo->aucData[ulPos]);
    /*TP VPF 23040 9.2.3.3*/
    MSG_GET_TP_VPF(pstSmsSubmitInfo->stValidPeriod.enValidPeriod, pstSmsRawDataInfo->aucData[ulPos]);
    /*TP RP  23040 9.2.3.17*/
    MSG_GET_TP_RP(pstSmsSubmitInfo->bReplayPath, pstSmsRawDataInfo->aucData[ulPos]);
    /*TP UDHI23040 9.2.3.23*/
    MSG_GET_TP_UDHI(pstSmsSubmitInfo->bUserDataHeaderInd, pstSmsRawDataInfo->aucData[ulPos]);
    /*TP SRR 23040 9.2.3.5*/
    MSG_GET_TP_SRR(pstSmsSubmitInfo->bStaRptReq, pstSmsRawDataInfo->aucData[ulPos]);
    ulPos++;

    /*TP MR*/
    pstSmsSubmitInfo->ucMr = pstSmsRawDataInfo->aucData[ulPos++];

    /*TP DA* Refer to 9.1.2.5*/
    ulRet = MN_MSG_DecodeAddress(&(pstSmsRawDataInfo->aucData[ulPos]),
                                 VOS_FALSE,
                                 &(pstSmsSubmitInfo->stDestAddr),
                                 &ulDaLen);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        return ulRet;
    }
    ulPos += ulDaLen;

    /*TP PID*/
    pstSmsSubmitInfo->enPid = pstSmsRawDataInfo->aucData[ulPos++];

    /*TP DCS 23038 4 */
    ulRet = MN_MSG_DecodeDcs(pstSmsRawDataInfo->aucData[ulPos],
                             &(pstSmsSubmitInfo->stDcs));
    if (MN_ERR_NO_ERROR != ulRet)
    {
        return ulRet;
    }
    ulPos ++;

    /*TP VP*/
    ulRet = MN_MSG_DecodeValidPeriod(pstSmsSubmitInfo->stValidPeriod.enValidPeriod,
                                  &(pstSmsRawDataInfo->aucData[ulPos]),
                                  &(pstSmsSubmitInfo->stValidPeriod),
                                  & ulVpLen);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        return ulRet;
    }
    ulPos += ulVpLen;

    /*UDL UD*/
    ulRet = MSG_DecodeUserData(pstSmsSubmitInfo->bUserDataHeaderInd,
                               &(pstSmsSubmitInfo->stDcs),
                               (VOS_UINT8 *)&(pstSmsRawDataInfo->aucData[ulPos]),
                               &(pstSmsSubmitInfo->stUserData));

    return ulRet;
}


LOCAL VOS_UINT32   MSG_DecodeSubmitRptAck(
    const MN_MSG_RAW_TS_DATA_STRU       *pstSmsRawDataInfo ,
    MN_MSG_SUBMIT_RPT_ACK_STRU          *pstSmsSubmitRptAckInfo
)
{
    VOS_UINT32                          ulRet               = MN_ERR_NO_ERROR;
    VOS_UINT32                          ulPos               = 0;
    VOS_UINT32                          ulSctsLen;

    if ((VOS_NULL_PTR == pstSmsRawDataInfo)
     || (VOS_NULL_PTR == pstSmsSubmitRptAckInfo))
    {
        MN_ERR_LOG("MSG_DecodeSubmitRptAck: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }

    TAF_MEM_SET_S(pstSmsSubmitRptAckInfo, sizeof(MN_MSG_SUBMIT_RPT_ACK_STRU), 0x00, sizeof(MN_MSG_SUBMIT_RPT_ACK_STRU));

    /*TP MTI ignore TP-UDHI  */
    MSG_GET_TP_UDHI(pstSmsSubmitRptAckInfo->bUserDataHeaderInd, pstSmsRawDataInfo->aucData[ulPos]);
    ulPos++;

    /*    TP PI  9.2.3.27 BIT   2       1       0             */
    /*                          TP UDL  TP DCS  TP PID        */
    pstSmsSubmitRptAckInfo->ucParaInd = pstSmsRawDataInfo->aucData[ulPos++];

    /*TP SCTS*/
    ulRet = MSG_DecodeTimeStamp((VOS_UINT8 *)&(pstSmsRawDataInfo->aucData[ulPos]),
                                &(pstSmsSubmitRptAckInfo->stTimeStamp),
                                &ulSctsLen);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        return ulRet;
    }
    ulPos += ulSctsLen;

    /*TP PID*/
    if (0 != (pstSmsSubmitRptAckInfo->ucParaInd & MN_MSG_TP_PID_MASK))
    {
        pstSmsSubmitRptAckInfo->enPid = pstSmsRawDataInfo->aucData[ulPos++];
    }

    /*  TP DCS*/
    if (0 != (pstSmsSubmitRptAckInfo->ucParaInd & MN_MSG_TP_DCS_MASK))
    {
        ulRet = MN_MSG_DecodeDcs(pstSmsRawDataInfo->aucData[ulPos],
                                 &(pstSmsSubmitRptAckInfo->stDcs));
        if (MN_ERR_NO_ERROR != ulRet)
        {
            return ulRet;
        }
        ulPos ++;
    }
    else
    {
        TAF_MEM_SET_S(&(pstSmsSubmitRptAckInfo->stDcs),
                   sizeof(pstSmsSubmitRptAckInfo->stDcs),
                   0x00,
                   sizeof(pstSmsSubmitRptAckInfo->stDcs));
        pstSmsSubmitRptAckInfo->stDcs.enMsgCoding = MN_MSG_MSG_CODING_7_BIT;
    }

    /*TP UD TP UDL;*/
    if (0 != (pstSmsSubmitRptAckInfo->ucParaInd & MN_MSG_TP_UDL_MASK))
    {
        ulRet = MSG_DecodeUserData(pstSmsSubmitRptAckInfo->bUserDataHeaderInd,
                                   &(pstSmsSubmitRptAckInfo->stDcs),
                                   (VOS_UINT8 *)&(pstSmsRawDataInfo->aucData[ulPos]),
                                   &(pstSmsSubmitRptAckInfo->stUserData));
    }

    return ulRet;
}


LOCAL VOS_UINT32   MSG_DecodeSubmitRptErr(
    const MN_MSG_RAW_TS_DATA_STRU       *pstSmsRawDataInfo ,
    MN_MSG_SUBMIT_RPT_ERR_STRU          *pstSmsSubmitRptErrInfo
)
{
    VOS_UINT32                          ulRet               = MN_ERR_NO_ERROR;
    VOS_UINT32                          ulPos               = 0;
    VOS_UINT32                          ulSctsLen;

    if ((VOS_NULL_PTR == pstSmsRawDataInfo)
     || (VOS_NULL_PTR == pstSmsSubmitRptErrInfo))
    {
        MN_ERR_LOG("MSG_DecodeSubmitRptErr: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }

    TAF_MEM_SET_S(pstSmsSubmitRptErrInfo, sizeof(MN_MSG_SUBMIT_RPT_ERR_STRU), 0x00, sizeof(MN_MSG_SUBMIT_RPT_ERR_STRU));


    /*TP MTI ignore TP-UDHI  */
    MSG_GET_TP_UDHI(pstSmsSubmitRptErrInfo->bUserDataHeaderInd, pstSmsRawDataInfo->aucData[ulPos]);
    ulPos++;

    /*TP FCS*/
    pstSmsSubmitRptErrInfo->enFailCause = pstSmsRawDataInfo->aucData[ulPos++];

    /*    TP PI  9.2.3.27 BIT   2       1       0             */
    /*                          TP UDL  TP DCS  TP PID        */
    pstSmsSubmitRptErrInfo->ucParaInd = pstSmsRawDataInfo->aucData[ulPos++];

    /*TP SCTS*/
    ulRet = MSG_DecodeTimeStamp((VOS_UINT8 *)&(pstSmsRawDataInfo->aucData[ulPos]),
                                &(pstSmsSubmitRptErrInfo->stTimeStamp),
                                &ulSctsLen);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        return ulRet;
    }
    ulPos += ulSctsLen;

    /*TP PID*/
    if (0 != (pstSmsSubmitRptErrInfo->ucParaInd & MN_MSG_TP_PID_MASK))
    {
        pstSmsSubmitRptErrInfo->enPid = pstSmsRawDataInfo->aucData[ulPos++];
    }

    /*  TP DCS*/
    if (0 != (pstSmsSubmitRptErrInfo->ucParaInd & MN_MSG_TP_DCS_MASK))
    {
        ulRet = MN_MSG_DecodeDcs(pstSmsRawDataInfo->aucData[ulPos],
                                 &(pstSmsSubmitRptErrInfo->stDcs));
        if (MN_ERR_NO_ERROR != ulRet)
        {
            return ulRet;
        }
        ulPos ++;
    }
    else
    {
        TAF_MEM_SET_S(&(pstSmsSubmitRptErrInfo->stDcs),
                   sizeof(pstSmsSubmitRptErrInfo->stDcs),
                   0x00,
                   sizeof(pstSmsSubmitRptErrInfo->stDcs));
        pstSmsSubmitRptErrInfo->stDcs.enMsgCoding = MN_MSG_MSG_CODING_7_BIT;
    }

    /*TP UD TP UDL;*/
    if (0 != (pstSmsSubmitRptErrInfo->ucParaInd & MN_MSG_TP_UDL_MASK))
    {
        ulRet = MSG_DecodeUserData(pstSmsSubmitRptErrInfo->bUserDataHeaderInd,
                                   &(pstSmsSubmitRptErrInfo->stDcs),
                                   (VOS_UINT8 *)&(pstSmsRawDataInfo->aucData[ulPos]),
                                   &(pstSmsSubmitRptErrInfo->stUserData));
    }

    return ulRet;
}


VOS_UINT32  MN_MSG_DecodeDcs(
    VOS_UINT8                           ucDcsData,
    MN_MSG_DCS_CODE_STRU                *pstDcs
)
{
    VOS_UINT8                           ucCodingGroup;

    /*�ж���������ĺϷ���*/
    if (VOS_NULL_PTR == pstDcs)
    {
        MN_ERR_LOG("MN_MSG_DecodeDcs: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }

    /*��pstDcsCode��ʼ��Ϊһ��Ĭ��ֵ*/
    pstDcs->bCompressed         = VOS_FALSE;
    pstDcs->bWaitingIndiActive  = VOS_FALSE;
    pstDcs->enMsgClass          = MN_MSG_MSG_CLASS_NONE;
    pstDcs->enMsgCoding         = MN_MSG_MSG_CODING_7_BIT;
    pstDcs->enMsgWaiting        = MN_MSG_MSG_WAITING_NONE;
    pstDcs->enMsgWaitingKind    = MN_MSG_MSG_WAITING_OTHER;
    pstDcs->ucRawDcsData        = ucDcsData;
    pstDcs->bRawDcsValid        = VOS_TRUE;
    /*ucDcsData ��bit 6 bit 7��λ*/
    ucCodingGroup               = (ucDcsData >> 6) & 0x03;

    /* LGU+�����¶���ʹ�õ�DCS����Ϊ0x84������Э������Reserved coding group����Ҫ���⴦��
       �Ա�֤���ŵ������շ�������Э�����DCS�󣬵�ǰʹ�õ�character setΪ8 bit��û������
       ѹ��ģʽ����û��ָ��message class */
    if (0x84 == ucDcsData)
    {
        pstDcs->enMsgCoding = MN_MSG_MSG_CODING_8_BIT;
        return MN_ERR_NO_ERROR;
    }

    switch (ucCodingGroup)
    {
        /*(pattern 00xx xxxx)*/
        case 1:
            /*Message Marked for Automatic Deletion Group*/
            pstDcs->enMsgWaiting = MN_MSG_MSG_WAITING_AUTO_DELETE;
            /* fall through */
        case 0:

            /*lint -e961*/
            /* Bit 5  if set to 0, indicates the text is uncompressed */
            MSG_GET_COMPRESSED(pstDcs->bCompressed, ucDcsData);
            /*lint +e961*/

            /* Bit 3 Bit2 Character set:*/
            MSG_GET_CHARSET(pstDcs->enMsgCoding, ucDcsData);
            /* Bit 4, if set to 0, indicates that bits 1 to 0 are reserved and have no message class*/
            if (0 != (ucDcsData & 0x10)) /*(bit 4)*/
            {
                MSG_GET_MSGCLASS(pstDcs->enMsgClass, ucDcsData);
            }
            /*������ʧ�����*/
            break;
        case 3:
            if ((ucDcsData & 0x30) == 0x30) /*(pattern 1111 xxxx)*/
            {
                pstDcs->enMsgWaiting = MN_MSG_MSG_WAITING_NONE_1111;
                MSG_GET_MSGCODING(pstDcs->enMsgCoding, ucDcsData);
                MSG_GET_MSGCLASS(pstDcs->enMsgClass, ucDcsData);
                /*bit3 Ĭ��Ϊ0��������ʧ�����*/
            }
            else
            {
                /*bit2 Ĭ��Ϊ0��������ʧ�����*/
                /*lint -e961*/
                MSG_GET_INDSENSE(pstDcs->bWaitingIndiActive, ucDcsData);
                MSG_GET_INDTYPE(pstDcs->enMsgWaitingKind, ucDcsData);
                /*lint +e961*/

                if ((ucDcsData & 0x30) == 0x00)/*(pattern 1100 xxxx)*/
                {
                    pstDcs->enMsgWaiting = MN_MSG_MSG_WAITING_DISCARD;
                }
                else
                {
                    pstDcs->enMsgWaiting = MN_MSG_MSG_WAITING_STORE;
                    if ((ucDcsData & 0x30) == 0x20)
                    {
                        pstDcs->enMsgCoding = MN_MSG_MSG_CODING_UCS2;
                    }
                }
            }
            break;
        default:
            
            MN_ERR_LOG("MN_MSG_DecodeDcs: ucCodingGroup is Reserve.");
            break;
    }

    return MN_ERR_NO_ERROR;
}


VOS_UINT32  MN_MSG_DecodeRelatTime(
    VOS_UINT8                           ucRelatTimeData,
    MN_MSG_TIMESTAMP_STRU               *pstRelatTime
)
{
    VOS_UINT32                          ulMunite;
    VOS_UINT32                          ulDay;

    if (VOS_NULL_PTR == pstRelatTime)
    {
        MN_ERR_LOG("MN_MSG_DecodeRelatTime: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }
    else
    {
        TAF_MEM_SET_S(pstRelatTime, sizeof(MN_MSG_TIMESTAMP_STRU), 0x00, sizeof(MN_MSG_TIMESTAMP_STRU));
    }

    /*0��143����VP+1��* 5 ���ӣ��ɱ�ʾ5���ӵ�12Сʱ��ʱ���
      144��167��12 Сʱ+����VP�C143��*30 ���ӣ���12 -> 23.5Сʱ
      168��196����VP�C166��*1 �գ�����ʾ(196 - 166)== 30��
      197��255����VP�C192��*1 �ܡ��ɱ�ʾ(255-192)*7 == 441��*/
    if (ucRelatTimeData < 144)
    {
        ulMunite                = (ucRelatTimeData + 1) * 5;
        pstRelatTime->ucHour    = (VOS_UINT8)(ulMunite / MN_MSG_MINUTES_IN_AN_HOUR);
        pstRelatTime->ucMinute  = ulMunite % MN_MSG_MINUTES_IN_AN_HOUR;
    }
    else if (ucRelatTimeData < 168)
    {
        ulMunite                = (12 * MN_MSG_MINUTES_IN_AN_HOUR) + ((ucRelatTimeData - 143) * 30);
        pstRelatTime->ucHour    = (VOS_UINT8 )(ulMunite / MN_MSG_MINUTES_IN_AN_HOUR);
        pstRelatTime->ucMinute  = ulMunite % MN_MSG_MINUTES_IN_AN_HOUR;
    }
    else if (ucRelatTimeData < 197)
    {
        pstRelatTime->ucDay = ucRelatTimeData - 166;
    }
    else
    {
        ulDay                   = (ucRelatTimeData - 192) * 7;
        pstRelatTime->ucYear    = (VOS_UINT8)(ulDay / MN_MSG_DAYS_IN_A_YEAR);
        pstRelatTime->ucDay     = (VOS_UINT8)(ulDay % MN_MSG_DAYS_IN_A_YEAR);
        pstRelatTime->ucMonth   = pstRelatTime->ucDay / 30;
        pstRelatTime->ucDay    %= 30;
    }

    return MN_ERR_NO_ERROR;
}


VOS_UINT32  MN_MSG_Decode(
    const MN_MSG_RAW_TS_DATA_STRU       *pstRawData ,
    MN_MSG_TS_DATA_INFO_STRU            *pstTsDataInfo
)
{
    VOS_UINT32                          ulRet;

    if ((VOS_NULL_PTR == pstRawData)
     || (VOS_NULL_PTR == pstTsDataInfo))
    {
        MN_ERR_LOG("MN_MSG_Decode: Parameter of the function is null.");
        return MN_ERR_NULLPTR;
    }
    else
    {
        TAF_MEM_SET_S(pstTsDataInfo, sizeof(MN_MSG_TS_DATA_INFO_STRU), 0x00, sizeof(MN_MSG_TS_DATA_INFO_STRU));
    }

    if (pstRawData->ulLen > MSG_MAX_TPDU_MSG_LEN)
    {
        MN_WARN_LOG("MN_MSG_Decode: Parameter of the function is null.");
        return MN_ERR_CLASS_SMS_MSGLEN_OVERFLOW;
    }

    pstTsDataInfo->enTpduType = pstRawData->enTpduType;

    MN_INFO_LOG1("MN_MSG_Decode: Tpdu type is ", (VOS_INT32)pstRawData->enTpduType);
    switch ( pstRawData->enTpduType )
    {
        case MN_MSG_TPDU_DELIVER:
            ulRet = MSG_DecodeDeliver(pstRawData, &(pstTsDataInfo->u.stDeliver));
            break;

        case MN_MSG_TPDU_DELIVER_RPT_ACK:
            ulRet = MSG_DecodeDeliverRptAck(pstRawData, &(pstTsDataInfo->u.stDeliverRptAck));
            break;

        case MN_MSG_TPDU_DELIVER_RPT_ERR:
            ulRet = MSG_DecodeDeliverRptErr(pstRawData, &(pstTsDataInfo->u.stDeliverRptErr));
            break;

        case MN_MSG_TPDU_STARPT:
            ulRet = MSG_DecodeStaRpt(pstRawData, &(pstTsDataInfo->u.stStaRpt));
            break;

        case MN_MSG_TPDU_COMMAND:
            ulRet = MSG_DecodeCommand(pstRawData, &(pstTsDataInfo->u.stCommand));
            break;

        case MN_MSG_TPDU_SUBMIT:
            ulRet = MSG_DecodeSubmit(pstRawData, &(pstTsDataInfo->u.stSubmit));
            break;

        case MN_MSG_TPDU_SUBMIT_RPT_ACK:
            ulRet = MSG_DecodeSubmitRptAck(pstRawData, &(pstTsDataInfo->u.stSubmitRptAck));
            break;

        case MN_MSG_TPDU_SUBMIT_RPT_ERR:
            ulRet = MSG_DecodeSubmitRptErr(pstRawData, &(pstTsDataInfo->u.stSubmitRptErr));
            break;

        default:
            MN_WARN_LOG("MN_MSG_Decode: invalid pdu type.");
            ulRet = MN_ERR_CLASS_SMS_INVALID_TPDUTYPE;
            break;
    }

    MN_INFO_LOG1("MN_MSG_Decode: result is ", (VOS_INT32)ulRet);
    return ulRet;
}


MN_MSG_USER_HEADER_TYPE_STRU  *MSG_GetSpecIdUdhIe(
    VOS_UINT8                           ucNumofHeaders,                         /*number of user header*/
    MN_MSG_USER_HEADER_TYPE_STRU        *pstUserDataHeader,
    MN_MSG_UDH_TYPE_ENUM_U8             enHeaderID
)
{
    VOS_BOOL                            bIeExist            = VOS_FALSE;
    VOS_UINT32                          ulLoop;

    if (VOS_NULL_PTR == pstUserDataHeader)
    {
        MN_ERR_LOG("MSG_GetSpecIdUdhIe: Parameter of the function is null.");
        return VOS_NULL_PTR;
    }

    for (ulLoop = 0; ulLoop < ucNumofHeaders; ulLoop++)
    {
        if (pstUserDataHeader->enHeaderID == enHeaderID)
        {
            bIeExist = VOS_TRUE;
            break;
        }
        pstUserDataHeader++;
    }

    if (VOS_TRUE == bIeExist)
    {
        MN_INFO_LOG("MSG_ConcatenateUdh: ie is exist in long message struct.");
        return pstUserDataHeader;
    }
    else
    {
        return VOS_NULL_PTR;
    }

}


VOS_UINT32 MSG_FillMsgUdhEo(
    MN_MSG_DELIVER_STRU                 *pstSmsDeliverInfo,
    MN_MSG_USER_HEADER_TYPE_STRU        *pstUserDataHeader,
    MN_MSG_DELIVER_LONG_STRU            *pstLongDeliver
)
{
    MN_MSG_USER_HEADER_TYPE_STRU        *pstLongUserDataHeader;                 /*detail of user header*/
    VOS_UINT16                          usCurrentLen;

    if (VOS_FALSE == pstUserDataHeader->u.stEo.bFirstSegment)
    {
        pstLongUserDataHeader = MSG_GetSpecIdUdhIe(pstLongDeliver->stLongUserData.ucNumofHeaders,
                                                   pstLongDeliver->stLongUserData.astUserDataHeader,
                                                   MN_MSG_UDH_EO);
        if (VOS_NULL_PTR == pstLongUserDataHeader)
        {
            MN_ERR_LOG("MSG_FillMsgUdhEo: The subsequent Extended Object IEs without first Extended Object IE");
            return MN_ERR_INVALIDPARM;
        }

        usCurrentLen = pstLongUserDataHeader->u.stEo.usDataLen;
        if ((usCurrentLen + pstUserDataHeader->u.stEo.usDataLen) > MN_MSG_MAX_UDH_LONG_EO_DATA_LEN)
        {
            MN_WARN_LOG("MSG_FillMsgUdhEo: Extended Object IE length is overflow, Check to get a right length for EO.");
            return MN_ERR_INVALIDPARM;
        }
        TAF_MEM_CPY_S(&pstLongUserDataHeader->u.stEo.aucData[usCurrentLen],
                   sizeof(VOS_UINT8) * (MN_MSG_MAX_UDH_LONG_EO_DATA_LEN - usCurrentLen),
                   pstUserDataHeader->u.stEo.aucData,
                   pstUserDataHeader->u.stEo.usDataLen);
    }

    return MN_ERR_NO_ERROR;
}


VOS_UINT32 MSG_FillMsgUdhCc(
    MN_MSG_DELIVER_STRU                 *pstSmsDeliverInfo,
    MN_MSG_USER_HEADER_TYPE_STRU        *pstUserDataHeader,
    MN_MSG_DELIVER_LONG_STRU            *pstLongDeliver
)
{
    MN_MSG_USER_HEADER_TYPE_STRU        *pstLongUserDataHeader;                 /*detail of user header*/
    VOS_UINT16                          usCurrentLen;

    pstLongUserDataHeader = MSG_GetSpecIdUdhIe(pstLongDeliver->stLongUserData.ucNumofHeaders,
                                               pstLongDeliver->stLongUserData.astUserDataHeader,
                                               MN_MSG_UDH_CC);
    if (VOS_NULL_PTR == pstLongUserDataHeader)
    {
        MN_ERR_LOG("MSG_FillMsgUdhCc: invalid Extended Object IE ");
        return MN_ERR_INVALIDPARM;
    }

    usCurrentLen = pstLongUserDataHeader->u.stEo.usDataLen;
    if ((usCurrentLen + pstUserDataHeader->u.stCc.usDataLen) > MN_MSG_UDH_MAX_COMPRESSION_DATA_LEN)
    {
        MN_WARN_LOG("MSG_FillMsgUdhCc: Extended Object IE length is overflow, Check to get a right length for CC.");
        return MN_ERR_INVALIDPARM;
    }

    TAF_MEM_CPY_S(&pstLongUserDataHeader->u.stCc.aucData[usCurrentLen],
               sizeof(VOS_UINT8) * (MN_MSG_UDH_MAX_COMPRESSION_DATA_LEN - usCurrentLen),
               pstUserDataHeader->u.stCc.aucData,
               pstUserDataHeader->u.stCc.usDataLen);

    return MN_ERR_NO_ERROR;
}

/*
MSG_FillLongMsgUdh
MSG_FillLongMsg
*/
/* MSG_FillLongMsg MSG_FillLongMsgUdh */


VOS_UINT32   MN_MSG_ParseConcatenateMsg(
    VOS_UINT8                           ucNum,
    const MN_MSG_RAW_TS_DATA_STRU       *pstRawData,
    MN_MSG_CONCENTRATE_MSG_ATTR         *pstConcentrateMsgAttr,
    MN_MSG_DELIVER_STRU                 *pstSmsDeliverInfo,
    VOS_UINT8                           *pucQueueMsg
)
{
    VOS_UINT32                          ulLoop;
    VOS_UINT32                          ulRet;
    MN_MSG_USER_HEADER_TYPE_STRU        *pstUserHeader;
    VOS_UINT8                           ucTotalNum          = 0;
    VOS_UINT8                           ucSeqNum;

    if (pstConcentrateMsgAttr->ucFirstMsgSeqNum < 1)
    {
        MN_WARN_LOG("MN_MSG_ParseConcatenateMsg: invalid SeqNum. ");
        return MN_ERR_INVALIDPARM;
    }

    pucQueueMsg[pstConcentrateMsgAttr->ucFirstMsgSeqNum - 1] = 1;
    /*Ϊ��������Ϣ����*/
    for (ulLoop = 1; ulLoop < ucNum; ulLoop++)
    {
        ulRet = MSG_DecodeDeliver(pstRawData, pstSmsDeliverInfo);
        if (MN_ERR_NO_ERROR != ulRet)
        {
            return ulRet;
        }

        if (VOS_TRUE == pstConcentrateMsgAttr->b8bitConcatMsg)
        {
            pstUserHeader = MSG_GetSpecIdUdhIe(pstSmsDeliverInfo->stUserData.ucNumofHeaders,
                                               pstSmsDeliverInfo->stUserData.astUserDataHeader,
                                               MN_MSG_UDH_CONCAT_8);
            if (VOS_NULL_PTR == pstUserHeader)
            {
                MN_ERR_LOG("MN_MSG_ParseConcatenateMsg: concatenate message without right concatenate IE. ");
                return MN_ERR_INVALIDPARM;
            }

            if (pstConcentrateMsgAttr->ucMr != pstUserHeader->u.stConcat_8.ucMr)
            {
                MN_WARN_LOG("MN_MSG_ParseConcatenateMsg: the reference number is not constant. ");
                return MN_ERR_INVALIDPARM;
            }
            ucSeqNum = pstUserHeader->u.stConcat_8.ucSeqNum;
            ucTotalNum = pstUserHeader->u.stConcat_8.ucTotalNum;
        }
        else
        {
            pstUserHeader = MSG_GetSpecIdUdhIe(pstSmsDeliverInfo->stUserData.ucNumofHeaders,
                                               pstSmsDeliverInfo->stUserData.astUserDataHeader,
                                               MN_MSG_UDH_CONCAT_16);
            if (VOS_NULL_PTR == pstUserHeader)
            {
                MN_ERR_LOG("MN_MSG_ParseConcatenateMsg: concatenate message without right concatenate IE. ");
                return MN_ERR_INVALIDPARM;
            }

            if (pstConcentrateMsgAttr->usMr != pstUserHeader->u.stConcat_16.usMr)
            {
                MN_WARN_LOG("MN_MSG_ParseConcatenateMsg: the reference number is not constant. ");
                return MN_ERR_INVALIDPARM;
            }
            ucSeqNum = pstUserHeader->u.stConcat_16.ucSeqNum;
            ucTotalNum = pstUserHeader->u.stConcat_16.ucTotalNum;
        }

        if (ucSeqNum > ucTotalNum)
        {
            MN_WARN_LOG("MN_MSG_ParseConcatenateMsg: Sequence number is bigger than Maximum number.");
            return MN_ERR_INVALIDPARM;
        }

        if (0 == ucSeqNum)
        {
            MN_WARN_LOG("MN_MSG_ParseConcatenateMsg: Sequence number is zero.");
            return MN_ERR_INVALIDPARM;
        }

        /*��Ϣ�ظ����*/
        if (0 != pucQueueMsg[ucSeqNum - 1])
        {
            MN_WARN_LOG("MN_MSG_ParseConcatenateMsg: Repeated message.");
            return MN_ERR_INVALIDPARM;
        }
        pucQueueMsg[ucSeqNum - 1] = (VOS_UINT8)(ulLoop + 1);
        pstRawData++;
    }

    /*��Ϣ��ϼ��*/
    for (ulLoop = 0; ulLoop < ucNum; ulLoop++)
    {
        if (0 == pucQueueMsg[ulLoop])
        {
            MN_WARN_LOG("MN_MSG_ParseConcatenateMsg: incontinuous message.");
            return MN_ERR_INVALIDPARM;
        }
    }

    return MN_ERR_NO_ERROR;
}


VOS_VOID MN_MSG_GetAddressFromSubmit(
    VOS_UINT8                          *pucRpduContent,
    VOS_UINT32                          ulRpDataLen,
    NAS_MNTN_ASCII_ADDR_STRU           *pstScAddr,
    NAS_MNTN_ASCII_ADDR_STRU           *pstDestAddr
)
{
    VOS_UINT8                           ucScLen;
    VOS_UINT8                           ucPos;
    VOS_UINT8                           ucMti;
    VOS_UINT32                          ulLen;
    VOS_UINT32                          ulRet;

    ucPos = 0;
    /* ��һ���ֽ���RP����Ϣ���ͣ� */
    ucPos++;

    /* �ڶ����ֽ���RP-MR */
    ucPos++;

    /* �ӵ������ֽڿ�ʼ��RP-OA */
    ucPos++;

    /* �ӵ��ĸ��ֽڿ�ʼ����RP-DA������������ */
    ucScLen = pucRpduContent[ucPos];

    ulRet = MN_MSG_DecodeAddress(&pucRpduContent[ucPos],
                                 VOS_TRUE,
                                 (MN_MSG_ASCII_ADDR_STRU *)pstScAddr,
                                 &ulLen);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        MN_WARN_LOG("NAS_MNTN_GetAddressFromSubmit:Error SC.");
        return;
    }
    /*ƫ�Ƶ��������ĺ��������: BCD�볤�ȼ�һλ����λ */
    ucPos += (ucScLen + 1);

    /* RP-DA��һ���ֽ�RP-DATA���� */
    ucPos++;

    /* ��Ϣ���͹��ˣ���Ϣ����SUBMIT��Ϣֱ���˳� */
    MSG_GET_TP_MTI(ucMti, pucRpduContent[ucPos]);
    if (MN_MSG_TP_MTI_SUBMIT != ucMti)
    {
        MN_WARN_LOG("NAS_MNTN_GetAddressFromSubmit:Error MsgName");
        return;
    }
    ucPos++;

    /* �ƶ���TP-MR�� */
    ucPos++;

    /* ��ȡ��Ŀ�ĺ�����׵�ַ������õ�Ŀ�ĺ��� */
    ulRet = MN_MSG_DecodeAddress(&pucRpduContent[ucPos],
                                 VOS_FALSE,
                                 (MN_MSG_ASCII_ADDR_STRU *)pstDestAddr,
                                 &ulLen);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        MN_WARN_LOG("NAS_MNTN_GetAddressFromSubmit:Error DA.");
        return;
    }

    return;
}


VOS_VOID MN_MSG_GetMsgMti(
    VOS_UINT8                           ucFo,
    VOS_UINT8                          *pucMti
)
{
    MSG_GET_TP_MTI(*pucMti, ucFo);

    return;
}


VOS_UINT32 MN_MSG_GetSubmitInfoForStk(
    MN_MSG_TPDU_STRU                   *pstTpdu,
    VOS_UINT8                          *pucUserDataLen,
    VOS_UINT8                          *pucUdhl,
    MN_MSG_MSG_CODING_ENUM_U8          *penMsgCoding,
    VOS_UINT32                         *pulDcsOffset
)
{
    VOS_UINT32                          ulRet;
    VOS_UINT32                          ulPos;
    VOS_UINT32                          ulDaLen;
    VOS_UINT32                          ulVpLen;
    MN_MSG_SUBMIT_STRU                 *pstSmsSubmitInfo;
    VOS_UINT8                           ucUdl;
    VOS_UINT8                           ucUdhl;

    if ((VOS_NULL_PTR == pstTpdu)
     || (VOS_NULL_PTR == pstTpdu->pucTpdu)
     || (VOS_NULL_PTR == pucUserDataLen)
     || (VOS_NULL_PTR == pucUdhl)
     || (VOS_NULL_PTR == penMsgCoding))
    {
        MN_WARN_LOG("MN_MSG_GetSubmitInfoForStk: NULL PTR. ");
        return MN_ERR_NULLPTR;
    }

    MN_NORM_LOG1("MN_MSG_GetSubmitInfoForStk: pstTpdu->ulLen is ", (VOS_INT32)pstTpdu->ulLen);

    pstSmsSubmitInfo = (MN_MSG_SUBMIT_STRU *)PS_MEM_ALLOC(WUEPS_PID_TAF,
                                                sizeof(MN_MSG_SUBMIT_STRU));
    if (VOS_NULL_PTR == pstSmsSubmitInfo)
    {
        MN_WARN_LOG("MN_MSG_GetSubmitInfoForStk: fail to alloc memory. ");
        return MN_ERR_NOMEM;
    }

    TAF_MEM_SET_S(pstSmsSubmitInfo, sizeof(MN_MSG_SUBMIT_STRU), 0x00, sizeof(MN_MSG_SUBMIT_STRU));

    /* FO */
    ulPos = 0;
    MSG_GET_TP_UDHI(pstSmsSubmitInfo->bUserDataHeaderInd, pstTpdu->pucTpdu[ulPos]);
    /*TP VPF 23040 9.2.3.3*/
    MSG_GET_TP_VPF(pstSmsSubmitInfo->stValidPeriod.enValidPeriod, pstTpdu->pucTpdu[ulPos]);
    ulPos++;

    /* TP MR */
    ulPos++;

    /* TP DA Refer to 9.1.2.5 */
    ulRet = MN_MSG_DecodeAddress(&(pstTpdu->pucTpdu[ulPos]),
                                 VOS_FALSE,
                                 &(pstSmsSubmitInfo->stDestAddr),
                                 &ulDaLen);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        /*lint -save -e516 */
        PS_MEM_FREE(WUEPS_PID_TAF, pstSmsSubmitInfo);
        /*lint -restore */
        return ulRet;
    }
    ulPos += ulDaLen;

    /* TP PID */
    pstSmsSubmitInfo->enPid = pstTpdu->pucTpdu[ulPos++];

    *pulDcsOffset = ulPos;

    /* TP DCS 23038 4 */
    ulRet = MN_MSG_DecodeDcs(pstTpdu->pucTpdu[ulPos],
                             &(pstSmsSubmitInfo->stDcs));
    if (MN_ERR_NO_ERROR != ulRet)
    {
        /*lint -save -e516 */
        PS_MEM_FREE(WUEPS_PID_TAF, pstSmsSubmitInfo);
        /*lint -restore */
        return ulRet;
    }
    ulPos ++;

    /*TP VP*/
    ulRet = MN_MSG_DecodeValidPeriod(pstSmsSubmitInfo->stValidPeriod.enValidPeriod,
                                     &(pstTpdu->pucTpdu[ulPos]),
                                     &(pstSmsSubmitInfo->stValidPeriod),
                                     & ulVpLen);
    if (MN_ERR_NO_ERROR != ulRet)
    {
        /*lint -save -e516 */
        PS_MEM_FREE(WUEPS_PID_TAF, pstSmsSubmitInfo);
        return ulRet;
        /*lint -restore */
    }
    ulPos += ulVpLen;

    ucUdl = pstTpdu->pucTpdu[ulPos];
    ulPos ++;

    if (VOS_TRUE == pstSmsSubmitInfo->bUserDataHeaderInd)
    {
        ucUdhl          = pstTpdu->pucTpdu[ulPos];
        if (MN_MSG_MSG_CODING_7_BIT == pstSmsSubmitInfo->stDcs.enMsgCoding)
        {
            *pucUserDataLen = (VOS_UINT8)(ucUdl - ((((ucUdhl + 1) * 8) + 6)/7));
        }
        else
        {
            *pucUserDataLen = (VOS_UINT8)(ucUdl - (ucUdhl + 1));
        }

        *pucUdhl        = ucUdhl;
    }
    else
    {
        *pucUserDataLen = ucUdl;
        *pucUdhl        = 0;
    }

    *penMsgCoding = pstSmsSubmitInfo->stDcs.enMsgCoding;

    /*lint -save -e516 */
        PS_MEM_FREE(WUEPS_PID_TAF, pstSmsSubmitInfo);
    /*lint -restore */
    return MN_ERR_NO_ERROR;
}


