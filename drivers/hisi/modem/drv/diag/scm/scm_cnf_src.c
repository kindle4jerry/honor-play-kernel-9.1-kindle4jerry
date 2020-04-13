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
**************************************************************************** */
#include <product_config.h>
#include <mdrv.h>
#include <mdrv_diag_system.h>
#include <osl_sem.h>
#include <soc_socp_adapter.h>
#include <bsp_socp.h>
#include <bsp_dump.h>
#include <securec.h>
#include "diag_port_manager.h"
#include "soft_decode.h"
#include "OmCommonPpm.h"
#include "scm_debug.h"
#include "scm_common.h"
#include "scm_cnf_src.h"


#define SOCP_CODER_SRC_CNF     SOCP_CODER_SRC_LOM_CNF1

/* ****************************************************************************
  2 ȫ�ֱ�������
**************************************************************************** */
SCM_CODER_SRC_CFG_STRU      g_astSCMCnfCoderSrcCfg=
{
    SCM_CHANNEL_UNINIT, 
    SOCP_CODER_SRC_CNF,
    SOCP_CODER_DST_OM_CNF,   
    SOCP_DATA_TYPE_0, 
    SOCP_ENCSRC_CHNMODE_CTSPACKET, 
    SOCP_CHAN_PRIORITY_2,       
    SOCP_TRANS_ID_EN,
    SOCP_PTR_IMG_DIS,    
    SCM_CODER_SRC_BDSIZE, 
    SCM_CODER_SRC_RDSIZE, 
    NULL, 
    NULL, 
    NULL, 
    NULL
};


extern SCM_CODER_SRC_DEBUG_STRU g_astScmCnfSrcDebugInfo;

u32 scm_init_cnf_src_buff(void)
{
    u32                          ulRet;


    ulRet = scm_create_cnf_src_buff(&g_astSCMCnfCoderSrcCfg.pucSrcBuf,
                                &g_astSCMCnfCoderSrcCfg.pucSrcPHY,
                                SCM_CODER_SRC_CNF_BUFFER_SIZE);
    if(BSP_OK != ulRet)
    {
        g_astSCMCnfCoderSrcCfg.enInitState   = SCM_CHANNEL_MEM_FAIL;  
        return (u32)BSP_ERROR;
    }
    g_astSCMCnfCoderSrcCfg.ulSrcBufLen   = SCM_CODER_SRC_CNF_BUFFER_SIZE;
    g_astSCMCnfCoderSrcCfg.enInitState   = SCM_CHANNEL_INIT_SUCC;  

    return BSP_OK;
}


/* ****************************************************************************
 �� �� ��  : scm_create_cnf_src_buff
 ��������  : �������Դbuffer�ռ�
 �޸���ʷ  :
**************************************************************************** */
u32 scm_create_cnf_src_buff(u8 **pBufVir, u8 **pBufPhy, u32 ulLen)
{
    unsigned long ulRealAddr;

    /*����uncache�Ķ�̬�ڴ���*/
    *pBufVir = (u8*)scm_UnCacheMemAlloc(ulLen, &ulRealAddr);

    /* �����ڴ�ʧ�� */
    if (NULL == *pBufVir)
    {
        return (u32)BSP_ERROR;
    }

    /* ����bufʵ��ַ */
    *pBufPhy = (u8*)ulRealAddr;

    return BSP_OK;
}



