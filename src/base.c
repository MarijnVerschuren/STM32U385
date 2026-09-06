//
// Created by marijn on 9/1/26.
//
#include "base.h"
#include "periph.h"



/*!<
 * static
 * */
static inline dev_clock_id_t dev_clk(void* dev) {
	if ((uint32_t)dev >= AHB2PERIPH_BASE) { return DEV_CLOCK_AHB2; }
	if ((uint32_t)dev >= APB3PERIPH_BASE) { return DEV_CLOCK_APB3; }
	if ((uint32_t)dev >= AHB1PERIPH_BASE) { return DEV_CLOCK_AHB1; }
	if ((uint32_t)dev >= APB2PERIPH_BASE) { return DEV_CLOCK_APB2; }
	return DEV_CLOCK_APB1;
}



/*!<
 * dev
 * */
void enable_dev(void* dev) {
	uint32_t base = (uint32_t)dev;

	_IO uint32_t* reg;

	switch (dev_clk(dev)) {
		case DEV_CLOCK_AHB1: return; // TODO
		case DEV_CLOCK_AHB2:
			base -= AHB2PERIPH_BASE;
			reg = &RCC->AHB2ENR[base >> 15];
			break;
		case DEV_CLOCK_APB1:
			base -= APB1PERIPH_BASE;
			reg = &RCC->APB1ENR[base >> 15];
			break;
		case DEV_CLOCK_APB2:
			base -= APB2PERIPH_BASE;
			//RCC->APB2ENR |= (0b1UL << ((base >> 10) & 0x1F));
			reg = &RCC->APB2ENR;
			break;
		case DEV_CLOCK_APB3:
			base -= AHB2PERIPH_BASE;
			reg = &RCC->APB3ENR;
			break;
		default: return;
	}

	uint8_t dnum = ((base >> 10) & 0x1F);
	uint32_t flg = (0b1UL << dnum);
	reg[0] |= flg;
}

void disable_dev(void* dev) {
	uint32_t base = (uint32_t)dev;
	_IO uint32_t* reg;
	switch (dev_clk(dev)) {
		case DEV_CLOCK_AHB1: return; // TODO
		case DEV_CLOCK_AHB2:
			base -= AHB2PERIPH_BASE;
			reg = &RCC->AHB2RSTR[base >> 15];
			break;
		case DEV_CLOCK_APB1:
			base -= APB1PERIPH_BASE;
			reg = &RCC->APB1RSTR[base >> 15];
			break;
		case DEV_CLOCK_APB2:
			base -= APB2PERIPH_BASE;
			reg = &RCC->APB2RSTR;
			break;
		case DEV_CLOCK_APB3:
			base -= AHB2PERIPH_BASE;
			reg = &RCC->APB3RSTR;
			break;
		default: return;
	}

	uint8_t dnum = ((base >> 10) & 0x1F);
	uint32_t flg = (0b1UL << dnum);
	(*reg) |= flg;
}
