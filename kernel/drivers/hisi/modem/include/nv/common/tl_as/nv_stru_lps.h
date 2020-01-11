/******************************************************************************

    Copyright(C)2008,Hisilicon Co. LTD.

 ******************************************************************************
  File Name       : PsNvInterface.h
  Description     : PsNvInterface.h header file
  History           :
     1.Name+ID      yyyy-mm-dd  Draft Enact
******************************************************************************/

#ifndef __LPSNVINTERFACE_H__
#define __LPSNVINTERFACE_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


/*****************************************************************************
  1 Include Headfile
*****************************************************************************/
#include  "vos.h"
#include  "PsTypeDef.h"
#include  "nv_id_tlas.h"
#include  "nv_stru_rrc.h"
#include  "msp_nvim.h"
#if (VOS_OS_VER != VOS_WIN32) && (!defined NV_DEFINE)
#include  "msp.h"
#endif
#pragma pack(4)

/*****************************************************************************
  2 macro
*****************************************************************************/
#define MAX_GLOBAL_PRANT_NUM   5

/* gaojishan-dcom-resel-cfg */
#define LPS_NV_JP_DCOM_CON_TO_IDLE_BIT        ( 0x08000000 )
/* gaojishan-dcom-resel-cfg */
#define LPS_NV_JP_DCOM_REL_OFFSET_BIT        ( 0x10000000 )
#define LPS_NV_JP_DCOM_REL_OFFSET_DEBUG_BIT  ( 0x20000000 )
/* gaojishan-fast-dorm-cfg */
#define LPS_NV_JP_DCOM_FAST_DORM_BIT  ( 0x40000000 )

/*****************************************************************************
  3 Massage Declare
*****************************************************************************/


/*****************************************************************************
  4 Enum
*****************************************************************************/

/*****************************************************************************
  5 STRU
*****************************************************************************/

/*****************************************************************************
 �ṹ��    : LPS_NV_LONG_BIT_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : Э��ջ�ĺ�Э�鹦����صĿ��صĽṹ��
*****************************************************************************/
typedef struct
{
    VOS_UINT32  bitFlag01                   :1;
    VOS_UINT32  bitFlag02                   :1;
    VOS_UINT32  bitFlag03                   :1;
    VOS_UINT32  bitFlag04                   :1;
    VOS_UINT32  bitFlag05                   :1;
    VOS_UINT32  bitFlag06                   :1;
    VOS_UINT32  bitFlag07                   :1;
    VOS_UINT32  bitFlag08                   :1;
    VOS_UINT32  bitFlag09                   :1;
    VOS_UINT32  bitFlag10                   :1;
    VOS_UINT32  bitFlag11                   :1;
    VOS_UINT32  bitFlag12                   :1;
    VOS_UINT32  bitFlag13                   :1;
    VOS_UINT32  bitFlag14                   :1;
    VOS_UINT32  bitFlag15                   :1;
    VOS_UINT32  bitFlag16                   :1;
    VOS_UINT32  bitFlag17                   :1;
    VOS_UINT32  bitFlag18                   :1;
    VOS_UINT32  bitFlag19                   :1;
    VOS_UINT32  bitFlag20                   :1;
    VOS_UINT32  bitFlag21                   :1;
    VOS_UINT32  bitFlag22                   :1;
    VOS_UINT32  bitFlag23                   :1;
    VOS_UINT32  bitFlag24                   :1;
    VOS_UINT32  bitFlag25                   :1;
    VOS_UINT32  bitFlag26                   :1;
    VOS_UINT32  bitFlag27                   :1;
    VOS_UINT32  bitFlag28                   :1;
    VOS_UINT32  bitFlag29                   :1;
    VOS_UINT32  bitFlag30                   :1;
    VOS_UINT32  bitFlag31                   :1;
    VOS_UINT32  bitFlag32                   :1;
}LPS_NV_LONG_BIT_STRU;