u32 scm_get_cnf_src_buff(
                                    u32 ulDataLen, 
                                    SCM_CODER_SRC_PACKET_HEADER_STRU** pstCoderHeader,
                                    SOCP_BUFFER_RW_STRU *pstSocpBuf)
{
    SOCP_BUFFER_RW_STRU                 stRwBuf = {0};
    SCM_CODER_SRC_PACKET_HEADER_STRU    *pstBuff;
    u32                          *pstBuftmp;
    u32                          ulTrueLen;
    SOCP_CODER_SRC_ENUM_U32             enChanlID;

    /* �ж����ݲ��ܴ���4K */
    if ((0 == ulDataLen) || (ulDataLen > SCM_CODER_SRC_MAX_LEN))
    {
        (void)scm_printf("ulDataLen %d.\n", ulDataLen);
        return (u32)BSP_ERROR;
    }

    if (g_astSCMCnfCoderSrcCfg.enInitState != SCM_CHANNEL_INIT_SUCC)/* �ж�ͨ������ */
    {
        scm_printf("cnf channel buff is not init\n");
        return (u32)BSP_ERROR;/* ����ʧ�� */
    }

    if(SOCP_ENCSRC_CHNMODE_LIST == g_astSCMCnfCoderSrcCfg.enCHMode)
    {
        scm_printf("cnf channel mode is list, error\n");
        return (u32)BSP_ERROR;
    }

    enChanlID = g_astSCMCnfCoderSrcCfg.enChannelID;
    if(BSP_OK != bsp_socp_get_write_buff(enChanlID, &stRwBuf))
    {
        g_astScmCnfSrcDebugInfo.ulGetWriteBufErr ++;
        return (u32)BSP_ERROR;/* ����ʧ�� */
    }

    ulTrueLen = ALIGN_DDR_WITH_8BYTE(ulDataLen);
    if((stRwBuf.u32Size + stRwBuf.u32RbSize) >= (ulTrueLen + SCM_HISI_HEADER_LENGTH))
    {
        /*��Ҫ���������ַ���ϲ�*/
        pstBuff = (SCM_CODER_SRC_PACKET_HEADER_STRU*)scm_UncacheMemPhyToVirt((u8*)stRwBuf.pBuffer,
                                    g_astSCMCnfCoderSrcCfg.pucSrcPHY,
                                    g_astSCMCnfCoderSrcCfg.pucSrcBuf,
                                    g_astSCMCnfCoderSrcCfg.ulSrcBufLen);

        if(stRwBuf.u32Size >= SCM_HISI_HEADER_LENGTH)
        {
            pstBuff->ulHisiMagic = SCM_HISI_HEADER_MAGIC;
            pstBuff->ulDataLen   = ulDataLen;
        }
        else if(stRwBuf.u32Size >= 4)
        {
            pstBuff->ulHisiMagic = SCM_HISI_HEADER_MAGIC;

            pstBuftmp = (u32*)g_astSCMCnfCoderSrcCfg.pucSrcBuf;
            *pstBuftmp      = ulDataLen;
        }
        else    /* TODO: Ӧ��û��stRwBuf.u32SizeΪ0�ĳ��� */
        {
            pstBuftmp = (u32*)g_astSCMCnfCoderSrcCfg.pucSrcBuf;

            *(pstBuftmp++)  = SCM_HISI_HEADER_MAGIC;
            *pstBuftmp      = ulDataLen;
        }

        *pstCoderHeader     = pstBuff;
        (void)memcpy_s(pstSocpBuf, sizeof(*pstSocpBuf), &stRwBuf, sizeof(stRwBuf));

        return BSP_OK;
    }
    else
    {
        g_astScmCnfSrcDebugInfo.ulGetCoherentBuffErr++;
        return (u32)BSP_ERROR;
    }

}



