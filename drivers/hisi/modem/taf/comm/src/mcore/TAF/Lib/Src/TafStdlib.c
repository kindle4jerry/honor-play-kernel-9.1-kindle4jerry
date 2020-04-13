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

#include "TafStdlib.h"
#include "MnErrorCode.h"
#include "MnMsgApi.h"
#include "MnMsgTs.h"



/*****************************************************************************
  2 ��������
*****************************************************************************/

#define    THIS_FILE_ID        PS_FILE_ID_TAF_STD_LIB_C

/*****************************************************************************
  3 ���Ͷ���
*****************************************************************************/

/*****************************************************************************
  4 ��������
*****************************************************************************/
LOCAL TAF_ERROR_CODE_ENUM_UINT32 TAF_STD_DecodeUtf8CharacterFirstByte(
    VOS_UINT8                          *pucUtf8FirstByte,
    VOS_UINT16                         *pusUtf8CharacterContent,
    VOS_UINT32                         *pulUtf8CharacterByteNum
);

/*****************************************************************************
  5 ��������
*****************************************************************************/
LOCAL VOS_UINT8 f_aucMsgAsciiSfxDefAlpha[TAF_STD_MAX_GSM7BITDEFALPHA_NUM] =
{
    '@',  163,   '$',  165,  232,  233,  249,  236,  242,  199,  0x0a, 216,  248,  0x0d, 197,  229,
    0xff, '_',   0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 198,  230,  223,  201,
    ' ',  '!',   '"',  '#',  164,  '%',  '&',  0x27, '(',  ')',  '*',  '+',  ',',  '-',  '.',  '/',
    '0',  '1',   '2',  '3',  '4',  '5',  '6',  '7',  '8',  '9',  ':',  ';',  '<',  '=',  '>',  '?',
    161,  'A',   'B',  'C',  'D',  'E',  'F',  'G',  'H',  'I',  'J',  'K',  'L',  'M',  'N',  'O',
    'P',  'Q',   'R',  'S',  'T',  'U',  'V',  'W',  'X',  'Y',  'Z',  196,  214,  209,  220,  167,
    191,  'a',   'b',  'c',  'd',  'e',  'f',  'g',  'h',  'i',  'j',  'k',  'l',  'm',  'n',  'o',
    'p',  'q',   'r',  's',  't',  'u',  'v',  'w',  'x',  'y',  'z',  228,  246,  241,  252,  224
};

LOCAL VOS_UINT8 f_aucMsgAsciiSfxDefAlphaExt[TAF_STD_MAX_GSM7BITDEFALPHA_NUM] =
{
    0xff, 0xff,  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0c, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff,  0xff, 0xff, '^',  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff,  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, '{',  '}',  0xff, 0xff, 0xff, 0xff, 0xff, '\\',
    0xff, 0xff,  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, '[',  '~',  ']',  0xff,
    '|',  0xff,  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff,  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff,  0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff,  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,

};


/* ��1980�꿪ʼ��������Ϊ��λ��ÿ������� */
LOCAL VOS_UINT16 g_ausTafStdDaysElapsedOfALeapYearSetTab[] = {
  /* �� 0 (����) */  0,
  /* �� 1        */  366,
  /* �� 2        */  366+365,
  /* �� 3        */  366+365+365,
  /* ��Ԫ������  */  366+365+365+365
};

/* ƽ����ÿ�µ����� */
LOCAL VOS_UINT16 g_ausTafStdNormMonthTab[] = {
  /* ---    */ 0,
  /* һ��   */ 31,
  /* ����   */ 31+28,
  /* ����   */ 31+28+31,
  /* ����   */ 31+28+31+30,
  /* ����   */ 31+28+31+30+31,
  /* ����   */ 31+28+31+30+31+30,
  /* ����   */ 31+28+31+30+31+30+31,
  /* ����   */ 31+28+31+30+31+30+31+31,
  /* ����   */ 31+28+31+30+31+30+31+31+30,
  /* ʮ��   */ 31+28+31+30+31+30+31+31+30+31,
  /* ʮһ�� */ 31+28+31+30+31+30+31+31+30+31+30,
  /* ʮ���� */ 31+28+31+30+31+30+31+31+30+31+30+31
};

/* ������ÿ�µ����� */
LOCAL VOS_UINT16 g_ausTafStdLeapMonthTab[] = {
  /* ---    */ 0,
  /* һ��   */ 31,
  /* ����   */ 31+29,
  /* ����   */ 31+29+31,
  /* ����   */ 31+29+31+30,
  /* ����   */ 31+29+31+30+31,
  /* ����   */ 31+29+31+30+31+30,
  /* ����   */ 31+29+31+30+31+30+31,
  /* ����   */ 31+29+31+30+31+30+31+31,
  /* ����   */ 31+29+31+30+31+30+31+31+30,
  /* ʮ��   */ 31+29+31+30+31+30+31+31+30+31,
  /* ʮһ�� */ 31+29+31+30+31+30+31+31+30+31+30,
  /* ʮ���� */ 31+29+31+30+31+30+31+31+30+31+30+31
};


/*****************************************************************************
  6 ��������
*****************************************************************************/

VOS_UINT32 TAF_STD_Itoa(
    VOS_UINT32                          ulDigit,
    VOS_CHAR                           *pcDigitStr,
    VOS_UINT32                         *pulDigitStrLength
)
{
    VOS_INT32                           lCharNum;

    lCharNum = VOS_sprintf_s(pcDigitStr, TAF_SPM_SSC_MAX_LEN, "%d", (VOS_INT)ulDigit);

    *pulDigitStrLength = (VOS_UINT32)lCharNum;

    return VOS_TRUE;
}



VOS_UINT32 TAF_STD_AsciiNum2HexString(
    VOS_UINT8                          *pucSrc,
    VOS_UINT16                         *pusSrcLen
)
{
    VOS_UINT16                          usChkLen;
    VOS_UINT8                           ucTmp;
    VOS_UINT8                           ucLeft;
    VOS_UINT16                          usSrcLen;
    VOS_UINT8                          *pucDst = VOS_NULL_PTR;

    usChkLen        = 0;
    ucTmp           = 0;
    ucLeft          = 0;
    usSrcLen        = *pusSrcLen;
    pucDst          = pucSrc;

    /* ��������������ֽ��򷵻ش��� */
    if (0 != (usSrcLen % 2))
    {
        return VOS_FALSE;
    }

    while (usChkLen < usSrcLen)
    {
        /* the number is 0-9 */
        if(isdigit(pucSrc[usChkLen]))
        {
            ucLeft = pucSrc[usChkLen] - '0';
        }
        /* the number is a-f */
        else if( (pucSrc[usChkLen] >= 'a') && (pucSrc[usChkLen] <= 'f') )
        {
            ucLeft = (pucSrc[usChkLen] - 'a') + 0x0a;
        }
        /* the number is A-F */
        else if( (pucSrc[usChkLen] >= 'A') && (pucSrc[usChkLen] <= 'F') )
        {
            ucLeft = (pucSrc[usChkLen] - 'A') + 0x0a;
        }
        else
        {
            return VOS_FALSE;
        }

        pucDst[ucTmp] = 0xf0 & (ucLeft << 4);
        usChkLen += 1;

        /* the number is 0-9 */
        if(isdigit(pucSrc[usChkLen]))
        {
            pucDst[ucTmp] |= pucSrc[usChkLen] - '0';
        }
        /* the number is a-f */
        else if( (pucSrc[usChkLen] >= 'a') && (pucSrc[usChkLen] <= 'f') )
        {
            pucDst[ucTmp] |= (pucSrc[usChkLen] - 'a') + 0x0a;
        }
        /* the number is A-F */
        else if( (pucSrc[usChkLen] >= 'A') && (pucSrc[usChkLen] <= 'F') )
        {
            pucDst[ucTmp] |= (pucSrc[usChkLen] - 'A') + 0x0a;
        }
        else
        {
            return VOS_FALSE;
        }

        usChkLen += 1;
        ucTmp += 1;
    }

    *pusSrcLen = usSrcLen / 2;

    return VOS_TRUE;
}


