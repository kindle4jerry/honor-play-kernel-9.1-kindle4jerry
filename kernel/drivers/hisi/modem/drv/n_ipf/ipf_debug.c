#include <linux/skbuff.h>
#include <linux/mm.h>
#include <bsp_slice.h>
#include <bsp_pm_om.h>
#include "ipf_balong.h"

#define SYMBOL(symbol)    #symbol

extern struct ipf_ctx g_ipf_ctx;

void bsp_ipf_show_status(void)
{
	int i;
	struct ipf_share_mem_map* sm = bsp_ipf_get_sharemem();
	struct ipf_debug* ptr = &sm->debug[0];
	struct int_handler* hd = g_ipf_ctx.irq_hd;

	g_ipf_ctx.status->flt_chain_loop = (unsigned int)ipf_readl(HI_IPF_FLT_CHAIN_LOOP_OFFSET);

	pr_err("======acore only=======================");
	pr_err("ipf_rst_leave 		%d\n", g_ipf_ctx.ipf_rst_leave);
	pr_err("dont get acore seg  %d\n", g_ipf_ctx.not_get_space);

	for (i = 0; i < IPF_CHANNEL_MAX; i++) {
		pr_err("====ipf %score status====\n", i == 0 ? "a" : "c");
		pr_err("flt_chain_loop		%d\n",  ptr->flt_chain_loop);
		pr_err("get_rd_num_times		%d\n", ptr->get_rd_num_times);
		pr_err("get_rd_times			%d\n", ptr->get_rd_times);
		pr_err("get_rd_short_cnt		%d\n", ptr->get_rd_cnt[IPF_AD_0]);
		pr_err("get_rd_long_cnt		%d\n", ptr->get_rd_cnt[IPF_AD_1]);
		pr_err("rd_len_update		%d\n", ptr->rd_len_update);
		pr_err("rd_len		%d\n", ptr->rd_len);
		pr_err("rd_len		%d\n", ptr->rd_ts);
		pr_err("get_ad_num_times		%d\n", ptr->get_ad_num_times);
		pr_err("cfg_ad_times		%d\n", ptr->cfg_ad_times);
		pr_err("get_ad_thred		%d\n", ptr->ad_thred);
		pr_err("short_adq_cfg_count	%d\n", ptr->cfg_ad_cnt[IPF_AD_0]);
		pr_err("short_adq_out_ptr_null	%d\n", ptr->ad_out_ptr_null[IPF_AD_0]);
		pr_err("long_adq_cfg_count	%d\n", ptr->cfg_ad_cnt[IPF_AD_1]);
		pr_err("long_adq_out_ptr_null	%d\n", ptr->ad_out_ptr_null[IPF_AD_1]);;
		pr_err("get_bd_num_times		%d\n", ptr->get_bd_num_times);
		pr_err("bd_cfg_times		%d\n", ptr->cfg_bd_times);
		pr_err("cfg_bd_cnt		%d\n", ptr->cfg_bd_cnt);
		pr_err("bd_full			%d\n", ptr->bd_full);
		pr_err("bd_len_zero_err		%d\n", ptr->bd_len_zero_err);
		pr_err("cd_not_enough			%d\n", ptr->cd_not_enough);
		pr_err("busy_cnt			%d\n", ptr->busy_cnt);
		pr_err("resume			%d\n", ptr->resume);
		pr_err("resume_with_intr			%d\n", ptr->resume_with_intr);
		pr_err("suspend			%d\n", ptr->suspend);
		pr_err("time_stamp_en		%d\n", ptr->timestamp_en);
		pr_err("rate_en			%d\n", ptr->rate_en);
		pr_err("init_ok			0x%x\n", ptr->init_ok);
		pr_err("mdrv_called_not_init	%d\n", ptr->mdrv_called_not_init);
		pr_err("invalid_para		%d\n", ptr->invalid_para);
		pr_err("scr wr			%d\n", ptr->reg_scur_wr_err);
		pr_err("scr rd			%d\n", ptr->reg_scur_rd_err);
		pr_err("occupy_cnt		%d\n", ptr->occupy_cnt);
		pr_err("ccore rst idle err		%d\n", ptr->ccore_rst_err);
		pr_err("ccore_reset		%d\n", ptr->ccore_reset);
		pr_err("core_rst_done		%d\n", ptr->core_rst_done);
        pr_err("cp_flag		%x\n", ptr->cp_flag);
        pr_err("rst_ts		%d\n", ptr->rst_ts);
		pr_err("dump_mem_alloc_ok		%d\n", ptr->dump_mem_alloc_ok);
		pr_err("dump_mem_alloc_ok		%d\n", ptr->rsr_suspend_begin);
		pr_err("dump_mem_alloc_ok		%d\n", ptr->rsr_suspend_end);
		pr_err("dump_mem_alloc_ok		%d\n", ptr->rsr_resume_begin);
		pr_err("dump_mem_alloc_ok		%d\n", ptr->rsr_resume_end);
		pr_err("========================\n");
		ptr++;
	}

	for(i=0;i<32;i++)
	{
		IPF_PRINT("%s\t%d\n", hd[i].name, hd[i].cnt);
	}
	
}

