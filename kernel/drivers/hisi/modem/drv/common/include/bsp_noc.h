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

#ifndef __BSP_NOC_H__
#define __BSP_NOC_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "osl_types.h"
#include "osl_list.h"
#include "osl_sem.h"
#if (defined(__OS_RTOSCK__)||defined(__OS_RTOSCK_SMP__))
#include "mdrv_dsp.h"
#endif

/*****************************************************************************
  1 �궨��
*****************************************************************************/
#define MST_NAME_MAX_LEN        (32)
#define NOC_BUS_NAME_MAX_LEN    (16)

#define NOC_ERR_PROBE_REG_SIZE       (64)

#define NOC_MAX_OFFSET   (0x3c)

#define NOC_RESET_GUC_MODID       0x70000009    /* GUC_BBP_TCM��GUC_BBP_DDR��UPACC����noc�쳣modid */
#define NOC_RESET_NXP_MODID       0xcb000001    /* NXP����noc�쳣modid */
#define NOC_RESET_BBP_DMA0_MODID  0xcb000002    /* BBP_DMA_0����noc�쳣modid */
#define NOC_RESET_BBP_DMA1_MODID  0xcb000003    /* BBP_DMA_1����noc�쳣modid */
#define NOC_RESET_HARQ_MODID      0xcb000004    /* HARQ_L��HARQ_H����noc�쳣modid */
#define NOC_RESET_CPHY_MODID      0xd0000001    /* BBE16_C����noc�쳣modid */
#define NOC_RESET_GUL2_MODID      0x31000000    /* CICOM��HDLC����noc�쳣modid */
#define NOC_RESET_MODID_ERR       0xffffffff

/*****************************************************************************
  2 ö�ٶ���
*****************************************************************************/
enum
{
    NOC_DISABLE = 0,
    NOC_ENABLE = 1
};

enum
{
    NOC_CP_RESET  = 0x0,
    NOC_AP_RESET  = 0x1
};

/* noc test module idע�ᣬ����ע�ᣬ����� */
typedef enum noc_test_modid_e
{
    NOC_IDLE_MODID        = 0x00,
    NOC_RSRACC_MODID      = 0x01,   /* RSRACC����noc�쳣 */
    NOC_EDMA0_MODID       = 0x02,   /* EDMA0����noc�쳣  */
    NOC_EDMA1_MODID       = 0x03,   /* EDMA1����noc�쳣  */
    NOC_NXP_MODID         = 0x04,   /* EDMA1����noc�쳣  */
    NOC_BBPDMA0_MODID     = 0x05,   /* BBP DMA TCM����noc�쳣  */
    NOC_BBPDMA1_MODID     = 0x06,   /* BBP DMA DDR����noc�쳣  */
    NOC_CBBE16_MODID      = 0x07,   /* CBBE16����noc�쳣  */
    NOC_BBPMST0_MODID     = 0x08,   /* GUC_BBP_TCM����noc�쳣  */
    NOC_BBPMST1_MODID     = 0x09,   /* GUC_BBP_DDR����noc�쳣  */
    NOC_DMAC_MODID        = 0x0A,   /* SOCP����noc�쳣  */

    NOC_MODID_BUTT        = 0x0B
}NOC_TEST_MODID_E;

/*****************************************************************************
  2 �궨��
*****************************************************************************/

typedef struct
{
    u32 enable;                 /*noc�쳣�澯����ʹ�ܱ�ʾ��0, ȥʹ��;  1, ʹ��*/
    u32 reset_enable;           /*noc�쳣��Ϣ�������Ƿ�λ��0, ����λ;  1, ��λ*/
}noc_err_probe_nv_cfg;

typedef struct
{
    u32    total          :16;  /*����noc���ܴ�������Χ:0x1-0xffff*/
    u32    max_record_num :8;   /*noc dump�ɼ�¼�����������acoreΪ�̶�ֵ5��ccoreΪ�̶�ֵ10*/
    u32    offset         :8;   /*��ǰnoc err��noc dump�е�ƫ��λ�ã�acoreΪ0x0-0x4��ccoreΪ0x0-0x9*/
}noc_record_num_stru;

typedef struct
{
    u32 magic_num;
    u32 noc_base_addr;
    noc_record_num_stru record_num_info;
    u32 slice;
    u32 noc_reg[16];
}noc_dump_record_stru;

typedef struct
{
    u32 modid;
    u32 errcode;
    u32 opc;
    u64 slv_addr;
    char master[16];
    u32 noc_err_probe_reg_val[16];
}noc_err_parse_info;