VOS_UINT16 TAF_STD_HexAlpha2AsciiString(
    VOS_UINT8                          *pucSrc,
    VOS_UINT16                          usSrcLen,
    VOS_UINT8                          *pucDst
)
{
    VOS_UINT16                          usLen;
    VOS_UINT16                          usChkLen;
    VOS_UINT8                           ucHigh;
    VOS_UINT8                           ucLow;
    VOS_UINT8                          *pucWrite = VOS_NULL_PTR;
    VOS_UINT8                          *pucRead = VOS_NULL_PTR;

    pucWrite = pucDst;
    pucRead  = pucSrc;
    usLen    = 0;
    usChkLen = 0;
    ucHigh   = 0;
    ucLow    = 0;

    /* ɨ�������ִ� */
    while ( usChkLen++ < usSrcLen )
    {
        ucHigh = 0x0F & (*pucRead >> 4);
        ucLow  = 0x0F & *pucRead;

        usLen += 2;    /* ��¼���� */

        if (0x09 >= ucHigh)   /* 0-9 */
        {
            *pucWrite++ = ucHigh + 0x30;
        }
        else if (0x0A <= ucHigh)    /* A-F */
        {
            *pucWrite++ = ucHigh + 0x37;
        }
        else
        {

        }

        if (0x09 >= ucLow)   /* 0-9 */
        {
            *pucWrite++ = ucLow + 0x30;
        }
        else if (0x0A <= ucLow)    /* A-F */
        {
            *pucWrite++ = ucLow + 0x37;
        }
        else
        {

        }

        /* ��һ���ַ� */
        pucRead++;
    }

    return usLen;
}


VOS_UINT32 TAF_STD_ConvertStrToDecInt(
    VOS_UINT8                          *pucSrc,
    VOS_UINT32                          ulSrcLen,
    VOS_UINT32                         *pulDec
)
{
    VOS_UINT32                          ulTmp;
    VOS_UINT32                          ultotal;
    VOS_UINT8                           ulLength;

    ulTmp       = 0;
    ultotal     = 0;
    ulLength    = 0;

    ulTmp = (VOS_UINT32)*pucSrc++;

    while (ulLength++ < ulSrcLen)
    {
        if( (ulTmp  >= '0') && (ulTmp  <= '9') )
        {
            ulTmp  = ulTmp  - '0';
        }
        else
        {
            return VOS_FALSE;
        }

        if (ultotal > 0x0FFFFFFF)
        {
            return VOS_FALSE;
        }
        else
        {
            ultotal = (ultotal * 10) + ulTmp;
            ulTmp = (VOS_UINT32)(*(pucSrc++));
        }
    }

    *pulDec = ultotal;
    return VOS_TRUE;
}


/* MN_UnPack7Bit��MnMsgDecode.c�Ƶ����ļ�������ΪTAF_STD_UnPack7Bit */
/* MN_Pack7Bit��MnMsgEncode.c�Ƶ����ļ�������ΪTAF_STD_Pack7Bit */


VOS_UINT32  TAF_STD_UnPack7Bit(
    const VOS_UINT8                    *pucOrgChar,
    VOS_UINT32                          ulLen,
    VOS_UINT8                           ucFillBit,
    VOS_UINT8                          *pucUnPackedChar
)
{
    /*����ֽڵ�ַ*/
    VOS_UINT32                          ulPos = 0;
     /*���λƫ��*/
    VOS_UINT32                          ulOffset;
    VOS_UINT32                          ulLoop;

    if ((VOS_NULL_PTR == pucOrgChar)
     || (VOS_NULL_PTR == pucUnPackedChar))
    {
        return VOS_ERR;
    }

    /*����Э��23040 9.2.3.24 UDHL��UDH������Fill Bits��SM��ȥ��Fill Bits�����SM(Unit: Septet),���Ի��SM�а����ַ�����*/
    ulOffset = ucFillBit % 8;

    /*��һ�����Ƴ���ǰ��Ч��ƫ��λulOffset���õ��ַ��ĵ�(8 - ulOffset)λ��
      �ڶ�������(8 - ulOffset)С��7λ����Ҫ����һ��OCTET�л�ȡ��(7 - (8 - ulOffset))λ
      ����������ȡ��һ������Դ���±�(ulPos)����Ҫȥ��������λ(ƫ��λulOffset)*/
    for (ulLoop = 0; ulLoop < ulLen; ulLoop++)
    {
        pucUnPackedChar[ulLoop] = (VOS_UINT8)(pucOrgChar[ulPos] >> ulOffset);
        if (ulOffset > 1)
        {
            /*lint -e701*/
            pucUnPackedChar[ulLoop] |= (VOS_UINT8)((pucOrgChar[ulPos + 1UL] << (8 - ulOffset)) & TAF_STD_7BIT_MASK);
            /*lint +e701*/
        }
        else
        {
            pucUnPackedChar[ulLoop] &= TAF_STD_7BIT_MASK;
        }

        ulPos   += (ulOffset + 7) / 8;
        ulOffset = (ulOffset + 7) % 8;
    }

    return VOS_OK;
}


VOS_UINT32  TAF_STD_Pack7Bit(
    const VOS_UINT8                     *pucOrgChar,
    VOS_UINT32                          ulLen,
    VOS_UINT8                           ucFillBit,
    VOS_UINT8                           *pucPackedChar,
    VOS_UINT32                          *pulLen
)
{
    /*����ֽڵ�ַ*/
    VOS_UINT32                          ulPos = 0;
    /*���λƫ��*/
    VOS_UINT32                          ulOffset;
    VOS_UINT32                          ulLoop;

    if ((VOS_NULL_PTR == pucOrgChar)
     || (VOS_NULL_PTR == pucPackedChar)
     || (VOS_NULL_PTR == pulLen))
    {
        return VOS_ERR;
    }

    *pulLen = ((VOS_UINT32)(((ulLen * 7) + ucFillBit) + 7) / 8); /* [false alarm]:ignore buffer overflow */

    ulOffset = ucFillBit % 8;

    /*bit 7   6   5   4   3   2   1   0 */
    /*    |digit1L|   |---ulOffset1---| */ /*����ulOffset1λ*/
    /*                |(0)  digit1H   | */ /*����(8-ulOffset1λ)*/
    /*    |-digit2L-  |   |-ulOffset2-| */ /*ƫ����Ϊ(8-1+ulOffset1)%8*/

    /*��һ�����ճ���ǰ�Ѿ�����ƫ��λulOffset����������Դ��ȡ��һ��OCTET����(8 - ulOffset)λ��
      �ڶ�������(8 - ulOffset)С��7λ����Ҫ����ǰ����Դ�ַ����¸�(7 - (8 - ulOffset))λ��䵽Ŀ�����ݵ���һ��OCTET��
      ����������ȡ��һ��Ŀ�����ݵ��±�(ulPos)���Ѿ���������λ(ƫ��λulOffset)*/
    for (ulLoop = 0; ulLoop < ulLen; ulLoop++)
    {
        if ((pucOrgChar[ulLoop] & (~TAF_STD_7BIT_MASK)) != 0)
        {
            return VOS_ERR;
        }

        pucPackedChar[ulPos] |= (VOS_UINT8)((VOS_UINT32)(pucOrgChar[ulLoop] & TAF_STD_7BIT_MASK) << ulOffset);
        if (ulOffset > 1)
        {
            pucPackedChar[ulPos + 1UL] = (VOS_UINT8)((pucOrgChar[ulLoop] & TAF_STD_7BIT_MASK) >> (8 - ulOffset));
        }

        ulPos   += (ulOffset + 7) / 8;
        ulOffset = (ulOffset + 7) % 8;
    }

    return VOS_OK;
}



VOS_UINT32  TAF_STD_ConvertBcdNumberToAscii(
    const VOS_UINT8                    *pucBcdNumber,
    VOS_UINT8                           ucBcdLen,
    VOS_CHAR                           *pcAsciiNumber
)
{
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

        /*������������ת����Ascii����ʽ*/
        ulRet = TAF_STD_ConvertBcdCodeToAscii(ucBcdCode, &(pcAsciiNumber[ucLoop]));
        if (MN_ERR_NO_ERROR != ulRet)
        {
            return ulRet;
        }
    }

    pcAsciiNumber[ucLoop] = '\0';      /*�ַ���ĩβΪ0*/

    return MN_ERR_NO_ERROR;
}