int bsp_ipf_bdinfo(IPF_CHANNEL_TYPE_E eChnType, unsigned int u32BdqPtr)
{
	IPF_CONFIG_PARAM_S sw_bd;
	
    switch(eChnType)
    {
        case IPF_CHANNEL_UP:
            if(u32BdqPtr >= IPF_ULBD_DESC_SIZE)
            {
                return IPF_ERROR;
            }
			g_ipf_ctx.desc->bd_h2s(&sw_bd, g_ipf_ctx.ul_info.pstIpfBDQ, u32BdqPtr);
            IPF_PRINT("==========BD Info=========\n");
            IPF_PRINT("BD position:         %d\n", u32BdqPtr);
            IPF_PRINT("int_en:   %d\n", sw_bd.int_en);
            IPF_PRINT("fc_head:   %d\n", sw_bd.fc_head);
            IPF_PRINT("u16PktLen:      %d\n", sw_bd.u16Len);
            IPF_PRINT("InPtr:       0x%lx\n", (unsigned long)sw_bd.Data);
            IPF_PRINT("u16UsrField1:   %d\n", sw_bd.u16UsrField1);
            IPF_PRINT("u32UsrField2:   0x%x\n", sw_bd.u32UsrField2);
            IPF_PRINT("u32UsrField3:   0x%x\n", sw_bd.u32UsrField3);
            break;
       case IPF_CHANNEL_DOWN:
            if(u32BdqPtr >= IPF_DLBD_DESC_SIZE)
            {
                return IPF_ERROR;
            }
			g_ipf_ctx.desc->bd_h2s(&sw_bd, g_ipf_ctx.dl_info.pstIpfBDQ, u32BdqPtr);
            IPF_PRINT("==========BD Info=========\n");
            IPF_PRINT("BD position:         %d\n",u32BdqPtr);
            IPF_PRINT("int_en:   %d\n", sw_bd.int_en);
            IPF_PRINT("fc_head:   %d\n", sw_bd.fc_head);
			IPF_PRINT("u16PktLen:      %d\n", sw_bd.u16Len);
            IPF_PRINT("InPtr:       0x%lx\n", (unsigned long)sw_bd.Data);
            IPF_PRINT("u16UsrField1:   %d\n", sw_bd.u16UsrField1);
            IPF_PRINT("u32UsrField2:   0x%x\n", sw_bd.u32UsrField2);
            IPF_PRINT("u32UsrField3:   0x%x\n", sw_bd.u32UsrField3);
            break; 
        default:
            break;
    }
    IPF_PRINT("************************\n");
    return 0;
}

int bsp_ipf_dump_bdinfo(IPF_CHANNEL_TYPE_E eChnType)
{
    unsigned int i;
    switch(eChnType)
    {
        case IPF_CHANNEL_UP:

            for(i = 0;i < IPF_ULBD_DESC_SIZE;i++)
            {
                bsp_ipf_bdinfo(IPF_CHANNEL_UP,i);
            }
        break;

        case IPF_CHANNEL_DOWN:

            for(i = 0;i < IPF_DLBD_DESC_SIZE;i++)
            {
                bsp_ipf_bdinfo(IPF_CHANNEL_DOWN,i);
            }
        break;

        default:
        IPF_PRINT("Input param invalid ! \n");
        break;

    }
    return 0;
}

unsigned long bsp_ipf_ad0_info(unsigned long *ad0_addr)
{
//	struct ipf_share_mem_map* sm = bsp_ipf_get_sharemem();
	
//	*ad0_addr = *((unsigned long*)&sm->dad0);
	return 0;
}

unsigned long bsp_ipf_ad1_info(unsigned long *ad1_addr)
{
//	struct ipf_share_mem_map* sm = bsp_ipf_get_sharemem();
	
//	*ad1_addr = *((unsigned long*)&sm->dad1);
	return 0;
}

int bsp_ipf_rdinfo(IPF_CHANNEL_TYPE_E eChnType, unsigned int u32RdqPtr)
{
	IPF_RD_DESC_S sw_rd;
    switch(eChnType)
    {
        case IPF_CHANNEL_UP:
            if(u32RdqPtr >= IPF_ULRD_DESC_SIZE)
            {
                return IPF_ERROR;
            }
			g_ipf_ctx.desc->rd_h2s(&sw_rd, g_ipf_ctx.ul_info.pstIpfRDQ, u32RdqPtr);
            IPF_PRINT("===========RD Info==========\n");
            IPF_PRINT("RD position:             %d\n",u32RdqPtr);
            IPF_PRINT("u16Attribute:       %d\n",sw_rd.u16Attribute);
            IPF_PRINT("u16PktLen:          %d\n",sw_rd.u16PktLen);
            IPF_PRINT("InPtr:              0x%lx\n",(unsigned long)sw_rd.InPtr);
            IPF_PRINT("OutPtr:          0x%lx\n",(unsigned long)sw_rd.OutPtr);
            IPF_PRINT("u16Result:          0x%x\n",sw_rd.u16Result);
            IPF_PRINT("u16UsrField1:       0x%x\n",sw_rd.u16UsrField1);
            IPF_PRINT("u32UsrField2:       0x%x\n",sw_rd.u32UsrField2);
            IPF_PRINT("u32UsrField3:       0x%x\n",sw_rd.u32UsrField3);
            break;
       case IPF_CHANNEL_DOWN:
            if(u32RdqPtr >= IPF_DLRD_DESC_SIZE)
            {
                return IPF_ERROR;
            }
			g_ipf_ctx.desc->rd_h2s(&sw_rd, g_ipf_ctx.dl_info.pstIpfRDQ, u32RdqPtr);
            IPF_PRINT("============RD Info===========\n");
            IPF_PRINT("RD position:             %d\n",u32RdqPtr);
            IPF_PRINT("u16Attribute:       %d\n",sw_rd.u16Attribute);
            IPF_PRINT("u16PktLen:          %d\n",sw_rd.u16PktLen);
            IPF_PRINT("InPtr:           0x%lx\n",(unsigned long)sw_rd.InPtr);
            IPF_PRINT("OutPtr:          0x%lx\n",(unsigned long)sw_rd.OutPtr);
            IPF_PRINT("u16Result:          0x%x\n",sw_rd.u16Result);
            IPF_PRINT("u16UsrField1:       0x%x\n",sw_rd.u16UsrField1);
            IPF_PRINT("u32UsrField2:       0x%x\n",sw_rd.u32UsrField2);
            IPF_PRINT("u32UsrField3:       0x%x\n",sw_rd.u32UsrField3);
            break;
        default:
            break;
    }
    IPF_PRINT("************************\n");
    return 0;
}

