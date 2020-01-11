

#ifndef  CSS_AT_INTERFACE_H
#define  CSS_AT_INTERFACE_H

/*****************************************************************************
  1 ͷ�ļ�����
*****************************************************************************/
#include "vos.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 �궨��
*****************************************************************************/
#define MCC_INFO_VERSION_LEN                 (9)
#define AT_CSS_MAX_MCC_ID_NUM                (17)
#define AT_CSS_BLACK_CELL_LIST_VERSION_LEN   (9)
#define AT_CSS_CLOUD_LINE_VERSION_LEN        (9)                 /* �ƶ�Ԥ�ø�����·�汾���ַ������� */
#define AT_CSS_PLMN_MAX_LINE_NUM             (64)                /* �ƶ�Ԥ�ø�����·һ��PLMN�°����������·���� */
#define AT_CSS_TACLAC_MAX_LINE_NUM           (10)                /* �ƶ�Ԥ�ø�����·һ��TAC/LAC����Ӧ�������·���� */



/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/

enum CSS_AT_MSG_TYPE_ENUM
{
    /* AT->CSS */
    ID_AT_CSS_MCC_INFO_SET_REQ                = 0x0001,                           /* _H2ASN_MsgChoice AT_CSS_MCC_INFO_SET_REQ_STRU */
    ID_AT_CSS_MCC_VERSION_INFO_REQ            = 0x0002,                           /* _H2ASN_MsgChoice AT_CSS_MCC_VERSION_INFO_REQ_STRU */
    ID_AT_CSS_BLACK_CELL_LIST_SET_REQ         = 0x0003,                           /* _H2ASN_MsgChoice AT_CSS_BLACK_CELL_LIST_SET_REQ_STRU */
    ID_AT_CSS_BLACK_CELL_LIST_QUERY_REQ       = 0x0004,                           /* _H2ASN_MsgChoice AT_CSS_BLACK_CELL_LIST_QUERY_REQ_STRU */
    ID_AT_CSS_LINE_INDEX_LIST_SET_REQ         = 0x0005,                           /* _H2ASN_MsgChoice AT_CSS_LINE_INDEX_LIST_SET_REQ_STRU */
    ID_AT_CSS_LINE_DETAIL_SET_REQ             = 0x0006,                           /* _H2ASN_MsgChoice AT_CSS_LINE_DETAIL_SET_REQ_STRU */
    ID_AT_CSS_LINE_INDEX_LIST_QUERY_REQ       = 0x0007,                           /* _H2ASN_MsgChoice AT_CSS_LINE_INDEX_LIST_QUERY_REQ_STRU */

    /* CSS->AT */
    ID_CSS_AT_MCC_INFO_SET_CNF                = 0x1001,                           /* _H2ASN_MsgChoice CSS_AT_MCC_INFO_SET_CNF_STRU */
    ID_CSS_AT_MCC_VERSION_INFO_CNF            = 0x1002,                           /* _H2ASN_MsgChoice CSS_AT_MCC_VERSION_INFO_CNF_STRU */
    ID_CSS_AT_QUERY_MCC_INFO_NOTIFY           = 0x1003,                           /* _H2ASN_MsgChoice CSS_AT_QUERY_MCC_INFO_NOTIFY_STRU */
    ID_CSS_AT_BLACK_CELL_LIST_SET_CNF         = 0x1004,                           /* _H2ASN_MsgChoice CSS_AT_BLACK_CELL_LIST_SET_CNF_STRU */
    ID_CSS_AT_BLACK_CELL_LIST_QUERY_CNF       = 0x1005,                           /* _H2ASN_MsgChoice CSS_AT_BLACK_CELL_LIST_QUERY_CNF_STRU */
    ID_CSS_AT_BLACK_CELL_MCC_NOTIFY           = 0x1006,                           /* _H2ASN_MsgChoice CSS_AT_BLACK_CELL_MCC_NOTIFY_STRU */
    ID_CSS_AT_LINE_INDEX_LIST_SET_CNF         = 0x1007,                           /* _H2ASN_MsgChoice CSS_AT_LINE_INDEX_LIST_SET_CNF_STRU */
    ID_CSS_AT_LINE_DETAIL_SET_CNF             = 0x1008,                           /* _H2ASN_MsgChoice CSS_AT_LINE_DETAIL_SET_CNF_STRU */
    ID_CSS_AT_LINE_INDEX_LIST_QUERY_CNF       = 0x1009,                           /* _H2ASN_MsgChoice CSS_AT_LINE_INDEX_LIST_QUERY_CNF_STRU */
    ID_CSS_AT_LINE_PLMN_NOTIFY                = 0x100a,                           /* _H2ASN_MsgChoice CSS_AT_LINE_PLMN_NOTIFY_STRU */
    ID_CSS_AT_LINE_INDEX_NOTIFY               = 0x100b,                           /* _H2ASN_MsgChoice CSS_AT_LINE_INDEX_NOTIFY_STRU */

