#pragma once

#include "base.h"

#include <stdint.h>
#include <malloc.h>
#include <stdio.h>




#ifdef __cplusplus
extern "C" {
#endif



// HAL -> project
void GPIO_toggle(void* port, uint8_t pin);
void delay_ms(uint64_t ms);
uint32_t USART_write(void* usart, const uint8_t* buffer, uint32_t size, uint32_t timeout);
uint32_t USART_read(void* usart, uint8_t* buffer, uint32_t size, uint32_t timeout);


// project -> HAL
void key_scan_tick_handler(void);
void keypad_main(void);




#ifdef __cplusplus
}
#endif