int bsp_ipf_dump_rdinfo(IPF_CHANNEL_TYPE_E eChnType)
{
    unsigned int i;

    switch(eChnType)
    {
        case IPF_CHANNEL_UP:

            for(i = 0;i < IPF_ULBD_DESC_SIZE;i++)
            {
                bsp_ipf_rdinfo(IPF_CHANNEL_UP,i);
            }
        break;

        case IPF_CHANNEL_DOWN:

            for(i = 0;i < IPF_DLBD_DESC_SIZE;i++)
            {
                bsp_ipf_rdinfo(IPF_CHANNEL_DOWN,i);
            }
        break;
        default:
        IPF_PRINT("Input param invalid ! \n");
        break;
    }
    return 0;
}
int bsp_ipf_adinfo(IPF_CHANNEL_TYPE_E eChnType, unsigned int u32AdqPtr, unsigned int u32AdType)
{
	IPF_AD_DESC_S sw_ad;

    switch(eChnType)
    {
        case IPF_CHANNEL_UP:
            if(u32AdqPtr >= IPF_ULAD0_DESC_SIZE)
            {
                return IPF_ERROR;
            }
            if(0 == u32AdType)
            {
            	g_ipf_ctx.desc->ad_h2s(&sw_ad, g_ipf_ctx.ul_info.pstIpfADQ0, u32AdqPtr);
                 IPF_PRINT("===========UL AD0 Info==========\n");
                 IPF_PRINT("AD position:             %d\n",u32AdqPtr);
                 IPF_PRINT("OutPtr0(phy_addr, use by hardware):       0x%lx\n",(unsigned long)sw_ad.OutPtr0);
                 IPF_PRINT("OutPtr1(usrfield skb_addr default):          0x%lx\n",(unsigned long)sw_ad.OutPtr1);
            }
            else
            {
            	g_ipf_ctx.desc->ad_h2s(&sw_ad, g_ipf_ctx.ul_info.pstIpfADQ1, u32AdqPtr);
                 IPF_PRINT("===========UL AD1 Info==========\n");
                 IPF_PRINT("AD position:             %d\n",u32AdqPtr);
                 IPF_PRINT("OutPtr0(phy_addr, use by hardware):       0x%lx\n",(unsigned long)sw_ad.OutPtr0);
                 IPF_PRINT("OutPtr1(usrfield skb_addr default):          0x%lx\n",(unsigned long)sw_ad.OutPtr1);
            }
            break;
       case IPF_CHANNEL_DOWN:
            if(u32AdqPtr >= IPF_ULAD1_DESC_SIZE)
            {
                return IPF_ERROR;
            }
            if(0 == u32AdType)
	      	{
	      		g_ipf_ctx.desc->ad_h2s(&sw_ad, g_ipf_ctx.dl_info.pstIpfADQ0, u32AdqPtr);
                 IPF_PRINT("===========DL AD0 Info==========\n");
                 IPF_PRINT("AD position:             %d\n",u32AdqPtr);
                 IPF_PRINT("OutPtr0(phy_addr, use by hardware):       0x%lx\n",(unsigned long)sw_ad.OutPtr0);
                 IPF_PRINT("OutPtr1(usrfield skb_addr default):          0x%lx\n",(unsigned long)sw_ad.OutPtr1);
            }
            else
            {
            	g_ipf_ctx.desc->ad_h2s(&sw_ad, g_ipf_ctx.dl_info.pstIpfADQ1, u32AdqPtr);
                 IPF_PRINT("===========DL AD1 Info==========\n");
                 IPF_PRINT("AD position:             %d\n",u32AdqPtr);
                 IPF_PRINT("OutPtr0(phy_addr, use by hardware):       0x%lx\n",(unsigned long)sw_ad.OutPtr0);
                 IPF_PRINT("OutPtr1(usrfield skb_addr default):          0x%lx\n",(unsigned long)sw_ad.OutPtr1);
            }
            break;
        default:
            break;
    }
    IPF_PRINT("************************\n");
    return 0;
}


