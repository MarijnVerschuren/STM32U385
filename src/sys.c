//
// Created by marijn on 9/10/24.
//
#include "sys.h"



/*!<
 * constants
 * */
const uint32_t	HSI_clock_frequency =	16000000;
const uint32_t	HSI48_clock_frequency =	48000000;
const uint32_t	LSE_clock_frequency =	32768;



/*!<
 * clock variables
 * */
uint32_t SYS_clock_frequency =		12000000;



/*!<
 * config functions
 * */
void set_SYS_tick_config(uint8_t interrupt_enable) {
	SYS_TICK->CTRL = 0;
    SYS_TICK->LOAD = (SYS_clock_frequency / 1000UL) - 1UL;
    SYS_TICK->VAL = 0;
    SYS_TICK->CTRL =
        (1UL << 2) |
        (interrupt_enable << 1) |
        (1UL << 0);
	//SCB->SHP[11U] = 0b11110000;
}

