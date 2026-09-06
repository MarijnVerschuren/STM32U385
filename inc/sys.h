//
// Created by marijn on 9/9/24.
//

#ifndef STM32U385_SYS_H
#define STM32U385_SYS_H
#include "periph.h"



/*!<
 * types
 * */
typedef enum {
	//==========================================================================+========================================|
	// flash access latency |                          H_CLK (MHz)              |     FLASH in LPM,  H_CLK (MHz)         |
	//      (table 43)      |              voltage range      voltage range     |   voltage range      voltage range     |
	//    in CPU cycles     |__________           1                  2          |          1                  2          |
	FLASH_WS1 =             0b000UL, //    0 < H_CLK ≤ 32     0 < H_CLK ≤ 16    |   0 < H_CLK ≤ 20     0 < H_CLK ≤ 16    |
	FLASH_WS2 =             0b001UL, //    32 < H_CLK ≤ 64    16 < H_CLK ≤ 32   |   20 < H_CLK ≤ 40    16 < H_CLK ≤ 32   |
	FLASH_WS3 =             0b010UL, //    64 < H_CLK ≤ 96    32 < H_CLK ≤ 48   |   40 < H_CLK ≤ 60    32 < H_CLK ≤ 48   |
	FLASH_WS4 =             0b011UL, //           -                  -          |   60 < H_CLK ≤ 80           -          |
	FLASH_WS5 =             0b100UL, //           -                  -          |   80 < H_CLK ≤ 96           -          |
	//==========================================================================+========================================|
} FLASH_WS_t;

typedef enum {
	PWR_VOS_1 =	0b01UL,
	PWR_VOS_2 = 0b10UL
} PWR_VOS_t;




/*!<
 * constants
 * */
extern const uint32_t HSI_clock_frequency;
extern const uint32_t HSI48_clock_frequency;
extern const uint32_t HSE_clock_frequency;
extern const uint32_t LSE_clock_frequency;



/*!<
 * clock variables
 * */
extern uint32_t SYS_clock_frequency;
extern uint32_t AHB_clock_frequency[2];
extern uint32_t APB_clock_frequency[3];

volatile extern uint64_t tick;



/*!<
 * functions
 * */
extern void delay_ms(uint64_t ms);



/*!<
 * config functions
 * */
void sys_init();
void set_SYS_tick_config(uint8_t interrupt_enable);



#endif //STM32U385_SYS_H
