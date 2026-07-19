#include "PAL.h"




int _write(int file, char *ptr, int len) {
	(void)file;
	USART_write(USART3, (uint8_t*)ptr, len, 0xFFFFFFFFU);
    return len;
}


int _read(int file, char *ptr, int len) {
	(void)file;
	USART_read(USART3, (uint8_t*)ptr, 1, 0xFFFFFFFFU);
    return 1;
}
