/*
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 * Gary Jennejohn <garyj@denx.de>
 * David Mueller <d.mueller@elsoft.ch>
 *
 * Configuation settings for the uCDragon FS2410 board.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H


/*
 * High Level Configuration Options
 * (easy to change)
 */
#define CONFIG_ARM920T		/* This is an ARM920T Core */
#define CONFIG_S3C24X0		/* in a SAMSUNG S3C24x0-type SoC */
#define CONFIG_S3C2410		/* specifically a SAMSUNG S3C2410 SoC */
#define CONFIG_FS2410		/* on a Specific FS2410 Board */
#define CONFIG_SYS_ARM_CACHE_WRITETHROUGH

/* input clock of PLL (the FS2410 has 12MHz input clock) */
#define CONFIG_SYS_CLK_FREQ		12000000

#undef CONFIG_USE_IRQ		/* we don't need IRQ/FIQ stuff */

#define CONFIG_CMDLINE_TAG	/* enable passing of ATAGs */
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG

/*
 * select serial console configuration
 */
#define CONFIG_S3C24X0_SERIAL
#define CONFIG_SERIAL1			1	/* we use SERIAL 1 on FS2410 */

/* 
 * autoboot 
 */
#define CONFIG_BOOTDELAY		1
#define CONFIG_BOOT_RETRY_TIME		-1
#define CONFIG_RESET_TO_RETRY
#define CONFIG_ZERO_BOOTDELAY_CHECK

/*
 * LCD support 
 */
//#define CONFIG_LCD
//#define CONFIG_LCD_S3C24X0

/*
 * RTC options
 */
#define CONFIG_RTC_S3C24X0

/*
 * Command line configuration.
 */
#include <config_cmd_default.h>

#undef  CONFIG_CMD_NET
#undef  CONFIG_CMD_NFS
#undef  CONFIG_CMD_XIMG
#undef  CONFIG_CMD_FPGA
#undef  CONFIG_CMD_ITEST
#undef  CONFIG_CMD_LOADS
#undef  CONFIG_CMD_MISC
#undef  CONFIG_CMD_SOURCE

#define CONFIG_CMD_CACHE
#define CONFIG_CMD_DATE
#define CONFIG_CMD_NAND

#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT_HUSH_PS2	"# "

#if defined(CONFIG_CMD_KGDB)
#define CONFIG_KGDB_BAUDRATE		115200	/* speed to run kgdb serial port */
/* what's this ? it's not used anywhere */
#define CONFIG_KGDB_SER_INDEX		2	/* which serial port to use */
#endif

/*
 * NET Hardware drivers
 */
#if defined(CONFIG_CMD_NET)
#define CONFIG_NETMASK			255.255.255.0
#define CONFIG_IPADDR			192.168.8.8
#define CONFIG_SERVERIP			192.168.8.2

#define CONFIG_NET_MULTI
#define CONFIG_CS8900			/* we have a CS8900 on-board */
#define CONFIG_CS8900_BASE		0x19000300
#define CONFIG_CS8900_BUS16		/* the Linux driver does accesses as shorts */
#endif /* CONFIG_CMD_NET */

/*
 * BOOTP options
 */
#if defined(CONFIG_CMD_DHCP)
#define CONFIG_BOOTP_BOOTFILESIZE
#define CONFIG_BOOTP_BOOTPATH
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME
#endif /* CONFIG_CMD_DHCP */

/*
 * USB support (currently only works with D-cache off)
 */
#if defined(CONFIG_CMD_USB)
#define CONFIG_USB_OHCI
#define CONFIG_USB_KEYBOARD
#define CONFIG_USB_STORAGE
#define CONFIG_DOS_PARTITION
#endif /* CONFIG_CMD_USB */

/*
 * Miscellaneous configurable options
 */
#define CONFIG_SYS_LONGHELP		/* undef to save memory */
#define CONFIG_SYS_PROMPT		"FS2410# "
#define CONFIG_SYS_CBSIZE		256
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT)+16)
#define CONFIG_SYS_MAXARGS		16
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE

#define CONFIG_SYS_MEMTEST_START	0x30800000	/* memtest works on */
#define CONFIG_SYS_MEMTEST_END		0x31800000	/* 16 MB in DRAM */
#define CONFIG_SYS_ALT_MEMTEST

#define CONFIG_SYS_LOAD_ADDR		0x30800000

#define CONFIG_SYS_HZ			1000

/* 
 * valid baudrates 
 */
#define CONFIG_BAUDRATE			115200
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

/* 
 * Support additional compression methods
 */
//#define CONFIG_BZIP2
#define CONFIG_LZO
//#define CONFIG_LZMA

