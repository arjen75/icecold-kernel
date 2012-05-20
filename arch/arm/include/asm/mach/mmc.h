/*
 *  arch/arm/include/asm/mach/mmc.h
 */
#ifndef ASMARM_MACH_MMC_H
#define ASMARM_MACH_MMC_H

#include <linux/mmc/host.h>
#include <linux/mmc/card.h>
#include <linux/mmc/sdio_func.h>

struct embedded_sdio_data {
        struct sdio_cis cis;
        struct sdio_cccr cccr;
        struct sdio_embedded_func *funcs;
        int num_funcs;
};

struct mmc_platform_data {
	unsigned int ocr_mask;			/* available voltages */
	int built_in;				/* built-in device flag */
	int card_present;			/* card detect state */
	u32 (*translate_vdd)(struct device *, unsigned int);
	unsigned int (*status)(struct device *);
	struct embedded_sdio_data *embedded_sdio;
	int (*register_status_notify)(void (*callback)(int card_present, void *dev_id), void *dev_id);
	/*
	 * XPC controls the maximum current in the
	 * default speed mode of SDXC card.
	 */
	unsigned int xpc_cap;
	/* Supported UHS-I Modes */
	unsigned int uhs_caps;
	void (*sdio_lpm_gpio_setup)(struct device *, unsigned int);
        unsigned int status_irq;
	unsigned int status_gpio;
	/* Indicates the polarity of the GPIO line when card is inserted */
	bool is_status_gpio_active_low;
        unsigned int sdiowakeup_irq;
        unsigned long irq_flags;
        unsigned long mmc_bus_width;
        int (*wpswitch) (struct device *);
	unsigned int msmsdcc_fmin;
	unsigned int msmsdcc_fmid;
	unsigned int msmsdcc_fmax;
	bool nonremovable;
	bool pclk_src_dfab;
	unsigned int mpm_sdiowakeup_int;
	unsigned int wpswitch_gpio;
	unsigned char wpswitch_polarity;
	struct msm_mmc_slot_reg_data *vreg_data;
	int is_sdio_al_client;
	unsigned int *sup_clk_table;
	unsigned char sup_clk_cnt;
	struct msm_mmc_pin_data *pin_data;
	bool disable_bam;
	bool disable_runtime_pm;
	bool disable_cmd23;
	u32 cpu_dma_latency;
};

#endif