    ID_CSS_AT_MSG_BUTT
};
typedef  VOS_UINT32  CSS_AT_MSG_TYPE_ENUM_UINT32;


enum AT_CSS_RAT_ENUM
{
    AT_CSS_RAT_TYPE_GSM = 0,                           /* GSM���뼼�� */
    AT_CSS_RAT_TYPE_WCDMA,                             /* WCDMA���뼼�� */
    AT_CSS_RAT_TYPE_LTE,                               /* LTE���뼼�� */

    AT_CSS_RAT_TYPE_BUTT
};
typedef  VOS_UINT8  AT_CSS_RAT_ENUM_UINT8;

enum AT_CSS_SET_MCC_OPERATE_TYPE_ENUM
{
    AT_CSS_SET_MCC_TYPE_ADD_MCC = 0,                   /* ����MCC */
    AT_CSS_SET_MCC_TYPE_DELETE_ALL_MCC,                /* ɾ������MCC��Ϣ */
    AT_CSS_SET_MCC_TYPE_DELETE_ONE_MCC,                /* ɾ��һ��MCC��Ϣ */

    AT_CSS_SET_MCC_TYPE_BUTT
};
typedef  VOS_UINT8  AT_CSS_SET_MCC_OPERATE_TYPE_ENUM_UINT8;


enum AT_CSS_BLACK_CELL_LIST_OPERATE_TYPE_ENUM
{
    AT_CSS_BLACK_CELL_LIST_ADD_ONE      = 0,           /* ����һ����С����Ϣ */
    AT_CSS_BLACK_CELL_LIST_DELETE_ALL,                 /* ɾ�����к�С����Ϣ */

    AT_CSS_BLACK_CELL_LIST_TYPE_BUTT
};
typedef  VOS_UINT8  AT_CSS_BLACK_CELL_LIST_OPERATE_TYPE_ENUM_UINT8;

/*****************************************************************************
ö����    : AT_CSS_LINE_INDEX_LIST_OPERATE_TYPE_ENUM
�ṹ˵��  : �����������������

*****************************************************************************/
enum AT_CSS_LINE_INDEX_LIST_OPERATE_TYPE_ENUM
{
    AT_CSS_LINE_INDEX_LIST_ADD          = 0,           /* ��������������Ϣ */
    AT_CSS_LINE_INDEX_LIST_DELETE_ALL,                 /* ɾ������������Ϣ */

    AT_CSS_LINE_INDEX_LIST_TYPE_BUTT
};
typedef  VOS_UINT8  AT_CSS_LINE_INDEX_LIST_OPERATE_TYPE_ENUM_UINT8;

/*****************************************************************************
ö����    : AT_CSS_LINE_DETAIL_OPERATE_TYPE_ENUM
�ṹ˵��  : ����������ϸ��Ϣ���������

*****************************************************************************/
enum AT_CSS_LINE_DETAIL_OPERATE_TYPE_ENUM
{
    AT_CSS_LINE_DETAIL_ADD              = 0,           /* ����������·��ϸ��Ϣ */
    AT_CSS_LINE_DETAIL_DELETE_ALL,                     /* ɾ��������·��ϸ��Ϣ */

    AT_CSS_LINE_DETAIL_TYPE_BUTT
};
typedef  VOS_UINT8  AT_CSS_LINE_DETAIL_OPERATE_TYPE_ENUM_UINT8;