VOS_UINT32  TAF_STD_ConvertBcdCodeToAscii(
    VOS_UINT8                           ucBcdCode,
    VOS_CHAR                           *pcAsciiCode
)
{
    VOS_CHAR                            cAsciiCode;

    if (VOS_NULL_PTR == pcAsciiCode)
    {
        return MN_ERR_NULLPTR;
    }

    if (ucBcdCode <= 0x09)
    {
        cAsciiCode = (VOS_CHAR)(ucBcdCode + 0x30);
    }
    else if (0x0A == ucBcdCode)
    {
        cAsciiCode = (VOS_CHAR)(ucBcdCode + 0x20);    /*�ַ�'*'*/
    }
    else if (0x0B == ucBcdCode)
    {
        cAsciiCode = (VOS_CHAR)(ucBcdCode + 0x18);    /*�ַ�'#'*/
    }
    else if ((0x0C == ucBcdCode)
          || (0x0D == ucBcdCode)
          || (0x0E == ucBcdCode))
    {
        cAsciiCode = (VOS_CHAR)(ucBcdCode + 0x55);    /*�ַ�'a', 'b', 'c'*/
    }
    else
    {
        return MN_ERR_INVALID_BCD;
    }

    *pcAsciiCode = cAsciiCode;

    return MN_ERR_NO_ERROR;
}


VOS_UINT32  TAF_STD_ConvertAsciiNumberToBcd(
    const VOS_CHAR                     *pcAsciiNumber,
    VOS_UINT8                          *pucBcdNumber,
    VOS_UINT8                          *pucBcdLen
)
{
    VOS_UINT8                           ucLoop;
    VOS_UINT8                           ucBcdCode;
    VOS_UINT32                          ulRet;

    if ((VOS_NULL_PTR == pcAsciiNumber)
     || (VOS_NULL_PTR == pucBcdNumber)
     || (VOS_NULL_PTR == pucBcdLen))
    {
        return MN_ERR_NULLPTR;
    }

    for (ucLoop = 0; pcAsciiNumber[ucLoop] != '\0'; ucLoop++)
    {
        ulRet = TAF_STD_ConvertAsciiCodeToBcd(pcAsciiNumber[ucLoop], &ucBcdCode);
        if (MN_ERR_NO_ERROR != ulRet)
        {
            return ulRet;
        }

        /*����ǰ��Ҫ����Ŀռ���0*/
        pucBcdNumber[(ucLoop / 2)] &= ((ucLoop % 2) == 1) ? 0x0F : 0xF0;

        /*������������Ӧ�Ŀռ�*/
        pucBcdNumber[(ucLoop / 2)] |= (((ucLoop % 2) == 1) ? ((ucBcdCode << 4) & 0xF0) : (ucBcdCode & 0x0F));
    }

    /*�������Ϊ�����������һ���ַ���Ҫ�� F */
    if (1 == (ucLoop % 2))
    {
        pucBcdNumber[(ucLoop / 2)] |= 0xF0;
    }

    *pucBcdLen = (ucLoop + 1) / 2;

    return MN_ERR_NO_ERROR;
}


VOS_UINT32 TAF_STD_ConvertAsciiAddrToBcd(
    MN_MSG_ASCII_ADDR_STRU             *pstAsciiAddr,
    MN_MSG_BCD_ADDR_STRU               *pstBcdAddr
)
{
    VOS_UINT32 ulRet;

    if ((VOS_NULL_PTR == pstAsciiAddr)
     || (VOS_NULL_PTR == pstBcdAddr))
    {
        return MN_ERR_NULLPTR;
    }

    MN_GET_ADDRTYPE(pstBcdAddr->addrType,
                    pstAsciiAddr->enNumType,
                    pstAsciiAddr->enNumPlan);

    ulRet = TAF_STD_ConvertAsciiNumberToBcd((VOS_CHAR *)(pstAsciiAddr->aucAsciiNum),
                              pstBcdAddr->aucBcdNum,
                              &pstBcdAddr->ucBcdLen);

    return ulRet;
}


VOS_UINT32  TAF_STD_ConvertAsciiCodeToBcd(
    VOS_CHAR                            cAsciiCode,
    VOS_UINT8                          *pucBcdCode
)
{
    if (VOS_NULL_PTR == pucBcdCode)
    {
        return MN_ERR_NULLPTR;
    }

    if ((cAsciiCode >= '0')
     && (cAsciiCode <= '9'))
    {
        *pucBcdCode = (VOS_UINT8)(cAsciiCode - '0');
    }
    else if ('*' == cAsciiCode)
    {
        *pucBcdCode = 0x0a;
    }
    else if ('#' == cAsciiCode)
    {
        *pucBcdCode = 0x0b;
    }
    else if (('a' == cAsciiCode)
          || ('b' == cAsciiCode)
          || ('c' == cAsciiCode))
    {
        *pucBcdCode = (VOS_UINT8)((cAsciiCode - 'a') + 0x0c);
    }
    else
    {
        return MN_ERR_INVALID_ASCII;
    }

    return MN_ERR_NO_ERROR;
}


VOS_UINT8 TAF_STD_ConvertDeciDigitToBcd(
    VOS_UINT8                           ucDeciDigit,
    VOS_BOOL                            bReverseOrder
)
{
    VOS_UINT8 ucBcd;

    if (VOS_TRUE == bReverseOrder)
    {
        /*��4BIT�洢ʮ�������ĸ�λ*/
        ucBcd  = ucDeciDigit / 10;
        /*��4BIT�洢ʮ�������ĵ�λ*/
        ucBcd |= (ucDeciDigit % 10) << 4;
    }
    else
    {
        /*��4BIT�洢ʮ�������ĵ�λ*/
        ucBcd  = ucDeciDigit % 10;
        /*��4BIT�洢ʮ�������ĸ�λ*/
        ucBcd |= (VOS_UINT8)((ucDeciDigit / 10) << 4);
    }

    return ucBcd;
}


VOS_UINT32 TAF_STD_ConvertBcdToDeciDigit(
    VOS_UINT8                           ucBcdDigit,
    VOS_BOOL                            bReverseOrder,
    VOS_UINT8                          *pucDigit
)
{
    VOS_UINT8                           ucHigher;
    VOS_UINT8                           ucLower;
    VOS_UINT32                          ulRet;

    ucHigher = (ucBcdDigit >> 4) & 0x0f;
    ucLower  = ucBcdDigit & 0x0f;
    if ((ucHigher > 9) || (ucLower > 9))
    {
        ulRet = MN_ERR_INVALIDPARM;
    }
    else
    {
        ulRet = MN_ERR_NO_ERROR;
    }

    if (VOS_TRUE == bReverseOrder)
    {
        *pucDigit  = (VOS_UINT8)((VOS_UINT8)(ucLower * 10) + ucHigher);
    }
    else
    {
        *pucDigit  = (VOS_UINT8)((VOS_UINT8)ucHigher * 10) + ucLower;
    }

    return ulRet;
}


VOS_UINT32 TAF_STD_RemapAsciiToSelectTable(
    VOS_UINT8                           ucAsciiChar,
    VOS_UINT8                          *pucAlphaTable,
    VOS_UINT32                          ulAlphaTableSize,
    VOS_UINT8                          *pucAlphaChar
)
{
    VOS_UINT32                          ulLoop1;

    if (VOS_NULL_PTR == pucAlphaTable)
    {
        return VOS_FALSE;
    }

    for (ulLoop1 = 0 ; ulLoop1 < ulAlphaTableSize ; ulLoop1++)
    {
        if (pucAlphaTable[ulLoop1] == (ucAsciiChar))
        {
            *pucAlphaChar = (VOS_UINT8)ulLoop1;
            return VOS_TRUE;
        }
    }

    return VOS_FALSE;
}


