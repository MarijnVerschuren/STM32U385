#include "EXTI.h"



/*!< static */
static inline void EXTI_reset(uint8_t EXTI_line) {
	EXTI->RTSR &= ~(0b1UL << EXTI_line);
	EXTI->FTSR &= ~(0b1UL << EXTI_line);
	EXTI->IMR &= ~(0b1UL << EXTI_line);
	EXTI->EMR &= ~(0b1UL << EXTI_line);
	EXTI->EXTICR[EXTI_line >> 2U] &= ~(0xFFUL << ((EXTI_line & 0b11U) << 3U));
}


/*!< misc */
IRQn_t EXTI_to_IRQn(uint8_t EXTI_line) {
	if (EXTI_line < 15)	{ return EXTI0_IRQn + EXTI_line; }
	switch (EXTI_line) {
	case 16: return PVD_PVM_IRQn;
	// TODO: 17 - 18
	default:
		if (EXTI_line < 22) { return PVD_PVM_IRQn; }
	}
	return reset_IRQn;	// TODO: other EXTI lines
}


/*!< init / enable / disable */
void config_EXTI(uint8_t EXTI_line, uint32_t flags) {
	EXTI_reset(EXTI_line);
    EXTI->RTSR |=	((flags >> 0) & 0b1UL) << EXTI_line;
    EXTI->FTSR |=	((flags >> 1) & 0b1UL) << EXTI_line;
    EXTI->IMR |=	((flags >> 2) & 0b1UL) << EXTI_line;
    EXTI->EMR |=	((flags >> 3) & 0b1UL) << EXTI_line;
}

void config_EXTI_GPIO(GPIO_t* EXTI_port, uint8_t EXTI_pin, uint32_t flags) {
	config_EXTI(EXTI_pin, flags);
	EXTI->EXTICR[EXTI_pin >> 2U] = GPIO_to_int(EXTI_port) << ((EXTI_pin & 0b11U) << 3U);
}

void start_EXTI(uint8_t EXTI_line) {
	NVIC_enable_IRQ(EXTI_to_IRQn(EXTI_line));
}

void stop_EXTI(uint8_t EXTI_line) {
	NVIC_disable_IRQ(EXTI_to_IRQn(EXTI_line));
}