/*****************************************************************************
ö����    : AT_CSS_LINE_DETAIL_INFO_TYPE_ENUM
�ṹ˵��  : ����������ϸ��Ϣ������

*****************************************************************************/
enum AT_CSS_LINE_DETAIL_INFO_TYPE_ENUM
{
    AT_CSS_LINE_DETAIL_INFO_TACLAC_PAIR     = 0,           /* TACLAC�� */
    AT_CSS_LINE_DETAIL_INFO_HO_PATH,                       /* HOԤ��·�� */
    AT_CSS_LINE_DETAIL_INFO_HO_BAR,                        /* HOԤ��Bar·�� */
    AT_CSS_LINE_DETAIL_INFO_NO_INFO         = 0xFF         /* ��ʾû����Ϣ��Ϣ��ֹͣ���� */
};
typedef  VOS_UINT8  AT_CSS_LINE_DETAIL_INFO_TYPE_ENUM_UINT8;

/*****************************************************************************
  4 ���Ͷ���
*****************************************************************************/

typedef struct
{
    /*MCC��aucMcc[2]�еĴ�Ÿ�ʽ,mccΪ460:
    ---------------------------------------------------------------------------
                 ||(BIT8)|(BIT7)|(BIT6)|(BIT5)|(BIT4)|(BIT3)|(BIT2)|(BIT1)
    ---------------------------------------------------------------------------
    aucMcc[0]    ||    MCC digit 2 = 6        |           MCC digit 1 = 4
    ---------------------------------------------------------------------------
    aucMcc[1]    ||    ��Ч                   |           MCC digit 3 = 0
    ---------------------------------------------------------------------------*/
    VOS_UINT8                           aucMcc[2];                              /* MCC ID */
    VOS_UINT8                           aucRsv[2];
} AT_CSS_MCC_ID_STRU;


typedef struct
{
    VOS_UINT32                          ulMcc;
    VOS_UINT32                          ulMnc;
}CSS_AT_PLMN_ID_STRU;

typedef struct
{
    VOS_UINT32                          ulFreqHigh;
    VOS_UINT32                          ulFreqLow;
} AT_CSS_FREQ_RANGE_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           aucRsv[2];
} AT_CSS_MCC_VERSION_INFO_REQ_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           aucRsv[1];
    VOS_UINT8                           aucVersionId[MCC_INFO_VERSION_LEN];     /* �汾�ţ��̶�Ϊxx.xx.xxx */
} CSS_AT_MCC_VERSION_INFO_CNF_STRU;