int bsp_ipf_dump_adinfo(IPF_CHANNEL_TYPE_E eChnType, unsigned int u32AdType)
{
    int i;

    switch(eChnType)
    {
        case IPF_CHANNEL_UP:
            for(i = 0;i < IPF_ULAD0_DESC_SIZE;i++)
            {
                bsp_ipf_adinfo(IPF_CHANNEL_UP, i, u32AdType);
            }
        break;

        case IPF_CHANNEL_DOWN:

            for(i = 0;i < IPF_DLAD1_DESC_SIZE;i++)
            {
                bsp_ipf_adinfo(IPF_CHANNEL_DOWN, i, u32AdType);
            }
        break;

        default:
        IPF_PRINT("Input param invalid ! \n");
        break;
    }
    return 0;
}

int bsp_ipf32_info(IPF_CHANNEL_TYPE_E eChnType)
{
    unsigned int u32BdqDepth = 0;
    unsigned int u32BdqWptr = 0;
    unsigned int u32BdqRptr = 0;
    unsigned int u32BdqWaddr = 0;
    unsigned int u32BdqRaddr = 0;
    unsigned int u32RdqDepth = 0;
    unsigned int u32RdqRptr = 0;
    unsigned int u32RdqWptr = 0;
    unsigned int u32RdqWaddr = 0;
    unsigned int u32RdqRaddr = 0;
    unsigned int u32status = 0;

    unsigned int u32Adq0Rptr = 0;
    unsigned int u32Adq0Wptr = 0;

    unsigned int u32Adq1Rptr = 0;
    unsigned int u32Adq1Wptr = 0;
    HI_IPF_CH0_DQ_DEPTH_T dq_depth;

    if(IPF_CHANNEL_UP == eChnType)
    {
        dq_depth.u32 = ipf_readl(HI_IPF32_CH0_DQ_DEPTH_OFFSET);
        u32RdqDepth = dq_depth.bits.ul_rdq_depth;
        u32BdqDepth = dq_depth.bits.ul_bdq_depth;

        u32status = ipf_readl(HI_IPF32_CH0_STATE_OFFSET);

        u32BdqWptr = ipf_readl(HI_IPF32_CH0_BDQ_WPTR_OFFSET);
        u32BdqRptr = ipf_readl(HI_IPF32_CH0_BDQ_RPTR_OFFSET);
        u32BdqWaddr = ipf_readl(HI_IPF32_CH0_BDQ_WADDR_OFFSET);
        u32BdqRaddr = ipf_readl(HI_IPF32_CH0_BDQ_RADDR_OFFSET);

        u32RdqWptr = ipf_readl(HI_IPF32_CH0_RDQ_WPTR_OFFSET);
        u32RdqRptr = ipf_readl(HI_IPF32_CH0_RDQ_RPTR_OFFSET);
        u32RdqWaddr = ipf_readl(HI_IPF32_CH0_RDQ_WADDR_OFFSET);
        u32RdqRaddr = ipf_readl(HI_IPF32_CH0_RDQ_RADDR_OFFSET);

        u32Adq0Rptr = ipf_readl(HI_IPF32_CH0_ADQ0_RPTR_OFFSET);
        u32Adq0Wptr = ipf_readl(HI_IPF32_CH0_ADQ0_WPTR_OFFSET);

        u32Adq1Rptr = ipf_readl(HI_IPF32_CH0_ADQ1_RPTR_OFFSET);
        u32Adq1Wptr = ipf_readl(HI_IPF32_CH0_ADQ1_WPTR_OFFSET);

    }
    else if(IPF_CHANNEL_DOWN == eChnType)
    {
        dq_depth.u32 = ipf_readl(HI_IPF32_CH1_DQ_DEPTH_OFFSET);
        u32RdqDepth = dq_depth.bits.ul_rdq_depth;
        u32BdqDepth = dq_depth.bits.ul_bdq_depth;

        u32status = ipf_readl(HI_IPF32_CH1_STATE_OFFSET);

        u32BdqWptr = ipf_readl(HI_IPF32_CH1_BDQ_WPTR_OFFSET);
        u32BdqRptr = ipf_readl(HI_IPF32_CH1_BDQ_RPTR_OFFSET);
        u32BdqWaddr = ipf_readl(HI_IPF32_CH1_BDQ_WADDR_OFFSET);
        u32BdqRaddr = ipf_readl(HI_IPF32_CH1_BDQ_RADDR_OFFSET);

        u32RdqWptr = ipf_readl(HI_IPF32_CH1_RDQ_WPTR_OFFSET);
        u32RdqRptr = ipf_readl(HI_IPF32_CH1_RDQ_RPTR_OFFSET);
        u32RdqWaddr = ipf_readl(HI_IPF32_CH1_RDQ_WADDR_OFFSET);
        u32RdqRaddr = ipf_readl(HI_IPF32_CH1_RDQ_RADDR_OFFSET);

        u32Adq0Rptr = ipf_readl(HI_IPF32_CH1_ADQ0_RPTR_OFFSET);
        u32Adq0Wptr = ipf_readl(HI_IPF32_CH1_ADQ0_WPTR_OFFSET);

        u32Adq1Rptr = ipf_readl(HI_IPF32_CH1_ADQ1_RPTR_OFFSET);
        u32Adq1Wptr = ipf_readl(HI_IPF32_CH1_ADQ1_WPTR_OFFSET);

    }
    else
    {
        return 1;
    }
    IPF_PRINT("============================\n");
    IPF_PRINT("channel status:      0x%x\n", u32status);
    IPF_PRINT("BD depth:            %d\n", u32BdqDepth);
    IPF_PRINT("BD wptr:             %d\n", u32BdqWptr);
    IPF_PRINT("BD rptr:             %d\n", u32BdqRptr);
    IPF_PRINT("BD write addr:       0x%x\n", u32BdqWaddr);
    IPF_PRINT("BD read addr:        0x%x\n", u32BdqRaddr);
    IPF_PRINT("RD depth:            %d\n", u32RdqDepth);
    IPF_PRINT("RD rptr:             %d\n", u32RdqRptr);
    IPF_PRINT("RD wptr:             %d\n", u32RdqWptr);
    IPF_PRINT("RD read addr:        0x%x\n", u32RdqRaddr);
    IPF_PRINT("RD write addr:       0x%x\n", u32RdqWaddr);
    IPF_PRINT("AD0 rptr:            %d\n", u32Adq0Rptr);
    IPF_PRINT("AD0 wptr:            %d\n", u32Adq0Wptr);
    IPF_PRINT("AD1 rptr:            %d\n", u32Adq1Rptr);
    IPF_PRINT("AD1 wptr:            %d\n", u32Adq1Wptr);
    IPF_PRINT("============================\n");
    return 0;
}