typedef int (*bsp_noc_hook_func)(noc_err_parse_info *parData);

typedef struct
{
    struct list_head    list;
    u32                 nocModId;
    bsp_noc_hook_func   pFunc;
    u32                 ulReserve;
}noc_hook_stru;

typedef struct
{
    u32 rsv_addr;
    u32 exc_addr;
    u32 nor_addr;
    u32 ap_exc_addr;
    u32 ulReserve;
}noc_test_addr;

typedef enum noc_test_mode_e
{
    NOC_MODE_OFF = 0,
    NOC_MODE_ON = 1,
    NOC_MODE_LLT = 2,
    NOC_MODE_ACT = 3,
    NOC_MODE_BUTT
}NOC_TEST_MODE_E;


typedef struct
{
    noc_test_addr test_addr;
    enum noc_test_modid_e modid;
    enum noc_test_mode_e test_mode;
    bool noc_exc_flag;  /* ��������noc�쳣��־ */
    osl_sem_id noc_test_sem;
}noc_err_test_stru;

typedef struct
{
    enum noc_test_modid_e modid;
    char *mst_name;
}noc_test_modid_match_stru;

typedef struct
{
    u32 modid;
    char *mst_name;
}noc_modid_match_stru;

extern noc_err_test_stru g_noc_err_test_cfg;
extern noc_err_probe_nv_cfg g_noc_err_probe_nv_cfg;


extern bsp_noc_hook_func g_NocTestFunc;


extern struct dsp_mainctrl *g_dsp_ctrl;
/*****************************************************************************
  3 ��������
*****************************************************************************/
#ifdef CONFIG_NOC
s32 bsp_noc_check_test_mode(void);
void bsp_noc_test_sem_up(void);
void bsp_noc_test_mode_start(u32 modid);
void bsp_noc_llt_mode_start(u32 modid);
void bsp_noc_test_start(u32 modid);
void bsp_noc_test_mode_stop(noc_err_parse_info *parse_info);
void bsp_noc_test_stop(noc_err_parse_info *parse_info);
u32 bsp_noc_get_rsv_addr(void);
u32 bsp_noc_get_exc_addr(void);
u32 bsp_noc_get_nor_addr(void);
u32 bsp_noc_get_exc_flag(void);
u32 bsp_noc_get_ap_exc_addr(void);
u32 bsp_noc_get_modid(void);
int bsp_noc_test_sem_down(void);
s32 bsp_noc_check_exc_flag(u32 modid, noc_err_parse_info *parse_info);
u32 noc_fault_dump_handler(void);

void bsp_noc_test_hook_register(bsp_noc_hook_func fn);
void bsp_noc_test_hook_unregister(void);
void bsp_noc_test_init(void);
u64 noc_get_addr_from_routeid(u32 initflow, u32 targetflow, u32 targetsubrange);
u64 noc_dmesg_get_addr_from_routeid(u32 initflow, u32 targetflow, u32 targetsubrange);

#if defined(__KERNEL__)
void bsp_noc_test_proc(void);
void bsp_noc_llt_test_proc(void);
void bsp_noc_reset_branch_test(void* base);
void noc_get_route_info(void* base, u32 idx, int *initflow, int *targetflow);
#elif (defined(__OS_RTOSCK__)||defined(__OS_RTOSCK_SMP__))
void bsp_noc_test_proc(u32 base);
void bsp_noc_llt_test_proc(u32 base);
void noc_get_route_info(u32 base, int *initflow, int *targetflow);
void bsp_noc_reset_branch_test(u32 base);
void bsp_dsp_pd_idle_req_cfg(enum bsp_dsp_type_e etype);
void bsp_dsp_pd_idle_dis_cfg(enum bsp_dsp_type_e etype);
u32 bsp_dsp_check_pd_idle_state(enum bsp_dsp_type_e etype);
#endif

#else
#if defined(__KERNEL__)

#elif (defined(__OS_RTOSCK__)||defined(__OS_RTOSCK_SMP__))
static inline void bsp_dsp_pd_idle_req_cfg(enum bsp_dsp_type_e etype){return;}
static inline void bsp_dsp_pd_idle_dis_cfg(enum bsp_dsp_type_e etype){return;}
static inline u32 bsp_dsp_check_pd_idle_state(enum bsp_dsp_type_e etype){return 0;}
#endif
#endif


/*****************************************************************************
  4 ����������
*****************************************************************************/


#ifdef __cplusplus
}
#endif


#endif


