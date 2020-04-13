#ifndef __PMIC_INTERFACE_H__
#define __PMIC_INTERFACE_H__ 
#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif
#ifndef __SOC_H_FOR_ASM__
#define PMIC_VERSION0_ADDR(base) ((base) + (0x000UL))
#define PMIC_VERSION1_ADDR(base) ((base) + (0x001UL))
#define PMIC_VERSION2_ADDR(base) ((base) + (0x002UL))
#define PMIC_VERSION3_ADDR(base) ((base) + (0x003UL))
#define PMIC_VERSION4_ADDR(base) ((base) + (0x004UL))
#define PMIC_VERSION5_ADDR(base) ((base) + (0x005UL))
#define PMIC_STATUS0_ADDR(base) ((base) + (0x006UL))
#define PMIC_STATUS1_ADDR(base) ((base) + (0x007UL))
#define PMIC_BUCK0_ONOFF_ECO_ADDR(base) ((base) + (0x008UL))
#define PMIC_BUCK1_ONOFF_ECO_ADDR(base) ((base) + (0x009UL))
#define PMIC_BUCK2_ONOFF_ECO_ADDR(base) ((base) + (0x00AUL))
#define PMIC_BUCK3_ONOFF_ECO_ADDR(base) ((base) + (0x00BUL))
#define PMIC_BUCK4_ONOFF_ECO_ADDR(base) ((base) + (0x00CUL))
#define PMIC_BUCK5_ONOFF_ECO_ADDR(base) ((base) + (0x00DUL))
#define PMIC_BUCK6_ONOFF_ECO_ADDR(base) ((base) + (0x00EUL))
#define PMIC_BUCK7_ONOFF_ECO_ADDR(base) ((base) + (0x00FUL))
#define PMIC_BUCK8_ONOFF_ECO_ADDR(base) ((base) + (0x010UL))
#define PMIC_LDO0_1_ONOFF_ADDR(base) ((base) + (0x011UL))
#define PMIC_LDO0_2_ONOFF_ECO_ADDR(base) ((base) + (0x012UL))
#define PMIC_LDO1_ONOFF_ADDR(base) ((base) + (0x013UL))
#define PMIC_LDO2_ONOFF1_ADDR(base) ((base) + (0x014UL))
#define PMIC_LDO2_ONOFF2_ADDR(base) ((base) + (0x015UL))
#define PMIC_LDO3_ONOFF_ADDR(base) ((base) + (0x016UL))
#define PMIC_LDO4_ONOFF_ECO_ADDR(base) ((base) + (0x017UL))
#define PMIC_LDO5_ONOFF_ADDR(base) ((base) + (0x018UL))
#define PMIC_LDO6_ONOFF_ADDR(base) ((base) + (0x019UL))
#define PMIC_LDO7_ONOFF_ADDR(base) ((base) + (0x01AUL))
#define PMIC_LDO8_ONOFF_ECO_ADDR(base) ((base) + (0x01BUL))
#define PMIC_LDO9_ONOFF_ECO_ADDR(base) ((base) + (0x01CUL))
#define PMIC_LDO11_ONOFF_ECO_ADDR(base) ((base) + (0x01DUL))
#define PMIC_LDO12_ONOFF_ECO_ADDR(base) ((base) + (0x01EUL))
#define PMIC_LDO13_ONOFF_ADDR(base) ((base) + (0x01FUL))
#define PMIC_LDO14_ONOFF_ADDR(base) ((base) + (0x020UL))
#define PMIC_LDO15_ONOFF_ECO_ADDR(base) ((base) + (0x021UL))
#define PMIC_LDO16_ONOFF_ECO_ADDR(base) ((base) + (0x022UL))
#define PMIC_LDO17_ONOFF_ECO_ADDR(base) ((base) + (0x023UL))
#define PMIC_LDO18_ONOFF_ECO_ADDR(base) ((base) + (0x024UL))
#define PMIC_LDO19_ONOFF_ADDR(base) ((base) + (0x025UL))
#define PMIC_LDO20_ONOFF_ADDR(base) ((base) + (0x026UL))
#define PMIC_LDO21_ONOFF_ADDR(base) ((base) + (0x027UL))
#define PMIC_LDO22_ONOFF_ADDR(base) ((base) + (0x028UL))
#define PMIC_LDO23_ONOFF_ADDR(base) ((base) + (0x029UL))
#define PMIC_LDO24_ONOFF_ECO_ADDR(base) ((base) + (0x02AUL))
#define PMIC_LDO25_ONOFF_ADDR(base) ((base) + (0x02BUL))
#define PMIC_LDO26_ONOFF_ECO_ADDR(base) ((base) + (0x02CUL))
#define PMIC_LDO27_ONOFF_ADDR(base) ((base) + (0x02DUL))
#define PMIC_LDO28_ONOFF_ADDR(base) ((base) + (0x02EUL))
#define PMIC_LDO29_ONOFF_ECO_ADDR(base) ((base) + (0x02FUL))
#define PMIC_LDO30_ONOFF_ADDR(base) ((base) + (0x030UL))
#define PMIC_LDO32_ONOFF_ADDR(base) ((base) + (0x031UL))
#define PMIC_LDO33_ONOFF_ADDR(base) ((base) + (0x032UL))
#define PMIC_LDO34_ONOFF_ADDR(base) ((base) + (0x033UL))
#define PMIC_LDO35_ONOFF_ECO_ADDR(base) ((base) + (0x034UL))
#define PMIC_LDO36_ONOFF_ADDR(base) ((base) + (0x035UL))
#define PMIC_LDO_PMUA_ECO_ADDR(base) ((base) + (0x036UL))
#define PMIC_CLK_ABB_EN_ADDR(base) ((base) + (0x037UL))
#define PMIC_CLK_WIFI1_EN_ADDR(base) ((base) + (0x038UL))
#define PMIC_CLK_NFC_EN_ADDR(base) ((base) + (0x039UL))
#define PMIC_CLK_RF0_EN_ADDR(base) ((base) + (0x03AUL))
#define PMIC_CLK_RF1_EN_ADDR(base) ((base) + (0x03BUL))
#define PMIC_CLK_SYS_USB_EN_ADDR(base) ((base) + (0x03CUL))
#define PMIC_CLK_CODEC_EN_ADDR(base) ((base) + (0x03DUL))
#define PMIC_OSC32K_GPS_ONOFF_CTRL_ADDR(base) ((base) + (0x03EUL))
#define PMIC_OSC32K_BT_ONOFF_CTRL_ADDR(base) ((base) + (0x03FUL))
#define PMIC_OSC32K_SYS_ONOFF_CTRL_ADDR(base) ((base) + (0x040UL))
#define PMIC_BUCK0_VSET_ADDR(base) ((base) + (0x041UL))
#define PMIC_BUCK0_VSET_ECO_ADDR(base) ((base) + (0x042UL))
#define PMIC_BUCK1_VSET_ADDR(base) ((base) + (0x043UL))
#define PMIC_BUCK2_VSET_ADDR(base) ((base) + (0x044UL))
#define PMIC_BUCK2_VSET_ECO_ADDR(base) ((base) + (0x045UL))
#define PMIC_BUCK3_VSET_ADDR(base) ((base) + (0x046UL))
#define PMIC_BUCK3_VSET_ECO_ADDR(base) ((base) + (0x047UL))
#define PMIC_BUCK4_VSET_ADDR(base) ((base) + (0x048UL))
#define PMIC_BUCK5_VSET_ADDR(base) ((base) + (0x049UL))
#define PMIC_BUCK6_VSET_ADDR(base) ((base) + (0x04AUL))
#define PMIC_BUCK7_VSET_ADDR(base) ((base) + (0x04BUL))
#define PMIC_BUCK8_VSET_ADDR(base) ((base) + (0x04CUL))
#define PMIC_BUCK8_VSET_ECO_ADDR(base) ((base) + (0x04DUL))
#define PMIC_LDO0_2_VSET_ADDR(base) ((base) + (0x04EUL))
#define PMIC_LDO1_VSET_ADDR(base) ((base) + (0x04FUL))
#define PMIC_LDO2_VSET_ADDR(base) ((base) + (0x050UL))
#define PMIC_LDO3_VSET_ADDR(base) ((base) + (0x051UL))
#define PMIC_LDO4_VSET_ADDR(base) ((base) + (0x052UL))
#define PMIC_LDO5_VSET_ADDR(base) ((base) + (0x053UL))
#define PMIC_LDO6_VSET_ADDR(base) ((base) + (0x054UL))
#define PMIC_LDO7_VSET_ADDR(base) ((base) + (0x055UL))
#define PMIC_LDO8_VSET_ADDR(base) ((base) + (0x056UL))
#define PMIC_LDO9_VSET_ADDR(base) ((base) + (0x057UL))
#define PMIC_LDO11_VSET_ADDR(base) ((base) + (0x058UL))
#define PMIC_LDO12_VSET_ADDR(base) ((base) + (0x059UL))
#define PMIC_LDO13_VSET_ADDR(base) ((base) + (0x05AUL))
#define PMIC_LDO14_VSET_ADDR(base) ((base) + (0x05BUL))
#define PMIC_LDO15_VSET_ADDR(base) ((base) + (0x05CUL))
#define PMIC_LDO16_VSET_ADDR(base) ((base) + (0x05DUL))
#define PMIC_LDO17_VSET_ADDR(base) ((base) + (0x05EUL))
#define PMIC_LDO18_VSET_ADDR(base) ((base) + (0x05FUL))
#define PMIC_LDO19_VSET1_ADDR(base) ((base) + (0x060UL))
#define PMIC_LDO20_VSET_ADDR(base) ((base) + (0x061UL))
#define PMIC_LDO21_VSET_ADDR(base) ((base) + (0x062UL))
#define PMIC_LDO22_VSET_ADDR(base) ((base) + (0x063UL))
#define PMIC_LDO23_VSET_ADDR(base) ((base) + (0x064UL))
#define PMIC_LDO24_VSET_ADDR(base) ((base) + (0x065UL))
#define PMIC_LDO25_VSET_ADDR(base) ((base) + (0x066UL))
#define PMIC_LDO26_VSET_ADDR(base) ((base) + (0x067UL))
#define PMIC_LDO27_VSET_ADDR(base) ((base) + (0x068UL))
#define PMIC_LDO28_VSET_ADDR(base) ((base) + (0x069UL))
#define PMIC_LDO29_VSET_ADDR(base) ((base) + (0x06AUL))
#define PMIC_LDO30_VSET_ADDR(base) ((base) + (0x06BUL))
#define PMIC_LDO32_VSET_ADDR(base) ((base) + (0x06CUL))
#define PMIC_LDO33_VSET_ADDR(base) ((base) + (0x06DUL))
#define PMIC_LDO34_VSET_ADDR(base) ((base) + (0x06EUL))
#define PMIC_LDO35_VSET_ADDR(base) ((base) + (0x06FUL))
#define PMIC_LDO36_VSET_ADDR(base) ((base) + (0x070UL))
#define PMIC_LDO_BUF_VSET_ADDR(base) ((base) + (0x071UL))
#define PMIC_LDO_PMUA_VSET_ADDR(base) ((base) + (0x072UL))
#define PMIC_BUCK0_CTRL0_ADDR(base) ((base) + (0x073UL))
#define PMIC_BUCK0_CTRL1_ADDR(base) ((base) + (0x074UL))
#define PMIC_BUCK0_CTRL2_ADDR(base) ((base) + (0x075UL))
#define PMIC_BUCK0_CTRL3_ADDR(base) ((base) + (0x076UL))
#define PMIC_BUCK0_CTRL4_ADDR(base) ((base) + (0x077UL))
#define PMIC_BUCK0_CTRL5_ADDR(base) ((base) + (0x078UL))
#define PMIC_BUCK0_CTRL6_ADDR(base) ((base) + (0x079UL))
#define PMIC_BUCK0_CTRL7_ADDR(base) ((base) + (0x07AUL))
#define PMIC_BUCK0_CTRL8_ADDR(base) ((base) + (0x07BUL))
#define PMIC_BUCK1_CTRL0_ADDR(base) ((base) + (0x07CUL))
#define PMIC_BUCK1_CTRL1_ADDR(base) ((base) + (0x07DUL))
#define PMIC_BUCK1_CTRL2_ADDR(base) ((base) + (0x07EUL))
#define PMIC_BUCK1_CTRL3_ADDR(base) ((base) + (0x07FUL))
#define PMIC_BUCK1_CTRL4_ADDR(base) ((base) + (0x080UL))
#define PMIC_BUCK1_CTRL5_ADDR(base) ((base) + (0x081UL))
#define PMIC_BUCK1_CTRL6_ADDR(base) ((base) + (0x082UL))
#define PMIC_BUCK1_CTRL7_ADDR(base) ((base) + (0x083UL))
#define PMIC_BUCK1_CTRL8_ADDR(base) ((base) + (0x084UL))
#define PMIC_BUCK1_CTRL9_ADDR(base) ((base) + (0x085UL))
#define PMIC_BUCK1_CTRL10_ADDR(base) ((base) + (0x086UL))
#define PMIC_BUCK2_CTRL0_ADDR(base) ((base) + (0x087UL))
#define PMIC_BUCK2_CTRL1_ADDR(base) ((base) + (0x088UL))
#define PMIC_BUCK2_CTRL2_ADDR(base) ((base) + (0x089UL))
#define PMIC_BUCK2_CTRL3_ADDR(base) ((base) + (0x08AUL))
#define PMIC_BUCK2_CTRL4_ADDR(base) ((base) + (0x08BUL))
#define PMIC_BUCK2_CTRL5_ADDR(base) ((base) + (0x08CUL))
#define PMIC_BUCK2_CTRL6_ADDR(base) ((base) + (0x08DUL))
#define PMIC_BUCK2_CTRL7_ADDR(base) ((base) + (0x08EUL))
#define PMIC_BUCK2_CTRL8_ADDR(base) ((base) + (0x08FUL))
#define PMIC_BUCK3_CTRL0_ADDR(base) ((base) + (0x090UL))
#define PMIC_BUCK3_CTRL1_ADDR(base) ((base) + (0x091UL))
#define PMIC_BUCK3_CTRL2_ADDR(base) ((base) + (0x092UL))
#define PMIC_BUCK3_CTRL3_ADDR(base) ((base) + (0x093UL))
#define PMIC_BUCK3_CTRL4_ADDR(base) ((base) + (0x094UL))
#define PMIC_BUCK3_CTRL5_ADDR(base) ((base) + (0x095UL))
#define PMIC_BUCK3_CTRL6_ADDR(base) ((base) + (0x096UL))
#define PMIC_BUCK3_CTRL7_ADDR(base) ((base) + (0x097UL))
#define PMIC_BUCK3_CTRL8_ADDR(base) ((base) + (0x098UL))
#define PMIC_BUCK4_CTRL0_ADDR(base) ((base) + (0x099UL))
#define PMIC_BUCK4_CTRL1_ADDR(base) ((base) + (0x09AUL))
#define PMIC_BUCK4_CTRL2_ADDR(base) ((base) + (0x09BUL))
#define PMIC_BUCK4_CTRL3_ADDR(base) ((base) + (0x09CUL))
#define PMIC_BUCK4_CTRL4_ADDR(base) ((base) + (0x09DUL))
#define PMIC_BUCK4_CTRL5_ADDR(base) ((base) + (0x09EUL))
#define PMIC_BUCK4_CTRL6_ADDR(base) ((base) + (0x09FUL))
#define PMIC_BUCK4_CTRL7_ADDR(base) ((base) + (0x0A0UL))
#define PMIC_BUCK4_CTRL8_ADDR(base) ((base) + (0x0A1UL))
#define PMIC_BUCK5_CTRL0_ADDR(base) ((base) + (0x0A2UL))
#define PMIC_BUCK5_CTRL1_ADDR(base) ((base) + (0x0A3UL))
#define PMIC_BUCK5_CTRL2_ADDR(base) ((base) + (0x0A4UL))
#define PMIC_BUCK5_CTRL3_ADDR(base) ((base) + (0x0A5UL))
#define PMIC_BUCK5_CTRL4_ADDR(base) ((base) + (0x0A6UL))
#define PMIC_BUCK5_CTRL5_ADDR(base) ((base) + (0x0A7UL))
#define PMIC_BUCK5_CTRL6_ADDR(base) ((base) + (0x0A8UL))
#define PMIC_BUCK5_CTRL7_ADDR(base) ((base) + (0x0A9UL))
#define PMIC_BUCK5_CTRL8_ADDR(base) ((base) + (0x0AAUL))
#define PMIC_BUCK6_CTRL0_ADDR(base) ((base) + (0x0ABUL))
#define PMIC_BUCK6_CTRL1_ADDR(base) ((base) + (0x0ACUL))
#define PMIC_BUCK6_CTRL2_ADDR(base) ((base) + (0x0ADUL))
#define PMIC_BUCK6_CTRL3_ADDR(base) ((base) + (0x0AEUL))
#define PMIC_BUCK6_CTRL4_ADDR(base) ((base) + (0x0AFUL))
#define PMIC_BUCK6_CTRL5_ADDR(base) ((base) + (0x0B0UL))
#define PMIC_BUCK6_CTRL6_ADDR(base) ((base) + (0x0B1UL))
#define PMIC_BUCK6_CTRL7_ADDR(base) ((base) + (0x0B2UL))
#define PMIC_BUCK6_CTRL8_ADDR(base) ((base) + (0x0B3UL))
#define PMIC_BUCK7_CTRL0_ADDR(base) ((base) + (0x0B4UL))
#define PMIC_BUCK7_CTRL1_ADDR(base) ((base) + (0x0B5UL))
#define PMIC_BUCK7_CTRL2_ADDR(base) ((base) + (0x0B6UL))
#define PMIC_BUCK7_CTRL3_ADDR(base) ((base) + (0x0B7UL))
#define PMIC_BUCK7_CTRL4_ADDR(base) ((base) + (0x0B8UL))
#define PMIC_BUCK7_CTRL5_ADDR(base) ((base) + (0x0B9UL))
#define PMIC_BUCK7_CTRL6_ADDR(base) ((base) + (0x0BAUL))
#define PMIC_BUCK7_CTRL7_ADDR(base) ((base) + (0x0BBUL))
#define PMIC_BUCK7_CTRL8_ADDR(base) ((base) + (0x0BCUL))
#define PMIC_BUCK7_CTRL9_ADDR(base) ((base) + (0x0BDUL))
#define PMIC_BUCK7_CTRL10_ADDR(base) ((base) + (0x0BEUL))
#define PMIC_BUCK8_CTRL0_ADDR(base) ((base) + (0x0BFUL))
#define PMIC_BUCK8_CTRL1_ADDR(base) ((base) + (0x0C0UL))
#define PMIC_BUCK8_CTRL2_ADDR(base) ((base) + (0x0C1UL))
#define PMIC_BUCK8_CTRL3_ADDR(base) ((base) + (0x0C2UL))
#define PMIC_BUCK8_CTRL4_ADDR(base) ((base) + (0x0C3UL))
#define PMIC_BUCK8_CTRL5_ADDR(base) ((base) + (0x0C4UL))
#define PMIC_BUCK8_CTRL6_ADDR(base) ((base) + (0x0C5UL))
#define PMIC_BUCK8_CTRL7_ADDR(base) ((base) + (0x0C6UL))
#define PMIC_BUCK8_CTRL8_ADDR(base) ((base) + (0x0C7UL))
#define PMIC_BUCK_RESERVE0_ADDR(base) ((base) + (0x0C8UL))
#define PMIC_BUCK_RESERVE1_ADDR(base) ((base) + (0x0C9UL))
#define PMIC_LDO_1_CTRL_ADDR(base) ((base) + (0x0CAUL))
#define PMIC_LDO1_CTRL_0_ADDR(base) ((base) + (0x0CBUL))
#define PMIC_LDO1_CTRL_1_ADDR(base) ((base) + (0x0CCUL))
#define PMIC_LDO2_3_CTRL_ADDR(base) ((base) + (0x0CDUL))
#define PMIC_LDO3_CTRL_ADDR(base) ((base) + (0x0CEUL))
#define PMIC_LDO4_CTRL_ADDR(base) ((base) + (0x0CFUL))
#define PMIC_LDO4_5_CTRL_ADDR(base) ((base) + (0x0D0UL))
#define PMIC_LDO6_CTRL_ADDR(base) ((base) + (0x0D1UL))
#define PMIC_LDO7_8_CTRL_ADDR(base) ((base) + (0x0D2UL))
#define PMIC_LDO8_CTRL_ADDR(base) ((base) + (0x0D3UL))
#define PMIC_LDO9_CTRL_ADDR(base) ((base) + (0x0D4UL))
#define PMIC_LD11_12_CTRL_ADDR(base) ((base) + (0x0D5UL))
#define PMIC_LDO13_CTRL_ADDR(base) ((base) + (0x0D6UL))
#define PMIC_LDO13_14_CTRL_ADDR(base) ((base) + (0x0D7UL))
#define PMIC_LDO15_16_CTRL_ADDR(base) ((base) + (0x0D8UL))
#define PMIC_LDO17_CTRL_ADDR(base) ((base) + (0x0D9UL))
#define PMIC_LDO18_CTRL0_ADDR(base) ((base) + (0x0DAUL))
#define PMIC_LDO18_CTRL1_ADDR(base) ((base) + (0x0DBUL))
#define PMIC_LDO_19_CTRL1_ADDR(base) ((base) + (0x0DCUL))
#define PMIC_LDO_19_CTRL2_ADDR(base) ((base) + (0x0DDUL))
#define PMIC_LDO_19_CTRL3_ADDR(base) ((base) + (0x0DEUL))
#define PMIC_LDO20_CTRL1_ADDR(base) ((base) + (0x0DFUL))
#define PMIC_LDO20_CTRL2_ADDR(base) ((base) + (0x0E0UL))
#define PMIC_LDO20_CTRL3_ADDR(base) ((base) + (0x0E1UL))
#define PMIC_LDO21_CTRL0_ADDR(base) ((base) + (0x0E2UL))
#define PMIC_LDO21_CTRL1_ADDR(base) ((base) + (0x0E3UL))
#define PMIC_LDO22_CTRL0_ADDR(base) ((base) + (0x0E4UL))
#define PMIC_LDO22_CTRL1_ADDR(base) ((base) + (0x0E5UL))
#define PMIC_LDO22_CTRL2_ADDR(base) ((base) + (0x0E6UL))
#define PMIC_LDO23_CTRL_ADDR(base) ((base) + (0x0E7UL))
#define PMIC_LDO24_25_CTRL_ADDR(base) ((base) + (0x0E8UL))
#define PMIC_LDO26_CTRL_ADDR(base) ((base) + (0x0E9UL))
#define PMIC_LDO27_CTRL_ADDR(base) ((base) + (0x0EAUL))
#define PMIC_LDO28_29_CTRL_ADDR(base) ((base) + (0x0EBUL))
#define PMIC_LDO30_CTRL_ADDR(base) ((base) + (0x0ECUL))
#define PMIC_LDO32_CTRL1_ADDR(base) ((base) + (0x0EDUL))
#define PMIC_LDO32_CTRL2_ADDR(base) ((base) + (0x0EEUL))
#define PMIC_LDO32_CTRL3_ADDR(base) ((base) + (0x0EFUL))
#define PMIC_LDO33_CTRL_ADDR(base) ((base) + (0x0F0UL))
#define PMIC_LDO34_35_CTRL_ADDR(base) ((base) + (0x0F1UL))
#define PMIC_LDO36_CTRL_ADDR(base) ((base) + (0x0F2UL))
#define PMIC_LDO_BUF_CTRL_ADDR(base) ((base) + (0x0F3UL))
#define PMIC_LDO_RESERVE0_ADDR(base) ((base) + (0x0F4UL))
#define PMIC_LDO_RESERVE1_ADDR(base) ((base) + (0x0F5UL))
#define PMIC_BUCK0_3_OCP_CTRL_ADDR(base) ((base) + (0x0F6UL))
#define PMIC_BUCK4_7_OCP_CTRL_ADDR(base) ((base) + (0x0F7UL))
#define PMIC_BUCK8_OCP_CTRL_ADDR(base) ((base) + (0x0F8UL))
#define PMIC_LDO0_3_OCP_CTRL_ADDR(base) ((base) + (0x0F9UL))
#define PMIC_LDO4_7_OCP_CTRL_ADDR(base) ((base) + (0x0FAUL))
#define PMIC_LDO8_12_OCP_CTRL_ADDR(base) ((base) + (0x0FBUL))
#define PMIC_LDO13_16_OCP_CTRL_ADDR(base) ((base) + (0x0FCUL))
#define PMIC_LDO17_20_OCP_CTRL_ADDR(base) ((base) + (0x0FDUL))
#define PMIC_LDO21_24_OCP_CTRL_ADDR(base) ((base) + (0x0FEUL))
#define PMIC_LDO25_28_OCP_CTRL_ADDR(base) ((base) + (0x0FFUL))
#define PMIC_LDO29_33_OCP_CTRL_ADDR(base) ((base) + (0x100UL))
#define PMIC_LDO34_36_OCP_CTRL_ADDR(base) ((base) + (0x101UL))
#define PMIC_LDO_BUFF_SCP_CTRL_ADDR(base) ((base) + (0x102UL))
#define PMIC_BUCK0_3_SCP_CTRL_ADDR(base) ((base) + (0x103UL))
#define PMIC_BUCK4_7_SCP_CTRL_ADDR(base) ((base) + (0x104UL))
#define PMIC_BUCK8_SCP_CTRL_ADDR(base) ((base) + (0x105UL))
#define PMIC_SYS_CTRL_RESERVE_ADDR(base) ((base) + (0x106UL))
#define PMIC_OCP_DEB_CTRL0_ADDR(base) ((base) + (0x107UL))
#define PMIC_OCP_DEB_CTRL1_ADDR(base) ((base) + (0x108UL))
#define PMIC_PWROFF_DEB_CTRL_ADDR(base) ((base) + (0x109UL))
#define PMIC_OCP_SCP_ONOFF_ADDR(base) ((base) + (0x10AUL))
#define PMIC_CLK_ABB_CTRL0_ADDR(base) ((base) + (0x10BUL))
#define PMIC_CLK_WIFI_CTRL0_ADDR(base) ((base) + (0x10CUL))
#define PMIC_CLK_NFC_CTRL0_ADDR(base) ((base) + (0x10DUL))
#define PMIC_CLK_RF0_CTRL0_ADDR(base) ((base) + (0x10EUL))
#define PMIC_CLK_RF1_CTRL0_ADDR(base) ((base) + (0x10FUL))
#define PMIC_CLK_SYS_USB_CTRL_ADDR(base) ((base) + (0x110UL))
#define PMIC_CLK_USB_CTRL_ADDR(base) ((base) + (0x111UL))
#define PMIC_CLK_CODEC_CTRL_ADDR(base) ((base) + (0x112UL))
#define PMIC_CLK_TOP_CTRL0_ADDR(base) ((base) + (0x113UL))
#define PMIC_CLK_TOP_CTRL1_ADDR(base) ((base) + (0x114UL))
#define PMIC_CLK_TOP_CTRL2_ADDR(base) ((base) + (0x115UL))
#define PMIC_BG_THSD_CTRL0_ADDR(base) ((base) + (0x116UL))
#define PMIC_BG_THSD_CTRL1_ADDR(base) ((base) + (0x117UL))
#define PMIC_BG_TEST_ADDR(base) ((base) + (0x118UL))
#define PMIC_HARDWIRE_CTRL0_ADDR(base) ((base) + (0x119UL))
#define PMIC_HARDWIRE_CTRL1_ADDR(base) ((base) + (0x11AUL))
#define PMIC_HARDWIRE_CTRL2_ADDR(base) ((base) + (0x11BUL))
#define PMIC_PERI_CTRL0_ADDR(base) ((base) + (0x11CUL))
#define PMIC_PERI_CTRL1_ADDR(base) ((base) + (0x11DUL))
#define PMIC_PERI_TIME__CTRL_ADDR(base) ((base) + (0x11EUL))
#define PMIC_PERI_CTRL2_ADDR(base) ((base) + (0x11FUL))
#define PMIC_PERI_CTRL3_ADDR(base) ((base) + (0x120UL))
#define PMIC_PERI_CTRL4_ADDR(base) ((base) + (0x121UL))
#define PMIC_PERI_VSET_CTRL_ADDR(base) ((base) + (0x122UL))
#define PMIC_COUL_ECO_MASK_ADDR(base) ((base) + (0x123UL))
#define PMIC_PMU_SOFT_RST_ADDR(base) ((base) + (0x124UL))
#define PMIC_LOCK_ADDR(base) ((base) + (0x125UL))
#define PMIC_DR_EN_MODE_ADDR(base) ((base) + (0x126UL))
#define PMIC_DR_EN_MODE_12_ADDR(base) ((base) + (0x127UL))
#define PMIC_FLASH_PERIOD_DR1_ADDR(base) ((base) + (0x128UL))
#define PMIC_FLASH_ON_DR1_ADDR(base) ((base) + (0x129UL))
#define PMIC_FLASH_PERIOD_DR2_ADDR(base) ((base) + (0x12AUL))
#define PMIC_FLASH_ON_DR2_ADDR(base) ((base) + (0x12BUL))
#define PMIC_FLASH_PERIOD_DR3_ADDR(base) ((base) + (0x12CUL))
#define PMIC_FLASH_ON_DR3_ADDR(base) ((base) + (0x12DUL))
#define PMIC_DR_MODE_SEL_ADDR(base) ((base) + (0x12EUL))
#define PMIC_DR_BRE_CTRL_ADDR(base) ((base) + (0x12FUL))
#define PMIC_DR1_ISET_ADDR(base) ((base) + (0x130UL))
#define PMIC_DR2_ISET_ADDR(base) ((base) + (0x131UL))
#define PMIC_DR3_ISET_ADDR(base) ((base) + (0x132UL))
#define PMIC_DR_OUT_CTRL_ADDR(base) ((base) + (0x133UL))
#define PMIC_DR1_START_DEL_ADDR(base) ((base) + (0x134UL))
#define PMIC_DR2_START_DEL_ADDR(base) ((base) + (0x135UL))
#define PMIC_DR3_START_DEL_ADDR(base) ((base) + (0x136UL))
#define PMIC_DR1_TIM_CONF0_ADDR(base) ((base) + (0x137UL))
#define PMIC_DR1_TIM_CONF1_ADDR(base) ((base) + (0x138UL))
#define PMIC_DR2_TIM_CONF0_ADDR(base) ((base) + (0x139UL))
#define PMIC_DR2_TIM_CONF1_ADDR(base) ((base) + (0x13AUL))
#define PMIC_DR3_TIM_CONF0_ADDR(base) ((base) + (0x13BUL))
#define PMIC_DR3_TIM_CONF1_ADDR(base) ((base) + (0x13CUL))
#define PMIC_DR_CTRLRESERVE8_ADDR(base) ((base) + (0x13DUL))
#define PMIC_DR_CTRLRESERVE9_ADDR(base) ((base) + (0x13EUL))
#define PMIC_OTP_0_ADDR(base) ((base) + (0x13FUL))
#define PMIC_OTP_1_ADDR(base) ((base) + (0x140UL))
#define PMIC_OTP_CTRL0_ADDR(base) ((base) + (0x141UL))
#define PMIC_OTP_CTRL1_ADDR(base) ((base) + (0x142UL))
#define PMIC_OTP_CTRL2_ADDR(base) ((base) + (0x143UL))
#define PMIC_OTP_WDATA_ADDR(base) ((base) + (0x144UL))
#define PMIC_OTP_0_W_ADDR(base) ((base) + (0x145UL))
#define PMIC_OTP_1_W_ADDR(base) ((base) + (0x146UL))
#define PMIC_OTP_2_W_ADDR(base) ((base) + (0x147UL))
#define PMIC_OTP_3_W_ADDR(base) ((base) + (0x148UL))
#define PMIC_OTP_4_W_ADDR(base) ((base) + (0x149UL))
#define PMIC_OTP_5_W_ADDR(base) ((base) + (0x14AUL))
#define PMIC_OTP_6_W_ADDR(base) ((base) + (0x14BUL))
#define PMIC_OTP_7_W_ADDR(base) ((base) + (0x14CUL))
#define PMIC_OTP_8_W_ADDR(base) ((base) + (0x14DUL))
#define PMIC_OTP_9_W_ADDR(base) ((base) + (0x14EUL))
#define PMIC_OTP_10_W_ADDR(base) ((base) + (0x14FUL))
#define PMIC_OTP_11_W_ADDR(base) ((base) + (0x150UL))
#define PMIC_OTP_12_W_ADDR(base) ((base) + (0x151UL))
#define PMIC_OTP_13_W_ADDR(base) ((base) + (0x152UL))
#define PMIC_OTP_14_W_ADDR(base) ((base) + (0x153UL))
#define PMIC_OTP_15_W_ADDR(base) ((base) + (0x154UL))
#define PMIC_OTP_16_W_ADDR(base) ((base) + (0x155UL))
#define PMIC_OTP_17_W_ADDR(base) ((base) + (0x156UL))
#define PMIC_OTP_18_W_ADDR(base) ((base) + (0x157UL))
#define PMIC_OTP_19_W_ADDR(base) ((base) + (0x158UL))
#define PMIC_OTP_20_W_ADDR(base) ((base) + (0x159UL))
#define PMIC_OTP_21_W_ADDR(base) ((base) + (0x15AUL))
#define PMIC_OTP_22_W_ADDR(base) ((base) + (0x15BUL))
#define PMIC_OTP_23_W_ADDR(base) ((base) + (0x15CUL))
#define PMIC_OTP_24_W_ADDR(base) ((base) + (0x15DUL))
#define PMIC_OTP_25_W_ADDR(base) ((base) + (0x15EUL))
#define PMIC_OTP_26_W_ADDR(base) ((base) + (0x15FUL))
#define PMIC_OTP_27_W_ADDR(base) ((base) + (0x160UL))
#define PMIC_OTP_28_W_ADDR(base) ((base) + (0x161UL))
#define PMIC_OTP_29_W_ADDR(base) ((base) + (0x162UL))
#define PMIC_OTP_30_W_ADDR(base) ((base) + (0x163UL))
#define PMIC_OTP_31_W_ADDR(base) ((base) + (0x164UL))
#define PMIC_D2A_RES0_ADDR(base) ((base) + (0x165UL))
#define PMIC_D2A_RES1_ADDR(base) ((base) + (0x166UL))
#define PMIC_A2D_RES0_ADDR(base) ((base) + (0x167UL))
#define PMIC_A2D_RES1_ADDR(base) ((base) + (0x168UL))
#define PMIC_SIM_CTRL0_ADDR(base) ((base) + (0x169UL))
#define PMIC_SIM_CTRL1_ADDR(base) ((base) + (0x16AUL))
#define PMIC_SIM_DEB_CTRL1_ADDR(base) ((base) + (0x16BUL))
#define PMIC_SIM_DEB_CTRL2_ADDR(base) ((base) + (0x16CUL))
#define PMIC_GPIO0DATA_ADDR(base) ((base) + (0x16DUL))
#define PMIC_GPIO0_DATA_RESERVE_ADDR(base) ((base) + (0x16EUL))
#define PMIC_GPIO0DIR_ADDR(base) ((base) + (0x16FUL))
#define PMIC_GPIO0_DIR_RESERVE_ADDR(base) ((base) + (0x170UL))
#define PMIC_GPIO0IS_ADDR(base) ((base) + (0x171UL))
#define PMIC_GPIO0IBE_ADDR(base) ((base) + (0x172UL))
#define PMIC_GPIO0IEV_ADDR(base) ((base) + (0x173UL))
#define PMIC_GPIO0AFSEL_ADDR(base) ((base) + (0x174UL))
#define PMIC_GPIO0DSSEL_ADDR(base) ((base) + (0x175UL))
#define PMIC_GPIO0PUSEL_ADDR(base) ((base) + (0x176UL))
#define PMIC_GPIO0PDSEL_ADDR(base) ((base) + (0x177UL))
#define PMIC_GPIO0DEBSEL_ADDR(base) ((base) + (0x178UL))
#define PMIC_GPIO1DATA_ADDR(base) ((base) + (0x179UL))
#define PMIC_GPIO1_DATA_RESERVE_ADDR(base) ((base) + (0x17AUL))
#define PMIC_GPIO1DIR_ADDR(base) ((base) + (0x17BUL))
#define PMIC_GPIO1_DIR_RESERVE_ADDR(base) ((base) + (0x17CUL))
#define PMIC_GPIO1IS_ADDR(base) ((base) + (0x17DUL))
#define PMIC_GPIO1IBE_ADDR(base) ((base) + (0x17EUL))
#define PMIC_GPIO1IEV_ADDR(base) ((base) + (0x17FUL))
#define PMIC_GPIO1AFSEL_ADDR(base) ((base) + (0x180UL))
#define PMIC_GPIO1DSSEL_ADDR(base) ((base) + (0x181UL))
#define PMIC_GPIO1PUSEL_ADDR(base) ((base) + (0x182UL))
#define PMIC_GPIO1PDSEL_ADDR(base) ((base) + (0x183UL))
#define PMIC_GPIO1DEBSEL_ADDR(base) ((base) + (0x184UL))
#define PMIC_GPIO2DATA_ADDR(base) ((base) + (0x185UL))
#define PMIC_GPIO2_DATA_RESERVE_ADDR(base) ((base) + (0x186UL))
#define PMIC_GPIO2DIR_ADDR(base) ((base) + (0x187UL))
#define PMIC_GPIO2_DIR_RESERVE_ADDR(base) ((base) + (0x188UL))
#define PMIC_GPIO2IS_ADDR(base) ((base) + (0x189UL))
#define PMIC_GPIO2IBE_ADDR(base) ((base) + (0x18AUL))
#define PMIC_GPIO2IEV_ADDR(base) ((base) + (0x18BUL))
#define PMIC_GPIO2AFSEL_ADDR(base) ((base) + (0x18CUL))
#define PMIC_GPIO2DSSEL_ADDR(base) ((base) + (0x18DUL))
#define PMIC_GPIO2PUSEL_ADDR(base) ((base) + (0x18EUL))
#define PMIC_GPIO2PDSEL_ADDR(base) ((base) + (0x18FUL))
#define PMIC_GPIO2DEBSEL_ADDR(base) ((base) + (0x190UL))
#define PMIC_AUX0_IBIAS_CFG_ADDR(base) ((base) + (0x191UL))
#define PMIC_AUX1_IBIAS_CFG_ADDR(base) ((base) + (0x192UL))
#define PMIC_DAC0_DIN_MSB_ADDR(base) ((base) + (0x193UL))
#define PMIC_DAC0_DIN_LSB_ADDR(base) ((base) + (0x194UL))
#define PMIC_DAC1_DIN_MSB_ADDR(base) ((base) + (0x195UL))
#define PMIC_DAC1_DIN_LSB_ADDR(base) ((base) + (0x196UL))
#define PMIC_RAMP_BUCK0_CTRL0_ADDR(base) ((base) + (0x197UL))
#define PMIC_RAMP_BUCK0_CTRL1_ADDR(base) ((base) + (0x198UL))
#define PMIC_RAMP_BUCK4_CTRL0_ADDR(base) ((base) + (0x199UL))
#define PMIC_RAMP_BUCK5_CTRL0_ADDR(base) ((base) + (0x19AUL))
#define PMIC_RAMP_BUCK6_CTRL0_ADDR(base) ((base) + (0x19BUL))
#define PMIC_SPMI_ECO_GT_BYPASS_ADDR(base) ((base) + (0x19CUL))
#define PMIC_PWRONN_8S_XOADC_DEBUG_CTRL_ADDR(base) ((base) + (0x19DUL))
#define PMIC_D2A_RES2_ADDR(base) ((base) + (0x19EUL))
#define PMIC_D2A_RES3_ADDR(base) ((base) + (0x19FUL))
#else
#define PMIC_VERSION0_ADDR(base) ((base) + (0x000))
#define PMIC_VERSION1_ADDR(base) ((base) + (0x001))
#define PMIC_VERSION2_ADDR(base) ((base) + (0x002))
#define PMIC_VERSION3_ADDR(base) ((base) + (0x003))
#define PMIC_VERSION4_ADDR(base) ((base) + (0x004))
#define PMIC_VERSION5_ADDR(base) ((base) + (0x005))
#define PMIC_STATUS0_ADDR(base) ((base) + (0x006))
#define PMIC_STATUS1_ADDR(base) ((base) + (0x007))
#define PMIC_BUCK0_ONOFF_ECO_ADDR(base) ((base) + (0x008))
#define PMIC_BUCK1_ONOFF_ECO_ADDR(base) ((base) + (0x009))
#define PMIC_BUCK2_ONOFF_ECO_ADDR(base) ((base) + (0x00A))
#define PMIC_BUCK3_ONOFF_ECO_ADDR(base) ((base) + (0x00B))
#define PMIC_BUCK4_ONOFF_ECO_ADDR(base) ((base) + (0x00C))
#define PMIC_BUCK5_ONOFF_ECO_ADDR(base) ((base) + (0x00D))
#define PMIC_BUCK6_ONOFF_ECO_ADDR(base) ((base) + (0x00E))
#define PMIC_BUCK7_ONOFF_ECO_ADDR(base) ((base) + (0x00F))
#define PMIC_BUCK8_ONOFF_ECO_ADDR(base) ((base) + (0x010))
#define PMIC_LDO0_1_ONOFF_ADDR(base) ((base) + (0x011))
#define PMIC_LDO0_2_ONOFF_ECO_ADDR(base) ((base) + (0x012))
#define PMIC_LDO1_ONOFF_ADDR(base) ((base) + (0x013))
#define PMIC_LDO2_ONOFF1_ADDR(base) ((base) + (0x014))
#define PMIC_LDO2_ONOFF2_ADDR(base) ((base) + (0x015))
#define PMIC_LDO3_ONOFF_ADDR(base) ((base) + (0x016))
#define PMIC_LDO4_ONOFF_ECO_ADDR(base) ((base) + (0x017))
#define PMIC_LDO5_ONOFF_ADDR(base) ((base) + (0x018))
#define PMIC_LDO6_ONOFF_ADDR(base) ((base) + (0x019))
#define PMIC_LDO7_ONOFF_ADDR(base) ((base) + (0x01A))
#define PMIC_LDO8_ONOFF_ECO_ADDR(base) ((base) + (0x01B))
#define PMIC_LDO9_ONOFF_ECO_ADDR(base) ((base) + (0x01C))
#define PMIC_LDO11_ONOFF_ECO_ADDR(base) ((base) + (0x01D))
#define PMIC_LDO12_ONOFF_ECO_ADDR(base) ((base) + (0x01E))
#define PMIC_LDO13_ONOFF_ADDR(base) ((base) + (0x01F))
#define PMIC_LDO14_ONOFF_ADDR(base) ((base) + (0x020))
#define PMIC_LDO15_ONOFF_ECO_ADDR(base) ((base) + (0x021))
#define PMIC_LDO16_ONOFF_ECO_ADDR(base) ((base) + (0x022))
#define PMIC_LDO17_ONOFF_ECO_ADDR(base) ((base) + (0x023))
#define PMIC_LDO18_ONOFF_ECO_ADDR(base) ((base) + (0x024))
#define PMIC_LDO19_ONOFF_ADDR(base) ((base) + (0x025))
#define PMIC_LDO20_ONOFF_ADDR(base) ((base) + (0x026))
#define PMIC_LDO21_ONOFF_ADDR(base) ((base) + (0x027))
#define PMIC_LDO22_ONOFF_ADDR(base) ((base) + (0x028))
#define PMIC_LDO23_ONOFF_ADDR(base) ((base) + (0x029))
#define PMIC_LDO24_ONOFF_ECO_ADDR(base) ((base) + (0x02A))
#define PMIC_LDO25_ONOFF_ADDR(base) ((base) + (0x02B))
#define PMIC_LDO26_ONOFF_ECO_ADDR(base) ((base) + (0x02C))
#define PMIC_LDO27_ONOFF_ADDR(base) ((base) + (0x02D))
#define PMIC_LDO28_ONOFF_ADDR(base) ((base) + (0x02E))
#define PMIC_LDO29_ONOFF_ECO_ADDR(base) ((base) + (0x02F))
#define PMIC_LDO30_ONOFF_ADDR(base) ((base) + (0x030))
#define PMIC_LDO32_ONOFF_ADDR(base) ((base) + (0x031))
#define PMIC_LDO33_ONOFF_ADDR(base) ((base) + (0x032))
#define PMIC_LDO34_ONOFF_ADDR(base) ((base) + (0x033))
#define PMIC_LDO35_ONOFF_ECO_ADDR(base) ((base) + (0x034))
#define PMIC_LDO36_ONOFF_ADDR(base) ((base) + (0x035))
#define PMIC_LDO_PMUA_ECO_ADDR(base) ((base) + (0x036))
#define PMIC_CLK_ABB_EN_ADDR(base) ((base) + (0x037))
#define PMIC_CLK_WIFI1_EN_ADDR(base) ((base) + (0x038))
#define PMIC_CLK_NFC_EN_ADDR(base) ((base) + (0x039))
#define PMIC_CLK_RF0_EN_ADDR(base) ((base) + (0x03A))
#define PMIC_CLK_RF1_EN_ADDR(base) ((base) + (0x03B))
#define PMIC_CLK_SYS_USB_EN_ADDR(base) ((base) + (0x03C))
#define PMIC_CLK_CODEC_EN_ADDR(base) ((base) + (0x03D))
#define PMIC_OSC32K_GPS_ONOFF_CTRL_ADDR(base) ((base) + (0x03E))
#define PMIC_OSC32K_BT_ONOFF_CTRL_ADDR(base) ((base) + (0x03F))
#define PMIC_OSC32K_SYS_ONOFF_CTRL_ADDR(base) ((base) + (0x040))
#define PMIC_BUCK0_VSET_ADDR(base) ((base) + (0x041))
#define PMIC_BUCK0_VSET_ECO_ADDR(base) ((base) + (0x042))
#define PMIC_BUCK1_VSET_ADDR(base) ((base) + (0x043))
#define PMIC_BUCK2_VSET_ADDR(base) ((base) + (0x044))
#define PMIC_BUCK2_VSET_ECO_ADDR(base) ((base) + (0x045))
#define PMIC_BUCK3_VSET_ADDR(base) ((base) + (0x046))
#define PMIC_BUCK3_VSET_ECO_ADDR(base) ((base) + (0x047))
#define PMIC_BUCK4_VSET_ADDR(base) ((base) + (0x048))
#define PMIC_BUCK5_VSET_ADDR(base) ((base) + (0x049))
#define PMIC_BUCK6_VSET_ADDR(base) ((base) + (0x04A))
#define PMIC_BUCK7_VSET_ADDR(base) ((base) + (0x04B))
#define PMIC_BUCK8_VSET_ADDR(base) ((base) + (0x04C))
#define PMIC_BUCK8_VSET_ECO_ADDR(base) ((base) + (0x04D))
#define PMIC_LDO0_2_VSET_ADDR(base) ((base) + (0x04E))
#define PMIC_LDO1_VSET_ADDR(base) ((base) + (0x04F))
#define PMIC_LDO2_VSET_ADDR(base) ((base) + (0x050))
#define PMIC_LDO3_VSET_ADDR(base) ((base) + (0x051))
#define PMIC_LDO4_VSET_ADDR(base) ((base) + (0x052))
#define PMIC_LDO5_VSET_ADDR(base) ((base) + (0x053))
#define PMIC_LDO6_VSET_ADDR(base) ((base) + (0x054))
#define PMIC_LDO7_VSET_ADDR(base) ((base) + (0x055))
#define PMIC_LDO8_VSET_ADDR(base) ((base) + (0x056))
#define PMIC_LDO9_VSET_ADDR(base) ((base) + (0x057))
#define PMIC_LDO11_VSET_ADDR(base) ((base) + (0x058))
#define PMIC_LDO12_VSET_ADDR(base) ((base) + (0x059))
#define PMIC_LDO13_VSET_ADDR(base) ((base) + (0x05A))
#define PMIC_LDO14_VSET_ADDR(base) ((base) + (0x05B))
#define PMIC_LDO15_VSET_ADDR(base) ((base) + (0x05C))
#define PMIC_LDO16_VSET_ADDR(base) ((base) + (0x05D))
#define PMIC_LDO17_VSET_ADDR(base) ((base) + (0x05E))
#define PMIC_LDO18_VSET_ADDR(base) ((base) + (0x05F))
#define PMIC_LDO19_VSET1_ADDR(base) ((base) + (0x060))
#define PMIC_LDO20_VSET_ADDR(base) ((base) + (0x061))
#define PMIC_LDO21_VSET_ADDR(base) ((base) + (0x062))
#define PMIC_LDO22_VSET_ADDR(base) ((base) + (0x063))
#define PMIC_LDO23_VSET_ADDR(base) ((base) + (0x064))
#define PMIC_LDO24_VSET_ADDR(base) ((base) + (0x065))
#define PMIC_LDO25_VSET_ADDR(base) ((base) + (0x066))
#define PMIC_LDO26_VSET_ADDR(base) ((base) + (0x067))
#define PMIC_LDO27_VSET_ADDR(base) ((base) + (0x068))
#define PMIC_LDO28_VSET_ADDR(base) ((base) + (0x069))
#define PMIC_LDO29_VSET_ADDR(base) ((base) + (0x06A))
#define PMIC_LDO30_VSET_ADDR(base) ((base) + (0x06B))
#define PMIC_LDO32_VSET_ADDR(base) ((base) + (0x06C))
#define PMIC_LDO33_VSET_ADDR(base) ((base) + (0x06D))
#define PMIC_LDO34_VSET_ADDR(base) ((base) + (0x06E))
#define PMIC_LDO35_VSET_ADDR(base) ((base) + (0x06F))
#define PMIC_LDO36_VSET_ADDR(base) ((base) + (0x070))
#define PMIC_LDO_BUF_VSET_ADDR(base) ((base) + (0x071))
#define PMIC_LDO_PMUA_VSET_ADDR(base) ((base) + (0x072))
#define PMIC_BUCK0_CTRL0_ADDR(base) ((base) + (0x073))
#define PMIC_BUCK0_CTRL1_ADDR(base) ((base) + (0x074))
#define PMIC_BUCK0_CTRL2_ADDR(base) ((base) + (0x075))
#define PMIC_BUCK0_CTRL3_ADDR(base) ((base) + (0x076))
#define PMIC_BUCK0_CTRL4_ADDR(base) ((base) + (0x077))
#define PMIC_BUCK0_CTRL5_ADDR(base) ((base) + (0x078))
#define PMIC_BUCK0_CTRL6_ADDR(base) ((base) + (0x079))
#define PMIC_BUCK0_CTRL7_ADDR(base) ((base) + (0x07A))
#define PMIC_BUCK0_CTRL8_ADDR(base) ((base) + (0x07B))
#define PMIC_BUCK1_CTRL0_ADDR(base) ((base) + (0x07C))
#define PMIC_BUCK1_CTRL1_ADDR(base) ((base) + (0x07D))
#define PMIC_BUCK1_CTRL2_ADDR(base) ((base) + (0x07E))
#define PMIC_BUCK1_CTRL3_ADDR(base) ((base) + (0x07F))
#define PMIC_BUCK1_CTRL4_ADDR(base) ((base) + (0x080))
#define PMIC_BUCK1_CTRL5_ADDR(base) ((base) + (0x081))
#define PMIC_BUCK1_CTRL6_ADDR(base) ((base) + (0x082))
#define PMIC_BUCK1_CTRL7_ADDR(base) ((base) + (0x083))
#define PMIC_BUCK1_CTRL8_ADDR(base) ((base) + (0x084))
#define PMIC_BUCK1_CTRL9_ADDR(base) ((base) + (0x085))
#define PMIC_BUCK1_CTRL10_ADDR(base) ((base) + (0x086))
#define PMIC_BUCK2_CTRL0_ADDR(base) ((base) + (0x087))
#define PMIC_BUCK2_CTRL1_ADDR(base) ((base) + (0x088))
#define PMIC_BUCK2_CTRL2_ADDR(base) ((base) + (0x089))
#define PMIC_BUCK2_CTRL3_ADDR(base) ((base) + (0x08A))
#define PMIC_BUCK2_CTRL4_ADDR(base) ((base) + (0x08B))
#define PMIC_BUCK2_CTRL5_ADDR(base) ((base) + (0x08C))
#define PMIC_BUCK2_CTRL6_ADDR(base) ((base) + (0x08D))
#define PMIC_BUCK2_CTRL7_ADDR(base) ((base) + (0x08E))
#define PMIC_BUCK2_CTRL8_ADDR(base) ((base) + (0x08F))
#define PMIC_BUCK3_CTRL0_ADDR(base) ((base) + (0x090))
#define PMIC_BUCK3_CTRL1_ADDR(base) ((base) + (0x091))
#define PMIC_BUCK3_CTRL2_ADDR(base) ((base) + (0x092))
#define PMIC_BUCK3_CTRL3_ADDR(base) ((base) + (0x093))
#define PMIC_BUCK3_CTRL4_ADDR(base) ((base) + (0x094))
#define PMIC_BUCK3_CTRL5_ADDR(base) ((base) + (0x095))
#define PMIC_BUCK3_CTRL6_ADDR(base) ((base) + (0x096))
#define PMIC_BUCK3_CTRL7_ADDR(base) ((base) + (0x097))
#define PMIC_BUCK3_CTRL8_ADDR(base) ((base) + (0x098))
#define PMIC_BUCK4_CTRL0_ADDR(base) ((base) + (0x099))
#define PMIC_BUCK4_CTRL1_ADDR(base) ((base) + (0x09A))
#define PMIC_BUCK4_CTRL2_ADDR(base) ((base) + (0x09B))
#define PMIC_BUCK4_CTRL3_ADDR(base) ((base) + (0x09C))
#define PMIC_BUCK4_CTRL4_ADDR(base) ((base) + (0x09D))
#define PMIC_BUCK4_CTRL5_ADDR(base) ((base) + (0x09E))
#define PMIC_BUCK4_CTRL6_ADDR(base) ((base) + (0x09F))
#define PMIC_BUCK4_CTRL7_ADDR(base) ((base) + (0x0A0))
#define PMIC_BUCK4_CTRL8_ADDR(base) ((base) + (0x0A1))
#define PMIC_BUCK5_CTRL0_ADDR(base) ((base) + (0x0A2))
#define PMIC_BUCK5_CTRL1_ADDR(base) ((base) + (0x0A3))
#define PMIC_BUCK5_CTRL2_ADDR(base) ((base) + (0x0A4))
#define PMIC_BUCK5_CTRL3_ADDR(base) ((base) + (0x0A5))
#define PMIC_BUCK5_CTRL4_ADDR(base) ((base) + (0x0A6))
#define PMIC_BUCK5_CTRL5_ADDR(base) ((base) + (0x0A7))
#define PMIC_BUCK5_CTRL6_ADDR(base) ((base) + (0x0A8))
#define PMIC_BUCK5_CTRL7_ADDR(base) ((base) + (0x0A9))
#define PMIC_BUCK5_CTRL8_ADDR(base) ((base) + (0x0AA))
#define PMIC_BUCK6_CTRL0_ADDR(base) ((base) + (0x0AB))
#define PMIC_BUCK6_CTRL1_ADDR(base) ((base) + (0x0AC))
#define PMIC_BUCK6_CTRL2_ADDR(base) ((base) + (0x0AD))
#define PMIC_BUCK6_CTRL3_ADDR(base) ((base) + (0x0AE))
#define PMIC_BUCK6_CTRL4_ADDR(base) ((base) + (0x0AF))
#define PMIC_BUCK6_CTRL5_ADDR(base) ((base) + (0x0B0))
#define PMIC_BUCK6_CTRL6_ADDR(base) ((base) + (0x0B1))
#define PMIC_BUCK6_CTRL7_ADDR(base) ((base) + (0x0B2))
#define PMIC_BUCK6_CTRL8_ADDR(base) ((base) + (0x0B3))
#define PMIC_BUCK7_CTRL0_ADDR(base) ((base) + (0x0B4))
#define PMIC_BUCK7_CTRL1_ADDR(base) ((base) + (0x0B5))
#define PMIC_BUCK7_CTRL2_ADDR(base) ((base) + (0x0B6))
#define PMIC_BUCK7_CTRL3_ADDR(base) ((base) + (0x0B7))
#define PMIC_BUCK7_CTRL4_ADDR(base) ((base) + (0x0B8))
#define PMIC_BUCK7_CTRL5_ADDR(base) ((base) + (0x0B9))
#define PMIC_BUCK7_CTRL6_ADDR(base) ((base) + (0x0BA))
#define PMIC_BUCK7_CTRL7_ADDR(base) ((base) + (0x0BB))
#define PMIC_BUCK7_CTRL8_ADDR(base) ((base) + (0x0BC))
#define PMIC_BUCK7_CTRL9_ADDR(base) ((base) + (0x0BD))
#define PMIC_BUCK7_CTRL10_ADDR(base) ((base) + (0x0BE))
#define PMIC_BUCK8_CTRL0_ADDR(base) ((base) + (0x0BF))
#define PMIC_BUCK8_CTRL1_ADDR(base) ((base) + (0x0C0))
#define PMIC_BUCK8_CTRL2_ADDR(base) ((base) + (0x0C1))
#define PMIC_BUCK8_CTRL3_ADDR(base) ((base) + (0x0C2))
#define PMIC_BUCK8_CTRL4_ADDR(base) ((base) + (0x0C3))
#define PMIC_BUCK8_CTRL5_ADDR(base) ((base) + (0x0C4))
#define PMIC_BUCK8_CTRL6_ADDR(base) ((base) + (0x0C5))
#define PMIC_BUCK8_CTRL7_ADDR(base) ((base) + (0x0C6))
#define PMIC_BUCK8_CTRL8_ADDR(base) ((base) + (0x0C7))
#define PMIC_BUCK_RESERVE0_ADDR(base) ((base) + (0x0C8))
#define PMIC_BUCK_RESERVE1_ADDR(base) ((base) + (0x0C9))
#define PMIC_LDO_1_CTRL_ADDR(base) ((base) + (0x0CA))
#define PMIC_LDO1_CTRL_0_ADDR(base) ((base) + (0x0CB))
#define PMIC_LDO1_CTRL_1_ADDR(base) ((base) + (0x0CC))
#define PMIC_LDO2_3_CTRL_ADDR(base) ((base) + (0x0CD))
#define PMIC_LDO3_CTRL_ADDR(base) ((base) + (0x0CE))
#define PMIC_LDO4_CTRL_ADDR(base) ((base) + (0x0CF))
#define PMIC_LDO4_5_CTRL_ADDR(base) ((base) + (0x0D0))
#define PMIC_LDO6_CTRL_ADDR(base) ((base) + (0x0D1))
#define PMIC_LDO7_8_CTRL_ADDR(base) ((base) + (0x0D2))
#define PMIC_LDO8_CTRL_ADDR(base) ((base) + (0x0D3))
#define PMIC_LDO9_CTRL_ADDR(base) ((base) + (0x0D4))
#define PMIC_LD11_12_CTRL_ADDR(base) ((base) + (0x0D5))
#define PMIC_LDO13_CTRL_ADDR(base) ((base) + (0x0D6))
#define PMIC_LDO13_14_CTRL_ADDR(base) ((base) + (0x0D7))
#define PMIC_LDO15_16_CTRL_ADDR(base) ((base) + (0x0D8))
#define PMIC_LDO17_CTRL_ADDR(base) ((base) + (0x0D9))
#define PMIC_LDO18_CTRL0_ADDR(base) ((base) + (0x0DA))
#define PMIC_LDO18_CTRL1_ADDR(base) ((base) + (0x0DB))
#define PMIC_LDO_19_CTRL1_ADDR(base) ((base) + (0x0DC))
#define PMIC_LDO_19_CTRL2_ADDR(base) ((base) + (0x0DD))
#define PMIC_LDO_19_CTRL3_ADDR(base) ((base) + (0x0DE))
#define PMIC_LDO20_CTRL1_ADDR(base) ((base) + (0x0DF))
#define PMIC_LDO20_CTRL2_ADDR(base) ((base) + (0x0E0))
#define PMIC_LDO20_CTRL3_ADDR(base) ((base) + (0x0E1))
#define PMIC_LDO21_CTRL0_ADDR(base) ((base) + (0x0E2))
#define PMIC_LDO21_CTRL1_ADDR(base) ((base) + (0x0E3))
#define PMIC_LDO22_CTRL0_ADDR(base) ((base) + (0x0E4))
#define PMIC_LDO22_CTRL1_ADDR(base) ((base) + (0x0E5))
#define PMIC_LDO22_CTRL2_ADDR(base) ((base) + (0x0E6))
#define PMIC_LDO23_CTRL_ADDR(base) ((base) + (0x0E7))
#define PMIC_LDO24_25_CTRL_ADDR(base) ((base) + (0x0E8))
#define PMIC_LDO26_CTRL_ADDR(base) ((base) + (0x0E9))
#define PMIC_LDO27_CTRL_ADDR(base) ((base) + (0x0EA))
#define PMIC_LDO28_29_CTRL_ADDR(base) ((base) + (0x0EB))
#define PMIC_LDO30_CTRL_ADDR(base) ((base) + (0x0EC))
#define PMIC_LDO32_CTRL1_ADDR(base) ((base) + (0x0ED))
#define PMIC_LDO32_CTRL2_ADDR(base) ((base) + (0x0EE))
#define PMIC_LDO32_CTRL3_ADDR(base) ((base) + (0x0EF))
#define PMIC_LDO33_CTRL_ADDR(base) ((base) + (0x0F0))
#define PMIC_LDO34_35_CTRL_ADDR(base) ((base) + (0x0F1))
#define PMIC_LDO36_CTRL_ADDR(base) ((base) + (0x0F2))
#define PMIC_LDO_BUF_CTRL_ADDR(base) ((base) + (0x0F3))
#define PMIC_LDO_RESERVE0_ADDR(base) ((base) + (0x0F4))
#define PMIC_LDO_RESERVE1_ADDR(base) ((base) + (0x0F5))
#define PMIC_BUCK0_3_OCP_CTRL_ADDR(base) ((base) + (0x0F6))
#define PMIC_BUCK4_7_OCP_CTRL_ADDR(base) ((base) + (0x0F7))
#define PMIC_BUCK8_OCP_CTRL_ADDR(base) ((base) + (0x0F8))
#define PMIC_LDO0_3_OCP_CTRL_ADDR(base) ((base) + (0x0F9))
#define PMIC_LDO4_7_OCP_CTRL_ADDR(base) ((base) + (0x0FA))
#define PMIC_LDO8_12_OCP_CTRL_ADDR(base) ((base) + (0x0FB))
#define PMIC_LDO13_16_OCP_CTRL_ADDR(base) ((base) + (0x0FC))
#define PMIC_LDO17_20_OCP_CTRL_ADDR(base) ((base) + (0x0FD))
#define PMIC_LDO21_24_OCP_CTRL_ADDR(base) ((base) + (0x0FE))
#define PMIC_LDO25_28_OCP_CTRL_ADDR(base) ((base) + (0x0FF))
#define PMIC_LDO29_33_OCP_CTRL_ADDR(base) ((base) + (0x100))
#define PMIC_LDO34_36_OCP_CTRL_ADDR(base) ((base) + (0x101))
#define PMIC_LDO_BUFF_SCP_CTRL_ADDR(base) ((base) + (0x102))
#define PMIC_BUCK0_3_SCP_CTRL_ADDR(base) ((base) + (0x103))
#define PMIC_BUCK4_7_SCP_CTRL_ADDR(base) ((base) + (0x104))
#define PMIC_BUCK8_SCP_CTRL_ADDR(base) ((base) + (0x105))
#define PMIC_SYS_CTRL_RESERVE_ADDR(base) ((base) + (0x106))
#define PMIC_OCP_DEB_CTRL0_ADDR(base) ((base) + (0x107))
#define PMIC_OCP_DEB_CTRL1_ADDR(base) ((base) + (0x108))
#define PMIC_PWROFF_DEB_CTRL_ADDR(base) ((base) + (0x109))
#define PMIC_OCP_SCP_ONOFF_ADDR(base) ((base) + (0x10A))
#define PMIC_CLK_ABB_CTRL0_ADDR(base) ((base) + (0x10B))
#define PMIC_CLK_WIFI_CTRL0_ADDR(base) ((base) + (0x10C))
#define PMIC_CLK_NFC_CTRL0_ADDR(base) ((base) + (0x10D))
#define PMIC_CLK_RF0_CTRL0_ADDR(base) ((base) + (0x10E))
#define PMIC_CLK_RF1_CTRL0_ADDR(base) ((base) + (0x10F))
#define PMIC_CLK_SYS_USB_CTRL_ADDR(base) ((base) + (0x110))
#define PMIC_CLK_USB_CTRL_ADDR(base) ((base) + (0x111))
#define PMIC_CLK_CODEC_CTRL_ADDR(base) ((base) + (0x112))
#define PMIC_CLK_TOP_CTRL0_ADDR(base) ((base) + (0x113))
#define PMIC_CLK_TOP_CTRL1_ADDR(base) ((base) + (0x114))
#define PMIC_CLK_TOP_CTRL2_ADDR(base) ((base) + (0x115))
#define PMIC_BG_THSD_CTRL0_ADDR(base) ((base) + (0x116))
#define PMIC_BG_THSD_CTRL1_ADDR(base) ((base) + (0x117))
#define PMIC_BG_TEST_ADDR(base) ((base) + (0x118))
#define PMIC_HARDWIRE_CTRL0_ADDR(base) ((base) + (0x119))
#define PMIC_HARDWIRE_CTRL1_ADDR(base) ((base) + (0x11A))
#define PMIC_HARDWIRE_CTRL2_ADDR(base) ((base) + (0x11B))
#define PMIC_PERI_CTRL0_ADDR(base) ((base) + (0x11C))
#define PMIC_PERI_CTRL1_ADDR(base) ((base) + (0x11D))
#define PMIC_PERI_TIME__CTRL_ADDR(base) ((base) + (0x11E))
#define PMIC_PERI_CTRL2_ADDR(base) ((base) + (0x11F))
#define PMIC_PERI_CTRL3_ADDR(base) ((base) + (0x120))
#define PMIC_PERI_CTRL4_ADDR(base) ((base) + (0x121))
#define PMIC_PERI_VSET_CTRL_ADDR(base) ((base) + (0x122))
#define PMIC_COUL_ECO_MASK_ADDR(base) ((base) + (0x123))
#define PMIC_PMU_SOFT_RST_ADDR(base) ((base) + (0x124))
#define PMIC_LOCK_ADDR(base) ((base) + (0x125))
#define PMIC_DR_EN_MODE_ADDR(base) ((base) + (0x126))
#define PMIC_DR_EN_MODE_12_ADDR(base) ((base) + (0x127))
#define PMIC_FLASH_PERIOD_DR1_ADDR(base) ((base) + (0x128))
#define PMIC_FLASH_ON_DR1_ADDR(base) ((base) + (0x129))
#define PMIC_FLASH_PERIOD_DR2_ADDR(base) ((base) + (0x12A))
#define PMIC_FLASH_ON_DR2_ADDR(base) ((base) + (0x12B))
#define PMIC_FLASH_PERIOD_DR3_ADDR(base) ((base) + (0x12C))
#define PMIC_FLASH_ON_DR3_ADDR(base) ((base) + (0x12D))
#define PMIC_DR_MODE_SEL_ADDR(base) ((base) + (0x12E))
#define PMIC_DR_BRE_CTRL_ADDR(base) ((base) + (0x12F))
#define PMIC_DR1_ISET_ADDR(base) ((base) + (0x130))
#define PMIC_DR2_ISET_ADDR(base) ((base) + (0x131))
#define PMIC_DR3_ISET_ADDR(base) ((base) + (0x132))
#define PMIC_DR_OUT_CTRL_ADDR(base) ((base) + (0x133))
#define PMIC_DR1_START_DEL_ADDR(base) ((base) + (0x134))
#define PMIC_DR2_START_DEL_ADDR(base) ((base) + (0x135))
#define PMIC_DR3_START_DEL_ADDR(base) ((base) + (0x136))
#define PMIC_DR1_TIM_CONF0_ADDR(base) ((base) + (0x137))
#define PMIC_DR1_TIM_CONF1_ADDR(base) ((base) + (0x138))
#define PMIC_DR2_TIM_CONF0_ADDR(base) ((base) + (0x139))
#define PMIC_DR2_TIM_CONF1_ADDR(base) ((base) + (0x13A))
#define PMIC_DR3_TIM_CONF0_ADDR(base) ((base) + (0x13B))
#define PMIC_DR3_TIM_CONF1_ADDR(base) ((base) + (0x13C))
#define PMIC_DR_CTRLRESERVE8_ADDR(base) ((base) + (0x13D))
#define PMIC_DR_CTRLRESERVE9_ADDR(base) ((base) + (0x13E))
#define PMIC_OTP_0_ADDR(base) ((base) + (0x13F))
#define PMIC_OTP_1_ADDR(base) ((base) + (0x140))
#define PMIC_OTP_CTRL0_ADDR(base) ((base) + (0x141))
#define PMIC_OTP_CTRL1_ADDR(base) ((base) + (0x142))
#define PMIC_OTP_CTRL2_ADDR(base) ((base) + (0x143))
#define PMIC_OTP_WDATA_ADDR(base) ((base) + (0x144))
#define PMIC_OTP_0_W_ADDR(base) ((base) + (0x145))
#define PMIC_OTP_1_W_ADDR(base) ((base) + (0x146))
#define PMIC_OTP_2_W_ADDR(base) ((base) + (0x147))
#define PMIC_OTP_3_W_ADDR(base) ((base) + (0x148))
#define PMIC_OTP_4_W_ADDR(base) ((base) + (0x149))
#define PMIC_OTP_5_W_ADDR(base) ((base) + (0x14A))
#define PMIC_OTP_6_W_ADDR(base) ((base) + (0x14B))
#define PMIC_OTP_7_W_ADDR(base) ((base) + (0x14C))
#define PMIC_OTP_8_W_ADDR(base) ((base) + (0x14D))
#define PMIC_OTP_9_W_ADDR(base) ((base) + (0x14E))
#define PMIC_OTP_10_W_ADDR(base) ((base) + (0x14F))
#define PMIC_OTP_11_W_ADDR(base) ((base) + (0x150))
#define PMIC_OTP_12_W_ADDR(base) ((base) + (0x151))
#define PMIC_OTP_13_W_ADDR(base) ((base) + (0x152))
#define PMIC_OTP_14_W_ADDR(base) ((base) + (0x153))
#define PMIC_OTP_15_W_ADDR(base) ((base) + (0x154))
#define PMIC_OTP_16_W_ADDR(base) ((base) + (0x155))
#define PMIC_OTP_17_W_ADDR(base) ((base) + (0x156))
#define PMIC_OTP_18_W_ADDR(base) ((base) + (0x157))
#define PMIC_OTP_19_W_ADDR(base) ((base) + (0x158))
#define PMIC_OTP_20_W_ADDR(base) ((base) + (0x159))
#define PMIC_OTP_21_W_ADDR(base) ((base) + (0x15A))
#define PMIC_OTP_22_W_ADDR(base) ((base) + (0x15B))
#define PMIC_OTP_23_W_ADDR(base) ((base) + (0x15C))
#define PMIC_OTP_24_W_ADDR(base) ((base) + (0x15D))
#define PMIC_OTP_25_W_ADDR(base) ((base) + (0x15E))
#define PMIC_OTP_26_W_ADDR(base) ((base) + (0x15F))
#define PMIC_OTP_27_W_ADDR(base) ((base) + (0x160))
#define PMIC_OTP_28_W_ADDR(base) ((base) + (0x161))
#define PMIC_OTP_29_W_ADDR(base) ((base) + (0x162))
#define PMIC_OTP_30_W_ADDR(base) ((base) + (0x163))
#define PMIC_OTP_31_W_ADDR(base) ((base) + (0x164))
#define PMIC_D2A_RES0_ADDR(base) ((base) + (0x165))
#define PMIC_D2A_RES1_ADDR(base) ((base) + (0x166))
#define PMIC_A2D_RES0_ADDR(base) ((base) + (0x167))
#define PMIC_A2D_RES1_ADDR(base) ((base) + (0x168))
#define PMIC_SIM_CTRL0_ADDR(base) ((base) + (0x169))
#define PMIC_SIM_CTRL1_ADDR(base) ((base) + (0x16A))
#define PMIC_SIM_DEB_CTRL1_ADDR(base) ((base) + (0x16B))
#define PMIC_SIM_DEB_CTRL2_ADDR(base) ((base) + (0x16C))
#define PMIC_GPIO0DATA_ADDR(base) ((base) + (0x16D))
#define PMIC_GPIO0_DATA_RESERVE_ADDR(base) ((base) + (0x16E))
#define PMIC_GPIO0DIR_ADDR(base) ((base) + (0x16F))
#define PMIC_GPIO0_DIR_RESERVE_ADDR(base) ((base) + (0x170))
#define PMIC_GPIO0IS_ADDR(base) ((base) + (0x171))
#define PMIC_GPIO0IBE_ADDR(base) ((base) + (0x172))
#define PMIC_GPIO0IEV_ADDR(base) ((base) + (0x173))
#define PMIC_GPIO0AFSEL_ADDR(base) ((base) + (0x174))
#define PMIC_GPIO0DSSEL_ADDR(base) ((base) + (0x175))
#define PMIC_GPIO0PUSEL_ADDR(base) ((base) + (0x176))
#define PMIC_GPIO0PDSEL_ADDR(base) ((base) + (0x177))
#define PMIC_GPIO0DEBSEL_ADDR(base) ((base) + (0x178))
#define PMIC_GPIO1DATA_ADDR(base) ((base) + (0x179))
#define PMIC_GPIO1_DATA_RESERVE_ADDR(base) ((base) + (0x17A))
#define PMIC_GPIO1DIR_ADDR(base) ((base) + (0x17B))
#define PMIC_GPIO1_DIR_RESERVE_ADDR(base) ((base) + (0x17C))
#define PMIC_GPIO1IS_ADDR(base) ((base) + (0x17D))
#define PMIC_GPIO1IBE_ADDR(base) ((base) + (0x17E))
#define PMIC_GPIO1IEV_ADDR(base) ((base) + (0x17F))
#define PMIC_GPIO1AFSEL_ADDR(base) ((base) + (0x180))
#define PMIC_GPIO1DSSEL_ADDR(base) ((base) + (0x181))
#define PMIC_GPIO1PUSEL_ADDR(base) ((base) + (0x182))
#define PMIC_GPIO1PDSEL_ADDR(base) ((base) + (0x183))
#define PMIC_GPIO1DEBSEL_ADDR(base) ((base) + (0x184))
#define PMIC_GPIO2DATA_ADDR(base) ((base) + (0x185))
#define PMIC_GPIO2_DATA_RESERVE_ADDR(base) ((base) + (0x186))
#define PMIC_GPIO2DIR_ADDR(base) ((base) + (0x187))
#define PMIC_GPIO2_DIR_RESERVE_ADDR(base) ((base) + (0x188))
#define PMIC_GPIO2IS_ADDR(base) ((base) + (0x189))
#define PMIC_GPIO2IBE_ADDR(base) ((base) + (0x18A))
#define PMIC_GPIO2IEV_ADDR(base) ((base) + (0x18B))
#define PMIC_GPIO2AFSEL_ADDR(base) ((base) + (0x18C))
#define PMIC_GPIO2DSSEL_ADDR(base) ((base) + (0x18D))
#define PMIC_GPIO2PUSEL_ADDR(base) ((base) + (0x18E))
#define PMIC_GPIO2PDSEL_ADDR(base) ((base) + (0x18F))
#define PMIC_GPIO2DEBSEL_ADDR(base) ((base) + (0x190))
#define PMIC_AUX0_IBIAS_CFG_ADDR(base) ((base) + (0x191))
#define PMIC_AUX1_IBIAS_CFG_ADDR(base) ((base) + (0x192))
#define PMIC_DAC0_DIN_MSB_ADDR(base) ((base) + (0x193))
#define PMIC_DAC0_DIN_LSB_ADDR(base) ((base) + (0x194))
#define PMIC_DAC1_DIN_MSB_ADDR(base) ((base) + (0x195))
#define PMIC_DAC1_DIN_LSB_ADDR(base) ((base) + (0x196))
#define PMIC_RAMP_BUCK0_CTRL0_ADDR(base) ((base) + (0x197))
#define PMIC_RAMP_BUCK0_CTRL1_ADDR(base) ((base) + (0x198))
#define PMIC_RAMP_BUCK4_CTRL0_ADDR(base) ((base) + (0x199))
#define PMIC_RAMP_BUCK5_CTRL0_ADDR(base) ((base) + (0x19A))
#define PMIC_RAMP_BUCK6_CTRL0_ADDR(base) ((base) + (0x19B))
#define PMIC_SPMI_ECO_GT_BYPASS_ADDR(base) ((base) + (0x19C))
#define PMIC_PWRONN_8S_XOADC_DEBUG_CTRL_ADDR(base) ((base) + (0x19D))
#define PMIC_D2A_RES2_ADDR(base) ((base) + (0x19E))
#define PMIC_D2A_RES3_ADDR(base) ((base) + (0x19F))
#endif
#ifndef __SOC_H_FOR_ASM__
#define PMIC_IRQ_MASK_0_ADDR(base) ((base) + (0x202UL))
#define PMIC_IRQ_MASK_1_ADDR(base) ((base) + (0x203UL))
#define PMIC_IRQ_MASK_2_ADDR(base) ((base) + (0x204UL))
#define PMIC_IRQ_MASK_3_ADDR(base) ((base) + (0x205UL))
#define PMIC_IRQ_MASK_4_ADDR(base) ((base) + (0x206UL))
#define PMIC_IRQ_MASK_5_ADDR(base) ((base) + (0x207UL))
#define PMIC_IRQ_MASK_6_ADDR(base) ((base) + (0x208UL))
#define PMIC_IRQ_MASK_7_ADDR(base) ((base) + (0x209UL))
#define PMIC_IRQ_MASK_8_ADDR(base) ((base) + (0x20AUL))
#define PMIC_IRQ_MASK_9_ADDR(base) ((base) + (0x20BUL))
#define PMIC_IRQ_MASK_10_ADDR(base) ((base) + (0x20CUL))
#else
#define PMIC_IRQ_MASK_0_ADDR(base) ((base) + (0x202))
#define PMIC_IRQ_MASK_1_ADDR(base) ((base) + (0x203))
#define PMIC_IRQ_MASK_2_ADDR(base) ((base) + (0x204))
#define PMIC_IRQ_MASK_3_ADDR(base) ((base) + (0x205))
#define PMIC_IRQ_MASK_4_ADDR(base) ((base) + (0x206))
#define PMIC_IRQ_MASK_5_ADDR(base) ((base) + (0x207))
#define PMIC_IRQ_MASK_6_ADDR(base) ((base) + (0x208))
#define PMIC_IRQ_MASK_7_ADDR(base) ((base) + (0x209))
#define PMIC_IRQ_MASK_8_ADDR(base) ((base) + (0x20A))
#define PMIC_IRQ_MASK_9_ADDR(base) ((base) + (0x20B))
#define PMIC_IRQ_MASK_10_ADDR(base) ((base) + (0x20C))
#endif
#ifndef __SOC_H_FOR_ASM__
#define PMIC_IRQ0_ADDR(base) ((base) + (0x212UL))
#define PMIC_IRQ1_ADDR(base) ((base) + (0x213UL))
#define PMIC_OCP_IRQ0_ADDR(base) ((base) + (0x214UL))
#define PMIC_OCP_IRQ1_ADDR(base) ((base) + (0x215UL))
#define PMIC_OCP_IRQ2_ADDR(base) ((base) + (0x216UL))
#define PMIC_OCP_IRQ3_ADDR(base) ((base) + (0x217UL))
#define PMIC_OCP_IRQ4_ADDR(base) ((base) + (0x218UL))
#define PMIC_OCP_IRQ5_ADDR(base) ((base) + (0x219UL))
#define PMIC_OCP_IRQ6_ADDR(base) ((base) + (0x21AUL))
#define PMIC_OCP_IRQ7_ADDR(base) ((base) + (0x21BUL))
#define PMIC_GPIO_IRQ_ADDR(base) ((base) + (0x21CUL))
#else
#define PMIC_IRQ0_ADDR(base) ((base) + (0x212))
#define PMIC_IRQ1_ADDR(base) ((base) + (0x213))
#define PMIC_OCP_IRQ0_ADDR(base) ((base) + (0x214))
#define PMIC_OCP_IRQ1_ADDR(base) ((base) + (0x215))
#define PMIC_OCP_IRQ2_ADDR(base) ((base) + (0x216))
#define PMIC_OCP_IRQ3_ADDR(base) ((base) + (0x217))
#define PMIC_OCP_IRQ4_ADDR(base) ((base) + (0x218))
#define PMIC_OCP_IRQ5_ADDR(base) ((base) + (0x219))
#define PMIC_OCP_IRQ6_ADDR(base) ((base) + (0x21A))
#define PMIC_OCP_IRQ7_ADDR(base) ((base) + (0x21B))
#define PMIC_GPIO_IRQ_ADDR(base) ((base) + (0x21C))
#endif
#ifndef __SOC_H_FOR_ASM__
#define PMIC_NP_OCP0_ADDR(base) ((base) + (0x222UL))
#define PMIC_NP_OCP1_ADDR(base) ((base) + (0x223UL))
#define PMIC_NP_OCP2_ADDR(base) ((base) + (0x224UL))
#define PMIC_NP_OCP3_ADDR(base) ((base) + (0x225UL))
#define PMIC_NP_OCP4_ADDR(base) ((base) + (0x226UL))
#define PMIC_NP_OCP5_ADDR(base) ((base) + (0x227UL))
#define PMIC_NP_SCP0_ADDR(base) ((base) + (0x228UL))
#define PMIC_NP_SCP1_ADDR(base) ((base) + (0x229UL))
#define PMIC_NP_RECORD0_ADDR(base) ((base) + (0x22AUL))
#define PMIC_NP_RECORD1_ADDR(base) ((base) + (0x22BUL))
#define PMIC_NP_RECORD2_ADDR(base) ((base) + (0x22CUL))
#define PMIC_NP_RECORD3_ADDR(base) ((base) + (0x22DUL))
#define PMIC_NP_RECORD4_ADDR(base) ((base) + (0x22EUL))
#define PMIC_NP_RECORD5_ADDR(base) ((base) + (0x22FUL))
#define PMIC_PWRONN_RAMP_EVENT_ADDR(base) ((base) + (0x230UL))
#else
#define PMIC_NP_OCP0_ADDR(base) ((base) + (0x222))
#define PMIC_NP_OCP1_ADDR(base) ((base) + (0x223))
#define PMIC_NP_OCP2_ADDR(base) ((base) + (0x224))
#define PMIC_NP_OCP3_ADDR(base) ((base) + (0x225))
#define PMIC_NP_OCP4_ADDR(base) ((base) + (0x226))
#define PMIC_NP_OCP5_ADDR(base) ((base) + (0x227))
#define PMIC_NP_SCP0_ADDR(base) ((base) + (0x228))
#define PMIC_NP_SCP1_ADDR(base) ((base) + (0x229))
#define PMIC_NP_RECORD0_ADDR(base) ((base) + (0x22A))
#define PMIC_NP_RECORD1_ADDR(base) ((base) + (0x22B))
#define PMIC_NP_RECORD2_ADDR(base) ((base) + (0x22C))
#define PMIC_NP_RECORD3_ADDR(base) ((base) + (0x22D))
#define PMIC_NP_RECORD4_ADDR(base) ((base) + (0x22E))
#define PMIC_NP_RECORD5_ADDR(base) ((base) + (0x22F))
#define PMIC_PWRONN_RAMP_EVENT_ADDR(base) ((base) + (0x230))
#endif
#ifndef __SOC_H_FOR_ASM__
#define PMIC_CLK_ABB_CTRL1_ADDR(base) ((base) + (0x236UL))
#define PMIC_CLK_WIFI_CTRL1_ADDR(base) ((base) + (0x237UL))
#define PMIC_CLK_NFC_CTRL1_ADDR(base) ((base) + (0x238UL))
#define PMIC_CLK_RF0_CTRL1_ADDR(base) ((base) + (0x239UL))
#define PMIC_CLK_RF1_CTRL1_ADDR(base) ((base) + (0x23AUL))
#define PMIC_CLK_TOP_CTRL1_0_ADDR(base) ((base) + (0x23BUL))
#define PMIC_CLK_TOP_CTRL1_1_ADDR(base) ((base) + (0x23CUL))
#define PMIC_CLK_256K_CTRL0_ADDR(base) ((base) + (0x23DUL))
#define PMIC_CLK_256K_CTRL1_ADDR(base) ((base) + (0x23EUL))
#define PMIC_VSYS_LOW_SET_ADDR(base) ((base) + (0x23FUL))
#define PMIC_NFC_ON_CTRL_ADDR(base) ((base) + (0x240UL))
#define PMIC_HRESET_PWRDOWN_CTRL_ADDR(base) ((base) + (0x241UL))
#define PMIC_SMPL_CTRL_ADDR(base) ((base) + (0x242UL))
#define PMIC_SYS_CTRL1_ADDR(base) ((base) + (0x243UL))
#define PMIC_DEBUG_LOCK_ADDR(base) ((base) + (0x244UL))
#define PMIC_SYS_DEBUG0_ADDR(base) ((base) + (0x245UL))
#define PMIC_SYS_DEBUG1_ADDR(base) ((base) + (0x246UL))
#define PMIC_SYS_DEBUG2_ADDR(base) ((base) + (0x247UL))
#define PMIC_SYS_DEBUG3_ADDR(base) ((base) + (0x248UL))
#define PMIC_BACKUP_CHG_ADDR(base) ((base) + (0x249UL))
#define PMIC_RTC_CALI_CTRL_ADDR(base) ((base) + (0x24AUL))
#define PMIC_NP_D2A_RES0_ADDR(base) ((base) + (0x24BUL))
#define PMIC_NP_D2A_RES1_ADDR(base) ((base) + (0x24CUL))
#define PMIC_HRST_REG0_ADDR(base) ((base) + (0x24DUL))
#define PMIC_HRST_REG1_ADDR(base) ((base) + (0x24EUL))
#define PMIC_HRST_REG2_ADDR(base) ((base) + (0x24FUL))
#define PMIC_HRST_REG3_ADDR(base) ((base) + (0x250UL))
#define PMIC_HRST_REG4_ADDR(base) ((base) + (0x251UL))
#define PMIC_HRST_REG5_ADDR(base) ((base) + (0x252UL))
#define PMIC_HRST_REG6_ADDR(base) ((base) + (0x253UL))
#define PMIC_HRST_REG7_ADDR(base) ((base) + (0x254UL))
#define PMIC_HRST_REG8_ADDR(base) ((base) + (0x255UL))
#define PMIC_HRST_REG9_ADDR(base) ((base) + (0x256UL))
#define PMIC_HRST_REG10_ADDR(base) ((base) + (0x257UL))
#define PMIC_HRST_REG11_ADDR(base) ((base) + (0x258UL))
#define PMIC_HRST_REG12_ADDR(base) ((base) + (0x259UL))
#define PMIC_HRST_REG13_ADDR(base) ((base) + (0x25AUL))
#define PMIC_HRST_REG14_ADDR(base) ((base) + (0x25BUL))
#define PMIC_OTP_0_R_ADDR(base) ((base) + (0x25CUL))
#define PMIC_OTP_1_R_ADDR(base) ((base) + (0x25DUL))
#define PMIC_OTP_2_R_ADDR(base) ((base) + (0x25EUL))
#define PMIC_OTP_3_R_ADDR(base) ((base) + (0x25FUL))
#define PMIC_OTP_4_R_ADDR(base) ((base) + (0x260UL))
#define PMIC_OTP_5_R_ADDR(base) ((base) + (0x261UL))
#define PMIC_OTP_6_R_ADDR(base) ((base) + (0x262UL))
#define PMIC_OTP_7_R_ADDR(base) ((base) + (0x263UL))
#define PMIC_OTP_8_R_ADDR(base) ((base) + (0x264UL))
#define PMIC_OTP_9_R_ADDR(base) ((base) + (0x265UL))
#define PMIC_OTP_10_R_ADDR(base) ((base) + (0x266UL))
#define PMIC_OTP_11_R_ADDR(base) ((base) + (0x267UL))
#define PMIC_OTP_12_R_ADDR(base) ((base) + (0x268UL))
#define PMIC_OTP_13_R_ADDR(base) ((base) + (0x269UL))
#define PMIC_OTP_14_R_ADDR(base) ((base) + (0x26AUL))
#define PMIC_OTP_15_R_ADDR(base) ((base) + (0x26BUL))
#define PMIC_OTP_16_R_ADDR(base) ((base) + (0x26CUL))
#define PMIC_OTP_17_R_ADDR(base) ((base) + (0x26DUL))
#define PMIC_OTP_18_R_ADDR(base) ((base) + (0x26EUL))
#define PMIC_OTP_19_R_ADDR(base) ((base) + (0x26FUL))
#define PMIC_OTP_20_R_ADDR(base) ((base) + (0x270UL))
#define PMIC_OTP_21_R_ADDR(base) ((base) + (0x271UL))
#define PMIC_OTP_22_R_ADDR(base) ((base) + (0x272UL))
#define PMIC_OTP_23_R_ADDR(base) ((base) + (0x273UL))
#define PMIC_OTP_24_R_ADDR(base) ((base) + (0x274UL))
#define PMIC_OTP_25_R_ADDR(base) ((base) + (0x275UL))
#define PMIC_OTP_26_R_ADDR(base) ((base) + (0x276UL))
#define PMIC_OTP_27_R_ADDR(base) ((base) + (0x277UL))
#define PMIC_OTP_28_R_ADDR(base) ((base) + (0x278UL))
#define PMIC_OTP_29_R_ADDR(base) ((base) + (0x279UL))
#define PMIC_OTP_30_R_ADDR(base) ((base) + (0x27AUL))
#define PMIC_OTP_31_R_ADDR(base) ((base) + (0x27BUL))
#define PMIC_OTP_32_R_ADDR(base) ((base) + (0x27CUL))
#define PMIC_OTP_33_R_ADDR(base) ((base) + (0x27DUL))
#define PMIC_OTP_34_R_ADDR(base) ((base) + (0x27EUL))
#define PMIC_OTP_35_R_ADDR(base) ((base) + (0x27FUL))
#define PMIC_OTP_36_R_ADDR(base) ((base) + (0x280UL))
#define PMIC_OTP_37_R_ADDR(base) ((base) + (0x281UL))
#define PMIC_OTP_38_R_ADDR(base) ((base) + (0x282UL))
#define PMIC_OTP_39_R_ADDR(base) ((base) + (0x283UL))
#define PMIC_OTP_40_R_ADDR(base) ((base) + (0x284UL))
#define PMIC_OTP_41_R_ADDR(base) ((base) + (0x285UL))
#define PMIC_OTP_42_R_ADDR(base) ((base) + (0x286UL))
#define PMIC_OTP_43_R_ADDR(base) ((base) + (0x287UL))
#define PMIC_OTP_44_R_ADDR(base) ((base) + (0x288UL))
#define PMIC_OTP_45_R_ADDR(base) ((base) + (0x289UL))
#define PMIC_OTP_46_R_ADDR(base) ((base) + (0x28AUL))
#define PMIC_OTP_47_R_ADDR(base) ((base) + (0x28BUL))
#define PMIC_OTP_48_R_ADDR(base) ((base) + (0x28CUL))
#define PMIC_OTP_49_R_ADDR(base) ((base) + (0x28DUL))
#define PMIC_OTP_50_R_ADDR(base) ((base) + (0x28EUL))
#define PMIC_OTP_51_R_ADDR(base) ((base) + (0x28FUL))
#define PMIC_OTP_52_R_ADDR(base) ((base) + (0x290UL))
#define PMIC_OTP_53_R_ADDR(base) ((base) + (0x291UL))
#define PMIC_OTP_54_R_ADDR(base) ((base) + (0x292UL))
#define PMIC_OTP_55_R_ADDR(base) ((base) + (0x293UL))
#define PMIC_OTP_56_R_ADDR(base) ((base) + (0x294UL))
#define PMIC_OTP_57_R_ADDR(base) ((base) + (0x295UL))
#define PMIC_OTP_58_R_ADDR(base) ((base) + (0x296UL))
#define PMIC_OTP_59_R_ADDR(base) ((base) + (0x297UL))
#define PMIC_OTP_60_R_ADDR(base) ((base) + (0x298UL))
#define PMIC_OTP_61_R_ADDR(base) ((base) + (0x299UL))
#define PMIC_OTP_62_R_ADDR(base) ((base) + (0x29AUL))
#define PMIC_OTP_63_R_ADDR(base) ((base) + (0x29BUL))
#define PMIC_NP_D2A_RES2_ADDR(base) ((base) + (0x29CUL))
#else
#define PMIC_CLK_ABB_CTRL1_ADDR(base) ((base) + (0x236))
#define PMIC_CLK_WIFI_CTRL1_ADDR(base) ((base) + (0x237))
#define PMIC_CLK_NFC_CTRL1_ADDR(base) ((base) + (0x238))
#define PMIC_CLK_RF0_CTRL1_ADDR(base) ((base) + (0x239))
#define PMIC_CLK_RF1_CTRL1_ADDR(base) ((base) + (0x23A))
#define PMIC_CLK_TOP_CTRL1_0_ADDR(base) ((base) + (0x23B))
#define PMIC_CLK_TOP_CTRL1_1_ADDR(base) ((base) + (0x23C))
#define PMIC_CLK_256K_CTRL0_ADDR(base) ((base) + (0x23D))
#define PMIC_CLK_256K_CTRL1_ADDR(base) ((base) + (0x23E))
#define PMIC_VSYS_LOW_SET_ADDR(base) ((base) + (0x23F))
#define PMIC_NFC_ON_CTRL_ADDR(base) ((base) + (0x240))
#define PMIC_HRESET_PWRDOWN_CTRL_ADDR(base) ((base) + (0x241))
#define PMIC_SMPL_CTRL_ADDR(base) ((base) + (0x242))
#define PMIC_SYS_CTRL1_ADDR(base) ((base) + (0x243))
#define PMIC_DEBUG_LOCK_ADDR(base) ((base) + (0x244))
#define PMIC_SYS_DEBUG0_ADDR(base) ((base) + (0x245))
#define PMIC_SYS_DEBUG1_ADDR(base) ((base) + (0x246))
#define PMIC_SYS_DEBUG2_ADDR(base) ((base) + (0x247))
#define PMIC_SYS_DEBUG3_ADDR(base) ((base) + (0x248))
#define PMIC_BACKUP_CHG_ADDR(base) ((base) + (0x249))
#define PMIC_RTC_CALI_CTRL_ADDR(base) ((base) + (0x24A))
#define PMIC_NP_D2A_RES0_ADDR(base) ((base) + (0x24B))
#define PMIC_NP_D2A_RES1_ADDR(base) ((base) + (0x24C))
#define PMIC_HRST_REG0_ADDR(base) ((base) + (0x24D))
#define PMIC_HRST_REG1_ADDR(base) ((base) + (0x24E))
#define PMIC_HRST_REG2_ADDR(base) ((base) + (0x24F))
#define PMIC_HRST_REG3_ADDR(base) ((base) + (0x250))
#define PMIC_HRST_REG4_ADDR(base) ((base) + (0x251))
#define PMIC_HRST_REG5_ADDR(base) ((base) + (0x252))
#define PMIC_HRST_REG6_ADDR(base) ((base) + (0x253))
#define PMIC_HRST_REG7_ADDR(base) ((base) + (0x254))
#define PMIC_HRST_REG8_ADDR(base) ((base) + (0x255))
#define PMIC_HRST_REG9_ADDR(base) ((base) + (0x256))
#define PMIC_HRST_REG10_ADDR(base) ((base) + (0x257))
#define PMIC_HRST_REG11_ADDR(base) ((base) + (0x258))
#define PMIC_HRST_REG12_ADDR(base) ((base) + (0x259))
#define PMIC_HRST_REG13_ADDR(base) ((base) + (0x25A))
#define PMIC_HRST_REG14_ADDR(base) ((base) + (0x25B))
#define PMIC_OTP_0_R_ADDR(base) ((base) + (0x25C))
#define PMIC_OTP_1_R_ADDR(base) ((base) + (0x25D))
#define PMIC_OTP_2_R_ADDR(base) ((base) + (0x25E))
#define PMIC_OTP_3_R_ADDR(base) ((base) + (0x25F))
#define PMIC_OTP_4_R_ADDR(base) ((base) + (0x260))
#define PMIC_OTP_5_R_ADDR(base) ((base) + (0x261))
#define PMIC_OTP_6_R_ADDR(base) ((base) + (0x262))
#define PMIC_OTP_7_R_ADDR(base) ((base) + (0x263))
#define PMIC_OTP_8_R_ADDR(base) ((base) + (0x264))
#define PMIC_OTP_9_R_ADDR(base) ((base) + (0x265))
#define PMIC_OTP_10_R_ADDR(base) ((base) + (0x266))
#define PMIC_OTP_11_R_ADDR(base) ((base) + (0x267))
#define PMIC_OTP_12_R_ADDR(base) ((base) + (0x268))
#define PMIC_OTP_13_R_ADDR(base) ((base) + (0x269))
#define PMIC_OTP_14_R_ADDR(base) ((base) + (0x26A))
#define PMIC_OTP_15_R_ADDR(base) ((base) + (0x26B))
#define PMIC_OTP_16_R_ADDR(base) ((base) + (0x26C))
#define PMIC_OTP_17_R_ADDR(base) ((base) + (0x26D))
#define PMIC_OTP_18_R_ADDR(base) ((base) + (0x26E))
#define PMIC_OTP_19_R_ADDR(base) ((base) + (0x26F))
#define PMIC_OTP_20_R_ADDR(base) ((base) + (0x270))
#define PMIC_OTP_21_R_ADDR(base) ((base) + (0x271))
#define PMIC_OTP_22_R_ADDR(base) ((base) + (0x272))
#define PMIC_OTP_23_R_ADDR(base) ((base) + (0x273))
#define PMIC_OTP_24_R_ADDR(base) ((base) + (0x274))
#define PMIC_OTP_25_R_ADDR(base) ((base) + (0x275))
#define PMIC_OTP_26_R_ADDR(base) ((base) + (0x276))
#define PMIC_OTP_27_R_ADDR(base) ((base) + (0x277))
#define PMIC_OTP_28_R_ADDR(base) ((base) + (0x278))
#define PMIC_OTP_29_R_ADDR(base) ((base) + (0x279))
#define PMIC_OTP_30_R_ADDR(base) ((base) + (0x27A))
#define PMIC_OTP_31_R_ADDR(base) ((base) + (0x27B))
#define PMIC_OTP_32_R_ADDR(base) ((base) + (0x27C))
#define PMIC_OTP_33_R_ADDR(base) ((base) + (0x27D))
#define PMIC_OTP_34_R_ADDR(base) ((base) + (0x27E))
#define PMIC_OTP_35_R_ADDR(base) ((base) + (0x27F))
#define PMIC_OTP_36_R_ADDR(base) ((base) + (0x280))
#define PMIC_OTP_37_R_ADDR(base) ((base) + (0x281))
#define PMIC_OTP_38_R_ADDR(base) ((base) + (0x282))
#define PMIC_OTP_39_R_ADDR(base) ((base) + (0x283))
#define PMIC_OTP_40_R_ADDR(base) ((base) + (0x284))
#define PMIC_OTP_41_R_ADDR(base) ((base) + (0x285))
#define PMIC_OTP_42_R_ADDR(base) ((base) + (0x286))
#define PMIC_OTP_43_R_ADDR(base) ((base) + (0x287))
#define PMIC_OTP_44_R_ADDR(base) ((base) + (0x288))
#define PMIC_OTP_45_R_ADDR(base) ((base) + (0x289))
#define PMIC_OTP_46_R_ADDR(base) ((base) + (0x28A))
#define PMIC_OTP_47_R_ADDR(base) ((base) + (0x28B))
#define PMIC_OTP_48_R_ADDR(base) ((base) + (0x28C))
#define PMIC_OTP_49_R_ADDR(base) ((base) + (0x28D))
#define PMIC_OTP_50_R_ADDR(base) ((base) + (0x28E))
#define PMIC_OTP_51_R_ADDR(base) ((base) + (0x28F))
#define PMIC_OTP_52_R_ADDR(base) ((base) + (0x290))
#define PMIC_OTP_53_R_ADDR(base) ((base) + (0x291))
#define PMIC_OTP_54_R_ADDR(base) ((base) + (0x292))
#define PMIC_OTP_55_R_ADDR(base) ((base) + (0x293))
#define PMIC_OTP_56_R_ADDR(base) ((base) + (0x294))
#define PMIC_OTP_57_R_ADDR(base) ((base) + (0x295))
#define PMIC_OTP_58_R_ADDR(base) ((base) + (0x296))
#define PMIC_OTP_59_R_ADDR(base) ((base) + (0x297))
#define PMIC_OTP_60_R_ADDR(base) ((base) + (0x298))
#define PMIC_OTP_61_R_ADDR(base) ((base) + (0x299))
#define PMIC_OTP_62_R_ADDR(base) ((base) + (0x29A))
#define PMIC_OTP_63_R_ADDR(base) ((base) + (0x29B))
#define PMIC_NP_D2A_RES2_ADDR(base) ((base) + (0x29C))
#endif
#ifndef __SOC_H_FOR_ASM__
#define PMIC_PWRUP_CALI_END_ADDR(base) ((base) + (0x2C4UL))
#define PMIC_XOADC_AUTOCALI_AVE0_ADDR(base) ((base) + (0x2C5UL))
#define PMIC_XOADC_AUTOCALI_AVE1_ADDR(base) ((base) + (0x2C6UL))
#define PMIC_XOADC_AUTOCALI_AVE2_ADDR(base) ((base) + (0x2C7UL))
#define PMIC_XOADC_AUTOCALI_AVE3_ADDR(base) ((base) + (0x2C8UL))
#define PMIC_XOADC_CTRL_ADDR(base) ((base) + (0x2C9UL))
#define PMIC_XOADC_SAMP_PHASE_ADDR(base) ((base) + (0x2CAUL))
#define PMIC_XOADC_OPT_0_ADDR(base) ((base) + (0x2CBUL))
#define PMIC_XOADC_OPT_1_ADDR(base) ((base) + (0x2CCUL))
#define PMIC_XOADC_AIN_SEL_ADDR(base) ((base) + (0x2CDUL))
#define PMIC_XOADC_WIFI_ANA_EN_ADDR(base) ((base) + (0x2CEUL))
#define PMIC_XOADC_SOC_ANA_EN_ADDR(base) ((base) + (0x2CFUL))
#define PMIC_XOADC_STATE_ADDR(base) ((base) + (0x2D0UL))
#define PMIC_XOADC_DATA0_ADDR(base) ((base) + (0x2D1UL))
#define PMIC_XOADC_DATA1_ADDR(base) ((base) + (0x2D2UL))
#define PMIC_XOADC_CALI_DATA0_ADDR(base) ((base) + (0x2D3UL))
#define PMIC_XOADC_CALI_DATA1_ADDR(base) ((base) + (0x2D4UL))
#define PMIC_XOADC_CFG_EN_ADDR(base) ((base) + (0x2D5UL))
#define PMIC_XOADC_ARB_DEBUG_ADDR(base) ((base) + (0x2D6UL))
#define PMIC_XOADC_CTRL_S_ADDR(base) ((base) + (0x2D7UL))
#define PMIC_XOADC_SAMP_PHASE_S_ADDR(base) ((base) + (0x2D8UL))
#define PMIC_XOADC_OPT_0_S_ADDR(base) ((base) + (0x2D9UL))
#define PMIC_XOADC_OPT_1_S_ADDR(base) ((base) + (0x2DAUL))
#define PMIC_XOADC_AIN_SEL_S_ADDR(base) ((base) + (0x2DBUL))
#define PMIC_XOADC_ANA_EN_S_ADDR(base) ((base) + (0x2DCUL))
#define PMIC_XOADC_SOFT_CFG0_ADDR(base) ((base) + (0x2DDUL))
#define PMIC_XOADC_SOFT_CFG1_ADDR(base) ((base) + (0x2DEUL))
#define PMIC_XOADC_SOFT_CFG2_ADDR(base) ((base) + (0x2DFUL))
#define PMIC_XOADC_SOFT_CFG3_ADDR(base) ((base) + (0x2E0UL))
#define PMIC_XOADC_SOFT_CFG4_ADDR(base) ((base) + (0x2E1UL))
#define PMIC_XOADC_SOFT_CFG5_ADDR(base) ((base) + (0x2E2UL))
#define PMIC_XOADC_SOFT_CFG6_ADDR(base) ((base) + (0x2E3UL))
#define PMIC_XOADC_SOFT_CFG7_ADDR(base) ((base) + (0x2E4UL))
#define PMIC_XOADC_RESERVE_ADDR(base) ((base) + (0x2E5UL))
#define PMIC_SPMI_DEBUG0_ADDR(base) ((base) + (0x2E7UL))
#define PMIC_SPMI_DEBUG1_ADDR(base) ((base) + (0x2E8UL))
#define PMIC_SPMI_DEBUG2_ADDR(base) ((base) + (0x2E9UL))
#define PMIC_SPMI_DEBUG3_ADDR(base) ((base) + (0x2EAUL))
#define PMIC_SPMI_DEBUG4_ADDR(base) ((base) + (0x2EBUL))
#define PMIC_SPMI_DEBUG5_ADDR(base) ((base) + (0x2ECUL))
#define PMIC_SPMI_DEBUG6_ADDR(base) ((base) + (0x2EDUL))
#define PMIC_SPMI_DEBUG7_ADDR(base) ((base) + (0x2EEUL))
#else
#define PMIC_PWRUP_CALI_END_ADDR(base) ((base) + (0x2C4))
#define PMIC_XOADC_AUTOCALI_AVE0_ADDR(base) ((base) + (0x2C5))
#define PMIC_XOADC_AUTOCALI_AVE1_ADDR(base) ((base) + (0x2C6))
#define PMIC_XOADC_AUTOCALI_AVE2_ADDR(base) ((base) + (0x2C7))
#define PMIC_XOADC_AUTOCALI_AVE3_ADDR(base) ((base) + (0x2C8))
#define PMIC_XOADC_CTRL_ADDR(base) ((base) + (0x2C9))
#define PMIC_XOADC_SAMP_PHASE_ADDR(base) ((base) + (0x2CA))
#define PMIC_XOADC_OPT_0_ADDR(base) ((base) + (0x2CB))
#define PMIC_XOADC_OPT_1_ADDR(base) ((base) + (0x2CC))
#define PMIC_XOADC_AIN_SEL_ADDR(base) ((base) + (0x2CD))
#define PMIC_XOADC_WIFI_ANA_EN_ADDR(base) ((base) + (0x2CE))
#define PMIC_XOADC_SOC_ANA_EN_ADDR(base) ((base) + (0x2CF))
#define PMIC_XOADC_STATE_ADDR(base) ((base) + (0x2D0))
#define PMIC_XOADC_DATA0_ADDR(base) ((base) + (0x2D1))
#define PMIC_XOADC_DATA1_ADDR(base) ((base) + (0x2D2))
#define PMIC_XOADC_CALI_DATA0_ADDR(base) ((base) + (0x2D3))
#define PMIC_XOADC_CALI_DATA1_ADDR(base) ((base) + (0x2D4))
#define PMIC_XOADC_CFG_EN_ADDR(base) ((base) + (0x2D5))
#define PMIC_XOADC_ARB_DEBUG_ADDR(base) ((base) + (0x2D6))
#define PMIC_XOADC_CTRL_S_ADDR(base) ((base) + (0x2D7))
#define PMIC_XOADC_SAMP_PHASE_S_ADDR(base) ((base) + (0x2D8))
#define PMIC_XOADC_OPT_0_S_ADDR(base) ((base) + (0x2D9))
#define PMIC_XOADC_OPT_1_S_ADDR(base) ((base) + (0x2DA))
#define PMIC_XOADC_AIN_SEL_S_ADDR(base) ((base) + (0x2DB))
#define PMIC_XOADC_ANA_EN_S_ADDR(base) ((base) + (0x2DC))
#define PMIC_XOADC_SOFT_CFG0_ADDR(base) ((base) + (0x2DD))
#define PMIC_XOADC_SOFT_CFG1_ADDR(base) ((base) + (0x2DE))
#define PMIC_XOADC_SOFT_CFG2_ADDR(base) ((base) + (0x2DF))
#define PMIC_XOADC_SOFT_CFG3_ADDR(base) ((base) + (0x2E0))
#define PMIC_XOADC_SOFT_CFG4_ADDR(base) ((base) + (0x2E1))
#define PMIC_XOADC_SOFT_CFG5_ADDR(base) ((base) + (0x2E2))
#define PMIC_XOADC_SOFT_CFG6_ADDR(base) ((base) + (0x2E3))
#define PMIC_XOADC_SOFT_CFG7_ADDR(base) ((base) + (0x2E4))
#define PMIC_XOADC_RESERVE_ADDR(base) ((base) + (0x2E5))
#define PMIC_SPMI_DEBUG0_ADDR(base) ((base) + (0x2E7))
#define PMIC_SPMI_DEBUG1_ADDR(base) ((base) + (0x2E8))
#define PMIC_SPMI_DEBUG2_ADDR(base) ((base) + (0x2E9))
#define PMIC_SPMI_DEBUG3_ADDR(base) ((base) + (0x2EA))
#define PMIC_SPMI_DEBUG4_ADDR(base) ((base) + (0x2EB))
#define PMIC_SPMI_DEBUG5_ADDR(base) ((base) + (0x2EC))
#define PMIC_SPMI_DEBUG6_ADDR(base) ((base) + (0x2ED))
#define PMIC_SPMI_DEBUG7_ADDR(base) ((base) + (0x2EE))
#endif
#ifndef __SOC_H_FOR_ASM__
#define PMIC_RTCDR0_ADDR(base) ((base) + (0x340UL))
#define PMIC_RTCDR1_ADDR(base) ((base) + (0x341UL))
#define PMIC_RTCDR2_ADDR(base) ((base) + (0x342UL))
#define PMIC_RTCDR3_ADDR(base) ((base) + (0x343UL))
#define PMIC_RTCMR0_ADDR(base) ((base) + (0x344UL))
#define PMIC_RTCMR1_ADDR(base) ((base) + (0x345UL))
#define PMIC_RTCMR2_ADDR(base) ((base) + (0x346UL))
#define PMIC_RTCMR3_ADDR(base) ((base) + (0x347UL))
#define PMIC_RTCLR0_ADDR(base) ((base) + (0x348UL))
#define PMIC_RTCLR1_ADDR(base) ((base) + (0x349UL))
#define PMIC_RTCLR2_ADDR(base) ((base) + (0x34AUL))
#define PMIC_RTCLR3_ADDR(base) ((base) + (0x34BUL))
#define PMIC_RTCCTRL_ADDR(base) ((base) + (0x34CUL))
#define PMIC_CRC_VAULE0_ADDR(base) ((base) + (0x34DUL))
#define PMIC_CRC_VAULE1_ADDR(base) ((base) + (0x34EUL))
#define PMIC_CRC_VAULE2_ADDR(base) ((base) + (0x34FUL))
#define PMIC_RTC_PWRUP_TIMER0_ADDR(base) ((base) + (0x350UL))
#define PMIC_RTC_PWRUP_TIMER1_ADDR(base) ((base) + (0x351UL))
#define PMIC_RTC_PWRUP_TIMER2_ADDR(base) ((base) + (0x352UL))
#define PMIC_RTC_PWRUP_TIMER3_ADDR(base) ((base) + (0x353UL))
#define PMIC_RTC_PWRDOWN_TIMER0_ADDR(base) ((base) + (0x354UL))
#define PMIC_RTC_PWRDOWN_TIMER1_ADDR(base) ((base) + (0x355UL))
#define PMIC_RTC_PWRDOWN_TIMER2_ADDR(base) ((base) + (0x356UL))
#define PMIC_RTC_PWRDOWN_TIMER3_ADDR(base) ((base) + (0x357UL))
#define PMIC_SER_RTCDR0_ADDR(base) ((base) + (0x360UL))
#define PMIC_SER_RTCDR1_ADDR(base) ((base) + (0x361UL))
#define PMIC_SER_RTCDR2_ADDR(base) ((base) + (0x362UL))
#define PMIC_SER_RTCDR3_ADDR(base) ((base) + (0x363UL))
#define PMIC_SER_RTCMR0_ADDR(base) ((base) + (0x364UL))
#define PMIC_SER_RTCMR1_ADDR(base) ((base) + (0x365UL))
#define PMIC_SER_RTCMR2_ADDR(base) ((base) + (0x366UL))
#define PMIC_SER_RTCMR3_ADDR(base) ((base) + (0x367UL))
#define PMIC_SER_RTCLR0_ADDR(base) ((base) + (0x368UL))
#define PMIC_SER_RTCLR1_ADDR(base) ((base) + (0x369UL))
#define PMIC_SER_RTCLR2_ADDR(base) ((base) + (0x36AUL))
#define PMIC_SER_RTCLR3_ADDR(base) ((base) + (0x36BUL))
#define PMIC_SER_RTCCTRL_ADDR(base) ((base) + (0x36CUL))
#define PMIC_SER_XO_THRESOLD0_ADDR(base) ((base) + (0x36DUL))
#define PMIC_SER_XO_THRESOLD1_ADDR(base) ((base) + (0x36EUL))
#define PMIC_SER_CRC_VAULE0_ADDR(base) ((base) + (0x36FUL))
#define PMIC_SER_CRC_VAULE1_ADDR(base) ((base) + (0x370UL))
#define PMIC_SER_CRC_VAULE2_ADDR(base) ((base) + (0x371UL))
#define PMIC_SER_RTC_PWRUP_TIMER0_ADDR(base) ((base) + (0x372UL))
#define PMIC_SER_RTC_PWRUP_TIMER1_ADDR(base) ((base) + (0x373UL))
#define PMIC_SER_RTC_PWRUP_TIMER2_ADDR(base) ((base) + (0x374UL))
#define PMIC_SER_RTC_PWRUP_TIMER3_ADDR(base) ((base) + (0x375UL))
#define PMIC_SER_RTC_PWRDOWN_TIMER0_ADDR(base) ((base) + (0x376UL))
#define PMIC_SER_RTC_PWRDOWN_TIMER1_ADDR(base) ((base) + (0x377UL))
#define PMIC_SER_RTC_PWRDOWN_TIMER2_ADDR(base) ((base) + (0x378UL))
#define PMIC_SER_RTC_PWRDOWN_TIMER3_ADDR(base) ((base) + (0x379UL))
#else
#define PMIC_RTCDR0_ADDR(base) ((base) + (0x340))
#define PMIC_RTCDR1_ADDR(base) ((base) + (0x341))
#define PMIC_RTCDR2_ADDR(base) ((base) + (0x342))
#define PMIC_RTCDR3_ADDR(base) ((base) + (0x343))
#define PMIC_RTCMR0_ADDR(base) ((base) + (0x344))
#define PMIC_RTCMR1_ADDR(base) ((base) + (0x345))
#define PMIC_RTCMR2_ADDR(base) ((base) + (0x346))
#define PMIC_RTCMR3_ADDR(base) ((base) + (0x347))
#define PMIC_RTCLR0_ADDR(base) ((base) + (0x348))
#define PMIC_RTCLR1_ADDR(base) ((base) + (0x349))
#define PMIC_RTCLR2_ADDR(base) ((base) + (0x34A))
#define PMIC_RTCLR3_ADDR(base) ((base) + (0x34B))
#define PMIC_RTCCTRL_ADDR(base) ((base) + (0x34C))
#define PMIC_CRC_VAULE0_ADDR(base) ((base) + (0x34D))
#define PMIC_CRC_VAULE1_ADDR(base) ((base) + (0x34E))
#define PMIC_CRC_VAULE2_ADDR(base) ((base) + (0x34F))
#define PMIC_RTC_PWRUP_TIMER0_ADDR(base) ((base) + (0x350))
#define PMIC_RTC_PWRUP_TIMER1_ADDR(base) ((base) + (0x351))
#define PMIC_RTC_PWRUP_TIMER2_ADDR(base) ((base) + (0x352))
#define PMIC_RTC_PWRUP_TIMER3_ADDR(base) ((base) + (0x353))
#define PMIC_RTC_PWRDOWN_TIMER0_ADDR(base) ((base) + (0x354))
#define PMIC_RTC_PWRDOWN_TIMER1_ADDR(base) ((base) + (0x355))
#define PMIC_RTC_PWRDOWN_TIMER2_ADDR(base) ((base) + (0x356))
#define PMIC_RTC_PWRDOWN_TIMER3_ADDR(base) ((base) + (0x357))
#define PMIC_SER_RTCDR0_ADDR(base) ((base) + (0x360))
#define PMIC_SER_RTCDR1_ADDR(base) ((base) + (0x361))
#define PMIC_SER_RTCDR2_ADDR(base) ((base) + (0x362))
#define PMIC_SER_RTCDR3_ADDR(base) ((base) + (0x363))
#define PMIC_SER_RTCMR0_ADDR(base) ((base) + (0x364))
#define PMIC_SER_RTCMR1_ADDR(base) ((base) + (0x365))
#define PMIC_SER_RTCMR2_ADDR(base) ((base) + (0x366))
#define PMIC_SER_RTCMR3_ADDR(base) ((base) + (0x367))
#define PMIC_SER_RTCLR0_ADDR(base) ((base) + (0x368))
#define PMIC_SER_RTCLR1_ADDR(base) ((base) + (0x369))
#define PMIC_SER_RTCLR2_ADDR(base) ((base) + (0x36A))
#define PMIC_SER_RTCLR3_ADDR(base) ((base) + (0x36B))
#define PMIC_SER_RTCCTRL_ADDR(base) ((base) + (0x36C))
#define PMIC_SER_XO_THRESOLD0_ADDR(base) ((base) + (0x36D))
#define PMIC_SER_XO_THRESOLD1_ADDR(base) ((base) + (0x36E))
#define PMIC_SER_CRC_VAULE0_ADDR(base) ((base) + (0x36F))
#define PMIC_SER_CRC_VAULE1_ADDR(base) ((base) + (0x370))
#define PMIC_SER_CRC_VAULE2_ADDR(base) ((base) + (0x371))
#define PMIC_SER_RTC_PWRUP_TIMER0_ADDR(base) ((base) + (0x372))
#define PMIC_SER_RTC_PWRUP_TIMER1_ADDR(base) ((base) + (0x373))
#define PMIC_SER_RTC_PWRUP_TIMER2_ADDR(base) ((base) + (0x374))
#define PMIC_SER_RTC_PWRUP_TIMER3_ADDR(base) ((base) + (0x375))
#define PMIC_SER_RTC_PWRDOWN_TIMER0_ADDR(base) ((base) + (0x376))
#define PMIC_SER_RTC_PWRDOWN_TIMER1_ADDR(base) ((base) + (0x377))
#define PMIC_SER_RTC_PWRDOWN_TIMER2_ADDR(base) ((base) + (0x378))
#define PMIC_SER_RTC_PWRDOWN_TIMER3_ADDR(base) ((base) + (0x379))
#endif
#ifndef __SOC_H_FOR_ASM__
#define PMIC_COUL_IRQ_ADDR(base) ((base) + (0x380UL))
#define PMIC_COUL_IRQ_MASK_ADDR(base) ((base) + (0x381UL))
#define PMIC_CURRENT_0_ADDR(base) ((base) + (0x382UL))
#define PMIC_CURRENT_1_ADDR(base) ((base) + (0x383UL))
#define PMIC_V_OUT_0_ADDR(base) ((base) + (0x384UL))
#define PMIC_V_OUT_1_ADDR(base) ((base) + (0x385UL))
#define PMIC_CLJ_CTRL_REG_ADDR(base) ((base) + (0x386UL))
#define PMIC_ECO_REFALSH_TIME_ADDR(base) ((base) + (0x387UL))
#define PMIC_CL_OUT0_ADDR(base) ((base) + (0x388UL))
#define PMIC_CL_OUT1_ADDR(base) ((base) + (0x389UL))
#define PMIC_CL_OUT2_ADDR(base) ((base) + (0x38AUL))
#define PMIC_CL_OUT3_ADDR(base) ((base) + (0x38BUL))
#define PMIC_CL_IN0_ADDR(base) ((base) + (0x38CUL))
#define PMIC_CL_IN1_ADDR(base) ((base) + (0x38DUL))
#define PMIC_CL_IN2_ADDR(base) ((base) + (0x38EUL))
#define PMIC_CL_IN3_ADDR(base) ((base) + (0x38FUL))
#define PMIC_CHG_TIMER0_ADDR(base) ((base) + (0x390UL))
#define PMIC_CHG_TIMER1_ADDR(base) ((base) + (0x391UL))
#define PMIC_CHG_TIMER2_ADDR(base) ((base) + (0x392UL))
#define PMIC_CHG_TIMER3_ADDR(base) ((base) + (0x393UL))
#define PMIC_LOAD_TIMER0_ADDR(base) ((base) + (0x394UL))
#define PMIC_LOAD_TIMER1_ADDR(base) ((base) + (0x395UL))
#define PMIC_LOAD_TIMER2_ADDR(base) ((base) + (0x396UL))
#define PMIC_LOAD_TIMER3_ADDR(base) ((base) + (0x397UL))
#define PMIC_CL_INT0_ADDR(base) ((base) + (0x398UL))
#define PMIC_CL_INT1_ADDR(base) ((base) + (0x399UL))
#define PMIC_CL_INT2_ADDR(base) ((base) + (0x39AUL))
#define PMIC_CL_INT3_ADDR(base) ((base) + (0x39BUL))
#define PMIC_V_INT0_ADDR(base) ((base) + (0x39CUL))
#define PMIC_V_INT1_ADDR(base) ((base) + (0x39DUL))
#define PMIC_OFFSET_CURRENT0_ADDR(base) ((base) + (0x39EUL))
#define PMIC_OFFSET_CURRENT1_ADDR(base) ((base) + (0x39FUL))
#define PMIC_OFFSET_VOLTAGE0_ADDR(base) ((base) + (0x3A0UL))
#define PMIC_OFFSET_VOLTAGE1_ADDR(base) ((base) + (0x3A1UL))
#define PMIC_OCV_VOLTAGE0_ADDR(base) ((base) + (0x3A2UL))
#define PMIC_OCV_VOLTAGE1_ADDR(base) ((base) + (0x3A3UL))
#define PMIC_OCV_CURRENT0_ADDR(base) ((base) + (0x3A4UL))
#define PMIC_OCV_CURRENT1_ADDR(base) ((base) + (0x3A5UL))
#define PMIC_ECO_OUT_CLIN_0_ADDR(base) ((base) + (0x3A6UL))
#define PMIC_ECO_OUT_CLIN_1_ADDR(base) ((base) + (0x3A7UL))
#define PMIC_ECO_OUT_CLIN_2_ADDR(base) ((base) + (0x3A8UL))
#define PMIC_ECO_OUT_CLIN_3_ADDR(base) ((base) + (0x3A9UL))
#define PMIC_ECO_OUT_CLOUT_0_ADDR(base) ((base) + (0x3AAUL))
#define PMIC_ECO_OUT_CLOUT_1_ADDR(base) ((base) + (0x3ABUL))
#define PMIC_ECO_OUT_CLOUT_2_ADDR(base) ((base) + (0x3ACUL))
#define PMIC_ECO_OUT_CLOUT_3_ADDR(base) ((base) + (0x3ADUL))
#define PMIC_V_OUT0_PRE0_ADDR(base) ((base) + (0x3AEUL))
#define PMIC_V_OUT1_PRE0_ADDR(base) ((base) + (0x3AFUL))
#define PMIC_V_OUT0_PRE1_ADDR(base) ((base) + (0x3B0UL))
#define PMIC_V_OUT1_PRE1_ADDR(base) ((base) + (0x3B1UL))
#define PMIC_V_OUT0_PRE2_ADDR(base) ((base) + (0x3B2UL))
#define PMIC_V_OUT1_PRE2_ADDR(base) ((base) + (0x3B3UL))
#define PMIC_V_OUT0_PRE3_ADDR(base) ((base) + (0x3B4UL))
#define PMIC_V_OUT1_PRE3_ADDR(base) ((base) + (0x3B5UL))
#define PMIC_V_OUT0_PRE4_ADDR(base) ((base) + (0x3B6UL))
#define PMIC_V_OUT1_PRE4_ADDR(base) ((base) + (0x3B7UL))
#define PMIC_V_OUT0_PRE5_ADDR(base) ((base) + (0x3B8UL))
#define PMIC_V_OUT1_PRE5_ADDR(base) ((base) + (0x3B9UL))
#define PMIC_V_OUT0_PRE6_ADDR(base) ((base) + (0x3BAUL))
#define PMIC_V_OUT1_PRE6_ADDR(base) ((base) + (0x3BBUL))
#define PMIC_V_OUT0_PRE7_ADDR(base) ((base) + (0x3BCUL))
#define PMIC_V_OUT1_PRE7_ADDR(base) ((base) + (0x3BDUL))
#define PMIC_V_OUT0_PRE8_ADDR(base) ((base) + (0x3BEUL))
#define PMIC_V_OUT1_PRE8_ADDR(base) ((base) + (0x3BFUL))
#define PMIC_V_OUT0_PRE9_ADDR(base) ((base) + (0x3C0UL))
#define PMIC_V_OUT1_PRE9_ADDR(base) ((base) + (0x3C1UL))
#define PMIC_CURRENT0_PRE0_ADDR(base) ((base) + (0x3C2UL))
#define PMIC_CURRENT1_PRE0_ADDR(base) ((base) + (0x3C3UL))
#define PMIC_CURRENT0_PRE1_ADDR(base) ((base) + (0x3C4UL))
#define PMIC_CURRENT1_PRE1_ADDR(base) ((base) + (0x3C5UL))
#define PMIC_CURRENT0_PRE2_ADDR(base) ((base) + (0x3C6UL))
#define PMIC_CURRENT1_PRE2_ADDR(base) ((base) + (0x3C7UL))
#define PMIC_CURRENT0_PRE3_ADDR(base) ((base) + (0x3C8UL))
#define PMIC_CURRENT1_PRE3_ADDR(base) ((base) + (0x3C9UL))
#define PMIC_CURRENT0_PRE4_ADDR(base) ((base) + (0x3CAUL))
#define PMIC_CURRENT1_PRE4_ADDR(base) ((base) + (0x3CBUL))
#define PMIC_CURRENT0_PRE5_ADDR(base) ((base) + (0x3CCUL))
#define PMIC_CURRENT1_PRE5_ADDR(base) ((base) + (0x3CDUL))
#define PMIC_CURRENT0_PRE6_ADDR(base) ((base) + (0x3CEUL))
#define PMIC_CURRENT1_PRE6_ADDR(base) ((base) + (0x3CFUL))
#define PMIC_CURRENT0_PRE7_ADDR(base) ((base) + (0x3D0UL))
#define PMIC_CURRENT1_PRE7_ADDR(base) ((base) + (0x3D1UL))
#define PMIC_CURRENT0_PRE8_ADDR(base) ((base) + (0x3D2UL))
#define PMIC_CURRENT1_PRE8_ADDR(base) ((base) + (0x3D3UL))
#define PMIC_CURRENT0_PRE9_ADDR(base) ((base) + (0x3D4UL))
#define PMIC_CURRENT1_PRE9_ADDR(base) ((base) + (0x3D5UL))
#define PMIC_OFFSET_CURRENT_MOD_0_ADDR(base) ((base) + (0x3D6UL))
#define PMIC_OFFSET_CURRENT_MOD_1_ADDR(base) ((base) + (0x3D7UL))
#define PMIC_OFFSET_VOLTAGE_MOD_0_ADDR(base) ((base) + (0x3D8UL))
#define PMIC_OFFSET_VOLTAGE_MOD_1_ADDR(base) ((base) + (0x3D9UL))
#define PMIC_COUL_RESERVE0_ADDR(base) ((base) + (0x3DAUL))
#define PMIC_CLJ_RESERVED0_ADDR(base) ((base) + (0x3DBUL))
#define PMIC_CLJ_RESERVED1_ADDR(base) ((base) + (0x3DCUL))
#define PMIC_CLJ_RESERVED2_ADDR(base) ((base) + (0x3DDUL))
#define PMIC_CLJ_DEBUG_ADDR(base) ((base) + (0x3DEUL))
#define PMIC_CLJ_DEBUG_2_ADDR(base) ((base) + (0x3DFUL))
#define PMIC_STATE_TEST_ADDR(base) ((base) + (0x3E0UL))
#define PMIC_CLJ_CTRL_REGS2_ADDR(base) ((base) + (0x3E1UL))
#define PMIC_DEBUG_WRITE_PRO_ADDR(base) ((base) + (0x3E2UL))
#else
#define PMIC_COUL_IRQ_ADDR(base) ((base) + (0x380))
#define PMIC_COUL_IRQ_MASK_ADDR(base) ((base) + (0x381))
#define PMIC_CURRENT_0_ADDR(base) ((base) + (0x382))
#define PMIC_CURRENT_1_ADDR(base) ((base) + (0x383))
#define PMIC_V_OUT_0_ADDR(base) ((base) + (0x384))
#define PMIC_V_OUT_1_ADDR(base) ((base) + (0x385))
#define PMIC_CLJ_CTRL_REG_ADDR(base) ((base) + (0x386))
#define PMIC_ECO_REFALSH_TIME_ADDR(base) ((base) + (0x387))
#define PMIC_CL_OUT0_ADDR(base) ((base) + (0x388))
#define PMIC_CL_OUT1_ADDR(base) ((base) + (0x389))
#define PMIC_CL_OUT2_ADDR(base) ((base) + (0x38A))
#define PMIC_CL_OUT3_ADDR(base) ((base) + (0x38B))
#define PMIC_CL_IN0_ADDR(base) ((base) + (0x38C))
#define PMIC_CL_IN1_ADDR(base) ((base) + (0x38D))
#define PMIC_CL_IN2_ADDR(base) ((base) + (0x38E))
#define PMIC_CL_IN3_ADDR(base) ((base) + (0x38F))
#define PMIC_CHG_TIMER0_ADDR(base) ((base) + (0x390))
#define PMIC_CHG_TIMER1_ADDR(base) ((base) + (0x391))
#define PMIC_CHG_TIMER2_ADDR(base) ((base) + (0x392))
#define PMIC_CHG_TIMER3_ADDR(base) ((base) + (0x393))
#define PMIC_LOAD_TIMER0_ADDR(base) ((base) + (0x394))
#define PMIC_LOAD_TIMER1_ADDR(base) ((base) + (0x395))
#define PMIC_LOAD_TIMER2_ADDR(base) ((base) + (0x396))
#define PMIC_LOAD_TIMER3_ADDR(base) ((base) + (0x397))
#define PMIC_CL_INT0_ADDR(base) ((base) + (0x398))
#define PMIC_CL_INT1_ADDR(base) ((base) + (0x399))
#define PMIC_CL_INT2_ADDR(base) ((base) + (0x39A))
#define PMIC_CL_INT3_ADDR(base) ((base) + (0x39B))
#define PMIC_V_INT0_ADDR(base) ((base) + (0x39C))
#define PMIC_V_INT1_ADDR(base) ((base) + (0x39D))
#define PMIC_OFFSET_CURRENT0_ADDR(base) ((base) + (0x39E))
#define PMIC_OFFSET_CURRENT1_ADDR(base) ((base) + (0x39F))
#define PMIC_OFFSET_VOLTAGE0_ADDR(base) ((base) + (0x3A0))
#define PMIC_OFFSET_VOLTAGE1_ADDR(base) ((base) + (0x3A1))
#define PMIC_OCV_VOLTAGE0_ADDR(base) ((base) + (0x3A2))
#define PMIC_OCV_VOLTAGE1_ADDR(base) ((base) + (0x3A3))
#define PMIC_OCV_CURRENT0_ADDR(base) ((base) + (0x3A4))
#define PMIC_OCV_CURRENT1_ADDR(base) ((base) + (0x3A5))
#define PMIC_ECO_OUT_CLIN_0_ADDR(base) ((base) + (0x3A6))
#define PMIC_ECO_OUT_CLIN_1_ADDR(base) ((base) + (0x3A7))
#define PMIC_ECO_OUT_CLIN_2_ADDR(base) ((base) + (0x3A8))
#define PMIC_ECO_OUT_CLIN_3_ADDR(base) ((base) + (0x3A9))
#define PMIC_ECO_OUT_CLOUT_0_ADDR(base) ((base) + (0x3AA))
#define PMIC_ECO_OUT_CLOUT_1_ADDR(base) ((base) + (0x3AB))
#define PMIC_ECO_OUT_CLOUT_2_ADDR(base) ((base) + (0x3AC))
#define PMIC_ECO_OUT_CLOUT_3_ADDR(base) ((base) + (0x3AD))
#define PMIC_V_OUT0_PRE0_ADDR(base) ((base) + (0x3AE))
#define PMIC_V_OUT1_PRE0_ADDR(base) ((base) + (0x3AF))
#define PMIC_V_OUT0_PRE1_ADDR(base) ((base) + (0x3B0))
#define PMIC_V_OUT1_PRE1_ADDR(base) ((base) + (0x3B1))
#define PMIC_V_OUT0_PRE2_ADDR(base) ((base) + (0x3B2))
#define PMIC_V_OUT1_PRE2_ADDR(base) ((base) + (0x3B3))
#define PMIC_V_OUT0_PRE3_ADDR(base) ((base) + (0x3B4))
#define PMIC_V_OUT1_PRE3_ADDR(base) ((base) + (0x3B5))
#define PMIC_V_OUT0_PRE4_ADDR(base) ((base) + (0x3B6))
#define PMIC_V_OUT1_PRE4_ADDR(base) ((base) + (0x3B7))
#define PMIC_V_OUT0_PRE5_ADDR(base) ((base) + (0x3B8))
#define PMIC_V_OUT1_PRE5_ADDR(base) ((base) + (0x3B9))
#define PMIC_V_OUT0_PRE6_ADDR(base) ((base) + (0x3BA))
#define PMIC_V_OUT1_PRE6_ADDR(base) ((base) + (0x3BB))
#define PMIC_V_OUT0_PRE7_ADDR(base) ((base) + (0x3BC))
#define PMIC_V_OUT1_PRE7_ADDR(base) ((base) + (0x3BD))
#define PMIC_V_OUT0_PRE8_ADDR(base) ((base) + (0x3BE))
#define PMIC_V_OUT1_PRE8_ADDR(base) ((base) + (0x3BF))
#define PMIC_V_OUT0_PRE9_ADDR(base) ((base) + (0x3C0))
#define PMIC_V_OUT1_PRE9_ADDR(base) ((base) + (0x3C1))
#define PMIC_CURRENT0_PRE0_ADDR(base) ((base) + (0x3C2))
#define PMIC_CURRENT1_PRE0_ADDR(base) ((base) + (0x3C3))
#define PMIC_CURRENT0_PRE1_ADDR(base) ((base) + (0x3C4))
#define PMIC_CURRENT1_PRE1_ADDR(base) ((base) + (0x3C5))
#define PMIC_CURRENT0_PRE2_ADDR(base) ((base) + (0x3C6))
#define PMIC_CURRENT1_PRE2_ADDR(base) ((base) + (0x3C7))
#define PMIC_CURRENT0_PRE3_ADDR(base) ((base) + (0x3C8))
#define PMIC_CURRENT1_PRE3_ADDR(base) ((base) + (0x3C9))
#define PMIC_CURRENT0_PRE4_ADDR(base) ((base) + (0x3CA))
#define PMIC_CURRENT1_PRE4_ADDR(base) ((base) + (0x3CB))
#define PMIC_CURRENT0_PRE5_ADDR(base) ((base) + (0x3CC))
#define PMIC_CURRENT1_PRE5_ADDR(base) ((base) + (0x3CD))
#define PMIC_CURRENT0_PRE6_ADDR(base) ((base) + (0x3CE))
#define PMIC_CURRENT1_PRE6_ADDR(base) ((base) + (0x3CF))
#define PMIC_CURRENT0_PRE7_ADDR(base) ((base) + (0x3D0))
#define PMIC_CURRENT1_PRE7_ADDR(base) ((base) + (0x3D1))
#define PMIC_CURRENT0_PRE8_ADDR(base) ((base) + (0x3D2))
#define PMIC_CURRENT1_PRE8_ADDR(base) ((base) + (0x3D3))
#define PMIC_CURRENT0_PRE9_ADDR(base) ((base) + (0x3D4))
#define PMIC_CURRENT1_PRE9_ADDR(base) ((base) + (0x3D5))
#define PMIC_OFFSET_CURRENT_MOD_0_ADDR(base) ((base) + (0x3D6))
#define PMIC_OFFSET_CURRENT_MOD_1_ADDR(base) ((base) + (0x3D7))
#define PMIC_OFFSET_VOLTAGE_MOD_0_ADDR(base) ((base) + (0x3D8))
#define PMIC_OFFSET_VOLTAGE_MOD_1_ADDR(base) ((base) + (0x3D9))
#define PMIC_COUL_RESERVE0_ADDR(base) ((base) + (0x3DA))
#define PMIC_CLJ_RESERVED0_ADDR(base) ((base) + (0x3DB))
#define PMIC_CLJ_RESERVED1_ADDR(base) ((base) + (0x3DC))
#define PMIC_CLJ_RESERVED2_ADDR(base) ((base) + (0x3DD))
#define PMIC_CLJ_DEBUG_ADDR(base) ((base) + (0x3DE))
#define PMIC_CLJ_DEBUG_2_ADDR(base) ((base) + (0x3DF))
#define PMIC_STATE_TEST_ADDR(base) ((base) + (0x3E0))
#define PMIC_CLJ_CTRL_REGS2_ADDR(base) ((base) + (0x3E1))
#define PMIC_DEBUG_WRITE_PRO_ADDR(base) ((base) + (0x3E2))
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char project_num0 : 8;
    } reg;
} PMIC_VERSION0_UNION;
#endif
#define PMIC_VERSION0_project_num0_START (0)
#define PMIC_VERSION0_project_num0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char project_num1 : 8;
    } reg;
} PMIC_VERSION1_UNION;
#endif
#define PMIC_VERSION1_project_num1_START (0)
#define PMIC_VERSION1_project_num1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char project_num2 : 8;
    } reg;
} PMIC_VERSION2_UNION;
#endif
#define PMIC_VERSION2_project_num2_START (0)
#define PMIC_VERSION2_project_num2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char project_num3 : 8;
    } reg;
} PMIC_VERSION3_UNION;
#endif
#define PMIC_VERSION3_project_num3_START (0)
#define PMIC_VERSION3_project_num3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char version : 8;
    } reg;
} PMIC_VERSION4_UNION;
#endif
#define PMIC_VERSION4_version_START (0)
#define PMIC_VERSION4_version_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char chip_id : 8;
    } reg;
} PMIC_VERSION5_UNION;
#endif
#define PMIC_VERSION5_chip_id_START (0)
#define PMIC_VERSION5_chip_id_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char st_vsys_ov_d200ur : 1;
        unsigned char st_vbus_det_insert_d20m : 1;
        unsigned char st_vsys_pwroff_abs_d20nr : 1;
        unsigned char st_vsys_pwroff_deb_d80mr : 1;
        unsigned char st_vsys_pwron_d60ur : 1;
        unsigned char st_thsd_otmp140_d1mr : 1;
        unsigned char st_thsd_otmp125_d1mr : 1;
        unsigned char st_pwron_d20m : 1;
    } reg;
} PMIC_STATUS0_UNION;
#endif
#define PMIC_STATUS0_st_vsys_ov_d200ur_START (0)
#define PMIC_STATUS0_st_vsys_ov_d200ur_END (0)
#define PMIC_STATUS0_st_vbus_det_insert_d20m_START (1)
#define PMIC_STATUS0_st_vbus_det_insert_d20m_END (1)
#define PMIC_STATUS0_st_vsys_pwroff_abs_d20nr_START (2)
#define PMIC_STATUS0_st_vsys_pwroff_abs_d20nr_END (2)
#define PMIC_STATUS0_st_vsys_pwroff_deb_d80mr_START (3)
#define PMIC_STATUS0_st_vsys_pwroff_deb_d80mr_END (3)
#define PMIC_STATUS0_st_vsys_pwron_d60ur_START (4)
#define PMIC_STATUS0_st_vsys_pwron_d60ur_END (4)
#define PMIC_STATUS0_st_thsd_otmp140_d1mr_START (5)
#define PMIC_STATUS0_st_thsd_otmp140_d1mr_END (5)
#define PMIC_STATUS0_st_thsd_otmp125_d1mr_START (6)
#define PMIC_STATUS0_st_thsd_otmp125_d1mr_END (6)
#define PMIC_STATUS0_st_pwron_d20m_START (7)
#define PMIC_STATUS0_st_pwron_d20m_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char st_fast_pwron_sel : 1;
        unsigned char st_ddr_voltage_sel : 1;
        unsigned char st_default_voltage_sel : 1;
        unsigned char st_spmi_ssi_sel : 1;
        unsigned char st_dcxo_clk_sel : 1;
        unsigned char st_sim0_hpd_d540u : 1;
        unsigned char st_sim1_hpd_d540u : 1;
        unsigned char st_avdd_osc_vld_d20nf : 1;
    } reg;
} PMIC_STATUS1_UNION;
#endif
#define PMIC_STATUS1_st_fast_pwron_sel_START (0)
#define PMIC_STATUS1_st_fast_pwron_sel_END (0)
#define PMIC_STATUS1_st_ddr_voltage_sel_START (1)
#define PMIC_STATUS1_st_ddr_voltage_sel_END (1)
#define PMIC_STATUS1_st_default_voltage_sel_START (2)
#define PMIC_STATUS1_st_default_voltage_sel_END (2)
#define PMIC_STATUS1_st_spmi_ssi_sel_START (3)
#define PMIC_STATUS1_st_spmi_ssi_sel_END (3)
#define PMIC_STATUS1_st_dcxo_clk_sel_START (4)
#define PMIC_STATUS1_st_dcxo_clk_sel_END (4)
#define PMIC_STATUS1_st_sim0_hpd_d540u_START (5)
#define PMIC_STATUS1_st_sim0_hpd_d540u_END (5)
#define PMIC_STATUS1_st_sim1_hpd_d540u_START (6)
#define PMIC_STATUS1_st_sim1_hpd_d540u_END (6)
#define PMIC_STATUS1_st_avdd_osc_vld_d20nf_START (7)
#define PMIC_STATUS1_st_avdd_osc_vld_d20nf_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_buck0_en : 1;
        unsigned char st_buck0_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_BUCK0_ONOFF_ECO_UNION;
#endif
#define PMIC_BUCK0_ONOFF_ECO_reg_buck0_en_START (0)
#define PMIC_BUCK0_ONOFF_ECO_reg_buck0_en_END (0)
#define PMIC_BUCK0_ONOFF_ECO_st_buck0_en_START (1)
#define PMIC_BUCK0_ONOFF_ECO_st_buck0_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_buck1_en : 1;
        unsigned char st_buck1_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_buck1_eco_en : 1;
        unsigned char st_buck1_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} PMIC_BUCK1_ONOFF_ECO_UNION;
#endif
#define PMIC_BUCK1_ONOFF_ECO_reg_buck1_en_START (0)
#define PMIC_BUCK1_ONOFF_ECO_reg_buck1_en_END (0)
#define PMIC_BUCK1_ONOFF_ECO_st_buck1_en_START (1)
#define PMIC_BUCK1_ONOFF_ECO_st_buck1_en_END (1)
#define PMIC_BUCK1_ONOFF_ECO_reg_buck1_eco_en_START (4)
#define PMIC_BUCK1_ONOFF_ECO_reg_buck1_eco_en_END (4)
#define PMIC_BUCK1_ONOFF_ECO_st_buck1_eco_en_START (5)
#define PMIC_BUCK1_ONOFF_ECO_st_buck1_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_buck2_en : 1;
        unsigned char st_buck2_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_buck2_eco_en : 1;
        unsigned char st_buck2_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} PMIC_BUCK2_ONOFF_ECO_UNION;
#endif
#define PMIC_BUCK2_ONOFF_ECO_reg_buck2_en_START (0)
#define PMIC_BUCK2_ONOFF_ECO_reg_buck2_en_END (0)
#define PMIC_BUCK2_ONOFF_ECO_st_buck2_en_START (1)
#define PMIC_BUCK2_ONOFF_ECO_st_buck2_en_END (1)
#define PMIC_BUCK2_ONOFF_ECO_reg_buck2_eco_en_START (4)
#define PMIC_BUCK2_ONOFF_ECO_reg_buck2_eco_en_END (4)
#define PMIC_BUCK2_ONOFF_ECO_st_buck2_eco_en_START (5)
#define PMIC_BUCK2_ONOFF_ECO_st_buck2_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_buck3_en : 1;
        unsigned char st_buck3_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_buck3_eco_en : 1;
        unsigned char st_buck3_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} PMIC_BUCK3_ONOFF_ECO_UNION;
#endif
#define PMIC_BUCK3_ONOFF_ECO_reg_buck3_en_START (0)
#define PMIC_BUCK3_ONOFF_ECO_reg_buck3_en_END (0)
#define PMIC_BUCK3_ONOFF_ECO_st_buck3_en_START (1)
#define PMIC_BUCK3_ONOFF_ECO_st_buck3_en_END (1)
#define PMIC_BUCK3_ONOFF_ECO_reg_buck3_eco_en_START (4)
#define PMIC_BUCK3_ONOFF_ECO_reg_buck3_eco_en_END (4)
#define PMIC_BUCK3_ONOFF_ECO_st_buck3_eco_en_START (5)
#define PMIC_BUCK3_ONOFF_ECO_st_buck3_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_buck4_en : 1;
        unsigned char st_buck4_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_BUCK4_ONOFF_ECO_UNION;
#endif
#define PMIC_BUCK4_ONOFF_ECO_reg_buck4_en_START (0)
#define PMIC_BUCK4_ONOFF_ECO_reg_buck4_en_END (0)
#define PMIC_BUCK4_ONOFF_ECO_st_buck4_en_START (1)
#define PMIC_BUCK4_ONOFF_ECO_st_buck4_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_buck5_en : 1;
        unsigned char st_buck5_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_BUCK5_ONOFF_ECO_UNION;
#endif
#define PMIC_BUCK5_ONOFF_ECO_reg_buck5_en_START (0)
#define PMIC_BUCK5_ONOFF_ECO_reg_buck5_en_END (0)
#define PMIC_BUCK5_ONOFF_ECO_st_buck5_en_START (1)
#define PMIC_BUCK5_ONOFF_ECO_st_buck5_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_buck6_en : 1;
        unsigned char st_buck6_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_BUCK6_ONOFF_ECO_UNION;
#endif
#define PMIC_BUCK6_ONOFF_ECO_reg_buck6_en_START (0)
#define PMIC_BUCK6_ONOFF_ECO_reg_buck6_en_END (0)
#define PMIC_BUCK6_ONOFF_ECO_st_buck6_en_START (1)
#define PMIC_BUCK6_ONOFF_ECO_st_buck6_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_buck7_en : 1;
        unsigned char st_buck7_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_buck7_eco_en : 1;
        unsigned char st_buck7_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} PMIC_BUCK7_ONOFF_ECO_UNION;
#endif
#define PMIC_BUCK7_ONOFF_ECO_reg_buck7_en_START (0)
#define PMIC_BUCK7_ONOFF_ECO_reg_buck7_en_END (0)
#define PMIC_BUCK7_ONOFF_ECO_st_buck7_en_START (1)
#define PMIC_BUCK7_ONOFF_ECO_st_buck7_en_END (1)
#define PMIC_BUCK7_ONOFF_ECO_reg_buck7_eco_en_START (4)
#define PMIC_BUCK7_ONOFF_ECO_reg_buck7_eco_en_END (4)
#define PMIC_BUCK7_ONOFF_ECO_st_buck7_eco_en_START (5)
#define PMIC_BUCK7_ONOFF_ECO_st_buck7_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_buck8_en : 1;
        unsigned char st_buck8_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_buck8_eco_en : 1;
        unsigned char st_buck8_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} PMIC_BUCK8_ONOFF_ECO_UNION;
#endif
#define PMIC_BUCK8_ONOFF_ECO_reg_buck8_en_START (0)
#define PMIC_BUCK8_ONOFF_ECO_reg_buck8_en_END (0)
#define PMIC_BUCK8_ONOFF_ECO_st_buck8_en_START (1)
#define PMIC_BUCK8_ONOFF_ECO_st_buck8_en_END (1)
#define PMIC_BUCK8_ONOFF_ECO_reg_buck8_eco_en_START (4)
#define PMIC_BUCK8_ONOFF_ECO_reg_buck8_eco_en_END (4)
#define PMIC_BUCK8_ONOFF_ECO_st_buck8_eco_en_START (5)
#define PMIC_BUCK8_ONOFF_ECO_st_buck8_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo0_1_en : 1;
        unsigned char st_ldo0_1_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO0_1_ONOFF_UNION;
#endif
#define PMIC_LDO0_1_ONOFF_reg_ldo0_1_en_START (0)
#define PMIC_LDO0_1_ONOFF_reg_ldo0_1_en_END (0)
#define PMIC_LDO0_1_ONOFF_st_ldo0_1_en_START (1)
#define PMIC_LDO0_1_ONOFF_st_ldo0_1_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo0_2_en : 1;
        unsigned char st_ldo0_2_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_ldo0_2_eco_en : 1;
        unsigned char st_ldo0_2_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} PMIC_LDO0_2_ONOFF_ECO_UNION;
#endif
#define PMIC_LDO0_2_ONOFF_ECO_reg_ldo0_2_en_START (0)
#define PMIC_LDO0_2_ONOFF_ECO_reg_ldo0_2_en_END (0)
#define PMIC_LDO0_2_ONOFF_ECO_st_ldo0_2_en_START (1)
#define PMIC_LDO0_2_ONOFF_ECO_st_ldo0_2_en_END (1)
#define PMIC_LDO0_2_ONOFF_ECO_reg_ldo0_2_eco_en_START (4)
#define PMIC_LDO0_2_ONOFF_ECO_reg_ldo0_2_eco_en_END (4)
#define PMIC_LDO0_2_ONOFF_ECO_st_ldo0_2_eco_en_START (5)
#define PMIC_LDO0_2_ONOFF_ECO_st_ldo0_2_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo1_en : 1;
        unsigned char st_ldo1_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO1_ONOFF_UNION;
#endif
#define PMIC_LDO1_ONOFF_reg_ldo1_en_START (0)
#define PMIC_LDO1_ONOFF_reg_ldo1_en_END (0)
#define PMIC_LDO1_ONOFF_st_ldo1_en_START (1)
#define PMIC_LDO1_ONOFF_st_ldo1_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo2_en_a : 1;
        unsigned char st_ldo2_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO2_ONOFF1_UNION;
#endif
#define PMIC_LDO2_ONOFF1_reg_ldo2_en_a_START (0)
#define PMIC_LDO2_ONOFF1_reg_ldo2_en_a_END (0)
#define PMIC_LDO2_ONOFF1_st_ldo2_en_START (1)
#define PMIC_LDO2_ONOFF1_st_ldo2_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo2_en_b : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_LDO2_ONOFF2_UNION;
#endif
#define PMIC_LDO2_ONOFF2_reg_ldo2_en_b_START (0)
#define PMIC_LDO2_ONOFF2_reg_ldo2_en_b_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo3_en : 1;
        unsigned char st_ldo3_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO3_ONOFF_UNION;
#endif
#define PMIC_LDO3_ONOFF_reg_ldo3_en_START (0)
#define PMIC_LDO3_ONOFF_reg_ldo3_en_END (0)
#define PMIC_LDO3_ONOFF_st_ldo3_en_START (1)
#define PMIC_LDO3_ONOFF_st_ldo3_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo4_en : 1;
        unsigned char st_ldo4_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_ldo4_eco_en : 1;
        unsigned char st_ldo4_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} PMIC_LDO4_ONOFF_ECO_UNION;
#endif
#define PMIC_LDO4_ONOFF_ECO_reg_ldo4_en_START (0)
#define PMIC_LDO4_ONOFF_ECO_reg_ldo4_en_END (0)
#define PMIC_LDO4_ONOFF_ECO_st_ldo4_en_START (1)
#define PMIC_LDO4_ONOFF_ECO_st_ldo4_en_END (1)
#define PMIC_LDO4_ONOFF_ECO_reg_ldo4_eco_en_START (4)
#define PMIC_LDO4_ONOFF_ECO_reg_ldo4_eco_en_END (4)
#define PMIC_LDO4_ONOFF_ECO_st_ldo4_eco_en_START (5)
#define PMIC_LDO4_ONOFF_ECO_st_ldo4_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo5_en : 1;
        unsigned char st_ldo5_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO5_ONOFF_UNION;
#endif
#define PMIC_LDO5_ONOFF_reg_ldo5_en_START (0)
#define PMIC_LDO5_ONOFF_reg_ldo5_en_END (0)
#define PMIC_LDO5_ONOFF_st_ldo5_en_START (1)
#define PMIC_LDO5_ONOFF_st_ldo5_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo6_en : 1;
        unsigned char st_ldo6_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO6_ONOFF_UNION;
#endif
#define PMIC_LDO6_ONOFF_reg_ldo6_en_START (0)
#define PMIC_LDO6_ONOFF_reg_ldo6_en_END (0)
#define PMIC_LDO6_ONOFF_st_ldo6_en_START (1)
#define PMIC_LDO6_ONOFF_st_ldo6_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo7_en : 1;
        unsigned char st_ldo7_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO7_ONOFF_UNION;
#endif
#define PMIC_LDO7_ONOFF_reg_ldo7_en_START (0)
#define PMIC_LDO7_ONOFF_reg_ldo7_en_END (0)
#define PMIC_LDO7_ONOFF_st_ldo7_en_START (1)
#define PMIC_LDO7_ONOFF_st_ldo7_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo8_en : 1;
        unsigned char st_ldo8_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_ldo8_eco_en : 1;
        unsigned char st_ldo8_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} PMIC_LDO8_ONOFF_ECO_UNION;
#endif
#define PMIC_LDO8_ONOFF_ECO_reg_ldo8_en_START (0)
#define PMIC_LDO8_ONOFF_ECO_reg_ldo8_en_END (0)
#define PMIC_LDO8_ONOFF_ECO_st_ldo8_en_START (1)
#define PMIC_LDO8_ONOFF_ECO_st_ldo8_en_END (1)
#define PMIC_LDO8_ONOFF_ECO_reg_ldo8_eco_en_START (4)
#define PMIC_LDO8_ONOFF_ECO_reg_ldo8_eco_en_END (4)
#define PMIC_LDO8_ONOFF_ECO_st_ldo8_eco_en_START (5)
#define PMIC_LDO8_ONOFF_ECO_st_ldo8_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo9_en : 1;
        unsigned char st_ldo9_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_ldo9_eco_en : 1;
        unsigned char st_ldo9_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} PMIC_LDO9_ONOFF_ECO_UNION;
#endif
#define PMIC_LDO9_ONOFF_ECO_reg_ldo9_en_START (0)
#define PMIC_LDO9_ONOFF_ECO_reg_ldo9_en_END (0)
#define PMIC_LDO9_ONOFF_ECO_st_ldo9_en_START (1)
#define PMIC_LDO9_ONOFF_ECO_st_ldo9_en_END (1)
#define PMIC_LDO9_ONOFF_ECO_reg_ldo9_eco_en_START (4)
#define PMIC_LDO9_ONOFF_ECO_reg_ldo9_eco_en_END (4)
#define PMIC_LDO9_ONOFF_ECO_st_ldo9_eco_en_START (5)
#define PMIC_LDO9_ONOFF_ECO_st_ldo9_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo11_en : 1;
        unsigned char st_ldo11_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_ldo11_eco_en : 1;
        unsigned char st_ldo11_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} PMIC_LDO11_ONOFF_ECO_UNION;
#endif
#define PMIC_LDO11_ONOFF_ECO_reg_ldo11_en_START (0)
#define PMIC_LDO11_ONOFF_ECO_reg_ldo11_en_END (0)
#define PMIC_LDO11_ONOFF_ECO_st_ldo11_en_START (1)
#define PMIC_LDO11_ONOFF_ECO_st_ldo11_en_END (1)
#define PMIC_LDO11_ONOFF_ECO_reg_ldo11_eco_en_START (4)
#define PMIC_LDO11_ONOFF_ECO_reg_ldo11_eco_en_END (4)
#define PMIC_LDO11_ONOFF_ECO_st_ldo11_eco_en_START (5)
#define PMIC_LDO11_ONOFF_ECO_st_ldo11_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo12_en : 1;
        unsigned char st_ldo12_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_ldo12_eco_en : 1;
        unsigned char st_ldo12_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} PMIC_LDO12_ONOFF_ECO_UNION;
#endif
#define PMIC_LDO12_ONOFF_ECO_reg_ldo12_en_START (0)
#define PMIC_LDO12_ONOFF_ECO_reg_ldo12_en_END (0)
#define PMIC_LDO12_ONOFF_ECO_st_ldo12_en_START (1)
#define PMIC_LDO12_ONOFF_ECO_st_ldo12_en_END (1)
#define PMIC_LDO12_ONOFF_ECO_reg_ldo12_eco_en_START (4)
#define PMIC_LDO12_ONOFF_ECO_reg_ldo12_eco_en_END (4)
#define PMIC_LDO12_ONOFF_ECO_st_ldo12_eco_en_START (5)
#define PMIC_LDO12_ONOFF_ECO_st_ldo12_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo13_en : 1;
        unsigned char st_ldo13_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO13_ONOFF_UNION;
#endif
#define PMIC_LDO13_ONOFF_reg_ldo13_en_START (0)
#define PMIC_LDO13_ONOFF_reg_ldo13_en_END (0)
#define PMIC_LDO13_ONOFF_st_ldo13_en_START (1)
#define PMIC_LDO13_ONOFF_st_ldo13_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo14_en : 1;
        unsigned char st_ldo14_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO14_ONOFF_UNION;
#endif
#define PMIC_LDO14_ONOFF_reg_ldo14_en_START (0)
#define PMIC_LDO14_ONOFF_reg_ldo14_en_END (0)
#define PMIC_LDO14_ONOFF_st_ldo14_en_START (1)
#define PMIC_LDO14_ONOFF_st_ldo14_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo15_en : 1;
        unsigned char st_ldo15_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_ldo15_eco_en : 1;
        unsigned char st_ldo15_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} PMIC_LDO15_ONOFF_ECO_UNION;
#endif
#define PMIC_LDO15_ONOFF_ECO_reg_ldo15_en_START (0)
#define PMIC_LDO15_ONOFF_ECO_reg_ldo15_en_END (0)
#define PMIC_LDO15_ONOFF_ECO_st_ldo15_en_START (1)
#define PMIC_LDO15_ONOFF_ECO_st_ldo15_en_END (1)
#define PMIC_LDO15_ONOFF_ECO_reg_ldo15_eco_en_START (4)
#define PMIC_LDO15_ONOFF_ECO_reg_ldo15_eco_en_END (4)
#define PMIC_LDO15_ONOFF_ECO_st_ldo15_eco_en_START (5)
#define PMIC_LDO15_ONOFF_ECO_st_ldo15_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo16_en : 1;
        unsigned char st_ldo16_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_ldo16_eco_en : 1;
        unsigned char st_ldo16_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} PMIC_LDO16_ONOFF_ECO_UNION;
#endif
#define PMIC_LDO16_ONOFF_ECO_reg_ldo16_en_START (0)
#define PMIC_LDO16_ONOFF_ECO_reg_ldo16_en_END (0)
#define PMIC_LDO16_ONOFF_ECO_st_ldo16_en_START (1)
#define PMIC_LDO16_ONOFF_ECO_st_ldo16_en_END (1)
#define PMIC_LDO16_ONOFF_ECO_reg_ldo16_eco_en_START (4)
#define PMIC_LDO16_ONOFF_ECO_reg_ldo16_eco_en_END (4)
#define PMIC_LDO16_ONOFF_ECO_st_ldo16_eco_en_START (5)
#define PMIC_LDO16_ONOFF_ECO_st_ldo16_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo17_en : 1;
        unsigned char st_ldo17_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_ldo17_eco_en : 1;
        unsigned char st_ldo17_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} PMIC_LDO17_ONOFF_ECO_UNION;
#endif
#define PMIC_LDO17_ONOFF_ECO_reg_ldo17_en_START (0)
#define PMIC_LDO17_ONOFF_ECO_reg_ldo17_en_END (0)
#define PMIC_LDO17_ONOFF_ECO_st_ldo17_en_START (1)
#define PMIC_LDO17_ONOFF_ECO_st_ldo17_en_END (1)
#define PMIC_LDO17_ONOFF_ECO_reg_ldo17_eco_en_START (4)
#define PMIC_LDO17_ONOFF_ECO_reg_ldo17_eco_en_END (4)
#define PMIC_LDO17_ONOFF_ECO_st_ldo17_eco_en_START (5)
#define PMIC_LDO17_ONOFF_ECO_st_ldo17_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo18_en : 1;
        unsigned char st_ldo18_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_ldo18_eco_en : 1;
        unsigned char st_ldo18_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} PMIC_LDO18_ONOFF_ECO_UNION;
#endif
#define PMIC_LDO18_ONOFF_ECO_reg_ldo18_en_START (0)
#define PMIC_LDO18_ONOFF_ECO_reg_ldo18_en_END (0)
#define PMIC_LDO18_ONOFF_ECO_st_ldo18_en_START (1)
#define PMIC_LDO18_ONOFF_ECO_st_ldo18_en_END (1)
#define PMIC_LDO18_ONOFF_ECO_reg_ldo18_eco_en_START (4)
#define PMIC_LDO18_ONOFF_ECO_reg_ldo18_eco_en_END (4)
#define PMIC_LDO18_ONOFF_ECO_st_ldo18_eco_en_START (5)
#define PMIC_LDO18_ONOFF_ECO_st_ldo18_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo19_en : 1;
        unsigned char st_ldo19_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO19_ONOFF_UNION;
#endif
#define PMIC_LDO19_ONOFF_reg_ldo19_en_START (0)
#define PMIC_LDO19_ONOFF_reg_ldo19_en_END (0)
#define PMIC_LDO19_ONOFF_st_ldo19_en_START (1)
#define PMIC_LDO19_ONOFF_st_ldo19_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo20_en : 1;
        unsigned char st_ldo20_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO20_ONOFF_UNION;
#endif
#define PMIC_LDO20_ONOFF_reg_ldo20_en_START (0)
#define PMIC_LDO20_ONOFF_reg_ldo20_en_END (0)
#define PMIC_LDO20_ONOFF_st_ldo20_en_START (1)
#define PMIC_LDO20_ONOFF_st_ldo20_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo21_en : 1;
        unsigned char st_ldo21_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO21_ONOFF_UNION;
#endif
#define PMIC_LDO21_ONOFF_reg_ldo21_en_START (0)
#define PMIC_LDO21_ONOFF_reg_ldo21_en_END (0)
#define PMIC_LDO21_ONOFF_st_ldo21_en_START (1)
#define PMIC_LDO21_ONOFF_st_ldo21_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo22_en : 1;
        unsigned char st_ldo22_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO22_ONOFF_UNION;
#endif
#define PMIC_LDO22_ONOFF_reg_ldo22_en_START (0)
#define PMIC_LDO22_ONOFF_reg_ldo22_en_END (0)
#define PMIC_LDO22_ONOFF_st_ldo22_en_START (1)
#define PMIC_LDO22_ONOFF_st_ldo22_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo23_en : 1;
        unsigned char st_ldo23_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO23_ONOFF_UNION;
#endif
#define PMIC_LDO23_ONOFF_reg_ldo23_en_START (0)
#define PMIC_LDO23_ONOFF_reg_ldo23_en_END (0)
#define PMIC_LDO23_ONOFF_st_ldo23_en_START (1)
#define PMIC_LDO23_ONOFF_st_ldo23_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo24_en : 1;
        unsigned char st_ldo24_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_ldo24_eco_en : 1;
        unsigned char st_ldo24_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} PMIC_LDO24_ONOFF_ECO_UNION;
#endif
#define PMIC_LDO24_ONOFF_ECO_reg_ldo24_en_START (0)
#define PMIC_LDO24_ONOFF_ECO_reg_ldo24_en_END (0)
#define PMIC_LDO24_ONOFF_ECO_st_ldo24_en_START (1)
#define PMIC_LDO24_ONOFF_ECO_st_ldo24_en_END (1)
#define PMIC_LDO24_ONOFF_ECO_reg_ldo24_eco_en_START (4)
#define PMIC_LDO24_ONOFF_ECO_reg_ldo24_eco_en_END (4)
#define PMIC_LDO24_ONOFF_ECO_st_ldo24_eco_en_START (5)
#define PMIC_LDO24_ONOFF_ECO_st_ldo24_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo25_en : 1;
        unsigned char st_ldo25_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO25_ONOFF_UNION;
#endif
#define PMIC_LDO25_ONOFF_reg_ldo25_en_START (0)
#define PMIC_LDO25_ONOFF_reg_ldo25_en_END (0)
#define PMIC_LDO25_ONOFF_st_ldo25_en_START (1)
#define PMIC_LDO25_ONOFF_st_ldo25_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo26_en : 1;
        unsigned char st_ldo26_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_ldo26_eco_en : 1;
        unsigned char st_ldo26_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} PMIC_LDO26_ONOFF_ECO_UNION;
#endif
#define PMIC_LDO26_ONOFF_ECO_reg_ldo26_en_START (0)
#define PMIC_LDO26_ONOFF_ECO_reg_ldo26_en_END (0)
#define PMIC_LDO26_ONOFF_ECO_st_ldo26_en_START (1)
#define PMIC_LDO26_ONOFF_ECO_st_ldo26_en_END (1)
#define PMIC_LDO26_ONOFF_ECO_reg_ldo26_eco_en_START (4)
#define PMIC_LDO26_ONOFF_ECO_reg_ldo26_eco_en_END (4)
#define PMIC_LDO26_ONOFF_ECO_st_ldo26_eco_en_START (5)
#define PMIC_LDO26_ONOFF_ECO_st_ldo26_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo27_en : 1;
        unsigned char st_ldo27_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO27_ONOFF_UNION;
#endif
#define PMIC_LDO27_ONOFF_reg_ldo27_en_START (0)
#define PMIC_LDO27_ONOFF_reg_ldo27_en_END (0)
#define PMIC_LDO27_ONOFF_st_ldo27_en_START (1)
#define PMIC_LDO27_ONOFF_st_ldo27_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo28_en : 1;
        unsigned char st_ldo28_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO28_ONOFF_UNION;
#endif
#define PMIC_LDO28_ONOFF_reg_ldo28_en_START (0)
#define PMIC_LDO28_ONOFF_reg_ldo28_en_END (0)
#define PMIC_LDO28_ONOFF_st_ldo28_en_START (1)
#define PMIC_LDO28_ONOFF_st_ldo28_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo29_en : 1;
        unsigned char st_ldo29_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_ldo29_eco_en : 1;
        unsigned char st_ldo29_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} PMIC_LDO29_ONOFF_ECO_UNION;
#endif
#define PMIC_LDO29_ONOFF_ECO_reg_ldo29_en_START (0)
#define PMIC_LDO29_ONOFF_ECO_reg_ldo29_en_END (0)
#define PMIC_LDO29_ONOFF_ECO_st_ldo29_en_START (1)
#define PMIC_LDO29_ONOFF_ECO_st_ldo29_en_END (1)
#define PMIC_LDO29_ONOFF_ECO_reg_ldo29_eco_en_START (4)
#define PMIC_LDO29_ONOFF_ECO_reg_ldo29_eco_en_END (4)
#define PMIC_LDO29_ONOFF_ECO_st_ldo29_eco_en_START (5)
#define PMIC_LDO29_ONOFF_ECO_st_ldo29_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo30_en : 1;
        unsigned char st_ldo30_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO30_ONOFF_UNION;
#endif
#define PMIC_LDO30_ONOFF_reg_ldo30_en_START (0)
#define PMIC_LDO30_ONOFF_reg_ldo30_en_END (0)
#define PMIC_LDO30_ONOFF_st_ldo30_en_START (1)
#define PMIC_LDO30_ONOFF_st_ldo30_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo32_en : 1;
        unsigned char st_ldo32_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO32_ONOFF_UNION;
#endif
#define PMIC_LDO32_ONOFF_reg_ldo32_en_START (0)
#define PMIC_LDO32_ONOFF_reg_ldo32_en_END (0)
#define PMIC_LDO32_ONOFF_st_ldo32_en_START (1)
#define PMIC_LDO32_ONOFF_st_ldo32_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo33_en : 1;
        unsigned char st_ldo33_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO33_ONOFF_UNION;
#endif
#define PMIC_LDO33_ONOFF_reg_ldo33_en_START (0)
#define PMIC_LDO33_ONOFF_reg_ldo33_en_END (0)
#define PMIC_LDO33_ONOFF_st_ldo33_en_START (1)
#define PMIC_LDO33_ONOFF_st_ldo33_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo34_en : 1;
        unsigned char st_ldo34_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO34_ONOFF_UNION;
#endif
#define PMIC_LDO34_ONOFF_reg_ldo34_en_START (0)
#define PMIC_LDO34_ONOFF_reg_ldo34_en_END (0)
#define PMIC_LDO34_ONOFF_st_ldo34_en_START (1)
#define PMIC_LDO34_ONOFF_st_ldo34_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo35_en : 1;
        unsigned char st_ldo35_en : 1;
        unsigned char reserved_0 : 2;
        unsigned char reg_ldo35_eco_en : 1;
        unsigned char st_ldo35_eco_en : 1;
        unsigned char reserved_1 : 2;
    } reg;
} PMIC_LDO35_ONOFF_ECO_UNION;
#endif
#define PMIC_LDO35_ONOFF_ECO_reg_ldo35_en_START (0)
#define PMIC_LDO35_ONOFF_ECO_reg_ldo35_en_END (0)
#define PMIC_LDO35_ONOFF_ECO_st_ldo35_en_START (1)
#define PMIC_LDO35_ONOFF_ECO_st_ldo35_en_END (1)
#define PMIC_LDO35_ONOFF_ECO_reg_ldo35_eco_en_START (4)
#define PMIC_LDO35_ONOFF_ECO_reg_ldo35_eco_en_END (4)
#define PMIC_LDO35_ONOFF_ECO_st_ldo35_eco_en_START (5)
#define PMIC_LDO35_ONOFF_ECO_st_ldo35_eco_en_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo36_en : 1;
        unsigned char st_ldo36_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO36_ONOFF_UNION;
#endif
#define PMIC_LDO36_ONOFF_reg_ldo36_en_START (0)
#define PMIC_LDO36_ONOFF_reg_ldo36_en_END (0)
#define PMIC_LDO36_ONOFF_st_ldo36_en_START (1)
#define PMIC_LDO36_ONOFF_st_ldo36_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char st_pmua_en : 1;
        unsigned char reserved : 3;
        unsigned char reg_pmua_eco_en : 1;
        unsigned char st_pmua_eco_en : 1;
        unsigned char reg_thsd_eco_en : 1;
        unsigned char st_thsd_eco_en : 1;
    } reg;
} PMIC_LDO_PMUA_ECO_UNION;
#endif
#define PMIC_LDO_PMUA_ECO_st_pmua_en_START (0)
#define PMIC_LDO_PMUA_ECO_st_pmua_en_END (0)
#define PMIC_LDO_PMUA_ECO_reg_pmua_eco_en_START (4)
#define PMIC_LDO_PMUA_ECO_reg_pmua_eco_en_END (4)
#define PMIC_LDO_PMUA_ECO_st_pmua_eco_en_START (5)
#define PMIC_LDO_PMUA_ECO_st_pmua_eco_en_END (5)
#define PMIC_LDO_PMUA_ECO_reg_thsd_eco_en_START (6)
#define PMIC_LDO_PMUA_ECO_reg_thsd_eco_en_END (6)
#define PMIC_LDO_PMUA_ECO_st_thsd_eco_en_START (7)
#define PMIC_LDO_PMUA_ECO_st_thsd_eco_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_xo_abb_en : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_CLK_ABB_EN_UNION;
#endif
#define PMIC_CLK_ABB_EN_reg_xo_abb_en_START (0)
#define PMIC_CLK_ABB_EN_reg_xo_abb_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_xo_wifi_en : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_CLK_WIFI1_EN_UNION;
#endif
#define PMIC_CLK_WIFI1_EN_reg_xo_wifi_en_START (0)
#define PMIC_CLK_WIFI1_EN_reg_xo_wifi_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_xo_nfc_en : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_CLK_NFC_EN_UNION;
#endif
#define PMIC_CLK_NFC_EN_reg_xo_nfc_en_START (0)
#define PMIC_CLK_NFC_EN_reg_xo_nfc_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xo_rf0_en : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_CLK_RF0_EN_UNION;
#endif
#define PMIC_CLK_RF0_EN_xo_rf0_en_START (0)
#define PMIC_CLK_RF0_EN_xo_rf0_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xo_rf1_en : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_CLK_RF1_EN_UNION;
#endif
#define PMIC_CLK_RF1_EN_xo_rf1_en_START (0)
#define PMIC_CLK_RF1_EN_xo_rf1_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_xo_sys_usb_en : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_CLK_SYS_USB_EN_UNION;
#endif
#define PMIC_CLK_SYS_USB_EN_reg_xo_sys_usb_en_START (0)
#define PMIC_CLK_SYS_USB_EN_reg_xo_sys_usb_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_xo_codec_en : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_CLK_CODEC_EN_UNION;
#endif
#define PMIC_CLK_CODEC_EN_reg_xo_codec_en_START (0)
#define PMIC_CLK_CODEC_EN_reg_xo_codec_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char en_32k_gps : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_OSC32K_GPS_ONOFF_CTRL_UNION;
#endif
#define PMIC_OSC32K_GPS_ONOFF_CTRL_en_32k_gps_START (0)
#define PMIC_OSC32K_GPS_ONOFF_CTRL_en_32k_gps_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char en_32k_bt : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_OSC32K_BT_ONOFF_CTRL_UNION;
#endif
#define PMIC_OSC32K_BT_ONOFF_CTRL_en_32k_bt_START (0)
#define PMIC_OSC32K_BT_ONOFF_CTRL_en_32k_bt_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char en_32k_sys : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_OSC32K_SYS_ONOFF_CTRL_UNION;
#endif
#define PMIC_OSC32K_SYS_ONOFF_CTRL_en_32k_sys_START (0)
#define PMIC_OSC32K_SYS_ONOFF_CTRL_en_32k_sys_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck0_vset : 6;
        unsigned char reserved : 2;
    } reg;
} PMIC_BUCK0_VSET_UNION;
#endif
#define PMIC_BUCK0_VSET_buck0_vset_START (0)
#define PMIC_BUCK0_VSET_buck0_vset_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck0_vset_eco : 6;
        unsigned char reserved : 2;
    } reg;
} PMIC_BUCK0_VSET_ECO_UNION;
#endif
#define PMIC_BUCK0_VSET_ECO_buck0_vset_eco_START (0)
#define PMIC_BUCK0_VSET_ECO_buck0_vset_eco_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck1_vset : 5;
        unsigned char reserved : 3;
    } reg;
} PMIC_BUCK1_VSET_UNION;
#endif
#define PMIC_BUCK1_VSET_buck1_vset_START (0)
#define PMIC_BUCK1_VSET_buck1_vset_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck2_vset : 5;
        unsigned char reserved : 3;
    } reg;
} PMIC_BUCK2_VSET_UNION;
#endif
#define PMIC_BUCK2_VSET_buck2_vset_START (0)
#define PMIC_BUCK2_VSET_buck2_vset_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck2_vset_eco : 5;
        unsigned char reserved : 3;
    } reg;
} PMIC_BUCK2_VSET_ECO_UNION;
#endif
#define PMIC_BUCK2_VSET_ECO_buck2_vset_eco_START (0)
#define PMIC_BUCK2_VSET_ECO_buck2_vset_eco_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck3_vset : 5;
        unsigned char reserved : 3;
    } reg;
} PMIC_BUCK3_VSET_UNION;
#endif
#define PMIC_BUCK3_VSET_buck3_vset_START (0)
#define PMIC_BUCK3_VSET_buck3_vset_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck3_vset_eco : 5;
        unsigned char reserved : 3;
    } reg;
} PMIC_BUCK3_VSET_ECO_UNION;
#endif
#define PMIC_BUCK3_VSET_ECO_buck3_vset_eco_START (0)
#define PMIC_BUCK3_VSET_ECO_buck3_vset_eco_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck4_vset : 6;
        unsigned char reserved : 2;
    } reg;
} PMIC_BUCK4_VSET_UNION;
#endif
#define PMIC_BUCK4_VSET_buck4_vset_START (0)
#define PMIC_BUCK4_VSET_buck4_vset_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck5_vset : 6;
        unsigned char reserved : 2;
    } reg;
} PMIC_BUCK5_VSET_UNION;
#endif
#define PMIC_BUCK5_VSET_buck5_vset_START (0)
#define PMIC_BUCK5_VSET_buck5_vset_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck6_vset : 6;
        unsigned char reserved : 2;
    } reg;
} PMIC_BUCK6_VSET_UNION;
#endif
#define PMIC_BUCK6_VSET_buck6_vset_START (0)
#define PMIC_BUCK6_VSET_buck6_vset_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck7_vset : 6;
        unsigned char reserved : 2;
    } reg;
} PMIC_BUCK7_VSET_UNION;
#endif
#define PMIC_BUCK7_VSET_buck7_vset_START (0)
#define PMIC_BUCK7_VSET_buck7_vset_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck8_vset : 5;
        unsigned char reserved : 3;
    } reg;
} PMIC_BUCK8_VSET_UNION;
#endif
#define PMIC_BUCK8_VSET_buck8_vset_START (0)
#define PMIC_BUCK8_VSET_buck8_vset_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck8_vset_eco : 5;
        unsigned char reserved : 3;
    } reg;
} PMIC_BUCK8_VSET_ECO_UNION;
#endif
#define PMIC_BUCK8_VSET_ECO_buck8_vset_eco_START (0)
#define PMIC_BUCK8_VSET_ECO_buck8_vset_eco_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo0_2_vset : 3;
        unsigned char reserved_0 : 1;
        unsigned char ldo0_2_vset_eco : 3;
        unsigned char reserved_1 : 1;
    } reg;
} PMIC_LDO0_2_VSET_UNION;
#endif
#define PMIC_LDO0_2_VSET_ldo0_2_vset_START (0)
#define PMIC_LDO0_2_VSET_ldo0_2_vset_END (2)
#define PMIC_LDO0_2_VSET_ldo0_2_vset_eco_START (4)
#define PMIC_LDO0_2_VSET_ldo0_2_vset_eco_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo1_vset : 4;
        unsigned char reserved : 4;
    } reg;
} PMIC_LDO1_VSET_UNION;
#endif
#define PMIC_LDO1_VSET_ldo1_vset_START (0)
#define PMIC_LDO1_VSET_ldo1_vset_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo2_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO2_VSET_UNION;
#endif
#define PMIC_LDO2_VSET_ldo2_vset_START (0)
#define PMIC_LDO2_VSET_ldo2_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo3_vset : 4;
        unsigned char reserved : 4;
    } reg;
} PMIC_LDO3_VSET_UNION;
#endif
#define PMIC_LDO3_VSET_ldo3_vset_START (0)
#define PMIC_LDO3_VSET_ldo3_vset_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo4_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO4_VSET_UNION;
#endif
#define PMIC_LDO4_VSET_ldo4_vset_START (0)
#define PMIC_LDO4_VSET_ldo4_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo5_vset : 4;
        unsigned char reserved : 4;
    } reg;
} PMIC_LDO5_VSET_UNION;
#endif
#define PMIC_LDO5_VSET_ldo5_vset_START (0)
#define PMIC_LDO5_VSET_ldo5_vset_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo6_vset : 4;
        unsigned char reserved : 4;
    } reg;
} PMIC_LDO6_VSET_UNION;
#endif
#define PMIC_LDO6_VSET_ldo6_vset_START (0)
#define PMIC_LDO6_VSET_ldo6_vset_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo7_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO7_VSET_UNION;
#endif
#define PMIC_LDO7_VSET_ldo7_vset_START (0)
#define PMIC_LDO7_VSET_ldo7_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo8_vset : 4;
        unsigned char reserved : 4;
    } reg;
} PMIC_LDO8_VSET_UNION;
#endif
#define PMIC_LDO8_VSET_ldo8_vset_START (0)
#define PMIC_LDO8_VSET_ldo8_vset_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo9_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO9_VSET_UNION;
#endif
#define PMIC_LDO9_VSET_ldo9_vset_START (0)
#define PMIC_LDO9_VSET_ldo9_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo11_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO11_VSET_UNION;
#endif
#define PMIC_LDO11_VSET_ldo11_vset_START (0)
#define PMIC_LDO11_VSET_ldo11_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo12_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO12_VSET_UNION;
#endif
#define PMIC_LDO12_VSET_ldo12_vset_START (0)
#define PMIC_LDO12_VSET_ldo12_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo13_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO13_VSET_UNION;
#endif
#define PMIC_LDO13_VSET_ldo13_vset_START (0)
#define PMIC_LDO13_VSET_ldo13_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo14_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO14_VSET_UNION;
#endif
#define PMIC_LDO14_VSET_ldo14_vset_START (0)
#define PMIC_LDO14_VSET_ldo14_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo15_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO15_VSET_UNION;
#endif
#define PMIC_LDO15_VSET_ldo15_vset_START (0)
#define PMIC_LDO15_VSET_ldo15_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo16_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO16_VSET_UNION;
#endif
#define PMIC_LDO16_VSET_ldo16_vset_START (0)
#define PMIC_LDO16_VSET_ldo16_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo17_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO17_VSET_UNION;
#endif
#define PMIC_LDO17_VSET_ldo17_vset_START (0)
#define PMIC_LDO17_VSET_ldo17_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo18_vset : 4;
        unsigned char reserved : 4;
    } reg;
} PMIC_LDO18_VSET_UNION;
#endif
#define PMIC_LDO18_VSET_ldo18_vset_START (0)
#define PMIC_LDO18_VSET_ldo18_vset_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo19_vset : 4;
        unsigned char reserved : 4;
    } reg;
} PMIC_LDO19_VSET1_UNION;
#endif
#define PMIC_LDO19_VSET1_ldo19_vset_START (0)
#define PMIC_LDO19_VSET1_ldo19_vset_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo20_vset : 4;
        unsigned char reserved : 4;
    } reg;
} PMIC_LDO20_VSET_UNION;
#endif
#define PMIC_LDO20_VSET_ldo20_vset_START (0)
#define PMIC_LDO20_VSET_ldo20_vset_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo21_vset : 4;
        unsigned char reserved : 4;
    } reg;
} PMIC_LDO21_VSET_UNION;
#endif
#define PMIC_LDO21_VSET_ldo21_vset_START (0)
#define PMIC_LDO21_VSET_ldo21_vset_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo22_vset : 4;
        unsigned char reserved : 4;
    } reg;
} PMIC_LDO22_VSET_UNION;
#endif
#define PMIC_LDO22_VSET_ldo22_vset_START (0)
#define PMIC_LDO22_VSET_ldo22_vset_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo23_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO23_VSET_UNION;
#endif
#define PMIC_LDO23_VSET_ldo23_vset_START (0)
#define PMIC_LDO23_VSET_ldo23_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo24_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO24_VSET_UNION;
#endif
#define PMIC_LDO24_VSET_ldo24_vset_START (0)
#define PMIC_LDO24_VSET_ldo24_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo25_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO25_VSET_UNION;
#endif
#define PMIC_LDO25_VSET_ldo25_vset_START (0)
#define PMIC_LDO25_VSET_ldo25_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo26_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO26_VSET_UNION;
#endif
#define PMIC_LDO26_VSET_ldo26_vset_START (0)
#define PMIC_LDO26_VSET_ldo26_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo27_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO27_VSET_UNION;
#endif
#define PMIC_LDO27_VSET_ldo27_vset_START (0)
#define PMIC_LDO27_VSET_ldo27_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo28_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO28_VSET_UNION;
#endif
#define PMIC_LDO28_VSET_ldo28_vset_START (0)
#define PMIC_LDO28_VSET_ldo28_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo29_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO29_VSET_UNION;
#endif
#define PMIC_LDO29_VSET_ldo29_vset_START (0)
#define PMIC_LDO29_VSET_ldo29_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo30_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO30_VSET_UNION;
#endif
#define PMIC_LDO30_VSET_ldo30_vset_START (0)
#define PMIC_LDO30_VSET_ldo30_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo32_vset : 4;
        unsigned char reserved : 4;
    } reg;
} PMIC_LDO32_VSET_UNION;
#endif
#define PMIC_LDO32_VSET_ldo32_vset_START (0)
#define PMIC_LDO32_VSET_ldo32_vset_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo33_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO33_VSET_UNION;
#endif
#define PMIC_LDO33_VSET_ldo33_vset_START (0)
#define PMIC_LDO33_VSET_ldo33_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo34_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO34_VSET_UNION;
#endif
#define PMIC_LDO34_VSET_ldo34_vset_START (0)
#define PMIC_LDO34_VSET_ldo34_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo35_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO35_VSET_UNION;
#endif
#define PMIC_LDO35_VSET_ldo35_vset_START (0)
#define PMIC_LDO35_VSET_ldo35_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo36_vset : 2;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO36_VSET_UNION;
#endif
#define PMIC_LDO36_VSET_ldo36_vset_START (0)
#define PMIC_LDO36_VSET_ldo36_vset_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo_buf_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO_BUF_VSET_UNION;
#endif
#define PMIC_LDO_BUF_VSET_ldo_buf_vset_START (0)
#define PMIC_LDO_BUF_VSET_ldo_buf_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pmua_vset : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_LDO_PMUA_VSET_UNION;
#endif
#define PMIC_LDO_PMUA_VSET_pmua_vset_START (0)
#define PMIC_LDO_PMUA_VSET_pmua_vset_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck0_dbias : 4;
        unsigned char buck0_adj_rlx : 4;
    } reg;
} PMIC_BUCK0_CTRL0_UNION;
#endif
#define PMIC_BUCK0_CTRL0_buck0_dbias_START (0)
#define PMIC_BUCK0_CTRL0_buck0_dbias_END (3)
#define PMIC_BUCK0_CTRL0_buck0_adj_rlx_START (4)
#define PMIC_BUCK0_CTRL0_buck0_adj_rlx_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck0_ng_dt_sel : 1;
        unsigned char buck0_pg_dt_sel : 1;
        unsigned char buck0_nmos_switch : 1;
        unsigned char reserved : 1;
        unsigned char buck0_dt_sel : 2;
        unsigned char buck0_ocp_sel : 2;
    } reg;
} PMIC_BUCK0_CTRL1_UNION;
#endif
#define PMIC_BUCK0_CTRL1_buck0_ng_dt_sel_START (0)
#define PMIC_BUCK0_CTRL1_buck0_ng_dt_sel_END (0)
#define PMIC_BUCK0_CTRL1_buck0_pg_dt_sel_START (1)
#define PMIC_BUCK0_CTRL1_buck0_pg_dt_sel_END (1)
#define PMIC_BUCK0_CTRL1_buck0_nmos_switch_START (2)
#define PMIC_BUCK0_CTRL1_buck0_nmos_switch_END (2)
#define PMIC_BUCK0_CTRL1_buck0_dt_sel_START (4)
#define PMIC_BUCK0_CTRL1_buck0_dt_sel_END (5)
#define PMIC_BUCK0_CTRL1_buck0_ocp_sel_START (6)
#define PMIC_BUCK0_CTRL1_buck0_ocp_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck0_ng_n_sel : 2;
        unsigned char buck0_ng_p_sel : 2;
        unsigned char buck0_pg_n_sel : 2;
        unsigned char buck0_pg_p_sel : 2;
    } reg;
} PMIC_BUCK0_CTRL2_UNION;
#endif
#define PMIC_BUCK0_CTRL2_buck0_ng_n_sel_START (0)
#define PMIC_BUCK0_CTRL2_buck0_ng_n_sel_END (1)
#define PMIC_BUCK0_CTRL2_buck0_ng_p_sel_START (2)
#define PMIC_BUCK0_CTRL2_buck0_ng_p_sel_END (3)
#define PMIC_BUCK0_CTRL2_buck0_pg_n_sel_START (4)
#define PMIC_BUCK0_CTRL2_buck0_pg_n_sel_END (5)
#define PMIC_BUCK0_CTRL2_buck0_pg_p_sel_START (6)
#define PMIC_BUCK0_CTRL2_buck0_pg_p_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck0_reg_r : 2;
        unsigned char reserved : 2;
        unsigned char buck0_reg_en : 1;
        unsigned char buck0_adj_clx : 2;
        unsigned char buck0_ocp_dis : 1;
    } reg;
} PMIC_BUCK0_CTRL3_UNION;
#endif
#define PMIC_BUCK0_CTRL3_buck0_reg_r_START (0)
#define PMIC_BUCK0_CTRL3_buck0_reg_r_END (1)
#define PMIC_BUCK0_CTRL3_buck0_reg_en_START (4)
#define PMIC_BUCK0_CTRL3_buck0_reg_en_END (4)
#define PMIC_BUCK0_CTRL3_buck0_adj_clx_START (5)
#define PMIC_BUCK0_CTRL3_buck0_adj_clx_END (6)
#define PMIC_BUCK0_CTRL3_buck0_ocp_dis_START (7)
#define PMIC_BUCK0_CTRL3_buck0_ocp_dis_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck0_short_pdp : 1;
        unsigned char buck0_reg_ss : 1;
        unsigned char buck0_regop_c : 1;
        unsigned char buck0_filter_ton : 2;
        unsigned char buck0_reg_dr : 3;
    } reg;
} PMIC_BUCK0_CTRL4_UNION;
#endif
#define PMIC_BUCK0_CTRL4_buck0_short_pdp_START (0)
#define PMIC_BUCK0_CTRL4_buck0_short_pdp_END (0)
#define PMIC_BUCK0_CTRL4_buck0_reg_ss_START (1)
#define PMIC_BUCK0_CTRL4_buck0_reg_ss_END (1)
#define PMIC_BUCK0_CTRL4_buck0_regop_c_START (2)
#define PMIC_BUCK0_CTRL4_buck0_regop_c_END (2)
#define PMIC_BUCK0_CTRL4_buck0_filter_ton_START (3)
#define PMIC_BUCK0_CTRL4_buck0_filter_ton_END (4)
#define PMIC_BUCK0_CTRL4_buck0_reg_dr_START (5)
#define PMIC_BUCK0_CTRL4_buck0_reg_dr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck0_ton : 3;
        unsigned char buck0_eco_ng : 1;
        unsigned char buck0_reg_bias : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_BUCK0_CTRL5_UNION;
#endif
#define PMIC_BUCK0_CTRL5_buck0_ton_START (0)
#define PMIC_BUCK0_CTRL5_buck0_ton_END (2)
#define PMIC_BUCK0_CTRL5_buck0_eco_ng_START (3)
#define PMIC_BUCK0_CTRL5_buck0_eco_ng_END (3)
#define PMIC_BUCK0_CTRL5_buck0_reg_bias_START (4)
#define PMIC_BUCK0_CTRL5_buck0_reg_bias_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck0_dmd_ton : 3;
        unsigned char buck0_ocp_toff : 2;
        unsigned char buck0_dmd_sel : 3;
    } reg;
} PMIC_BUCK0_CTRL6_UNION;
#endif
#define PMIC_BUCK0_CTRL6_buck0_dmd_ton_START (0)
#define PMIC_BUCK0_CTRL6_buck0_dmd_ton_END (2)
#define PMIC_BUCK0_CTRL6_buck0_ocp_toff_START (3)
#define PMIC_BUCK0_CTRL6_buck0_ocp_toff_END (4)
#define PMIC_BUCK0_CTRL6_buck0_dmd_sel_START (5)
#define PMIC_BUCK0_CTRL6_buck0_dmd_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck0_ton_dmd : 1;
        unsigned char buck0_eco_dmd : 1;
        unsigned char buck0_cmp_filter : 1;
        unsigned char buck0_ocp_delay : 1;
        unsigned char buck0_dmd_clamp : 1;
        unsigned char buck0_regop_clamp : 1;
        unsigned char reserved : 2;
    } reg;
} PMIC_BUCK0_CTRL7_UNION;
#endif
#define PMIC_BUCK0_CTRL7_buck0_ton_dmd_START (0)
#define PMIC_BUCK0_CTRL7_buck0_ton_dmd_END (0)
#define PMIC_BUCK0_CTRL7_buck0_eco_dmd_START (1)
#define PMIC_BUCK0_CTRL7_buck0_eco_dmd_END (1)
#define PMIC_BUCK0_CTRL7_buck0_cmp_filter_START (2)
#define PMIC_BUCK0_CTRL7_buck0_cmp_filter_END (2)
#define PMIC_BUCK0_CTRL7_buck0_ocp_delay_START (3)
#define PMIC_BUCK0_CTRL7_buck0_ocp_delay_END (3)
#define PMIC_BUCK0_CTRL7_buck0_dmd_clamp_START (4)
#define PMIC_BUCK0_CTRL7_buck0_dmd_clamp_END (4)
#define PMIC_BUCK0_CTRL7_buck0_regop_clamp_START (5)
#define PMIC_BUCK0_CTRL7_buck0_regop_clamp_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck0_reserve : 8;
    } reg;
} PMIC_BUCK0_CTRL8_UNION;
#endif
#define PMIC_BUCK0_CTRL8_buck0_reserve_START (0)
#define PMIC_BUCK0_CTRL8_buck0_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck1_dbias : 4;
        unsigned char buck1_adj_rlx : 4;
    } reg;
} PMIC_BUCK1_CTRL0_UNION;
#endif
#define PMIC_BUCK1_CTRL0_buck1_dbias_START (0)
#define PMIC_BUCK1_CTRL0_buck1_dbias_END (3)
#define PMIC_BUCK1_CTRL0_buck1_adj_rlx_START (4)
#define PMIC_BUCK1_CTRL0_buck1_adj_rlx_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck1_ng_dt_sel : 1;
        unsigned char buck1_pg_dt_sel : 1;
        unsigned char buck1_nmos_switch : 1;
        unsigned char reserved : 1;
        unsigned char buck1_dt_sel : 2;
        unsigned char buck1_ocp_sel : 2;
    } reg;
} PMIC_BUCK1_CTRL1_UNION;
#endif
#define PMIC_BUCK1_CTRL1_buck1_ng_dt_sel_START (0)
#define PMIC_BUCK1_CTRL1_buck1_ng_dt_sel_END (0)
#define PMIC_BUCK1_CTRL1_buck1_pg_dt_sel_START (1)
#define PMIC_BUCK1_CTRL1_buck1_pg_dt_sel_END (1)
#define PMIC_BUCK1_CTRL1_buck1_nmos_switch_START (2)
#define PMIC_BUCK1_CTRL1_buck1_nmos_switch_END (2)
#define PMIC_BUCK1_CTRL1_buck1_dt_sel_START (4)
#define PMIC_BUCK1_CTRL1_buck1_dt_sel_END (5)
#define PMIC_BUCK1_CTRL1_buck1_ocp_sel_START (6)
#define PMIC_BUCK1_CTRL1_buck1_ocp_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck1_ng_n_sel : 2;
        unsigned char buck1_ng_p_sel : 2;
        unsigned char buck1_pg_n_sel : 2;
        unsigned char buck1_pg_p_sel : 2;
    } reg;
} PMIC_BUCK1_CTRL2_UNION;
#endif
#define PMIC_BUCK1_CTRL2_buck1_ng_n_sel_START (0)
#define PMIC_BUCK1_CTRL2_buck1_ng_n_sel_END (1)
#define PMIC_BUCK1_CTRL2_buck1_ng_p_sel_START (2)
#define PMIC_BUCK1_CTRL2_buck1_ng_p_sel_END (3)
#define PMIC_BUCK1_CTRL2_buck1_pg_n_sel_START (4)
#define PMIC_BUCK1_CTRL2_buck1_pg_n_sel_END (5)
#define PMIC_BUCK1_CTRL2_buck1_pg_p_sel_START (6)
#define PMIC_BUCK1_CTRL2_buck1_pg_p_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck1_reg_r : 2;
        unsigned char reserved : 2;
        unsigned char buck1_reg_en : 1;
        unsigned char buck1_adj_clx : 2;
        unsigned char buck1_ocp_dis : 1;
    } reg;
} PMIC_BUCK1_CTRL3_UNION;
#endif
#define PMIC_BUCK1_CTRL3_buck1_reg_r_START (0)
#define PMIC_BUCK1_CTRL3_buck1_reg_r_END (1)
#define PMIC_BUCK1_CTRL3_buck1_reg_en_START (4)
#define PMIC_BUCK1_CTRL3_buck1_reg_en_END (4)
#define PMIC_BUCK1_CTRL3_buck1_adj_clx_START (5)
#define PMIC_BUCK1_CTRL3_buck1_adj_clx_END (6)
#define PMIC_BUCK1_CTRL3_buck1_ocp_dis_START (7)
#define PMIC_BUCK1_CTRL3_buck1_ocp_dis_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck1_short_pdp : 1;
        unsigned char buck1_reg_ss : 1;
        unsigned char buck1_regop_c : 1;
        unsigned char buck1_filter_ton : 2;
        unsigned char buck1_reg_dr : 3;
    } reg;
} PMIC_BUCK1_CTRL4_UNION;
#endif
#define PMIC_BUCK1_CTRL4_buck1_short_pdp_START (0)
#define PMIC_BUCK1_CTRL4_buck1_short_pdp_END (0)
#define PMIC_BUCK1_CTRL4_buck1_reg_ss_START (1)
#define PMIC_BUCK1_CTRL4_buck1_reg_ss_END (1)
#define PMIC_BUCK1_CTRL4_buck1_regop_c_START (2)
#define PMIC_BUCK1_CTRL4_buck1_regop_c_END (2)
#define PMIC_BUCK1_CTRL4_buck1_filter_ton_START (3)
#define PMIC_BUCK1_CTRL4_buck1_filter_ton_END (4)
#define PMIC_BUCK1_CTRL4_buck1_reg_dr_START (5)
#define PMIC_BUCK1_CTRL4_buck1_reg_dr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck1_ton : 3;
        unsigned char buck1_eco_ng : 1;
        unsigned char buck1_reg_bias : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_BUCK1_CTRL5_UNION;
#endif
#define PMIC_BUCK1_CTRL5_buck1_ton_START (0)
#define PMIC_BUCK1_CTRL5_buck1_ton_END (2)
#define PMIC_BUCK1_CTRL5_buck1_eco_ng_START (3)
#define PMIC_BUCK1_CTRL5_buck1_eco_ng_END (3)
#define PMIC_BUCK1_CTRL5_buck1_reg_bias_START (4)
#define PMIC_BUCK1_CTRL5_buck1_reg_bias_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck1_dmd_ton : 3;
        unsigned char buck1_ocp_toff : 2;
        unsigned char buck1_dmd_sel : 3;
    } reg;
} PMIC_BUCK1_CTRL6_UNION;
#endif
#define PMIC_BUCK1_CTRL6_buck1_dmd_ton_START (0)
#define PMIC_BUCK1_CTRL6_buck1_dmd_ton_END (2)
#define PMIC_BUCK1_CTRL6_buck1_ocp_toff_START (3)
#define PMIC_BUCK1_CTRL6_buck1_ocp_toff_END (4)
#define PMIC_BUCK1_CTRL6_buck1_dmd_sel_START (5)
#define PMIC_BUCK1_CTRL6_buck1_dmd_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck1_sense_dmd : 1;
        unsigned char buck1_ton_dmd : 1;
        unsigned char buck1_eco_dmd : 1;
        unsigned char buck1_cmp_filter : 1;
        unsigned char buck1_ocp_delay : 1;
        unsigned char buck1_dmd_clamp : 1;
        unsigned char buck1_regop_clamp : 1;
        unsigned char reserved : 1;
    } reg;
} PMIC_BUCK1_CTRL7_UNION;
#endif
#define PMIC_BUCK1_CTRL7_buck1_sense_dmd_START (0)
#define PMIC_BUCK1_CTRL7_buck1_sense_dmd_END (0)
#define PMIC_BUCK1_CTRL7_buck1_ton_dmd_START (1)
#define PMIC_BUCK1_CTRL7_buck1_ton_dmd_END (1)
#define PMIC_BUCK1_CTRL7_buck1_eco_dmd_START (2)
#define PMIC_BUCK1_CTRL7_buck1_eco_dmd_END (2)
#define PMIC_BUCK1_CTRL7_buck1_cmp_filter_START (3)
#define PMIC_BUCK1_CTRL7_buck1_cmp_filter_END (3)
#define PMIC_BUCK1_CTRL7_buck1_ocp_delay_START (4)
#define PMIC_BUCK1_CTRL7_buck1_ocp_delay_END (4)
#define PMIC_BUCK1_CTRL7_buck1_dmd_clamp_START (5)
#define PMIC_BUCK1_CTRL7_buck1_dmd_clamp_END (5)
#define PMIC_BUCK1_CTRL7_buck1_regop_clamp_START (6)
#define PMIC_BUCK1_CTRL7_buck1_regop_clamp_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck1_sense_sel : 1;
        unsigned char buck1_sense_ctrl : 1;
        unsigned char buck1_sense_r : 6;
    } reg;
} PMIC_BUCK1_CTRL8_UNION;
#endif
#define PMIC_BUCK1_CTRL8_buck1_sense_sel_START (0)
#define PMIC_BUCK1_CTRL8_buck1_sense_sel_END (0)
#define PMIC_BUCK1_CTRL8_buck1_sense_ctrl_START (1)
#define PMIC_BUCK1_CTRL8_buck1_sense_ctrl_END (1)
#define PMIC_BUCK1_CTRL8_buck1_sense_r_START (2)
#define PMIC_BUCK1_CTRL8_buck1_sense_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck1_sense_rev0 : 4;
        unsigned char buck1_sense_filter : 4;
    } reg;
} PMIC_BUCK1_CTRL9_UNION;
#endif
#define PMIC_BUCK1_CTRL9_buck1_sense_rev0_START (0)
#define PMIC_BUCK1_CTRL9_buck1_sense_rev0_END (3)
#define PMIC_BUCK1_CTRL9_buck1_sense_filter_START (4)
#define PMIC_BUCK1_CTRL9_buck1_sense_filter_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck1_reserve : 8;
    } reg;
} PMIC_BUCK1_CTRL10_UNION;
#endif
#define PMIC_BUCK1_CTRL10_buck1_reserve_START (0)
#define PMIC_BUCK1_CTRL10_buck1_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck2_dbias : 4;
        unsigned char buck2_adj_rlx : 4;
    } reg;
} PMIC_BUCK2_CTRL0_UNION;
#endif
#define PMIC_BUCK2_CTRL0_buck2_dbias_START (0)
#define PMIC_BUCK2_CTRL0_buck2_dbias_END (3)
#define PMIC_BUCK2_CTRL0_buck2_adj_rlx_START (4)
#define PMIC_BUCK2_CTRL0_buck2_adj_rlx_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck2_ng_dt_sel : 1;
        unsigned char buck2_pg_dt_sel : 1;
        unsigned char buck2_nmos_switch : 1;
        unsigned char reserved : 1;
        unsigned char buck2_dt_sel : 2;
        unsigned char buck2_ocp_sel : 2;
    } reg;
} PMIC_BUCK2_CTRL1_UNION;
#endif
#define PMIC_BUCK2_CTRL1_buck2_ng_dt_sel_START (0)
#define PMIC_BUCK2_CTRL1_buck2_ng_dt_sel_END (0)
#define PMIC_BUCK2_CTRL1_buck2_pg_dt_sel_START (1)
#define PMIC_BUCK2_CTRL1_buck2_pg_dt_sel_END (1)
#define PMIC_BUCK2_CTRL1_buck2_nmos_switch_START (2)
#define PMIC_BUCK2_CTRL1_buck2_nmos_switch_END (2)
#define PMIC_BUCK2_CTRL1_buck2_dt_sel_START (4)
#define PMIC_BUCK2_CTRL1_buck2_dt_sel_END (5)
#define PMIC_BUCK2_CTRL1_buck2_ocp_sel_START (6)
#define PMIC_BUCK2_CTRL1_buck2_ocp_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck2_ng_n_sel : 2;
        unsigned char buck2_ng_p_sel : 2;
        unsigned char buck2_pg_n_sel : 2;
        unsigned char buck2_pg_p_sel : 2;
    } reg;
} PMIC_BUCK2_CTRL2_UNION;
#endif
#define PMIC_BUCK2_CTRL2_buck2_ng_n_sel_START (0)
#define PMIC_BUCK2_CTRL2_buck2_ng_n_sel_END (1)
#define PMIC_BUCK2_CTRL2_buck2_ng_p_sel_START (2)
#define PMIC_BUCK2_CTRL2_buck2_ng_p_sel_END (3)
#define PMIC_BUCK2_CTRL2_buck2_pg_n_sel_START (4)
#define PMIC_BUCK2_CTRL2_buck2_pg_n_sel_END (5)
#define PMIC_BUCK2_CTRL2_buck2_pg_p_sel_START (6)
#define PMIC_BUCK2_CTRL2_buck2_pg_p_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck2_reg_r : 2;
        unsigned char reserved : 2;
        unsigned char buck2_reg_en : 1;
        unsigned char buck2_adj_clx : 2;
        unsigned char buck2_ocp_dis : 1;
    } reg;
} PMIC_BUCK2_CTRL3_UNION;
#endif
#define PMIC_BUCK2_CTRL3_buck2_reg_r_START (0)
#define PMIC_BUCK2_CTRL3_buck2_reg_r_END (1)
#define PMIC_BUCK2_CTRL3_buck2_reg_en_START (4)
#define PMIC_BUCK2_CTRL3_buck2_reg_en_END (4)
#define PMIC_BUCK2_CTRL3_buck2_adj_clx_START (5)
#define PMIC_BUCK2_CTRL3_buck2_adj_clx_END (6)
#define PMIC_BUCK2_CTRL3_buck2_ocp_dis_START (7)
#define PMIC_BUCK2_CTRL3_buck2_ocp_dis_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck2_short_pdp : 1;
        unsigned char buck2_reg_ss : 1;
        unsigned char buck2_regop_c : 1;
        unsigned char buck2_filter_ton : 2;
        unsigned char buck2_reg_dr : 3;
    } reg;
} PMIC_BUCK2_CTRL4_UNION;
#endif
#define PMIC_BUCK2_CTRL4_buck2_short_pdp_START (0)
#define PMIC_BUCK2_CTRL4_buck2_short_pdp_END (0)
#define PMIC_BUCK2_CTRL4_buck2_reg_ss_START (1)
#define PMIC_BUCK2_CTRL4_buck2_reg_ss_END (1)
#define PMIC_BUCK2_CTRL4_buck2_regop_c_START (2)
#define PMIC_BUCK2_CTRL4_buck2_regop_c_END (2)
#define PMIC_BUCK2_CTRL4_buck2_filter_ton_START (3)
#define PMIC_BUCK2_CTRL4_buck2_filter_ton_END (4)
#define PMIC_BUCK2_CTRL4_buck2_reg_dr_START (5)
#define PMIC_BUCK2_CTRL4_buck2_reg_dr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck2_ton : 3;
        unsigned char buck2_eco_ng : 1;
        unsigned char buck2_reg_bias : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_BUCK2_CTRL5_UNION;
#endif
#define PMIC_BUCK2_CTRL5_buck2_ton_START (0)
#define PMIC_BUCK2_CTRL5_buck2_ton_END (2)
#define PMIC_BUCK2_CTRL5_buck2_eco_ng_START (3)
#define PMIC_BUCK2_CTRL5_buck2_eco_ng_END (3)
#define PMIC_BUCK2_CTRL5_buck2_reg_bias_START (4)
#define PMIC_BUCK2_CTRL5_buck2_reg_bias_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck2_dmd_ton : 3;
        unsigned char buck2_ocp_toff : 2;
        unsigned char buck2_dmd_sel : 3;
    } reg;
} PMIC_BUCK2_CTRL6_UNION;
#endif
#define PMIC_BUCK2_CTRL6_buck2_dmd_ton_START (0)
#define PMIC_BUCK2_CTRL6_buck2_dmd_ton_END (2)
#define PMIC_BUCK2_CTRL6_buck2_ocp_toff_START (3)
#define PMIC_BUCK2_CTRL6_buck2_ocp_toff_END (4)
#define PMIC_BUCK2_CTRL6_buck2_dmd_sel_START (5)
#define PMIC_BUCK2_CTRL6_buck2_dmd_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck2_ton_dmd : 1;
        unsigned char buck2_eco_dmd : 1;
        unsigned char buck2_cmp_filter : 1;
        unsigned char buck2_ocp_delay : 1;
        unsigned char buck2_dmd_clamp : 1;
        unsigned char buck2_regop_clamp : 1;
        unsigned char reserved : 2;
    } reg;
} PMIC_BUCK2_CTRL7_UNION;
#endif
#define PMIC_BUCK2_CTRL7_buck2_ton_dmd_START (0)
#define PMIC_BUCK2_CTRL7_buck2_ton_dmd_END (0)
#define PMIC_BUCK2_CTRL7_buck2_eco_dmd_START (1)
#define PMIC_BUCK2_CTRL7_buck2_eco_dmd_END (1)
#define PMIC_BUCK2_CTRL7_buck2_cmp_filter_START (2)
#define PMIC_BUCK2_CTRL7_buck2_cmp_filter_END (2)
#define PMIC_BUCK2_CTRL7_buck2_ocp_delay_START (3)
#define PMIC_BUCK2_CTRL7_buck2_ocp_delay_END (3)
#define PMIC_BUCK2_CTRL7_buck2_dmd_clamp_START (4)
#define PMIC_BUCK2_CTRL7_buck2_dmd_clamp_END (4)
#define PMIC_BUCK2_CTRL7_buck2_regop_clamp_START (5)
#define PMIC_BUCK2_CTRL7_buck2_regop_clamp_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck2_reserve : 8;
    } reg;
} PMIC_BUCK2_CTRL8_UNION;
#endif
#define PMIC_BUCK2_CTRL8_buck2_reserve_START (0)
#define PMIC_BUCK2_CTRL8_buck2_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck3_dbias : 4;
        unsigned char buck3_adj_rlx : 4;
    } reg;
} PMIC_BUCK3_CTRL0_UNION;
#endif
#define PMIC_BUCK3_CTRL0_buck3_dbias_START (0)
#define PMIC_BUCK3_CTRL0_buck3_dbias_END (3)
#define PMIC_BUCK3_CTRL0_buck3_adj_rlx_START (4)
#define PMIC_BUCK3_CTRL0_buck3_adj_rlx_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck3_ng_dt_sel : 1;
        unsigned char buck3_pg_dt_sel : 1;
        unsigned char buck3_nmos_switch : 1;
        unsigned char reserved : 1;
        unsigned char buck3_dt_sel : 2;
        unsigned char buck3_ocp_sel : 2;
    } reg;
} PMIC_BUCK3_CTRL1_UNION;
#endif
#define PMIC_BUCK3_CTRL1_buck3_ng_dt_sel_START (0)
#define PMIC_BUCK3_CTRL1_buck3_ng_dt_sel_END (0)
#define PMIC_BUCK3_CTRL1_buck3_pg_dt_sel_START (1)
#define PMIC_BUCK3_CTRL1_buck3_pg_dt_sel_END (1)
#define PMIC_BUCK3_CTRL1_buck3_nmos_switch_START (2)
#define PMIC_BUCK3_CTRL1_buck3_nmos_switch_END (2)
#define PMIC_BUCK3_CTRL1_buck3_dt_sel_START (4)
#define PMIC_BUCK3_CTRL1_buck3_dt_sel_END (5)
#define PMIC_BUCK3_CTRL1_buck3_ocp_sel_START (6)
#define PMIC_BUCK3_CTRL1_buck3_ocp_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck3_ng_n_sel : 2;
        unsigned char buck3_ng_p_sel : 2;
        unsigned char buck3_pg_n_sel : 2;
        unsigned char buck3_pg_p_sel : 2;
    } reg;
} PMIC_BUCK3_CTRL2_UNION;
#endif
#define PMIC_BUCK3_CTRL2_buck3_ng_n_sel_START (0)
#define PMIC_BUCK3_CTRL2_buck3_ng_n_sel_END (1)
#define PMIC_BUCK3_CTRL2_buck3_ng_p_sel_START (2)
#define PMIC_BUCK3_CTRL2_buck3_ng_p_sel_END (3)
#define PMIC_BUCK3_CTRL2_buck3_pg_n_sel_START (4)
#define PMIC_BUCK3_CTRL2_buck3_pg_n_sel_END (5)
#define PMIC_BUCK3_CTRL2_buck3_pg_p_sel_START (6)
#define PMIC_BUCK3_CTRL2_buck3_pg_p_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck3_reg_r : 2;
        unsigned char reserved : 2;
        unsigned char buck3_reg_en : 1;
        unsigned char buck3_adj_clx : 2;
        unsigned char buck3_ocp_dis : 1;
    } reg;
} PMIC_BUCK3_CTRL3_UNION;
#endif
#define PMIC_BUCK3_CTRL3_buck3_reg_r_START (0)
#define PMIC_BUCK3_CTRL3_buck3_reg_r_END (1)
#define PMIC_BUCK3_CTRL3_buck3_reg_en_START (4)
#define PMIC_BUCK3_CTRL3_buck3_reg_en_END (4)
#define PMIC_BUCK3_CTRL3_buck3_adj_clx_START (5)
#define PMIC_BUCK3_CTRL3_buck3_adj_clx_END (6)
#define PMIC_BUCK3_CTRL3_buck3_ocp_dis_START (7)
#define PMIC_BUCK3_CTRL3_buck3_ocp_dis_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck3_short_pdp : 1;
        unsigned char buck3_reg_ss : 1;
        unsigned char buck3_regop_c : 1;
        unsigned char buck3_filter_ton : 2;
        unsigned char buck3_reg_dr : 3;
    } reg;
} PMIC_BUCK3_CTRL4_UNION;
#endif
#define PMIC_BUCK3_CTRL4_buck3_short_pdp_START (0)
#define PMIC_BUCK3_CTRL4_buck3_short_pdp_END (0)
#define PMIC_BUCK3_CTRL4_buck3_reg_ss_START (1)
#define PMIC_BUCK3_CTRL4_buck3_reg_ss_END (1)
#define PMIC_BUCK3_CTRL4_buck3_regop_c_START (2)
#define PMIC_BUCK3_CTRL4_buck3_regop_c_END (2)
#define PMIC_BUCK3_CTRL4_buck3_filter_ton_START (3)
#define PMIC_BUCK3_CTRL4_buck3_filter_ton_END (4)
#define PMIC_BUCK3_CTRL4_buck3_reg_dr_START (5)
#define PMIC_BUCK3_CTRL4_buck3_reg_dr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck3_ton : 3;
        unsigned char buck3_eco_ng : 1;
        unsigned char buck3_reg_bias : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_BUCK3_CTRL5_UNION;
#endif
#define PMIC_BUCK3_CTRL5_buck3_ton_START (0)
#define PMIC_BUCK3_CTRL5_buck3_ton_END (2)
#define PMIC_BUCK3_CTRL5_buck3_eco_ng_START (3)
#define PMIC_BUCK3_CTRL5_buck3_eco_ng_END (3)
#define PMIC_BUCK3_CTRL5_buck3_reg_bias_START (4)
#define PMIC_BUCK3_CTRL5_buck3_reg_bias_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck3_dmd_ton : 3;
        unsigned char buck3_ocp_toff : 2;
        unsigned char buck3_dmd_sel : 3;
    } reg;
} PMIC_BUCK3_CTRL6_UNION;
#endif
#define PMIC_BUCK3_CTRL6_buck3_dmd_ton_START (0)
#define PMIC_BUCK3_CTRL6_buck3_dmd_ton_END (2)
#define PMIC_BUCK3_CTRL6_buck3_ocp_toff_START (3)
#define PMIC_BUCK3_CTRL6_buck3_ocp_toff_END (4)
#define PMIC_BUCK3_CTRL6_buck3_dmd_sel_START (5)
#define PMIC_BUCK3_CTRL6_buck3_dmd_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck3_ton_dmd : 1;
        unsigned char buck3_eco_dmd : 1;
        unsigned char buck3_cmp_filter : 1;
        unsigned char buck3_ocp_delay : 1;
        unsigned char buck3_dmd_clamp : 1;
        unsigned char buck3_regop_clamp : 1;
        unsigned char reserved : 2;
    } reg;
} PMIC_BUCK3_CTRL7_UNION;
#endif
#define PMIC_BUCK3_CTRL7_buck3_ton_dmd_START (0)
#define PMIC_BUCK3_CTRL7_buck3_ton_dmd_END (0)
#define PMIC_BUCK3_CTRL7_buck3_eco_dmd_START (1)
#define PMIC_BUCK3_CTRL7_buck3_eco_dmd_END (1)
#define PMIC_BUCK3_CTRL7_buck3_cmp_filter_START (2)
#define PMIC_BUCK3_CTRL7_buck3_cmp_filter_END (2)
#define PMIC_BUCK3_CTRL7_buck3_ocp_delay_START (3)
#define PMIC_BUCK3_CTRL7_buck3_ocp_delay_END (3)
#define PMIC_BUCK3_CTRL7_buck3_dmd_clamp_START (4)
#define PMIC_BUCK3_CTRL7_buck3_dmd_clamp_END (4)
#define PMIC_BUCK3_CTRL7_buck3_regop_clamp_START (5)
#define PMIC_BUCK3_CTRL7_buck3_regop_clamp_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck3_reserve : 8;
    } reg;
} PMIC_BUCK3_CTRL8_UNION;
#endif
#define PMIC_BUCK3_CTRL8_buck3_reserve_START (0)
#define PMIC_BUCK3_CTRL8_buck3_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck4_dbias : 4;
        unsigned char buck4_adj_rlx : 4;
    } reg;
} PMIC_BUCK4_CTRL0_UNION;
#endif
#define PMIC_BUCK4_CTRL0_buck4_dbias_START (0)
#define PMIC_BUCK4_CTRL0_buck4_dbias_END (3)
#define PMIC_BUCK4_CTRL0_buck4_adj_rlx_START (4)
#define PMIC_BUCK4_CTRL0_buck4_adj_rlx_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck4_ng_dt_sel : 1;
        unsigned char buck4_pg_dt_sel : 1;
        unsigned char buck4_nmos_switch : 1;
        unsigned char reserved : 1;
        unsigned char buck4_dt_sel : 2;
        unsigned char buck4_ocp_sel : 2;
    } reg;
} PMIC_BUCK4_CTRL1_UNION;
#endif
#define PMIC_BUCK4_CTRL1_buck4_ng_dt_sel_START (0)
#define PMIC_BUCK4_CTRL1_buck4_ng_dt_sel_END (0)
#define PMIC_BUCK4_CTRL1_buck4_pg_dt_sel_START (1)
#define PMIC_BUCK4_CTRL1_buck4_pg_dt_sel_END (1)
#define PMIC_BUCK4_CTRL1_buck4_nmos_switch_START (2)
#define PMIC_BUCK4_CTRL1_buck4_nmos_switch_END (2)
#define PMIC_BUCK4_CTRL1_buck4_dt_sel_START (4)
#define PMIC_BUCK4_CTRL1_buck4_dt_sel_END (5)
#define PMIC_BUCK4_CTRL1_buck4_ocp_sel_START (6)
#define PMIC_BUCK4_CTRL1_buck4_ocp_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck4_ng_n_sel : 2;
        unsigned char buck4_ng_p_sel : 2;
        unsigned char buck4_pg_n_sel : 2;
        unsigned char buck4_pg_p_sel : 2;
    } reg;
} PMIC_BUCK4_CTRL2_UNION;
#endif
#define PMIC_BUCK4_CTRL2_buck4_ng_n_sel_START (0)
#define PMIC_BUCK4_CTRL2_buck4_ng_n_sel_END (1)
#define PMIC_BUCK4_CTRL2_buck4_ng_p_sel_START (2)
#define PMIC_BUCK4_CTRL2_buck4_ng_p_sel_END (3)
#define PMIC_BUCK4_CTRL2_buck4_pg_n_sel_START (4)
#define PMIC_BUCK4_CTRL2_buck4_pg_n_sel_END (5)
#define PMIC_BUCK4_CTRL2_buck4_pg_p_sel_START (6)
#define PMIC_BUCK4_CTRL2_buck4_pg_p_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck4_reg_r : 2;
        unsigned char reserved : 2;
        unsigned char buck4_reg_en : 1;
        unsigned char buck4_adj_clx : 2;
        unsigned char buck4_ocp_dis : 1;
    } reg;
} PMIC_BUCK4_CTRL3_UNION;
#endif
#define PMIC_BUCK4_CTRL3_buck4_reg_r_START (0)
#define PMIC_BUCK4_CTRL3_buck4_reg_r_END (1)
#define PMIC_BUCK4_CTRL3_buck4_reg_en_START (4)
#define PMIC_BUCK4_CTRL3_buck4_reg_en_END (4)
#define PMIC_BUCK4_CTRL3_buck4_adj_clx_START (5)
#define PMIC_BUCK4_CTRL3_buck4_adj_clx_END (6)
#define PMIC_BUCK4_CTRL3_buck4_ocp_dis_START (7)
#define PMIC_BUCK4_CTRL3_buck4_ocp_dis_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck4_short_pdp : 1;
        unsigned char buck4_reg_ss : 1;
        unsigned char buck4_regop_c : 1;
        unsigned char buck4_filter_ton : 2;
        unsigned char buck4_reg_dr : 3;
    } reg;
} PMIC_BUCK4_CTRL4_UNION;
#endif
#define PMIC_BUCK4_CTRL4_buck4_short_pdp_START (0)
#define PMIC_BUCK4_CTRL4_buck4_short_pdp_END (0)
#define PMIC_BUCK4_CTRL4_buck4_reg_ss_START (1)
#define PMIC_BUCK4_CTRL4_buck4_reg_ss_END (1)
#define PMIC_BUCK4_CTRL4_buck4_regop_c_START (2)
#define PMIC_BUCK4_CTRL4_buck4_regop_c_END (2)
#define PMIC_BUCK4_CTRL4_buck4_filter_ton_START (3)
#define PMIC_BUCK4_CTRL4_buck4_filter_ton_END (4)
#define PMIC_BUCK4_CTRL4_buck4_reg_dr_START (5)
#define PMIC_BUCK4_CTRL4_buck4_reg_dr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck4_ton : 3;
        unsigned char buck4_eco_ng : 1;
        unsigned char buck4_reg_bias : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_BUCK4_CTRL5_UNION;
#endif
#define PMIC_BUCK4_CTRL5_buck4_ton_START (0)
#define PMIC_BUCK4_CTRL5_buck4_ton_END (2)
#define PMIC_BUCK4_CTRL5_buck4_eco_ng_START (3)
#define PMIC_BUCK4_CTRL5_buck4_eco_ng_END (3)
#define PMIC_BUCK4_CTRL5_buck4_reg_bias_START (4)
#define PMIC_BUCK4_CTRL5_buck4_reg_bias_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck4_dmd_ton : 3;
        unsigned char buck4_ocp_toff : 2;
        unsigned char buck4_dmd_sel : 3;
    } reg;
} PMIC_BUCK4_CTRL6_UNION;
#endif
#define PMIC_BUCK4_CTRL6_buck4_dmd_ton_START (0)
#define PMIC_BUCK4_CTRL6_buck4_dmd_ton_END (2)
#define PMIC_BUCK4_CTRL6_buck4_ocp_toff_START (3)
#define PMIC_BUCK4_CTRL6_buck4_ocp_toff_END (4)
#define PMIC_BUCK4_CTRL6_buck4_dmd_sel_START (5)
#define PMIC_BUCK4_CTRL6_buck4_dmd_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck4_ton_dmd : 1;
        unsigned char buck4_eco_dmd : 1;
        unsigned char buck4_cmp_filter : 1;
        unsigned char buck4_ocp_delay : 1;
        unsigned char buck4_dmd_clamp : 1;
        unsigned char buck4_regop_clamp : 1;
        unsigned char reserved : 2;
    } reg;
} PMIC_BUCK4_CTRL7_UNION;
#endif
#define PMIC_BUCK4_CTRL7_buck4_ton_dmd_START (0)
#define PMIC_BUCK4_CTRL7_buck4_ton_dmd_END (0)
#define PMIC_BUCK4_CTRL7_buck4_eco_dmd_START (1)
#define PMIC_BUCK4_CTRL7_buck4_eco_dmd_END (1)
#define PMIC_BUCK4_CTRL7_buck4_cmp_filter_START (2)
#define PMIC_BUCK4_CTRL7_buck4_cmp_filter_END (2)
#define PMIC_BUCK4_CTRL7_buck4_ocp_delay_START (3)
#define PMIC_BUCK4_CTRL7_buck4_ocp_delay_END (3)
#define PMIC_BUCK4_CTRL7_buck4_dmd_clamp_START (4)
#define PMIC_BUCK4_CTRL7_buck4_dmd_clamp_END (4)
#define PMIC_BUCK4_CTRL7_buck4_regop_clamp_START (5)
#define PMIC_BUCK4_CTRL7_buck4_regop_clamp_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck4_reserve : 8;
    } reg;
} PMIC_BUCK4_CTRL8_UNION;
#endif
#define PMIC_BUCK4_CTRL8_buck4_reserve_START (0)
#define PMIC_BUCK4_CTRL8_buck4_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck5_dbias : 4;
        unsigned char buck5_adj_rlx : 4;
    } reg;
} PMIC_BUCK5_CTRL0_UNION;
#endif
#define PMIC_BUCK5_CTRL0_buck5_dbias_START (0)
#define PMIC_BUCK5_CTRL0_buck5_dbias_END (3)
#define PMIC_BUCK5_CTRL0_buck5_adj_rlx_START (4)
#define PMIC_BUCK5_CTRL0_buck5_adj_rlx_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck5_ng_dt_sel : 1;
        unsigned char buck5_pg_dt_sel : 1;
        unsigned char buck5_nmos_switch : 1;
        unsigned char reserved : 1;
        unsigned char buck5_dt_sel : 2;
        unsigned char buck5_ocp_sel : 2;
    } reg;
} PMIC_BUCK5_CTRL1_UNION;
#endif
#define PMIC_BUCK5_CTRL1_buck5_ng_dt_sel_START (0)
#define PMIC_BUCK5_CTRL1_buck5_ng_dt_sel_END (0)
#define PMIC_BUCK5_CTRL1_buck5_pg_dt_sel_START (1)
#define PMIC_BUCK5_CTRL1_buck5_pg_dt_sel_END (1)
#define PMIC_BUCK5_CTRL1_buck5_nmos_switch_START (2)
#define PMIC_BUCK5_CTRL1_buck5_nmos_switch_END (2)
#define PMIC_BUCK5_CTRL1_buck5_dt_sel_START (4)
#define PMIC_BUCK5_CTRL1_buck5_dt_sel_END (5)
#define PMIC_BUCK5_CTRL1_buck5_ocp_sel_START (6)
#define PMIC_BUCK5_CTRL1_buck5_ocp_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck5_ng_n_sel : 2;
        unsigned char buck5_ng_p_sel : 2;
        unsigned char buck5_pg_n_sel : 2;
        unsigned char buck5_pg_p_sel : 2;
    } reg;
} PMIC_BUCK5_CTRL2_UNION;
#endif
#define PMIC_BUCK5_CTRL2_buck5_ng_n_sel_START (0)
#define PMIC_BUCK5_CTRL2_buck5_ng_n_sel_END (1)
#define PMIC_BUCK5_CTRL2_buck5_ng_p_sel_START (2)
#define PMIC_BUCK5_CTRL2_buck5_ng_p_sel_END (3)
#define PMIC_BUCK5_CTRL2_buck5_pg_n_sel_START (4)
#define PMIC_BUCK5_CTRL2_buck5_pg_n_sel_END (5)
#define PMIC_BUCK5_CTRL2_buck5_pg_p_sel_START (6)
#define PMIC_BUCK5_CTRL2_buck5_pg_p_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck5_reg_r : 2;
        unsigned char reserved : 2;
        unsigned char buck5_reg_en : 1;
        unsigned char buck5_adj_clx : 2;
        unsigned char buck5_ocp_dis : 1;
    } reg;
} PMIC_BUCK5_CTRL3_UNION;
#endif
#define PMIC_BUCK5_CTRL3_buck5_reg_r_START (0)
#define PMIC_BUCK5_CTRL3_buck5_reg_r_END (1)
#define PMIC_BUCK5_CTRL3_buck5_reg_en_START (4)
#define PMIC_BUCK5_CTRL3_buck5_reg_en_END (4)
#define PMIC_BUCK5_CTRL3_buck5_adj_clx_START (5)
#define PMIC_BUCK5_CTRL3_buck5_adj_clx_END (6)
#define PMIC_BUCK5_CTRL3_buck5_ocp_dis_START (7)
#define PMIC_BUCK5_CTRL3_buck5_ocp_dis_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck5_short_pdp : 1;
        unsigned char buck5_reg_ss : 1;
        unsigned char buck5_regop_c : 1;
        unsigned char buck5_filter_ton : 2;
        unsigned char buck5_reg_dr : 3;
    } reg;
} PMIC_BUCK5_CTRL4_UNION;
#endif
#define PMIC_BUCK5_CTRL4_buck5_short_pdp_START (0)
#define PMIC_BUCK5_CTRL4_buck5_short_pdp_END (0)
#define PMIC_BUCK5_CTRL4_buck5_reg_ss_START (1)
#define PMIC_BUCK5_CTRL4_buck5_reg_ss_END (1)
#define PMIC_BUCK5_CTRL4_buck5_regop_c_START (2)
#define PMIC_BUCK5_CTRL4_buck5_regop_c_END (2)
#define PMIC_BUCK5_CTRL4_buck5_filter_ton_START (3)
#define PMIC_BUCK5_CTRL4_buck5_filter_ton_END (4)
#define PMIC_BUCK5_CTRL4_buck5_reg_dr_START (5)
#define PMIC_BUCK5_CTRL4_buck5_reg_dr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck5_ton : 3;
        unsigned char buck5_eco_ng : 1;
        unsigned char buck5_reg_bias : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_BUCK5_CTRL5_UNION;
#endif
#define PMIC_BUCK5_CTRL5_buck5_ton_START (0)
#define PMIC_BUCK5_CTRL5_buck5_ton_END (2)
#define PMIC_BUCK5_CTRL5_buck5_eco_ng_START (3)
#define PMIC_BUCK5_CTRL5_buck5_eco_ng_END (3)
#define PMIC_BUCK5_CTRL5_buck5_reg_bias_START (4)
#define PMIC_BUCK5_CTRL5_buck5_reg_bias_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck5_dmd_ton : 3;
        unsigned char buck5_ocp_toff : 2;
        unsigned char buck5_dmd_sel : 3;
    } reg;
} PMIC_BUCK5_CTRL6_UNION;
#endif
#define PMIC_BUCK5_CTRL6_buck5_dmd_ton_START (0)
#define PMIC_BUCK5_CTRL6_buck5_dmd_ton_END (2)
#define PMIC_BUCK5_CTRL6_buck5_ocp_toff_START (3)
#define PMIC_BUCK5_CTRL6_buck5_ocp_toff_END (4)
#define PMIC_BUCK5_CTRL6_buck5_dmd_sel_START (5)
#define PMIC_BUCK5_CTRL6_buck5_dmd_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck5_ton_dmd : 1;
        unsigned char buck5_eco_dmd : 1;
        unsigned char buck5_cmp_filter : 1;
        unsigned char buck5_ocp_delay : 1;
        unsigned char buck5_dmd_clamp : 1;
        unsigned char buck5_regop_clamp : 1;
        unsigned char reserved : 2;
    } reg;
} PMIC_BUCK5_CTRL7_UNION;
#endif
#define PMIC_BUCK5_CTRL7_buck5_ton_dmd_START (0)
#define PMIC_BUCK5_CTRL7_buck5_ton_dmd_END (0)
#define PMIC_BUCK5_CTRL7_buck5_eco_dmd_START (1)
#define PMIC_BUCK5_CTRL7_buck5_eco_dmd_END (1)
#define PMIC_BUCK5_CTRL7_buck5_cmp_filter_START (2)
#define PMIC_BUCK5_CTRL7_buck5_cmp_filter_END (2)
#define PMIC_BUCK5_CTRL7_buck5_ocp_delay_START (3)
#define PMIC_BUCK5_CTRL7_buck5_ocp_delay_END (3)
#define PMIC_BUCK5_CTRL7_buck5_dmd_clamp_START (4)
#define PMIC_BUCK5_CTRL7_buck5_dmd_clamp_END (4)
#define PMIC_BUCK5_CTRL7_buck5_regop_clamp_START (5)
#define PMIC_BUCK5_CTRL7_buck5_regop_clamp_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck5_reserve : 8;
    } reg;
} PMIC_BUCK5_CTRL8_UNION;
#endif
#define PMIC_BUCK5_CTRL8_buck5_reserve_START (0)
#define PMIC_BUCK5_CTRL8_buck5_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck6_dbias : 4;
        unsigned char buck6_adj_rlx : 4;
    } reg;
} PMIC_BUCK6_CTRL0_UNION;
#endif
#define PMIC_BUCK6_CTRL0_buck6_dbias_START (0)
#define PMIC_BUCK6_CTRL0_buck6_dbias_END (3)
#define PMIC_BUCK6_CTRL0_buck6_adj_rlx_START (4)
#define PMIC_BUCK6_CTRL0_buck6_adj_rlx_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck6_ng_dt_sel : 1;
        unsigned char buck6_pg_dt_sel : 1;
        unsigned char buck6_nmos_switch : 1;
        unsigned char reserved : 1;
        unsigned char buck6_dt_sel : 2;
        unsigned char buck6_ocp_sel : 2;
    } reg;
} PMIC_BUCK6_CTRL1_UNION;
#endif
#define PMIC_BUCK6_CTRL1_buck6_ng_dt_sel_START (0)
#define PMIC_BUCK6_CTRL1_buck6_ng_dt_sel_END (0)
#define PMIC_BUCK6_CTRL1_buck6_pg_dt_sel_START (1)
#define PMIC_BUCK6_CTRL1_buck6_pg_dt_sel_END (1)
#define PMIC_BUCK6_CTRL1_buck6_nmos_switch_START (2)
#define PMIC_BUCK6_CTRL1_buck6_nmos_switch_END (2)
#define PMIC_BUCK6_CTRL1_buck6_dt_sel_START (4)
#define PMIC_BUCK6_CTRL1_buck6_dt_sel_END (5)
#define PMIC_BUCK6_CTRL1_buck6_ocp_sel_START (6)
#define PMIC_BUCK6_CTRL1_buck6_ocp_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck6_ng_n_sel : 2;
        unsigned char buck6_ng_p_sel : 2;
        unsigned char buck6_pg_n_sel : 2;
        unsigned char buck6_pg_p_sel : 2;
    } reg;
} PMIC_BUCK6_CTRL2_UNION;
#endif
#define PMIC_BUCK6_CTRL2_buck6_ng_n_sel_START (0)
#define PMIC_BUCK6_CTRL2_buck6_ng_n_sel_END (1)
#define PMIC_BUCK6_CTRL2_buck6_ng_p_sel_START (2)
#define PMIC_BUCK6_CTRL2_buck6_ng_p_sel_END (3)
#define PMIC_BUCK6_CTRL2_buck6_pg_n_sel_START (4)
#define PMIC_BUCK6_CTRL2_buck6_pg_n_sel_END (5)
#define PMIC_BUCK6_CTRL2_buck6_pg_p_sel_START (6)
#define PMIC_BUCK6_CTRL2_buck6_pg_p_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck6_reg_r : 2;
        unsigned char reserved : 2;
        unsigned char buck6_reg_en : 1;
        unsigned char buck6_adj_clx : 2;
        unsigned char buck6_ocp_dis : 1;
    } reg;
} PMIC_BUCK6_CTRL3_UNION;
#endif
#define PMIC_BUCK6_CTRL3_buck6_reg_r_START (0)
#define PMIC_BUCK6_CTRL3_buck6_reg_r_END (1)
#define PMIC_BUCK6_CTRL3_buck6_reg_en_START (4)
#define PMIC_BUCK6_CTRL3_buck6_reg_en_END (4)
#define PMIC_BUCK6_CTRL3_buck6_adj_clx_START (5)
#define PMIC_BUCK6_CTRL3_buck6_adj_clx_END (6)
#define PMIC_BUCK6_CTRL3_buck6_ocp_dis_START (7)
#define PMIC_BUCK6_CTRL3_buck6_ocp_dis_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck6_short_pdp : 1;
        unsigned char buck6_reg_ss : 1;
        unsigned char buck6_regop_c : 1;
        unsigned char buck6_filter_ton : 2;
        unsigned char buck6_reg_dr : 3;
    } reg;
} PMIC_BUCK6_CTRL4_UNION;
#endif
#define PMIC_BUCK6_CTRL4_buck6_short_pdp_START (0)
#define PMIC_BUCK6_CTRL4_buck6_short_pdp_END (0)
#define PMIC_BUCK6_CTRL4_buck6_reg_ss_START (1)
#define PMIC_BUCK6_CTRL4_buck6_reg_ss_END (1)
#define PMIC_BUCK6_CTRL4_buck6_regop_c_START (2)
#define PMIC_BUCK6_CTRL4_buck6_regop_c_END (2)
#define PMIC_BUCK6_CTRL4_buck6_filter_ton_START (3)
#define PMIC_BUCK6_CTRL4_buck6_filter_ton_END (4)
#define PMIC_BUCK6_CTRL4_buck6_reg_dr_START (5)
#define PMIC_BUCK6_CTRL4_buck6_reg_dr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck6_ton : 3;
        unsigned char buck6_eco_ng : 1;
        unsigned char buck6_reg_bias : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_BUCK6_CTRL5_UNION;
#endif
#define PMIC_BUCK6_CTRL5_buck6_ton_START (0)
#define PMIC_BUCK6_CTRL5_buck6_ton_END (2)
#define PMIC_BUCK6_CTRL5_buck6_eco_ng_START (3)
#define PMIC_BUCK6_CTRL5_buck6_eco_ng_END (3)
#define PMIC_BUCK6_CTRL5_buck6_reg_bias_START (4)
#define PMIC_BUCK6_CTRL5_buck6_reg_bias_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck6_dmd_ton : 3;
        unsigned char buck6_ocp_toff : 2;
        unsigned char buck6_dmd_sel : 3;
    } reg;
} PMIC_BUCK6_CTRL6_UNION;
#endif
#define PMIC_BUCK6_CTRL6_buck6_dmd_ton_START (0)
#define PMIC_BUCK6_CTRL6_buck6_dmd_ton_END (2)
#define PMIC_BUCK6_CTRL6_buck6_ocp_toff_START (3)
#define PMIC_BUCK6_CTRL6_buck6_ocp_toff_END (4)
#define PMIC_BUCK6_CTRL6_buck6_dmd_sel_START (5)
#define PMIC_BUCK6_CTRL6_buck6_dmd_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck6_ton_dmd : 1;
        unsigned char buck6_eco_dmd : 1;
        unsigned char buck6_cmp_filter : 1;
        unsigned char buck6_ocp_delay : 1;
        unsigned char buck6_dmd_clamp : 1;
        unsigned char buck6_regop_clamp : 1;
        unsigned char reserved : 2;
    } reg;
} PMIC_BUCK6_CTRL7_UNION;
#endif
#define PMIC_BUCK6_CTRL7_buck6_ton_dmd_START (0)
#define PMIC_BUCK6_CTRL7_buck6_ton_dmd_END (0)
#define PMIC_BUCK6_CTRL7_buck6_eco_dmd_START (1)
#define PMIC_BUCK6_CTRL7_buck6_eco_dmd_END (1)
#define PMIC_BUCK6_CTRL7_buck6_cmp_filter_START (2)
#define PMIC_BUCK6_CTRL7_buck6_cmp_filter_END (2)
#define PMIC_BUCK6_CTRL7_buck6_ocp_delay_START (3)
#define PMIC_BUCK6_CTRL7_buck6_ocp_delay_END (3)
#define PMIC_BUCK6_CTRL7_buck6_dmd_clamp_START (4)
#define PMIC_BUCK6_CTRL7_buck6_dmd_clamp_END (4)
#define PMIC_BUCK6_CTRL7_buck6_regop_clamp_START (5)
#define PMIC_BUCK6_CTRL7_buck6_regop_clamp_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck6_reserve : 8;
    } reg;
} PMIC_BUCK6_CTRL8_UNION;
#endif
#define PMIC_BUCK6_CTRL8_buck6_reserve_START (0)
#define PMIC_BUCK6_CTRL8_buck6_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck7_dbias : 4;
        unsigned char buck7_adj_rlx : 4;
    } reg;
} PMIC_BUCK7_CTRL0_UNION;
#endif
#define PMIC_BUCK7_CTRL0_buck7_dbias_START (0)
#define PMIC_BUCK7_CTRL0_buck7_dbias_END (3)
#define PMIC_BUCK7_CTRL0_buck7_adj_rlx_START (4)
#define PMIC_BUCK7_CTRL0_buck7_adj_rlx_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck7_ng_dt_sel : 1;
        unsigned char buck7_pg_dt_sel : 1;
        unsigned char buck7_nmos_switch : 1;
        unsigned char reserved : 1;
        unsigned char buck7_dt_sel : 2;
        unsigned char buck7_ocp_sel : 2;
    } reg;
} PMIC_BUCK7_CTRL1_UNION;
#endif
#define PMIC_BUCK7_CTRL1_buck7_ng_dt_sel_START (0)
#define PMIC_BUCK7_CTRL1_buck7_ng_dt_sel_END (0)
#define PMIC_BUCK7_CTRL1_buck7_pg_dt_sel_START (1)
#define PMIC_BUCK7_CTRL1_buck7_pg_dt_sel_END (1)
#define PMIC_BUCK7_CTRL1_buck7_nmos_switch_START (2)
#define PMIC_BUCK7_CTRL1_buck7_nmos_switch_END (2)
#define PMIC_BUCK7_CTRL1_buck7_dt_sel_START (4)
#define PMIC_BUCK7_CTRL1_buck7_dt_sel_END (5)
#define PMIC_BUCK7_CTRL1_buck7_ocp_sel_START (6)
#define PMIC_BUCK7_CTRL1_buck7_ocp_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck7_ng_n_sel : 2;
        unsigned char buck7_ng_p_sel : 2;
        unsigned char buck7_pg_n_sel : 2;
        unsigned char buck7_pg_p_sel : 2;
    } reg;
} PMIC_BUCK7_CTRL2_UNION;
#endif
#define PMIC_BUCK7_CTRL2_buck7_ng_n_sel_START (0)
#define PMIC_BUCK7_CTRL2_buck7_ng_n_sel_END (1)
#define PMIC_BUCK7_CTRL2_buck7_ng_p_sel_START (2)
#define PMIC_BUCK7_CTRL2_buck7_ng_p_sel_END (3)
#define PMIC_BUCK7_CTRL2_buck7_pg_n_sel_START (4)
#define PMIC_BUCK7_CTRL2_buck7_pg_n_sel_END (5)
#define PMIC_BUCK7_CTRL2_buck7_pg_p_sel_START (6)
#define PMIC_BUCK7_CTRL2_buck7_pg_p_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck7_reg_r : 2;
        unsigned char reserved : 2;
        unsigned char buck7_reg_en : 1;
        unsigned char buck7_adj_clx : 2;
        unsigned char buck7_ocp_dis : 1;
    } reg;
} PMIC_BUCK7_CTRL3_UNION;
#endif
#define PMIC_BUCK7_CTRL3_buck7_reg_r_START (0)
#define PMIC_BUCK7_CTRL3_buck7_reg_r_END (1)
#define PMIC_BUCK7_CTRL3_buck7_reg_en_START (4)
#define PMIC_BUCK7_CTRL3_buck7_reg_en_END (4)
#define PMIC_BUCK7_CTRL3_buck7_adj_clx_START (5)
#define PMIC_BUCK7_CTRL3_buck7_adj_clx_END (6)
#define PMIC_BUCK7_CTRL3_buck7_ocp_dis_START (7)
#define PMIC_BUCK7_CTRL3_buck7_ocp_dis_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck7_short_pdp : 1;
        unsigned char buck7_reg_ss : 1;
        unsigned char buck7_regop_c : 1;
        unsigned char buck7_filter_ton : 2;
        unsigned char buck7_reg_dr : 3;
    } reg;
} PMIC_BUCK7_CTRL4_UNION;
#endif
#define PMIC_BUCK7_CTRL4_buck7_short_pdp_START (0)
#define PMIC_BUCK7_CTRL4_buck7_short_pdp_END (0)
#define PMIC_BUCK7_CTRL4_buck7_reg_ss_START (1)
#define PMIC_BUCK7_CTRL4_buck7_reg_ss_END (1)
#define PMIC_BUCK7_CTRL4_buck7_regop_c_START (2)
#define PMIC_BUCK7_CTRL4_buck7_regop_c_END (2)
#define PMIC_BUCK7_CTRL4_buck7_filter_ton_START (3)
#define PMIC_BUCK7_CTRL4_buck7_filter_ton_END (4)
#define PMIC_BUCK7_CTRL4_buck7_reg_dr_START (5)
#define PMIC_BUCK7_CTRL4_buck7_reg_dr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck7_ton : 3;
        unsigned char buck7_eco_ng : 1;
        unsigned char buck7_reg_bias : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_BUCK7_CTRL5_UNION;
#endif
#define PMIC_BUCK7_CTRL5_buck7_ton_START (0)
#define PMIC_BUCK7_CTRL5_buck7_ton_END (2)
#define PMIC_BUCK7_CTRL5_buck7_eco_ng_START (3)
#define PMIC_BUCK7_CTRL5_buck7_eco_ng_END (3)
#define PMIC_BUCK7_CTRL5_buck7_reg_bias_START (4)
#define PMIC_BUCK7_CTRL5_buck7_reg_bias_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck7_dmd_ton : 3;
        unsigned char buck7_ocp_toff : 2;
        unsigned char buck7_dmd_sel : 3;
    } reg;
} PMIC_BUCK7_CTRL6_UNION;
#endif
#define PMIC_BUCK7_CTRL6_buck7_dmd_ton_START (0)
#define PMIC_BUCK7_CTRL6_buck7_dmd_ton_END (2)
#define PMIC_BUCK7_CTRL6_buck7_ocp_toff_START (3)
#define PMIC_BUCK7_CTRL6_buck7_ocp_toff_END (4)
#define PMIC_BUCK7_CTRL6_buck7_dmd_sel_START (5)
#define PMIC_BUCK7_CTRL6_buck7_dmd_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck7_sense_dmd : 1;
        unsigned char buck7_ton_dmd : 1;
        unsigned char buck7_eco_dmd : 1;
        unsigned char buck7_cmp_filter : 1;
        unsigned char buck7_ocp_delay : 1;
        unsigned char buck7_dmd_clamp : 1;
        unsigned char buck7_regop_clamp : 1;
        unsigned char reserved : 1;
    } reg;
} PMIC_BUCK7_CTRL7_UNION;
#endif
#define PMIC_BUCK7_CTRL7_buck7_sense_dmd_START (0)
#define PMIC_BUCK7_CTRL7_buck7_sense_dmd_END (0)
#define PMIC_BUCK7_CTRL7_buck7_ton_dmd_START (1)
#define PMIC_BUCK7_CTRL7_buck7_ton_dmd_END (1)
#define PMIC_BUCK7_CTRL7_buck7_eco_dmd_START (2)
#define PMIC_BUCK7_CTRL7_buck7_eco_dmd_END (2)
#define PMIC_BUCK7_CTRL7_buck7_cmp_filter_START (3)
#define PMIC_BUCK7_CTRL7_buck7_cmp_filter_END (3)
#define PMIC_BUCK7_CTRL7_buck7_ocp_delay_START (4)
#define PMIC_BUCK7_CTRL7_buck7_ocp_delay_END (4)
#define PMIC_BUCK7_CTRL7_buck7_dmd_clamp_START (5)
#define PMIC_BUCK7_CTRL7_buck7_dmd_clamp_END (5)
#define PMIC_BUCK7_CTRL7_buck7_regop_clamp_START (6)
#define PMIC_BUCK7_CTRL7_buck7_regop_clamp_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck7_sense_sel : 1;
        unsigned char buck7_sense_ctrl : 1;
        unsigned char buck7_sense_r : 6;
    } reg;
} PMIC_BUCK7_CTRL8_UNION;
#endif
#define PMIC_BUCK7_CTRL8_buck7_sense_sel_START (0)
#define PMIC_BUCK7_CTRL8_buck7_sense_sel_END (0)
#define PMIC_BUCK7_CTRL8_buck7_sense_ctrl_START (1)
#define PMIC_BUCK7_CTRL8_buck7_sense_ctrl_END (1)
#define PMIC_BUCK7_CTRL8_buck7_sense_r_START (2)
#define PMIC_BUCK7_CTRL8_buck7_sense_r_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck7_sense_rev0 : 4;
        unsigned char buck7_sense_filter : 4;
    } reg;
} PMIC_BUCK7_CTRL9_UNION;
#endif
#define PMIC_BUCK7_CTRL9_buck7_sense_rev0_START (0)
#define PMIC_BUCK7_CTRL9_buck7_sense_rev0_END (3)
#define PMIC_BUCK7_CTRL9_buck7_sense_filter_START (4)
#define PMIC_BUCK7_CTRL9_buck7_sense_filter_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck7_reserve : 8;
    } reg;
} PMIC_BUCK7_CTRL10_UNION;
#endif
#define PMIC_BUCK7_CTRL10_buck7_reserve_START (0)
#define PMIC_BUCK7_CTRL10_buck7_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck8_dbias : 4;
        unsigned char buck8_adj_rlx : 4;
    } reg;
} PMIC_BUCK8_CTRL0_UNION;
#endif
#define PMIC_BUCK8_CTRL0_buck8_dbias_START (0)
#define PMIC_BUCK8_CTRL0_buck8_dbias_END (3)
#define PMIC_BUCK8_CTRL0_buck8_adj_rlx_START (4)
#define PMIC_BUCK8_CTRL0_buck8_adj_rlx_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck8_ng_dt_sel : 1;
        unsigned char buck8_pg_dt_sel : 1;
        unsigned char buck8_nmos_switch : 1;
        unsigned char reserved : 1;
        unsigned char buck8_dt_sel : 2;
        unsigned char buck8_ocp_sel : 2;
    } reg;
} PMIC_BUCK8_CTRL1_UNION;
#endif
#define PMIC_BUCK8_CTRL1_buck8_ng_dt_sel_START (0)
#define PMIC_BUCK8_CTRL1_buck8_ng_dt_sel_END (0)
#define PMIC_BUCK8_CTRL1_buck8_pg_dt_sel_START (1)
#define PMIC_BUCK8_CTRL1_buck8_pg_dt_sel_END (1)
#define PMIC_BUCK8_CTRL1_buck8_nmos_switch_START (2)
#define PMIC_BUCK8_CTRL1_buck8_nmos_switch_END (2)
#define PMIC_BUCK8_CTRL1_buck8_dt_sel_START (4)
#define PMIC_BUCK8_CTRL1_buck8_dt_sel_END (5)
#define PMIC_BUCK8_CTRL1_buck8_ocp_sel_START (6)
#define PMIC_BUCK8_CTRL1_buck8_ocp_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck8_ng_n_sel : 2;
        unsigned char buck8_ng_p_sel : 2;
        unsigned char buck8_pg_n_sel : 2;
        unsigned char buck8_pg_p_sel : 2;
    } reg;
} PMIC_BUCK8_CTRL2_UNION;
#endif
#define PMIC_BUCK8_CTRL2_buck8_ng_n_sel_START (0)
#define PMIC_BUCK8_CTRL2_buck8_ng_n_sel_END (1)
#define PMIC_BUCK8_CTRL2_buck8_ng_p_sel_START (2)
#define PMIC_BUCK8_CTRL2_buck8_ng_p_sel_END (3)
#define PMIC_BUCK8_CTRL2_buck8_pg_n_sel_START (4)
#define PMIC_BUCK8_CTRL2_buck8_pg_n_sel_END (5)
#define PMIC_BUCK8_CTRL2_buck8_pg_p_sel_START (6)
#define PMIC_BUCK8_CTRL2_buck8_pg_p_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck8_reg_r : 2;
        unsigned char reserved : 2;
        unsigned char buck8_reg_en : 1;
        unsigned char buck8_adj_clx : 2;
        unsigned char buck8_ocp_dis : 1;
    } reg;
} PMIC_BUCK8_CTRL3_UNION;
#endif
#define PMIC_BUCK8_CTRL3_buck8_reg_r_START (0)
#define PMIC_BUCK8_CTRL3_buck8_reg_r_END (1)
#define PMIC_BUCK8_CTRL3_buck8_reg_en_START (4)
#define PMIC_BUCK8_CTRL3_buck8_reg_en_END (4)
#define PMIC_BUCK8_CTRL3_buck8_adj_clx_START (5)
#define PMIC_BUCK8_CTRL3_buck8_adj_clx_END (6)
#define PMIC_BUCK8_CTRL3_buck8_ocp_dis_START (7)
#define PMIC_BUCK8_CTRL3_buck8_ocp_dis_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck8_short_pdp : 1;
        unsigned char buck8_reg_ss : 1;
        unsigned char buck8_regop_c : 1;
        unsigned char buck8_filter_ton : 2;
        unsigned char buck8_reg_dr : 3;
    } reg;
} PMIC_BUCK8_CTRL4_UNION;
#endif
#define PMIC_BUCK8_CTRL4_buck8_short_pdp_START (0)
#define PMIC_BUCK8_CTRL4_buck8_short_pdp_END (0)
#define PMIC_BUCK8_CTRL4_buck8_reg_ss_START (1)
#define PMIC_BUCK8_CTRL4_buck8_reg_ss_END (1)
#define PMIC_BUCK8_CTRL4_buck8_regop_c_START (2)
#define PMIC_BUCK8_CTRL4_buck8_regop_c_END (2)
#define PMIC_BUCK8_CTRL4_buck8_filter_ton_START (3)
#define PMIC_BUCK8_CTRL4_buck8_filter_ton_END (4)
#define PMIC_BUCK8_CTRL4_buck8_reg_dr_START (5)
#define PMIC_BUCK8_CTRL4_buck8_reg_dr_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck8_ton : 3;
        unsigned char buck8_eco_ng : 1;
        unsigned char buck8_reg_bias : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_BUCK8_CTRL5_UNION;
#endif
#define PMIC_BUCK8_CTRL5_buck8_ton_START (0)
#define PMIC_BUCK8_CTRL5_buck8_ton_END (2)
#define PMIC_BUCK8_CTRL5_buck8_eco_ng_START (3)
#define PMIC_BUCK8_CTRL5_buck8_eco_ng_END (3)
#define PMIC_BUCK8_CTRL5_buck8_reg_bias_START (4)
#define PMIC_BUCK8_CTRL5_buck8_reg_bias_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck8_dmd_ton : 3;
        unsigned char buck8_ocp_toff : 2;
        unsigned char buck8_dmd_sel : 3;
    } reg;
} PMIC_BUCK8_CTRL6_UNION;
#endif
#define PMIC_BUCK8_CTRL6_buck8_dmd_ton_START (0)
#define PMIC_BUCK8_CTRL6_buck8_dmd_ton_END (2)
#define PMIC_BUCK8_CTRL6_buck8_ocp_toff_START (3)
#define PMIC_BUCK8_CTRL6_buck8_ocp_toff_END (4)
#define PMIC_BUCK8_CTRL6_buck8_dmd_sel_START (5)
#define PMIC_BUCK8_CTRL6_buck8_dmd_sel_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck8_ton_dmd : 1;
        unsigned char buck8_eco_dmd : 1;
        unsigned char buck8_cmp_filter : 1;
        unsigned char buck8_ocp_delay : 1;
        unsigned char buck8_dmd_clamp : 1;
        unsigned char buck8_regop_clamp : 1;
        unsigned char reserved : 2;
    } reg;
} PMIC_BUCK8_CTRL7_UNION;
#endif
#define PMIC_BUCK8_CTRL7_buck8_ton_dmd_START (0)
#define PMIC_BUCK8_CTRL7_buck8_ton_dmd_END (0)
#define PMIC_BUCK8_CTRL7_buck8_eco_dmd_START (1)
#define PMIC_BUCK8_CTRL7_buck8_eco_dmd_END (1)
#define PMIC_BUCK8_CTRL7_buck8_cmp_filter_START (2)
#define PMIC_BUCK8_CTRL7_buck8_cmp_filter_END (2)
#define PMIC_BUCK8_CTRL7_buck8_ocp_delay_START (3)
#define PMIC_BUCK8_CTRL7_buck8_ocp_delay_END (3)
#define PMIC_BUCK8_CTRL7_buck8_dmd_clamp_START (4)
#define PMIC_BUCK8_CTRL7_buck8_dmd_clamp_END (4)
#define PMIC_BUCK8_CTRL7_buck8_regop_clamp_START (5)
#define PMIC_BUCK8_CTRL7_buck8_regop_clamp_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck8_reserve : 8;
    } reg;
} PMIC_BUCK8_CTRL8_UNION;
#endif
#define PMIC_BUCK8_CTRL8_buck8_reserve_START (0)
#define PMIC_BUCK8_CTRL8_buck8_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck_reserve0 : 8;
    } reg;
} PMIC_BUCK_RESERVE0_UNION;
#endif
#define PMIC_BUCK_RESERVE0_buck_reserve0_START (0)
#define PMIC_BUCK_RESERVE0_buck_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck_reserve1 : 8;
    } reg;
} PMIC_BUCK_RESERVE1_UNION;
#endif
#define PMIC_BUCK_RESERVE1_buck_reserve1_START (0)
#define PMIC_BUCK_RESERVE1_buck_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo1_vrset : 3;
        unsigned char ldo1_ocp_enn : 1;
        unsigned char ldo0_2_vrset : 3;
        unsigned char ldo0_2_ocp_enn : 1;
    } reg;
} PMIC_LDO_1_CTRL_UNION;
#endif
#define PMIC_LDO_1_CTRL_ldo1_vrset_START (0)
#define PMIC_LDO_1_CTRL_ldo1_vrset_END (2)
#define PMIC_LDO_1_CTRL_ldo1_ocp_enn_START (3)
#define PMIC_LDO_1_CTRL_ldo1_ocp_enn_END (3)
#define PMIC_LDO_1_CTRL_ldo0_2_vrset_START (4)
#define PMIC_LDO_1_CTRL_ldo0_2_vrset_END (6)
#define PMIC_LDO_1_CTRL_ldo0_2_ocp_enn_START (7)
#define PMIC_LDO_1_CTRL_ldo0_2_ocp_enn_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo1_ref_buf_bypass : 1;
        unsigned char ldo1_psrr2_set : 3;
        unsigned char ldo1_psrr1_set : 3;
        unsigned char ldo1_psrr_en : 1;
    } reg;
} PMIC_LDO1_CTRL_0_UNION;
#endif
#define PMIC_LDO1_CTRL_0_ldo1_ref_buf_bypass_START (0)
#define PMIC_LDO1_CTRL_0_ldo1_ref_buf_bypass_END (0)
#define PMIC_LDO1_CTRL_0_ldo1_psrr2_set_START (1)
#define PMIC_LDO1_CTRL_0_ldo1_psrr2_set_END (3)
#define PMIC_LDO1_CTRL_0_ldo1_psrr1_set_START (4)
#define PMIC_LDO1_CTRL_0_ldo1_psrr1_set_END (6)
#define PMIC_LDO1_CTRL_0_ldo1_psrr_en_START (7)
#define PMIC_LDO1_CTRL_0_ldo1_psrr_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo1_ocps_en : 1;
        unsigned char ldo1_bw_en : 1;
        unsigned char ldo1_vgpr_en : 1;
        unsigned char ldo1_ref_buf_rset : 2;
        unsigned char ldo1_comp : 3;
    } reg;
} PMIC_LDO1_CTRL_1_UNION;
#endif
#define PMIC_LDO1_CTRL_1_ldo1_ocps_en_START (0)
#define PMIC_LDO1_CTRL_1_ldo1_ocps_en_END (0)
#define PMIC_LDO1_CTRL_1_ldo1_bw_en_START (1)
#define PMIC_LDO1_CTRL_1_ldo1_bw_en_END (1)
#define PMIC_LDO1_CTRL_1_ldo1_vgpr_en_START (2)
#define PMIC_LDO1_CTRL_1_ldo1_vgpr_en_END (2)
#define PMIC_LDO1_CTRL_1_ldo1_ref_buf_rset_START (3)
#define PMIC_LDO1_CTRL_1_ldo1_ref_buf_rset_END (4)
#define PMIC_LDO1_CTRL_1_ldo1_comp_START (5)
#define PMIC_LDO1_CTRL_1_ldo1_comp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo3_vrset : 3;
        unsigned char ldo3_ocp_enn : 1;
        unsigned char ldo2_vrset : 3;
        unsigned char ldo2_ocp_enn : 1;
    } reg;
} PMIC_LDO2_3_CTRL_UNION;
#endif
#define PMIC_LDO2_3_CTRL_ldo3_vrset_START (0)
#define PMIC_LDO2_3_CTRL_ldo3_vrset_END (2)
#define PMIC_LDO2_3_CTRL_ldo3_ocp_enn_START (3)
#define PMIC_LDO2_3_CTRL_ldo3_ocp_enn_END (3)
#define PMIC_LDO2_3_CTRL_ldo2_vrset_START (4)
#define PMIC_LDO2_3_CTRL_ldo2_vrset_END (6)
#define PMIC_LDO2_3_CTRL_ldo2_ocp_enn_START (7)
#define PMIC_LDO2_3_CTRL_ldo2_ocp_enn_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo3_psrr2_set : 3;
        unsigned char ldo3_psrr1_set : 3;
        unsigned char ldo3_psrr_en : 1;
        unsigned char reserved : 1;
    } reg;
} PMIC_LDO3_CTRL_UNION;
#endif
#define PMIC_LDO3_CTRL_ldo3_psrr2_set_START (0)
#define PMIC_LDO3_CTRL_ldo3_psrr2_set_END (2)
#define PMIC_LDO3_CTRL_ldo3_psrr1_set_START (3)
#define PMIC_LDO3_CTRL_ldo3_psrr1_set_END (5)
#define PMIC_LDO3_CTRL_ldo3_psrr_en_START (6)
#define PMIC_LDO3_CTRL_ldo3_psrr_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo4_iss_en : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_LDO4_CTRL_UNION;
#endif
#define PMIC_LDO4_CTRL_ldo4_iss_en_START (0)
#define PMIC_LDO4_CTRL_ldo4_iss_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo5_vrset : 3;
        unsigned char ldo5_ocp_enn : 1;
        unsigned char ldo4_vrset : 3;
        unsigned char ldo4_ocp_enn : 1;
    } reg;
} PMIC_LDO4_5_CTRL_UNION;
#endif
#define PMIC_LDO4_5_CTRL_ldo5_vrset_START (0)
#define PMIC_LDO4_5_CTRL_ldo5_vrset_END (2)
#define PMIC_LDO4_5_CTRL_ldo5_ocp_enn_START (3)
#define PMIC_LDO4_5_CTRL_ldo5_ocp_enn_END (3)
#define PMIC_LDO4_5_CTRL_ldo4_vrset_START (4)
#define PMIC_LDO4_5_CTRL_ldo4_vrset_END (6)
#define PMIC_LDO4_5_CTRL_ldo4_ocp_enn_START (7)
#define PMIC_LDO4_5_CTRL_ldo4_ocp_enn_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo6_vrset : 3;
        unsigned char ldo6_ocp_enn : 1;
        unsigned char ldo6_ocps_en : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_LDO6_CTRL_UNION;
#endif
#define PMIC_LDO6_CTRL_ldo6_vrset_START (0)
#define PMIC_LDO6_CTRL_ldo6_vrset_END (2)
#define PMIC_LDO6_CTRL_ldo6_ocp_enn_START (3)
#define PMIC_LDO6_CTRL_ldo6_ocp_enn_END (3)
#define PMIC_LDO6_CTRL_ldo6_ocps_en_START (4)
#define PMIC_LDO6_CTRL_ldo6_ocps_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo8_vrset : 3;
        unsigned char ldo8_ocp_enn : 1;
        unsigned char ldo7_vrset : 3;
        unsigned char ldo7_ocp_enn : 1;
    } reg;
} PMIC_LDO7_8_CTRL_UNION;
#endif
#define PMIC_LDO7_8_CTRL_ldo8_vrset_START (0)
#define PMIC_LDO7_8_CTRL_ldo8_vrset_END (2)
#define PMIC_LDO7_8_CTRL_ldo8_ocp_enn_START (3)
#define PMIC_LDO7_8_CTRL_ldo8_ocp_enn_END (3)
#define PMIC_LDO7_8_CTRL_ldo7_vrset_START (4)
#define PMIC_LDO7_8_CTRL_ldo7_vrset_END (6)
#define PMIC_LDO7_8_CTRL_ldo7_ocp_enn_START (7)
#define PMIC_LDO7_8_CTRL_ldo7_ocp_enn_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo8_psrr2_set : 3;
        unsigned char ldo8_psrr1_set : 3;
        unsigned char ldo8_psrr_en : 1;
        unsigned char reserved : 1;
    } reg;
} PMIC_LDO8_CTRL_UNION;
#endif
#define PMIC_LDO8_CTRL_ldo8_psrr2_set_START (0)
#define PMIC_LDO8_CTRL_ldo8_psrr2_set_END (2)
#define PMIC_LDO8_CTRL_ldo8_psrr1_set_START (3)
#define PMIC_LDO8_CTRL_ldo8_psrr1_set_END (5)
#define PMIC_LDO8_CTRL_ldo8_psrr_en_START (6)
#define PMIC_LDO8_CTRL_ldo8_psrr_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo9_vrset : 3;
        unsigned char ldo9_ocp_enn : 1;
        unsigned char reserved : 4;
    } reg;
} PMIC_LDO9_CTRL_UNION;
#endif
#define PMIC_LDO9_CTRL_ldo9_vrset_START (0)
#define PMIC_LDO9_CTRL_ldo9_vrset_END (2)
#define PMIC_LDO9_CTRL_ldo9_ocp_enn_START (3)
#define PMIC_LDO9_CTRL_ldo9_ocp_enn_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo12_vrset : 3;
        unsigned char ldo12_ocp_enn : 1;
        unsigned char ldo11_vrset : 3;
        unsigned char ldo11_ocp_enn : 1;
    } reg;
} PMIC_LD11_12_CTRL_UNION;
#endif
#define PMIC_LD11_12_CTRL_ldo12_vrset_START (0)
#define PMIC_LD11_12_CTRL_ldo12_vrset_END (2)
#define PMIC_LD11_12_CTRL_ldo12_ocp_enn_START (3)
#define PMIC_LD11_12_CTRL_ldo12_ocp_enn_END (3)
#define PMIC_LD11_12_CTRL_ldo11_vrset_START (4)
#define PMIC_LD11_12_CTRL_ldo11_vrset_END (6)
#define PMIC_LD11_12_CTRL_ldo11_ocp_enn_START (7)
#define PMIC_LD11_12_CTRL_ldo11_ocp_enn_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo13_psrr2_set : 3;
        unsigned char ldo13_psrr1_set : 3;
        unsigned char ldo13_psrr_en : 1;
        unsigned char reserved : 1;
    } reg;
} PMIC_LDO13_CTRL_UNION;
#endif
#define PMIC_LDO13_CTRL_ldo13_psrr2_set_START (0)
#define PMIC_LDO13_CTRL_ldo13_psrr2_set_END (2)
#define PMIC_LDO13_CTRL_ldo13_psrr1_set_START (3)
#define PMIC_LDO13_CTRL_ldo13_psrr1_set_END (5)
#define PMIC_LDO13_CTRL_ldo13_psrr_en_START (6)
#define PMIC_LDO13_CTRL_ldo13_psrr_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo14_vrset : 3;
        unsigned char ldo14_ocp_enn : 1;
        unsigned char ldo13_vrset : 3;
        unsigned char ldo13_ocp_enn : 1;
    } reg;
} PMIC_LDO13_14_CTRL_UNION;
#endif
#define PMIC_LDO13_14_CTRL_ldo14_vrset_START (0)
#define PMIC_LDO13_14_CTRL_ldo14_vrset_END (2)
#define PMIC_LDO13_14_CTRL_ldo14_ocp_enn_START (3)
#define PMIC_LDO13_14_CTRL_ldo14_ocp_enn_END (3)
#define PMIC_LDO13_14_CTRL_ldo13_vrset_START (4)
#define PMIC_LDO13_14_CTRL_ldo13_vrset_END (6)
#define PMIC_LDO13_14_CTRL_ldo13_ocp_enn_START (7)
#define PMIC_LDO13_14_CTRL_ldo13_ocp_enn_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo16_vrset : 3;
        unsigned char ldo16_ocp_enn : 1;
        unsigned char ldo15_vrset : 3;
        unsigned char ldo15_ocp_enn : 1;
    } reg;
} PMIC_LDO15_16_CTRL_UNION;
#endif
#define PMIC_LDO15_16_CTRL_ldo16_vrset_START (0)
#define PMIC_LDO15_16_CTRL_ldo16_vrset_END (2)
#define PMIC_LDO15_16_CTRL_ldo16_ocp_enn_START (3)
#define PMIC_LDO15_16_CTRL_ldo16_ocp_enn_END (3)
#define PMIC_LDO15_16_CTRL_ldo15_vrset_START (4)
#define PMIC_LDO15_16_CTRL_ldo15_vrset_END (6)
#define PMIC_LDO15_16_CTRL_ldo15_ocp_enn_START (7)
#define PMIC_LDO15_16_CTRL_ldo15_ocp_enn_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo17_iss_en : 1;
        unsigned char ldo17_vrset : 3;
        unsigned char ldo17_ocp_enn : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_LDO17_CTRL_UNION;
#endif
#define PMIC_LDO17_CTRL_ldo17_iss_en_START (0)
#define PMIC_LDO17_CTRL_ldo17_iss_en_END (0)
#define PMIC_LDO17_CTRL_ldo17_vrset_START (1)
#define PMIC_LDO17_CTRL_ldo17_vrset_END (3)
#define PMIC_LDO17_CTRL_ldo17_ocp_enn_START (4)
#define PMIC_LDO17_CTRL_ldo17_ocp_enn_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo18_vrset : 3;
        unsigned char ldo18_ocp_enn : 1;
        unsigned char reserved : 4;
    } reg;
} PMIC_LDO18_CTRL0_UNION;
#endif
#define PMIC_LDO18_CTRL0_ldo18_vrset_START (0)
#define PMIC_LDO18_CTRL0_ldo18_vrset_END (2)
#define PMIC_LDO18_CTRL0_ldo18_ocp_enn_START (3)
#define PMIC_LDO18_CTRL0_ldo18_ocp_enn_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo18_psrr2_set : 3;
        unsigned char ldo18_psrr1_set : 3;
        unsigned char ldo18_psrr_en : 1;
        unsigned char reserved : 1;
    } reg;
} PMIC_LDO18_CTRL1_UNION;
#endif
#define PMIC_LDO18_CTRL1_ldo18_psrr2_set_START (0)
#define PMIC_LDO18_CTRL1_ldo18_psrr2_set_END (2)
#define PMIC_LDO18_CTRL1_ldo18_psrr1_set_START (3)
#define PMIC_LDO18_CTRL1_ldo18_psrr1_set_END (5)
#define PMIC_LDO18_CTRL1_ldo18_psrr_en_START (6)
#define PMIC_LDO18_CTRL1_ldo18_psrr_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo19_vrset : 3;
        unsigned char ldo19_ocp_enn : 1;
        unsigned char ldo19_iss_en : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_LDO_19_CTRL1_UNION;
#endif
#define PMIC_LDO_19_CTRL1_ldo19_vrset_START (0)
#define PMIC_LDO_19_CTRL1_ldo19_vrset_END (2)
#define PMIC_LDO_19_CTRL1_ldo19_ocp_enn_START (3)
#define PMIC_LDO_19_CTRL1_ldo19_ocp_enn_END (3)
#define PMIC_LDO_19_CTRL1_ldo19_iss_en_START (4)
#define PMIC_LDO_19_CTRL1_ldo19_iss_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo19_psrr2_set : 3;
        unsigned char ldo19_psrr1_set : 3;
        unsigned char ldo19_psrr_en : 1;
        unsigned char reserved : 1;
    } reg;
} PMIC_LDO_19_CTRL2_UNION;
#endif
#define PMIC_LDO_19_CTRL2_ldo19_psrr2_set_START (0)
#define PMIC_LDO_19_CTRL2_ldo19_psrr2_set_END (2)
#define PMIC_LDO_19_CTRL2_ldo19_psrr1_set_START (3)
#define PMIC_LDO_19_CTRL2_ldo19_psrr1_set_END (5)
#define PMIC_LDO_19_CTRL2_ldo19_psrr_en_START (6)
#define PMIC_LDO_19_CTRL2_ldo19_psrr_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo19_ocps_en : 1;
        unsigned char ldo19_bw_en : 1;
        unsigned char ldo19_vgpr_en : 1;
        unsigned char ldo19_comp : 3;
        unsigned char reserved : 2;
    } reg;
} PMIC_LDO_19_CTRL3_UNION;
#endif
#define PMIC_LDO_19_CTRL3_ldo19_ocps_en_START (0)
#define PMIC_LDO_19_CTRL3_ldo19_ocps_en_END (0)
#define PMIC_LDO_19_CTRL3_ldo19_bw_en_START (1)
#define PMIC_LDO_19_CTRL3_ldo19_bw_en_END (1)
#define PMIC_LDO_19_CTRL3_ldo19_vgpr_en_START (2)
#define PMIC_LDO_19_CTRL3_ldo19_vgpr_en_END (2)
#define PMIC_LDO_19_CTRL3_ldo19_comp_START (3)
#define PMIC_LDO_19_CTRL3_ldo19_comp_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo20_vrset : 3;
        unsigned char ldo20_ocp_enn : 1;
        unsigned char ldo20_iss_en : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_LDO20_CTRL1_UNION;
#endif
#define PMIC_LDO20_CTRL1_ldo20_vrset_START (0)
#define PMIC_LDO20_CTRL1_ldo20_vrset_END (2)
#define PMIC_LDO20_CTRL1_ldo20_ocp_enn_START (3)
#define PMIC_LDO20_CTRL1_ldo20_ocp_enn_END (3)
#define PMIC_LDO20_CTRL1_ldo20_iss_en_START (4)
#define PMIC_LDO20_CTRL1_ldo20_iss_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo20_psrr2_set : 3;
        unsigned char ldo20_psrr1_set : 3;
        unsigned char ldo20_psrr_en : 1;
        unsigned char reserved : 1;
    } reg;
} PMIC_LDO20_CTRL2_UNION;
#endif
#define PMIC_LDO20_CTRL2_ldo20_psrr2_set_START (0)
#define PMIC_LDO20_CTRL2_ldo20_psrr2_set_END (2)
#define PMIC_LDO20_CTRL2_ldo20_psrr1_set_START (3)
#define PMIC_LDO20_CTRL2_ldo20_psrr1_set_END (5)
#define PMIC_LDO20_CTRL2_ldo20_psrr_en_START (6)
#define PMIC_LDO20_CTRL2_ldo20_psrr_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo20_ocps_en : 1;
        unsigned char ldo20_bw_en : 1;
        unsigned char ldo20_vgpr_en : 1;
        unsigned char ldo20_comp : 3;
        unsigned char reserved : 2;
    } reg;
} PMIC_LDO20_CTRL3_UNION;
#endif
#define PMIC_LDO20_CTRL3_ldo20_ocps_en_START (0)
#define PMIC_LDO20_CTRL3_ldo20_ocps_en_END (0)
#define PMIC_LDO20_CTRL3_ldo20_bw_en_START (1)
#define PMIC_LDO20_CTRL3_ldo20_bw_en_END (1)
#define PMIC_LDO20_CTRL3_ldo20_vgpr_en_START (2)
#define PMIC_LDO20_CTRL3_ldo20_vgpr_en_END (2)
#define PMIC_LDO20_CTRL3_ldo20_comp_START (3)
#define PMIC_LDO20_CTRL3_ldo20_comp_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo21_vrset : 3;
        unsigned char ldo21_ocp_enn : 1;
        unsigned char ldo21_iss_en : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_LDO21_CTRL0_UNION;
#endif
#define PMIC_LDO21_CTRL0_ldo21_vrset_START (0)
#define PMIC_LDO21_CTRL0_ldo21_vrset_END (2)
#define PMIC_LDO21_CTRL0_ldo21_ocp_enn_START (3)
#define PMIC_LDO21_CTRL0_ldo21_ocp_enn_END (3)
#define PMIC_LDO21_CTRL0_ldo21_iss_en_START (4)
#define PMIC_LDO21_CTRL0_ldo21_iss_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo21_psrr2_set : 3;
        unsigned char ldo21_psrr1_set : 3;
        unsigned char ldo21_psrr_en : 1;
        unsigned char reserved : 1;
    } reg;
} PMIC_LDO21_CTRL1_UNION;
#endif
#define PMIC_LDO21_CTRL1_ldo21_psrr2_set_START (0)
#define PMIC_LDO21_CTRL1_ldo21_psrr2_set_END (2)
#define PMIC_LDO21_CTRL1_ldo21_psrr1_set_START (3)
#define PMIC_LDO21_CTRL1_ldo21_psrr1_set_END (5)
#define PMIC_LDO21_CTRL1_ldo21_psrr_en_START (6)
#define PMIC_LDO21_CTRL1_ldo21_psrr_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo22_vrset : 3;
        unsigned char ldo22_ocp_enn : 1;
        unsigned char reserved : 4;
    } reg;
} PMIC_LDO22_CTRL0_UNION;
#endif
#define PMIC_LDO22_CTRL0_ldo22_vrset_START (0)
#define PMIC_LDO22_CTRL0_ldo22_vrset_END (2)
#define PMIC_LDO22_CTRL0_ldo22_ocp_enn_START (3)
#define PMIC_LDO22_CTRL0_ldo22_ocp_enn_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo22_ref_buf_bypass : 1;
        unsigned char ldo22_psrr2_set : 3;
        unsigned char ldo22_psrr1_set : 3;
        unsigned char ldo22_psrr_en : 1;
    } reg;
} PMIC_LDO22_CTRL1_UNION;
#endif
#define PMIC_LDO22_CTRL1_ldo22_ref_buf_bypass_START (0)
#define PMIC_LDO22_CTRL1_ldo22_ref_buf_bypass_END (0)
#define PMIC_LDO22_CTRL1_ldo22_psrr2_set_START (1)
#define PMIC_LDO22_CTRL1_ldo22_psrr2_set_END (3)
#define PMIC_LDO22_CTRL1_ldo22_psrr1_set_START (4)
#define PMIC_LDO22_CTRL1_ldo22_psrr1_set_END (6)
#define PMIC_LDO22_CTRL1_ldo22_psrr_en_START (7)
#define PMIC_LDO22_CTRL1_ldo22_psrr_en_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo22_ocps_en : 1;
        unsigned char ldo22_bw_en : 1;
        unsigned char ldo22_vgpr_en : 1;
        unsigned char ldo22_ref_buf_rset : 2;
        unsigned char ldo22_comp : 3;
    } reg;
} PMIC_LDO22_CTRL2_UNION;
#endif
#define PMIC_LDO22_CTRL2_ldo22_ocps_en_START (0)
#define PMIC_LDO22_CTRL2_ldo22_ocps_en_END (0)
#define PMIC_LDO22_CTRL2_ldo22_bw_en_START (1)
#define PMIC_LDO22_CTRL2_ldo22_bw_en_END (1)
#define PMIC_LDO22_CTRL2_ldo22_vgpr_en_START (2)
#define PMIC_LDO22_CTRL2_ldo22_vgpr_en_END (2)
#define PMIC_LDO22_CTRL2_ldo22_ref_buf_rset_START (3)
#define PMIC_LDO22_CTRL2_ldo22_ref_buf_rset_END (4)
#define PMIC_LDO22_CTRL2_ldo22_comp_START (5)
#define PMIC_LDO22_CTRL2_ldo22_comp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo23_vrset : 3;
        unsigned char ldo23_ocp_enn : 1;
        unsigned char reserved : 4;
    } reg;
} PMIC_LDO23_CTRL_UNION;
#endif
#define PMIC_LDO23_CTRL_ldo23_vrset_START (0)
#define PMIC_LDO23_CTRL_ldo23_vrset_END (2)
#define PMIC_LDO23_CTRL_ldo23_ocp_enn_START (3)
#define PMIC_LDO23_CTRL_ldo23_ocp_enn_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo25_vrset : 3;
        unsigned char ldo25_ocp_enn : 1;
        unsigned char ldo24_vrset : 3;
        unsigned char ldo24_ocp_enn : 1;
    } reg;
} PMIC_LDO24_25_CTRL_UNION;
#endif
#define PMIC_LDO24_25_CTRL_ldo25_vrset_START (0)
#define PMIC_LDO24_25_CTRL_ldo25_vrset_END (2)
#define PMIC_LDO24_25_CTRL_ldo25_ocp_enn_START (3)
#define PMIC_LDO24_25_CTRL_ldo25_ocp_enn_END (3)
#define PMIC_LDO24_25_CTRL_ldo24_vrset_START (4)
#define PMIC_LDO24_25_CTRL_ldo24_vrset_END (6)
#define PMIC_LDO24_25_CTRL_ldo24_ocp_enn_START (7)
#define PMIC_LDO24_25_CTRL_ldo24_ocp_enn_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo26_vrset : 3;
        unsigned char ldo26_ocp_enn : 1;
        unsigned char ldo26_i_sst : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_LDO26_CTRL_UNION;
#endif
#define PMIC_LDO26_CTRL_ldo26_vrset_START (0)
#define PMIC_LDO26_CTRL_ldo26_vrset_END (2)
#define PMIC_LDO26_CTRL_ldo26_ocp_enn_START (3)
#define PMIC_LDO26_CTRL_ldo26_ocp_enn_END (3)
#define PMIC_LDO26_CTRL_ldo26_i_sst_START (4)
#define PMIC_LDO26_CTRL_ldo26_i_sst_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo27_vrset : 3;
        unsigned char ldo27_ocp_enn : 1;
        unsigned char reserved : 4;
    } reg;
} PMIC_LDO27_CTRL_UNION;
#endif
#define PMIC_LDO27_CTRL_ldo27_vrset_START (0)
#define PMIC_LDO27_CTRL_ldo27_vrset_END (2)
#define PMIC_LDO27_CTRL_ldo27_ocp_enn_START (3)
#define PMIC_LDO27_CTRL_ldo27_ocp_enn_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo29_vrset : 3;
        unsigned char ldo29_ocp_enn : 1;
        unsigned char ldo28_vrset : 3;
        unsigned char ldo28_ocp_enn : 1;
    } reg;
} PMIC_LDO28_29_CTRL_UNION;
#endif
#define PMIC_LDO28_29_CTRL_ldo29_vrset_START (0)
#define PMIC_LDO28_29_CTRL_ldo29_vrset_END (2)
#define PMIC_LDO28_29_CTRL_ldo29_ocp_enn_START (3)
#define PMIC_LDO28_29_CTRL_ldo29_ocp_enn_END (3)
#define PMIC_LDO28_29_CTRL_ldo28_vrset_START (4)
#define PMIC_LDO28_29_CTRL_ldo28_vrset_END (6)
#define PMIC_LDO28_29_CTRL_ldo28_ocp_enn_START (7)
#define PMIC_LDO28_29_CTRL_ldo28_ocp_enn_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo30_ocps_en : 1;
        unsigned char ldo30_vrset : 3;
        unsigned char ldo30_ocp_enn : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_LDO30_CTRL_UNION;
#endif
#define PMIC_LDO30_CTRL_ldo30_ocps_en_START (0)
#define PMIC_LDO30_CTRL_ldo30_ocps_en_END (0)
#define PMIC_LDO30_CTRL_ldo30_vrset_START (1)
#define PMIC_LDO30_CTRL_ldo30_vrset_END (3)
#define PMIC_LDO30_CTRL_ldo30_ocp_enn_START (4)
#define PMIC_LDO30_CTRL_ldo30_ocp_enn_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo32_vrset : 3;
        unsigned char ldo32_ocp_enn : 1;
        unsigned char ldo32_iss_en : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_LDO32_CTRL1_UNION;
#endif
#define PMIC_LDO32_CTRL1_ldo32_vrset_START (0)
#define PMIC_LDO32_CTRL1_ldo32_vrset_END (2)
#define PMIC_LDO32_CTRL1_ldo32_ocp_enn_START (3)
#define PMIC_LDO32_CTRL1_ldo32_ocp_enn_END (3)
#define PMIC_LDO32_CTRL1_ldo32_iss_en_START (4)
#define PMIC_LDO32_CTRL1_ldo32_iss_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo32_psrr2_set : 3;
        unsigned char ldo32_psrr1_set : 3;
        unsigned char ldo32_psrr_en : 1;
        unsigned char reserved : 1;
    } reg;
} PMIC_LDO32_CTRL2_UNION;
#endif
#define PMIC_LDO32_CTRL2_ldo32_psrr2_set_START (0)
#define PMIC_LDO32_CTRL2_ldo32_psrr2_set_END (2)
#define PMIC_LDO32_CTRL2_ldo32_psrr1_set_START (3)
#define PMIC_LDO32_CTRL2_ldo32_psrr1_set_END (5)
#define PMIC_LDO32_CTRL2_ldo32_psrr_en_START (6)
#define PMIC_LDO32_CTRL2_ldo32_psrr_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo32_ocps_en : 1;
        unsigned char ldo32_bw_en : 1;
        unsigned char ldo32_vgpr_en : 1;
        unsigned char ldo32_comp : 3;
        unsigned char reserved : 2;
    } reg;
} PMIC_LDO32_CTRL3_UNION;
#endif
#define PMIC_LDO32_CTRL3_ldo32_ocps_en_START (0)
#define PMIC_LDO32_CTRL3_ldo32_ocps_en_END (0)
#define PMIC_LDO32_CTRL3_ldo32_bw_en_START (1)
#define PMIC_LDO32_CTRL3_ldo32_bw_en_END (1)
#define PMIC_LDO32_CTRL3_ldo32_vgpr_en_START (2)
#define PMIC_LDO32_CTRL3_ldo32_vgpr_en_END (2)
#define PMIC_LDO32_CTRL3_ldo32_comp_START (3)
#define PMIC_LDO32_CTRL3_ldo32_comp_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo33_vrset : 3;
        unsigned char ldo33_ocp_enn : 1;
        unsigned char ldo33_iss_en : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_LDO33_CTRL_UNION;
#endif
#define PMIC_LDO33_CTRL_ldo33_vrset_START (0)
#define PMIC_LDO33_CTRL_ldo33_vrset_END (2)
#define PMIC_LDO33_CTRL_ldo33_ocp_enn_START (3)
#define PMIC_LDO33_CTRL_ldo33_ocp_enn_END (3)
#define PMIC_LDO33_CTRL_ldo33_iss_en_START (4)
#define PMIC_LDO33_CTRL_ldo33_iss_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo35_vrset : 3;
        unsigned char ldo35_ocp_enn : 1;
        unsigned char ldo34_vrset : 3;
        unsigned char ldo34_ocp_enn : 1;
    } reg;
} PMIC_LDO34_35_CTRL_UNION;
#endif
#define PMIC_LDO34_35_CTRL_ldo35_vrset_START (0)
#define PMIC_LDO34_35_CTRL_ldo35_vrset_END (2)
#define PMIC_LDO34_35_CTRL_ldo35_ocp_enn_START (3)
#define PMIC_LDO34_35_CTRL_ldo35_ocp_enn_END (3)
#define PMIC_LDO34_35_CTRL_ldo34_vrset_START (4)
#define PMIC_LDO34_35_CTRL_ldo34_vrset_END (6)
#define PMIC_LDO34_35_CTRL_ldo34_ocp_enn_START (7)
#define PMIC_LDO34_35_CTRL_ldo34_ocp_enn_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo36_vrset : 3;
        unsigned char ldo36_ocp_enn : 1;
        unsigned char reserved : 4;
    } reg;
} PMIC_LDO36_CTRL_UNION;
#endif
#define PMIC_LDO36_CTRL_ldo36_vrset_START (0)
#define PMIC_LDO36_CTRL_ldo36_vrset_END (2)
#define PMIC_LDO36_CTRL_ldo36_ocp_enn_START (3)
#define PMIC_LDO36_CTRL_ldo36_ocp_enn_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo_buf_curr_sel : 2;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO_BUF_CTRL_UNION;
#endif
#define PMIC_LDO_BUF_CTRL_ldo_buf_curr_sel_START (0)
#define PMIC_LDO_BUF_CTRL_ldo_buf_curr_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo_reserve0 : 8;
    } reg;
} PMIC_LDO_RESERVE0_UNION;
#endif
#define PMIC_LDO_RESERVE0_ldo_reserve0_START (0)
#define PMIC_LDO_RESERVE0_ldo_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo_reserve1 : 8;
    } reg;
} PMIC_LDO_RESERVE1_UNION;
#endif
#define PMIC_LDO_RESERVE1_ldo_reserve1_START (0)
#define PMIC_LDO_RESERVE1_ldo_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck3_ocp_auto_stop : 2;
        unsigned char buck2_ocp_auto_stop : 2;
        unsigned char buck1_ocp_auto_stop : 2;
        unsigned char buck0_ocp_auto_stop : 2;
    } reg;
} PMIC_BUCK0_3_OCP_CTRL_UNION;
#endif
#define PMIC_BUCK0_3_OCP_CTRL_buck3_ocp_auto_stop_START (0)
#define PMIC_BUCK0_3_OCP_CTRL_buck3_ocp_auto_stop_END (1)
#define PMIC_BUCK0_3_OCP_CTRL_buck2_ocp_auto_stop_START (2)
#define PMIC_BUCK0_3_OCP_CTRL_buck2_ocp_auto_stop_END (3)
#define PMIC_BUCK0_3_OCP_CTRL_buck1_ocp_auto_stop_START (4)
#define PMIC_BUCK0_3_OCP_CTRL_buck1_ocp_auto_stop_END (5)
#define PMIC_BUCK0_3_OCP_CTRL_buck0_ocp_auto_stop_START (6)
#define PMIC_BUCK0_3_OCP_CTRL_buck0_ocp_auto_stop_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck7_ocp_auto_stop : 2;
        unsigned char buck6_ocp_auto_stop : 2;
        unsigned char buck5_ocp_auto_stop : 2;
        unsigned char buck4_ocp_auto_stop : 2;
    } reg;
} PMIC_BUCK4_7_OCP_CTRL_UNION;
#endif
#define PMIC_BUCK4_7_OCP_CTRL_buck7_ocp_auto_stop_START (0)
#define PMIC_BUCK4_7_OCP_CTRL_buck7_ocp_auto_stop_END (1)
#define PMIC_BUCK4_7_OCP_CTRL_buck6_ocp_auto_stop_START (2)
#define PMIC_BUCK4_7_OCP_CTRL_buck6_ocp_auto_stop_END (3)
#define PMIC_BUCK4_7_OCP_CTRL_buck5_ocp_auto_stop_START (4)
#define PMIC_BUCK4_7_OCP_CTRL_buck5_ocp_auto_stop_END (5)
#define PMIC_BUCK4_7_OCP_CTRL_buck4_ocp_auto_stop_START (6)
#define PMIC_BUCK4_7_OCP_CTRL_buck4_ocp_auto_stop_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck8_ocp_auto_stop : 2;
        unsigned char reserved : 6;
    } reg;
} PMIC_BUCK8_OCP_CTRL_UNION;
#endif
#define PMIC_BUCK8_OCP_CTRL_buck8_ocp_auto_stop_START (0)
#define PMIC_BUCK8_OCP_CTRL_buck8_ocp_auto_stop_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo3_ocp_auto_stop : 2;
        unsigned char ldo2_ocp_auto_stop : 2;
        unsigned char ldo1_ocp_auto_stop : 2;
        unsigned char ldo0_ocp_auto_stop : 2;
    } reg;
} PMIC_LDO0_3_OCP_CTRL_UNION;
#endif
#define PMIC_LDO0_3_OCP_CTRL_ldo3_ocp_auto_stop_START (0)
#define PMIC_LDO0_3_OCP_CTRL_ldo3_ocp_auto_stop_END (1)
#define PMIC_LDO0_3_OCP_CTRL_ldo2_ocp_auto_stop_START (2)
#define PMIC_LDO0_3_OCP_CTRL_ldo2_ocp_auto_stop_END (3)
#define PMIC_LDO0_3_OCP_CTRL_ldo1_ocp_auto_stop_START (4)
#define PMIC_LDO0_3_OCP_CTRL_ldo1_ocp_auto_stop_END (5)
#define PMIC_LDO0_3_OCP_CTRL_ldo0_ocp_auto_stop_START (6)
#define PMIC_LDO0_3_OCP_CTRL_ldo0_ocp_auto_stop_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo7_ocp_auto_stop : 2;
        unsigned char ldo6_ocp_auto_stop : 2;
        unsigned char ldo5_ocp_auto_stop : 2;
        unsigned char ldo4_ocp_auto_stop : 2;
    } reg;
} PMIC_LDO4_7_OCP_CTRL_UNION;
#endif
#define PMIC_LDO4_7_OCP_CTRL_ldo7_ocp_auto_stop_START (0)
#define PMIC_LDO4_7_OCP_CTRL_ldo7_ocp_auto_stop_END (1)
#define PMIC_LDO4_7_OCP_CTRL_ldo6_ocp_auto_stop_START (2)
#define PMIC_LDO4_7_OCP_CTRL_ldo6_ocp_auto_stop_END (3)
#define PMIC_LDO4_7_OCP_CTRL_ldo5_ocp_auto_stop_START (4)
#define PMIC_LDO4_7_OCP_CTRL_ldo5_ocp_auto_stop_END (5)
#define PMIC_LDO4_7_OCP_CTRL_ldo4_ocp_auto_stop_START (6)
#define PMIC_LDO4_7_OCP_CTRL_ldo4_ocp_auto_stop_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo12_ocp_auto_stop : 2;
        unsigned char ldo11_ocp_auto_stop : 2;
        unsigned char ldo9_ocp_auto_stop : 2;
        unsigned char ldo8_ocp_auto_stop : 2;
    } reg;
} PMIC_LDO8_12_OCP_CTRL_UNION;
#endif
#define PMIC_LDO8_12_OCP_CTRL_ldo12_ocp_auto_stop_START (0)
#define PMIC_LDO8_12_OCP_CTRL_ldo12_ocp_auto_stop_END (1)
#define PMIC_LDO8_12_OCP_CTRL_ldo11_ocp_auto_stop_START (2)
#define PMIC_LDO8_12_OCP_CTRL_ldo11_ocp_auto_stop_END (3)
#define PMIC_LDO8_12_OCP_CTRL_ldo9_ocp_auto_stop_START (4)
#define PMIC_LDO8_12_OCP_CTRL_ldo9_ocp_auto_stop_END (5)
#define PMIC_LDO8_12_OCP_CTRL_ldo8_ocp_auto_stop_START (6)
#define PMIC_LDO8_12_OCP_CTRL_ldo8_ocp_auto_stop_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo16_ocp_auto_stop : 2;
        unsigned char ldo15_ocp_auto_stop : 2;
        unsigned char ldo14_ocp_auto_stop : 2;
        unsigned char ldo13_ocp_auto_stop : 2;
    } reg;
} PMIC_LDO13_16_OCP_CTRL_UNION;
#endif
#define PMIC_LDO13_16_OCP_CTRL_ldo16_ocp_auto_stop_START (0)
#define PMIC_LDO13_16_OCP_CTRL_ldo16_ocp_auto_stop_END (1)
#define PMIC_LDO13_16_OCP_CTRL_ldo15_ocp_auto_stop_START (2)
#define PMIC_LDO13_16_OCP_CTRL_ldo15_ocp_auto_stop_END (3)
#define PMIC_LDO13_16_OCP_CTRL_ldo14_ocp_auto_stop_START (4)
#define PMIC_LDO13_16_OCP_CTRL_ldo14_ocp_auto_stop_END (5)
#define PMIC_LDO13_16_OCP_CTRL_ldo13_ocp_auto_stop_START (6)
#define PMIC_LDO13_16_OCP_CTRL_ldo13_ocp_auto_stop_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo20_ocp_auto_stop : 2;
        unsigned char ldo19_ocp_auto_stop : 2;
        unsigned char ldo18_ocp_auto_stop : 2;
        unsigned char ldo17_ocp_auto_stop : 2;
    } reg;
} PMIC_LDO17_20_OCP_CTRL_UNION;
#endif
#define PMIC_LDO17_20_OCP_CTRL_ldo20_ocp_auto_stop_START (0)
#define PMIC_LDO17_20_OCP_CTRL_ldo20_ocp_auto_stop_END (1)
#define PMIC_LDO17_20_OCP_CTRL_ldo19_ocp_auto_stop_START (2)
#define PMIC_LDO17_20_OCP_CTRL_ldo19_ocp_auto_stop_END (3)
#define PMIC_LDO17_20_OCP_CTRL_ldo18_ocp_auto_stop_START (4)
#define PMIC_LDO17_20_OCP_CTRL_ldo18_ocp_auto_stop_END (5)
#define PMIC_LDO17_20_OCP_CTRL_ldo17_ocp_auto_stop_START (6)
#define PMIC_LDO17_20_OCP_CTRL_ldo17_ocp_auto_stop_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo24_ocp_auto_stop : 2;
        unsigned char ldo23_ocp_auto_stop : 2;
        unsigned char ldo22_ocp_auto_stop : 2;
        unsigned char ldo21_ocp_auto_stop : 2;
    } reg;
} PMIC_LDO21_24_OCP_CTRL_UNION;
#endif
#define PMIC_LDO21_24_OCP_CTRL_ldo24_ocp_auto_stop_START (0)
#define PMIC_LDO21_24_OCP_CTRL_ldo24_ocp_auto_stop_END (1)
#define PMIC_LDO21_24_OCP_CTRL_ldo23_ocp_auto_stop_START (2)
#define PMIC_LDO21_24_OCP_CTRL_ldo23_ocp_auto_stop_END (3)
#define PMIC_LDO21_24_OCP_CTRL_ldo22_ocp_auto_stop_START (4)
#define PMIC_LDO21_24_OCP_CTRL_ldo22_ocp_auto_stop_END (5)
#define PMIC_LDO21_24_OCP_CTRL_ldo21_ocp_auto_stop_START (6)
#define PMIC_LDO21_24_OCP_CTRL_ldo21_ocp_auto_stop_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo28_ocp_auto_stop : 2;
        unsigned char ldo27_ocp_auto_stop : 2;
        unsigned char ldo26_ocp_auto_stop : 2;
        unsigned char ldo25_ocp_auto_stop : 2;
    } reg;
} PMIC_LDO25_28_OCP_CTRL_UNION;
#endif
#define PMIC_LDO25_28_OCP_CTRL_ldo28_ocp_auto_stop_START (0)
#define PMIC_LDO25_28_OCP_CTRL_ldo28_ocp_auto_stop_END (1)
#define PMIC_LDO25_28_OCP_CTRL_ldo27_ocp_auto_stop_START (2)
#define PMIC_LDO25_28_OCP_CTRL_ldo27_ocp_auto_stop_END (3)
#define PMIC_LDO25_28_OCP_CTRL_ldo26_ocp_auto_stop_START (4)
#define PMIC_LDO25_28_OCP_CTRL_ldo26_ocp_auto_stop_END (5)
#define PMIC_LDO25_28_OCP_CTRL_ldo25_ocp_auto_stop_START (6)
#define PMIC_LDO25_28_OCP_CTRL_ldo25_ocp_auto_stop_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo33_ocp_auto_stop : 2;
        unsigned char ldo32_ocp_auto_stop : 2;
        unsigned char ldo30_ocp_auto_stop : 2;
        unsigned char ldo29_ocp_auto_stop : 2;
    } reg;
} PMIC_LDO29_33_OCP_CTRL_UNION;
#endif
#define PMIC_LDO29_33_OCP_CTRL_ldo33_ocp_auto_stop_START (0)
#define PMIC_LDO29_33_OCP_CTRL_ldo33_ocp_auto_stop_END (1)
#define PMIC_LDO29_33_OCP_CTRL_ldo32_ocp_auto_stop_START (2)
#define PMIC_LDO29_33_OCP_CTRL_ldo32_ocp_auto_stop_END (3)
#define PMIC_LDO29_33_OCP_CTRL_ldo30_ocp_auto_stop_START (4)
#define PMIC_LDO29_33_OCP_CTRL_ldo30_ocp_auto_stop_END (5)
#define PMIC_LDO29_33_OCP_CTRL_ldo29_ocp_auto_stop_START (6)
#define PMIC_LDO29_33_OCP_CTRL_ldo29_ocp_auto_stop_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo36_ocp_auto_stop : 2;
        unsigned char ldo34_ocp_auto_stop : 2;
        unsigned char reserved : 4;
    } reg;
} PMIC_LDO34_36_OCP_CTRL_UNION;
#endif
#define PMIC_LDO34_36_OCP_CTRL_ldo36_ocp_auto_stop_START (0)
#define PMIC_LDO34_36_OCP_CTRL_ldo36_ocp_auto_stop_END (1)
#define PMIC_LDO34_36_OCP_CTRL_ldo34_ocp_auto_stop_START (2)
#define PMIC_LDO34_36_OCP_CTRL_ldo34_ocp_auto_stop_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo_buff_scp_auto_stop : 2;
        unsigned char reserved : 6;
    } reg;
} PMIC_LDO_BUFF_SCP_CTRL_UNION;
#endif
#define PMIC_LDO_BUFF_SCP_CTRL_ldo_buff_scp_auto_stop_START (0)
#define PMIC_LDO_BUFF_SCP_CTRL_ldo_buff_scp_auto_stop_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck3_scp_auto_stop : 2;
        unsigned char buck2_scp_auto_stop : 2;
        unsigned char buck1_scp_auto_stop : 2;
        unsigned char buck0_scp_auto_stop : 2;
    } reg;
} PMIC_BUCK0_3_SCP_CTRL_UNION;
#endif
#define PMIC_BUCK0_3_SCP_CTRL_buck3_scp_auto_stop_START (0)
#define PMIC_BUCK0_3_SCP_CTRL_buck3_scp_auto_stop_END (1)
#define PMIC_BUCK0_3_SCP_CTRL_buck2_scp_auto_stop_START (2)
#define PMIC_BUCK0_3_SCP_CTRL_buck2_scp_auto_stop_END (3)
#define PMIC_BUCK0_3_SCP_CTRL_buck1_scp_auto_stop_START (4)
#define PMIC_BUCK0_3_SCP_CTRL_buck1_scp_auto_stop_END (5)
#define PMIC_BUCK0_3_SCP_CTRL_buck0_scp_auto_stop_START (6)
#define PMIC_BUCK0_3_SCP_CTRL_buck0_scp_auto_stop_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck7_scp_auto_stop : 2;
        unsigned char buck6_scp_auto_stop : 2;
        unsigned char buck5_scp_auto_stop : 2;
        unsigned char buck4_scp_auto_stop : 2;
    } reg;
} PMIC_BUCK4_7_SCP_CTRL_UNION;
#endif
#define PMIC_BUCK4_7_SCP_CTRL_buck7_scp_auto_stop_START (0)
#define PMIC_BUCK4_7_SCP_CTRL_buck7_scp_auto_stop_END (1)
#define PMIC_BUCK4_7_SCP_CTRL_buck6_scp_auto_stop_START (2)
#define PMIC_BUCK4_7_SCP_CTRL_buck6_scp_auto_stop_END (3)
#define PMIC_BUCK4_7_SCP_CTRL_buck5_scp_auto_stop_START (4)
#define PMIC_BUCK4_7_SCP_CTRL_buck5_scp_auto_stop_END (5)
#define PMIC_BUCK4_7_SCP_CTRL_buck4_scp_auto_stop_START (6)
#define PMIC_BUCK4_7_SCP_CTRL_buck4_scp_auto_stop_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck8_scp_auto_stop : 2;
        unsigned char reserved : 6;
    } reg;
} PMIC_BUCK8_SCP_CTRL_UNION;
#endif
#define PMIC_BUCK8_SCP_CTRL_buck8_scp_auto_stop_START (0)
#define PMIC_BUCK8_SCP_CTRL_buck8_scp_auto_stop_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sys_ctrl_reserve : 8;
    } reg;
} PMIC_SYS_CTRL_RESERVE_UNION;
#endif
#define PMIC_SYS_CTRL_RESERVE_sys_ctrl_reserve_START (0)
#define PMIC_SYS_CTRL_RESERVE_sys_ctrl_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo_ocp_deb_sel : 2;
        unsigned char buck_scp_deb_sel : 2;
        unsigned char buck_ocp_deb_sel : 2;
        unsigned char reserved : 2;
    } reg;
} PMIC_OCP_DEB_CTRL0_UNION;
#endif
#define PMIC_OCP_DEB_CTRL0_ldo_ocp_deb_sel_START (0)
#define PMIC_OCP_DEB_CTRL0_ldo_ocp_deb_sel_END (1)
#define PMIC_OCP_DEB_CTRL0_buck_scp_deb_sel_START (2)
#define PMIC_OCP_DEB_CTRL0_buck_scp_deb_sel_END (3)
#define PMIC_OCP_DEB_CTRL0_buck_ocp_deb_sel_START (4)
#define PMIC_OCP_DEB_CTRL0_buck_ocp_deb_sel_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char vin_ldoh_deb_sel : 2;
        unsigned char ldo_buff_scp_deb_sel : 2;
        unsigned char reserved : 4;
    } reg;
} PMIC_OCP_DEB_CTRL1_UNION;
#endif
#define PMIC_OCP_DEB_CTRL1_vin_ldoh_deb_sel_START (0)
#define PMIC_OCP_DEB_CTRL1_vin_ldoh_deb_sel_END (1)
#define PMIC_OCP_DEB_CTRL1_ldo_buff_scp_deb_sel_START (2)
#define PMIC_OCP_DEB_CTRL1_ldo_buff_scp_deb_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char vsys_pwroff_deb_sel : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_PWROFF_DEB_CTRL_UNION;
#endif
#define PMIC_PWROFF_DEB_CTRL_vsys_pwroff_deb_sel_START (0)
#define PMIC_PWROFF_DEB_CTRL_vsys_pwroff_deb_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char en_vin_ldoh_deb : 1;
        unsigned char en_ldo_buff_scp_deb : 1;
        unsigned char en_ldo_ocp_deb : 1;
        unsigned char en_buck_scp_deb : 1;
        unsigned char en_buck_ocp_deb : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_OCP_SCP_ONOFF_UNION;
#endif
#define PMIC_OCP_SCP_ONOFF_en_vin_ldoh_deb_START (0)
#define PMIC_OCP_SCP_ONOFF_en_vin_ldoh_deb_END (0)
#define PMIC_OCP_SCP_ONOFF_en_ldo_buff_scp_deb_START (1)
#define PMIC_OCP_SCP_ONOFF_en_ldo_buff_scp_deb_END (1)
#define PMIC_OCP_SCP_ONOFF_en_ldo_ocp_deb_START (2)
#define PMIC_OCP_SCP_ONOFF_en_ldo_ocp_deb_END (2)
#define PMIC_OCP_SCP_ONOFF_en_buck_scp_deb_START (3)
#define PMIC_OCP_SCP_ONOFF_en_buck_scp_deb_END (3)
#define PMIC_OCP_SCP_ONOFF_en_buck_ocp_deb_START (4)
#define PMIC_OCP_SCP_ONOFF_en_buck_ocp_deb_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xo_abb_drv : 2;
        unsigned char reserved : 6;
    } reg;
} PMIC_CLK_ABB_CTRL0_UNION;
#endif
#define PMIC_CLK_ABB_CTRL0_xo_abb_drv_START (0)
#define PMIC_CLK_ABB_CTRL0_xo_abb_drv_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xo_wifi_drv : 2;
        unsigned char reserved : 6;
    } reg;
} PMIC_CLK_WIFI_CTRL0_UNION;
#endif
#define PMIC_CLK_WIFI_CTRL0_xo_wifi_drv_START (0)
#define PMIC_CLK_WIFI_CTRL0_xo_wifi_drv_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xo_nfc_drv : 2;
        unsigned char reserved : 6;
    } reg;
} PMIC_CLK_NFC_CTRL0_UNION;
#endif
#define PMIC_CLK_NFC_CTRL0_xo_nfc_drv_START (0)
#define PMIC_CLK_NFC_CTRL0_xo_nfc_drv_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xo_rf0_drv : 2;
        unsigned char reserved : 6;
    } reg;
} PMIC_CLK_RF0_CTRL0_UNION;
#endif
#define PMIC_CLK_RF0_CTRL0_xo_rf0_drv_START (0)
#define PMIC_CLK_RF0_CTRL0_xo_rf0_drv_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xo_rf1_drv : 2;
        unsigned char reserved : 6;
    } reg;
} PMIC_CLK_RF1_CTRL0_UNION;
#endif
#define PMIC_CLK_RF1_CTRL0_xo_rf1_drv_START (0)
#define PMIC_CLK_RF1_CTRL0_xo_rf1_drv_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xo_sys_usb_drv : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_CLK_SYS_USB_CTRL_UNION;
#endif
#define PMIC_CLK_SYS_USB_CTRL_xo_sys_usb_drv_START (0)
#define PMIC_CLK_SYS_USB_CTRL_xo_sys_usb_drv_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xo_usb_drv : 2;
        unsigned char reserved : 6;
    } reg;
} PMIC_CLK_USB_CTRL_UNION;
#endif
#define PMIC_CLK_USB_CTRL_xo_usb_drv_START (0)
#define PMIC_CLK_USB_CTRL_xo_usb_drv_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xo_codec_drv : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_CLK_CODEC_CTRL_UNION;
#endif
#define PMIC_CLK_CODEC_CTRL_xo_codec_drv_START (0)
#define PMIC_CLK_CODEC_CTRL_xo_codec_drv_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xo_core_curr_pmos : 1;
        unsigned char xo_rf1_ph_sel : 1;
        unsigned char xo_delay_sel : 2;
        unsigned char xo_tri_cap : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_CLK_TOP_CTRL0_UNION;
#endif
#define PMIC_CLK_TOP_CTRL0_xo_core_curr_pmos_START (0)
#define PMIC_CLK_TOP_CTRL0_xo_core_curr_pmos_END (0)
#define PMIC_CLK_TOP_CTRL0_xo_rf1_ph_sel_START (1)
#define PMIC_CLK_TOP_CTRL0_xo_rf1_ph_sel_END (1)
#define PMIC_CLK_TOP_CTRL0_xo_delay_sel_START (2)
#define PMIC_CLK_TOP_CTRL0_xo_delay_sel_END (3)
#define PMIC_CLK_TOP_CTRL0_xo_tri_cap_START (4)
#define PMIC_CLK_TOP_CTRL0_xo_tri_cap_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xo_reserve : 8;
    } reg;
} PMIC_CLK_TOP_CTRL1_UNION;
#endif
#define PMIC_CLK_TOP_CTRL1_xo_reserve_START (0)
#define PMIC_CLK_TOP_CTRL1_xo_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} PMIC_CLK_TOP_CTRL2_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char thsd_tmp_set : 2;
        unsigned char reg_thsd_en : 1;
        unsigned char ref_out_sel : 2;
        unsigned char ref_ibias_trim_en : 2;
        unsigned char reserved : 1;
    } reg;
} PMIC_BG_THSD_CTRL0_UNION;
#endif
#define PMIC_BG_THSD_CTRL0_thsd_tmp_set_START (0)
#define PMIC_BG_THSD_CTRL0_thsd_tmp_set_END (1)
#define PMIC_BG_THSD_CTRL0_reg_thsd_en_START (2)
#define PMIC_BG_THSD_CTRL0_reg_thsd_en_END (2)
#define PMIC_BG_THSD_CTRL0_ref_out_sel_START (3)
#define PMIC_BG_THSD_CTRL0_ref_out_sel_END (4)
#define PMIC_BG_THSD_CTRL0_ref_ibias_trim_en_START (5)
#define PMIC_BG_THSD_CTRL0_ref_ibias_trim_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ref_res_sel : 1;
        unsigned char ref_chop_clk_sel : 2;
        unsigned char ref_chop_sel : 1;
        unsigned char reserved : 4;
    } reg;
} PMIC_BG_THSD_CTRL1_UNION;
#endif
#define PMIC_BG_THSD_CTRL1_ref_res_sel_START (0)
#define PMIC_BG_THSD_CTRL1_ref_res_sel_END (0)
#define PMIC_BG_THSD_CTRL1_ref_chop_clk_sel_START (1)
#define PMIC_BG_THSD_CTRL1_ref_chop_clk_sel_END (2)
#define PMIC_BG_THSD_CTRL1_ref_chop_sel_START (3)
#define PMIC_BG_THSD_CTRL1_ref_chop_sel_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ref_reserve : 8;
    } reg;
} PMIC_BG_TEST_UNION;
#endif
#define PMIC_BG_TEST_ref_reserve_START (0)
#define PMIC_BG_TEST_ref_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_eco_in_hd_mask : 1;
        unsigned char reg_sys_clk_hd_mask : 1;
        unsigned char reg_abb_clk_hd_mask : 1;
        unsigned char reg_wifi_clk_hd_mask : 1;
        unsigned char reg_nfc_clk_hd_mask : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_HARDWIRE_CTRL0_UNION;
#endif
#define PMIC_HARDWIRE_CTRL0_reg_eco_in_hd_mask_START (0)
#define PMIC_HARDWIRE_CTRL0_reg_eco_in_hd_mask_END (0)
#define PMIC_HARDWIRE_CTRL0_reg_sys_clk_hd_mask_START (1)
#define PMIC_HARDWIRE_CTRL0_reg_sys_clk_hd_mask_END (1)
#define PMIC_HARDWIRE_CTRL0_reg_abb_clk_hd_mask_START (2)
#define PMIC_HARDWIRE_CTRL0_reg_abb_clk_hd_mask_END (2)
#define PMIC_HARDWIRE_CTRL0_reg_wifi_clk_hd_mask_START (3)
#define PMIC_HARDWIRE_CTRL0_reg_wifi_clk_hd_mask_END (3)
#define PMIC_HARDWIRE_CTRL0_reg_nfc_clk_hd_mask_START (4)
#define PMIC_HARDWIRE_CTRL0_reg_nfc_clk_hd_mask_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_ldo26_hd_mask : 1;
        unsigned char reg_ldo_buf_hd_mask : 1;
        unsigned char reg_ldo29_hd_mask : 1;
        unsigned char reserved : 5;
    } reg;
} PMIC_HARDWIRE_CTRL1_UNION;
#endif
#define PMIC_HARDWIRE_CTRL1_reg_ldo26_hd_mask_START (0)
#define PMIC_HARDWIRE_CTRL1_reg_ldo26_hd_mask_END (0)
#define PMIC_HARDWIRE_CTRL1_reg_ldo_buf_hd_mask_START (1)
#define PMIC_HARDWIRE_CTRL1_reg_ldo_buf_hd_mask_END (1)
#define PMIC_HARDWIRE_CTRL1_reg_ldo29_hd_mask_START (2)
#define PMIC_HARDWIRE_CTRL1_reg_ldo29_hd_mask_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_buck0_vset_hd_mask : 1;
        unsigned char reg_ldo0_2_vset_hd_mask : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_HARDWIRE_CTRL2_UNION;
#endif
#define PMIC_HARDWIRE_CTRL2_reg_buck0_vset_hd_mask_START (0)
#define PMIC_HARDWIRE_CTRL2_reg_buck0_vset_hd_mask_END (0)
#define PMIC_HARDWIRE_CTRL2_reg_ldo0_2_vset_hd_mask_START (1)
#define PMIC_HARDWIRE_CTRL2_reg_ldo0_2_vset_hd_mask_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char peri_en_buck6_on : 1;
        unsigned char peri_en_buck4_on : 1;
        unsigned char peri_en_buck2_on : 1;
        unsigned char peri_en_buck0_on : 1;
        unsigned char reserved : 4;
    } reg;
} PMIC_PERI_CTRL0_UNION;
#endif
#define PMIC_PERI_CTRL0_peri_en_buck6_on_START (0)
#define PMIC_PERI_CTRL0_peri_en_buck6_on_END (0)
#define PMIC_PERI_CTRL0_peri_en_buck4_on_START (1)
#define PMIC_PERI_CTRL0_peri_en_buck4_on_END (1)
#define PMIC_PERI_CTRL0_peri_en_buck2_on_START (2)
#define PMIC_PERI_CTRL0_peri_en_buck2_on_END (2)
#define PMIC_PERI_CTRL0_peri_en_buck0_on_START (3)
#define PMIC_PERI_CTRL0_peri_en_buck0_on_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char peri_en_ldo30_on : 1;
        unsigned char peri_en_ldo28_on : 1;
        unsigned char peri_en_ldo27_on : 1;
        unsigned char peri_en_ldo23_on : 1;
        unsigned char peri_en_ldo7_on : 1;
        unsigned char peri_en_ldo6_on : 1;
        unsigned char peri_en_ldo5_on : 1;
        unsigned char reserved : 1;
    } reg;
} PMIC_PERI_CTRL1_UNION;
#endif
#define PMIC_PERI_CTRL1_peri_en_ldo30_on_START (0)
#define PMIC_PERI_CTRL1_peri_en_ldo30_on_END (0)
#define PMIC_PERI_CTRL1_peri_en_ldo28_on_START (1)
#define PMIC_PERI_CTRL1_peri_en_ldo28_on_END (1)
#define PMIC_PERI_CTRL1_peri_en_ldo27_on_START (2)
#define PMIC_PERI_CTRL1_peri_en_ldo27_on_END (2)
#define PMIC_PERI_CTRL1_peri_en_ldo23_on_START (3)
#define PMIC_PERI_CTRL1_peri_en_ldo23_on_END (3)
#define PMIC_PERI_CTRL1_peri_en_ldo7_on_START (4)
#define PMIC_PERI_CTRL1_peri_en_ldo7_on_END (4)
#define PMIC_PERI_CTRL1_peri_en_ldo6_on_START (5)
#define PMIC_PERI_CTRL1_peri_en_ldo6_on_END (5)
#define PMIC_PERI_CTRL1_peri_en_ldo5_on_START (6)
#define PMIC_PERI_CTRL1_peri_en_ldo5_on_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char peri_time_sel : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_PERI_TIME__CTRL_UNION;
#endif
#define PMIC_PERI_TIME__CTRL_peri_time_sel_START (0)
#define PMIC_PERI_TIME__CTRL_peri_time_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char peri_en_ldo11_eco : 1;
        unsigned char peri_en_ldo8_eco : 1;
        unsigned char peri_en_ldo0_2_eco : 1;
        unsigned char peri_en_buck8_eco : 1;
        unsigned char peri_en_buck7_eco : 1;
        unsigned char peri_en_buck3_eco : 1;
        unsigned char peri_en_buck2_eco : 1;
        unsigned char peri_en_buck1_eco : 1;
    } reg;
} PMIC_PERI_CTRL2_UNION;
#endif
#define PMIC_PERI_CTRL2_peri_en_ldo11_eco_START (0)
#define PMIC_PERI_CTRL2_peri_en_ldo11_eco_END (0)
#define PMIC_PERI_CTRL2_peri_en_ldo8_eco_START (1)
#define PMIC_PERI_CTRL2_peri_en_ldo8_eco_END (1)
#define PMIC_PERI_CTRL2_peri_en_ldo0_2_eco_START (2)
#define PMIC_PERI_CTRL2_peri_en_ldo0_2_eco_END (2)
#define PMIC_PERI_CTRL2_peri_en_buck8_eco_START (3)
#define PMIC_PERI_CTRL2_peri_en_buck8_eco_END (3)
#define PMIC_PERI_CTRL2_peri_en_buck7_eco_START (4)
#define PMIC_PERI_CTRL2_peri_en_buck7_eco_END (4)
#define PMIC_PERI_CTRL2_peri_en_buck3_eco_START (5)
#define PMIC_PERI_CTRL2_peri_en_buck3_eco_END (5)
#define PMIC_PERI_CTRL2_peri_en_buck2_eco_START (6)
#define PMIC_PERI_CTRL2_peri_en_buck2_eco_END (6)
#define PMIC_PERI_CTRL2_peri_en_buck1_eco_START (7)
#define PMIC_PERI_CTRL2_peri_en_buck1_eco_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char peri_en_ldo35_eco : 1;
        unsigned char peri_en_ldo29_eco : 1;
        unsigned char peri_en_ldo24_eco : 1;
        unsigned char peri_en_ldo18_eco : 1;
        unsigned char peri_en_ldo15_eco : 1;
        unsigned char peri_en_ldo12_eco : 1;
        unsigned char reserved : 2;
    } reg;
} PMIC_PERI_CTRL3_UNION;
#endif
#define PMIC_PERI_CTRL3_peri_en_ldo35_eco_START (0)
#define PMIC_PERI_CTRL3_peri_en_ldo35_eco_END (0)
#define PMIC_PERI_CTRL3_peri_en_ldo29_eco_START (1)
#define PMIC_PERI_CTRL3_peri_en_ldo29_eco_END (1)
#define PMIC_PERI_CTRL3_peri_en_ldo24_eco_START (2)
#define PMIC_PERI_CTRL3_peri_en_ldo24_eco_END (2)
#define PMIC_PERI_CTRL3_peri_en_ldo18_eco_START (3)
#define PMIC_PERI_CTRL3_peri_en_ldo18_eco_END (3)
#define PMIC_PERI_CTRL3_peri_en_ldo15_eco_START (4)
#define PMIC_PERI_CTRL3_peri_en_ldo15_eco_END (4)
#define PMIC_PERI_CTRL3_peri_en_ldo12_eco_START (5)
#define PMIC_PERI_CTRL3_peri_en_ldo12_eco_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char peri_en_thsd_eco : 1;
        unsigned char peri_en_pmua_eco : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_PERI_CTRL4_UNION;
#endif
#define PMIC_PERI_CTRL4_peri_en_thsd_eco_START (0)
#define PMIC_PERI_CTRL4_peri_en_thsd_eco_END (0)
#define PMIC_PERI_CTRL4_peri_en_pmua_eco_START (1)
#define PMIC_PERI_CTRL4_peri_en_pmua_eco_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char peri_en_buck8_vset : 1;
        unsigned char peri_en_buck3_vset : 1;
        unsigned char peri_en_buck2_vset : 1;
        unsigned char peri_en_ldo0_2_vset : 1;
        unsigned char reserved : 4;
    } reg;
} PMIC_PERI_VSET_CTRL_UNION;
#endif
#define PMIC_PERI_VSET_CTRL_peri_en_buck8_vset_START (0)
#define PMIC_PERI_VSET_CTRL_peri_en_buck8_vset_END (0)
#define PMIC_PERI_VSET_CTRL_peri_en_buck3_vset_START (1)
#define PMIC_PERI_VSET_CTRL_peri_en_buck3_vset_END (1)
#define PMIC_PERI_VSET_CTRL_peri_en_buck2_vset_START (2)
#define PMIC_PERI_VSET_CTRL_peri_en_buck2_vset_END (2)
#define PMIC_PERI_VSET_CTRL_peri_en_ldo0_2_vset_START (3)
#define PMIC_PERI_VSET_CTRL_peri_en_ldo0_2_vset_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char coul_codec_clk_en_mask : 1;
        unsigned char coul_nfc_clk_en_mask : 1;
        unsigned char coul_wifi1_clk_en_mask : 1;
        unsigned char coul_sys_clk_en_mask : 1;
        unsigned char reserved : 4;
    } reg;
} PMIC_COUL_ECO_MASK_UNION;
#endif
#define PMIC_COUL_ECO_MASK_coul_codec_clk_en_mask_START (0)
#define PMIC_COUL_ECO_MASK_coul_codec_clk_en_mask_END (0)
#define PMIC_COUL_ECO_MASK_coul_nfc_clk_en_mask_START (1)
#define PMIC_COUL_ECO_MASK_coul_nfc_clk_en_mask_END (1)
#define PMIC_COUL_ECO_MASK_coul_wifi1_clk_en_mask_START (2)
#define PMIC_COUL_ECO_MASK_coul_wifi1_clk_en_mask_END (2)
#define PMIC_COUL_ECO_MASK_coul_sys_clk_en_mask_START (3)
#define PMIC_COUL_ECO_MASK_coul_sys_clk_en_mask_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char soft_rst_n : 8;
    } reg;
} PMIC_PMU_SOFT_RST_UNION;
#endif
#define PMIC_PMU_SOFT_RST_soft_rst_n_START (0)
#define PMIC_PMU_SOFT_RST_soft_rst_n_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char lock : 8;
    } reg;
} PMIC_LOCK_UNION;
#endif
#define PMIC_LOCK_lock_START (0)
#define PMIC_LOCK_lock_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char en_dr1_int : 1;
        unsigned char en_dr2_int : 1;
        unsigned char en_dr3_int : 1;
        unsigned char reserved : 5;
    } reg;
} PMIC_DR_EN_MODE_UNION;
#endif
#define PMIC_DR_EN_MODE_en_dr1_int_START (0)
#define PMIC_DR_EN_MODE_en_dr1_int_END (0)
#define PMIC_DR_EN_MODE_en_dr2_int_START (1)
#define PMIC_DR_EN_MODE_en_dr2_int_END (1)
#define PMIC_DR_EN_MODE_en_dr3_int_START (2)
#define PMIC_DR_EN_MODE_en_dr3_int_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dr1_mode : 1;
        unsigned char dr2_mode : 1;
        unsigned char dr3_mode : 1;
        unsigned char reserved : 5;
    } reg;
} PMIC_DR_EN_MODE_12_UNION;
#endif
#define PMIC_DR_EN_MODE_12_dr1_mode_START (0)
#define PMIC_DR_EN_MODE_12_dr1_mode_END (0)
#define PMIC_DR_EN_MODE_12_dr2_mode_START (1)
#define PMIC_DR_EN_MODE_12_dr2_mode_END (1)
#define PMIC_DR_EN_MODE_12_dr3_mode_START (2)
#define PMIC_DR_EN_MODE_12_dr3_mode_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char flash_period_dr1 : 8;
    } reg;
} PMIC_FLASH_PERIOD_DR1_UNION;
#endif
#define PMIC_FLASH_PERIOD_DR1_flash_period_dr1_START (0)
#define PMIC_FLASH_PERIOD_DR1_flash_period_dr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char flash_on_dr1 : 8;
    } reg;
} PMIC_FLASH_ON_DR1_UNION;
#endif
#define PMIC_FLASH_ON_DR1_flash_on_dr1_START (0)
#define PMIC_FLASH_ON_DR1_flash_on_dr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char flash_period_dr2 : 8;
    } reg;
} PMIC_FLASH_PERIOD_DR2_UNION;
#endif
#define PMIC_FLASH_PERIOD_DR2_flash_period_dr2_START (0)
#define PMIC_FLASH_PERIOD_DR2_flash_period_dr2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char flash_on_dr2 : 8;
    } reg;
} PMIC_FLASH_ON_DR2_UNION;
#endif
#define PMIC_FLASH_ON_DR2_flash_on_dr2_START (0)
#define PMIC_FLASH_ON_DR2_flash_on_dr2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char flash_period_dr3 : 8;
    } reg;
} PMIC_FLASH_PERIOD_DR3_UNION;
#endif
#define PMIC_FLASH_PERIOD_DR3_flash_period_dr3_START (0)
#define PMIC_FLASH_PERIOD_DR3_flash_period_dr3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char flash_on_dr3 : 8;
    } reg;
} PMIC_FLASH_ON_DR3_UNION;
#endif
#define PMIC_FLASH_ON_DR3_flash_on_dr3_START (0)
#define PMIC_FLASH_ON_DR3_flash_on_dr3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dr1_mode_sel : 1;
        unsigned char dr2_mode_sel : 1;
        unsigned char dr3_mode_sel : 1;
        unsigned char reserved : 5;
    } reg;
} PMIC_DR_MODE_SEL_UNION;
#endif
#define PMIC_DR_MODE_SEL_dr1_mode_sel_START (0)
#define PMIC_DR_MODE_SEL_dr1_mode_sel_END (0)
#define PMIC_DR_MODE_SEL_dr2_mode_sel_START (1)
#define PMIC_DR_MODE_SEL_dr2_mode_sel_END (1)
#define PMIC_DR_MODE_SEL_dr3_mode_sel_START (2)
#define PMIC_DR_MODE_SEL_dr3_mode_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reg_dr1_en : 1;
        unsigned char reg_dr2_en : 1;
        unsigned char reg_dr3_en : 1;
        unsigned char reserved : 5;
    } reg;
} PMIC_DR_BRE_CTRL_UNION;
#endif
#define PMIC_DR_BRE_CTRL_reg_dr1_en_START (0)
#define PMIC_DR_BRE_CTRL_reg_dr1_en_END (0)
#define PMIC_DR_BRE_CTRL_reg_dr2_en_START (1)
#define PMIC_DR_BRE_CTRL_reg_dr2_en_END (1)
#define PMIC_DR_BRE_CTRL_reg_dr3_en_START (2)
#define PMIC_DR_BRE_CTRL_reg_dr3_en_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dr1_iset : 4;
        unsigned char reserved : 4;
    } reg;
} PMIC_DR1_ISET_UNION;
#endif
#define PMIC_DR1_ISET_dr1_iset_START (0)
#define PMIC_DR1_ISET_dr1_iset_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dr2_iset : 4;
        unsigned char reserved : 4;
    } reg;
} PMIC_DR2_ISET_UNION;
#endif
#define PMIC_DR2_ISET_dr2_iset_START (0)
#define PMIC_DR2_ISET_dr2_iset_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dr3_iset : 4;
        unsigned char reserved : 4;
    } reg;
} PMIC_DR3_ISET_UNION;
#endif
#define PMIC_DR3_ISET_dr3_iset_START (0)
#define PMIC_DR3_ISET_dr3_iset_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dr1_out_ctrl : 2;
        unsigned char dr2_out_ctrl : 2;
        unsigned char dr3_out_ctrl : 2;
        unsigned char reserved : 2;
    } reg;
} PMIC_DR_OUT_CTRL_UNION;
#endif
#define PMIC_DR_OUT_CTRL_dr1_out_ctrl_START (0)
#define PMIC_DR_OUT_CTRL_dr1_out_ctrl_END (1)
#define PMIC_DR_OUT_CTRL_dr2_out_ctrl_START (2)
#define PMIC_DR_OUT_CTRL_dr2_out_ctrl_END (3)
#define PMIC_DR_OUT_CTRL_dr3_out_ctrl_START (4)
#define PMIC_DR_OUT_CTRL_dr3_out_ctrl_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dr1_start_delay : 8;
    } reg;
} PMIC_DR1_START_DEL_UNION;
#endif
#define PMIC_DR1_START_DEL_dr1_start_delay_START (0)
#define PMIC_DR1_START_DEL_dr1_start_delay_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dr2_start_delay : 8;
    } reg;
} PMIC_DR2_START_DEL_UNION;
#endif
#define PMIC_DR2_START_DEL_dr2_start_delay_START (0)
#define PMIC_DR2_START_DEL_dr2_start_delay_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dr3_start_delay : 8;
    } reg;
} PMIC_DR3_START_DEL_UNION;
#endif
#define PMIC_DR3_START_DEL_dr3_start_delay_START (0)
#define PMIC_DR3_START_DEL_dr3_start_delay_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dr1_t_off : 4;
        unsigned char dr1_t_on : 4;
    } reg;
} PMIC_DR1_TIM_CONF0_UNION;
#endif
#define PMIC_DR1_TIM_CONF0_dr1_t_off_START (0)
#define PMIC_DR1_TIM_CONF0_dr1_t_off_END (3)
#define PMIC_DR1_TIM_CONF0_dr1_t_on_START (4)
#define PMIC_DR1_TIM_CONF0_dr1_t_on_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dr1_t_rise : 3;
        unsigned char reserved_0 : 1;
        unsigned char dr1_t_fall : 3;
        unsigned char reserved_1 : 1;
    } reg;
} PMIC_DR1_TIM_CONF1_UNION;
#endif
#define PMIC_DR1_TIM_CONF1_dr1_t_rise_START (0)
#define PMIC_DR1_TIM_CONF1_dr1_t_rise_END (2)
#define PMIC_DR1_TIM_CONF1_dr1_t_fall_START (4)
#define PMIC_DR1_TIM_CONF1_dr1_t_fall_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dr2_t_off : 4;
        unsigned char dr2_t_on : 4;
    } reg;
} PMIC_DR2_TIM_CONF0_UNION;
#endif
#define PMIC_DR2_TIM_CONF0_dr2_t_off_START (0)
#define PMIC_DR2_TIM_CONF0_dr2_t_off_END (3)
#define PMIC_DR2_TIM_CONF0_dr2_t_on_START (4)
#define PMIC_DR2_TIM_CONF0_dr2_t_on_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dr2_t_rise : 3;
        unsigned char reserved_0 : 1;
        unsigned char dr2_t_fall : 3;
        unsigned char reserved_1 : 1;
    } reg;
} PMIC_DR2_TIM_CONF1_UNION;
#endif
#define PMIC_DR2_TIM_CONF1_dr2_t_rise_START (0)
#define PMIC_DR2_TIM_CONF1_dr2_t_rise_END (2)
#define PMIC_DR2_TIM_CONF1_dr2_t_fall_START (4)
#define PMIC_DR2_TIM_CONF1_dr2_t_fall_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dr3_t_off : 4;
        unsigned char dr3_t_on : 4;
    } reg;
} PMIC_DR3_TIM_CONF0_UNION;
#endif
#define PMIC_DR3_TIM_CONF0_dr3_t_off_START (0)
#define PMIC_DR3_TIM_CONF0_dr3_t_off_END (3)
#define PMIC_DR3_TIM_CONF0_dr3_t_on_START (4)
#define PMIC_DR3_TIM_CONF0_dr3_t_on_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dr3_t_rise : 3;
        unsigned char reserved_0 : 1;
        unsigned char dr3_t_fall : 3;
        unsigned char reserved_1 : 1;
    } reg;
} PMIC_DR3_TIM_CONF1_UNION;
#endif
#define PMIC_DR3_TIM_CONF1_dr3_t_rise_START (0)
#define PMIC_DR3_TIM_CONF1_dr3_t_rise_END (2)
#define PMIC_DR3_TIM_CONF1_dr3_t_fall_START (4)
#define PMIC_DR3_TIM_CONF1_dr3_t_fall_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} PMIC_DR_CTRLRESERVE8_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} PMIC_DR_CTRLRESERVE9_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob0 : 8;
    } reg;
} PMIC_OTP_0_UNION;
#endif
#define PMIC_OTP_0_otp_pdob0_START (0)
#define PMIC_OTP_0_otp_pdob0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob1 : 8;
    } reg;
} PMIC_OTP_1_UNION;
#endif
#define PMIC_OTP_1_otp_pdob1_START (0)
#define PMIC_OTP_1_otp_pdob1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pwe_int : 1;
        unsigned char otp_pwe_pulse : 1;
        unsigned char otp_por_int : 1;
        unsigned char otp_por_pulse : 1;
        unsigned char reserved : 4;
    } reg;
} PMIC_OTP_CTRL0_UNION;
#endif
#define PMIC_OTP_CTRL0_otp_pwe_int_START (0)
#define PMIC_OTP_CTRL0_otp_pwe_int_END (0)
#define PMIC_OTP_CTRL0_otp_pwe_pulse_START (1)
#define PMIC_OTP_CTRL0_otp_pwe_pulse_END (1)
#define PMIC_OTP_CTRL0_otp_por_int_START (2)
#define PMIC_OTP_CTRL0_otp_por_int_END (2)
#define PMIC_OTP_CTRL0_otp_por_pulse_START (3)
#define PMIC_OTP_CTRL0_otp_por_pulse_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pprog : 1;
        unsigned char otp_inctrl_sel : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_OTP_CTRL1_UNION;
#endif
#define PMIC_OTP_CTRL1_otp_pprog_START (0)
#define PMIC_OTP_CTRL1_otp_pprog_END (0)
#define PMIC_OTP_CTRL1_otp_inctrl_sel_START (1)
#define PMIC_OTP_CTRL1_otp_inctrl_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pa_cfg : 6;
        unsigned char otp_ptm : 2;
    } reg;
} PMIC_OTP_CTRL2_UNION;
#endif
#define PMIC_OTP_CTRL2_otp_pa_cfg_START (0)
#define PMIC_OTP_CTRL2_otp_pa_cfg_END (5)
#define PMIC_OTP_CTRL2_otp_ptm_START (6)
#define PMIC_OTP_CTRL2_otp_ptm_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdin : 8;
    } reg;
} PMIC_OTP_WDATA_UNION;
#endif
#define PMIC_OTP_WDATA_otp_pdin_START (0)
#define PMIC_OTP_WDATA_otp_pdin_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob0_w : 8;
    } reg;
} PMIC_OTP_0_W_UNION;
#endif
#define PMIC_OTP_0_W_otp_pdob0_w_START (0)
#define PMIC_OTP_0_W_otp_pdob0_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob1_w : 8;
    } reg;
} PMIC_OTP_1_W_UNION;
#endif
#define PMIC_OTP_1_W_otp_pdob1_w_START (0)
#define PMIC_OTP_1_W_otp_pdob1_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob2_w : 8;
    } reg;
} PMIC_OTP_2_W_UNION;
#endif
#define PMIC_OTP_2_W_otp_pdob2_w_START (0)
#define PMIC_OTP_2_W_otp_pdob2_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob3_w : 8;
    } reg;
} PMIC_OTP_3_W_UNION;
#endif
#define PMIC_OTP_3_W_otp_pdob3_w_START (0)
#define PMIC_OTP_3_W_otp_pdob3_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob4_w : 8;
    } reg;
} PMIC_OTP_4_W_UNION;
#endif
#define PMIC_OTP_4_W_otp_pdob4_w_START (0)
#define PMIC_OTP_4_W_otp_pdob4_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob5_w : 8;
    } reg;
} PMIC_OTP_5_W_UNION;
#endif
#define PMIC_OTP_5_W_otp_pdob5_w_START (0)
#define PMIC_OTP_5_W_otp_pdob5_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob6_w : 8;
    } reg;
} PMIC_OTP_6_W_UNION;
#endif
#define PMIC_OTP_6_W_otp_pdob6_w_START (0)
#define PMIC_OTP_6_W_otp_pdob6_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob7_w : 8;
    } reg;
} PMIC_OTP_7_W_UNION;
#endif
#define PMIC_OTP_7_W_otp_pdob7_w_START (0)
#define PMIC_OTP_7_W_otp_pdob7_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob8_w : 8;
    } reg;
} PMIC_OTP_8_W_UNION;
#endif
#define PMIC_OTP_8_W_otp_pdob8_w_START (0)
#define PMIC_OTP_8_W_otp_pdob8_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob9_w : 8;
    } reg;
} PMIC_OTP_9_W_UNION;
#endif
#define PMIC_OTP_9_W_otp_pdob9_w_START (0)
#define PMIC_OTP_9_W_otp_pdob9_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob10_w : 8;
    } reg;
} PMIC_OTP_10_W_UNION;
#endif
#define PMIC_OTP_10_W_otp_pdob10_w_START (0)
#define PMIC_OTP_10_W_otp_pdob10_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob11_w : 8;
    } reg;
} PMIC_OTP_11_W_UNION;
#endif
#define PMIC_OTP_11_W_otp_pdob11_w_START (0)
#define PMIC_OTP_11_W_otp_pdob11_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob12_w : 8;
    } reg;
} PMIC_OTP_12_W_UNION;
#endif
#define PMIC_OTP_12_W_otp_pdob12_w_START (0)
#define PMIC_OTP_12_W_otp_pdob12_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob13_w : 8;
    } reg;
} PMIC_OTP_13_W_UNION;
#endif
#define PMIC_OTP_13_W_otp_pdob13_w_START (0)
#define PMIC_OTP_13_W_otp_pdob13_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob14_w : 8;
    } reg;
} PMIC_OTP_14_W_UNION;
#endif
#define PMIC_OTP_14_W_otp_pdob14_w_START (0)
#define PMIC_OTP_14_W_otp_pdob14_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob15_w : 8;
    } reg;
} PMIC_OTP_15_W_UNION;
#endif
#define PMIC_OTP_15_W_otp_pdob15_w_START (0)
#define PMIC_OTP_15_W_otp_pdob15_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob16_w : 8;
    } reg;
} PMIC_OTP_16_W_UNION;
#endif
#define PMIC_OTP_16_W_otp_pdob16_w_START (0)
#define PMIC_OTP_16_W_otp_pdob16_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob17_w : 8;
    } reg;
} PMIC_OTP_17_W_UNION;
#endif
#define PMIC_OTP_17_W_otp_pdob17_w_START (0)
#define PMIC_OTP_17_W_otp_pdob17_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob18_w : 8;
    } reg;
} PMIC_OTP_18_W_UNION;
#endif
#define PMIC_OTP_18_W_otp_pdob18_w_START (0)
#define PMIC_OTP_18_W_otp_pdob18_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob19_w : 8;
    } reg;
} PMIC_OTP_19_W_UNION;
#endif
#define PMIC_OTP_19_W_otp_pdob19_w_START (0)
#define PMIC_OTP_19_W_otp_pdob19_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob20_w : 8;
    } reg;
} PMIC_OTP_20_W_UNION;
#endif
#define PMIC_OTP_20_W_otp_pdob20_w_START (0)
#define PMIC_OTP_20_W_otp_pdob20_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob21_w : 8;
    } reg;
} PMIC_OTP_21_W_UNION;
#endif
#define PMIC_OTP_21_W_otp_pdob21_w_START (0)
#define PMIC_OTP_21_W_otp_pdob21_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob22_w : 8;
    } reg;
} PMIC_OTP_22_W_UNION;
#endif
#define PMIC_OTP_22_W_otp_pdob22_w_START (0)
#define PMIC_OTP_22_W_otp_pdob22_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob23_w : 8;
    } reg;
} PMIC_OTP_23_W_UNION;
#endif
#define PMIC_OTP_23_W_otp_pdob23_w_START (0)
#define PMIC_OTP_23_W_otp_pdob23_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob24_w : 8;
    } reg;
} PMIC_OTP_24_W_UNION;
#endif
#define PMIC_OTP_24_W_otp_pdob24_w_START (0)
#define PMIC_OTP_24_W_otp_pdob24_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob25_w : 8;
    } reg;
} PMIC_OTP_25_W_UNION;
#endif
#define PMIC_OTP_25_W_otp_pdob25_w_START (0)
#define PMIC_OTP_25_W_otp_pdob25_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob26_w : 8;
    } reg;
} PMIC_OTP_26_W_UNION;
#endif
#define PMIC_OTP_26_W_otp_pdob26_w_START (0)
#define PMIC_OTP_26_W_otp_pdob26_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob27_w : 8;
    } reg;
} PMIC_OTP_27_W_UNION;
#endif
#define PMIC_OTP_27_W_otp_pdob27_w_START (0)
#define PMIC_OTP_27_W_otp_pdob27_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob28_w : 8;
    } reg;
} PMIC_OTP_28_W_UNION;
#endif
#define PMIC_OTP_28_W_otp_pdob28_w_START (0)
#define PMIC_OTP_28_W_otp_pdob28_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob29_w : 8;
    } reg;
} PMIC_OTP_29_W_UNION;
#endif
#define PMIC_OTP_29_W_otp_pdob29_w_START (0)
#define PMIC_OTP_29_W_otp_pdob29_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob30_w : 8;
    } reg;
} PMIC_OTP_30_W_UNION;
#endif
#define PMIC_OTP_30_W_otp_pdob30_w_START (0)
#define PMIC_OTP_30_W_otp_pdob30_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char otp_pdob31_w : 8;
    } reg;
} PMIC_OTP_31_W_UNION;
#endif
#define PMIC_OTP_31_W_otp_pdob31_w_START (0)
#define PMIC_OTP_31_W_otp_pdob31_w_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char d2a_reserve0 : 8;
    } reg;
} PMIC_D2A_RES0_UNION;
#endif
#define PMIC_D2A_RES0_d2a_reserve0_START (0)
#define PMIC_D2A_RES0_d2a_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char d2a_reserve1 : 8;
    } reg;
} PMIC_D2A_RES1_UNION;
#endif
#define PMIC_D2A_RES1_d2a_reserve1_START (0)
#define PMIC_D2A_RES1_d2a_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char a2d_reserve0 : 8;
    } reg;
} PMIC_A2D_RES0_UNION;
#endif
#define PMIC_A2D_RES0_a2d_reserve0_START (0)
#define PMIC_A2D_RES0_a2d_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char a2d_reserve1 : 8;
    } reg;
} PMIC_A2D_RES1_UNION;
#endif
#define PMIC_A2D_RES1_a2d_reserve1_START (0)
#define PMIC_A2D_RES1_a2d_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sim0_hpd_r_pd_en : 1;
        unsigned char sim0_hpd_f_pd_en : 1;
        unsigned char sim1_hpd_r_pd_en : 1;
        unsigned char sim1_hpd_f_pd_en : 1;
        unsigned char sim0_hpd_pd_ldo12_en : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_SIM_CTRL0_UNION;
#endif
#define PMIC_SIM_CTRL0_sim0_hpd_r_pd_en_START (0)
#define PMIC_SIM_CTRL0_sim0_hpd_r_pd_en_END (0)
#define PMIC_SIM_CTRL0_sim0_hpd_f_pd_en_START (1)
#define PMIC_SIM_CTRL0_sim0_hpd_f_pd_en_END (1)
#define PMIC_SIM_CTRL0_sim1_hpd_r_pd_en_START (2)
#define PMIC_SIM_CTRL0_sim1_hpd_r_pd_en_END (2)
#define PMIC_SIM_CTRL0_sim1_hpd_f_pd_en_START (3)
#define PMIC_SIM_CTRL0_sim1_hpd_f_pd_en_END (3)
#define PMIC_SIM_CTRL0_sim0_hpd_pd_ldo12_en_START (4)
#define PMIC_SIM_CTRL0_sim0_hpd_pd_ldo12_en_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sim0_hpd_ldo16_en3 : 1;
        unsigned char sim0_hpd_ldo16_en2 : 1;
        unsigned char sim1_hpd_ldo16_en1 : 1;
        unsigned char sim1_hpd_ldo16_en0 : 1;
        unsigned char reserved : 4;
    } reg;
} PMIC_SIM_CTRL1_UNION;
#endif
#define PMIC_SIM_CTRL1_sim0_hpd_ldo16_en3_START (0)
#define PMIC_SIM_CTRL1_sim0_hpd_ldo16_en3_END (0)
#define PMIC_SIM_CTRL1_sim0_hpd_ldo16_en2_START (1)
#define PMIC_SIM_CTRL1_sim0_hpd_ldo16_en2_END (1)
#define PMIC_SIM_CTRL1_sim1_hpd_ldo16_en1_START (2)
#define PMIC_SIM_CTRL1_sim1_hpd_ldo16_en1_END (2)
#define PMIC_SIM_CTRL1_sim1_hpd_ldo16_en0_START (3)
#define PMIC_SIM_CTRL1_sim1_hpd_ldo16_en0_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sim_hpd_deb_sel : 5;
        unsigned char sim_del_sel0 : 3;
    } reg;
} PMIC_SIM_DEB_CTRL1_UNION;
#endif
#define PMIC_SIM_DEB_CTRL1_sim_hpd_deb_sel_START (0)
#define PMIC_SIM_DEB_CTRL1_sim_hpd_deb_sel_END (4)
#define PMIC_SIM_DEB_CTRL1_sim_del_sel0_START (5)
#define PMIC_SIM_DEB_CTRL1_sim_del_sel0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char sim_del_sel : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_SIM_DEB_CTRL2_UNION;
#endif
#define PMIC_SIM_DEB_CTRL2_sim_del_sel_START (0)
#define PMIC_SIM_DEB_CTRL2_sim_del_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio0_data : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO0DATA_UNION;
#endif
#define PMIC_GPIO0DATA_gpio0_data_START (0)
#define PMIC_GPIO0DATA_gpio0_data_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} PMIC_GPIO0_DATA_RESERVE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio0_dir : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO0DIR_UNION;
#endif
#define PMIC_GPIO0DIR_gpio0_dir_START (0)
#define PMIC_GPIO0DIR_gpio0_dir_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} PMIC_GPIO0_DIR_RESERVE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio0_int_sense : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO0IS_UNION;
#endif
#define PMIC_GPIO0IS_gpio0_int_sense_START (0)
#define PMIC_GPIO0IS_gpio0_int_sense_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio0_int_edge : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO0IBE_UNION;
#endif
#define PMIC_GPIO0IBE_gpio0_int_edge_START (0)
#define PMIC_GPIO0IBE_gpio0_int_edge_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio0_int_f : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO0IEV_UNION;
#endif
#define PMIC_GPIO0IEV_gpio0_int_f_START (0)
#define PMIC_GPIO0IEV_gpio0_int_f_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio0_mode_ctrl : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO0AFSEL_UNION;
#endif
#define PMIC_GPIO0AFSEL_gpio0_mode_ctrl_START (0)
#define PMIC_GPIO0AFSEL_gpio0_mode_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio0_out_ctrl : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO0DSSEL_UNION;
#endif
#define PMIC_GPIO0DSSEL_gpio0_out_ctrl_START (0)
#define PMIC_GPIO0DSSEL_gpio0_out_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio0_pullup_ctrl : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO0PUSEL_UNION;
#endif
#define PMIC_GPIO0PUSEL_gpio0_pullup_ctrl_START (0)
#define PMIC_GPIO0PUSEL_gpio0_pullup_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio0_pulldown_ctrl : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO0PDSEL_UNION;
#endif
#define PMIC_GPIO0PDSEL_gpio0_pulldown_ctrl_START (0)
#define PMIC_GPIO0PDSEL_gpio0_pulldown_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio0_del_sel : 2;
        unsigned char reserved : 6;
    } reg;
} PMIC_GPIO0DEBSEL_UNION;
#endif
#define PMIC_GPIO0DEBSEL_gpio0_del_sel_START (0)
#define PMIC_GPIO0DEBSEL_gpio0_del_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio1_data : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO1DATA_UNION;
#endif
#define PMIC_GPIO1DATA_gpio1_data_START (0)
#define PMIC_GPIO1DATA_gpio1_data_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} PMIC_GPIO1_DATA_RESERVE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio1_dir : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO1DIR_UNION;
#endif
#define PMIC_GPIO1DIR_gpio1_dir_START (0)
#define PMIC_GPIO1DIR_gpio1_dir_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} PMIC_GPIO1_DIR_RESERVE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio1_int_sense : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO1IS_UNION;
#endif
#define PMIC_GPIO1IS_gpio1_int_sense_START (0)
#define PMIC_GPIO1IS_gpio1_int_sense_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio1_int_edge : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO1IBE_UNION;
#endif
#define PMIC_GPIO1IBE_gpio1_int_edge_START (0)
#define PMIC_GPIO1IBE_gpio1_int_edge_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio1_int_f : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO1IEV_UNION;
#endif
#define PMIC_GPIO1IEV_gpio1_int_f_START (0)
#define PMIC_GPIO1IEV_gpio1_int_f_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio1_mode_ctrl : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO1AFSEL_UNION;
#endif
#define PMIC_GPIO1AFSEL_gpio1_mode_ctrl_START (0)
#define PMIC_GPIO1AFSEL_gpio1_mode_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio1_out_ctrl : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO1DSSEL_UNION;
#endif
#define PMIC_GPIO1DSSEL_gpio1_out_ctrl_START (0)
#define PMIC_GPIO1DSSEL_gpio1_out_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio1_pullup_ctrl : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO1PUSEL_UNION;
#endif
#define PMIC_GPIO1PUSEL_gpio1_pullup_ctrl_START (0)
#define PMIC_GPIO1PUSEL_gpio1_pullup_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio1_pulldown_ctrl : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO1PDSEL_UNION;
#endif
#define PMIC_GPIO1PDSEL_gpio1_pulldown_ctrl_START (0)
#define PMIC_GPIO1PDSEL_gpio1_pulldown_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio1_del_sel : 2;
        unsigned char reserved : 6;
    } reg;
} PMIC_GPIO1DEBSEL_UNION;
#endif
#define PMIC_GPIO1DEBSEL_gpio1_del_sel_START (0)
#define PMIC_GPIO1DEBSEL_gpio1_del_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio2_data : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO2DATA_UNION;
#endif
#define PMIC_GPIO2DATA_gpio2_data_START (0)
#define PMIC_GPIO2DATA_gpio2_data_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} PMIC_GPIO2_DATA_RESERVE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio2_dir : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO2DIR_UNION;
#endif
#define PMIC_GPIO2DIR_gpio2_dir_START (0)
#define PMIC_GPIO2DIR_gpio2_dir_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char reserved : 8;
    } reg;
} PMIC_GPIO2_DIR_RESERVE_UNION;
#endif
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio2_int_sense : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO2IS_UNION;
#endif
#define PMIC_GPIO2IS_gpio2_int_sense_START (0)
#define PMIC_GPIO2IS_gpio2_int_sense_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio2_int_edge : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO2IBE_UNION;
#endif
#define PMIC_GPIO2IBE_gpio2_int_edge_START (0)
#define PMIC_GPIO2IBE_gpio2_int_edge_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio2_int_f : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO2IEV_UNION;
#endif
#define PMIC_GPIO2IEV_gpio2_int_f_START (0)
#define PMIC_GPIO2IEV_gpio2_int_f_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio2_mode_ctrl : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO2AFSEL_UNION;
#endif
#define PMIC_GPIO2AFSEL_gpio2_mode_ctrl_START (0)
#define PMIC_GPIO2AFSEL_gpio2_mode_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio2_out_ctrl : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO2DSSEL_UNION;
#endif
#define PMIC_GPIO2DSSEL_gpio2_out_ctrl_START (0)
#define PMIC_GPIO2DSSEL_gpio2_out_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio2_pullup_ctrl : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO2PUSEL_UNION;
#endif
#define PMIC_GPIO2PUSEL_gpio2_pullup_ctrl_START (0)
#define PMIC_GPIO2PUSEL_gpio2_pullup_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio2_pulldown_ctrl : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_GPIO2PDSEL_UNION;
#endif
#define PMIC_GPIO2PDSEL_gpio2_pulldown_ctrl_START (0)
#define PMIC_GPIO2PDSEL_gpio2_pulldown_ctrl_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio2_del_sel : 2;
        unsigned char reserved : 6;
    } reg;
} PMIC_GPIO2DEBSEL_UNION;
#endif
#define PMIC_GPIO2DEBSEL_gpio2_del_sel_START (0)
#define PMIC_GPIO2DEBSEL_gpio2_del_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char aux0_offset_cfg : 2;
        unsigned char aux0_ibias_cfg : 2;
        unsigned char reserved : 4;
    } reg;
} PMIC_AUX0_IBIAS_CFG_UNION;
#endif
#define PMIC_AUX0_IBIAS_CFG_aux0_offset_cfg_START (0)
#define PMIC_AUX0_IBIAS_CFG_aux0_offset_cfg_END (1)
#define PMIC_AUX0_IBIAS_CFG_aux0_ibias_cfg_START (2)
#define PMIC_AUX0_IBIAS_CFG_aux0_ibias_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char aux1_offset_cfg : 2;
        unsigned char aux1_ibias_cfg : 2;
        unsigned char reserved : 4;
    } reg;
} PMIC_AUX1_IBIAS_CFG_UNION;
#endif
#define PMIC_AUX1_IBIAS_CFG_aux1_offset_cfg_START (0)
#define PMIC_AUX1_IBIAS_CFG_aux1_offset_cfg_END (1)
#define PMIC_AUX1_IBIAS_CFG_aux1_ibias_cfg_START (2)
#define PMIC_AUX1_IBIAS_CFG_aux1_ibias_cfg_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dac0_din_msb : 2;
        unsigned char reserved : 6;
    } reg;
} PMIC_DAC0_DIN_MSB_UNION;
#endif
#define PMIC_DAC0_DIN_MSB_dac0_din_msb_START (0)
#define PMIC_DAC0_DIN_MSB_dac0_din_msb_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dac0_din_lsb : 8;
    } reg;
} PMIC_DAC0_DIN_LSB_UNION;
#endif
#define PMIC_DAC0_DIN_LSB_dac0_din_lsb_START (0)
#define PMIC_DAC0_DIN_LSB_dac0_din_lsb_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dac1_din_msb : 2;
        unsigned char reserved : 6;
    } reg;
} PMIC_DAC1_DIN_MSB_UNION;
#endif
#define PMIC_DAC1_DIN_MSB_dac1_din_msb_START (0)
#define PMIC_DAC1_DIN_MSB_dac1_din_msb_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char dac1_din_lsb : 8;
    } reg;
} PMIC_DAC1_DIN_LSB_UNION;
#endif
#define PMIC_DAC1_DIN_LSB_dac1_din_lsb_START (0)
#define PMIC_DAC1_DIN_LSB_dac1_din_lsb_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck0_pull_down_mode : 1;
        unsigned char buck0_pull_down_cfg : 1;
        unsigned char buck0_rampdown_ctrl : 2;
        unsigned char buck0_rampup_ctrl : 2;
        unsigned char buck0_ramp_en_cfg : 1;
        unsigned char reserved : 1;
    } reg;
} PMIC_RAMP_BUCK0_CTRL0_UNION;
#endif
#define PMIC_RAMP_BUCK0_CTRL0_buck0_pull_down_mode_START (0)
#define PMIC_RAMP_BUCK0_CTRL0_buck0_pull_down_mode_END (0)
#define PMIC_RAMP_BUCK0_CTRL0_buck0_pull_down_cfg_START (1)
#define PMIC_RAMP_BUCK0_CTRL0_buck0_pull_down_cfg_END (1)
#define PMIC_RAMP_BUCK0_CTRL0_buck0_rampdown_ctrl_START (2)
#define PMIC_RAMP_BUCK0_CTRL0_buck0_rampdown_ctrl_END (3)
#define PMIC_RAMP_BUCK0_CTRL0_buck0_rampup_ctrl_START (4)
#define PMIC_RAMP_BUCK0_CTRL0_buck0_rampup_ctrl_END (5)
#define PMIC_RAMP_BUCK0_CTRL0_buck0_ramp_en_cfg_START (6)
#define PMIC_RAMP_BUCK0_CTRL0_buck0_ramp_en_cfg_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck0_pull_down_off_adj : 4;
        unsigned char buck0_pull_down_on_adj : 3;
        unsigned char reserved : 1;
    } reg;
} PMIC_RAMP_BUCK0_CTRL1_UNION;
#endif
#define PMIC_RAMP_BUCK0_CTRL1_buck0_pull_down_off_adj_START (0)
#define PMIC_RAMP_BUCK0_CTRL1_buck0_pull_down_off_adj_END (3)
#define PMIC_RAMP_BUCK0_CTRL1_buck0_pull_down_on_adj_START (4)
#define PMIC_RAMP_BUCK0_CTRL1_buck0_pull_down_on_adj_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck4_rampdown_ctrl : 2;
        unsigned char buck4_rampup_ctrl : 2;
        unsigned char buck4_ramp_en_cfg : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_RAMP_BUCK4_CTRL0_UNION;
#endif
#define PMIC_RAMP_BUCK4_CTRL0_buck4_rampdown_ctrl_START (0)
#define PMIC_RAMP_BUCK4_CTRL0_buck4_rampdown_ctrl_END (1)
#define PMIC_RAMP_BUCK4_CTRL0_buck4_rampup_ctrl_START (2)
#define PMIC_RAMP_BUCK4_CTRL0_buck4_rampup_ctrl_END (3)
#define PMIC_RAMP_BUCK4_CTRL0_buck4_ramp_en_cfg_START (4)
#define PMIC_RAMP_BUCK4_CTRL0_buck4_ramp_en_cfg_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck5_rampdown_ctrl : 2;
        unsigned char buck5_rampup_ctrl : 2;
        unsigned char buck5_ramp_en_cfg : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_RAMP_BUCK5_CTRL0_UNION;
#endif
#define PMIC_RAMP_BUCK5_CTRL0_buck5_rampdown_ctrl_START (0)
#define PMIC_RAMP_BUCK5_CTRL0_buck5_rampdown_ctrl_END (1)
#define PMIC_RAMP_BUCK5_CTRL0_buck5_rampup_ctrl_START (2)
#define PMIC_RAMP_BUCK5_CTRL0_buck5_rampup_ctrl_END (3)
#define PMIC_RAMP_BUCK5_CTRL0_buck5_ramp_en_cfg_START (4)
#define PMIC_RAMP_BUCK5_CTRL0_buck5_ramp_en_cfg_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck6_rampdown_ctrl : 2;
        unsigned char buck6_rampup_ctrl : 2;
        unsigned char buck6_ramp_en_cfg : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_RAMP_BUCK6_CTRL0_UNION;
#endif
#define PMIC_RAMP_BUCK6_CTRL0_buck6_rampdown_ctrl_START (0)
#define PMIC_RAMP_BUCK6_CTRL0_buck6_rampdown_ctrl_END (1)
#define PMIC_RAMP_BUCK6_CTRL0_buck6_rampup_ctrl_START (2)
#define PMIC_RAMP_BUCK6_CTRL0_buck6_rampup_ctrl_END (3)
#define PMIC_RAMP_BUCK6_CTRL0_buck6_ramp_en_cfg_START (4)
#define PMIC_RAMP_BUCK6_CTRL0_buck6_ramp_en_cfg_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_eco_gt_bypass : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_SPMI_ECO_GT_BYPASS_UNION;
#endif
#define PMIC_SPMI_ECO_GT_BYPASS_spmi_eco_gt_bypass_START (0)
#define PMIC_SPMI_ECO_GT_BYPASS_spmi_eco_gt_bypass_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xoadc_debug : 1;
        unsigned char pwronn_8s_hreset_mode : 1;
        unsigned char ramp_gt_debug : 1;
        unsigned char reserved : 5;
    } reg;
} PMIC_PWRONN_8S_XOADC_DEBUG_CTRL_UNION;
#endif
#define PMIC_PWRONN_8S_XOADC_DEBUG_CTRL_xoadc_debug_START (0)
#define PMIC_PWRONN_8S_XOADC_DEBUG_CTRL_xoadc_debug_END (0)
#define PMIC_PWRONN_8S_XOADC_DEBUG_CTRL_pwronn_8s_hreset_mode_START (1)
#define PMIC_PWRONN_8S_XOADC_DEBUG_CTRL_pwronn_8s_hreset_mode_END (1)
#define PMIC_PWRONN_8S_XOADC_DEBUG_CTRL_ramp_gt_debug_START (2)
#define PMIC_PWRONN_8S_XOADC_DEBUG_CTRL_ramp_gt_debug_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char d2a_reserve2 : 8;
    } reg;
} PMIC_D2A_RES2_UNION;
#endif
#define PMIC_D2A_RES2_d2a_reserve2_START (0)
#define PMIC_D2A_RES2_d2a_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char d2a_reserve3 : 8;
    } reg;
} PMIC_D2A_RES3_UNION;
#endif
#define PMIC_D2A_RES3_d2a_reserve3_START (0)
#define PMIC_D2A_RES3_d2a_reserve3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_mask_0 : 8;
    } reg;
} PMIC_IRQ_MASK_0_UNION;
#endif
#define PMIC_IRQ_MASK_0_irq_mask_0_START (0)
#define PMIC_IRQ_MASK_0_irq_mask_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_mask_1 : 8;
    } reg;
} PMIC_IRQ_MASK_1_UNION;
#endif
#define PMIC_IRQ_MASK_1_irq_mask_1_START (0)
#define PMIC_IRQ_MASK_1_irq_mask_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_mask_2 : 8;
    } reg;
} PMIC_IRQ_MASK_2_UNION;
#endif
#define PMIC_IRQ_MASK_2_irq_mask_2_START (0)
#define PMIC_IRQ_MASK_2_irq_mask_2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_mask_3 : 8;
    } reg;
} PMIC_IRQ_MASK_3_UNION;
#endif
#define PMIC_IRQ_MASK_3_irq_mask_3_START (0)
#define PMIC_IRQ_MASK_3_irq_mask_3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_mask_4 : 8;
    } reg;
} PMIC_IRQ_MASK_4_UNION;
#endif
#define PMIC_IRQ_MASK_4_irq_mask_4_START (0)
#define PMIC_IRQ_MASK_4_irq_mask_4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_mask_5 : 8;
    } reg;
} PMIC_IRQ_MASK_5_UNION;
#endif
#define PMIC_IRQ_MASK_5_irq_mask_5_START (0)
#define PMIC_IRQ_MASK_5_irq_mask_5_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_mask_6 : 8;
    } reg;
} PMIC_IRQ_MASK_6_UNION;
#endif
#define PMIC_IRQ_MASK_6_irq_mask_6_START (0)
#define PMIC_IRQ_MASK_6_irq_mask_6_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_mask_7 : 8;
    } reg;
} PMIC_IRQ_MASK_7_UNION;
#endif
#define PMIC_IRQ_MASK_7_irq_mask_7_START (0)
#define PMIC_IRQ_MASK_7_irq_mask_7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_mask_8 : 8;
    } reg;
} PMIC_IRQ_MASK_8_UNION;
#endif
#define PMIC_IRQ_MASK_8_irq_mask_8_START (0)
#define PMIC_IRQ_MASK_8_irq_mask_8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char irq_mask_9 : 8;
    } reg;
} PMIC_IRQ_MASK_9_UNION;
#endif
#define PMIC_IRQ_MASK_9_irq_mask_9_START (0)
#define PMIC_IRQ_MASK_9_irq_mask_9_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio_mask : 8;
    } reg;
} PMIC_IRQ_MASK_10_UNION;
#endif
#define PMIC_IRQ_MASK_10_gpio_mask_START (0)
#define PMIC_IRQ_MASK_10_gpio_mask_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char thsd_otmp125_d1mr : 1;
        unsigned char vbus_det_insert_d20mr : 1;
        unsigned char vbus_det_insert_d20mf : 1;
        unsigned char alarmon_r : 1;
        unsigned char pwronn_d6sf : 1;
        unsigned char pwronn_d1sf : 1;
        unsigned char pwronn_d20mr : 1;
        unsigned char pwronn_d20mf : 1;
    } reg;
} PMIC_IRQ0_UNION;
#endif
#define PMIC_IRQ0_thsd_otmp125_d1mr_START (0)
#define PMIC_IRQ0_thsd_otmp125_d1mr_END (0)
#define PMIC_IRQ0_vbus_det_insert_d20mr_START (1)
#define PMIC_IRQ0_vbus_det_insert_d20mr_END (1)
#define PMIC_IRQ0_vbus_det_insert_d20mf_START (2)
#define PMIC_IRQ0_vbus_det_insert_d20mf_END (2)
#define PMIC_IRQ0_alarmon_r_START (3)
#define PMIC_IRQ0_alarmon_r_END (3)
#define PMIC_IRQ0_pwronn_d6sf_START (4)
#define PMIC_IRQ0_pwronn_d6sf_END (4)
#define PMIC_IRQ0_pwronn_d1sf_START (5)
#define PMIC_IRQ0_pwronn_d1sf_END (5)
#define PMIC_IRQ0_pwronn_d20mr_START (6)
#define PMIC_IRQ0_pwronn_d20mr_END (6)
#define PMIC_IRQ0_pwronn_d20mf_START (7)
#define PMIC_IRQ0_pwronn_d20mf_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ocp_scp_r : 1;
        unsigned char coul_r : 1;
        unsigned char sim0_hpd_r : 1;
        unsigned char sim0_hpd_f : 1;
        unsigned char sim1_hpd_r : 1;
        unsigned char sim1_hpd_f : 1;
        unsigned char reserved : 2;
    } reg;
} PMIC_IRQ1_UNION;
#endif
#define PMIC_IRQ1_ocp_scp_r_START (0)
#define PMIC_IRQ1_ocp_scp_r_END (0)
#define PMIC_IRQ1_coul_r_START (1)
#define PMIC_IRQ1_coul_r_END (1)
#define PMIC_IRQ1_sim0_hpd_r_START (2)
#define PMIC_IRQ1_sim0_hpd_r_END (2)
#define PMIC_IRQ1_sim0_hpd_f_START (3)
#define PMIC_IRQ1_sim0_hpd_f_END (3)
#define PMIC_IRQ1_sim1_hpd_r_START (4)
#define PMIC_IRQ1_sim1_hpd_r_END (4)
#define PMIC_IRQ1_sim1_hpd_f_START (5)
#define PMIC_IRQ1_sim1_hpd_f_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ocpbuck7 : 1;
        unsigned char ocpbuck6 : 1;
        unsigned char ocpbuck5 : 1;
        unsigned char ocpbuck4 : 1;
        unsigned char ocpbuck3 : 1;
        unsigned char ocpbuck2 : 1;
        unsigned char ocpbuck1 : 1;
        unsigned char ocpbuck0 : 1;
    } reg;
} PMIC_OCP_IRQ0_UNION;
#endif
#define PMIC_OCP_IRQ0_ocpbuck7_START (0)
#define PMIC_OCP_IRQ0_ocpbuck7_END (0)
#define PMIC_OCP_IRQ0_ocpbuck6_START (1)
#define PMIC_OCP_IRQ0_ocpbuck6_END (1)
#define PMIC_OCP_IRQ0_ocpbuck5_START (2)
#define PMIC_OCP_IRQ0_ocpbuck5_END (2)
#define PMIC_OCP_IRQ0_ocpbuck4_START (3)
#define PMIC_OCP_IRQ0_ocpbuck4_END (3)
#define PMIC_OCP_IRQ0_ocpbuck3_START (4)
#define PMIC_OCP_IRQ0_ocpbuck3_END (4)
#define PMIC_OCP_IRQ0_ocpbuck2_START (5)
#define PMIC_OCP_IRQ0_ocpbuck2_END (5)
#define PMIC_OCP_IRQ0_ocpbuck1_START (6)
#define PMIC_OCP_IRQ0_ocpbuck1_END (6)
#define PMIC_OCP_IRQ0_ocpbuck0_START (7)
#define PMIC_OCP_IRQ0_ocpbuck0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ocpldo3 : 1;
        unsigned char ocpldo2 : 1;
        unsigned char ocpldo1 : 1;
        unsigned char ocpldo0_2 : 1;
        unsigned char ocpbuck8 : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_OCP_IRQ1_UNION;
#endif
#define PMIC_OCP_IRQ1_ocpldo3_START (0)
#define PMIC_OCP_IRQ1_ocpldo3_END (0)
#define PMIC_OCP_IRQ1_ocpldo2_START (1)
#define PMIC_OCP_IRQ1_ocpldo2_END (1)
#define PMIC_OCP_IRQ1_ocpldo1_START (2)
#define PMIC_OCP_IRQ1_ocpldo1_END (2)
#define PMIC_OCP_IRQ1_ocpldo0_2_START (3)
#define PMIC_OCP_IRQ1_ocpldo0_2_END (3)
#define PMIC_OCP_IRQ1_ocpbuck8_START (4)
#define PMIC_OCP_IRQ1_ocpbuck8_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ocpldo12 : 1;
        unsigned char ocpldo11 : 1;
        unsigned char ocpldo9 : 1;
        unsigned char ocpldo8 : 1;
        unsigned char ocpldo7 : 1;
        unsigned char ocpldo6 : 1;
        unsigned char ocpldo5 : 1;
        unsigned char ocpldo4 : 1;
    } reg;
} PMIC_OCP_IRQ2_UNION;
#endif
#define PMIC_OCP_IRQ2_ocpldo12_START (0)
#define PMIC_OCP_IRQ2_ocpldo12_END (0)
#define PMIC_OCP_IRQ2_ocpldo11_START (1)
#define PMIC_OCP_IRQ2_ocpldo11_END (1)
#define PMIC_OCP_IRQ2_ocpldo9_START (2)
#define PMIC_OCP_IRQ2_ocpldo9_END (2)
#define PMIC_OCP_IRQ2_ocpldo8_START (3)
#define PMIC_OCP_IRQ2_ocpldo8_END (3)
#define PMIC_OCP_IRQ2_ocpldo7_START (4)
#define PMIC_OCP_IRQ2_ocpldo7_END (4)
#define PMIC_OCP_IRQ2_ocpldo6_START (5)
#define PMIC_OCP_IRQ2_ocpldo6_END (5)
#define PMIC_OCP_IRQ2_ocpldo5_START (6)
#define PMIC_OCP_IRQ2_ocpldo5_END (6)
#define PMIC_OCP_IRQ2_ocpldo4_START (7)
#define PMIC_OCP_IRQ2_ocpldo4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ocpldo20 : 1;
        unsigned char ocpldo19 : 1;
        unsigned char ocpldo18 : 1;
        unsigned char ocpldo17 : 1;
        unsigned char ocpldo16 : 1;
        unsigned char ocpldo15 : 1;
        unsigned char ocpldo14 : 1;
        unsigned char ocpldo13 : 1;
    } reg;
} PMIC_OCP_IRQ3_UNION;
#endif
#define PMIC_OCP_IRQ3_ocpldo20_START (0)
#define PMIC_OCP_IRQ3_ocpldo20_END (0)
#define PMIC_OCP_IRQ3_ocpldo19_START (1)
#define PMIC_OCP_IRQ3_ocpldo19_END (1)
#define PMIC_OCP_IRQ3_ocpldo18_START (2)
#define PMIC_OCP_IRQ3_ocpldo18_END (2)
#define PMIC_OCP_IRQ3_ocpldo17_START (3)
#define PMIC_OCP_IRQ3_ocpldo17_END (3)
#define PMIC_OCP_IRQ3_ocpldo16_START (4)
#define PMIC_OCP_IRQ3_ocpldo16_END (4)
#define PMIC_OCP_IRQ3_ocpldo15_START (5)
#define PMIC_OCP_IRQ3_ocpldo15_END (5)
#define PMIC_OCP_IRQ3_ocpldo14_START (6)
#define PMIC_OCP_IRQ3_ocpldo14_END (6)
#define PMIC_OCP_IRQ3_ocpldo13_START (7)
#define PMIC_OCP_IRQ3_ocpldo13_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ocpldo28 : 1;
        unsigned char ocpldo27 : 1;
        unsigned char ocpldo26 : 1;
        unsigned char ocpldo25 : 1;
        unsigned char ocpldo24 : 1;
        unsigned char ocpldo23 : 1;
        unsigned char ocpldo22 : 1;
        unsigned char ocpldo21 : 1;
    } reg;
} PMIC_OCP_IRQ4_UNION;
#endif
#define PMIC_OCP_IRQ4_ocpldo28_START (0)
#define PMIC_OCP_IRQ4_ocpldo28_END (0)
#define PMIC_OCP_IRQ4_ocpldo27_START (1)
#define PMIC_OCP_IRQ4_ocpldo27_END (1)
#define PMIC_OCP_IRQ4_ocpldo26_START (2)
#define PMIC_OCP_IRQ4_ocpldo26_END (2)
#define PMIC_OCP_IRQ4_ocpldo25_START (3)
#define PMIC_OCP_IRQ4_ocpldo25_END (3)
#define PMIC_OCP_IRQ4_ocpldo24_START (4)
#define PMIC_OCP_IRQ4_ocpldo24_END (4)
#define PMIC_OCP_IRQ4_ocpldo23_START (5)
#define PMIC_OCP_IRQ4_ocpldo23_END (5)
#define PMIC_OCP_IRQ4_ocpldo22_START (6)
#define PMIC_OCP_IRQ4_ocpldo22_END (6)
#define PMIC_OCP_IRQ4_ocpldo21_START (7)
#define PMIC_OCP_IRQ4_ocpldo21_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ocpldo36 : 1;
        unsigned char ocpldo35 : 1;
        unsigned char ocpldo34 : 1;
        unsigned char ocpldo33 : 1;
        unsigned char ocpldo32 : 1;
        unsigned char ocpldo30 : 1;
        unsigned char ocpldo29 : 1;
        unsigned char reserved : 1;
    } reg;
} PMIC_OCP_IRQ5_UNION;
#endif
#define PMIC_OCP_IRQ5_ocpldo36_START (0)
#define PMIC_OCP_IRQ5_ocpldo36_END (0)
#define PMIC_OCP_IRQ5_ocpldo35_START (1)
#define PMIC_OCP_IRQ5_ocpldo35_END (1)
#define PMIC_OCP_IRQ5_ocpldo34_START (2)
#define PMIC_OCP_IRQ5_ocpldo34_END (2)
#define PMIC_OCP_IRQ5_ocpldo33_START (3)
#define PMIC_OCP_IRQ5_ocpldo33_END (3)
#define PMIC_OCP_IRQ5_ocpldo32_START (4)
#define PMIC_OCP_IRQ5_ocpldo32_END (4)
#define PMIC_OCP_IRQ5_ocpldo30_START (5)
#define PMIC_OCP_IRQ5_ocpldo30_END (5)
#define PMIC_OCP_IRQ5_ocpldo29_START (6)
#define PMIC_OCP_IRQ5_ocpldo29_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char buck7_scp : 1;
        unsigned char buck6_scp : 1;
        unsigned char buck5_scp : 1;
        unsigned char buck4_scp : 1;
        unsigned char buck3_scp : 1;
        unsigned char buck2_scp : 1;
        unsigned char buck1_scp : 1;
        unsigned char buck0_scp : 1;
    } reg;
} PMIC_OCP_IRQ6_UNION;
#endif
#define PMIC_OCP_IRQ6_buck7_scp_START (0)
#define PMIC_OCP_IRQ6_buck7_scp_END (0)
#define PMIC_OCP_IRQ6_buck6_scp_START (1)
#define PMIC_OCP_IRQ6_buck6_scp_END (1)
#define PMIC_OCP_IRQ6_buck5_scp_START (2)
#define PMIC_OCP_IRQ6_buck5_scp_END (2)
#define PMIC_OCP_IRQ6_buck4_scp_START (3)
#define PMIC_OCP_IRQ6_buck4_scp_END (3)
#define PMIC_OCP_IRQ6_buck3_scp_START (4)
#define PMIC_OCP_IRQ6_buck3_scp_END (4)
#define PMIC_OCP_IRQ6_buck2_scp_START (5)
#define PMIC_OCP_IRQ6_buck2_scp_END (5)
#define PMIC_OCP_IRQ6_buck1_scp_START (6)
#define PMIC_OCP_IRQ6_buck1_scp_END (6)
#define PMIC_OCP_IRQ6_buck0_scp_START (7)
#define PMIC_OCP_IRQ6_buck0_scp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ldo_buff_scp : 1;
        unsigned char buck8_scp : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_OCP_IRQ7_UNION;
#endif
#define PMIC_OCP_IRQ7_ldo_buff_scp_START (0)
#define PMIC_OCP_IRQ7_ldo_buff_scp_END (0)
#define PMIC_OCP_IRQ7_buck8_scp_START (1)
#define PMIC_OCP_IRQ7_buck8_scp_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char gpio0_int_status : 1;
        unsigned char gpio1_int_status : 1;
        unsigned char gpio2_int_status : 1;
        unsigned char reserved : 5;
    } reg;
} PMIC_GPIO_IRQ_UNION;
#endif
#define PMIC_GPIO_IRQ_gpio0_int_status_START (0)
#define PMIC_GPIO_IRQ_gpio0_int_status_END (0)
#define PMIC_GPIO_IRQ_gpio1_int_status_START (1)
#define PMIC_GPIO_IRQ_gpio1_int_status_END (1)
#define PMIC_GPIO_IRQ_gpio2_int_status_START (2)
#define PMIC_GPIO_IRQ_gpio2_int_status_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_ocpbuck7 : 1;
        unsigned char np_ocpbuck6 : 1;
        unsigned char np_ocpbuck5 : 1;
        unsigned char np_ocpbuck4 : 1;
        unsigned char np_ocpbuck3 : 1;
        unsigned char np_ocpbuck2 : 1;
        unsigned char np_ocpbuck1 : 1;
        unsigned char np_ocpbuck0 : 1;
    } reg;
} PMIC_NP_OCP0_UNION;
#endif
#define PMIC_NP_OCP0_np_ocpbuck7_START (0)
#define PMIC_NP_OCP0_np_ocpbuck7_END (0)
#define PMIC_NP_OCP0_np_ocpbuck6_START (1)
#define PMIC_NP_OCP0_np_ocpbuck6_END (1)
#define PMIC_NP_OCP0_np_ocpbuck5_START (2)
#define PMIC_NP_OCP0_np_ocpbuck5_END (2)
#define PMIC_NP_OCP0_np_ocpbuck4_START (3)
#define PMIC_NP_OCP0_np_ocpbuck4_END (3)
#define PMIC_NP_OCP0_np_ocpbuck3_START (4)
#define PMIC_NP_OCP0_np_ocpbuck3_END (4)
#define PMIC_NP_OCP0_np_ocpbuck2_START (5)
#define PMIC_NP_OCP0_np_ocpbuck2_END (5)
#define PMIC_NP_OCP0_np_ocpbuck1_START (6)
#define PMIC_NP_OCP0_np_ocpbuck1_END (6)
#define PMIC_NP_OCP0_np_ocpbuck0_START (7)
#define PMIC_NP_OCP0_np_ocpbuck0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_ocpldo3 : 1;
        unsigned char np_ocpldo2 : 1;
        unsigned char np_ocpldo1 : 1;
        unsigned char np_ocpldo0_2 : 1;
        unsigned char np_ocpbuck8 : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_NP_OCP1_UNION;
#endif
#define PMIC_NP_OCP1_np_ocpldo3_START (0)
#define PMIC_NP_OCP1_np_ocpldo3_END (0)
#define PMIC_NP_OCP1_np_ocpldo2_START (1)
#define PMIC_NP_OCP1_np_ocpldo2_END (1)
#define PMIC_NP_OCP1_np_ocpldo1_START (2)
#define PMIC_NP_OCP1_np_ocpldo1_END (2)
#define PMIC_NP_OCP1_np_ocpldo0_2_START (3)
#define PMIC_NP_OCP1_np_ocpldo0_2_END (3)
#define PMIC_NP_OCP1_np_ocpbuck8_START (4)
#define PMIC_NP_OCP1_np_ocpbuck8_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_ocpldo12 : 1;
        unsigned char np_ocpldo11 : 1;
        unsigned char np_ocpldo9 : 1;
        unsigned char np_ocpldo8 : 1;
        unsigned char np_ocpldo7 : 1;
        unsigned char np_ocpldo6 : 1;
        unsigned char np_ocpldo5 : 1;
        unsigned char np_ocpldo4 : 1;
    } reg;
} PMIC_NP_OCP2_UNION;
#endif
#define PMIC_NP_OCP2_np_ocpldo12_START (0)
#define PMIC_NP_OCP2_np_ocpldo12_END (0)
#define PMIC_NP_OCP2_np_ocpldo11_START (1)
#define PMIC_NP_OCP2_np_ocpldo11_END (1)
#define PMIC_NP_OCP2_np_ocpldo9_START (2)
#define PMIC_NP_OCP2_np_ocpldo9_END (2)
#define PMIC_NP_OCP2_np_ocpldo8_START (3)
#define PMIC_NP_OCP2_np_ocpldo8_END (3)
#define PMIC_NP_OCP2_np_ocpldo7_START (4)
#define PMIC_NP_OCP2_np_ocpldo7_END (4)
#define PMIC_NP_OCP2_np_ocpldo6_START (5)
#define PMIC_NP_OCP2_np_ocpldo6_END (5)
#define PMIC_NP_OCP2_np_ocpldo5_START (6)
#define PMIC_NP_OCP2_np_ocpldo5_END (6)
#define PMIC_NP_OCP2_np_ocpldo4_START (7)
#define PMIC_NP_OCP2_np_ocpldo4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_ocpldo20 : 1;
        unsigned char np_ocpldo19 : 1;
        unsigned char np_ocpldo18 : 1;
        unsigned char np_ocpldo17 : 1;
        unsigned char np_ocpldo16 : 1;
        unsigned char np_ocpldo15 : 1;
        unsigned char np_ocpldo14 : 1;
        unsigned char np_ocpldo13 : 1;
    } reg;
} PMIC_NP_OCP3_UNION;
#endif
#define PMIC_NP_OCP3_np_ocpldo20_START (0)
#define PMIC_NP_OCP3_np_ocpldo20_END (0)
#define PMIC_NP_OCP3_np_ocpldo19_START (1)
#define PMIC_NP_OCP3_np_ocpldo19_END (1)
#define PMIC_NP_OCP3_np_ocpldo18_START (2)
#define PMIC_NP_OCP3_np_ocpldo18_END (2)
#define PMIC_NP_OCP3_np_ocpldo17_START (3)
#define PMIC_NP_OCP3_np_ocpldo17_END (3)
#define PMIC_NP_OCP3_np_ocpldo16_START (4)
#define PMIC_NP_OCP3_np_ocpldo16_END (4)
#define PMIC_NP_OCP3_np_ocpldo15_START (5)
#define PMIC_NP_OCP3_np_ocpldo15_END (5)
#define PMIC_NP_OCP3_np_ocpldo14_START (6)
#define PMIC_NP_OCP3_np_ocpldo14_END (6)
#define PMIC_NP_OCP3_np_ocpldo13_START (7)
#define PMIC_NP_OCP3_np_ocpldo13_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_ocpldo28 : 1;
        unsigned char np_ocpldo27 : 1;
        unsigned char np_ocpldo26 : 1;
        unsigned char np_ocpldo25 : 1;
        unsigned char np_ocpldo24 : 1;
        unsigned char np_ocpldo23 : 1;
        unsigned char np_ocpldo22 : 1;
        unsigned char np_ocpldo21 : 1;
    } reg;
} PMIC_NP_OCP4_UNION;
#endif
#define PMIC_NP_OCP4_np_ocpldo28_START (0)
#define PMIC_NP_OCP4_np_ocpldo28_END (0)
#define PMIC_NP_OCP4_np_ocpldo27_START (1)
#define PMIC_NP_OCP4_np_ocpldo27_END (1)
#define PMIC_NP_OCP4_np_ocpldo26_START (2)
#define PMIC_NP_OCP4_np_ocpldo26_END (2)
#define PMIC_NP_OCP4_np_ocpldo25_START (3)
#define PMIC_NP_OCP4_np_ocpldo25_END (3)
#define PMIC_NP_OCP4_np_ocpldo24_START (4)
#define PMIC_NP_OCP4_np_ocpldo24_END (4)
#define PMIC_NP_OCP4_np_ocpldo23_START (5)
#define PMIC_NP_OCP4_np_ocpldo23_END (5)
#define PMIC_NP_OCP4_np_ocpldo22_START (6)
#define PMIC_NP_OCP4_np_ocpldo22_END (6)
#define PMIC_NP_OCP4_np_ocpldo21_START (7)
#define PMIC_NP_OCP4_np_ocpldo21_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_ocpldo36 : 1;
        unsigned char np_ocpldo35 : 1;
        unsigned char np_ocpldo34 : 1;
        unsigned char np_ocpldo33 : 1;
        unsigned char np_ocpldo32 : 1;
        unsigned char np_ocpldo30 : 1;
        unsigned char np_ocpldo29 : 1;
        unsigned char reserved : 1;
    } reg;
} PMIC_NP_OCP5_UNION;
#endif
#define PMIC_NP_OCP5_np_ocpldo36_START (0)
#define PMIC_NP_OCP5_np_ocpldo36_END (0)
#define PMIC_NP_OCP5_np_ocpldo35_START (1)
#define PMIC_NP_OCP5_np_ocpldo35_END (1)
#define PMIC_NP_OCP5_np_ocpldo34_START (2)
#define PMIC_NP_OCP5_np_ocpldo34_END (2)
#define PMIC_NP_OCP5_np_ocpldo33_START (3)
#define PMIC_NP_OCP5_np_ocpldo33_END (3)
#define PMIC_NP_OCP5_np_ocpldo32_START (4)
#define PMIC_NP_OCP5_np_ocpldo32_END (4)
#define PMIC_NP_OCP5_np_ocpldo30_START (5)
#define PMIC_NP_OCP5_np_ocpldo30_END (5)
#define PMIC_NP_OCP5_np_ocpldo29_START (6)
#define PMIC_NP_OCP5_np_ocpldo29_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_buck7_scp : 1;
        unsigned char np_buck6_scp : 1;
        unsigned char np_buck5_scp : 1;
        unsigned char np_buck4_scp : 1;
        unsigned char np_buck3_scp : 1;
        unsigned char np_buck2_scp : 1;
        unsigned char np_buck1_scp : 1;
        unsigned char np_buck0_scp : 1;
    } reg;
} PMIC_NP_SCP0_UNION;
#endif
#define PMIC_NP_SCP0_np_buck7_scp_START (0)
#define PMIC_NP_SCP0_np_buck7_scp_END (0)
#define PMIC_NP_SCP0_np_buck6_scp_START (1)
#define PMIC_NP_SCP0_np_buck6_scp_END (1)
#define PMIC_NP_SCP0_np_buck5_scp_START (2)
#define PMIC_NP_SCP0_np_buck5_scp_END (2)
#define PMIC_NP_SCP0_np_buck4_scp_START (3)
#define PMIC_NP_SCP0_np_buck4_scp_END (3)
#define PMIC_NP_SCP0_np_buck3_scp_START (4)
#define PMIC_NP_SCP0_np_buck3_scp_END (4)
#define PMIC_NP_SCP0_np_buck2_scp_START (5)
#define PMIC_NP_SCP0_np_buck2_scp_END (5)
#define PMIC_NP_SCP0_np_buck1_scp_START (6)
#define PMIC_NP_SCP0_np_buck1_scp_END (6)
#define PMIC_NP_SCP0_np_buck0_scp_START (7)
#define PMIC_NP_SCP0_np_buck0_scp_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_ldo_buff_scp : 1;
        unsigned char np_buck8_scp : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_NP_SCP1_UNION;
#endif
#define PMIC_NP_SCP1_np_ldo_buff_scp_START (0)
#define PMIC_NP_SCP1_np_ldo_buff_scp_END (0)
#define PMIC_NP_SCP1_np_buck8_scp_START (1)
#define PMIC_NP_SCP1_np_buck8_scp_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_vsys_ov_d200ur : 1;
        unsigned char np_vsys_pwroff_abs_2d : 1;
        unsigned char np_vsys_pwroff_deb_d80mr : 1;
        unsigned char np_thsd_otmp140_d1mr : 1;
        unsigned char np_thsd_otmp125_d1mr : 1;
        unsigned char np_hresetn_d90uf : 1;
        unsigned char np_avdd_osc_vld_d20nf : 1;
        unsigned char np_19m2_dis : 1;
    } reg;
} PMIC_NP_RECORD0_UNION;
#endif
#define PMIC_NP_RECORD0_np_vsys_ov_d200ur_START (0)
#define PMIC_NP_RECORD0_np_vsys_ov_d200ur_END (0)
#define PMIC_NP_RECORD0_np_vsys_pwroff_abs_2d_START (1)
#define PMIC_NP_RECORD0_np_vsys_pwroff_abs_2d_END (1)
#define PMIC_NP_RECORD0_np_vsys_pwroff_deb_d80mr_START (2)
#define PMIC_NP_RECORD0_np_vsys_pwroff_deb_d80mr_END (2)
#define PMIC_NP_RECORD0_np_thsd_otmp140_d1mr_START (3)
#define PMIC_NP_RECORD0_np_thsd_otmp140_d1mr_END (3)
#define PMIC_NP_RECORD0_np_thsd_otmp125_d1mr_START (4)
#define PMIC_NP_RECORD0_np_thsd_otmp125_d1mr_END (4)
#define PMIC_NP_RECORD0_np_hresetn_d90uf_START (5)
#define PMIC_NP_RECORD0_np_hresetn_d90uf_END (5)
#define PMIC_NP_RECORD0_np_avdd_osc_vld_d20nf_START (6)
#define PMIC_NP_RECORD0_np_avdd_osc_vld_d20nf_END (6)
#define PMIC_NP_RECORD0_np_19m2_dis_START (7)
#define PMIC_NP_RECORD0_np_19m2_dis_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_pwronn_restart : 1;
        unsigned char np_pwrhold_shutdown : 1;
        unsigned char np_pwronn_shutdown : 1;
        unsigned char np_pwrhold_pwrup : 1;
        unsigned char np_alarmon_pwrup : 1;
        unsigned char np_vbus_pwrup : 1;
        unsigned char np_pwronn_pwrup : 1;
        unsigned char np_fast_pwrup : 1;
    } reg;
} PMIC_NP_RECORD1_UNION;
#endif
#define PMIC_NP_RECORD1_np_pwronn_restart_START (0)
#define PMIC_NP_RECORD1_np_pwronn_restart_END (0)
#define PMIC_NP_RECORD1_np_pwrhold_shutdown_START (1)
#define PMIC_NP_RECORD1_np_pwrhold_shutdown_END (1)
#define PMIC_NP_RECORD1_np_pwronn_shutdown_START (2)
#define PMIC_NP_RECORD1_np_pwronn_shutdown_END (2)
#define PMIC_NP_RECORD1_np_pwrhold_pwrup_START (3)
#define PMIC_NP_RECORD1_np_pwrhold_pwrup_END (3)
#define PMIC_NP_RECORD1_np_alarmon_pwrup_START (4)
#define PMIC_NP_RECORD1_np_alarmon_pwrup_END (4)
#define PMIC_NP_RECORD1_np_vbus_pwrup_START (5)
#define PMIC_NP_RECORD1_np_vbus_pwrup_END (5)
#define PMIC_NP_RECORD1_np_pwronn_pwrup_START (6)
#define PMIC_NP_RECORD1_np_pwronn_pwrup_END (6)
#define PMIC_NP_RECORD1_np_fast_pwrup_START (7)
#define PMIC_NP_RECORD1_np_fast_pwrup_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_dcxo_clk_sel_r : 1;
        unsigned char np_dcxo_clk_sel_f : 1;
        unsigned char np_vsys_vcoin_sel : 1;
        unsigned char np_smpl : 1;
        unsigned char np_core_io_vld_f : 1;
        unsigned char np_pwrhold_4s : 1;
        unsigned char reserved : 2;
    } reg;
} PMIC_NP_RECORD2_UNION;
#endif
#define PMIC_NP_RECORD2_np_dcxo_clk_sel_r_START (0)
#define PMIC_NP_RECORD2_np_dcxo_clk_sel_r_END (0)
#define PMIC_NP_RECORD2_np_dcxo_clk_sel_f_START (1)
#define PMIC_NP_RECORD2_np_dcxo_clk_sel_f_END (1)
#define PMIC_NP_RECORD2_np_vsys_vcoin_sel_START (2)
#define PMIC_NP_RECORD2_np_vsys_vcoin_sel_END (2)
#define PMIC_NP_RECORD2_np_smpl_START (3)
#define PMIC_NP_RECORD2_np_smpl_END (3)
#define PMIC_NP_RECORD2_np_core_io_vld_f_START (4)
#define PMIC_NP_RECORD2_np_core_io_vld_f_END (4)
#define PMIC_NP_RECORD2_np_pwrhold_4s_START (5)
#define PMIC_NP_RECORD2_np_pwrhold_4s_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_pmua_short_f : 1;
        unsigned char np_ldo35_short_f : 1;
        unsigned char np_vin_ldoh_shutdown : 1;
        unsigned char np_vsys_pwron_shutdown : 1;
        unsigned char reserved : 4;
    } reg;
} PMIC_NP_RECORD3_UNION;
#endif
#define PMIC_NP_RECORD3_np_pmua_short_f_START (0)
#define PMIC_NP_RECORD3_np_pmua_short_f_END (0)
#define PMIC_NP_RECORD3_np_ldo35_short_f_START (1)
#define PMIC_NP_RECORD3_np_ldo35_short_f_END (1)
#define PMIC_NP_RECORD3_np_vin_ldoh_shutdown_START (2)
#define PMIC_NP_RECORD3_np_vin_ldoh_shutdown_END (2)
#define PMIC_NP_RECORD3_np_vsys_pwron_shutdown_START (3)
#define PMIC_NP_RECORD3_np_vsys_pwron_shutdown_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_cali_ldo35_ocp : 1;
        unsigned char np_cali_ldo26_ocp : 1;
        unsigned char np_cali_buck3_scp : 1;
        unsigned char np_cali_buck3_ocp : 1;
        unsigned char np_cali_ldo35_short : 1;
        unsigned char np_cali_pmua_short : 1;
        unsigned char np_cali_vsys_pwroff_deb : 1;
        unsigned char np_cali_vsys_pwroff_abs : 1;
    } reg;
} PMIC_NP_RECORD4_UNION;
#endif
#define PMIC_NP_RECORD4_np_cali_ldo35_ocp_START (0)
#define PMIC_NP_RECORD4_np_cali_ldo35_ocp_END (0)
#define PMIC_NP_RECORD4_np_cali_ldo26_ocp_START (1)
#define PMIC_NP_RECORD4_np_cali_ldo26_ocp_END (1)
#define PMIC_NP_RECORD4_np_cali_buck3_scp_START (2)
#define PMIC_NP_RECORD4_np_cali_buck3_scp_END (2)
#define PMIC_NP_RECORD4_np_cali_buck3_ocp_START (3)
#define PMIC_NP_RECORD4_np_cali_buck3_ocp_END (3)
#define PMIC_NP_RECORD4_np_cali_ldo35_short_START (4)
#define PMIC_NP_RECORD4_np_cali_ldo35_short_END (4)
#define PMIC_NP_RECORD4_np_cali_pmua_short_START (5)
#define PMIC_NP_RECORD4_np_cali_pmua_short_END (5)
#define PMIC_NP_RECORD4_np_cali_vsys_pwroff_deb_START (6)
#define PMIC_NP_RECORD4_np_cali_vsys_pwroff_deb_END (6)
#define PMIC_NP_RECORD4_np_cali_vsys_pwroff_abs_START (7)
#define PMIC_NP_RECORD4_np_cali_vsys_pwroff_abs_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_cali_avdd_osc_vld : 1;
        unsigned char np_cali_thsd_otmp140 : 1;
        unsigned char np_cali_thsd_otmp125 : 1;
        unsigned char np_cali_vsys_ov : 1;
        unsigned char reserved : 4;
    } reg;
} PMIC_NP_RECORD5_UNION;
#endif
#define PMIC_NP_RECORD5_np_cali_avdd_osc_vld_START (0)
#define PMIC_NP_RECORD5_np_cali_avdd_osc_vld_END (0)
#define PMIC_NP_RECORD5_np_cali_thsd_otmp140_START (1)
#define PMIC_NP_RECORD5_np_cali_thsd_otmp140_END (1)
#define PMIC_NP_RECORD5_np_cali_thsd_otmp125_START (2)
#define PMIC_NP_RECORD5_np_cali_thsd_otmp125_END (2)
#define PMIC_NP_RECORD5_np_cali_vsys_ov_START (3)
#define PMIC_NP_RECORD5_np_cali_vsys_ov_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_pwron_n_hrst : 1;
        unsigned char np_ramp_abnor_1 : 1;
        unsigned char np_ramp_abnor_2 : 1;
        unsigned char np_ramp_abnor_3 : 1;
        unsigned char np_ramp_abnor_4 : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_PWRONN_RAMP_EVENT_UNION;
#endif
#define PMIC_PWRONN_RAMP_EVENT_np_pwron_n_hrst_START (0)
#define PMIC_PWRONN_RAMP_EVENT_np_pwron_n_hrst_END (0)
#define PMIC_PWRONN_RAMP_EVENT_np_ramp_abnor_1_START (1)
#define PMIC_PWRONN_RAMP_EVENT_np_ramp_abnor_1_END (1)
#define PMIC_PWRONN_RAMP_EVENT_np_ramp_abnor_2_START (2)
#define PMIC_PWRONN_RAMP_EVENT_np_ramp_abnor_2_END (2)
#define PMIC_PWRONN_RAMP_EVENT_np_ramp_abnor_3_START (3)
#define PMIC_PWRONN_RAMP_EVENT_np_ramp_abnor_3_END (3)
#define PMIC_PWRONN_RAMP_EVENT_np_ramp_abnor_4_START (4)
#define PMIC_PWRONN_RAMP_EVENT_np_ramp_abnor_4_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_xo_dig_abb_sel : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_CLK_ABB_CTRL1_UNION;
#endif
#define PMIC_CLK_ABB_CTRL1_np_xo_dig_abb_sel_START (0)
#define PMIC_CLK_ABB_CTRL1_np_xo_dig_abb_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_xo_dig_wifi_sel : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_CLK_WIFI_CTRL1_UNION;
#endif
#define PMIC_CLK_WIFI_CTRL1_np_xo_dig_wifi_sel_START (0)
#define PMIC_CLK_WIFI_CTRL1_np_xo_dig_wifi_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_xo_dig_nfc_sel : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_CLK_NFC_CTRL1_UNION;
#endif
#define PMIC_CLK_NFC_CTRL1_np_xo_dig_nfc_sel_START (0)
#define PMIC_CLK_NFC_CTRL1_np_xo_dig_nfc_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_xo_dig_rf0_sel : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_CLK_RF0_CTRL1_UNION;
#endif
#define PMIC_CLK_RF0_CTRL1_np_xo_dig_rf0_sel_START (0)
#define PMIC_CLK_RF0_CTRL1_np_xo_dig_rf0_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_xo_dig_rf1_sel : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_CLK_RF1_CTRL1_UNION;
#endif
#define PMIC_CLK_RF1_CTRL1_np_xo_dig_rf1_sel_START (0)
#define PMIC_CLK_RF1_CTRL1_np_xo_dig_rf1_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_xo_trim_c2fix : 4;
        unsigned char reserved : 4;
    } reg;
} PMIC_CLK_TOP_CTRL1_0_UNION;
#endif
#define PMIC_CLK_TOP_CTRL1_0_np_xo_trim_c2fix_START (0)
#define PMIC_CLK_TOP_CTRL1_0_np_xo_trim_c2fix_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_xo_trim_c1fix : 8;
    } reg;
} PMIC_CLK_TOP_CTRL1_1_UNION;
#endif
#define PMIC_CLK_TOP_CTRL1_1_np_xo_trim_c1fix_START (0)
#define PMIC_CLK_TOP_CTRL1_1_np_xo_trim_c1fix_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_reg_256k_en0 : 8;
    } reg;
} PMIC_CLK_256K_CTRL0_UNION;
#endif
#define PMIC_CLK_256K_CTRL0_np_reg_256k_en0_START (0)
#define PMIC_CLK_256K_CTRL0_np_reg_256k_en0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_reg_256k_en1 : 8;
    } reg;
} PMIC_CLK_256K_CTRL1_UNION;
#endif
#define PMIC_CLK_256K_CTRL1_np_reg_256k_en1_START (0)
#define PMIC_CLK_256K_CTRL1_np_reg_256k_en1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_vsys_pwroff_deb_set : 2;
        unsigned char np_vsys_pwroff_abs_set : 2;
        unsigned char np_vsys_pwron_set : 2;
        unsigned char reserved : 2;
    } reg;
} PMIC_VSYS_LOW_SET_UNION;
#endif
#define PMIC_VSYS_LOW_SET_np_vsys_pwroff_deb_set_START (0)
#define PMIC_VSYS_LOW_SET_np_vsys_pwroff_deb_set_END (1)
#define PMIC_VSYS_LOW_SET_np_vsys_pwroff_abs_set_START (2)
#define PMIC_VSYS_LOW_SET_np_vsys_pwroff_abs_set_END (3)
#define PMIC_VSYS_LOW_SET_np_vsys_pwron_set_START (4)
#define PMIC_VSYS_LOW_SET_np_vsys_pwron_set_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_nfc_on_d2a : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_NFC_ON_CTRL_UNION;
#endif
#define PMIC_NFC_ON_CTRL_np_nfc_on_d2a_START (0)
#define PMIC_NFC_ON_CTRL_np_nfc_on_d2a_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_hreset_mode : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_HRESET_PWRDOWN_CTRL_UNION;
#endif
#define PMIC_HRESET_PWRDOWN_CTRL_np_hreset_mode_START (0)
#define PMIC_HRESET_PWRDOWN_CTRL_np_hreset_mode_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_smpl_open_en : 1;
        unsigned char np_smpl_time_sel : 2;
        unsigned char reserved : 5;
    } reg;
} PMIC_SMPL_CTRL_UNION;
#endif
#define PMIC_SMPL_CTRL_np_smpl_open_en_START (0)
#define PMIC_SMPL_CTRL_np_smpl_open_en_END (0)
#define PMIC_SMPL_CTRL_np_smpl_time_sel_START (1)
#define PMIC_SMPL_CTRL_np_smpl_time_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_pwron_8s_sel : 1;
        unsigned char np_pwron_time_sel : 2;
        unsigned char reserved : 5;
    } reg;
} PMIC_SYS_CTRL1_UNION;
#endif
#define PMIC_SYS_CTRL1_np_pwron_8s_sel_START (0)
#define PMIC_SYS_CTRL1_np_pwron_8s_sel_END (0)
#define PMIC_SYS_CTRL1_np_pwron_time_sel_START (1)
#define PMIC_SYS_CTRL1_np_pwron_time_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_debug_lock : 8;
    } reg;
} PMIC_DEBUG_LOCK_UNION;
#endif
#define PMIC_DEBUG_LOCK_np_debug_lock_START (0)
#define PMIC_DEBUG_LOCK_np_debug_lock_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_sys_debug0 : 8;
    } reg;
} PMIC_SYS_DEBUG0_UNION;
#endif
#define PMIC_SYS_DEBUG0_np_sys_debug0_START (0)
#define PMIC_SYS_DEBUG0_np_sys_debug0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_sys_debug1 : 8;
    } reg;
} PMIC_SYS_DEBUG1_UNION;
#endif
#define PMIC_SYS_DEBUG1_np_sys_debug1_START (0)
#define PMIC_SYS_DEBUG1_np_sys_debug1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_reg_rc_debug : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_SYS_DEBUG2_UNION;
#endif
#define PMIC_SYS_DEBUG2_np_reg_rc_debug_START (0)
#define PMIC_SYS_DEBUG2_np_reg_rc_debug_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_vsys_pwroff_abs_pd_mask : 1;
        unsigned char np_vsys_pwroff_deb_pd_mask : 1;
        unsigned char np_thsd_otmp140_pd_mask : 1;
        unsigned char np_vsys_ov_pd_mask : 1;
        unsigned char np_vin_ldoh_vld_pd_mask : 1;
        unsigned char reserved : 3;
    } reg;
} PMIC_SYS_DEBUG3_UNION;
#endif
#define PMIC_SYS_DEBUG3_np_vsys_pwroff_abs_pd_mask_START (0)
#define PMIC_SYS_DEBUG3_np_vsys_pwroff_abs_pd_mask_END (0)
#define PMIC_SYS_DEBUG3_np_vsys_pwroff_deb_pd_mask_START (1)
#define PMIC_SYS_DEBUG3_np_vsys_pwroff_deb_pd_mask_END (1)
#define PMIC_SYS_DEBUG3_np_thsd_otmp140_pd_mask_START (2)
#define PMIC_SYS_DEBUG3_np_thsd_otmp140_pd_mask_END (2)
#define PMIC_SYS_DEBUG3_np_vsys_ov_pd_mask_START (3)
#define PMIC_SYS_DEBUG3_np_vsys_ov_pd_mask_END (3)
#define PMIC_SYS_DEBUG3_np_vin_ldoh_vld_pd_mask_START (4)
#define PMIC_SYS_DEBUG3_np_vin_ldoh_vld_pd_mask_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_chg_en : 1;
        unsigned char np_chg_bypass : 1;
        unsigned char np_chg_vset : 2;
        unsigned char reserved : 4;
    } reg;
} PMIC_BACKUP_CHG_UNION;
#endif
#define PMIC_BACKUP_CHG_np_chg_en_START (0)
#define PMIC_BACKUP_CHG_np_chg_en_END (0)
#define PMIC_BACKUP_CHG_np_chg_bypass_START (1)
#define PMIC_BACKUP_CHG_np_chg_bypass_END (1)
#define PMIC_BACKUP_CHG_np_chg_vset_START (2)
#define PMIC_BACKUP_CHG_np_chg_vset_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_rtc_cali_ctrl : 1;
        unsigned char np_hreset_d_sel : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_RTC_CALI_CTRL_UNION;
#endif
#define PMIC_RTC_CALI_CTRL_np_rtc_cali_ctrl_START (0)
#define PMIC_RTC_CALI_CTRL_np_rtc_cali_ctrl_END (0)
#define PMIC_RTC_CALI_CTRL_np_hreset_d_sel_START (1)
#define PMIC_RTC_CALI_CTRL_np_hreset_d_sel_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_d2a_reserve0 : 8;
    } reg;
} PMIC_NP_D2A_RES0_UNION;
#endif
#define PMIC_NP_D2A_RES0_np_d2a_reserve0_START (0)
#define PMIC_NP_D2A_RES0_np_d2a_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_d2a_reserve1 : 8;
    } reg;
} PMIC_NP_D2A_RES1_UNION;
#endif
#define PMIC_NP_D2A_RES1_np_d2a_reserve1_START (0)
#define PMIC_NP_D2A_RES1_np_d2a_reserve1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_hrst_reg0 : 8;
    } reg;
} PMIC_HRST_REG0_UNION;
#endif
#define PMIC_HRST_REG0_np_hrst_reg0_START (0)
#define PMIC_HRST_REG0_np_hrst_reg0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_hrst_reg1 : 8;
    } reg;
} PMIC_HRST_REG1_UNION;
#endif
#define PMIC_HRST_REG1_np_hrst_reg1_START (0)
#define PMIC_HRST_REG1_np_hrst_reg1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_hrst_reg2 : 8;
    } reg;
} PMIC_HRST_REG2_UNION;
#endif
#define PMIC_HRST_REG2_np_hrst_reg2_START (0)
#define PMIC_HRST_REG2_np_hrst_reg2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_hrst_reg3 : 8;
    } reg;
} PMIC_HRST_REG3_UNION;
#endif
#define PMIC_HRST_REG3_np_hrst_reg3_START (0)
#define PMIC_HRST_REG3_np_hrst_reg3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_hrst_reg4 : 8;
    } reg;
} PMIC_HRST_REG4_UNION;
#endif
#define PMIC_HRST_REG4_np_hrst_reg4_START (0)
#define PMIC_HRST_REG4_np_hrst_reg4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_hrst_reg5 : 8;
    } reg;
} PMIC_HRST_REG5_UNION;
#endif
#define PMIC_HRST_REG5_np_hrst_reg5_START (0)
#define PMIC_HRST_REG5_np_hrst_reg5_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_hrst_reg6 : 8;
    } reg;
} PMIC_HRST_REG6_UNION;
#endif
#define PMIC_HRST_REG6_np_hrst_reg6_START (0)
#define PMIC_HRST_REG6_np_hrst_reg6_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_hrst_reg7 : 8;
    } reg;
} PMIC_HRST_REG7_UNION;
#endif
#define PMIC_HRST_REG7_np_hrst_reg7_START (0)
#define PMIC_HRST_REG7_np_hrst_reg7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_hrst_reg8 : 8;
    } reg;
} PMIC_HRST_REG8_UNION;
#endif
#define PMIC_HRST_REG8_np_hrst_reg8_START (0)
#define PMIC_HRST_REG8_np_hrst_reg8_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_hrst_reg9 : 8;
    } reg;
} PMIC_HRST_REG9_UNION;
#endif
#define PMIC_HRST_REG9_np_hrst_reg9_START (0)
#define PMIC_HRST_REG9_np_hrst_reg9_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_hrst_reg10 : 8;
    } reg;
} PMIC_HRST_REG10_UNION;
#endif
#define PMIC_HRST_REG10_np_hrst_reg10_START (0)
#define PMIC_HRST_REG10_np_hrst_reg10_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_hrst_reg11 : 8;
    } reg;
} PMIC_HRST_REG11_UNION;
#endif
#define PMIC_HRST_REG11_np_hrst_reg11_START (0)
#define PMIC_HRST_REG11_np_hrst_reg11_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_hrst_reg12 : 8;
    } reg;
} PMIC_HRST_REG12_UNION;
#endif
#define PMIC_HRST_REG12_np_hrst_reg12_START (0)
#define PMIC_HRST_REG12_np_hrst_reg12_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_hrst_reg13 : 8;
    } reg;
} PMIC_HRST_REG13_UNION;
#endif
#define PMIC_HRST_REG13_np_hrst_reg13_START (0)
#define PMIC_HRST_REG13_np_hrst_reg13_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_hrst_reg14 : 8;
    } reg;
} PMIC_HRST_REG14_UNION;
#endif
#define PMIC_HRST_REG14_np_hrst_reg14_START (0)
#define PMIC_HRST_REG14_np_hrst_reg14_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob0_d2a : 8;
    } reg;
} PMIC_OTP_0_R_UNION;
#endif
#define PMIC_OTP_0_R_np_otp_pdob0_d2a_START (0)
#define PMIC_OTP_0_R_np_otp_pdob0_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob1_d2a : 8;
    } reg;
} PMIC_OTP_1_R_UNION;
#endif
#define PMIC_OTP_1_R_np_otp_pdob1_d2a_START (0)
#define PMIC_OTP_1_R_np_otp_pdob1_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob2_d2a : 8;
    } reg;
} PMIC_OTP_2_R_UNION;
#endif
#define PMIC_OTP_2_R_np_otp_pdob2_d2a_START (0)
#define PMIC_OTP_2_R_np_otp_pdob2_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob3_d2a : 8;
    } reg;
} PMIC_OTP_3_R_UNION;
#endif
#define PMIC_OTP_3_R_np_otp_pdob3_d2a_START (0)
#define PMIC_OTP_3_R_np_otp_pdob3_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob4_d2a : 8;
    } reg;
} PMIC_OTP_4_R_UNION;
#endif
#define PMIC_OTP_4_R_np_otp_pdob4_d2a_START (0)
#define PMIC_OTP_4_R_np_otp_pdob4_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob5_d2a : 8;
    } reg;
} PMIC_OTP_5_R_UNION;
#endif
#define PMIC_OTP_5_R_np_otp_pdob5_d2a_START (0)
#define PMIC_OTP_5_R_np_otp_pdob5_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob6_d2a : 8;
    } reg;
} PMIC_OTP_6_R_UNION;
#endif
#define PMIC_OTP_6_R_np_otp_pdob6_d2a_START (0)
#define PMIC_OTP_6_R_np_otp_pdob6_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob7_d2a : 8;
    } reg;
} PMIC_OTP_7_R_UNION;
#endif
#define PMIC_OTP_7_R_np_otp_pdob7_d2a_START (0)
#define PMIC_OTP_7_R_np_otp_pdob7_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob8_d2a : 8;
    } reg;
} PMIC_OTP_8_R_UNION;
#endif
#define PMIC_OTP_8_R_np_otp_pdob8_d2a_START (0)
#define PMIC_OTP_8_R_np_otp_pdob8_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob9_d2a : 8;
    } reg;
} PMIC_OTP_9_R_UNION;
#endif
#define PMIC_OTP_9_R_np_otp_pdob9_d2a_START (0)
#define PMIC_OTP_9_R_np_otp_pdob9_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob10_d2a : 8;
    } reg;
} PMIC_OTP_10_R_UNION;
#endif
#define PMIC_OTP_10_R_np_otp_pdob10_d2a_START (0)
#define PMIC_OTP_10_R_np_otp_pdob10_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob11_d2a : 8;
    } reg;
} PMIC_OTP_11_R_UNION;
#endif
#define PMIC_OTP_11_R_np_otp_pdob11_d2a_START (0)
#define PMIC_OTP_11_R_np_otp_pdob11_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob12_d2a : 8;
    } reg;
} PMIC_OTP_12_R_UNION;
#endif
#define PMIC_OTP_12_R_np_otp_pdob12_d2a_START (0)
#define PMIC_OTP_12_R_np_otp_pdob12_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob13_d2a : 8;
    } reg;
} PMIC_OTP_13_R_UNION;
#endif
#define PMIC_OTP_13_R_np_otp_pdob13_d2a_START (0)
#define PMIC_OTP_13_R_np_otp_pdob13_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob14_d2a : 8;
    } reg;
} PMIC_OTP_14_R_UNION;
#endif
#define PMIC_OTP_14_R_np_otp_pdob14_d2a_START (0)
#define PMIC_OTP_14_R_np_otp_pdob14_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob15_d2a : 8;
    } reg;
} PMIC_OTP_15_R_UNION;
#endif
#define PMIC_OTP_15_R_np_otp_pdob15_d2a_START (0)
#define PMIC_OTP_15_R_np_otp_pdob15_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob16_d2a : 8;
    } reg;
} PMIC_OTP_16_R_UNION;
#endif
#define PMIC_OTP_16_R_np_otp_pdob16_d2a_START (0)
#define PMIC_OTP_16_R_np_otp_pdob16_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob17_d2a : 8;
    } reg;
} PMIC_OTP_17_R_UNION;
#endif
#define PMIC_OTP_17_R_np_otp_pdob17_d2a_START (0)
#define PMIC_OTP_17_R_np_otp_pdob17_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob18_d2a : 8;
    } reg;
} PMIC_OTP_18_R_UNION;
#endif
#define PMIC_OTP_18_R_np_otp_pdob18_d2a_START (0)
#define PMIC_OTP_18_R_np_otp_pdob18_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob19_d2a : 8;
    } reg;
} PMIC_OTP_19_R_UNION;
#endif
#define PMIC_OTP_19_R_np_otp_pdob19_d2a_START (0)
#define PMIC_OTP_19_R_np_otp_pdob19_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob20_d2a : 8;
    } reg;
} PMIC_OTP_20_R_UNION;
#endif
#define PMIC_OTP_20_R_np_otp_pdob20_d2a_START (0)
#define PMIC_OTP_20_R_np_otp_pdob20_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob21_d2a : 8;
    } reg;
} PMIC_OTP_21_R_UNION;
#endif
#define PMIC_OTP_21_R_np_otp_pdob21_d2a_START (0)
#define PMIC_OTP_21_R_np_otp_pdob21_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob22_d2a : 8;
    } reg;
} PMIC_OTP_22_R_UNION;
#endif
#define PMIC_OTP_22_R_np_otp_pdob22_d2a_START (0)
#define PMIC_OTP_22_R_np_otp_pdob22_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob23_d2a : 8;
    } reg;
} PMIC_OTP_23_R_UNION;
#endif
#define PMIC_OTP_23_R_np_otp_pdob23_d2a_START (0)
#define PMIC_OTP_23_R_np_otp_pdob23_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob24_d2a : 8;
    } reg;
} PMIC_OTP_24_R_UNION;
#endif
#define PMIC_OTP_24_R_np_otp_pdob24_d2a_START (0)
#define PMIC_OTP_24_R_np_otp_pdob24_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob25_d2a : 8;
    } reg;
} PMIC_OTP_25_R_UNION;
#endif
#define PMIC_OTP_25_R_np_otp_pdob25_d2a_START (0)
#define PMIC_OTP_25_R_np_otp_pdob25_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob26_d2a : 8;
    } reg;
} PMIC_OTP_26_R_UNION;
#endif
#define PMIC_OTP_26_R_np_otp_pdob26_d2a_START (0)
#define PMIC_OTP_26_R_np_otp_pdob26_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob27_d2a : 8;
    } reg;
} PMIC_OTP_27_R_UNION;
#endif
#define PMIC_OTP_27_R_np_otp_pdob27_d2a_START (0)
#define PMIC_OTP_27_R_np_otp_pdob27_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob28_d2a : 8;
    } reg;
} PMIC_OTP_28_R_UNION;
#endif
#define PMIC_OTP_28_R_np_otp_pdob28_d2a_START (0)
#define PMIC_OTP_28_R_np_otp_pdob28_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob29_d2a : 8;
    } reg;
} PMIC_OTP_29_R_UNION;
#endif
#define PMIC_OTP_29_R_np_otp_pdob29_d2a_START (0)
#define PMIC_OTP_29_R_np_otp_pdob29_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob30_d2a : 8;
    } reg;
} PMIC_OTP_30_R_UNION;
#endif
#define PMIC_OTP_30_R_np_otp_pdob30_d2a_START (0)
#define PMIC_OTP_30_R_np_otp_pdob30_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob31_d2a : 8;
    } reg;
} PMIC_OTP_31_R_UNION;
#endif
#define PMIC_OTP_31_R_np_otp_pdob31_d2a_START (0)
#define PMIC_OTP_31_R_np_otp_pdob31_d2a_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob32 : 8;
    } reg;
} PMIC_OTP_32_R_UNION;
#endif
#define PMIC_OTP_32_R_np_otp_pdob32_START (0)
#define PMIC_OTP_32_R_np_otp_pdob32_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob33 : 8;
    } reg;
} PMIC_OTP_33_R_UNION;
#endif
#define PMIC_OTP_33_R_np_otp_pdob33_START (0)
#define PMIC_OTP_33_R_np_otp_pdob33_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob34 : 8;
    } reg;
} PMIC_OTP_34_R_UNION;
#endif
#define PMIC_OTP_34_R_np_otp_pdob34_START (0)
#define PMIC_OTP_34_R_np_otp_pdob34_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob35 : 8;
    } reg;
} PMIC_OTP_35_R_UNION;
#endif
#define PMIC_OTP_35_R_np_otp_pdob35_START (0)
#define PMIC_OTP_35_R_np_otp_pdob35_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob36 : 8;
    } reg;
} PMIC_OTP_36_R_UNION;
#endif
#define PMIC_OTP_36_R_np_otp_pdob36_START (0)
#define PMIC_OTP_36_R_np_otp_pdob36_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob37 : 8;
    } reg;
} PMIC_OTP_37_R_UNION;
#endif
#define PMIC_OTP_37_R_np_otp_pdob37_START (0)
#define PMIC_OTP_37_R_np_otp_pdob37_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob38 : 8;
    } reg;
} PMIC_OTP_38_R_UNION;
#endif
#define PMIC_OTP_38_R_np_otp_pdob38_START (0)
#define PMIC_OTP_38_R_np_otp_pdob38_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob39 : 8;
    } reg;
} PMIC_OTP_39_R_UNION;
#endif
#define PMIC_OTP_39_R_np_otp_pdob39_START (0)
#define PMIC_OTP_39_R_np_otp_pdob39_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob40 : 8;
    } reg;
} PMIC_OTP_40_R_UNION;
#endif
#define PMIC_OTP_40_R_np_otp_pdob40_START (0)
#define PMIC_OTP_40_R_np_otp_pdob40_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob41 : 8;
    } reg;
} PMIC_OTP_41_R_UNION;
#endif
#define PMIC_OTP_41_R_np_otp_pdob41_START (0)
#define PMIC_OTP_41_R_np_otp_pdob41_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob42 : 8;
    } reg;
} PMIC_OTP_42_R_UNION;
#endif
#define PMIC_OTP_42_R_np_otp_pdob42_START (0)
#define PMIC_OTP_42_R_np_otp_pdob42_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob43 : 8;
    } reg;
} PMIC_OTP_43_R_UNION;
#endif
#define PMIC_OTP_43_R_np_otp_pdob43_START (0)
#define PMIC_OTP_43_R_np_otp_pdob43_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob44 : 8;
    } reg;
} PMIC_OTP_44_R_UNION;
#endif
#define PMIC_OTP_44_R_np_otp_pdob44_START (0)
#define PMIC_OTP_44_R_np_otp_pdob44_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob45 : 8;
    } reg;
} PMIC_OTP_45_R_UNION;
#endif
#define PMIC_OTP_45_R_np_otp_pdob45_START (0)
#define PMIC_OTP_45_R_np_otp_pdob45_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob46 : 8;
    } reg;
} PMIC_OTP_46_R_UNION;
#endif
#define PMIC_OTP_46_R_np_otp_pdob46_START (0)
#define PMIC_OTP_46_R_np_otp_pdob46_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob47 : 8;
    } reg;
} PMIC_OTP_47_R_UNION;
#endif
#define PMIC_OTP_47_R_np_otp_pdob47_START (0)
#define PMIC_OTP_47_R_np_otp_pdob47_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob48 : 8;
    } reg;
} PMIC_OTP_48_R_UNION;
#endif
#define PMIC_OTP_48_R_np_otp_pdob48_START (0)
#define PMIC_OTP_48_R_np_otp_pdob48_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob49 : 8;
    } reg;
} PMIC_OTP_49_R_UNION;
#endif
#define PMIC_OTP_49_R_np_otp_pdob49_START (0)
#define PMIC_OTP_49_R_np_otp_pdob49_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob50 : 8;
    } reg;
} PMIC_OTP_50_R_UNION;
#endif
#define PMIC_OTP_50_R_np_otp_pdob50_START (0)
#define PMIC_OTP_50_R_np_otp_pdob50_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob51 : 8;
    } reg;
} PMIC_OTP_51_R_UNION;
#endif
#define PMIC_OTP_51_R_np_otp_pdob51_START (0)
#define PMIC_OTP_51_R_np_otp_pdob51_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob52 : 8;
    } reg;
} PMIC_OTP_52_R_UNION;
#endif
#define PMIC_OTP_52_R_np_otp_pdob52_START (0)
#define PMIC_OTP_52_R_np_otp_pdob52_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob53 : 8;
    } reg;
} PMIC_OTP_53_R_UNION;
#endif
#define PMIC_OTP_53_R_np_otp_pdob53_START (0)
#define PMIC_OTP_53_R_np_otp_pdob53_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob54 : 8;
    } reg;
} PMIC_OTP_54_R_UNION;
#endif
#define PMIC_OTP_54_R_np_otp_pdob54_START (0)
#define PMIC_OTP_54_R_np_otp_pdob54_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob55 : 8;
    } reg;
} PMIC_OTP_55_R_UNION;
#endif
#define PMIC_OTP_55_R_np_otp_pdob55_START (0)
#define PMIC_OTP_55_R_np_otp_pdob55_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob56 : 8;
    } reg;
} PMIC_OTP_56_R_UNION;
#endif
#define PMIC_OTP_56_R_np_otp_pdob56_START (0)
#define PMIC_OTP_56_R_np_otp_pdob56_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob57 : 8;
    } reg;
} PMIC_OTP_57_R_UNION;
#endif
#define PMIC_OTP_57_R_np_otp_pdob57_START (0)
#define PMIC_OTP_57_R_np_otp_pdob57_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob58 : 8;
    } reg;
} PMIC_OTP_58_R_UNION;
#endif
#define PMIC_OTP_58_R_np_otp_pdob58_START (0)
#define PMIC_OTP_58_R_np_otp_pdob58_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob59 : 8;
    } reg;
} PMIC_OTP_59_R_UNION;
#endif
#define PMIC_OTP_59_R_np_otp_pdob59_START (0)
#define PMIC_OTP_59_R_np_otp_pdob59_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob60 : 8;
    } reg;
} PMIC_OTP_60_R_UNION;
#endif
#define PMIC_OTP_60_R_np_otp_pdob60_START (0)
#define PMIC_OTP_60_R_np_otp_pdob60_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob61 : 8;
    } reg;
} PMIC_OTP_61_R_UNION;
#endif
#define PMIC_OTP_61_R_np_otp_pdob61_START (0)
#define PMIC_OTP_61_R_np_otp_pdob61_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob62 : 8;
    } reg;
} PMIC_OTP_62_R_UNION;
#endif
#define PMIC_OTP_62_R_np_otp_pdob62_START (0)
#define PMIC_OTP_62_R_np_otp_pdob62_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_otp_pdob63 : 8;
    } reg;
} PMIC_OTP_63_R_UNION;
#endif
#define PMIC_OTP_63_R_np_otp_pdob63_START (0)
#define PMIC_OTP_63_R_np_otp_pdob63_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char np_d2a_reserve2 : 8;
    } reg;
} PMIC_NP_D2A_RES2_UNION;
#endif
#define PMIC_NP_D2A_RES2_np_d2a_reserve2_START (0)
#define PMIC_NP_D2A_RES2_np_d2a_reserve2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char pwrup_cali_end : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_PWRUP_CALI_END_UNION;
#endif
#define PMIC_PWRUP_CALI_END_pwrup_cali_end_START (0)
#define PMIC_PWRUP_CALI_END_pwrup_cali_end_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xo_autocali_ave0_l : 8;
    } reg;
} PMIC_XOADC_AUTOCALI_AVE0_UNION;
#endif
#define PMIC_XOADC_AUTOCALI_AVE0_xo_autocali_ave0_l_START (0)
#define PMIC_XOADC_AUTOCALI_AVE0_xo_autocali_ave0_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xo_autocali_ave0_h : 8;
    } reg;
} PMIC_XOADC_AUTOCALI_AVE1_UNION;
#endif
#define PMIC_XOADC_AUTOCALI_AVE1_xo_autocali_ave0_h_START (0)
#define PMIC_XOADC_AUTOCALI_AVE1_xo_autocali_ave0_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xo_autocali_ave1_l : 8;
    } reg;
} PMIC_XOADC_AUTOCALI_AVE2_UNION;
#endif
#define PMIC_XOADC_AUTOCALI_AVE2_xo_autocali_ave1_l_START (0)
#define PMIC_XOADC_AUTOCALI_AVE2_xo_autocali_ave1_l_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xo_autocali_ave1_h : 8;
    } reg;
} PMIC_XOADC_AUTOCALI_AVE3_UNION;
#endif
#define PMIC_XOADC_AUTOCALI_AVE3_xo_autocali_ave1_h_START (0)
#define PMIC_XOADC_AUTOCALI_AVE3_xo_autocali_ave1_h_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xoadc_data_rate_sel : 3;
        unsigned char xoadc_sdm_clk_sel : 1;
        unsigned char xo_chop_fre_sel : 2;
        unsigned char xo_chop_en : 1;
        unsigned char reserved : 1;
    } reg;
} PMIC_XOADC_CTRL_UNION;
#endif
#define PMIC_XOADC_CTRL_xoadc_data_rate_sel_START (0)
#define PMIC_XOADC_CTRL_xoadc_data_rate_sel_END (2)
#define PMIC_XOADC_CTRL_xoadc_sdm_clk_sel_START (3)
#define PMIC_XOADC_CTRL_xoadc_sdm_clk_sel_END (3)
#define PMIC_XOADC_CTRL_xo_chop_fre_sel_START (4)
#define PMIC_XOADC_CTRL_xo_chop_fre_sel_END (5)
#define PMIC_XOADC_CTRL_xo_chop_en_START (6)
#define PMIC_XOADC_CTRL_xo_chop_en_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xoadc_samp_phase_sel : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_XOADC_SAMP_PHASE_UNION;
#endif
#define PMIC_XOADC_SAMP_PHASE_xoadc_samp_phase_sel_START (0)
#define PMIC_XOADC_SAMP_PHASE_xoadc_samp_phase_sel_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xoadc_opt_0 : 8;
    } reg;
} PMIC_XOADC_OPT_0_UNION;
#endif
#define PMIC_XOADC_OPT_0_xoadc_opt_0_START (0)
#define PMIC_XOADC_OPT_0_xoadc_opt_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xoadc_opt_1 : 6;
        unsigned char reserved : 2;
    } reg;
} PMIC_XOADC_OPT_1_UNION;
#endif
#define PMIC_XOADC_OPT_1_xoadc_opt_1_START (0)
#define PMIC_XOADC_OPT_1_xoadc_opt_1_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xoadc_ain_sel : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_XOADC_AIN_SEL_UNION;
#endif
#define PMIC_XOADC_AIN_SEL_xoadc_ain_sel_START (0)
#define PMIC_XOADC_AIN_SEL_xoadc_ain_sel_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char wifi_xoadc_ana_en : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_XOADC_WIFI_ANA_EN_UNION;
#endif
#define PMIC_XOADC_WIFI_ANA_EN_wifi_xoadc_ana_en_START (0)
#define PMIC_XOADC_WIFI_ANA_EN_wifi_xoadc_ana_en_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char soc_initial : 1;
        unsigned char soc_xoadc_ana_en : 1;
        unsigned char reserved : 6;
    } reg;
} PMIC_XOADC_SOC_ANA_EN_UNION;
#endif
#define PMIC_XOADC_SOC_ANA_EN_soc_initial_START (0)
#define PMIC_XOADC_SOC_ANA_EN_soc_initial_END (0)
#define PMIC_XOADC_SOC_ANA_EN_soc_xoadc_ana_en_START (1)
#define PMIC_XOADC_SOC_ANA_EN_soc_xoadc_ana_en_END (1)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char data_valid : 1;
        unsigned char soc_initial_ro : 1;
        unsigned char soc_xoadc_ana_en_ro : 1;
        unsigned char wifi_xoadc_ana_en_ro : 1;
        unsigned char soc_xo_cfg_en_ro : 2;
        unsigned char wifi_xo_cfg_en_ro : 2;
    } reg;
} PMIC_XOADC_STATE_UNION;
#endif
#define PMIC_XOADC_STATE_data_valid_START (0)
#define PMIC_XOADC_STATE_data_valid_END (0)
#define PMIC_XOADC_STATE_soc_initial_ro_START (1)
#define PMIC_XOADC_STATE_soc_initial_ro_END (1)
#define PMIC_XOADC_STATE_soc_xoadc_ana_en_ro_START (2)
#define PMIC_XOADC_STATE_soc_xoadc_ana_en_ro_END (2)
#define PMIC_XOADC_STATE_wifi_xoadc_ana_en_ro_START (3)
#define PMIC_XOADC_STATE_wifi_xoadc_ana_en_ro_END (3)
#define PMIC_XOADC_STATE_soc_xo_cfg_en_ro_START (4)
#define PMIC_XOADC_STATE_soc_xo_cfg_en_ro_END (5)
#define PMIC_XOADC_STATE_wifi_xo_cfg_en_ro_START (6)
#define PMIC_XOADC_STATE_wifi_xo_cfg_en_ro_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xo_data_0 : 8;
    } reg;
} PMIC_XOADC_DATA0_UNION;
#endif
#define PMIC_XOADC_DATA0_xo_data_0_START (0)
#define PMIC_XOADC_DATA0_xo_data_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xo_data_1 : 8;
    } reg;
} PMIC_XOADC_DATA1_UNION;
#endif
#define PMIC_XOADC_DATA1_xo_data_1_START (0)
#define PMIC_XOADC_DATA1_xo_data_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xo_cali_data_0 : 8;
    } reg;
} PMIC_XOADC_CALI_DATA0_UNION;
#endif
#define PMIC_XOADC_CALI_DATA0_xo_cali_data_0_START (0)
#define PMIC_XOADC_CALI_DATA0_xo_cali_data_0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xo_cali_data_1 : 8;
    } reg;
} PMIC_XOADC_CALI_DATA1_UNION;
#endif
#define PMIC_XOADC_CALI_DATA1_xo_cali_data_1_START (0)
#define PMIC_XOADC_CALI_DATA1_xo_cali_data_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char soc_xo_cfg_en : 2;
        unsigned char wifi_xo_cfg_en : 2;
        unsigned char reserved : 4;
    } reg;
} PMIC_XOADC_CFG_EN_UNION;
#endif
#define PMIC_XOADC_CFG_EN_soc_xo_cfg_en_START (0)
#define PMIC_XOADC_CFG_EN_soc_xo_cfg_en_END (1)
#define PMIC_XOADC_CFG_EN_wifi_xo_cfg_en_START (2)
#define PMIC_XOADC_CFG_EN_wifi_xo_cfg_en_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char abnm_cfg : 2;
        unsigned char data_valid_ori : 1;
        unsigned char abnm_info : 1;
        unsigned char reserved : 4;
    } reg;
} PMIC_XOADC_ARB_DEBUG_UNION;
#endif
#define PMIC_XOADC_ARB_DEBUG_abnm_cfg_START (0)
#define PMIC_XOADC_ARB_DEBUG_abnm_cfg_END (1)
#define PMIC_XOADC_ARB_DEBUG_data_valid_ori_START (2)
#define PMIC_XOADC_ARB_DEBUG_data_valid_ori_END (2)
#define PMIC_XOADC_ARB_DEBUG_abnm_info_START (3)
#define PMIC_XOADC_ARB_DEBUG_abnm_info_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xoadc_data_rate_sel_s : 3;
        unsigned char xoadc_sdm_clk_sel_s : 1;
        unsigned char xo_chop_fre_sel_s : 2;
        unsigned char xo_chop_en_s : 1;
        unsigned char reserved : 1;
    } reg;
} PMIC_XOADC_CTRL_S_UNION;
#endif
#define PMIC_XOADC_CTRL_S_xoadc_data_rate_sel_s_START (0)
#define PMIC_XOADC_CTRL_S_xoadc_data_rate_sel_s_END (2)
#define PMIC_XOADC_CTRL_S_xoadc_sdm_clk_sel_s_START (3)
#define PMIC_XOADC_CTRL_S_xoadc_sdm_clk_sel_s_END (3)
#define PMIC_XOADC_CTRL_S_xo_chop_fre_sel_s_START (4)
#define PMIC_XOADC_CTRL_S_xo_chop_fre_sel_s_END (5)
#define PMIC_XOADC_CTRL_S_xo_chop_en_s_START (6)
#define PMIC_XOADC_CTRL_S_xo_chop_en_s_END (6)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xoadc_samp_phase_sel_s : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_XOADC_SAMP_PHASE_S_UNION;
#endif
#define PMIC_XOADC_SAMP_PHASE_S_xoadc_samp_phase_sel_s_START (0)
#define PMIC_XOADC_SAMP_PHASE_S_xoadc_samp_phase_sel_s_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xoadc_opt_0_s : 8;
    } reg;
} PMIC_XOADC_OPT_0_S_UNION;
#endif
#define PMIC_XOADC_OPT_0_S_xoadc_opt_0_s_START (0)
#define PMIC_XOADC_OPT_0_S_xoadc_opt_0_s_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xoadc_opt_1_s : 6;
        unsigned char reserved : 2;
    } reg;
} PMIC_XOADC_OPT_1_S_UNION;
#endif
#define PMIC_XOADC_OPT_1_S_xoadc_opt_1_s_START (0)
#define PMIC_XOADC_OPT_1_S_xoadc_opt_1_s_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xoadc_ain_sel_s : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_XOADC_AIN_SEL_S_UNION;
#endif
#define PMIC_XOADC_AIN_SEL_S_xoadc_ain_sel_s_START (0)
#define PMIC_XOADC_AIN_SEL_S_xoadc_ain_sel_s_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xoadc_ana_en_s : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_XOADC_ANA_EN_S_UNION;
#endif
#define PMIC_XOADC_ANA_EN_S_xoadc_ana_en_s_START (0)
#define PMIC_XOADC_ANA_EN_S_xoadc_ana_en_s_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char soft_cfg0 : 8;
    } reg;
} PMIC_XOADC_SOFT_CFG0_UNION;
#endif
#define PMIC_XOADC_SOFT_CFG0_soft_cfg0_START (0)
#define PMIC_XOADC_SOFT_CFG0_soft_cfg0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char soft_cfg1 : 8;
    } reg;
} PMIC_XOADC_SOFT_CFG1_UNION;
#endif
#define PMIC_XOADC_SOFT_CFG1_soft_cfg1_START (0)
#define PMIC_XOADC_SOFT_CFG1_soft_cfg1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char soft_cfg2 : 8;
    } reg;
} PMIC_XOADC_SOFT_CFG2_UNION;
#endif
#define PMIC_XOADC_SOFT_CFG2_soft_cfg2_START (0)
#define PMIC_XOADC_SOFT_CFG2_soft_cfg2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char soft_cfg3 : 8;
    } reg;
} PMIC_XOADC_SOFT_CFG3_UNION;
#endif
#define PMIC_XOADC_SOFT_CFG3_soft_cfg3_START (0)
#define PMIC_XOADC_SOFT_CFG3_soft_cfg3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char soft_cfg4 : 8;
    } reg;
} PMIC_XOADC_SOFT_CFG4_UNION;
#endif
#define PMIC_XOADC_SOFT_CFG4_soft_cfg4_START (0)
#define PMIC_XOADC_SOFT_CFG4_soft_cfg4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char soft_cfg5 : 8;
    } reg;
} PMIC_XOADC_SOFT_CFG5_UNION;
#endif
#define PMIC_XOADC_SOFT_CFG5_soft_cfg5_START (0)
#define PMIC_XOADC_SOFT_CFG5_soft_cfg5_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char soft_cfg6 : 8;
    } reg;
} PMIC_XOADC_SOFT_CFG6_UNION;
#endif
#define PMIC_XOADC_SOFT_CFG6_soft_cfg6_START (0)
#define PMIC_XOADC_SOFT_CFG6_soft_cfg6_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char soft_cfg7 : 8;
    } reg;
} PMIC_XOADC_SOFT_CFG7_UNION;
#endif
#define PMIC_XOADC_SOFT_CFG7_soft_cfg7_START (0)
#define PMIC_XOADC_SOFT_CFG7_soft_cfg7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char xoadc_reserve : 8;
    } reg;
} PMIC_XOADC_RESERVE_UNION;
#endif
#define PMIC_XOADC_RESERVE_xoadc_reserve_START (0)
#define PMIC_XOADC_RESERVE_xoadc_reserve_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug0 : 8;
    } reg;
} PMIC_SPMI_DEBUG0_UNION;
#endif
#define PMIC_SPMI_DEBUG0_spmi_debug0_START (0)
#define PMIC_SPMI_DEBUG0_spmi_debug0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug1 : 8;
    } reg;
} PMIC_SPMI_DEBUG1_UNION;
#endif
#define PMIC_SPMI_DEBUG1_spmi_debug1_START (0)
#define PMIC_SPMI_DEBUG1_spmi_debug1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug2 : 8;
    } reg;
} PMIC_SPMI_DEBUG2_UNION;
#endif
#define PMIC_SPMI_DEBUG2_spmi_debug2_START (0)
#define PMIC_SPMI_DEBUG2_spmi_debug2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug3 : 8;
    } reg;
} PMIC_SPMI_DEBUG3_UNION;
#endif
#define PMIC_SPMI_DEBUG3_spmi_debug3_START (0)
#define PMIC_SPMI_DEBUG3_spmi_debug3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug4 : 8;
    } reg;
} PMIC_SPMI_DEBUG4_UNION;
#endif
#define PMIC_SPMI_DEBUG4_spmi_debug4_START (0)
#define PMIC_SPMI_DEBUG4_spmi_debug4_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug5 : 8;
    } reg;
} PMIC_SPMI_DEBUG5_UNION;
#endif
#define PMIC_SPMI_DEBUG5_spmi_debug5_START (0)
#define PMIC_SPMI_DEBUG5_spmi_debug5_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug6 : 8;
    } reg;
} PMIC_SPMI_DEBUG6_UNION;
#endif
#define PMIC_SPMI_DEBUG6_spmi_debug6_START (0)
#define PMIC_SPMI_DEBUG6_spmi_debug6_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char spmi_debug7 : 8;
    } reg;
} PMIC_SPMI_DEBUG7_UNION;
#endif
#define PMIC_SPMI_DEBUG7_spmi_debug7_START (0)
#define PMIC_SPMI_DEBUG7_spmi_debug7_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtcdr0 : 8;
    } reg;
} PMIC_RTCDR0_UNION;
#endif
#define PMIC_RTCDR0_rtcdr0_START (0)
#define PMIC_RTCDR0_rtcdr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtcdr1 : 8;
    } reg;
} PMIC_RTCDR1_UNION;
#endif
#define PMIC_RTCDR1_rtcdr1_START (0)
#define PMIC_RTCDR1_rtcdr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtcdr2 : 8;
    } reg;
} PMIC_RTCDR2_UNION;
#endif
#define PMIC_RTCDR2_rtcdr2_START (0)
#define PMIC_RTCDR2_rtcdr2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtcdr3 : 8;
    } reg;
} PMIC_RTCDR3_UNION;
#endif
#define PMIC_RTCDR3_rtcdr3_START (0)
#define PMIC_RTCDR3_rtcdr3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtcmr0 : 8;
    } reg;
} PMIC_RTCMR0_UNION;
#endif
#define PMIC_RTCMR0_rtcmr0_START (0)
#define PMIC_RTCMR0_rtcmr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtcmr1 : 8;
    } reg;
} PMIC_RTCMR1_UNION;
#endif
#define PMIC_RTCMR1_rtcmr1_START (0)
#define PMIC_RTCMR1_rtcmr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtcmr2 : 8;
    } reg;
} PMIC_RTCMR2_UNION;
#endif
#define PMIC_RTCMR2_rtcmr2_START (0)
#define PMIC_RTCMR2_rtcmr2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtcmr3 : 8;
    } reg;
} PMIC_RTCMR3_UNION;
#endif
#define PMIC_RTCMR3_rtcmr3_START (0)
#define PMIC_RTCMR3_rtcmr3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtcclr0 : 8;
    } reg;
} PMIC_RTCLR0_UNION;
#endif
#define PMIC_RTCLR0_rtcclr0_START (0)
#define PMIC_RTCLR0_rtcclr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtcclr1 : 8;
    } reg;
} PMIC_RTCLR1_UNION;
#endif
#define PMIC_RTCLR1_rtcclr1_START (0)
#define PMIC_RTCLR1_rtcclr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtcclr2 : 8;
    } reg;
} PMIC_RTCLR2_UNION;
#endif
#define PMIC_RTCLR2_rtcclr2_START (0)
#define PMIC_RTCLR2_rtcclr2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtcclr3 : 8;
    } reg;
} PMIC_RTCLR3_UNION;
#endif
#define PMIC_RTCLR3_rtcclr3_START (0)
#define PMIC_RTCLR3_rtcclr3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtccr : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_RTCCTRL_UNION;
#endif
#define PMIC_RTCCTRL_rtccr_START (0)
#define PMIC_RTCCTRL_rtccr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char crc_value0 : 8;
    } reg;
} PMIC_CRC_VAULE0_UNION;
#endif
#define PMIC_CRC_VAULE0_crc_value0_START (0)
#define PMIC_CRC_VAULE0_crc_value0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char crc_value1 : 8;
    } reg;
} PMIC_CRC_VAULE1_UNION;
#endif
#define PMIC_CRC_VAULE1_crc_value1_START (0)
#define PMIC_CRC_VAULE1_crc_value1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char crc_value2 : 5;
        unsigned char reserved : 3;
    } reg;
} PMIC_CRC_VAULE2_UNION;
#endif
#define PMIC_CRC_VAULE2_crc_value2_START (0)
#define PMIC_CRC_VAULE2_crc_value2_END (4)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtc_pwrup_timer0 : 8;
    } reg;
} PMIC_RTC_PWRUP_TIMER0_UNION;
#endif
#define PMIC_RTC_PWRUP_TIMER0_rtc_pwrup_timer0_START (0)
#define PMIC_RTC_PWRUP_TIMER0_rtc_pwrup_timer0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtc_pwrup_timer1 : 8;
    } reg;
} PMIC_RTC_PWRUP_TIMER1_UNION;
#endif
#define PMIC_RTC_PWRUP_TIMER1_rtc_pwrup_timer1_START (0)
#define PMIC_RTC_PWRUP_TIMER1_rtc_pwrup_timer1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtc_pwrup_timer2 : 8;
    } reg;
} PMIC_RTC_PWRUP_TIMER2_UNION;
#endif
#define PMIC_RTC_PWRUP_TIMER2_rtc_pwrup_timer2_START (0)
#define PMIC_RTC_PWRUP_TIMER2_rtc_pwrup_timer2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtc_pwrup_timer3 : 8;
    } reg;
} PMIC_RTC_PWRUP_TIMER3_UNION;
#endif
#define PMIC_RTC_PWRUP_TIMER3_rtc_pwrup_timer3_START (0)
#define PMIC_RTC_PWRUP_TIMER3_rtc_pwrup_timer3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtc_pwrdown_timer0 : 8;
    } reg;
} PMIC_RTC_PWRDOWN_TIMER0_UNION;
#endif
#define PMIC_RTC_PWRDOWN_TIMER0_rtc_pwrdown_timer0_START (0)
#define PMIC_RTC_PWRDOWN_TIMER0_rtc_pwrdown_timer0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtc_pwrdown_timer1 : 8;
    } reg;
} PMIC_RTC_PWRDOWN_TIMER1_UNION;
#endif
#define PMIC_RTC_PWRDOWN_TIMER1_rtc_pwrdown_timer1_START (0)
#define PMIC_RTC_PWRDOWN_TIMER1_rtc_pwrdown_timer1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtc_pwrdown_timer2 : 8;
    } reg;
} PMIC_RTC_PWRDOWN_TIMER2_UNION;
#endif
#define PMIC_RTC_PWRDOWN_TIMER2_rtc_pwrdown_timer2_START (0)
#define PMIC_RTC_PWRDOWN_TIMER2_rtc_pwrdown_timer2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char rtc_pwrdown_timer3 : 8;
    } reg;
} PMIC_RTC_PWRDOWN_TIMER3_UNION;
#endif
#define PMIC_RTC_PWRDOWN_TIMER3_rtc_pwrdown_timer3_START (0)
#define PMIC_RTC_PWRDOWN_TIMER3_rtc_pwrdown_timer3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_rtcdr0 : 8;
    } reg;
} PMIC_SER_RTCDR0_UNION;
#endif
#define PMIC_SER_RTCDR0_ser_rtcdr0_START (0)
#define PMIC_SER_RTCDR0_ser_rtcdr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_rtcdr1 : 8;
    } reg;
} PMIC_SER_RTCDR1_UNION;
#endif
#define PMIC_SER_RTCDR1_ser_rtcdr1_START (0)
#define PMIC_SER_RTCDR1_ser_rtcdr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_rtcdr2 : 8;
    } reg;
} PMIC_SER_RTCDR2_UNION;
#endif
#define PMIC_SER_RTCDR2_ser_rtcdr2_START (0)
#define PMIC_SER_RTCDR2_ser_rtcdr2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_rtcdr3 : 8;
    } reg;
} PMIC_SER_RTCDR3_UNION;
#endif
#define PMIC_SER_RTCDR3_ser_rtcdr3_START (0)
#define PMIC_SER_RTCDR3_ser_rtcdr3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_rtcmr0 : 8;
    } reg;
} PMIC_SER_RTCMR0_UNION;
#endif
#define PMIC_SER_RTCMR0_ser_rtcmr0_START (0)
#define PMIC_SER_RTCMR0_ser_rtcmr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_rtcmr1 : 8;
    } reg;
} PMIC_SER_RTCMR1_UNION;
#endif
#define PMIC_SER_RTCMR1_ser_rtcmr1_START (0)
#define PMIC_SER_RTCMR1_ser_rtcmr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_rtcmr2 : 8;
    } reg;
} PMIC_SER_RTCMR2_UNION;
#endif
#define PMIC_SER_RTCMR2_ser_rtcmr2_START (0)
#define PMIC_SER_RTCMR2_ser_rtcmr2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_rtcmr3 : 8;
    } reg;
} PMIC_SER_RTCMR3_UNION;
#endif
#define PMIC_SER_RTCMR3_ser_rtcmr3_START (0)
#define PMIC_SER_RTCMR3_ser_rtcmr3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_rtcclr0 : 8;
    } reg;
} PMIC_SER_RTCLR0_UNION;
#endif
#define PMIC_SER_RTCLR0_ser_rtcclr0_START (0)
#define PMIC_SER_RTCLR0_ser_rtcclr0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_rtcclr1 : 8;
    } reg;
} PMIC_SER_RTCLR1_UNION;
#endif
#define PMIC_SER_RTCLR1_ser_rtcclr1_START (0)
#define PMIC_SER_RTCLR1_ser_rtcclr1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_rtcclr2 : 8;
    } reg;
} PMIC_SER_RTCLR2_UNION;
#endif
#define PMIC_SER_RTCLR2_ser_rtcclr2_START (0)
#define PMIC_SER_RTCLR2_ser_rtcclr2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_rtcclr3 : 8;
    } reg;
} PMIC_SER_RTCLR3_UNION;
#endif
#define PMIC_SER_RTCLR3_ser_rtcclr3_START (0)
#define PMIC_SER_RTCLR3_ser_rtcclr3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_rtccr : 1;
        unsigned char reserved : 7;
    } reg;
} PMIC_SER_RTCCTRL_UNION;
#endif
#define PMIC_SER_RTCCTRL_ser_rtccr_START (0)
#define PMIC_SER_RTCCTRL_ser_rtccr_END (0)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_xo_cali_thresold_low : 8;
    } reg;
} PMIC_SER_XO_THRESOLD0_UNION;
#endif
#define PMIC_SER_XO_THRESOLD0_ser_xo_cali_thresold_low_START (0)
#define PMIC_SER_XO_THRESOLD0_ser_xo_cali_thresold_low_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_xo_cali_thresold1_high : 8;
    } reg;
} PMIC_SER_XO_THRESOLD1_UNION;
#endif
#define PMIC_SER_XO_THRESOLD1_ser_xo_cali_thresold1_high_START (0)
#define PMIC_SER_XO_THRESOLD1_ser_xo_cali_thresold1_high_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_crc_value0 : 8;
    } reg;
} PMIC_SER_CRC_VAULE0_UNION;
#endif
#define PMIC_SER_CRC_VAULE0_ser_crc_value0_START (0)
#define PMIC_SER_CRC_VAULE0_ser_crc_value0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_crc_value1 : 8;
    } reg;
} PMIC_SER_CRC_VAULE1_UNION;
#endif
#define PMIC_SER_CRC_VAULE1_ser_crc_value1_START (0)
#define PMIC_SER_CRC_VAULE1_ser_crc_value1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_crc_value2 : 5;
        unsigned char ser_reserved : 3;
    } reg;
} PMIC_SER_CRC_VAULE2_UNION;
#endif
#define PMIC_SER_CRC_VAULE2_ser_crc_value2_START (0)
#define PMIC_SER_CRC_VAULE2_ser_crc_value2_END (4)
#define PMIC_SER_CRC_VAULE2_ser_reserved_START (5)
#define PMIC_SER_CRC_VAULE2_ser_reserved_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_rtc_pwrup_timer0 : 8;
    } reg;
} PMIC_SER_RTC_PWRUP_TIMER0_UNION;
#endif
#define PMIC_SER_RTC_PWRUP_TIMER0_ser_rtc_pwrup_timer0_START (0)
#define PMIC_SER_RTC_PWRUP_TIMER0_ser_rtc_pwrup_timer0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_rtc_pwrup_timer1 : 8;
    } reg;
} PMIC_SER_RTC_PWRUP_TIMER1_UNION;
#endif
#define PMIC_SER_RTC_PWRUP_TIMER1_ser_rtc_pwrup_timer1_START (0)
#define PMIC_SER_RTC_PWRUP_TIMER1_ser_rtc_pwrup_timer1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_rtc_pwrup_timer2 : 8;
    } reg;
} PMIC_SER_RTC_PWRUP_TIMER2_UNION;
#endif
#define PMIC_SER_RTC_PWRUP_TIMER2_ser_rtc_pwrup_timer2_START (0)
#define PMIC_SER_RTC_PWRUP_TIMER2_ser_rtc_pwrup_timer2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_rtc_pwrup_timer3 : 8;
    } reg;
} PMIC_SER_RTC_PWRUP_TIMER3_UNION;
#endif
#define PMIC_SER_RTC_PWRUP_TIMER3_ser_rtc_pwrup_timer3_START (0)
#define PMIC_SER_RTC_PWRUP_TIMER3_ser_rtc_pwrup_timer3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_rtc_pwrdown_timer0 : 8;
    } reg;
} PMIC_SER_RTC_PWRDOWN_TIMER0_UNION;
#endif
#define PMIC_SER_RTC_PWRDOWN_TIMER0_ser_rtc_pwrdown_timer0_START (0)
#define PMIC_SER_RTC_PWRDOWN_TIMER0_ser_rtc_pwrdown_timer0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_rtc_pwrdown_timer1 : 8;
    } reg;
} PMIC_SER_RTC_PWRDOWN_TIMER1_UNION;
#endif
#define PMIC_SER_RTC_PWRDOWN_TIMER1_ser_rtc_pwrdown_timer1_START (0)
#define PMIC_SER_RTC_PWRDOWN_TIMER1_ser_rtc_pwrdown_timer1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_rtc_pwrdown_timer2 : 8;
    } reg;
} PMIC_SER_RTC_PWRDOWN_TIMER2_UNION;
#endif
#define PMIC_SER_RTC_PWRDOWN_TIMER2_ser_rtc_pwrdown_timer2_START (0)
#define PMIC_SER_RTC_PWRDOWN_TIMER2_ser_rtc_pwrdown_timer2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char ser_rtc_pwrdown_timer3 : 8;
    } reg;
} PMIC_SER_RTC_PWRDOWN_TIMER3_UNION;
#endif
#define PMIC_SER_RTC_PWRDOWN_TIMER3_ser_rtc_pwrdown_timer3_START (0)
#define PMIC_SER_RTC_PWRDOWN_TIMER3_ser_rtc_pwrdown_timer3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cl_gate_int : 1;
        unsigned char cl_out_int : 1;
        unsigned char cl_in_int : 1;
        unsigned char v_gate_int : 1;
        unsigned char reserved : 4;
    } reg;
} PMIC_COUL_IRQ_UNION;
#endif
#define PMIC_COUL_IRQ_cl_gate_int_START (0)
#define PMIC_COUL_IRQ_cl_gate_int_END (0)
#define PMIC_COUL_IRQ_cl_out_int_START (1)
#define PMIC_COUL_IRQ_cl_out_int_END (1)
#define PMIC_COUL_IRQ_cl_in_int_START (2)
#define PMIC_COUL_IRQ_cl_in_int_END (2)
#define PMIC_COUL_IRQ_v_gate_int_START (3)
#define PMIC_COUL_IRQ_v_gate_int_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cl_gate_int_mk : 1;
        unsigned char cl_out_int_mk : 1;
        unsigned char cl_in_int_mk : 1;
        unsigned char v_gate_int_mk : 1;
        unsigned char reserved : 4;
    } reg;
} PMIC_COUL_IRQ_MASK_UNION;
#endif
#define PMIC_COUL_IRQ_MASK_cl_gate_int_mk_START (0)
#define PMIC_COUL_IRQ_MASK_cl_gate_int_mk_END (0)
#define PMIC_COUL_IRQ_MASK_cl_out_int_mk_START (1)
#define PMIC_COUL_IRQ_MASK_cl_out_int_mk_END (1)
#define PMIC_COUL_IRQ_MASK_cl_in_int_mk_START (2)
#define PMIC_COUL_IRQ_MASK_cl_in_int_mk_END (2)
#define PMIC_COUL_IRQ_MASK_v_gate_int_mk_START (3)
#define PMIC_COUL_IRQ_MASK_v_gate_int_mk_END (3)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_s0 : 8;
    } reg;
} PMIC_CURRENT_0_UNION;
#endif
#define PMIC_CURRENT_0_current_s0_START (0)
#define PMIC_CURRENT_0_current_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_s1 : 8;
    } reg;
} PMIC_CURRENT_1_UNION;
#endif
#define PMIC_CURRENT_1_current_s1_START (0)
#define PMIC_CURRENT_1_current_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_s0 : 8;
    } reg;
} PMIC_V_OUT_0_UNION;
#endif
#define PMIC_V_OUT_0_v_out_s0_START (0)
#define PMIC_V_OUT_0_v_out_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_s1 : 8;
    } reg;
} PMIC_V_OUT_1_UNION;
#endif
#define PMIC_V_OUT_1_v_out_s1_START (0)
#define PMIC_V_OUT_1_v_out_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char eco_ctrl : 3;
        unsigned char reflash_value_ctrl : 1;
        unsigned char eco_filter_time : 3;
        unsigned char calibration_ctrl : 1;
    } reg;
} PMIC_CLJ_CTRL_REG_UNION;
#endif
#define PMIC_CLJ_CTRL_REG_eco_ctrl_START (0)
#define PMIC_CLJ_CTRL_REG_eco_ctrl_END (2)
#define PMIC_CLJ_CTRL_REG_reflash_value_ctrl_START (3)
#define PMIC_CLJ_CTRL_REG_reflash_value_ctrl_END (3)
#define PMIC_CLJ_CTRL_REG_eco_filter_time_START (4)
#define PMIC_CLJ_CTRL_REG_eco_filter_time_END (6)
#define PMIC_CLJ_CTRL_REG_calibration_ctrl_START (7)
#define PMIC_CLJ_CTRL_REG_calibration_ctrl_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char eco_reflash_time : 8;
    } reg;
} PMIC_ECO_REFALSH_TIME_UNION;
#endif
#define PMIC_ECO_REFALSH_TIME_eco_reflash_time_START (0)
#define PMIC_ECO_REFALSH_TIME_eco_reflash_time_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cl_out_s0 : 8;
    } reg;
} PMIC_CL_OUT0_UNION;
#endif
#define PMIC_CL_OUT0_cl_out_s0_START (0)
#define PMIC_CL_OUT0_cl_out_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cl_out_s1 : 8;
    } reg;
} PMIC_CL_OUT1_UNION;
#endif
#define PMIC_CL_OUT1_cl_out_s1_START (0)
#define PMIC_CL_OUT1_cl_out_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cl_out_s2 : 8;
    } reg;
} PMIC_CL_OUT2_UNION;
#endif
#define PMIC_CL_OUT2_cl_out_s2_START (0)
#define PMIC_CL_OUT2_cl_out_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cl_out_s3 : 8;
    } reg;
} PMIC_CL_OUT3_UNION;
#endif
#define PMIC_CL_OUT3_cl_out_s3_START (0)
#define PMIC_CL_OUT3_cl_out_s3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cl_in_s0 : 8;
    } reg;
} PMIC_CL_IN0_UNION;
#endif
#define PMIC_CL_IN0_cl_in_s0_START (0)
#define PMIC_CL_IN0_cl_in_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cl_in_s1 : 8;
    } reg;
} PMIC_CL_IN1_UNION;
#endif
#define PMIC_CL_IN1_cl_in_s1_START (0)
#define PMIC_CL_IN1_cl_in_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cl_in_s2 : 8;
    } reg;
} PMIC_CL_IN2_UNION;
#endif
#define PMIC_CL_IN2_cl_in_s2_START (0)
#define PMIC_CL_IN2_cl_in_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cl_in_s3 : 8;
    } reg;
} PMIC_CL_IN3_UNION;
#endif
#define PMIC_CL_IN3_cl_in_s3_START (0)
#define PMIC_CL_IN3_cl_in_s3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char chg_timer_s0 : 8;
    } reg;
} PMIC_CHG_TIMER0_UNION;
#endif
#define PMIC_CHG_TIMER0_chg_timer_s0_START (0)
#define PMIC_CHG_TIMER0_chg_timer_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char chg_timer_s1 : 8;
    } reg;
} PMIC_CHG_TIMER1_UNION;
#endif
#define PMIC_CHG_TIMER1_chg_timer_s1_START (0)
#define PMIC_CHG_TIMER1_chg_timer_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char chg_timer_s2 : 8;
    } reg;
} PMIC_CHG_TIMER2_UNION;
#endif
#define PMIC_CHG_TIMER2_chg_timer_s2_START (0)
#define PMIC_CHG_TIMER2_chg_timer_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char chg_timer_s3 : 8;
    } reg;
} PMIC_CHG_TIMER3_UNION;
#endif
#define PMIC_CHG_TIMER3_chg_timer_s3_START (0)
#define PMIC_CHG_TIMER3_chg_timer_s3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char load_timer_s0 : 8;
    } reg;
} PMIC_LOAD_TIMER0_UNION;
#endif
#define PMIC_LOAD_TIMER0_load_timer_s0_START (0)
#define PMIC_LOAD_TIMER0_load_timer_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char load_timer_s1 : 8;
    } reg;
} PMIC_LOAD_TIMER1_UNION;
#endif
#define PMIC_LOAD_TIMER1_load_timer_s1_START (0)
#define PMIC_LOAD_TIMER1_load_timer_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char load_timer_s2 : 8;
    } reg;
} PMIC_LOAD_TIMER2_UNION;
#endif
#define PMIC_LOAD_TIMER2_load_timer_s2_START (0)
#define PMIC_LOAD_TIMER2_load_timer_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char load_timer_s3 : 8;
    } reg;
} PMIC_LOAD_TIMER3_UNION;
#endif
#define PMIC_LOAD_TIMER3_load_timer_s3_START (0)
#define PMIC_LOAD_TIMER3_load_timer_s3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cl_int_s0 : 8;
    } reg;
} PMIC_CL_INT0_UNION;
#endif
#define PMIC_CL_INT0_cl_int_s0_START (0)
#define PMIC_CL_INT0_cl_int_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cl_int_s1 : 8;
    } reg;
} PMIC_CL_INT1_UNION;
#endif
#define PMIC_CL_INT1_cl_int_s1_START (0)
#define PMIC_CL_INT1_cl_int_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cl_int_s2 : 8;
    } reg;
} PMIC_CL_INT2_UNION;
#endif
#define PMIC_CL_INT2_cl_int_s2_START (0)
#define PMIC_CL_INT2_cl_int_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char cl_int_s3 : 8;
    } reg;
} PMIC_CL_INT3_UNION;
#endif
#define PMIC_CL_INT3_cl_int_s3_START (0)
#define PMIC_CL_INT3_cl_int_s3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_int_s0 : 8;
    } reg;
} PMIC_V_INT0_UNION;
#endif
#define PMIC_V_INT0_v_int_s0_START (0)
#define PMIC_V_INT0_v_int_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_int_s1 : 8;
    } reg;
} PMIC_V_INT1_UNION;
#endif
#define PMIC_V_INT1_v_int_s1_START (0)
#define PMIC_V_INT1_v_int_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char offset_current_s0 : 8;
    } reg;
} PMIC_OFFSET_CURRENT0_UNION;
#endif
#define PMIC_OFFSET_CURRENT0_offset_current_s0_START (0)
#define PMIC_OFFSET_CURRENT0_offset_current_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char offset_current_s1 : 8;
    } reg;
} PMIC_OFFSET_CURRENT1_UNION;
#endif
#define PMIC_OFFSET_CURRENT1_offset_current_s1_START (0)
#define PMIC_OFFSET_CURRENT1_offset_current_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char offset_voltage_s0 : 8;
    } reg;
} PMIC_OFFSET_VOLTAGE0_UNION;
#endif
#define PMIC_OFFSET_VOLTAGE0_offset_voltage_s0_START (0)
#define PMIC_OFFSET_VOLTAGE0_offset_voltage_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char offset_voltage_s1 : 8;
    } reg;
} PMIC_OFFSET_VOLTAGE1_UNION;
#endif
#define PMIC_OFFSET_VOLTAGE1_offset_voltage_s1_START (0)
#define PMIC_OFFSET_VOLTAGE1_offset_voltage_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_ocv_data_s0 : 8;
    } reg;
} PMIC_OCV_VOLTAGE0_UNION;
#endif
#define PMIC_OCV_VOLTAGE0_v_ocv_data_s0_START (0)
#define PMIC_OCV_VOLTAGE0_v_ocv_data_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_ocv_data_s1 : 8;
    } reg;
} PMIC_OCV_VOLTAGE1_UNION;
#endif
#define PMIC_OCV_VOLTAGE1_v_ocv_data_s1_START (0)
#define PMIC_OCV_VOLTAGE1_v_ocv_data_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char i_ocv_data_s0 : 8;
    } reg;
} PMIC_OCV_CURRENT0_UNION;
#endif
#define PMIC_OCV_CURRENT0_i_ocv_data_s0_START (0)
#define PMIC_OCV_CURRENT0_i_ocv_data_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char i_ocv_data_s1 : 8;
    } reg;
} PMIC_OCV_CURRENT1_UNION;
#endif
#define PMIC_OCV_CURRENT1_i_ocv_data_s1_START (0)
#define PMIC_OCV_CURRENT1_i_ocv_data_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char eco_out_clin_s0 : 8;
    } reg;
} PMIC_ECO_OUT_CLIN_0_UNION;
#endif
#define PMIC_ECO_OUT_CLIN_0_eco_out_clin_s0_START (0)
#define PMIC_ECO_OUT_CLIN_0_eco_out_clin_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char eco_out_clin_s1 : 8;
    } reg;
} PMIC_ECO_OUT_CLIN_1_UNION;
#endif
#define PMIC_ECO_OUT_CLIN_1_eco_out_clin_s1_START (0)
#define PMIC_ECO_OUT_CLIN_1_eco_out_clin_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char eco_out_clin_s2 : 8;
    } reg;
} PMIC_ECO_OUT_CLIN_2_UNION;
#endif
#define PMIC_ECO_OUT_CLIN_2_eco_out_clin_s2_START (0)
#define PMIC_ECO_OUT_CLIN_2_eco_out_clin_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char eco_out_clin_s3 : 8;
    } reg;
} PMIC_ECO_OUT_CLIN_3_UNION;
#endif
#define PMIC_ECO_OUT_CLIN_3_eco_out_clin_s3_START (0)
#define PMIC_ECO_OUT_CLIN_3_eco_out_clin_s3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char eco_out_clout_s0 : 8;
    } reg;
} PMIC_ECO_OUT_CLOUT_0_UNION;
#endif
#define PMIC_ECO_OUT_CLOUT_0_eco_out_clout_s0_START (0)
#define PMIC_ECO_OUT_CLOUT_0_eco_out_clout_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char eco_out_clout_s1 : 8;
    } reg;
} PMIC_ECO_OUT_CLOUT_1_UNION;
#endif
#define PMIC_ECO_OUT_CLOUT_1_eco_out_clout_s1_START (0)
#define PMIC_ECO_OUT_CLOUT_1_eco_out_clout_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char eco_out_clout_s2 : 8;
    } reg;
} PMIC_ECO_OUT_CLOUT_2_UNION;
#endif
#define PMIC_ECO_OUT_CLOUT_2_eco_out_clout_s2_START (0)
#define PMIC_ECO_OUT_CLOUT_2_eco_out_clout_s2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char eco_out_clout_s3 : 8;
    } reg;
} PMIC_ECO_OUT_CLOUT_3_UNION;
#endif
#define PMIC_ECO_OUT_CLOUT_3_eco_out_clout_s3_START (0)
#define PMIC_ECO_OUT_CLOUT_3_eco_out_clout_s3_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_pre0_s0 : 8;
    } reg;
} PMIC_V_OUT0_PRE0_UNION;
#endif
#define PMIC_V_OUT0_PRE0_v_out_pre0_s0_START (0)
#define PMIC_V_OUT0_PRE0_v_out_pre0_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_pre0_s1 : 8;
    } reg;
} PMIC_V_OUT1_PRE0_UNION;
#endif
#define PMIC_V_OUT1_PRE0_v_out_pre0_s1_START (0)
#define PMIC_V_OUT1_PRE0_v_out_pre0_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_pre1_s0 : 8;
    } reg;
} PMIC_V_OUT0_PRE1_UNION;
#endif
#define PMIC_V_OUT0_PRE1_v_out_pre1_s0_START (0)
#define PMIC_V_OUT0_PRE1_v_out_pre1_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_pre1_s1 : 8;
    } reg;
} PMIC_V_OUT1_PRE1_UNION;
#endif
#define PMIC_V_OUT1_PRE1_v_out_pre1_s1_START (0)
#define PMIC_V_OUT1_PRE1_v_out_pre1_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_pre2_s0 : 8;
    } reg;
} PMIC_V_OUT0_PRE2_UNION;
#endif
#define PMIC_V_OUT0_PRE2_v_out_pre2_s0_START (0)
#define PMIC_V_OUT0_PRE2_v_out_pre2_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_pre2_s1 : 8;
    } reg;
} PMIC_V_OUT1_PRE2_UNION;
#endif
#define PMIC_V_OUT1_PRE2_v_out_pre2_s1_START (0)
#define PMIC_V_OUT1_PRE2_v_out_pre2_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_pre3_s0 : 8;
    } reg;
} PMIC_V_OUT0_PRE3_UNION;
#endif
#define PMIC_V_OUT0_PRE3_v_out_pre3_s0_START (0)
#define PMIC_V_OUT0_PRE3_v_out_pre3_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_pre3_s1 : 8;
    } reg;
} PMIC_V_OUT1_PRE3_UNION;
#endif
#define PMIC_V_OUT1_PRE3_v_out_pre3_s1_START (0)
#define PMIC_V_OUT1_PRE3_v_out_pre3_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_pre4_s0 : 8;
    } reg;
} PMIC_V_OUT0_PRE4_UNION;
#endif
#define PMIC_V_OUT0_PRE4_v_out_pre4_s0_START (0)
#define PMIC_V_OUT0_PRE4_v_out_pre4_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_pre4_s1 : 8;
    } reg;
} PMIC_V_OUT1_PRE4_UNION;
#endif
#define PMIC_V_OUT1_PRE4_v_out_pre4_s1_START (0)
#define PMIC_V_OUT1_PRE4_v_out_pre4_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_pre5_s0 : 8;
    } reg;
} PMIC_V_OUT0_PRE5_UNION;
#endif
#define PMIC_V_OUT0_PRE5_v_out_pre5_s0_START (0)
#define PMIC_V_OUT0_PRE5_v_out_pre5_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_pre5_s1 : 8;
    } reg;
} PMIC_V_OUT1_PRE5_UNION;
#endif
#define PMIC_V_OUT1_PRE5_v_out_pre5_s1_START (0)
#define PMIC_V_OUT1_PRE5_v_out_pre5_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_pre6_s0 : 8;
    } reg;
} PMIC_V_OUT0_PRE6_UNION;
#endif
#define PMIC_V_OUT0_PRE6_v_out_pre6_s0_START (0)
#define PMIC_V_OUT0_PRE6_v_out_pre6_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_pre6_s1 : 8;
    } reg;
} PMIC_V_OUT1_PRE6_UNION;
#endif
#define PMIC_V_OUT1_PRE6_v_out_pre6_s1_START (0)
#define PMIC_V_OUT1_PRE6_v_out_pre6_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_pre7_s0 : 8;
    } reg;
} PMIC_V_OUT0_PRE7_UNION;
#endif
#define PMIC_V_OUT0_PRE7_v_out_pre7_s0_START (0)
#define PMIC_V_OUT0_PRE7_v_out_pre7_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_pre7_s1 : 8;
    } reg;
} PMIC_V_OUT1_PRE7_UNION;
#endif
#define PMIC_V_OUT1_PRE7_v_out_pre7_s1_START (0)
#define PMIC_V_OUT1_PRE7_v_out_pre7_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_pre8_s0 : 8;
    } reg;
} PMIC_V_OUT0_PRE8_UNION;
#endif
#define PMIC_V_OUT0_PRE8_v_out_pre8_s0_START (0)
#define PMIC_V_OUT0_PRE8_v_out_pre8_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_pre8_s1 : 8;
    } reg;
} PMIC_V_OUT1_PRE8_UNION;
#endif
#define PMIC_V_OUT1_PRE8_v_out_pre8_s1_START (0)
#define PMIC_V_OUT1_PRE8_v_out_pre8_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_pre9_s0 : 8;
    } reg;
} PMIC_V_OUT0_PRE9_UNION;
#endif
#define PMIC_V_OUT0_PRE9_v_out_pre9_s0_START (0)
#define PMIC_V_OUT0_PRE9_v_out_pre9_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_out_pre9_s1 : 8;
    } reg;
} PMIC_V_OUT1_PRE9_UNION;
#endif
#define PMIC_V_OUT1_PRE9_v_out_pre9_s1_START (0)
#define PMIC_V_OUT1_PRE9_v_out_pre9_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_pre0_s0 : 8;
    } reg;
} PMIC_CURRENT0_PRE0_UNION;
#endif
#define PMIC_CURRENT0_PRE0_current_pre0_s0_START (0)
#define PMIC_CURRENT0_PRE0_current_pre0_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_pre0_s1 : 8;
    } reg;
} PMIC_CURRENT1_PRE0_UNION;
#endif
#define PMIC_CURRENT1_PRE0_current_pre0_s1_START (0)
#define PMIC_CURRENT1_PRE0_current_pre0_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_pre1_s0 : 8;
    } reg;
} PMIC_CURRENT0_PRE1_UNION;
#endif
#define PMIC_CURRENT0_PRE1_current_pre1_s0_START (0)
#define PMIC_CURRENT0_PRE1_current_pre1_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_pre1_s1 : 8;
    } reg;
} PMIC_CURRENT1_PRE1_UNION;
#endif
#define PMIC_CURRENT1_PRE1_current_pre1_s1_START (0)
#define PMIC_CURRENT1_PRE1_current_pre1_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_pre2_s0 : 8;
    } reg;
} PMIC_CURRENT0_PRE2_UNION;
#endif
#define PMIC_CURRENT0_PRE2_current_pre2_s0_START (0)
#define PMIC_CURRENT0_PRE2_current_pre2_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_pre2_s1 : 8;
    } reg;
} PMIC_CURRENT1_PRE2_UNION;
#endif
#define PMIC_CURRENT1_PRE2_current_pre2_s1_START (0)
#define PMIC_CURRENT1_PRE2_current_pre2_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_pre3_s0 : 8;
    } reg;
} PMIC_CURRENT0_PRE3_UNION;
#endif
#define PMIC_CURRENT0_PRE3_current_pre3_s0_START (0)
#define PMIC_CURRENT0_PRE3_current_pre3_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_pre3_s1 : 8;
    } reg;
} PMIC_CURRENT1_PRE3_UNION;
#endif
#define PMIC_CURRENT1_PRE3_current_pre3_s1_START (0)
#define PMIC_CURRENT1_PRE3_current_pre3_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_pre4_s0 : 8;
    } reg;
} PMIC_CURRENT0_PRE4_UNION;
#endif
#define PMIC_CURRENT0_PRE4_current_pre4_s0_START (0)
#define PMIC_CURRENT0_PRE4_current_pre4_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_pre4_s1 : 8;
    } reg;
} PMIC_CURRENT1_PRE4_UNION;
#endif
#define PMIC_CURRENT1_PRE4_current_pre4_s1_START (0)
#define PMIC_CURRENT1_PRE4_current_pre4_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_pre5_s0 : 8;
    } reg;
} PMIC_CURRENT0_PRE5_UNION;
#endif
#define PMIC_CURRENT0_PRE5_current_pre5_s0_START (0)
#define PMIC_CURRENT0_PRE5_current_pre5_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_pre5_s1 : 8;
    } reg;
} PMIC_CURRENT1_PRE5_UNION;
#endif
#define PMIC_CURRENT1_PRE5_current_pre5_s1_START (0)
#define PMIC_CURRENT1_PRE5_current_pre5_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_pre6_s0 : 8;
    } reg;
} PMIC_CURRENT0_PRE6_UNION;
#endif
#define PMIC_CURRENT0_PRE6_current_pre6_s0_START (0)
#define PMIC_CURRENT0_PRE6_current_pre6_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_pre6_s1 : 8;
    } reg;
} PMIC_CURRENT1_PRE6_UNION;
#endif
#define PMIC_CURRENT1_PRE6_current_pre6_s1_START (0)
#define PMIC_CURRENT1_PRE6_current_pre6_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_pre7_s0 : 8;
    } reg;
} PMIC_CURRENT0_PRE7_UNION;
#endif
#define PMIC_CURRENT0_PRE7_current_pre7_s0_START (0)
#define PMIC_CURRENT0_PRE7_current_pre7_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_pre7_s1 : 8;
    } reg;
} PMIC_CURRENT1_PRE7_UNION;
#endif
#define PMIC_CURRENT1_PRE7_current_pre7_s1_START (0)
#define PMIC_CURRENT1_PRE7_current_pre7_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_pre8_s0 : 8;
    } reg;
} PMIC_CURRENT0_PRE8_UNION;
#endif
#define PMIC_CURRENT0_PRE8_current_pre8_s0_START (0)
#define PMIC_CURRENT0_PRE8_current_pre8_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_pre8_s1 : 8;
    } reg;
} PMIC_CURRENT1_PRE8_UNION;
#endif
#define PMIC_CURRENT1_PRE8_current_pre8_s1_START (0)
#define PMIC_CURRENT1_PRE8_current_pre8_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_pre9_s0 : 8;
    } reg;
} PMIC_CURRENT0_PRE9_UNION;
#endif
#define PMIC_CURRENT0_PRE9_current_pre9_s0_START (0)
#define PMIC_CURRENT0_PRE9_current_pre9_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_pre9_s1 : 8;
    } reg;
} PMIC_CURRENT1_PRE9_UNION;
#endif
#define PMIC_CURRENT1_PRE9_current_pre9_s1_START (0)
#define PMIC_CURRENT1_PRE9_current_pre9_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char offset_current_mod_s0 : 8;
    } reg;
} PMIC_OFFSET_CURRENT_MOD_0_UNION;
#endif
#define PMIC_OFFSET_CURRENT_MOD_0_offset_current_mod_s0_START (0)
#define PMIC_OFFSET_CURRENT_MOD_0_offset_current_mod_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char offset_current_mod_s1 : 8;
    } reg;
} PMIC_OFFSET_CURRENT_MOD_1_UNION;
#endif
#define PMIC_OFFSET_CURRENT_MOD_1_offset_current_mod_s1_START (0)
#define PMIC_OFFSET_CURRENT_MOD_1_offset_current_mod_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char offset_voltage_mod_s0 : 8;
    } reg;
} PMIC_OFFSET_VOLTAGE_MOD_0_UNION;
#endif
#define PMIC_OFFSET_VOLTAGE_MOD_0_offset_voltage_mod_s0_START (0)
#define PMIC_OFFSET_VOLTAGE_MOD_0_offset_voltage_mod_s0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char offset_voltage_mod_s1 : 8;
    } reg;
} PMIC_OFFSET_VOLTAGE_MOD_1_UNION;
#endif
#define PMIC_OFFSET_VOLTAGE_MOD_1_offset_voltage_mod_s1_START (0)
#define PMIC_OFFSET_VOLTAGE_MOD_1_offset_voltage_mod_s1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char coul_reserve0 : 8;
    } reg;
} PMIC_COUL_RESERVE0_UNION;
#endif
#define PMIC_COUL_RESERVE0_coul_reserve0_START (0)
#define PMIC_COUL_RESERVE0_coul_reserve0_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char i_reserve_1 : 8;
    } reg;
} PMIC_CLJ_RESERVED0_UNION;
#endif
#define PMIC_CLJ_RESERVED0_i_reserve_1_START (0)
#define PMIC_CLJ_RESERVED0_i_reserve_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char i_reserve_2 : 8;
    } reg;
} PMIC_CLJ_RESERVED1_UNION;
#endif
#define PMIC_CLJ_RESERVED1_i_reserve_2_START (0)
#define PMIC_CLJ_RESERVED1_i_reserve_2_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char v_reserve_1 : 8;
    } reg;
} PMIC_CLJ_RESERVED2_UNION;
#endif
#define PMIC_CLJ_RESERVED2_v_reserve_1_START (0)
#define PMIC_CLJ_RESERVED2_v_reserve_1_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char clj_debug_0 : 1;
        unsigned char clj_debug_1 : 1;
        unsigned char clj_debug_2 : 1;
        unsigned char clj_debug_3 : 1;
        unsigned char cali_en_i : 1;
        unsigned char cali_en_i_force : 1;
        unsigned char cali_en_v_force : 1;
        unsigned char cali_en_v : 1;
    } reg;
} PMIC_CLJ_DEBUG_UNION;
#endif
#define PMIC_CLJ_DEBUG_clj_debug_0_START (0)
#define PMIC_CLJ_DEBUG_clj_debug_0_END (0)
#define PMIC_CLJ_DEBUG_clj_debug_1_START (1)
#define PMIC_CLJ_DEBUG_clj_debug_1_END (1)
#define PMIC_CLJ_DEBUG_clj_debug_2_START (2)
#define PMIC_CLJ_DEBUG_clj_debug_2_END (2)
#define PMIC_CLJ_DEBUG_clj_debug_3_START (3)
#define PMIC_CLJ_DEBUG_clj_debug_3_END (3)
#define PMIC_CLJ_DEBUG_cali_en_i_START (4)
#define PMIC_CLJ_DEBUG_cali_en_i_END (4)
#define PMIC_CLJ_DEBUG_cali_en_i_force_START (5)
#define PMIC_CLJ_DEBUG_cali_en_i_force_END (5)
#define PMIC_CLJ_DEBUG_cali_en_v_force_START (6)
#define PMIC_CLJ_DEBUG_cali_en_v_force_END (6)
#define PMIC_CLJ_DEBUG_cali_en_v_START (7)
#define PMIC_CLJ_DEBUG_cali_en_v_END (7)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char current_coul_always_off : 1;
        unsigned char voltage_coul_always_off : 1;
        unsigned char clj_debug_2_2 : 1;
        unsigned char reserved : 5;
    } reg;
} PMIC_CLJ_DEBUG_2_UNION;
#endif
#define PMIC_CLJ_DEBUG_2_current_coul_always_off_START (0)
#define PMIC_CLJ_DEBUG_2_current_coul_always_off_END (0)
#define PMIC_CLJ_DEBUG_2_voltage_coul_always_off_START (1)
#define PMIC_CLJ_DEBUG_2_voltage_coul_always_off_END (1)
#define PMIC_CLJ_DEBUG_2_clj_debug_2_2_START (2)
#define PMIC_CLJ_DEBUG_2_clj_debug_2_2_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char mstate : 3;
        unsigned char reserved : 5;
    } reg;
} PMIC_STATE_TEST_UNION;
#endif
#define PMIC_STATE_TEST_mstate_START (0)
#define PMIC_STATE_TEST_mstate_END (2)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char coul_ctrl_onoff_reg : 1;
        unsigned char reg_data_clr : 1;
        unsigned char cali_auto_time : 3;
        unsigned char cali_auto_onoff_ctrl : 1;
        unsigned char reserved : 2;
    } reg;
} PMIC_CLJ_CTRL_REGS2_UNION;
#endif
#define PMIC_CLJ_CTRL_REGS2_coul_ctrl_onoff_reg_START (0)
#define PMIC_CLJ_CTRL_REGS2_coul_ctrl_onoff_reg_END (0)
#define PMIC_CLJ_CTRL_REGS2_reg_data_clr_START (1)
#define PMIC_CLJ_CTRL_REGS2_reg_data_clr_END (1)
#define PMIC_CLJ_CTRL_REGS2_cali_auto_time_START (2)
#define PMIC_CLJ_CTRL_REGS2_cali_auto_time_END (4)
#define PMIC_CLJ_CTRL_REGS2_cali_auto_onoff_ctrl_START (5)
#define PMIC_CLJ_CTRL_REGS2_cali_auto_onoff_ctrl_END (5)
#ifndef __SOC_H_FOR_ASM__
typedef union
{
    unsigned char value;
    struct
    {
        unsigned char debug_write_pro : 8;
    } reg;
} PMIC_DEBUG_WRITE_PRO_UNION;
#endif
#define PMIC_DEBUG_WRITE_PRO_debug_write_pro_START (0)
#define PMIC_DEBUG_WRITE_PRO_debug_write_pro_END (7)
#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif
#endif
