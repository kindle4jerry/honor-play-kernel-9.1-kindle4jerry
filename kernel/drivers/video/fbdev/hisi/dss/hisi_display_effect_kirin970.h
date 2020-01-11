/* Copyright (c) 2013-2014, Hisilicon Tech. Co., Ltd. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */



#ifndef EFFECT_KIRIN970_H
#define EFFECT_KIRIN970_H

#include <linux/types.h>

// for 32/64 bit compatiable
#define compat_pointer(x) \
    union { \
        uint32_t* x; \
        uint64_t x##_sizer; \
    }

#define TAG_ARSR_1P_ENABLE 100
#define TAG_LCP_XCC_ENABLE 302
#define TAG_LCP_GMP_ENABLE 300
#define TAG_LCP_IGM_ENABLE 303
#define TAG_GAMMA_ENABLE 400
#define TAG_HIACE_LHIST_SFT 503

// acm algorithm info define, mem_ctrl decide by enable or not
struct acm_info {
    uint32_t acm_en;
    uint32_t param_mode;
    uint32_t sata_offset;
    uint32_t acm_hue_rlh01;
    uint32_t acm_hue_rlh23;
    uint32_t acm_hue_rlh45;
    uint32_t acm_hue_rlh67;
    uint32_t acm_hue_param01;
    uint32_t acm_hue_param23;
    uint32_t acm_hue_param45;
    uint32_t acm_hue_param67;
    uint32_t acm_hue_smooth0;
    uint32_t acm_hue_smooth1;
    uint32_t acm_hue_smooth2;
    uint32_t acm_hue_smooth3;
    uint32_t acm_hue_smooth4;
    uint32_t acm_hue_smooth5;
    uint32_t acm_hue_smooth6;
    uint32_t acm_hue_smooth7;
    uint32_t acm_color_choose;
    uint32_t acm_l_cont_en;
    uint32_t acm_lc_param01;
    uint32_t acm_lc_param23;
    uint32_t acm_lc_param45;
    uint32_t acm_lc_param67;
    uint32_t acm_l_adj_ctrl;
    uint32_t acm_capture_ctrl;
    uint32_t acm_capture_in;
    uint32_t acm_capture_out;
    uint32_t acm_ink_ctrl;
    uint32_t acm_ink_out;
    compat_pointer(hue_table);
    compat_pointer(sata_table);
    compat_pointer(satr0_table);
    compat_pointer(satr1_table);
    compat_pointer(satr2_table);
    compat_pointer(satr3_table);
    compat_pointer(satr4_table);
    compat_pointer(satr5_table);
    compat_pointer(satr6_table);
    compat_pointer(satr7_table);

};


struct arsr1p_info {
    uint32_t enable;
    uint32_t para_mode;
    uint32_t sharp_enable;
    uint32_t skin_enable;
    uint32_t shoot_enable;
    uint32_t skin_thres_y;
    uint32_t skin_thres_u;
    uint32_t skin_thres_v;
    uint32_t skin_expected;
    uint32_t skin_cfg;
    uint32_t shoot_cfg1;
    uint32_t shoot_cfg2;
    uint32_t sharp_cfg1;
    uint32_t sharp_cfg2;
    uint32_t sharp_cfg3;
    uint32_t sharp_cfg4;
    uint32_t sharp_cfg5;
    uint32_t sharp_cfg6;
    uint32_t sharp_cfg7;
    uint32_t sharp_cfg8;
    uint32_t sharp_cfg9;
    uint32_t sharp_cfg10;
    uint32_t sharp_cfg11;
    uint32_t diff_ctrl;
    uint32_t lsc_cfg1;
    uint32_t lsc_cfg2;
    uint32_t lsc_cfg3;
    uint32_t shoot_cfg3;
    uint32_t sharp_cfg1_h;
    uint32_t sharp_cfg1_l;
    uint32_t sharp_cfg2_h;
    uint32_t sharp_cfg2_l;
    uint32_t sharp_cfg6_cut;
    uint32_t sharp_cfg7_ratio;
    uint32_t skin_slop_y;
    uint32_t skin_slop_u;
    uint32_t skin_slop_v;
    uint32_t update;
};