int bsp_ipf64_info(IPF_CHANNEL_TYPE_E eChnType)
{
    unsigned int u32BdqDepth = 0;
    unsigned int u32BdqWptr = 0;
    unsigned int u32BdqRptr = 0;
    unsigned int u32BdqWaddr = 0;
    unsigned int u32BdqRaddr = 0;
    unsigned int u32RdqDepth = 0;
    unsigned int u32RdqRptr = 0;
    unsigned int u32RdqWptr = 0;
    unsigned int u32RdqWaddr = 0;
    unsigned int u32RdqRaddr = 0;
    unsigned int u32status = 0;

    unsigned int u32Adq0Rptr = 0;
    unsigned int u32Adq0Wptr = 0;

    unsigned int u32Adq1Rptr = 0;
    unsigned int u32Adq1Wptr = 0;
    HI_IPF_CH0_RDQ_DEPTH_T dq_depth;

    if(IPF_CHANNEL_UP == eChnType)
    {
        dq_depth.u32 = ipf_readl(HI_IPF64_CH0_RDQ_DEPTH_OFFSET);
        u32RdqDepth = dq_depth.bits.ul_rdq_depth;
        u32BdqDepth = dq_depth.bits.ul_rdq_depth;

        u32status = ipf_readl(HI_IPF64_CH0_STATE_OFFSET);

        u32BdqWptr = ipf_readl(HI_IPF64_CH0_BDQ_WPTR_OFFSET);
        u32BdqRptr = ipf_readl(HI_IPF64_CH0_BDQ_RPTR_OFFSET);

		u32BdqWaddr = phy_addr_read((unsigned char*)g_ipf_ctx.regs + HI_IPF64_CH0_BDQ_WADDR_H_OFFSET,
		                            (unsigned char*)g_ipf_ctx.regs + HI_IPF64_CH0_BDQ_WADDR_L_OFFSET);

		u32BdqRaddr = phy_addr_read((unsigned char*)g_ipf_ctx.regs + HI_IPF64_CH0_BDQ_RADDR_H_OFFSET,
		                            (unsigned char*)g_ipf_ctx.regs + HI_IPF64_CH0_BDQ_RADDR_L_OFFSET);
        u32RdqWptr = ipf_readl(HI_IPF64_CH0_RDQ_WPTR_OFFSET);
        u32RdqRptr = ipf_readl(HI_IPF64_CH0_RDQ_RPTR_OFFSET);

		u32RdqWaddr = phy_addr_read((unsigned char*)g_ipf_ctx.regs + HI_IPF64_CH0_RDQ_WADDR_H_OFFSET,
		                            (unsigned char*)g_ipf_ctx.regs + HI_IPF64_CH0_RDQ_WADDR_L_OFFSET);

		u32RdqRaddr = phy_addr_read((unsigned char*)g_ipf_ctx.regs + HI_IPF64_CH0_RDQ_RADDR_H_OFFSET,
		                            (unsigned char*)g_ipf_ctx.regs + HI_IPF64_CH0_RDQ_RADDR_L_OFFSET);

        u32Adq0Rptr = ipf_readl(HI_IPF64_CH0_ADQ0_RPTR_OFFSET);
        u32Adq0Wptr = ipf_readl(HI_IPF64_CH0_ADQ0_WPTR_OFFSET);

        u32Adq1Rptr = ipf_readl(HI_IPF64_CH0_ADQ1_RPTR_OFFSET);
        u32Adq1Wptr = ipf_readl(HI_IPF64_CH0_ADQ1_WPTR_OFFSET);

    }
    else if(IPF_CHANNEL_DOWN == eChnType)
    {
        dq_depth.u32 = ipf_readl(HI_IPF64_CH1_RDQ_DEPTH_OFFSET);
        u32RdqDepth = dq_depth.bits.ul_rdq_depth;
        u32BdqDepth = dq_depth.bits.ul_rdq_depth;

        u32status = ipf_readl(HI_IPF64_CH1_STATE_OFFSET);

        u32BdqWptr = ipf_readl(HI_IPF64_CH1_BDQ_WPTR_OFFSET);
        u32BdqRptr = ipf_readl(HI_IPF64_CH1_BDQ_RPTR_OFFSET);
		u32BdqWaddr = phy_addr_read((unsigned char*)g_ipf_ctx.regs + HI_IPF64_CH1_BDQ_WADDR_H_OFFSET,
		                            (unsigned char*)g_ipf_ctx.regs + HI_IPF64_CH1_BDQ_WADDR_L_OFFSET);
		u32BdqRaddr = phy_addr_read((unsigned char*)g_ipf_ctx.regs + HI_IPF64_CH1_BDQ_RADDR_H_OFFSET,
		                            (unsigned char*)g_ipf_ctx.regs + HI_IPF64_CH1_BDQ_RADDR_L_OFFSET);
        u32RdqWptr = ipf_readl(HI_IPF64_CH1_RDQ_WPTR_OFFSET);
        u32RdqRptr = ipf_readl(HI_IPF64_CH1_RDQ_RPTR_OFFSET);
		u32RdqWaddr = phy_addr_read((unsigned char*)g_ipf_ctx.regs + HI_IPF64_CH1_RDQ_WADDR_H_OFFSET,
		                            (unsigned char*)g_ipf_ctx.regs + HI_IPF64_CH1_RDQ_WADDR_L_OFFSET);
		u32RdqRaddr = phy_addr_read((unsigned char*)g_ipf_ctx.regs + HI_IPF64_CH1_RDQ_RADDR_H_OFFSET,
		                            (unsigned char*)g_ipf_ctx.regs + HI_IPF64_CH1_RDQ_RADDR_L_OFFSET);

        u32Adq0Rptr = ipf_readl(HI_IPF64_CH1_ADQ0_RPTR_OFFSET);
        u32Adq0Wptr = ipf_readl(HI_IPF64_CH1_ADQ0_WPTR_OFFSET);

        u32Adq1Rptr = ipf_readl(HI_IPF64_CH1_ADQ1_RPTR_OFFSET);
        u32Adq1Wptr = ipf_readl(HI_IPF64_CH1_ADQ1_WPTR_OFFSET);

    }
    else
    {
        return 1;
    }
    IPF_PRINT("============================\n");
    IPF_PRINT("channel status:        0x%x\n", u32status);
    IPF_PRINT("BD depth:              %d\n", u32BdqDepth);
    IPF_PRINT("BD wptr:               %d\n", u32BdqWptr);
    IPF_PRINT("BD rptr:               %d\n", u32BdqRptr);
    IPF_PRINT("BD write addr:         0x%x\n", u32BdqWaddr);
    IPF_PRINT("BD read addr:          0x%x\n", u32BdqRaddr);
    IPF_PRINT("RD depth:              %d\n", u32RdqDepth);
    IPF_PRINT("RD rptr:               %d\n", u32RdqRptr);
    IPF_PRINT("RD wptr:               %d\n", u32RdqWptr);
    IPF_PRINT("RD read addr:          0x%x\n", u32RdqRaddr);
    IPF_PRINT("RD write addr:         0x%x\n", u32RdqWaddr);
    IPF_PRINT("AD0 rptr:              %d\n", u32Adq0Rptr);
    IPF_PRINT("AD0 wptr:              %d\n", u32Adq0Wptr);
    IPF_PRINT("AD1 rptr:              %d\n", u32Adq1Rptr);
    IPF_PRINT("AD1 wptr:              %d\n", u32Adq1Wptr);
    IPF_PRINT("============================\n");
    return 0;
}

