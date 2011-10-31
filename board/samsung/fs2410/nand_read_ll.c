
#include <common.h>

#if defined(CONFIG_NAND_BOOT_S3C2410)
#define __REGb(x) 	(*(volatile unsigned char *)(x)) 
#define __REGi(x) 	(*(volatile ulong  *)(x)) 
#define NF_BASE 	0x4E000000 
#define NFCONF 		__REGi(NF_BASE + 0x00) 
#define NFCMD 		__REGb(NF_BASE + 0x04) 
#define NFADDR 		__REGb(NF_BASE + 0x08) 
#define NFDATA 		__REGb(NF_BASE + 0x0C) 
#define NFSTAT 		__REGb(NF_BASE + 0x10) 
#define BUSY 		1 

#define NFCONF_TWRPH1	7
#define NFCONF_TWRPH0	7
#define NFCONF_TACLS	7
#define NFCONF_nFCE	1
#define NFCONF_ECC	1
#define NFCONF_ENABLE	1

static inline void nand_chip_en (void) { NFCONF &= ~0x0800; }
static inline void nand_chip_di (void) { NFCONF |=  0x0800; }

static inline void wait_idle (void) 
{ 
	int i;  

	while (!(NFSTAT & BUSY)) 
		for (i = 0; i < 10; i++); 
} 

static int nand_read_page (ulong block, ulong page, uchar* dst)
{
	ulong offs;

	nand_chip_en ();

	NFCMD = 0; 
	offs = block * CONFIG_SYS_NAND_BLOCK_SIZE + page * CONFIG_SYS_NAND_PAGE_SIZE;
	NFADDR = (offs >>  0U) & 0xFFU; 
	NFADDR = (offs >>  9U) & 0xFFU; 
	NFADDR = (offs >> 17U) & 0xFFU; 
	NFADDR = (offs >> 25U) & 0xFFU; 
	wait_idle ();

	for (offs = 0; offs < CONFIG_SYS_NAND_PAGE_SIZE; offs++)
		*dst++ = NFDATA & 0xFFU;

	nand_chip_di ();

	return (0);
}

void nand_init_ll (void) 
{
	NFCONF = (NFCONF_TWRPH1 <<  0) | (NFCONF_TWRPH0 <<  4) |
		 (NFCONF_TACLS  <<  8) | (NFCONF_nFCE   << 11) |
		 (NFCONF_ECC    << 12) | (NFCONF_ENABLE << 15);

	nand_chip_en ();

	NFCMD = 0xFF;		/* reset command.	*/
	wait_idle ();

	nand_chip_di ();
}

int nand_read_ll (ulong offs, ulong uboot_size, uchar* dst)
{
	int ret;
	ulong page;
	ulong block;
	ulong last_block;

	/*
 	 * offs has to be aligned to a page address!
	 */
	block = offs / CONFIG_SYS_NAND_BLOCK_SIZE;
	last_block = (offs + uboot_size - 1) / CONFIG_SYS_NAND_BLOCK_SIZE;
	page = (offs % CONFIG_SYS_NAND_BLOCK_SIZE) / CONFIG_SYS_NAND_PAGE_SIZE;

	while (block <= last_block) {
		while (page < CONFIG_SYS_NAND_PAGE_COUNT) {
			ret  = nand_read_page (block, page, dst);
			dst += CONFIG_SYS_NAND_PAGE_SIZE;
			page++;
		}
		page = 0;
		block++;
	}

	return (0);
}

#endif /* CONFIG_NAND_BOOT_S3C2410 */

		
