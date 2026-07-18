#pragma once

#include "base.h"
#include "stm32u385xx.h"

#include <stdint.h>
#include <malloc.h>


#ifdef __cplusplus
extern "C" {
#endif




void GPIO_toggle(void* port, uint8_t pin);


void delay_ms(uint64_t ms);


void keypad_main(void);




#ifdef __cplusplus
}
#endif