int bsp_ipf_info(IPF_CHANNEL_TYPE_E eChnType)
{
	if(g_ipf_ctx.ipf_version < IPF_VERSION_160){
		return bsp_ipf32_info(eChnType);
	}
	else{
		return bsp_ipf64_info(eChnType);
	}
}

void bsp_ipf_mem(void)
{
	ipf_ddr_t *ddr_info;
	unsigned int dl_start;
	struct ipf_share_mem_map* sm = bsp_ipf_get_sharemem();
	dl_start = (unsigned int)(unsigned long)g_ipf_ctx.dl_info.pstIpfBDQ;
	ddr_info= &g_ipf_ctx.status->share_ddr_info;
	
	
	IPF_PRINT("IPF Shared DDR information:\n");
	IPF_PRINT("start                 0x%x \n", ddr_info->start);
	IPF_PRINT("ul_start              0x%x \n", ddr_info->ul_start);
	IPF_PRINT("dl_start              0x%x \n", dl_start);
	IPF_PRINT("filter_pwc_start      0x%x \n", ddr_info->filter_pwc_start);
	IPF_PRINT("pwc_info_start        0x%x \n", ddr_info->pwc_info_start);
	IPF_PRINT("dlcdrptr              0x%x \n", ddr_info->dlcdrptr);
	IPF_PRINT("debug_dlcd_start      0x%x \n", ddr_info->debug_dlcd_start);
	IPF_PRINT("debug_dlcd_size       0x%x \n", ddr_info->debug_dlcd_size);
	IPF_PRINT("end                   0x%x \n", ddr_info->end);
	IPF_PRINT("len(The max:0x10000)  0x%x \n", ddr_info->len);

    IPF_PRINT("=======================================\n");
    IPF_PRINT("   bsp_ipf_mem          ADDR            SIZE\n");
    IPF_PRINT("%s%lx\t%d\n", "IPF_INIT_ADDR        ", (unsigned long)&sm->init, IPF_INIT_SIZE);
    IPF_PRINT("%s%lx\t\t%lu\n", "IPF_DEBUG_INFO_ADDR  ", (unsigned long)&sm->debug[0], (unsigned long)IPF_DEBUG_INFO_SIZE);
}