void scm_cnf_src_buff_mempy(SCM_CODER_SRC_MEMCPY_STRU *pInfo, SOCP_BUFFER_RW_STRU *pstSocpBuf)
{
    void    *pDst;

    /* �������Ŀ����������̲����Խ��������ɵ��õĵط���֤ */
    if(pInfo->uloffset < pstSocpBuf->u32Size)
    {
        if((pInfo->uloffset + pInfo->ulLen) <= pstSocpBuf->u32Size)
        {
            (void)memcpy_s(((u8*)pInfo->pHeader + pInfo->uloffset), pstSocpBuf->u32Size-pInfo->uloffset, pInfo->pSrc, pInfo->ulLen);          
            scm_FlushCpuWriteBuf();
        }
        else
        {
            (void)memcpy_s(((u8*)pInfo->pHeader + pInfo->uloffset),pstSocpBuf->u32Size-pInfo->uloffset,
                pInfo->pSrc, (pstSocpBuf->u32Size - pInfo->uloffset));
            scm_FlushCpuWriteBuf();
            
            pDst = g_astSCMCnfCoderSrcCfg.pucSrcBuf;
            (void)memcpy_s(pDst, (pInfo->uloffset + pInfo->ulLen - pstSocpBuf->u32Size),
                ((u8*)pInfo->pSrc + (pstSocpBuf->u32Size - pInfo->uloffset)),
                (pInfo->uloffset + pInfo->ulLen - pstSocpBuf->u32Size));           
            scm_FlushCpuWriteBuf();
            
        }
    }
    else
    {
        pDst = g_astSCMCnfCoderSrcCfg.pucSrcBuf;

        pDst = (u8*)pDst + (pInfo->uloffset - pstSocpBuf->u32Size);
        (void)memcpy_s(pDst, pInfo->ulLen, pInfo->pSrc, pInfo->ulLen);
        scm_FlushCpuWriteBuf();
        
    }
}

static u32 scm_send_cnf_src_data_list(SOCP_CODER_SRC_ENUM_U32 enChanlID, SOCP_BUFFER_RW_STRU stRwBuf, u8 *pucSendDataAddr, u32 ulSendLen)
{
    u32 ulBDNum;
    SOCP_BD_DATA_STRU stBDData;
    
    /* �������BD��ֵ */
    ulBDNum = (stRwBuf.u32Size + stRwBuf.u32RbSize) / sizeof(SOCP_BD_DATA_STRU);

    /* �ж��Ƿ��пռ� */
    if (1 >= ulBDNum)
    {
        return (u32)BSP_ERROR;
    }

    stRwBuf.pBuffer = (char*)scm_UncacheMemPhyToVirt((u8*)stRwBuf.pBuffer,
                                    g_astSCMCnfCoderSrcCfg.pucSrcPHY,
                                    g_astSCMCnfCoderSrcCfg.pucSrcBuf,
                                    g_astSCMCnfCoderSrcCfg.ulSrcBufLen);

   	memset_s(&stBDData, sizeof(stBDData), 0, sizeof(stBDData));
	 
	stBDData.ulDataAddr = (u32)((unsigned long)pucSendDataAddr);
    stBDData.usMsgLen   = (u16)ulSendLen;
    stBDData.enDataType = SOCP_BD_DATA;

    if(stRwBuf.u32Size >= sizeof(stBDData))
    {
        (void)memcpy_s(stRwBuf.pBuffer, stRwBuf.u32Size, &stBDData, sizeof(stBDData));    /* �������ݵ�ָ���ĵ�ַ */
        scm_FlushCpuWriteBuf();            
    }
    else  /*�ؾ�����*/
    {
        (void)memcpy_s(stRwBuf.pBuffer, stRwBuf.u32Size, &stBDData, stRwBuf.u32Size);
        (void)memcpy_s(stRwBuf.pRbBuffer, stRwBuf.u32RbSize, ((u8*)(&stBDData))+stRwBuf.u32Size, sizeof(stBDData)-stRwBuf.u32Size);
        scm_FlushCpuWriteBuf();             
    }
     
    if (BSP_OK != bsp_socp_write_done(enChanlID, sizeof(stBDData)))   /* ��ǰ����д����� */
    {
        SCM_CODER_SRC_ERR("SCM_SendCoderSrc: Write Buffer is Error", enChanlID, 0);/* ��¼Log */
        return (u32)BSP_ERROR;/* ����ʧ�� */
    }

    return BSP_OK;
}

