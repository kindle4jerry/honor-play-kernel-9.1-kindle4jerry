
#include "product_config.h"
#include "omerrorlog.h"
#include "blist.h"
#include "mdrv_sysboot.h"

/*���ȼ�������ʼ����*/
#define   PRIORITY_PACKET_START            (0)
#define   PRIORITY_PACKET_END              (0x7F)



/*�������ð�����ʼ����*/
#define   PERIOD_PACKET_START            (0)
#define   PERIOD_PACKET_END              (0x7F)

#define   PERIOD_CHK_FAIL            (3)
#define   PERIOD_CHK_COMPLETE        (0)
#define   PERIOD_CHK_CONTINUE        (1)
#define   PERIOD_CHK_RESTART         (2)

#define CHR_ID_RESET_CCORE   (0x1001)
#define CHR_ID_BLACKLIST_MSG     (0x2002)
#define CHR_ID_PRIORITY_MSG      (0x3003)
#define CHR_ID_PERIOD_MSG        (0x4004)

#define chr_print(fmt, ...)    (printk(KERN_ERR "[CHR]<%s:%d> "fmt, __FUNCTION__, __LINE__ ,##__VA_ARGS__))

/*����������Ľṹ��*/
typedef struct
{
    VOS_UINT32          ulBlackListPacketLen;
    CHR_LIST_INFO_S    *pstChrBlackList;
    
}CHR_ACPU_BLACK_SAVE_STRU;


/*OM a�˷���c�ĺ������ṹ��*/
typedef struct
{   
    VOS_MSG_HEADER 
    VOS_UINT32                   ulMsgName;
    VOS_UINT32                   ulPacketLen;
    CHR_LIST_INFO_S              stOmAcpuBlackList[0];        
}OM_ACPU_BLACK_LIST_STRU;


/*�������ȼ�0�Ľṹ��*/
typedef struct
{
    VOS_UINT32                  ulPiorityLen;
    CHR_PRIORITY_INFO_S         PriorityCfg[0];
}CHR_ACPU_PRIORITY_SAVE_STRU;


/*OM a�˷���c�����ȼ�0���б�Ľṹ��*/
typedef struct
{   
    VOS_MSG_HEADER 
    VOS_UINT32                     ulMsgName;
    VOS_UINT32                     ulPacketLen;
    CHR_PRIORITY_INFO_S            PriorityCfg[0];        
}OM_ACPU_PRIORITY_CFG_STRU;


/*�����ϱ����ڵĽṹ��*/
typedef struct
{
    VOS_UINT32                      ulperiod; /*ap�·���period��8bit*/
    VOS_UINT32                      ulPacketLen;
    CHR_PERIOD_CFG_STRU             PeriodCfg[0];
}CHR_ACPU_PERIOD_SAVE_STRU;



/*���ȼ�����ṹ��*/
typedef struct
{
    LIST_S                     PriorityList;
    VOS_UINT32                 ulPacketLen;
    CHR_PRIORITY_INFO_S        pstPriorityCfg[0];
}OM_PRIORITY_NODE_STRU;

typedef struct
{
    VOS_UINT32              ulSN;
    VOS_UINT32              ulPrioPacketLen;
    OM_PRIORITY_NODE_STRU   List;
}OM_PRIORITY_LIST_STRU;

/*�ϱ���������ṹ��*/

typedef struct
{  
    LIST_S                  PeriodList;
    VOS_UINT32              ulperiod;
    VOS_UINT32              ulPacketLen;
    CHR_PERIOD_CFG_STRU     pstPeriodCfg[0];
}OM_PERIOD_NODE_STRU;

typedef struct
{
    VOS_UINT32              ulSN;
    VOS_UINT32              ulPeriodPacketLen;
    OM_PERIOD_NODE_STRU     List;
}OM_PERIOD_LIST_STRU;


/*OM a�˷���c�����������б�*/
typedef struct
{   
    VOS_MSG_HEADER
    VOS_UINT32                    ulMsgName;
    VOS_UINT32                    ulperiod;
    VOS_UINT32                    ulPacketLen;      
    CHR_PERIOD_CFG_STRU           stOmAcpuPeriodCfg[0];  
    
}OM_ACPU_PERIOD_CFG_STRU;




/* ������λʱ��a�˷���Ϣ*/
typedef struct
{
    VOS_MSG_HEADER
    VOS_UINT32                          ulMsgName;
}CHR_MSG_HEADER_STRU;

typedef struct
{
    CHR_MSG_HEADER_STRU           stMsgHeader;                
    VOS_UINT32                    ulReserved;
}CHR_APP_RESET_MSG_STRU;


typedef struct
{
    CHR_MSG_HEADER_STRU           stMsgHeader;                
    OM_APP_PRIORITY_CFG_STRU      stOmAppPrioCfg;
}CHR_APP_PRIORITY_CFG_MSG_STRU;

VOS_UINT32 OM_AcpuBlackListProc(VOS_UINT8 *pucData, VOS_UINT32 ulLen);
VOS_UINT32 OM_AcpuPriorityCfgProc(VOS_UINT8 *pucData, VOS_UINT32 ulLen);
VOS_UINT32 OM_AcpuPeriodCfgProc(VOS_UINT8 *pucData, VOS_UINT32 ulLen);
VOS_INT    chr_ResetCcoreCB(DRV_RESET_CB_MOMENT_E enParam, int userdata);
VOS_UINT32 OM_AcpuResetProc(VOS_VOID);

VOS_UINT32 CHR_Cfg_Init(VOS_VOID);
VOS_VOID OM_AcpuSendAppcfgResult(VOS_UINT32 ulRest);