VOS_UINT32  TAF_STD_ConvertAsciiToDefAlpha(
    const VOS_UINT8                    *pucAsciiChar,
    VOS_UINT32                          ulLen,
    VOS_UINT8                          *pucDefAlpha,
    VOS_UINT32                         *pulDefAlphaLen,
    VOS_UINT32                          ulDefAlphaBuffLen
)
{
    VOS_UINT32                          ulLoop2;
    VOS_UINT32                          ulRet;
    VOS_UINT32                          ulDefAlphaIdx;

    if ((VOS_NULL_PTR == pucAsciiChar)
     || (VOS_NULL_PTR == pucDefAlpha)
     || (VOS_NULL_PTR == pulDefAlphaLen))
    {
        return MN_ERR_NULLPTR;
    }

    ulRet         = MN_ERR_NO_ERROR;
    ulDefAlphaIdx = 0;
    /*
    Ŀǰ�ο�����ƽ̨��֧��23038 6.2.1 GSM 7 bit Default Alphabet���д��ڵ��ַ�����
    ��֧����չ���е��ַ���
    ASCII����GSM 7 bit Default Alphabet�������ֵı�׼ASCII�����ת��ΪGSM 7 bit Default Alphabet��
    �����ܹ�������ַ��Ѳ���ͨ��������δ���ԣ�
    ASCII���������ַ�����{�����¼Ϊ00���ض�������@��������ʧ�ܣ�
    �����ܹ�������ַ��Ѳ���ͨ��������δ���ԣ�
    ��Ҫ�ο�����ƽ̨�Ĵ���
    */
    for (ulLoop2 = 0; ulLoop2 < ulLen; ulLoop2++)
    {
        /*7BIT convert into ASCII ,consider later!!!!!*/
        /* ������ */
        if (ulDefAlphaIdx >= ulDefAlphaBuffLen)
        {
            ulRet = MN_ERR_INVALIDPARM;
            break;
        }

        /* ʹ��Basic Character Set�� */
        if (VOS_TRUE == TAF_STD_RemapAsciiToSelectTable(*pucAsciiChar,
                                                        f_aucMsgAsciiSfxDefAlpha,
                                                        TAF_STD_MAX_GSM7BITDEFALPHA_NUM,
                                                        pucDefAlpha))
        {
            ulDefAlphaIdx++;
            pucDefAlpha++;
        }
        else
        {
            /* ʣ�໺�泤�Ȳ���֧��ʹ����չ����� */
            if ((ulDefAlphaIdx + 1) >= ulDefAlphaBuffLen)
            {
                ulRet = MN_ERR_INVALIDPARM;
                MN_INFO_LOG("TAF_STD_ConvertAsciiToDefAlpha ExtTable need larger buffer");
                break;
            }

            /* ʹ��Basic Character Set Extension�� */
            if (VOS_TRUE == TAF_STD_RemapAsciiToSelectTable(*pucAsciiChar,
                                                            f_aucMsgAsciiSfxDefAlphaExt,
                                                            TAF_STD_MAX_GSM7BITDEFALPHA_NUM,
                                                            pucDefAlpha + 1))
            {
                *pucDefAlpha   = 0x1B;
                ulDefAlphaIdx += 2;
                pucDefAlpha   += 2;
            }
            else
            {
                /* ��չ�����Ҳ�޷����� */
                MN_INFO_LOG1("TAF_STD_ConvertAsciiToDefAlpha Encode Failed ", *pucAsciiChar);
                ulRet = MN_ERR_INVALIDPARM;
            }
        }

        pucAsciiChar++;
    }

    *pulDefAlphaLen = ulDefAlphaIdx;

    return ulRet;
}


VOS_VOID  TAF_STD_ConvertDefAlphaToAscii(
    const VOS_UINT8                     *pucDefAlpha,
    VOS_UINT32                           ulDefAlphaLen,
    VOS_UINT8                           *pucAsciiChar,
    VOS_UINT32                          *pulDstLen
)
{
    VOS_UINT32                          ulLoop;
    VOS_UINT8                           ucPos;
    VOS_UINT32                          ulValidLen = 0;
    VOS_UINT8                           ucExtFlg;

    if ((VOS_NULL_PTR == pucDefAlpha)
     || (VOS_NULL_PTR == pucAsciiChar))
    {
        return;
    }

    ucExtFlg = VOS_FALSE;

    /*
    Ŀǰ�ο�����ƽ̨��֧��23038 6.2.1 GSM 7 bit Default Alphabet���д��ڵ��ַ�����
    ��֧����չ���е��ַ���
    ��ASCII�������ֵ�GSM 7 bit Default Alphabet����ת��Ϊ��׼ASCII�빩��ʾ�ã�
    ��չ�ַ����ת��Ϊ0XFE����ͬ�豸�϶�����˽�н��ͣ�
    �����Ǳ�׼�ַ�ת��Ϊ0XFF����ͬ�豸�϶�����˽�н��ͣ�
    ��Ҫ�ο�����ƽ̨�Ĵ���
    */
    for (ulLoop = 0; ulLoop < ulDefAlphaLen; ulLoop++)
    {
        ucPos           = TAF_STD_7BIT_MASK & pucDefAlpha[ulLoop];
        *pucAsciiChar   = (VOS_FALSE == ucExtFlg) ? f_aucMsgAsciiSfxDefAlpha[ucPos] : f_aucMsgAsciiSfxDefAlphaExt[ucPos];

        if (TAF_STD_NOSTANDARD_ASCII_CODE == (*pucAsciiChar))
        {
            /* �Աȱ��,���޷���ʾ���ַ�ʹ�ÿո��滻 */
            ucExtFlg        = VOS_FALSE;
            (*pucAsciiChar) = ' ';
            pucAsciiChar++;
            ulValidLen++;
        }
        else if (TAF_STD_GSM_7BIT_EXTENSION_FLAG == (*pucAsciiChar))
        {
            /* ��һ��Default Alphaʹ����չ����� */
            (*pucAsciiChar) = ' ';
            ucExtFlg        = VOS_TRUE;
        }
        else
        {
            ucExtFlg        = VOS_FALSE;
            pucAsciiChar++;
            ulValidLen++;
        }
    }

    if (ulValidLen < ulDefAlphaLen)
    {
        *pucAsciiChar = 0;
    }

    *pulDstLen = ulValidLen;

    return;
}



VOS_UINT32  TAF_STD_ConvertBcdCodeToDtmf(
    VOS_UINT8                           ucBcdCode,
    VOS_UINT8                          *pucDtmfCode
)
{
    VOS_UINT8                            ucDtmfCode;

    if (VOS_NULL_PTR == pucDtmfCode)
    {
        return MN_ERR_NULLPTR;
    }

    /*����'0' BCD:0x00, DTMF:0x0A*/
    /*�ַ�'*' BCD:0x0A, DTMF:0x0B*/
    /*�ַ�'#' BCD:0x0B, DTMF:0x0C*/

    if (ucBcdCode == 0x00)
    {
        ucDtmfCode = 0x0A;
    }
    else if (ucBcdCode <= 0x09)
    {
        ucDtmfCode = ucBcdCode;
    }
    else if (0x0A == ucBcdCode)         /*�ַ�'*'*/
    {
        ucDtmfCode = ucBcdCode + 1;
    }
    else if (0x0B == ucBcdCode)
    {
        ucDtmfCode = ucBcdCode + 1;     /*�ַ�'#'*/
    }
    else
    {
        return MN_ERR_INVALID_BCD;
    }

    *pucDtmfCode = ucDtmfCode;

    return MN_ERR_NO_ERROR;
}


VOS_UINT32  TAF_STD_ConvertBcdNumberToDtmf(
    const VOS_UINT8                    *pucBcdNumber,
    VOS_UINT8                           ucBcdLen,
    VOS_UINT8                          *pucDtmfNumber
)
{
    VOS_UINT8                           ucLoop;
    VOS_UINT8                           ucLen;
    VOS_UINT8                           ucBcdCode;
    VOS_UINT32                          ulRet;

    if ((VOS_NULL_PTR == pucBcdNumber)
     || (VOS_NULL_PTR == pucDtmfNumber))
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

        /*������������ת����DTMF����ʽ*/
        ulRet = TAF_STD_ConvertBcdCodeToDtmf(ucBcdCode, pucDtmfNumber);
        if (MN_ERR_NO_ERROR != ulRet)
        {
            return ulRet;
        }

        pucDtmfNumber++;
    }

    return MN_ERR_NO_ERROR;
}




LOCAL VOS_UINT16* TAF_STD_GetDaysOfLeapMonthTabAddr(VOS_VOID)
{
    return g_ausTafStdLeapMonthTab;
}


LOCAL VOS_UINT16* TAF_STD_GetDaysOfNormalMonthTabAddr(VOS_VOID)
{
    return g_ausTafStdNormMonthTab;
}


LOCAL VOS_UINT16* TAF_STD_GetDaysElapsedOfALeapYearSet(VOS_VOID)
{
    return g_ausTafStdDaysElapsedOfALeapYearSetTab;
}