void ipf_enable_dl_time_stamp(int en)
{
	g_ipf_ctx.status->timestamp_en = en;
    return;
}

void ipf_enable_rd_rate(int en)
{
	g_ipf_ctx.status->rate_en = en;
    return;
}

void ipf_clear_time_stamp(void)
{


    return;
}

static inline
unsigned int ipf_calc_percent(unsigned int value, unsigned int sum)
{
    if (0 == sum) {
        return 0;
    }
    return (value * 100 / sum);
}

void ipf_dump_time_stamp(void)
{
    IPF_TIMESTAMP_INFO_S* stamp_info = &g_ipf_ctx.timestamp;
    unsigned int tmp = 0;
    int i;

    printk(" max diff:%u(%uus)\n",
              stamp_info->diff_max, stamp_info->diff_max*10/192);
    printk(" sum diff:%u(%uus)\n",
              stamp_info->diff_sum, stamp_info->diff_max/19);

    if (stamp_info->cnt_sum) {
        tmp = stamp_info->diff_sum / stamp_info->cnt_sum;
    }

    printk(" avg diff:%u(%uus)\n", tmp, tmp*10/192);

    for (i = 0; i < IPF_MAX_STAMP_ORDER; i++) {
        tmp = ipf_calc_percent(stamp_info->diff_order_cnt[i], stamp_info->cnt_sum);
        printk(" diff time (%u~%u) (%uus~%uus) count:%u (%u %%)\n",
            (0x80000000 >> (31-i)),
            (0xFFFFFFFF >> (31-i)),
            (0x80000000 >> (31-i))/19,
            (0xFFFFFFFF >> (31-i))/19,
            stamp_info->diff_order_cnt[i], tmp);
    }
    return;
}

void bsp_ipf_ad_status(void)
{
	HI_IPF_CH1_ADQ0_STAT_T ad0_stat;
	HI_IPF_CH1_ADQ1_STAT_T ad1_stat;
	if(g_ipf_ctx.ipf_version <  IPF_VERSION_160){
		ad0_stat.u32 = ipf_readl(HI_IPF32_CH1_ADQ0_STAT_OFFSET);
		ad1_stat.u32 = ipf_readl(HI_IPF32_CH1_ADQ1_STAT_OFFSET);
	}
	else{
		ad0_stat.u32 = ipf_readl(HI_IPF64_CH1_ADQ0_STAT_OFFSET);
		ad1_stat.u32 = ipf_readl(HI_IPF64_CH1_ADQ1_STAT_OFFSET);
	}

	if((ad0_stat.bits.dl_adq0_buf_epty == 1)&&(ad0_stat.bits.dl_adq0_buf_full == 1))
	{
		printk("\r CH1_AD0_BUF_FLAG_ERROR.\n");
	}
	else if(ad0_stat.bits.dl_adq0_buf_full == 1)
	{
		printk("\r CH1_AD0_BUF_NUM 2,2 unused AD in AD_Buff.\n");
	}
	else if(ad0_stat.bits.dl_adq0_buf_epty == 1)
	{
		printk("\r CH1_AD0_BUF_NUM 0,0 unused AD in AD_Buff.\n");
	}
	else
	{
		printk("\r CH1_AD0_BUF_NUM 1,1 unused AD in AD_Buff.\n");
	}
	
	if((ad1_stat.bits.dl_adq1_buf_epty == 1)&&(ad1_stat.bits.dl_adq1_buf_full == 1))
	{
		printk("\r CH1_AD1_BUF_FLAG_ERROR.\n");
	}
	else if(ad1_stat.bits.dl_adq1_buf_full == 1)
	{
		printk("\r CH1_AD1_BUF_NUM 2,2 unused AD in AD_Buff.\n");
	}
	else if(ad1_stat.bits.dl_adq1_buf_epty == 1)
	{
		printk("\r CH1_AD1_BUF_NUM 0,0 unused AD in AD_Buff.\n");
	}
	else
	{
		printk("\r CH1_AD1_BUF_NUM 1,1 unused AD in AD_Buff.\n");
	}
	return;
}

