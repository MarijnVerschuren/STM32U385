//
// Created by marijn on 9/1/26.
//

#ifndef STM32U385_TIM_H
#define STM32U385_TIM_H
#include "periph.h"
#include "base.h"
#include "NVIC.h"



/*!< init / enable / disable */
void config_TIM(TIM_t* tim, uint32_t prescaler, uint32_t limit);
void disable_TIM(TIM_t* tim);
/*!< actions */
void start_TIM(TIM_t* tim);
void stop_TIM(TIM_t* tim);
void delay_TIM(TIM_t* tim, uint32_t count);
/*!< irq */
void start_TIM_update_irq(TIM_t* tim);
void stop_TIM_update_irq(TIM_t* tim);


#endif //STM32U385_TIM_H