typedef struct
{
    VOS_MSG_HEADER                                                                        /* _H2ASN_Skip */
    VOS_UINT32                                    ulMsgId;                                /* _H2ASN_Skip */
    MODEM_ID_ENUM_UINT16                          usModemId;
    VOS_UINT16                                    usClientId;
    VOS_UINT8                                     ucSeq;                                  /* ��ˮ�� */
    AT_CSS_SET_MCC_OPERATE_TYPE_ENUM_UINT8        ucOperateType;                          /* �������� */
    VOS_UINT8                                     aucVersionId[MCC_INFO_VERSION_LEN];     /* �汾�ţ��̶�Ϊxx.xx.xxx */
    VOS_UINT8                                     aucRsv[1];

    /*
        1)aucMccINfoBuff��洢����MCC����Ϣ���洢������ʵ��С��ulMccInfoBuffLen���¼���ֽ�����
        2)aucMccINfoBuff��ĸ�ʽΪAT_CSS_MCC_INFO_STRU�ṹ�ĸ�ʽ������MNC����,
          BAND������Ԥ��Ƶ�θ�����Ԥ��Ƶ��ĸ������ǿɱ�ġ�

        typedef struct
        {
            VOS_UINT8                           ucSupportFlag;    // 1:��ʾ֧��GSM 2:��ʾ֧��WCDMA 4:��ʾ֧��LTE�����߿����������
            AT_CSS_FREQ_RANGE_STRU              stFreqRange;
        } AT_CSS_FREQ_RANGE_WITH_RAT_STRU;

        typedef struct
        {
            VOS_UINT8                                   ucBandInd;
            VOS_UINT8                                   ucFreqRangNum;
            //����������ucFreqRangNum��AT_CSS_FREQ_RANGE_WITH_RAT_STRU�ṹ
              ��FreqRange��Ϣ�����û��FreqRange������Ҫ��ucFreqRangNum��Ϊ0
            AT_CSS_FREQ_RANGE_WITH_RAT_STRU             astFreqRangeArray[ucFreqRangNum];

            VOS_UINT8                                   ucPreConfigFreqNum;
            //����������ucPreConfigFreqNum��AT_CSS_FREQ_RANGE_WITH_RAT_STRU�ṹ
              ��PreConfigFreq��Ϣ�����û��PreConfigFreq������Ҫ��ucPreConfigFreqNum��Ϊ0
            AT_CSS_FREQ_RANGE_WITH_RAT_STRU             astPreConfigFreqArray[ucPreConfigFreqNum];      //Ԥ��Ƶ���б�
        }AT_CSS_BAND_INFO_STRU;


        typedef struct
        {
            MNC��aucMnc[2]�еĴ�Ÿ�ʽ��mncΪ01:
            ---------------------------------------------------------------------------
                         ||(BIT8)|(BIT7)|(BIT6)|(BIT5)|(BIT4)|(BIT3)|(BIT2)|(BIT1)
            ---------------------------------------------------------------------------
            aucMnc[0]    ||    MNC digit 3 = f        |           ��Ч
            ---------------------------------------------------------------------------
            aucMnc[1]    ||    MNC digit 2 = 1        |           MNC digit 1 = 0
            ---------------------------------------------------------------------------
            VOS_UINT8                           aucMnc[2];
            VOS_UINT8                           ucBandCount;// BAND�ĸ���
            //����������ucBandCount��band����Ϣ�����û��BAND������Ҫ��ucBandCount��Ϊ0
            AT_CSS_BAND_INFO_STRU               astBandArray[ucBandCount];
        }AT_CSS_MNC_INFO_STRU;


        typedef struct
        {
            MCC��aucMcc[2]�еĴ�Ÿ�ʽ,mccΪ460:
            ---------------------------------------------------------------------------
                         ||(BIT8)|(BIT7)|(BIT6)|(BIT5)|(BIT4)|(BIT3)|(BIT2)|(BIT1)
            ---------------------------------------------------------------------------
            aucMcc[0]    ||    MCC digit 2 = 6        |           MCC digit 1 = 4
            ---------------------------------------------------------------------------
            aucMcc[1]    ||    ��Ч                   |           MCC digit 3 = 0
            ---------------------------------------------------------------------------
            VOS_UINT8                           aucMcc[2];
            VOS_UINT8                           ucMncCount;// MNC�ĸ���
            //����������ucMncCount��AT_CSS_MNC_INFO_STRU�ṹ��mnc��Ϣ�����û��mnc������Ҫ��ucMncCount��Ϊ0
            AT_CSS_MNC_INFO_STRU                astMncAarry[ucMncCount];
        }AT_CSS_MCC_INFO_STRU;


        3)aucMccINfoBuff�д洢��Ϣ�ĸ�ʽAP��CSSֱ�ӶԽӣ�AT��������޸ģ�AP���γ������ĸ�ʽ��
          Ȼ��ת���ַ�����ʽ����AT��AT���ַ�����ʽ��ԭ������������Ȼ�󷢸�CSS��
          ����AP�γ�ĳһ���ֽ�Ϊ0x22��Ȼ��ת��Ϊ�ַ���'22'��AT�յ�����ת��0x22;
        4)aucMccINfoBuff�еĸ�ʽΪС�ˣ�
        5)ulMccInfoBuffLen���ܳ���1.6K��
    */
    VOS_UINT32                          ulMccInfoBuffLen;
    VOS_UINT8                           aucMccInfoBuff[4];
} AT_CSS_MCC_INFO_SET_REQ_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                                                              /* _H2ASN_Skip */
    VOS_UINT32                                              ulMsgId;                                            /* _H2ASN_Skip */
    VOS_UINT16                                              usClientId;
    VOS_UINT8                                               ucSeq;                                              /* ��ˮ�� */
    AT_CSS_BLACK_CELL_LIST_OPERATE_TYPE_ENUM_UINT8          enOperateType;                                      /* �������� */
    VOS_UINT8                                               aucVersionId[AT_CSS_BLACK_CELL_LIST_VERSION_LEN];   /* �汾�ţ��̶�Ϊxx.xx.xxx */
    AT_CSS_RAT_ENUM_UINT8                                   enRatType;                                          /* ϵͳ��ʽ */
    VOS_UINT8                                               aucRsv[2];

    /*
        1)aucBlackCellListBuff��洢���Ǻ�С������Ϣ���洢������ʵ��С��ulBlackCellListBuffLen���¼���ֽ�����
        2)aucBlackCellListBuff��ĸ�ʽΪAT_CSS_GSM_CLOUD_BLACKCELL_STRU�ṹ�ĸ�ʽ

        ��������BS1,BS2��BS3�ı����ʽ��ͬ������AT_CSS_GSM_CLOUD_BLACKCELL_STRU�ṹ�ĸ�ʽ���룺
        ����ucPairCount��astBlackListArray�ǿ��Ա��
        typedef struct
        {
            CSS_PLMN_ID_STRU    stPlmn;
            VOS_UNIT8           ucPairCount;
            //����������ucPairCount��AT_CSS_GSM_CLOUD_BLACKCELL_PAIR_STRU�ṹ��pair��Ϣ��
              ���û�������mccû�к�С����Ϣ��AP����Ҫ�·���MCC����Ϣ��Modem��Ϊ��MCCû�к�С����Ϣ��
              ��������Ҫ���ϱ�^REPORTBLACKCELLMCC����ȡ��С��
            AT_CSS_GSM_CLOUD_BLACKCELL_PAIR_STRU astBlackListPairArray[ucPairCount];
        }AT_CSS_GSM_CLOUD_BLACKCELL_STRU;

        typedef struct
        {
            VOS_UNIT32  ulMcc; //Modem�ڲ�plmn��ʽ;����460---0x00000604
            VOS_UNIT32  ulMnc; //Modem�ڲ�plmn��ʽ;���� 01---0x000F0100
        }CSS_PLMN_ID_STRU;

        typedef struct
        {
            VOS_UNIT16  usSourceCellLai;
            VOS_UNIT16  usSourceCellId;
            VOS_UNIT16  usBlackCellArfcn; //������GSM��Ƶ����Ϣ������0x1029��ʾGSM900Ƶ��,41Ƶ��
            VOS_UNIT8   ucBlackCellBsic;  //����ncc,bcc;����0x14��ʾ<2,4>
            VOS_UNIT8   ucBlackCellReduceVal;//��Ա���С���ͷ�ʱ��������dbֵ
        }AT_CSS_GSM_CLOUD_BLACKCELL_PAIR_STRU;
    */

    VOS_UINT32                                              ulBlackCellListBuffLen;
    VOS_UINT8                                               aucBlackCellListBuff[4];
} AT_CSS_BLACK_CELL_LIST_SET_REQ_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           aucRsv[2];
} AT_CSS_BLACK_CELL_LIST_QUERY_REQ_STRU;

typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucSeq;                                  /* ��ˮ�� */
    VOS_UINT8                           aucRsv[1];

    VOS_UINT32                          ulResult;                               /*0��ʾ�ɹ���1��ʾʧ��*/
} CSS_AT_MCC_INFO_SET_CNF_STRU;

typedef struct
{
    VOS_MSG_HEADER                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           aucRsv[1];
    VOS_UINT8                           aucVersionId[MCC_INFO_VERSION_LEN];     /* �汾�ţ��̶�Ϊxx.xx.xxx */
    VOS_UINT32                          ulMccNum;                               /* MCC ���� */
    AT_CSS_MCC_ID_STRU                  astMccId[AT_CSS_MAX_MCC_ID_NUM];        /* MCC ID�б� */
} CSS_AT_QUERY_MCC_INFO_NOTIFY_STRU;


typedef struct
{
    VOS_UINT32                          ulMccNum;                                               /* MCC ���� */
    VOS_UINT32                          aulMcc[AT_CSS_MAX_MCC_ID_NUM];                          /* MCC �б�,Modem�ڲ�plmn��ʽ;����460---0x00000604 */
} CSS_AT_BLACK_CELL_MCC_INFO_STRU;



typedef struct
{
    VOS_MSG_HEADER                                                          /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                            /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucSeq;                              /* ��ˮ�� */
    VOS_UINT8                           ucReserved;
    VOS_UINT32                          ulResult;                           /* VOS_OK��ʾ�ɹ���VOS_ERR��ʾʧ�� */
} CSS_AT_BLACK_CELL_LIST_SET_CNF_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                                /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucReserved;
    VOS_UINT8                           aucVersionId[AT_CSS_BLACK_CELL_LIST_VERSION_LEN];       /* �汾�ţ��̶�Ϊxx.xx.xxx */
    CSS_AT_BLACK_CELL_MCC_INFO_STRU     stMccInfo;                                              /* ��С��MCC��Ϣ */
} CSS_AT_BLACK_CELL_LIST_QUERY_CNF_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                                              /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                                                /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucReserved;
    VOS_UINT8                           aucVersionId[AT_CSS_BLACK_CELL_LIST_VERSION_LEN];       /* �汾�ţ��̶�Ϊxx.xx.xxx */
    CSS_AT_BLACK_CELL_MCC_INFO_STRU     stMccInfo;                                              /* ��С��MCC��Ϣ */
} CSS_AT_BLACK_CELL_MCC_NOTIFY_STRU;



