/*
 * Copyright (C) 2007 Google, Inc.
 * Copyright (c) 2008-2011, Code Aurora Forum. All rights reserved.
 * Author: Brian Swetland <swetland@google.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 *
 * The MSM peripherals are spread all over across 768MB of physical
 * space, which makes just having a simple IO_ADDRESS macro to slide
 * them into the right virtual location rough.  Instead, we will
 * provide a master phys->virt mapping for peripherals here.
 *
 */

#ifndef __ASM_ARCH_MSM_IOMAP_H
#define __ASM_ARCH_MSM_IOMAP_H

#include <asm/sizes.h>

/* Physical base address and size of peripherals.
 * Ordered by the virtual base addresses they will be mapped at.
 *
 * MSM_VIC_BASE must be an value that can be loaded via a "mov"
 * instruction, otherwise entry-macro.S will not compile.
 *
 * If you add or remove entries here, you'll want to edit the
 * msm_io_desc array in arch/arm/mach-msm/io.c to reflect your
 * changes.
 *
 */

#ifdef __ASSEMBLY__
#define IOMEM(x)	x
#else
#define IOMEM(x)	((void __force __iomem *)(x))
#endif

#include "msm_iomap-7xxx.h"
#if defined(CONFIG_ARCH_MSM7X30)
#include "msm_iomap-7x30.h"
#elif defined(CONFIG_ARCH_QSD8X50)
#include "msm_iomap-8x50.h"
#elif defined(CONFIG_ARCH_MSM8X60)
#include "msm_iomap-8x60.h"
#else
#include "msm_iomap-7xxx.h"
#endif

#include "msm_iomap-8960.h"

#define MSM_STRONGLY_ORDERED_PAGE	0xFA0F0000
#define MSM8625_SECONDARY_PHYS		0x0FE00000

#if defined(CONFIG_DEBUG_MSM_UART1)
#define MSM_DEBUG_UART_BASE 0xFB000000
#define MSM_DEBUG_UART_PHYS MSM_UART1_PHYS
#elif defined(CONFIG_DEBUG_MSM_UART2)
#define MSM_DEBUG_UART_BASE 0xFB000000
#define MSM_DEBUG_UART_PHYS MSM_UART2_PHYS
#elif defined(CONFIG_DEBUG_MSM_UART3)
#define MSM_DEBUG_UART_BASE 0xFB000000
#define MSM_DEBUG_UART_PHYS MSM_UART3_PHYS
#endif

#endif
