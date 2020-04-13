

#ifndef __NV_STRU_WAS_H__
#define __NV_STRU_WAS_H__


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 Include Headfile
*****************************************************************************/
#if (VOS_OS_VER != VOS_WIN32)
#pragma pack(4)
#else
#pragma pack(push, 4)
#endif

#include "PsTypeDef.h"
#include "nv_id_guas.h"

/*****************************************************************************
  2 Macro
*****************************************************************************/
#define WAS_NV_PTL_VER_R3                       (0)                             /* WAS_PTL_VER_R3 */
#define WAS_NV_PTL_VER_R4                       (1)                             /* WAS_PTL_VER_R4 */
#define WAS_NV_PTL_VER_R5                       (2)                             /* WAS_PTL_VER_R5 */
#define WAS_NV_PTL_VER_R6                       (3)                             /* WAS_PTL_VER_R6 */
#define WAS_NV_PTL_VER_R7                       (4)                             /* WAS_PTL_VER_R7 */
#define WAS_NV_PTL_VER_R8                       (5)                             /* WAS_PTL_VER_R8 */
#define WAS_NV_PTL_VER_R9                       (6)                             /* WAS_PTL_VER_R9 */


/*****************************************************************************
  3 Massage Declare
*****************************************************************************/

/*****************************************************************************
  4 Enum
*****************************************************************************/
/*****************************************************************************
 ö����    : WAS_TX_RX_FREQ_SEPARAT_ENUM_UINT8
 Э����  :
 ASN.1���� :
 ö��˵��  :
*****************************************************************************/
enum WAS_TX_RX_FREQ_SEPARAT_ENUM
{
    WAS_TX_RX_FREQ_SEPARAT_DEFAULT_TX_RX_SEPARATION = 0,
    WAS_TX_RX_FREQ_SEPARAT_SPARE2,
    WAS_TX_RX_FREQ_SEPARAT_SPARE1,
    WAS_TX_RX_FREQ_SEPARAT_BUTT
} ;
typedef VOS_UINT8 WAS_TX_RX_FREQ_SEPARAT_ENUM_UINT8;

/*****************************************************************************
 ö����    : WAS_DL_SIMUL_HS_DSCH_CFG_ENUM_UINT8
 Э����  :
 ASN.1���� :
 ö��˵��  :
*****************************************************************************/
enum  WAS_DL_SIMUL_HS_DSCH_CFG_ENUM
{
    WAS_DL_SIMUL_HS_DSCH_CFG_KBPS32 = 0,
    WAS_DL_SIMUL_HS_DSCH_CFG_KBPS64,
    WAS_DL_SIMUL_HS_DSCH_CFG_KBPS128,
    WAS_DL_SIMUL_HS_DSCH_CFG_KBPS384,
    WAS_DL_SIMUL_HS_DSCH_CFG_BUTT
};
typedef VOS_UINT8 WAS_DL_SIMUL_HS_DSCH_CFG_ENUM_UINT8;

/*****************************************************************************
 ö����    : WAS_PTL_VER_TYPE_ENUM_UINT8
 Э����  : 10.2.39    RRC CONNECTION REQUEST
 ASN.1���� : AccessStratumReleaseIndicator
 ö��˵��  : Э��汾
             Absence of the IE implies R3.
             The IE also indicates the release of the RRC transfer syntax
             supported by the UE 13 spare values are needed
*****************************************************************************/
enum WAS_PTL_VER_TYPE_ENUM
{
    WAS_PTL_VER_ENUM_R3                 = WAS_NV_PTL_VER_R3,                    /* _H2ASN_Replace  WAS_NV_PTL_VER_R3 = 0 */
    WAS_PTL_VER_ENUM_R4                 = WAS_NV_PTL_VER_R4,                    /* _H2ASN_Replace  WAS_NV_PTL_VER_R4 = 1 */
    WAS_PTL_VER_ENUM_R5                 = WAS_NV_PTL_VER_R5,                    /* _H2ASN_Replace  WAS_NV_PTL_VER_R5 = 2 */
    WAS_PTL_VER_ENUM_R6                 = WAS_NV_PTL_VER_R6,                    /* _H2ASN_Replace  WAS_NV_PTL_VER_R6 = 3 */
    WAS_PTL_VER_ENUM_R7                 = WAS_NV_PTL_VER_R7,                    /* _H2ASN_Replace  WAS_NV_PTL_VER_R7 = 4 */
    WAS_PTL_VER_ENUM_R8                 = WAS_NV_PTL_VER_R8,                    /* _H2ASN_Replace  WAS_NV_PTL_VER_R8 = 5 */
    WAS_PTL_VER_ENUM_R9                 = WAS_NV_PTL_VER_R9,                    /* _H2ASN_Replace  WAS_NV_PTL_VER_R9 = 6 */
    WAS_PTL_VER_ENUM_BUTT
};
typedef VOS_UINT8 WAS_PTL_VER_TYPE_ENUM_UINT8;

