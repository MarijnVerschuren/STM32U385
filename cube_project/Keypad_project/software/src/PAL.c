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
extern TIM_HandleTypeDef htim1;
extern UART_HandleTypeDef huart3;
extern PCD_HandleTypeDef hpcd_USB_DRD_FS;




void GPIO_toggle(void* port, uint8_t pin) {
	HAL_GPIO_TogglePin(port, 0b1 << pin);
}

void delay_ms(uint64_t ms) {
	HAL_Delay(ms);
}

uint32_t USART_write(void* usart, const uint8_t* buffer, uint32_t size, uint32_t timeout) {
    HAL_UART_Transmit(usart, buffer, size, timeout);
}

uint32_t USART_read(void* usart, uint8_t* buffer, uint32_t size, uint32_t timeout) {
    HAL_UART_Receive(usart, buffer, size, timeout);
}