// define arsr2p effect parameter
struct arsr2p_info {
    uint32_t enable;
    uint32_t sharp_enable;
    uint32_t skin_enable;
    uint32_t shoot_enable;
    uint32_t skin_thres_y;
    uint32_t skin_thres_u;
    uint32_t skin_thres_v;
    uint32_t skin_cfg0;
    uint32_t skin_cfg1;
    uint32_t skin_cfg2;
    uint32_t shoot_cfg1;
    uint32_t shoot_cfg2;
    uint32_t shoot_cfg3;
    uint32_t sharp_cfg1;
    uint32_t sharp_cfg2;
    uint32_t sharp_cfg3;
    uint32_t sharp_cfg4;
    uint32_t sharp_cfg5;
    uint32_t sharp_cfg6;
    uint32_t sharp_cfg7;
    uint32_t sharp_cfg8;
    uint32_t sharp_cfg9;
    uint32_t sharp_cfg10;
    uint32_t sharp_cfg11;
    uint32_t sharp_cfg12;
    uint32_t texturw_analysts;
    uint32_t intplshootctrl;
    uint32_t update;
};

struct lcp_info {
    uint32_t gmp_enable;
    uint32_t xcc_enable;
    uint32_t igm_enable;
    compat_pointer(gmp_table_low32); //gmp lut length is 9*9*9
    compat_pointer(gmp_table_high4);
    compat_pointer(igm_r_table); //igm lut length is 257, the same with gamma
    compat_pointer(igm_g_table);
    compat_pointer(igm_b_table);
    compat_pointer(xcc_table);
};

struct gamma_info {
    uint32_t enable;
    uint32_t para_mode;
    compat_pointer(gamma_r_table); //gamma lut length 257
    compat_pointer(gamma_g_table);
    compat_pointer(gamma_b_table);
};

struct hiace_info {
    uint32_t image_info;
    uint32_t half_block_info;
    uint32_t xyweight;
    uint32_t lhist_sft;
    uint32_t roi_start_point;
    uint32_t roi_width_high;
    uint32_t roi_mode_ctrl;
    uint32_t roi_hist_stat_mode;
    uint32_t hue;
    uint32_t saturation;
    uint32_t value;
    uint32_t skin_gain;
    uint32_t up_low_th;
    uint32_t rgb_blend_weight;
    uint32_t fna_statistic;
    uint32_t up_cnt;
    uint32_t low_cnt;
    uint32_t sum_saturation;
    uint32_t lhist_en;
    uint32_t gamma_w;
    uint32_t gamma_r;
    uint32_t fna_addr;
    uint32_t fna_data;
    uint32_t update_fna;
    uint32_t fna_valid;
    uint32_t db_pipe_cfg;
    uint32_t db_pipe_ext_width;
    uint32_t db_pipe_full_img_width;
    uint32_t bypass_nr;
    uint32_t s3_some_brightness01;
    uint32_t s3_some_brightness23;
    uint32_t s3_some_brightness4;
    uint32_t s3_min_max_sigma;
    uint32_t s3_green_sigma03;
    uint32_t s3_green_sigma45;
    uint32_t s3_red_sigma03;
    uint32_t s3_red_sigma45;
    uint32_t s3_blue_sigma03;
    uint32_t s3_blue_sigma45;
    uint32_t s3_white_sigma03;
    uint32_t s3_white_sigma45;
    uint32_t s3_filter_level;
    uint32_t s3_similarity_coeff;
    uint32_t s3_v_filter_weight_adj;
    uint32_t s3_hue;
    uint32_t s3_saturation;
    uint32_t s3_value;
    uint32_t s3_skin_gain;
    uint32_t param_update;
    uint32_t enable;
    uint32_t enable_update;     // 1 valid; 0 invalid
    uint32_t lut_update;           // 1 valid; 0 invalid
    uint32_t thminv;
    unsigned int *lut;
};

struct dss_effect {
    bool dss_ready;
    bool arsr2p_sharp_support;
    bool arsr1p_sharp_support;
    bool acm_support;
    bool sbl_support;
    bool ace_support;
    bool hiace_support;
    bool lcp_igm_support;
    bool lcp_gmp_support;
    bool lcp_xcc_support;
    bool gamma_support;
    bool dither_support;
};

struct dss_reg{
    uint32_t tag;
    uint32_t value;
};

struct dss_effect_info {
    uint32_t modules;
    bool arsr1p_rog_initialized;

    struct acm_info acm;
    struct arsr1p_info arsr1p[2]; /* 0: normal arsr1p; 1: ROG arsr1p*/
    struct arsr2p_info arsr2p[3]; /* 0: 1:1 arsr2p; 1: scale-up arsr2p; 2: scale-down arsr2p */
    struct lcp_info lcp;
    struct gamma_info gamma;
    struct hiace_info hiace;
};


#endif  // EFFECT_KIRIN970_H
