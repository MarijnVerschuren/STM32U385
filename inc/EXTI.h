//
// Created by marijn on 9/19/24.
//

#ifndef STM32U385_EXTI_H
#define STM32U385_EXTI_H
#include "GPIO.h"
#include "NVIC.h"



/*!< types */
typedef enum {
	EXTI_RISING =		0b01UL << 0U,
	EXTI_FALLING =		0b01UL << 1U,
	EXTI_IRQ =			0b01UL << 2U,
	EXTI_EVENT =		0b01UL << 3U
} EXTI_FLAG_t;


/*!< misc */
IRQn_t EXTI_to_IRQn(uint8_t EXTI_line);

/*!< init / enable / disable */
void config_EXTI(uint8_t EXTI_line, uint32_t flags);
void config_EXTI_GPIO(GPIO_t* EXTI_port, uint8_t EXTI_pin, uint32_t GPIO_pull_flags, uint32_t EXTI_flags);



#endif //STM32U385_EXTI_H