VOS_UINT32 TAF_STD_64Add32
(
    VOS_UINT32                          ulHighAddend,
    VOS_UINT32                          ulLowAddend,
    VOS_UINT32                          ulAddFactor,
    VOS_UINT32                         *pulHighRslt,
    VOS_UINT32                         *pulLowRslt
)
{
    if (0xFFFFFFFF - ulLowAddend >= ulAddFactor)
    {
        *pulLowRslt  = ulLowAddend + ulAddFactor;
        *pulHighRslt = ulHighAddend;
    }
    else
    {
        if (0xFFFFFFFF == ulHighAddend)
        {
            return VOS_ERR;
        }

        *pulHighRslt = ulHighAddend + 1;
        *pulLowRslt = ulAddFactor - (0xFFFFFFFF - ulLowAddend) - 1;
    }

    return VOS_OK;
}


VOS_UINT32 TAF_STD_64Sub32
(
    VOS_UINT32                          ulHighMinuend,
    VOS_UINT32                          ulLowMinuend,
    VOS_UINT32                          ulSubFactor,
    VOS_UINT32                         *pulHighRslt,
    VOS_UINT32                         *pulLowRslt
)
{
    if(ulLowMinuend  >= ulSubFactor)
    {
        *pulHighRslt = ulHighMinuend;
        *pulLowRslt = ulLowMinuend - ulSubFactor;
    }
    else if (ulHighMinuend >= 1)
    {
        *pulHighRslt = ulHighMinuend - 1;
        *pulLowRslt  = ulLowMinuend + (0xFFFFFFFF - ulSubFactor) + 1;
    }
    else
    {
        return VOS_ERR;
    }

    return VOS_OK;
}


VOS_VOID  TAF_STD_U64ToStr(
    VOS_UINT64                         ullNum,
    VOS_UINT8                         *pString
)
{
    VOS_UINT32                          ulProductHigh;
    VOS_UINT32                          ulProductLow;
    VOS_UINT32                          ulQuotientHigh;
    VOS_UINT32                          ulQuotientLow;
    VOS_UINT32                          ulRemainder;
    VOS_UINT32                          ulRst;
    VOS_UINT64                         *pullTempNum;
    VOS_UINT32                          aulTmpNum[2];

    VOS_UINT8                           ucStrLen;

    pullTempNum                 = (VOS_UINT64 *)aulTmpNum;
    *pullTempNum                = ullNum;

    ucStrLen        = 0;

    ulProductHigh   = aulTmpNum[1];
    ulProductLow    = aulTmpNum[0];

    while ((0 != ulProductHigh) || (0 != ulProductLow))
    {
        ulQuotientHigh  = 0;
        ulQuotientLow   = 0;

        ulRst = VOS_64Div32(ulProductHigh,
                            ulProductLow,
                            10,
                            &ulQuotientHigh,
                            &ulQuotientLow,
                            &ulRemainder);
        if (VOS_OK == ulRst)
        {
            ulProductHigh   = ulQuotientHigh;
            ulProductLow    = ulQuotientLow;

            if (0 == ucStrLen)
            {
                *pString = '0' + (VOS_UINT8)ulRemainder;
                ucStrLen++;
                continue;
            }

            TAF_MEM_MOVE_S((pString + 1), ucStrLen, pString, ucStrLen);
            *pString = '0' + (VOS_UINT8)ulRemainder;
            ucStrLen++;
        }
        else
        {
            break;
        }
    }

    return;
}


VOS_UINT32 TAF_STD_ConvertTimeFromSecsToTimeZone
(
    VOS_UINT32                          ulHighSystemTime,
    VOS_UINT32                          ulLowSystemTime,
    TAF_STD_TIME_ZONE_TYPE_STRU        *pstUniversalTimeandLocalTimeZone
)
{
    VOS_UINT16                          i;
    VOS_UINT16                          usDays;
    VOS_UINT32                          ulQuadYyears;
    VOS_UINT16                         *pusMonthTable = VOS_NULL_PTR;
    VOS_UINT16                         *pusLeapMonthTable = VOS_NULL_PTR;
    VOS_UINT16                         *pusNormalMonthTable = VOS_NULL_PTR;
    VOS_UINT16                         *pusDaysElapsedTable = VOS_NULL_PTR;
    VOS_UINT32                          ulHighTmp;
    VOS_UINT32                          ulLowTmp;
    VOS_UINT32                          ulQuotientHigh;
    VOS_UINT32                          ulQuotientLow;
    VOS_UINT32                          ulResult;
    VOS_UINT32                          ulRemainder;

    pusLeapMonthTable                 = TAF_STD_GetDaysOfLeapMonthTabAddr();

    pusNormalMonthTable               = TAF_STD_GetDaysOfNormalMonthTabAddr();

    pusDaysElapsedTable               = TAF_STD_GetDaysElapsedOfALeapYearSet();

    ulHighTmp      = 0;
    ulLowTmp       = 0;
    ulQuotientHigh = 0;
    ulQuotientLow  = 0;
    ulRemainder    = 0;
     /* ʱ�任��ɴ�1980.1.1 ��ʼ������ */
    ulResult = TAF_STD_64Add32(ulHighSystemTime, ulLowSystemTime, (VOS_UINT32)TAF_STD_TIME_ZONE_OFFSET_S, &ulHighTmp, &ulLowTmp);
    if ( VOS_OK != ulResult )
    {
        return VOS_ERR;
    }

     /* ����ϵͳʱ����������㵱ǰʱ������� */
    ulResult = VOS_64Div32(ulHighTmp, ulLowTmp, TAF_STD_SECONDS_PER_MINUTE, &ulQuotientHigh, &ulQuotientLow, &ulRemainder);
    if ( VOS_OK != ulResult )
    {
        return VOS_ERR;
    }
    pstUniversalTimeandLocalTimeZone->usSecond = (VOS_UINT16)ulRemainder;

    /* ����ϵͳʱ����������㵱ǰʱ��ķ����� */
    ulResult = VOS_64Div32(ulQuotientHigh, ulQuotientLow, TAF_STD_MINUTES_PER_HOUR, &ulHighTmp, &ulLowTmp, &ulRemainder);
    if ( VOS_OK != ulResult )
    {
        return VOS_ERR;
    }
    pstUniversalTimeandLocalTimeZone->usMinute = (VOS_UINT16)ulRemainder;

    /* ����ϵͳʱ����������㵱ǰʱ���Сʱ */
    ulResult = VOS_64Div32(ulHighTmp, ulLowTmp, TAF_STD_HOURS_PER_DAY, &ulQuotientHigh, &ulQuotientLow, &ulRemainder);
    if ( VOS_OK != ulResult )
    {
        return VOS_ERR;
    }
    pstUniversalTimeandLocalTimeZone->usHour = (VOS_UINT16)ulRemainder;

    /* ������1980��ʼ��ȥ�˶������� */
    ulResult = VOS_64Div32(ulQuotientHigh, ulQuotientLow, TAF_STD_TIME_ZONE_QUAD_YEAR, &ulHighTmp, &ulLowTmp, &ulRemainder);
    if ( VOS_OK != ulResult )
    {
        return VOS_ERR;
    }
    usDays = (VOS_UINT16)ulRemainder;

    ulQuadYyears = ulLowTmp;

    pstUniversalTimeandLocalTimeZone->usYear = (VOS_UINT16)(TAF_STD_TIME_ZONE_BASE_YEAR + (4 * ulQuadYyears));

    /* ���㵱ǰ�괦���ĸ������� */
    for ( i = 0; i < TAF_STD_DAYS_ELAPSED_OF_A_LEAP_YEAR_SET_TAB_COUNT - 1; i++ )
    {
        if (usDays < pusDaysElapsedTable[i + 1])
        {
            break;
        }
    }

    /* ��ȡ��ǰ���ȥ������ */
    usDays -= pusDaysElapsedTable[i];

    /* ��������һ�� */
    pstUniversalTimeandLocalTimeZone->usYear += (VOS_UINT16)i;

    /* ��������·ݺ���һ�� */

    /* ��ȡ�·ݱ� */
    pusMonthTable = (i == 0) ? pusLeapMonthTable : pusNormalMonthTable;

    /* �����·ݱ� */
    for ( i = 0; i < TAF_STD_NORMAL_MONTH_TAB_COUNT - 1; i++ )
    {
        if (usDays < pusMonthTable[i + 1])
        {
            break;
        }
    }

    /* �������ǰ����һ����.*/
    pstUniversalTimeandLocalTimeZone->usDay = usDays - pusMonthTable[i] + 1;

    /* ������·� */
    pstUniversalTimeandLocalTimeZone->usMonth = (VOS_UINT16)i + 1;

    return VOS_OK;
}


