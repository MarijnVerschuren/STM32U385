//
// Created by marijn on 9/10/24.
//
#include "sys.h"



/*!<
 * constants
 * */
const uint32_t	HSI_clock_frequency =	16000000;
const uint32_t	HSI48_clock_frequency =	48000000;
const uint32_t	HSE_clock_frequency =	25000000;
const uint32_t	LSE_clock_frequency =	32768;



/*!<
 * clock variables
 * */
uint32_t SYS_clock_frequency =		12000000;
uint32_t AHB_clock_frequency[2] =	{12000000, 12000000};
uint32_t APB_clock_frequency[3] =	{12000000, 12000000, 12000000};



/*!<
 * config functions
 * */
void sys_init() {
	uint32_t tmp;
	while (!(RCC->CR & (0x1UL << (2UL))));						// wait until MSIS ready

	RCC->AHB1ENR1 |= 0b1UL << 8;								// enable FLASH
	RCC->AHB1ENR2 |= 0b1UL << 2;								// enable PWR

    tmp = RCC->CFGR[3] & (~0xF003UL);							// clear EPOD cfg
    tmp |= ((0b0000UL << 12) | (0b01UL));						// MSIS source, div 1
    RCC->CFGR[3] = tmp;											// write EPOD cfg

	PWR->VOS |= (0b1UL << 8);									// enable EPOD boost
	while (!(PWR->VOS & (0b1UL << 24)));						// wait until EPOD boost enabled

	tmp = (PWR->VOS & ~0x3UL);									// clear R2, R1 enable
	tmp |= PWR_VOS_1 << 0;										// set voltage scale 1
	PWR->VOS = tmp;												// write setting
	while (!(PWR->VOS & (PWR_VOS_1 << 16)));					// wait until ready

	FLASH->ACR = (FLASH->ACR & ~0xFUL) | FLASH_WS3;				// set 3 CPU wait states for flash read
	PWR->DBPR = 0b1UL;											// write access to backup domain enabled

	RCC->BDCR = (RCC->BDCR & ~(0b11 << 3)) | (0b01 << 3);		// set LSE med-low drive capability

	RCC->CR |= (0b1UL << 14);									// HSI48 enable
	while (!(RCC->CR & (0b1UL << 15)));							// wait until HSI48 enabled

	RCC->BDCR |= (0b1UL << 0);									// LSE enable
	while (!(RCC->BDCR & (0b1UL << 1)));						// wait until LSE enabled

	tmp = RCC->ICSCR[0] & ~((0b1UL << 31) | (0x3UL << 29));		// clear MSIS cfg
	tmp |= ((0b1UL << 23) | (0b0UL << 31) | (0x0UL << 29));		// set MSIS to 96MHz
	RCC->ICSCR[0] = tmp;										// write cfg

	SYS_clock_frequency = 96000000;
	AHB_clock_frequency[0] = 96000000;
	AHB_clock_frequency[1] = 96000000;
	APB_clock_frequency[0] = 96000000;
	APB_clock_frequency[1] = 96000000;
	APB_clock_frequency[2] = 96000000;

	set_SYS_tick_config(1);
}

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

