#pragma once

#include "base.h"
#include "stm32u385xx.h"

#include <stdint.h>
#include <malloc.h>
#include <stdio.h>



#ifdef __cplusplus
extern "C" {
#endif



// HAL -> project
void GPIO_toggle(void* port, uint8_t pin);
void delay_ms(uint64_t ms);
uint64_t get_tick(void);
uint32_t USART_write(void* usart, const uint8_t* buffer, uint32_t size, uint32_t timeout);
uint32_t USART_read(void* usart, uint8_t* buffer, uint32_t size, uint32_t timeout);


void HID_run_tasks(void);
void HID_send_msg(uint8_t msg[8]);


// project -> HAL
void key_scan_tick_handler(void);
void keypad_main(void);




#ifdef __cplusplus
}
#endif
