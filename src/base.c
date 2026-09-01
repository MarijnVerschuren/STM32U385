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
	switch (dev_clk(dev)) {
		case
	}
}

void disable_dev(void* dev) {

}
