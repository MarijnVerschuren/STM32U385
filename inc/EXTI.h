//
// Created by marijn on 9/19/24.
//

#ifndef STM32U385_EXTI_H
#define STM32U385_EXTI_H
#include "GPIO.h"
#include "NVIC.h"



/*!< types */
typedef enum {
	EXTI_TRIG_RISING =		0b01UL << 0U,
	EXTI_TRIG_FALLING =		0b01UL << 1U
} EXTI_TRIG_t;

typedef enum {
	EXTI_GEN_IRQ =			0b01UL << 2U,
	EXTI_GEN_EVENT =		0b01UL << 3U
} EXTI_GEN_t;


/*!< misc */
IRQn_t EXTI_to_IRQn(uint8_t EXTI_line);

/*!< init / enable / disable */
void config_EXTI(uint8_t EXTI_line, uint32_t flags);
void config_EXTI_GPIO(GPIO_t* EXTI_port, uint8_t EXTI_pin, uint32_t flags);
void start_EXTI(uint8_t EXTI_line);
void stop_EXTI(uint8_t EXTI_line);


#endif //STM32U385_EXTI_H
