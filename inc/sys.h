//
// Created by marijn on 9/9/24.
//

#ifndef STM32U385_SYS_H
#define STM32U385_SYS_H
#include "periph.h"



/*!<
 * constants
 * */
extern const uint32_t HSI_clock_frequency;
extern const uint32_t HSI48_clock_frequency;
extern const uint32_t LSE_clock_frequency;



/*!<
 * clock variables
 * */
extern uint32_t SYS_clock_frequency;

volatile extern uint64_t tick;



/*!<
 * functions
 * */
extern void delay_ms(uint64_t ms);



/*!<
 * config functions
 * */
void set_SYS_tick_config(uint8_t interrupt_enable);



#endif //STM32U385_SYS_H