static u32 scm_send_cnf_src_data_ctspacket(SOCP_CODER_SRC_ENUM_U32 enChanlID, SOCP_BUFFER_RW_STRU stRwBuf, u8 *pucSendDataAddr, u32 ulSendLen)
{
    SCM_CODER_SRC_PACKET_HEADER_STRU*   pstCoderHeader;
    
    if(stRwBuf.u32Size < SCM_HISI_HEADER_LENGTH)
    {
        g_astScmCnfSrcDebugInfo.ulSendFirstNotEnough ++;
        return (u32)BSP_ERROR;
    }

    stRwBuf.pBuffer = (char*)scm_UncacheMemPhyToVirt((u8*)stRwBuf.pBuffer,
                                    g_astSCMCnfCoderSrcCfg.pucSrcPHY,
                                    g_astSCMCnfCoderSrcCfg.pucSrcBuf,
                                    g_astSCMCnfCoderSrcCfg.ulSrcBufLen);
    if(stRwBuf.pBuffer != (char*)pucSendDataAddr)
    {
        g_astScmCnfSrcDebugInfo.ulSendAddrErr++;
        return (u32)BSP_ERROR;
    }

    pstCoderHeader = (SCM_CODER_SRC_PACKET_HEADER_STRU*)pucSendDataAddr;
    if((pstCoderHeader->ulDataLen != ulSendLen)||(pstCoderHeader->ulHisiMagic != SCM_HISI_HEADER_MAGIC))
    {
        g_astScmCnfSrcDebugInfo.ulSendHeaderErr++;
        return (u32)BSP_ERROR;
    }
    scm_FlushCpuWriteBuf();
    /*��һ�������ռ䲻��HISI��ͷ����*/
    ulSendLen = ALIGN_DDR_WITH_8BYTE(ulSendLen);
    if(BSP_OK != bsp_socp_write_done(enChanlID, (ulSendLen + SCM_HISI_HEADER_LENGTH)))
    {
        g_astScmCnfSrcDebugInfo.ulSendWriteDoneErr ++;
        return (u32)BSP_ERROR;
    }
    g_astScmCnfSrcDebugInfo.ulSendDataLen += ulSendLen;
    g_astScmCnfSrcDebugInfo.ulSendPacketNum ++;

    return BSP_OK;
}


u32 scm_send_cnf_src_data(u8 *pucSendDataAddr, u32 ulSendLen)
{
    SOCP_BUFFER_RW_STRU                 stRwBuf = {0};
    SOCP_CODER_SRC_ENUM_U32             enChanlID;
    u32 ret;

    /* �ж�����ָ��ͳ��ȵ���ȷ�����Ȳ��ܴ���4K */
    if ((NULL == pucSendDataAddr)
        ||(0 == ulSendLen)
        /*||(SCM_CODER_SRC_MAX_LEN < ulSendLen)*/)
    {
        return (u32)BSP_ERROR;
    }

    if (g_astSCMCnfCoderSrcCfg.enInitState != SCM_CHANNEL_INIT_SUCC)/* �ж�ͨ������ */
    {
        scm_printf("cnf channel buff is not init\n");
        return (u32)BSP_ERROR;/* ����ʧ�� */
    }

    enChanlID = g_astSCMCnfCoderSrcCfg.enChannelID;
    if (BSP_OK != bsp_socp_get_write_buff(enChanlID, &stRwBuf))
    {
        g_astScmCnfSrcDebugInfo.ulGetWriteBufErr ++;
        return (u32)BSP_ERROR;/* ����ʧ�� */
    }


    if(SOCP_ENCSRC_CHNMODE_LIST == g_astSCMCnfCoderSrcCfg.enCHMode)
    {

       ret = scm_send_cnf_src_data_list(enChanlID, stRwBuf, pucSendDataAddr, ulSendLen);

    }
    else if(SOCP_ENCSRC_CHNMODE_CTSPACKET == g_astSCMCnfCoderSrcCfg.enCHMode)
    {
        ret = scm_send_cnf_src_data_ctspacket(enChanlID, stRwBuf, pucSendDataAddr, ulSendLen);
    }
    else
    {
        return (u32)BSP_ERROR;
    }
    return ret;
}