VOS_VOID TAF_STD_ConvertSystemTimeToHighLow(
    VOS_UINT8                          *pucSysTimeByte,
    VOS_UINT32                         *pulHighSystemTime,
    VOS_UINT32                         *pulLowSystemTime
)
{
    VOS_UINT32                          ulTmp;
    VOS_UINT8                          *pucAddr = VOS_NULL_PTR;

    pucAddr = pucSysTimeByte + 1;

    ulTmp = *pucAddr++;
    ulTmp <<= 8;
    ulTmp |= *pucAddr++;
    ulTmp <<= 8;
    ulTmp |= *pucAddr++;
    ulTmp <<= 8;
    ulTmp |= *pucAddr;

    /* ȡsystemtime�ĸ���λ */
    *pulHighSystemTime = (VOS_UINT32)((pucSysTimeByte[0] & 0xF0) >> 4);

    /* ȡsystemtime�ĵ���λ */
    *pulLowSystemTime  = ((((VOS_UINT32)(((VOS_UINT32)(pucSysTimeByte[0] & 0x0F)) << 28)) & 0xF0000000)
                       | ((VOS_UINT32)(ulTmp >> 4) & 0x0FFFFFFF));

}



VOS_UINT16 TAF_STD_TransformBcdMccToDeciDigit(
    VOS_UINT32                          ulBcdMcc
)
{
    /*0x00 06 04 --> 460 */
    VOS_UINT16                          usMcc;

    usMcc = (ulBcdMcc & 0xff) * 100 + ((ulBcdMcc >> 8) & 0xff) * 10 + ((ulBcdMcc >> 16) & 0xff);

    if ( 999 < usMcc )
    {
        usMcc = 0xffff;
    }

    return usMcc;
}


VOS_UINT16 TAF_STD_TransformBcdMncToDeciDigit(
    VOS_UINT32                          ulBcdMnc
)
{
    /* 2λMncת����ʽ:0x00 0f 03 00 --> 03 */
    /* 3λMncת����ʽ:0x0f 03 00 00 --> 003 */
    VOS_UINT16                          usMnc;

    if (0x0f0000 == (ulBcdMnc & 0x0f0000))
    {
        usMnc = (ulBcdMnc & 0xff) * 10 + ((ulBcdMnc >> 8) & 0xff);

        if (usMnc >= 100)
        {
            usMnc = 0xffff;
        }
    }
    else
    {
        usMnc = (ulBcdMnc & 0xff) * 100 + ((ulBcdMnc >> 8) & 0xff) * 10 + ((ulBcdMnc >> 16) & 0xff);

        if (usMnc >= 1000)
        {
            usMnc = 0xffff;
        }
    }

    return usMnc;
}



VOS_UINT8 TAF_STD_TransformBcdImsi1112ToDeciDigit(
    VOS_UINT16                          usBcdImsi1112
)
{
    /*0x03 00 --> 3 */
    VOS_UINT16                          usImsi1112;

    usImsi1112 = ((usBcdImsi1112 ) & 0xff) * 10 + ((usBcdImsi1112 >> 8) & 0xff);

    if ( 100 < usImsi1112 )
    {
        usImsi1112 = 0xffff;
    }

    return (VOS_UINT8)usImsi1112;
}


VOS_UINT16 TAF_STD_TransformCLBcdMncToDeciDigit(
    VOS_UINT16                          usBcdMnc
)
{
    /*0x03 00 --> 03 */
    VOS_UINT16                          usMnc;

    usMnc = (usBcdMnc & 0xff) * 10 + ((usBcdMnc >> 8) & 0xff);

    if ( 100 < usMnc )
    {
        usMnc = 0xffff;
    }

    return usMnc;
}


VOS_UINT32 TAF_STD_TransformDeciDigitToBcdMcc(
    VOS_UINT32                          ulDeciDigitMcc
)
{
    /*460 --->0x00 06 04 */
    VOS_UINT32                          ulBcdMcc;

    if (TAF_STD_INVALID_MCC != ulDeciDigitMcc)
    {
        ulBcdMcc  = (ulDeciDigitMcc % 1000) / 100;

        ulBcdMcc += (ulDeciDigitMcc % 10) << 16;

        ulBcdMcc += ((ulDeciDigitMcc % 100) / 10) << 8;

        return ulBcdMcc;
    }
    else
    {
        return TAF_STD_INVALID_MCC;
    }
}



/*lint -e701*/
VOS_UINT8  TAF_STD_ExtractBitStringToOctet(
    VOS_UINT8                          *pucSrcAddr,
    VOS_UINT8                           ucOffsetPos,
    VOS_UINT8                           ucBitLen
)
{
    VOS_UINT8                          *pucBuffOffset = VOS_NULL_PTR;
    VOS_INT16                           iRemainBitLen;
    VOS_UINT8                           ucExtractByte;
    VOS_UINT8                           ucRemainLen;

    pucBuffOffset = pucSrcAddr;

    iRemainBitLen = (VOS_INT16)(TAF_STD_BIT_LEN_8_BIT - (ucOffsetPos + ucBitLen));

    /* ���һ���ֽ�����usOffsetPos��ʣ��bit�ĳ��ȴ��ڵ���usOffsetPos����ֱ���ڸ��ֽ��н���ȡֵ */
    /* ���һ���ֽ�����usOffsetPos��ʣ��bit�ĳ���С��usOffsetPos,����Ҫ����һ���ֽ��н���ȡֵ*/
    if ( iRemainBitLen >= 0 )
    {
        ucExtractByte =  (VOS_UINT8)(((VOS_UINT8)((*pucBuffOffset) << ucOffsetPos)) >> (ucOffsetPos + iRemainBitLen));
    }
    else
    {
        /* ����ʣ��λ */
        ucRemainLen = (VOS_UINT8)(ucBitLen - (TAF_STD_BIT_LEN_8_BIT - ucOffsetPos));

        ucExtractByte = (VOS_UINT8)(((*pucBuffOffset) & (0xFF >> ucOffsetPos)) << ucRemainLen);

        pucBuffOffset++;

        /* ���ֽ�ʣ��bit���� */
        ucExtractByte |= (VOS_UINT8)(((*pucBuffOffset) & 0xFF) >> (TAF_STD_BIT_LEN_8_BIT - ucRemainLen));
    }

    return ucExtractByte;

}


VOS_UINT32 TAF_STD_ExtractBitStringToDword(
    VOS_UINT8                          *pucSrcAddr,
    VOS_UINT8                           ucOffsetPos,
    VOS_UINT8                           ucBitLen
)
{
    VOS_UINT8                          *pucTmpSrc = VOS_NULL_PTR;
    VOS_UINT32                          ulExtractWord;
    VOS_UINT16                          usRemainBitLen;
    VOS_UINT8                           ucIndex;
    VOS_UINT16                          usByteNum;

    pucTmpSrc = pucSrcAddr;

    if (ucBitLen > TAF_STD_BIT_LEN_32_BIT)
    {
        ucBitLen = TAF_STD_BIT_LEN_32_BIT;
    }

    if (ucBitLen <= TAF_STD_BIT_LEN_8_BIT)
    {
        /* ����bit lengthС�ڵ���8bit�Ĵ��� */
        ulExtractWord = (VOS_UINT32)TAF_STD_ExtractBitStringToOctet( pucTmpSrc,
                                                                     ucOffsetPos,
                                                                     ucBitLen);

        return ulExtractWord;
    }

    /* �����ȥ��ǰ�ֽ���Чbit��ʣ��bit���� */
    usRemainBitLen = (VOS_UINT16)(ucBitLen - (TAF_STD_BIT_LEN_8_BIT - ucOffsetPos));

    /* ��ȡ�׸��ֽ����ݲ��֣����Ƶ���Ӧ�ĸ�λ, �ճ�ʣ��bitλ */
    ulExtractWord  = (VOS_UINT32)((VOS_UINT32)((*pucTmpSrc) & (0xFF >> ucOffsetPos)) << usRemainBitLen);

    /* ʣ�����������Ϊ1�ֽ� */
    usByteNum = (usRemainBitLen / TAF_STD_BIT_LEN_8_BIT) + 1;

    for (ucIndex = 0; ucIndex < usByteNum; ucIndex++)
    {
        /* ָ����һ���ֽ� */
        pucTmpSrc++;

        /* ���ʣ�೤�� */
        if (usRemainBitLen > TAF_STD_BIT_LEN_8_BIT)
        {
            /* ����ʣ��δȡ���bit */
            usRemainBitLen -= TAF_STD_BIT_LEN_8_BIT;

            /* ���ƣ��ճ�ʣ��bitλ */
            ulExtractWord |= (VOS_UINT32)((VOS_UINT8)(*pucTmpSrc) << usRemainBitLen);
        }
        else
        {
            /* ���ֽ�ʣ��bit���� */
            ulExtractWord |= (VOS_UINT32)((*pucTmpSrc) >> (TAF_STD_BIT_LEN_8_BIT - usRemainBitLen));

            /* bit�Ѿ�ȡ�꣬��0 */
            usRemainBitLen = 0;
        }

        if (0 == usRemainBitLen)
        {
            break;
        }
    }

    /* ����ת�����ֽڵĴ��� */
    return ulExtractWord;
}
/*lint +e701*/


