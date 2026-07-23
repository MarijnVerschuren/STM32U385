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
void GPIO_write(void* port, uint8_t pin, uint8_t val);
void delay_ms(uint64_t ms);
uint64_t get_tick(void);
uint32_t USART_write(void* usart, const uint8_t* buffer, uint32_t size, uint32_t timeout);
uint32_t USART_read(void* usart, uint8_t* buffer, uint32_t size, uint32_t timeout);


void HID_run_tasks(void);
void HID_send_msg(uint8_t msg[8]);


// project -> HAL
void USB_HID_enumerated_callback(void);
void USB_HID_disconnect_callback(void);

void key_scan_tick_handler(void);
void rotary_button_handler(uint8_t dir);	// 0: down, 1: up
void keypad_main(void);




#ifdef __cplusplus
}
#endif