u32 scm_cnf_src_chan_init(void)
{

    if (BSP_OK != scm_cnf_src_chan_cfg(&g_astSCMCnfCoderSrcCfg))
    {
        g_astSCMCnfCoderSrcCfg.enInitState = SCM_CHANNEL_CFG_FAIL;  /* ��¼ͨ����ʼ�����ô��� */

        return (u32)BSP_ERROR;/* ����ʧ�� */
    }

    if(BSP_OK != bsp_socp_start(g_astSCMCnfCoderSrcCfg.enChannelID))
    {
        g_astSCMCnfCoderSrcCfg.enInitState = SCM_CHANNEL_START_FAIL;  /* ��¼ͨ���������ô��� */

        return (u32)BSP_ERROR;/* ����ʧ�� */
    }

    g_astSCMCnfCoderSrcCfg.enInitState = SCM_CHANNEL_INIT_SUCC;     /* ��¼ͨ����ʼ�����ô��� */

    return BSP_OK;/* ���سɹ� */
}



u32 scm_cnf_src_chan_cfg(SCM_CODER_SRC_CFG_STRU *pstCfg)
{
    SOCP_CODER_SRC_CHAN_S               stChannel;          /* ��ǰͨ����������Ϣ */

    stChannel.u32DestChanID = pstCfg->enDstCHID;            /*  Ŀ��ͨ��ID */
    stChannel.eDataType     = pstCfg->enDataType;           /*  �������ͣ�ָ�����ݷ�װЭ�飬���ڸ��ö�ƽ̨ */
    stChannel.eMode         = pstCfg->enCHMode;             /*  ͨ������ģʽ */
    stChannel.ePriority     = pstCfg->enCHLevel;            /*  ͨ�����ȼ� */
	stChannel.eTransIdEn    = pstCfg->enTransIdEn;          /*  SOCP TransIdʹ��λ */
	stChannel.ePtrImgEn     = pstCfg->enPtrImgEn;           /*  SOCPָ�뾵��ʹ��λ */
    stChannel.u32BypassEn   = SOCP_HDLC_ENABLE;             /*  ͨ��bypassʹ�� */
    stChannel.eDataTypeEn   = SOCP_DATA_TYPE_EN;            /*  ��������ʹ��λ */
    stChannel.eDebugEn      = SOCP_ENC_DEBUG_DIS;           /*  ����λʹ�� */

    stChannel.sCoderSetSrcBuf.pucInputStart  = pstCfg->pucSrcPHY;                             /*  ����ͨ����ʼ��ַ */
    stChannel.sCoderSetSrcBuf.pucInputEnd    = (pstCfg->pucSrcPHY + pstCfg->ulSrcBufLen)-1;   /*  ����ͨ��������ַ */
    stChannel.sCoderSetSrcBuf.pucRDStart     = pstCfg->pucRDPHY;                              /* RD buffer��ʼ��ַ */
    stChannel.sCoderSetSrcBuf.pucRDEnd       = (pstCfg->pucRDPHY + pstCfg->ulRDBufLen)-1;     /*  RD buffer������ַ */
    stChannel.sCoderSetSrcBuf.u32RDThreshold = SCM_CODER_SRC_RD_THRESHOLD;                    /* RD buffer�����ϱ���ֵ */

    if (BSP_OK != bsp_socp_coder_set_src_chan(pstCfg->enChannelID, &stChannel))
    {
        SCM_CODER_SRC_ERR("SCM_CoderSrcChannelCfg: Search Channel ID Error", pstCfg->enChannelID, 0);/* ��ӡʧ�� */

        return (u32)BSP_ERROR;/* ���ش��� */
    }

    pstCfg->enInitState = SCM_CHANNEL_INIT_SUCC; /* ��¼ͨ����ʼ�����ô��� */

    return BSP_OK;/* ���سɹ� */
}