VOS_UINT32 TAF_STD_ChangeEndian(
    VOS_UINT8                          *pucSrcStr,
    VOS_UINT32                          ulStrLen,
    VOS_UINT8                          *pucDstStr,
    VOS_UINT8                           ucDataSize
)
{
    VOS_UINT32                          ulIndex;
    VOS_UINT32                          ulInterOrder;
    VOS_UINT8                           ucTmp;

    if ((VOS_NULL_PTR == pucSrcStr)
     || (VOS_NULL_PTR == pucDstStr))
    {
        return TAF_ERR_NULL_PTR;
    }

    MN_INFO_LOG2("TAF_STD_ChangeEndian SLen DSize", ulStrLen, ucDataSize);

    if ((0 == ucDataSize)
     || (ulStrLen < ucDataSize))
    {
        return TAF_ERR_PARA_ERROR;
    }

    ulIndex = 0;

    while (ulIndex + ucDataSize <= ulStrLen)
    {
        for (ulInterOrder = 0; ulInterOrder < (ucDataSize / 2); ulInterOrder++)
        {
            ucTmp = *(pucSrcStr + ulIndex + ulInterOrder);
            *(pucSrcStr + ulIndex + ulInterOrder) = *(pucSrcStr + ulIndex + ucDataSize - ulInterOrder - 1);
            *(pucSrcStr + ulIndex + ucDataSize - ulInterOrder - 1) = ucTmp;
        }
        ulIndex += ucDataSize;
    }

    return TAF_ERR_NO_ERROR;
}


VOS_UINT32 TAF_STD_EncodeUnicodeToUtf8(
    VOS_UINT16                          usUnicode,
    VOS_UINT8                          *pucUtf8Str,
    VOS_UINT32                          ulUtf8Len
)
{
    if ((TAF_STD_UTF8_1BYTE_MAX >= usUnicode)
     && (1 <= ulUtf8Len))
    {
        * pucUtf8Str        = (VOS_UINT8)usUnicode;

        return 1;
    }
    else if ((TAF_STD_UTF8_2BYTE_MAX >= usUnicode)
          && (2 <= ulUtf8Len))
    {
        *(pucUtf8Str + 1)   = (VOS_UINT8)(0x80 |  (usUnicode &  0x3F));
        * pucUtf8Str        = (VOS_UINT8)(0xC0 |  (usUnicode >> 6 ));

        return 2;
    }
    else if (3 <= ulUtf8Len)
    {
        * pucUtf8Str        = (VOS_UINT8)(0xE0 |  (usUnicode >> 12));
        *(pucUtf8Str + 1)   = (VOS_UINT8)(0x80 | ((usUnicode >> 6 ) & 0x3F));
        *(pucUtf8Str + 2)   = (VOS_UINT8)(0x80 |  (usUnicode &  0x3F));

        return 3;
    }
    else
    {
        return 0;
    }
}

LOCAL TAF_ERROR_CODE_ENUM_UINT32 TAF_STD_DecodeUtf8CharacterFirstByte(
    VOS_UINT8                          *pucUtf8FirstByte,
    VOS_UINT16                         *pusUtf8CharacterContent,
    VOS_UINT32                         *pulUtf8CharacterByteNum
)
{
    /* �����λbit������1�ĸ��� */
    for (*pulUtf8CharacterByteNum = 0; *pulUtf8CharacterByteNum < 8; (*pulUtf8CharacterByteNum)++)
    {
        if (0 == ((*pucUtf8FirstByte) & (0x80 >> (*pulUtf8CharacterByteNum))))
        {
            break;
        }
    }

    /* ��֤����ͨ���ԣ�֧�ֽ���ѯutf8�ַ��������ֽ�����������ΪNULL���������ֽ��� */
    if (VOS_NULL_PTR == pusUtf8CharacterContent)
    {
        return TAF_ERR_NO_ERROR;
    }

    /* ��֧�ֳ���4����4�������ֽ����һ���ַ���UTF8���� */
    if (3 < *pulUtf8CharacterByteNum)
    {
        /* ����֡ͷ�쳣������Ŀǰ֧�ֵ�����ֽڸ���������ʧ�� */
        return TAF_DECODE_ERR_UTF8_BEYOND_MAX_BYTE_LIMIT;
    }
    else if (1 < *pulUtf8CharacterByteNum)
    {
        /* utf8�ַ����ɶ���ֽ���� */
        *pusUtf8CharacterContent = *pucUtf8FirstByte & (0x7F >> (*pulUtf8CharacterByteNum));
    }
    else if (0 == *pulUtf8CharacterByteNum)
    {
        /* utf8�ַ��ɵ��ֽ���� */
        *pusUtf8CharacterContent = *pucUtf8FirstByte;

        *pulUtf8CharacterByteNum = 1;
    }
    else
    {
        /* ����֡ͷ�쳣(bit7~bit6: 10)������ʧ�� */
        return TAF_DECODE_ERR_UTF8_ABNORMAL_BYTE_HEADER;
    }

    return TAF_ERR_NO_ERROR;
}


VOS_UINT32 TAF_STD_ConvertUtf8ToUcs2(
    VOS_UINT8                          *pucUtf8Str,
    VOS_UINT32                          ulUtf8Len,
    VOS_UINT16                         *pusUcs2Str,
    VOS_UINT32                          ulUcs2BuffLen,
    VOS_UINT32                         *pulUcs2Idx
)
{
    VOS_UINT32                          ulUcs2Idx;
    VOS_UINT32                          ulUtf8Idx;
    VOS_UINT32                          ulUtf8Num;
    VOS_UINT8                           ucUtf8Char;
    VOS_UINT32                          ulRslt;

    if ((VOS_NULL_PTR == pusUcs2Str)
     || (VOS_NULL_PTR == pucUtf8Str))
    {
        return TAF_ERR_NULL_PTR;
    }

    ulUtf8Num = 0;
    ulUcs2Idx = 0;

    for (ulUtf8Idx = 0; ulUtf8Idx < ulUtf8Len; ulUtf8Idx++)
    {
        ucUtf8Char = *(pucUtf8Str + ulUtf8Idx);

        /* Utf8��һ���ֽ� */
        if (0 == ulUtf8Num)
        {
            ulRslt = TAF_STD_DecodeUtf8CharacterFirstByte(&ucUtf8Char, pusUcs2Str + ulUcs2Idx, &ulUtf8Num);

            /* ͷ�ֽڽ���ͨ�ú����������utf8���ֽ���(����ͷ�ֽ�)������Ҫ��1 */
            ulUtf8Num--;


            if (TAF_ERR_NO_ERROR != ulRslt)
            {
                return ulRslt;
            }
        }
        else
        {
            /* Utf8�����ֽ� */
            if (0x2 == (ucUtf8Char >> 6))
            {
                *(pusUcs2Str + ulUcs2Idx) = (VOS_UINT16)(*(pusUcs2Str + ulUcs2Idx) << 6) | (ucUtf8Char & 0x3F);
                ulUtf8Num--;
            }
            else
            {
                MN_INFO_LOG("TAF_STD_ConvertUtf8ToUcs2 Invaild follow Byte");

                /* ������֡ͷ�쳣������ʧ�� */
                return TAF_DECODE_ERR_UTF8_ABNORMAL_BYTE_CONTENT;
            }
        }

        /* ��ǰUtf8�ֽ���Utf8��������һ���ֽ� */
        if (0 == ulUtf8Num)
        {
            ulUcs2Idx++;
            if (ulUcs2Idx >= ulUcs2BuffLen)
            {
                break;
            }
        }
    }

    *pulUcs2Idx = ulUcs2Idx;


    return TAF_ERR_NO_ERROR;
}