typedef struct
{
    VOS_MSG_HEADER                                                                                              /* _H2ASN_Skip */
    VOS_UINT32                                              ulMsgId;                                            /* _H2ASN_Skip */
    VOS_UINT16                                              usClientId;
    MODEM_ID_ENUM_UINT16                                    usModemId;
    VOS_UINT8                                               ucSeq;                                              /* ��ˮ�� */
    AT_CSS_LINE_INDEX_LIST_OPERATE_TYPE_ENUM_UINT8          enOperateType;                                      /* �������� */
    VOS_UINT8                                               aucVersionId[AT_CSS_CLOUD_LINE_VERSION_LEN];        /* �汾�ţ��̶�Ϊxx.xx.xxx */
    VOS_UINT8                                               ucRsv;

    /*
        1)aucLineIndexListBuff��洢���Ǹ�����·��������Ϣ���洢������ʵ��С��ulLineIndexListBuffLen���¼���ֽ�����
        2)aucLineIndexListBuff��ĸ�ʽΪAT_CSS_CLOUD_LINE_INDEX_LIST_INFO_STRU�ṹ�ĸ�ʽ
        ��LineIndexΪ0xFFFFʱ��ʾ��PLMN��û�и�����·��Ϣ��

        typedef struct
        {
            CSS_PLMN_ID_STRU stPlmn;
            VOS_UNIT16          usLineIndex;
            VOS_UINT8           ucTacNum;
            VOS_UINT8           ucLacNum;
            //����������ucTacNum��VOS_UINT16��TAC�б���Ϣ��
            VOS_UINT16          ausTacList[ucTacNum];
            //����������ucLacNum��VOS_UINT16��LAC�б���Ϣ��
            VOS_UINT16          ausLacList[ucLacNum];
        }AT_CSS_CLOUD_LINE_INDEX_INFO_STRU;

    */
    VOS_UINT32                                              ulLineIndexListBuffLen;
    VOS_UINT8                                               aucLineIndexListBuff[4];
}AT_CSS_LINE_INDEX_LIST_SET_REQ_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                          /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                            /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucSeq;                              /* ��ˮ�� */
    VOS_UINT8                           ucRsv;
    VOS_UINT32                          ulResult;                           /* VOS_OK��ʾ�ɹ���VOS_ERR��ʾʧ�� */
} CSS_AT_LINE_INDEX_LIST_SET_CNF_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                                                              /* _H2ASN_Skip */
    VOS_UINT32                                              ulMsgId;                                            /* _H2ASN_Skip */
    VOS_UINT16                                              usClientId;
    MODEM_ID_ENUM_UINT16                                    usModemId;
    VOS_UINT8                                               ucSeq;                                              /* ��ˮ�� */
    AT_CSS_LINE_DETAIL_OPERATE_TYPE_ENUM_UINT8              enOperateType;                                      /* �������� */
    VOS_UINT8                                               aucVersionId[AT_CSS_CLOUD_LINE_VERSION_LEN];   /* �汾�ţ��̶�Ϊxx.xx.xxx */
    VOS_UINT8                                               ucRsv;

    /*
        1)aucLineDetailBuff��洢���Ǹ�����·��������Ϣ���洢������ʵ��С��ulLineDetailBuffLen���¼���ֽ�����

        2)aucLineDetailBuff��ĸ�ʽΪAT_CSS_LINE_DETAIL_INFO_STRU�ṹ�ĸ�ʽ:
        typedef struct
        {
            CSS_PLMN_ID_STRU                             stPlmn;
            VOS_UNIT16                                      usLineIndex;
            AT_CSS_LINE_DETAIL_INFO_TYPE_ENUM_UINT8         enInfoType;
            VOS_UINT8                                       aucLeftBuff[ulLineDetailBuffLen-11];
        }AT_CSS_LINE_DETAIL_INFO_STRU;

        3)AT_CSS_LINE_DETAIL_INFO_STRU�ṹ�е�aucLeftBuff����enInfoType��ָʾ���б��룺
          i.��enInfoTypeΪAT_CSS_LINE_DETAIL_INFO_TACLAC_PAIRʱaucLeftBuff��ĸ�ʽΪAT_CSS_CLOUD_LINE_TACLAC_MAP_INFO_STRU�ṹ�ĸ�ʽ��
            typedef struct
            {
                VOS_UITN16                                       usTac;
                VOS_UINT16                                       usLac;
            }AT_CSS_CLOUD_LINE_TACLAC_PAIR_INFO_STRU;
            typedef struct
            {
                VOS_UINT8                                        ucPairNum;
                //����������ucPairNum��AT_CSS_CLOUD_LINE_TACLAC_PAIR_INFO_STRU����Ϣ��
                AT_CSS_CLOUD_LINE_TACLAC_PAIR_INFO_STRU          astCloudTacLacPairInfoList[ucPairNum];
            }AT_CSS_CLOUD_LINE_TACLAC_MAP_INFO_STRU;

          ii.��enInfoTypeΪAT_CSS_LINE_DETAIL_INFO_HO_PATHʱaucLeftBuff��ĸ�ʽΪAT_CSS_CLOUD_LINE_HO_PATH_INFO_STRU�ṹ�ĸ�ʽ��
            typedef struct
            {
                VOS_UINT32                                       usSrcCellId;
                VOS_UINT16                                       usSrcArfcn;
                VOS_UINT16                                       usSrcBsic;
                VOS_UINT16                                       usDstArfcn;
                VOS_UINT16                                       usDstBsic;
                VOS_UINT16                                       usRxlevA;
                VOS_UINT16                                       usRxlevB;
            }AT_CSS_CLOUD_LINE_HO_PATH_CELL_INFO_STRU;
            typedef struct
            {
                VOS_UITN16                                       usLac;
                VOS_UINT8                                        ucCellNum;
                //����������ucCellNum��AT_CSS_CLOUD_LINE_HO_PATH_CELL_INFO_STRU����Ϣ��
                AT_CSS_CLOUD_LINE_HO_PATH_CELL_INFO_STRU         astCellInfoList[ucCellNum];
            }AT_CSS_CLOUD_LINE_HO_PATH_LAC_INFO_STRU;
            typedef struct
            {
                VOS_UINT8                                        ucRat;
                VOS_UINT8                                        ucDirection;
                VOS_UINT8                                        ucLacNum;
                //����������ucLacNum��AT_CSS_CLOUD_LINE_HO_PATH_LAC_INFO_STRU����Ϣ��
                AT_CSS_CLOUD_LINE_HO_PATH_LAC_INFO_STRU          astLacInfoList[ucLacNum];
            }AT_CSS_CLOUD_LINE_HO_PATH_INFO_STRU;
          iii.��enInfoTypeΪAT_CSS_LINE_DETAIL_INFO_HO_BARʱaucLeftBuff��ĸ�ʽΪAT_CSS_CLOUD_LINE_HO_BAR_INFO_STRU�ṹ�ĸ�ʽ��
            typedef struct
            {
                VOS_UINT16                                       usLac;
                VOS_UINT32                                       usSrcCellId;
                VOS_UINT16                                       usSrcArfcn;
                VOS_UINT16                                       usSrcBsic;
                VOS_UINT16                                       usDstArfcn;
                VOS_UINT16                                       usDstBsic;
            }AT_CSS_CLOUD_LINE_HO_BAR_CELL_INFO_STRU;
            typedef struct
            {
                VOS_UINT8                                        ucRat;
                VOS_UINT8                                        ucCellNum;
                //����������ucCellNum��AT_CSS_CLOUD_LINE_HO_BAR_CELL_INFO_STRU����Ϣ��
                AT_CSS_CLOUD_LINE_HO_BAR_CELL_INFO_STRU          astCellInfoList[ucCellNum];
            }AT_CSS_CLOUD_LINE_HO_BAR_INFO_STRU;
          iiii.��enInfoTypeΪAT_CSS_LINE_DETAIL_INFO_NO_INFOʱ��ʾ��PLMN/��·��û����ϸ��Ϣ��ֹͣ������modem������ap��ѯ��PLMN/��·��ϸ��Ϣ��
          iiiii.��enInfoTypeΪ�������͵�������Ч����ʱ��ֹͣ������ֱ�ӷ���ʧ�ܡ�
    */
    VOS_UINT32                                              ulLineDetailBuffLen;
    VOS_UINT8                                               aucLineDetailBuff[4];
} AT_CSS_LINE_DETAIL_SET_REQ_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                          /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                            /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           ucSeq;                              /* ��ˮ�� */
    VOS_UINT8                           ucRsv;
    VOS_UINT32                          ulResult;                           /* VOS_OK��ʾ�ɹ���VOS_ERR��ʾʧ�� */
}CSS_AT_LINE_DETAIL_SET_CNF_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                          /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                            /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    MODEM_ID_ENUM_UINT16                usModemId;
}AT_CSS_LINE_INDEX_LIST_QUERY_REQ_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                          /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                            /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           aucVersionId[AT_CSS_CLOUD_LINE_VERSION_LEN];   /* �汾�� */
    VOS_UINT8                           ucRsv;
    CSS_AT_PLMN_ID_STRU                 stRplmnInfo;                        /* rplmn��Ϣ */
    VOS_UINT32                          ulResult;                           /* ��ѯ����Ƿ���Ч */
}CSS_AT_LINE_INDEX_LIST_QUERY_CNF_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                          /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                            /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;
    VOS_UINT8                           aucRsv[2];
    CSS_AT_PLMN_ID_STRU                 stRplmnInfo;                        /* rplmn��Ϣ */
} CSS_AT_LINE_PLMN_NOTIFY_STRU;


