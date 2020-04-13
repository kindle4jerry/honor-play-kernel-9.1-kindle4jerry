#ifndef __MDRV_HDS_COMMON_H__
#define __MDRV_HDS_COMMON_H__
#ifdef __cplusplus
extern "C"
{
#endif

/*����cmdidע�����:31-28bit(���ID):0x9; 27-24bit(ģָʾ); 23-19bit(��Ϣ����):0x0; 18-0bit(��ϢID):�Լ�����*/
/* BSP CFG BEGIN*/
#define DIAG_CMD_LOG_SET                        (0x90035308)

/* �ļ������ࣨ0x5600-0x56ff��*/
#define DIAG_CMD_FS_QUERY_DIR                   (0x90015601)
#define DIAG_CMD_FS_SCAN_DIR                    (0x90015602)
#define DIAG_CMD_FS_MAKE_DIR                    (0x90015603)
#define DIAG_CMD_FS_OPEN                        (0x90015604)
#define DIAG_CMD_FS_IMPORT                      (0x90015605)
#define DIAG_CMD_FS_EXPORT                      (0x90015606)
#define DIAG_CMD_FS_DELETE                      (0x90015607)
#define DIAG_CMD_FS_SPACE                       (0x90015608)

/* NV�����ࣨ0x5500-0x55ff��*/
#define DIAG_CMD_NV_WR                          (0x90015001)
#define DIAG_CMD_NV_RD                          (0x90015003)
#define DIAG_CMD_GET_NV_LIST                    (0x90015005)
#define DIAG_CMD_GET_NV_RESUM_LIST              (0x90015006)
#define DIAG_CMD_NV_AUTH                        (0x90015007)

/* BSP CFG END*/

/* ������Ϣ�ϱ�msg_id */
#define DIAG_IND_MSGID_CPM_LTE0_WAKEUP_SLICE           (0x1002)
#define DIAG_IND_MSGID_CPM_LTE1_WAKEUP_SLICE           (0x11002)
#define DIAG_IND_MSGID_CPM_TDS_WAKEUP_SLICE            (0x1003)
#define DIAG_IND_MSGID_CPM_COMMON_WAKEUP_SLICE         (0x1004)
#define DIAG_IND_MSGID_CPM_1X_WAKEUP_SLICE             (0x1005)
#define DIAG_IND_MSGID_SCI0_EVENT                      (0x1006)
#define DIAG_IND_MSGID_SCI1_EVENT                      (0x1007)
#define DIAG_IND_MSGID_SCI2_EVENT                      (0x1008)
#define DIAG_IND_MSGID_SCI3_EVENT                      (0x1009)

/* Board info ind */
#define DIAG_CMD_BOARD_TRACE_IND_ACORE          (0x90000001)
#define DIAG_CMD_BOARD_TRACE_IND_CCORE          (0x90000002)


typedef unsigned int (*bsp_hds_func)(unsigned char *pstReq);
typedef unsigned int (*hds_cnf_func)(void *hds_cnf, void *data, unsigned int len);
int mdrv_hds_printlog_conn(void);
int mdrv_hds_translog_conn(void);
int mdrv_hds_printlog_disconn(void);
int mdrv_hds_translog_disconn(void);
int mdrv_hds_msg_proc(void *pstReq);
void mdrv_hds_cmd_register(unsigned int cmdid, bsp_hds_func fn);
void mdrv_hds_get_cmdlist(unsigned int *cmdlist, unsigned int *num);
void mdrv_hds_cnf_register(hds_cnf_func fn);

#ifdef __cplusplus
}
#endif
#endif