/*****************************************************************************
 �ṹ��    : LPS_NV_FLOW_CONTROL
 Э����  :
 ASN.1���� :
 �ṹ˵��  : Э��ջ���ؽṹ��
*****************************************************************************/
typedef struct
{
    /* �����ܿ��� */
    VOS_UINT32                          ulFlowCtrlFlag;
    /*ulFcInitFlag���س�ʼ��ѡ�� 0-��RRC��̬ѡ��1-������NV����п���*/
    VOS_UINT32                          ulFcInitFlag;
    VOS_UINT32                          ulFcPdcpTarget;
    VOS_UINT32                          ulTargetIPMax;
    VOS_UINT32                          ulSendSduMax;
    VOS_UINT32                          ulDlSduMax;
    VOS_UINT32                          ulULIpMax;
    VOS_UINT32                          ulMeasGap;
    VOS_UINT32                          ulSduGap;
}LPS_NV_FLOW_CONTROL;


/*****************************************************************************
 �ṹ��    : LPS_NV_GLOBAL_PRINT
 Э����  :
 ASN.1���� :
 �ṹ˵��  : Э��ջ��ӡȫ�ֱ����ṹ��
*****************************************************************************/
typedef struct
{
    /* ��ӡ�ܿ��� 0:�رմ�ӡȫ�ֱ�����1: ��ӡһ����2:��ӡ���������� 3 4 5 */
    VOS_UINT32                          ulGlobalPrintFlag;
    VOS_UINT32                          aulPara[MAX_GLOBAL_PRANT_NUM];
}LPS_NV_GLOBAL_PRINT_STRU;


/*****************************************************************************
 �ṹ��    : LPS_SWITCH_PARA_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : Э��ջ�ĺ�Э�鹦����صĿ��صĽṹ��
*****************************************************************************/
typedef struct
{
    /* ����TA Timer��ʱSRS��PUCCH�ͷſ��� 0:�رգ�1:�򿪣�Ĭ�Ϲر� */
    VOS_UINT32                          ulCloseTaTimer;

    /* ����SR���������� 0:�ر�  1:�򿪣�Ĭ�Ϲر� */
    VOS_UINT32                          ulSrTrigFlag;

    /* ����SR����������뿪�� 0:�رգ�1:�򿪣�Ĭ�Ϲر� */
    VOS_UINT32                          ulCloseSrRandFlag;

    /*ͬʧ�����أ�0Ϊ�رգ�1Ϊ�򿪡�Ĭ��Ϊ�رգ�����Ϊ��*/
    /*VOS_UINT32                          ulSyncCtrlFlag;*/

    /*����̬�������أ�0Ϊ�رգ�1Ϊ�򿪡�Ĭ��Ϊ�رգ�����Ϊ��*/
    VOS_UINT32                          ulConnMeasFlg;

    /*���ò���IND��ϢƵ�ʣ�������ʾ�ϱ����: ȡֵ����Ҫ���ڵ���1*/
    VOS_UINT32                          ulMeasReportMaxNum;

    /*0:�ر�ץ������ 1:��ץ������ Ĭ���Ǵ�*/
    VOS_UINT32                          ulIfForwardToPc;

    /*�򿪰�ȫ���ܿ��أ�������Ҫʱ���øñ�־*/
    VOS_UINT32                          ulSmcControl;

    /*���eNB��TDD�Ľ�������*/
    /*VOS_UINT32                          ulMsg4OnlyPadding;*/

    /*�ж��Ƿ�BARС������*/
    VOS_UINT32                          ulCloseBarCell;

    /*DRX���ܿ��� 0:�ر�  1:��*/
    VOS_UINT32                          ulDrxControlFlag;

   /*�ⳡ����׮���뿪�� 0:�ر�  1:��.Ĭ��Ϊ�ر�*/
    VOS_UINT32                          ulFieldTestSwitch;

    /* PCO���ܿ��أ�0Ϊ�رգ�1Ϊ�򿪡�Ĭ��Ϊ�� */
    VOS_UINT32                          ulPcoFlag;

    /*���ؽṹ*/
    LPS_NV_FLOW_CONTROL                  stPsNvFlowCtl;

    /************************stPsGcfFlag01����BIT����***************************
     bitFlag01:��ʾGCF���Գ���TAU��Ϣ�Ƿ���ܣ�ƽ̨ȱʡֵΪ1��
               0: ���ܣ�1:������
     bitFlag02:��ʾGCF���Գ���msg4�������أ�ƽ̨ȱʡֵΪ1��
               0: ��ʾ��Э��ʵ��; 1:��ʾ����ܷ���ʵ��
     bitFlag03:��ʾGCF���Գ����Ƿ�֧��24.301 Table D.1.1�н���ԭ�����ã�ƽ̨ȱʡֵΪ1��
               0: ֧��; 1:��֧��
     bitFlag04:��ʾGCF���Գ���ָʾ��ȫ�����Ƿ�֧�ֲ���ģʽ������ģʽ֧�ֿ��������㷨��ƽ̨ȱʡֵΪ1��
               0: ֧��; 1:��֧��
    ****************************************************************************/
    LPS_NV_LONG_BIT_STRU                 stPsGcfFlag01;

    /************************stPsGcfFlag02����BIT����***************************
     stPsGcfFlag01����BIT����:
     bitFlag01:
     bitFlag02:
    ****************************************************************************/
    LPS_NV_LONG_BIT_STRU                 stPsGcfFlag02;

    /************************stPsFunFlag01����BIT����***************************
     bitFlag01: Band64�Ƿ�֧�֣�ȱʡֵ:0; 0:��֧��;1:֧��
     bitFlag02: ɾ��SDFʱ�Ƿ�Я��Qos��Ϣ,ȱʡֵ:0; 0:Я��;1:��Я��
     bitFlag03: �Ƿ��������̬�յ���ue��ҵ��Ѱ��������ͷ�,ȱʡֵ:0; 0:�ͷ�;1:���ͷ�
     bitFlag04: У�鰲ȫ���ܿ���,ȱʡֵ:0; 0:��;1:�ر�
     bitFlag05:
     bitFlag06:
     bitFlag07: ���Ź��ܺ���֮ǰ��װ������ʱ����DRB������PDCP��ڶ���,0Ϊ�رգ�1Ϊ�򿪡�Ĭ��Ϊ�ر�
     bitFlag08: Printʱ���Ż����أ�ȱʡֵ:0; 0:��;1:��;����RRM����ʱʱ�Զ���Ч��
     bitFlag09: �����Ϣʱ���Ż����أ�ȱʡֵ:0; 0:��;1:��;
     bitFlag10: MBMS��֧�ֿ��أ�ȱʡֵ:0; 0:��;1:��;
     bitFlag11: SBM�������󿪹أ��ض�band֧���ض��Ĵ���.ȱʡֵ:0; 0:��;1:��;
     bitFlag12: �������С���Ĵ����Ƕ���Э��Ƶ���ڣ�ȱʡֵ:1; 0:��;1:��;
     bitFlag13: ���Բ�����,ģ���л�ʧ��������ȱʡֵ:1; 0:��;1:��;
     bitFlag14: DCM�������� GU��L���л�NAS���жϱ���TA;ȱʡֵ:0; 0:��;1:��;
     bitFlag15: �Ƿ�֧��ETWS����;ȱʡֵ:1; 0:��;1:��;
     bitFlag16: �Ƿ�֧��CMAS����;ȱʡֵ:1; 0:��;1:��;
     bitFlag17:
     bitFlag18: L�ؽ�ʱ�Ƿ�����UTRAN;ȱʡֵ:1; 0:��;1:��;
     bitFlag19: L�ؽ�ʱ�Ƿ�����GSM;ȱʡֵ:1; 0:��;1:��;
     bitFlag20: ���ֽ��յ�ϵͳ��Ϣʱ,���С��RSRP����С���趨ֵ�������жϷ���ҪbarС����;ȱʡֵ:0; 0:��;1:��;
     bitFlag21: NCC�������һ��Ǵ�������Ŀǰ����Э��ʵ�֣�ȱʡֵ:0; 0��ʾ����Э�飬1��ʾ������Э��
     bitFlag22: �Ƿ�֧�ֱ�������,ȱʡֵ:0;1:�أ�0:����
     bitFlag23: �ؽ�ʱ��Ҫ����GAP�Ƿ���������������һ������㣬ȱʡֵ:1; 1:����0:��
     bitFlag24:
     bitFlag25:
     bitFlag26: IDLE����ѡǰ���ж�NCC��ȱʡֵ:0; 0��ʾ��Ҫ�жϣ�1��ʾ���жϡ�
     bitFlag27: V7R1�ձ�DCOM����ȱʡֵ:0; 0:��;1:��;
     bitFlag28: V7R1�ձ�DCOM����ȱʡֵ:0; 0:��;1:��;
     bitFlag29: V7R1�ձ�DCOM����ȱʡֵ:0; 0:��;1:��;
     bitFlag30: V7R1�ձ�DCOM����ȱʡֵ:0; 0:��;1:��;
     bitFlag31: V7R1�ձ�DCOM����ȱʡֵ:0; 0:��;1:��;
     bitFlag32: RRM����ʱ��ȱʡ�رմ�ӡ�Ƿ���Ч��ȱʡֵ:0; 1:����Ч��0:��Ч��
    ****************************************************************************/
    LPS_NV_LONG_BIT_STRU                 stPsFunFlag01;

    /************************stPsFunFlag02����BIT����***************************
     bitFlag01: CA���Կ���:ȱʡֵ:0; 0:��;1:��:;
     bitFlag02:
     bitFlag03:
     bitFlag04: CMAS��פ��֮ǰ����פ��֮���ϱ���ȱʡֵ:0;0: פ��֮���ϱ�; 1:פ��ǰ�󶼿����ϱ�
     bitFlag05:
     bitFlag06:
     bitFlag07: �����ѣ�ֻ��L��ģ.����GUģ����.ȱʡֵ:0; 0:��;1:��;
     bitFlag08: ETWS����ʱ��; 1:�������ͣ�0:������ٷ���
     bitFlag09: TL L2�ؼ��¼��ϱ�-ȱʡֵ:0;0:��;1:��
     bitFlag10: LTE L2 ������Ϣ�ϱ�-ȱʡֵ:0;0:��;1:��
     bitFlag11: LIST��������Ƶ���Ƿ�����2�Ρ�0:��;1:��
     bitFlag12: ����ָ��ģʽ�ض���������Ƿ������������ģʽ���ض�������; 0:��������ָ��ģʽ���ض���֮�������������ģʽ���ض���;1:ֻ��������ָ��ģʽ���ض���
     bitFlag13: �Ƿ�֧�ְ�ȫ�����ļ���ʱ�������ĵ�NAS�ܾ���Ϣ��ȱʡֵ: 0; 0: ��֧�� 1: ֧��
     bitFlag14: LTE CAС��״̬��Ϣ�ϱ�-ȱʡֵ:0;0:��;1:��
     bitFlag15: Ϊ�������BUG���µ�CSFB����FR�ص�Lʱ�����ղ���paging�����⣬���õĽ���㷢�����ϵͳ�任��L�·���TAU��������type2���Ϳ��ء�ȱʡֵ0.0: �ر� 1:��
     bitFlag16: LTEģ���л�NAS���Ա���TA,ȱʡֵ:0; 0:��; 1:��
     bitFlag17: ESR�����з����л�,δ����TAU����,�ط�ESR��Ϣ���ƿ���,ȱʡֵ:0; 0:���ش� 1:�ش�
     bitFlag18: csfb�����ղ�������release�����Ż����أ�ȱʡֵ:0;0:��;1:��
     bitFlag19: LRRC����쳣�����ϱ�CHR���ܿ���,ȱʡֵ:1; 0:�ر�;1:��
     bitFlag20: ��˫���л�UE������̬��ȡ����,0:��;1:��;chicagoƽ̨Ĭ�Ͽ�,����ƽ̨Ĭ�Ϲر�
     bitFlag21: UE��֧��CAʱ,����Ǳ�ǿ��CA,UE�Ƿ�ظ�RECFG_CMP����;ȱʡֵ:0;  0:���ظ�CMP; 1:�ظ�CMP
     bitFlag22: ̨��CMAS��ʱ��������; ȱʡֵ:0;  0:�ر�; 1:��;
     bitFlag23:
     bitFlag24:
     bitFlag25:
     bitFlag26:
     bitFlag27:
     bitFlag28:
     bitFlag29:
     bitFlag30:
     bitFlag31:
     bitFlag32:
    ****************************************************************************/
    LPS_NV_LONG_BIT_STRU                 stPsFunFlag02;

    
    LPS_NV_LONG_BIT_STRU                 stPsFunFlag03;

   /************************stPsFunFlag04����BIT����***************************
     bitFlag01: ���LTE����Ѱ����� ����,IDLE̬������UE Paging��Ĭ��Ϊ0.
                0:���ܹر�  1:���ܴ�
     bitFlag02:
     bitFlag03:
     bitFlag04:
     bitFlag05:
     bitFlag06: ����L2 MAC�������ʱ���ڸ���С���Ƿ�����С���뾶������Ż���1��ʾ����,Ĭ�Ϲرգ��ɲ�Ʒ�߶���
     bitFlag07: ����L2 MAC�������ʱ����Preamble��2�Ƿ�����С���뾶������Ż�,1��ʾ������Ĭ�Ϲرգ��ɲ�Ʒ�߶���
     bitFlag08:
     bitFlag09:
     bitFlag10:
     bitFlag11:
     bitFlag12:
     bitFlag13:
     bitFlag14:
     bitFlag15:
     bitFlag16:
     bitFlag17:
     bitFlag18:
     bitFlag19:
     bitFlag20:
     bitFlag21:
     bitFlag22:
     bitFlag23:
     bitFlag24:
     bitFlag25:
     bitFlag26:
     bitFlag27:
     bitFlag28:
     bitFlag29:
     bitFlag30:
     bitFlag31:
     bitFlag32:
    ****************************************************************************/
    LPS_NV_LONG_BIT_STRU                 stPsFunFlag04;

    LPS_NV_GLOBAL_PRINT_STRU             stPsNvGlobalPrint;
}LPS_SWITCH_PARA_STRU;