typedef struct
{
    VOS_MSG_HEADER                                                          /* _H2ASN_Skip */
    VOS_UINT32                          ulMsgId;                            /* _H2ASN_Skip */
    VOS_UINT16                          usClientId;                         /* _H2ASN_Skip */
    VOS_UINT16                          usLineNum;                          /* ��·���� */
    VOS_UINT16                          ausLineIndexList[AT_CSS_TACLAC_MAX_LINE_NUM]; /* ��·�б� */
    CSS_AT_PLMN_ID_STRU                 stPlmnId;                           /* plmn id */
} CSS_AT_LINE_INDEX_NOTIFY_STRU;


/*****************************************************************************
  5 ȫ�ֱ�������
*****************************************************************************/


/*****************************************************************************
  6 �ӿں�������
*****************************************************************************/

/*****************************************************************************
  7 OTHERS����
*****************************************************************************/

/* ASN�����ṹ */
typedef struct
{
    VOS_UINT32                          ulMsgId;                                /*_H2ASN_MsgChoice_Export CSS_AT_MSG_TYPE_ENUM_UINT32 */
    VOS_UINT8                           aucMsg[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          CSS_AT_MSG_TYPE_ENUM_UINT32
    ****************************************************************************/
}CSS_AT_INTERFACE_MSG_DATA;
/*_H2ASN_Length UINT32*/

typedef struct
{
    VOS_MSG_HEADER
    CSS_AT_INTERFACE_MSG_DATA           stMsgData;
} CssAtInterface_MSG;


#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif


