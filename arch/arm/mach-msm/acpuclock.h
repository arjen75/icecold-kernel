/* arch/arm/mach-msm/acpuclock.h
 *
 * MSM architecture clock driver header
 *
 * Copyright (C) 2007 Google, Inc.
 * Copyright (c) 2007 QUALCOMM Incorporated
 * Author: San Mehat <san@android.com>
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
 */

#ifndef __ARCH_ARM_MACH_MSM_ACPUCLOCK_H
#define __ARCH_ARM_MACH_MSM_ACPUCLOCK_H

int acpuclk_set_rate(unsigned long rate, int for_power_collapse);
unsigned long acpuclk_get_rate(void);
uint32_t acpuclk_get_switch_time(void);
unsigned long acpuclk_wait_for_irq(void);
unsigned long acpuclk_power_collapse(void);
unsigned long acpuclk_get_wfi_rate(void);

void __init msm_acpu_clock_init(struct msm_acpu_clock_platform_data *clkdata)
{
	pr_info("acpu_clock_init()\n");

	mutex_init(&drv_state.lock);
	if (cpu_is_msm7x27())
		shared_pll_control_init();
	drv_state.acpu_switch_time_us = clkdata->acpu_switch_time_us;
	drv_state.max_speed_delta_khz = clkdata->max_speed_delta_khz;
	drv_state.vdd_switch_time_us = clkdata->vdd_switch_time_us;
	drv_state.max_axi_khz = clkdata->max_axi_khz;
	acpu_freq_tbl_fixup();
	precompute_stepping();
	if (cpu_is_msm7x25())
		msm7x25_acpu_pll_hw_bug_fix();
	acpuclk_init();
	lpj_init();
	print_acpu_freq_tbl();
#ifdef CONFIG_CPU_FREQ_MSM
	cpufreq_table_init();
	cpufreq_frequency_table_get_attr(freq_table, smp_processor_id());
#endif
}

#endif