/*-----------------------------------------------------------------------
 * Stack sizes
 *
 * The stack sizes are set up in start.S using the settings below
 */
#define CONFIG_STACKSIZE		(128*1024)	/* regular stack */
#ifdef CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ		(4*1024)	/* IRQ stack */
#define CONFIG_STACKSIZE_FIQ		(4*1024)	/* FIQ stack */
#endif

/*-----------------------------------------------------------------------
 * Physical Memory Map
 */
#define CONFIG_NR_DRAM_BANKS		1          /* we have 1 bank of DRAM */
#define PHYS_SDRAM_1			0x30000000 /* SDRAM Bank #1 */
#define PHYS_SDRAM_1_SIZE		0x04000000 /* 64 MB */

/*-----------------------------------------------------------------------
 * FLASH and environment organization
 */
#define PHYS_FLASH_1			0x00000000 /* Flash Bank #0 */
#define CONFIG_SYS_FLASH_BASE		PHYS_FLASH_1
#define CONFIG_SYS_FLASH_CFI
#define CONFIG_FLASH_CFI_DRIVER
#define CONFIG_FLASH_CFI_LEGACY
#define CONFIG_SYS_FLASH_LEGACY_2Mx16
#define CONFIG_FLASH_SHOW_PROGRESS	45

#define CONFIG_SYS_MAX_FLASH_BANKS	1
#define CONFIG_SYS_FLASH_BANKS_LIST     { CONFIG_SYS_FLASH_BASE }
#define CONFIG_SYS_MAX_FLASH_SECT	(512)

#define CONFIG_ENV_IS_IN_NAND
#if defined(CONFIG_ENV_IS_IN_FLASH)
#define CONFIG_ENV_SIZE			0x00020000
#define CONFIG_ENV_ADDR			(CONFIG_SYS_FLASH_BASE + 0x00E0000)
#elif defined(CONFIG_ENV_IS_IN_NAND)
#define CONFIG_ENV_SIZE			0x00020000
#define CONFIG_ENV_OFFSET		0x000E0000
#endif /* CONFIG_ENV_IS_IN_FLASH */

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE

/*
 * Size of malloc() pool
 * BZIP2 / LZO / LZMA need a lot of RAM
 */
#define CONFIG_SYS_MALLOC_LEN		(4 * 1024 * 1024)

#define CONFIG_SYS_MONITOR_LEN		(448 * 1024)
#define CONFIG_SYS_MONITOR_BASE		CONFIG_SYS_FLASH_BASE

/*
 * NAND configuration
 */
#if defined(CONFIG_CMD_NAND)
#define CONFIG_NAND_S3C2410
#define CONFIG_SYS_S3C2410_NAND_HWECC
#define CONFIG_SYS_MAX_NAND_DEVICE	1
#define NAND_MAX_CHIPS			1
#define CONFIG_SYS_NAND_BASE		0x4E000000
#define CONFIG_NAND_BOOT
#endif /* CONFIG_CMD_NAND */

#if defined(CONFIG_NAND_BOOT)
#define CONFIG_NAND_BOOT_S3C2410
#define CONFIG_SYS_NO_FLASH
#undef  CONFIG_CMD_FLASH
#undef  CONFIG_CMD_IMLS
#undef  CONFIG_SYS_FLASH_CFI
#undef  CONFIG_FLASH_CFI_DRIVER
#undef  CONFIG_FLASH_CFI_LEGACY
#define CONFIG_SYS_NAND_PAGE_SIZE	0x00000200
#define CONFIG_SYS_NAND_PAGE_COUNT	32
#define CONFIG_SYS_NAND_BLOCK_SIZE	0x00004000
#define CONFIG_SYS_TEXT_BASE		0x31000000
#else
#define CONFIG_SYS_TEXT_BASE		0x00000000
#endif /* CONFIG_NAND_BOOT */

/*
 * File system
 */
//#define CONFIG_CMD_FAT
//#define CONFIG_CMD_EXT2
#define CONFIG_CMD_UBI
#define CONFIG_CMD_UBIFS
#define CONFIG_CMD_MTDPARTS
#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS
//#define CONFIG_YAFFS2
#define CONFIG_RBTREE

#define MTDIDS_DEFAULT			"nand0=fs2410-nand"
#define MTDPARTS_DEFAULT		"mtdparts=fs2410-nand:896k(u-boot),128k(env),3m(kernel),40m(root),-(user)"	

/* additions for new relocation code, must be added to all boards */
#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_SDRAM_BASE + 0x1000 - GENERATED_GBL_DATA_SIZE)

#define CONFIG_BOARD_EARLY_INIT_F

#endif /* __CONFIG_H */
