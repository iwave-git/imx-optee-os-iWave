/* SPDX-License-Identifier: BSD-2-Clause */
/*
 * Copyright 2017-2018 NXP
 *
 */

#ifndef __MX6_IOMUX_REGS_H__
#define __MX6_IOMUX_REGS_H__

/*
 * Macros definition
 */
#define IOMUX_GPRx_OFFSET(idx)	(idx * 4)

/*
 * TrustZone Address Space Controller Select
 */
#define IOMUX_GPR_TZASC_ID		9
#define BP_IOMUX_GPR_TZASC2_MUX_CTRL	1
#define BM_IOMUX_GPR_TZASC2_MUX_CTRL	BIT32(BP_IOMUX_GPR_TZASC2_MUX_CTRL)
#define BP_IOMUX_GPR_TZASC1_MUX_CTRL	0
#define BM_IOMUX_GPR_TZASC1_MUX_CTRL	BIT32(BP_IOMUX_GPR_TZASC1_MUX_CTRL)

/*
 * OCRAM Configuration
 */
#define IOMUX_GPR_OCRAM_ID		10

#define BP_IOMUX_GPR_OCRAM_TZ_ADDR	5
#define BM_IOMUX_GPR_OCRAM_TZ_ADDR	\
				SHIFT_U32(0x3F, BP_IOMUX_GPR_OCRAM_TZ_ADDR)
#define BP_IOMUX_GPR_OCRAM_TZ_EN	4
#define BM_IOMUX_GPR_OCRAM_TZ_EN	BIT32(BP_IOMUX_GPR_OCRAM_TZ_EN)
#define IOMUX_GPR_OCRAM_TZ_ENABLE	BIT32(BP_IOMUX_GPR_OCRAM_TZ_EN)
#define IOMUX_GPR_OCRAM_TZ_DISABLE	SHIFT_U32(0, BP_IOMUX_GPR_OCRAM_TZ_EN)

// For MX6DL
#define BP_IOMUX_GPR_OCRAM_TZ_ADDR_6DL	5
#define BM_IOMUX_GPR_OCRAM_TZ_ADDR_6DL	\
			SHIFT_U32(0x1F, BP_IOMUX_GPR_OCRAM_TZ_ADDR_6DL)
#define BP_IOMUX_GPR_OCRAM_TZ_EN_6DL	4
#define BM_IOMUX_GPR_OCRAM_TZ_EN_6DL	\
			BIT32(BP_IOMUX_GPR_OCRAM_TZ_EN_6DL)
#define IOMUX_GPR_OCRAM_TZ_ENABLE_6DL	\
			BIT32(BP_IOMUX_GPR_OCRAM_TZ_EN_6DL)
#define IOMUX_GPR_OCRAM_TZ_DISABLE_6DL	\
			SHIFT_U32(0, BP_IOMUX_GPR_OCRAM_TZ_EN_6DL)

// For MX6SX
#define BP_IOMUX_GPR_OCRAM_TZ_ADDR_6SX	11
#define BM_IOMUX_GPR_OCRAM_TZ_ADDR_6SX	\
			SHIFT_U32(0x3F, BP_IOMUX_GPR_OCRAM_TZ_ADDR_6SX)
#define BP_IOMUX_GPR_OCRAM_TZ_EN_6SX	10
#define BM_IOMUX_GPR_OCRAM_TZ_EN_6SX	\
			BIT32(BP_IOMUX_GPR_OCRAM_TZ_EN_6SX)
#define IOMUX_GPR_OCRAM_TZ_ENABLE_6SX	\
			BIT32(BP_IOMUX_GPR_OCRAM_TZ_EN_6SX)
#define IOMUX_GPR_OCRAM_TZ_DISABLE_6SX	\
			SHIFT_U32(0, BP_IOMUX_GPR_OCRAM_TZ_EN_6SX)

// For MX6UL
#define BP_IOMUX_GPR_OCRAM_TZ_ADDR_6UL	11
#define BM_IOMUX_GPR_OCRAM_TZ_ADDR_6UL	\
			SHIFT_U32(0x1F, BP_IOMUX_GPR_OCRAM_TZ_ADDR_6UL)
#define BP_IOMUX_GPR_OCRAM_TZ_EN_6UL	10
#define BM_IOMUX_GPR_OCRAM_TZ_EN_6UL	\
			BIT32(BP_IOMUX_GPR_OCRAM_TZ_EN_6UL)
#define IOMUX_GPR_OCRAM_TZ_ENABLE_6UL	\
			BIT32(BP_IOMUX_GPR_OCRAM_TZ_EN_6UL)
#define IOMUX_GPR_OCRAM_TZ_DISABLE_6UL	\
			SHIFT_U32(0, BP_IOMUX_GPR_OCRAM_TZ_EN_6UL)

/* The configuration is locked with register bits 16 to 29 as mirror
 * of bits 0 to 13
 */
#define BP_IOMUX_GPR_OCRAM_LOCK		16
#define IOMUX_GPR_OCRAM_LOCK(value)	\
			SHIFT_U32(value, BP_IOMUX_GPR_OCRAM_LOCK)

/*
 * S_OCRAM Configuration
 */
#define IOMUX_GPR_S_OCRAM_ID	11

// For MX6SX
#define BP_IOMUX_GPR_S_OCRAM_TZ_ADDR_6SX	11
#define BM_IOMUX_GPR_S_OCRAM_TZ_ADDR_6SX	\
			SHIFT_U32(0x3, BP_IOMUX_GPR_S_OCRAM_TZ_ADDR_6SX)
#define BP_IOMUX_GPR_S_OCRAM_TZ_EN_6SX		10
#define BM_IOMUX_GPR_S_OCRAM_TZ_EN_6SX		\
			BIT32(BP_IOMUX_GPR_S_OCRAM_TZ_EN_6SX)
#define IOMUX_GPR_S_OCRAM_TZ_ENABLE_6SX		\
			BIT32(BP_IOMUX_GPR_S_OCRAM_TZ_EN_6SX)
#define IOMUX_GPR_S_OCRAM_TZ_DISABLE_6SX	\
			SHIFT_U32(0, BP_IOMUX_GPR_S_OCRAM_TZ_EN_6SX)
#define BP_IOMUX_GPR_S_OCRAM_L2_EN_6SX		1
#define BM_IOMUX_GPR_S_OCRAM_L2_EN_6SX		\
			BIT32(BP_IOMUX_GPR_S_OCRAM_L2_EN_6SX)

#endif /* __MX6_IOMUX_REGS_H__ */