/*****************************************************************************
  5 STRUCT
*****************************************************************************/

/*****************************************************************************
 �ṹ��    : WAS_RF_CAPA_STRU
 Э����  : 10.3.3.33 RF capability FDD
 ASN.1���� :
 �ṹ˵��  : RF������Ϣ
 DESCRIPTION: RF������Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT8                               ucPowerClass;                       /* UE���ʼ���                               */
    WAS_TX_RX_FREQ_SEPARAT_ENUM_UINT8       enTxRxFreqSeparate;                 /* Tx/Rx Ƶ������                           */
    VOS_UINT8                               aucReserve1[2];                     /* 4�ֽڶ��룬���� */
}WAS_RF_CAPA_STRU;

/*****************************************************************************
 �ṹ��    : WAS_NVIM_UE_CAPA_CUSTOMED_STRU
 �ṹ˵��  : ����������洢��NVIM�е�UE������Ϣ,��ǰ��BOSTON��֧����ʹ��   ID:9008 en_NV_Item_WAS_RadioAccess_Capa_New
 DESCRIPTION: ����������洢��NVIM�е�UE������Ϣ,��ǰ��BOSTON��֧����ʹ��
*****************************************************************************/
typedef struct
{
    VOS_UINT32                              ulHspaStatus;                       /* 0��ʾδ����,��ôDPA��UPA��֧��;1��ʾ���� */

    WAS_RF_CAPA_STRU                        stRfCapa;                           /* RF ������Ϣ                                  */

    PS_BOOL_ENUM_UINT8                      enSupportPwrBoosting;               /* 16QAM������أ��Ƿ�֧��E-DPCCH Power Boosting*/
    PS_BOOL_ENUM_UINT8                      enReserve1;                         /* ����enSf4Support��ԭλ����Ϊreserved */

    WAS_DL_SIMUL_HS_DSCH_CFG_ENUM_UINT8     enDlSimulHsDschCfg;                 /* ENUMERATED  OPTIONAL                         */
    WAS_PTL_VER_TYPE_ENUM_UINT8             enAsRelIndicator;                   /* Access Stratum Release Indicator             */

    PS_BOOL_ENUM_UINT8                      enHSDSCHSupport;                    /* �Ƿ�֧��enHSDSCHSupport�ı�־                */
    VOS_UINT8                               ucHSDSCHPhyCategory;                /* ֧��HS-DSCH���������ͱ�־                  */

    PS_BOOL_ENUM_UINT8                      enMacEhsSupport;
    VOS_UINT8                               ucHSDSCHPhyCategoryExt;
    PS_BOOL_ENUM_UINT8                      enMultiCellSupport;                 /* �Ƿ�֧�� Multi cell support,���֧��MultiCell,Ex2���� */
    VOS_UINT8                               ucHSDSCHPhyCategoryExt2;            /* HS-DSCH physical layer category extension 2 */

    PS_BOOL_ENUM_UINT8                      enCellSpecTxDiversityForDc;         /*  This IE is optionally present if Dual-Cell HSDPA is supported. Otherwise it is not needed.
                                                                                    The IE is not needed in the INTER RAT HANDOVER INFO message. Otherwise, it is optional*/
    PS_BOOL_ENUM_UINT8                      enReserve2;                         /* ����enEFDPCHSupport��ԭλ����Ϊreserved */
    PS_BOOL_ENUM_UINT8                      enEDCHSupport;                      /* �Ƿ�֧��EDCH�ı�־                           */
    VOS_UINT8                               ucEDCHPhyCategory;                  /* ֧��UPA�ĵȼ�                                */
    PS_BOOL_ENUM_UINT8                      enSuppUl16QAM;                      /* �Ƿ�֧������16QAM����֧��ʱucEDCHPhyCategoryExt����Ч */
    VOS_UINT8                               ucEDCHPhyCategoryExt;               /* ���е��ز�֧��16QAMʱ����д7 */
    PS_BOOL_ENUM_UINT8                      enSuppEDpdchInterpolationFormula;   /* 16QAM������أ��Ƿ�֧��E-DPDCH power interpolation formula */
    PS_BOOL_ENUM_UINT8                      enReserve3;                         /* ����enSuppHsdpaInFach��ԭλ����Ϊreserved */
    PS_BOOL_ENUM_UINT8                      enReserve4;                         /* ����enSuppHsdpaInPch��ԭλ����Ϊreserved */

    PS_BOOL_ENUM_UINT8                      enMacIsSupport;                     /* �Ƿ�֧��MAC_I/MAC_Is */

    PS_BOOL_ENUM_UINT8                      enReserve5;                         /* ����enFDPCHSupport��ԭλ����Ϊreserved */

    PS_BOOL_ENUM_UINT8                      enReserve6;                         /* ����enHsscchLessSupport��ԭλ����Ϊreserved */
    PS_BOOL_ENUM_UINT8                      enReserve7;                         /* ����enUlDpcchDtxSupport��ԭλ����Ϊreserved */

    PS_BOOL_ENUM_UINT8                      enAdjFreqMeasWithoutCmprMode;       /* �Ƿ�֧�� Adjacent Frequency measurements without compressed mode */

    PS_BOOL_ENUM_UINT8                      enMimoSingleStreamStrict;           /* �Ƿ�����ֻ��ʹ�õ���MIMO */
    PS_BOOL_ENUM_UINT8                      enMimoWithDlTxDiversity;            /* R9���ԣ���MIMO����ʱ�����п����ŵ��Ƿ�����ʹ�÷ּ� */

    /* V7r1 ˫ģ����NV�� LTE���� */
    PS_BOOL_ENUM_UINT8                      enSptAbsPriBasedReselInUtra;        /* ֧��UTRA�е����ȼ���ѡ��Ĭ��Ϊ0��1Ϊ֧�֣�0Ϊ��֧�� */

    VOS_UINT8                               ucHSDSCHPhyCategoryExt3;            /* HS-DSCH physical layer category extension 3 */
    PS_BOOL_ENUM_UINT8                      enDcMimoSupport;                    /* �Ƿ�֧��DC+MIMO */
    PS_BOOL_ENUM_UINT8                      enSuppCommEDCH;                     /* E-RACH�������� */

    PS_BOOL_ENUM_UINT8                      enDcUpaSupport;                     /* �Ƿ�֧��DC UPA�ı�־ */
    VOS_UINT8                               ucEDCHPhyCategoryExt2;              /* EDCH  category extension 2*/
    PS_BOOL_ENUM_UINT8                      enEdpdchGainFactorFlg;              /* E-DPDCH���ʻ�������ʹ�ܱ�־λ */
    PS_BOOL_ENUM_UINT8                      enReserve8;                         /* ����enHo2EutranUnSupportFlg��ԭλ����Ϊreserved */
    PS_BOOL_ENUM_UINT8                      enReserve9;                         /* ����enEutranMeasUnSupportFlg��ԭλ����Ϊreserved */
    VOS_UINT8                               aucReserve2[5];
}WAS_NVIM_UE_CAPA_CUSTOMED_STRU;