/*****************************************************************************
 �ṹ��    : RRC_UE_EUTRA_CAP_STRU
 Э����  :
 ASN.1���� :
 �ṹ˵��  : UE EUTRA������Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitFeatureGroupIndsPresent    : 1;
    VOS_UINT32                          bitUeCapV920IesPresent        : 1;
    VOS_UINT32                          bitSpare                      : 30;
    VOS_UINT8                           aucReserved[2];
    /* ��������UE�����汾��1��֧�֣�0����֧�֣��ӵ͵���λ�ֱ�����ָʾRel8,Rel9,.... */
    VOS_UINT8                           ucAsRelBitmap;
    RRC_UE_CATEGORY_ENUM_UINT8          enUeCatg;
    RRC_UE_CAP_PDCP_PARA_STRU           stPdcpPara;
    RRC_UE_CAP_PHY_PARA_STRU            stPhyPara;
    RRC_UE_CAP_RF_PARA_STRU             stRfPara;
    RRC_UE_CAP_MEAS_PARA_STRU           stMeasPara;
    RRC_UE_CAP_FEATURE_GROUP_IND_STRU   stFeatrueGroupInds;
    RRC_UE_CAP_INTER_RAT_PARA_STRU      stInterRatPara;
    RRC_UE_EUTRA_CAP_V920_IES_STRU      stUeCapV920Ies;
} LRRC_NV_UE_EUTRA_CAP_STRU;


/*****************************************************************************
 �ṹ��    : ����log�����Ƿ��

 �ṹ˵��  : cPowerOnlogC��cPowerOnlogA��Ϊ1���˹��ܲ���Ч
*****************************************************************************/
typedef struct
{
    /* C�˵Ŀ���log�Ƿ��*/
    VOS_INT8                            cPowerOnlogC;

    /* AP�Ŀ���log�Ƿ��,Ĭ��Ϊ0����A��linux�ں˳�ʼ��ʱ����SOCP��50M�Ƿ�����޸Ĵ�NV��ֵ:���ڣ���ֵ�ᱻ�޸�Ϊ1�����򣬱���0���� */
    VOS_INT8                            cPowerOnlogA;
    VOS_INT8                            cSpare1;
    VOS_INT8                            cSpare2;
}NV_POWER_ON_LOG_SWITCH_STRU;


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

#endif /* end of PsNvInterface.h */