VOS_UINT32 TAF_STD_ConvertUcs2ToUtf8(
    VOS_UINT16                         *pusUcs2Str,
    VOS_UINT32                          ulUcs2Len,
    VOS_UINT8                          *pucUtf8Str,
    VOS_UINT32                          ulUtf8BuffLen
)
{
    VOS_UINT32                          ulUcs2Idx;
    VOS_UINT32                          ulUtf8Idx;
    VOS_UINT32                          ulEncodeLen;

    if ((VOS_NULL_PTR == pusUcs2Str)
     || (VOS_NULL_PTR == pucUtf8Str))
    {
        return 0;
    }

    ulUtf8Idx = 0;

    for (ulUcs2Idx = 0; ulUcs2Idx < ulUcs2Len; ulUcs2Idx++)
    {
        ulEncodeLen  = TAF_STD_EncodeUnicodeToUtf8(*(pusUcs2Str + ulUcs2Idx), pucUtf8Str + ulUtf8Idx, ulUtf8BuffLen - ulUtf8Idx);
        ulUtf8Idx   += ulEncodeLen;

        if (0 == ulEncodeLen)
        {
            break;
        }
    }

    return ulUtf8Idx;
}


VOS_UINT32 TAF_STD_ConvertUcs2To8Bit(
    VOS_UINT16                         *pusUcs2Str,
    VOS_UINT32                          ulUcs2Len,
    VOS_UINT8                          *puc8BitStr,
    VOS_UINT32                          ul8BitBuffLen
)
{
    VOS_UINT32                          ulIndex;
    VOS_UINT32                          ul8BitLen;

    ul8BitLen = ulUcs2Len > ul8BitBuffLen ? ul8BitBuffLen : ulUcs2Len;

    for (ulIndex = 0; ulIndex < ul8BitLen; ulIndex++)
    {
        *(puc8BitStr + ulIndex) = (VOS_UINT8)*(pusUcs2Str + ulIndex);
    }

    return ul8BitLen;
}


VOS_UINT32 TAF_STD_Convert8BitToUcs2(
    VOS_UINT8                          *puc8BitStr,
    VOS_UINT32                          ul8BitLen,
    VOS_UINT16                         *pusUcs2Str,
    VOS_UINT32                          ulUcs2BuffLen
)
{
    VOS_UINT32                          ulIndex;
    VOS_UINT32                          ulUcs2Len;

    ulUcs2Len = ul8BitLen < ulUcs2BuffLen ? ul8BitLen : ulUcs2BuffLen;

    for (ulIndex = 0; ulIndex < ulUcs2Len; ulIndex++)
    {
        *(pusUcs2Str + ulIndex) = *(puc8BitStr + ulIndex);
    }

    return ulUcs2Len;
}



VOS_UINT32 TAF_STD_IsSuitableEncodeForUcs2(
    VOS_UINT16                         *pusUcs2,
    VOS_UINT32                          ulUcs2Len,
    TAF_STD_ENCODING_TYPE_ENUM_U8       enCoding
)
{
    VOS_UINT32                          ulIndex;
    VOS_UINT32                          ulDecodeRet1;
    VOS_UINT32                          ulDecodeRet2;
    VOS_UINT8                           ucTmp;
    VOS_UINT16                          usUcs2Char;

    if (VOS_NULL_PTR == pusUcs2)
    {
        return TAF_ERR_NULL_PTR;
    }

    ucTmp = 0;

    for (ulIndex = 0; ulIndex < ulUcs2Len; ulIndex++)
    {
        usUcs2Char = pusUcs2[ulIndex];

        switch (enCoding)
        {
            case TAF_STD_ENCODING_7BIT:
                ulDecodeRet1 = TAF_STD_RemapAsciiToSelectTable((VOS_UINT8)usUcs2Char,
                                                                f_aucMsgAsciiSfxDefAlpha,
                                                                TAF_STD_MAX_GSM7BITDEFALPHA_NUM,
                                                                &ucTmp);
                ulDecodeRet2 = TAF_STD_RemapAsciiToSelectTable((VOS_UINT8)usUcs2Char,
                                                                f_aucMsgAsciiSfxDefAlphaExt,
                                                                TAF_STD_MAX_GSM7BITDEFALPHA_NUM,
                                                                &ucTmp);
                if (((VOS_FALSE == ulDecodeRet1)
                  && (VOS_FALSE == ulDecodeRet2))
                 || (0xFF < usUcs2Char))
                {
                    return TAF_ERR_ERROR;
                }
                break;

            case TAF_STD_ENCODING_8BIT:
                if (0x7F < usUcs2Char)
                {
                    return TAF_ERR_ERROR;
                }
                break;

            case TAF_STD_ENCODING_UCS2:
            case TAF_STD_ENCODING_UTF8:
                return TAF_ERR_NO_ERROR;

            default:
                return TAF_ERR_ERROR;
        }
    }

    return TAF_ERR_NO_ERROR;
}




VOS_VOID TAF_STD_MemCpy_s(
    VOS_VOID                           *pDestBuffer,
    VOS_UINT32                          ulDestSize,
    const VOS_VOID                     *pSrcBuffer,
    VOS_UINT32                          ulCount,
    VOS_INT32                           lFileIdAndLine
)
{
    VOS_UINT32                          ulMemCpyLen;

    ulMemCpyLen = TAF_MIN(ulDestSize, ulCount);

    if (VOS_NULL_PTR == VOS_MemCpy_s( pDestBuffer, ulDestSize, pSrcBuffer, ulCount ))
    {
        if (VOS_NULL_PTR == VOS_MemCpy_s( pDestBuffer, ulMemCpyLen, pSrcBuffer, ulMemCpyLen ))
        {
            mdrv_om_system_error(TAF_REBOOT_MOD_ID_MEM, 0, lFileIdAndLine, 0, 0 );
        }
    }

    return;
}

/*lint -e429*/

VOS_VOID TAF_STD_MemSet_s(
    VOS_VOID                           *pDestBuffer,
    VOS_UINT32                          ulDestSize,
    VOS_CHAR                            ucChar,
    VOS_UINT32                          ulCount,
    VOS_INT32                           lFileIdAndLine
)
{
    VOS_UINT32                          ulMemSetLen;

    ulMemSetLen = TAF_MIN(ulDestSize, ulCount);

    if (VOS_NULL_PTR == VOS_MemSet_s( pDestBuffer, ulDestSize, (VOS_CHAR)(ucChar), ulCount ))
    {
        if (VOS_NULL_PTR == VOS_MemSet_s( pDestBuffer, ulMemSetLen, (VOS_CHAR)(ucChar), ulMemSetLen ))
        {
            mdrv_om_system_error(TAF_REBOOT_MOD_ID_MEM, 0, lFileIdAndLine, 0, 0 );
        }
    }

    return;
}
/*lint +e429*/

VOS_VOID TAF_STD_MemMove_s(
    VOS_VOID                           *pDestBuffer,
    VOS_UINT32                          ulDestSize,
    const VOS_VOID                     *pSrcBuffer,
    VOS_UINT32                          ulCount,
    VOS_INT32                           lFileIdAndLine
)
{
    VOS_UINT32                          ulMemMoveLen;

    ulMemMoveLen = TAF_MIN(ulDestSize, ulCount);

    if (VOS_NULL_PTR == VOS_MemMove_s( pDestBuffer, ulDestSize, pSrcBuffer, ulCount ))
    {
        if (VOS_NULL_PTR == VOS_MemMove_s( pDestBuffer, ulMemMoveLen, pSrcBuffer, ulMemMoveLen ))
        {
            mdrv_om_system_error(TAF_REBOOT_MOD_ID_MEM, 0, lFileIdAndLine, 0, 0 );
        }
    }

    return;
}





