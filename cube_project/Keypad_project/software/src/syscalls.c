#include "PAL.h"


extern UART_HandleTypeDef huart3;



int _write(int file, char *ptr, int len) {
	(void)file;
	USART_write(&huart3, (uint8_t*)ptr, len, HAL_MAX_DELAY);
    return len;
}


int _read(int file, char *ptr, int len) {
	(void)file;
    HAL_UART_Receive(&huart3, (uint8_t*)ptr, 1, HAL_MAX_DELAY);
    return 1;
}
