#include "PAL.h"

#include "main.h"
#include "app_usbx.h"



extern CRC_HandleTypeDef hcrc;
extern HASH_HandleTypeDef hhash;
extern LPTIM_HandleTypeDef hlptim2;
extern RNG_HandleTypeDef hrng;
extern RTC_HandleTypeDef hrtc;
extern MMC_HandleTypeDef hmmc1;
extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi2;
//extern TIM_HandleTypeDef htim1;
extern UART_HandleTypeDef huart3;
extern PCD_HandleTypeDef hpcd_USB_DRD_FS;

extern UX_SLAVE_CLASS_HID* HID_keyboard;


static inline UART_HandleTypeDef* USART_to_handle(void* usart) {
	switch ((uint32_t)usart) {
	case (uint32_t)USART3: return &huart3;
	}
	return NULL;
}






void GPIO_toggle(void* port, uint8_t pin) {
	HAL_GPIO_TogglePin(port, 0b1 << pin);
}

void delay_ms(uint64_t ms) {
	HAL_Delay(ms);
}

uint64_t get_tick(void) {
	return HAL_GetTick();
}

uint32_t USART_write(void* usart, const uint8_t* buffer, uint32_t size, uint32_t timeout) {
    HAL_UART_Transmit(USART_to_handle(usart), buffer, size, timeout);
}

uint32_t USART_read(void* usart, uint8_t* buffer, uint32_t size, uint32_t timeout) {
    HAL_UART_Receive(USART_to_handle(usart), buffer, size, timeout);
}


void HID_run_tasks(void) {
	ux_device_stack_tasks_run();
}

void HID_send_msg(uint8_t msg[8]) {
	UX_SLAVE_CLASS_HID_EVENT event;
	event.ux_device_class_hid_event_length = 8;
	for (uint8_t i = 0; i < 8; i++) {
		event.ux_device_class_hid_event_buffer[i] = msg[i];
	}
	ux_device_class_hid_event_set(HID_keyboard, &event);
}