void ipf_pm_print_packet(void *buf, size_t len)
{
	void *virt = buf;

	if (g_ipf_ctx.status->resume_with_intr){
		if (!virt_addr_valid(buf)){//lint !e648
			virt = phys_to_virt((unsigned long)buf);
			if(!virt_addr_valid(virt)){//lint !e648
				return;
			}
		}

		virt = (void *)(((struct sk_buff*)virt)->data);
		if (!virt_addr_valid(virt)){//lint !e648
			return;
		}
		
		if (len > MAX_PM_OM_SAVE_SIZE) {
			len = MAX_PM_OM_SAVE_SIZE;
		}
		
    	dma_unmap_single(g_ipf_ctx.dev, (dma_addr_t)virt_to_phys(virt), len, DMA_FROM_DEVICE);

		bsp_pm_log(PM_OM_AIPF, len, virt);

		print_hex_dump(KERN_INFO, "", DUMP_PREFIX_ADDRESS, 16, 1, virt, len, 0);

		g_ipf_ctx.status->resume_with_intr = 0;
	}
	return;
}

int ipf_rd_rate(unsigned int enable, IPF_CHANNEL_TYPE_E eChnType)
{
	unsigned int rate = 0;
	unsigned int rd_len = 0;
	unsigned int rd_ts =  0;
	unsigned int ratio = IPF_LEN_RATIO / (IPF_TIMER_RATIO * 8);

	if(!enable) {
		return IPF_ERROR;
	}

	switch(eChnType)
    {
		case IPF_CHANNEL_DOWN:
			rd_ts =  bsp_get_slice_value() - g_ipf_ctx.status->rd_ts;
			if(rd_ts < IPF_RD_TMOUT) {
				return IPF_ERROR;
			}

			rd_len = g_ipf_ctx.status->rd_len_update - g_ipf_ctx.status->rd_len;
			g_ipf_ctx.status->rd_ts = bsp_get_slice_value();
			g_ipf_ctx.status->rd_len = g_ipf_ctx.status->rd_len_update;
			break;
		default:
            break;
	}

	if(rd_len <= 0 || rd_ts <= 0) {
		IPF_PRINT("ipf rd len or ts err!\n");
		return IPF_ERROR;
	} else {
		rate = rd_len / (rd_ts * ratio);
		IPF_PRINT("ipf rd rate:%uMbps\n", rate);
	}

	return IPF_SUCCESS;
}

void ipf_print_statx(void)
{
    IPF_PRINT("direct_bd:                  %10u\n", g_ipf_ctx.stax.direct_bd);
    IPF_PRINT("indirect_bd:                %10u\n", g_ipf_ctx.stax.indirect_bd);
    IPF_PRINT("wakeup_irq:                 %10u\n", g_ipf_ctx.stax.wakeup_irq);
    IPF_PRINT("pkt_dbg_in:                 %10u\n", g_ipf_ctx.stax.pkt_dbg_in);
    IPF_PRINT("pkt_dbg_out:                %10u\n", g_ipf_ctx.stax.pkt_dbg_out);
}

struct ipf_mannul_unit ipf_mannul[] = {
    {SYMBOL(bsp_ipf_show_status),   "\n"},
    {SYMBOL(bsp_ipf_info),      "\n"},
    {SYMBOL(bsp_ipf_bdinfo),    "\n"},
    {SYMBOL(bsp_ipf_rdinfo),    "\n"},
    {SYMBOL(bsp_ipf_adinfo),    "\n"},
    {SYMBOL(bsp_ipf_dump_bdinfo),   "\n"},
    {SYMBOL(bsp_ipf_dump_rdinfo),   "\n"},
    {SYMBOL(bsp_ipf_dump_adinfo),   "\n"},
    {SYMBOL(ipf_enable_dl_time_stamp),  "\n"},
    {SYMBOL(ipf_clear_time_stamp),  "\n"},
    {SYMBOL(ipf_dump_time_stamp),   "\n"},
    {SYMBOL(bsp_ipf_mem),   "\n"},
    {SYMBOL(ipf_enable_dl_time_stamp),    "\n"},
    {SYMBOL(ipf_clear_time_stamp),  "\n"},
    {SYMBOL(ipf_dump_time_stamp),  "\n"},
    {SYMBOL(bsp_ipf_ad_status),  "\n"},
};

void bsp_ipf_help(void)
{
    unsigned int i;

    for(i=0;i<sizeof(ipf_mannul)/sizeof(ipf_mannul[0]);i++)
    {
        IPF_PRINT("%s",ipf_mannul[i].name);
        IPF_PRINT("\t");
        IPF_PRINT("%s",ipf_mannul[i].desc);
        IPF_PRINT("\n");
    }
}

EXPORT_SYMBOL(bsp_ipf_dump_bdinfo);
EXPORT_SYMBOL(bsp_ipf_help);
EXPORT_SYMBOL(bsp_ipf_ad0_info);
EXPORT_SYMBOL(bsp_ipf_dump_adinfo);
EXPORT_SYMBOL(bsp_ipf_mem);
EXPORT_SYMBOL(bsp_ipf_info);
EXPORT_SYMBOL(bsp_ipf_dump_rdinfo);
EXPORT_SYMBOL(bsp_ipf_ad1_info);
EXPORT_SYMBOL(bsp_ipf_ad_status);
EXPORT_SYMBOL(bsp_ipf_bdinfo);
EXPORT_SYMBOL(bsp_ipf_adinfo);