/*****************************************************************************
 �ṹ��    : WAS_NVIM_UE_CAPA_STRU
 �ṹ˵��  : �洢��NVIM�е�UE������Ϣ               ID:9008 en_NV_Item_WAS_RadioAccess_Capa_New
 DESCRIPTION: �洢��NVIM�е�UE������Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                              ulHspaStatus;                       /* 0��ʾδ����,��ôDPA��UPA��֧��;1��ʾ���� */

    WAS_RF_CAPA_STRU                        stRfCapa;                           /* RF ������Ϣ                                  */

    PS_BOOL_ENUM_UINT8                      enSupportPwrBoosting;               /* 16QAM������أ��Ƿ�֧��E-DPCCH Power Boosting*/
    PS_BOOL_ENUM_UINT8                      enSf4Support;                       /* �Ƿ�֧��ul dpcch ʹ�� slotFormat4 */

    WAS_DL_SIMUL_HS_DSCH_CFG_ENUM_UINT8     enDlSimulHsDschCfg;                 /* ENUMERATED  OPTIONAL                         */
    WAS_PTL_VER_TYPE_ENUM_UINT8             enAsRelIndicator;                   /* Access Stratum Release Indicator             */

    PS_BOOL_ENUM_UINT8                      enHSDSCHSupport;                    /* �Ƿ�֧��enHSDSCHSupport�ı�־                */
    VOS_UINT8                               ucHSDSCHPhyCategory;                /* ֧��HS-DSCH���������ͱ�־                  */

    PS_BOOL_ENUM_UINT8                      enMacEhsSupport;
    VOS_UINT8                               ucHSDSCHPhyCategoryExt;
    PS_BOOL_ENUM_UINT8                      enMultiCellSupport;                 /* �Ƿ�֧�� Multi cell support,���֧��MultiCell,Ex2���� */
    VOS_UINT8                               ucHSDSCHPhyCategoryExt2;            /* HS-DSCH physical layer category extension 2 */

    PS_BOOL_ENUM_UINT8                      enCellSpecTxDiversityForDc;         /*  This IE is optionally present if Dual-Cell HSDPA is supported. Otherwise it is not needed.
                                                                                    The IE is not needed in the INTER RAT HANDOVER INFO message. Otherwise, it is optional*/
    PS_BOOL_ENUM_UINT8                      enEFDPCHSupport;                    /* �Ƿ�֧��E-FDPCH�ı�־,FDPCH֧��ʱ��NV����Ч */
    PS_BOOL_ENUM_UINT8                      enEDCHSupport;                      /* �Ƿ�֧��EDCH�ı�־                           */
    VOS_UINT8                               ucEDCHPhyCategory;                  /* ֧��UPA�ĵȼ�                                */
    PS_BOOL_ENUM_UINT8                      enSuppUl16QAM;                      /* �Ƿ�֧������16QAM����֧��ʱucEDCHPhyCategoryExt����Ч */
    VOS_UINT8                               ucEDCHPhyCategoryExt;               /* ���е��ز�֧��16QAMʱ����д7 */
    PS_BOOL_ENUM_UINT8                      enSuppEDpdchInterpolationFormula;   /* 16QAM������أ��Ƿ�֧��E-DPDCH power interpolation formula */
    PS_BOOL_ENUM_UINT8                      enSuppHsdpaInFach;                  /* ֧��CELL_FACH��HS-DSCH�Ľ��� */
    PS_BOOL_ENUM_UINT8                      enSuppHsdpaInPch;                   /* ֧��CELL_PCH��URA_PCH��HS-DSCH�Ľ��� */

    PS_BOOL_ENUM_UINT8                      enMacIsSupport;                     /* �Ƿ�֧��MAC_I/MAC_Is */

    PS_BOOL_ENUM_UINT8                      enFDPCHSupport;                     /* �Ƿ�֧��FDPCH�ı�־                          */

    PS_BOOL_ENUM_UINT8                      enHsscchLessSupport;                /* �Ƿ�֧�� hsscchlessHsdschOperation           */
    PS_BOOL_ENUM_UINT8                      enUlDpcchDtxSupport;                /* �Ƿ�֧�� discontinuousDpcchTransmission      */

    PS_BOOL_ENUM_UINT8                      enAdjFreqMeasWithoutCmprMode;       /* �Ƿ�֧�� Adjacent Frequency measurements without compressed mode */

    PS_BOOL_ENUM_UINT8                      enMimoSingleStreamStrict;           /* �Ƿ�����ֻ��ʹ�õ���MIMO */
    PS_BOOL_ENUM_UINT8                      enMimoWithDlTxDiversity;            /* R9���ԣ���MIMO����ʱ�����п����ŵ��Ƿ�����ʹ�÷ּ� */

    /* V7r1 ˫ģ����NV�� LTE���� */
    PS_BOOL_ENUM_UINT8                      enSptAbsPriBasedReselInUtra;        /* ֧��UTRA�е����ȼ���ѡ��Ĭ��Ϊ0��1Ϊ֧�֣�0Ϊ��֧�� */

    VOS_UINT8                               ucHSDSCHPhyCategoryExt3;            /* HS-DSCH physical layer category extension 3 */
    PS_BOOL_ENUM_UINT8                      enDcMimoSupport;                    /* �Ƿ�֧��DC+MIMO */
    PS_BOOL_ENUM_UINT8                      enSuppCommEDCH;                     /* E-RACH�������� */

    PS_BOOL_ENUM_UINT8                      enDcUpaSupport;                     /* �Ƿ�֧��DC UPA�ı�־ */
    VOS_UINT8                               ucEDCHPhyCategoryExt2;              /* EDCH  category extension 2*/
    PS_BOOL_ENUM_UINT8                      enEdpdchGainFactorFlg;              /* E-DPDCH���ʻ�������ʹ�ܱ�־λ */
    PS_BOOL_ENUM_UINT8                      enHo2EutranUnSupportFlg;            /* �Ƿ�֧�ֵ�L��HO */
    PS_BOOL_ENUM_UINT8                      enEutranMeasUnSupportFlg;           /* �Ƿ�֧�ֵ�����̬L�Ĳ��� */
    VOS_UINT8                               aucReserve2[5];
}WAS_NVIM_UE_CAPA_STRU;


/*****************************************************************************
  6 UNION
*****************************************************************************/


/*****************************************************************************
  7 Extern Global Variable
*****************************************************************************/


/*****************************************************************************
  8 Fuction Extern
*****************************************************************************/


/*****************************************************************************
  9 OTHERS
*****************************************************************************/

#if (VOS_OS_VER != VOS_WIN32)
#pragma pack()
#else
#pragma pack(pop)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif

/* end of nv_stru_was.h */

