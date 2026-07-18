#include "PAL.h"

#include "main.h"
#include "app_usbx.h"



void GPIO_toggle(void* port, uint8_t pin) {
	HAL_GPIO_TogglePin(port, 0b1 << pin);
}

void delay_ms(uint64_t ms) {
	HAL_Delay(ms);
}
