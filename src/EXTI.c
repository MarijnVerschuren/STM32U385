#include "EXTI.h"



/*!< static */
static inline void EXTI_reset(uint8_t EXTI_line) {
	EXTI->RTSR &= ~(0b1UL << EXTI_line);
	EXTI->FTSR &= ~(0b1UL << EXTI_line);
	EXTI->IMR &= ~(0b1UL << EXTI_line);
	EXTI->EMR &= ~(0b1UL << EXTI_line);
	if (EXTI_line > 15) { return; }
	EXTI->EXTICR[EXTI_line >> 2U] &= ~(0xFFUL << ((EXTI_line & 0b11U) << 3U));
}


/*!< misc */
IRQn_t EXTI_to_IRQn(uint8_t EXTI_line) {
	if (EXTI_line < 15)	{ return EXTI0_IRQn + EXTI_line; }
	if (EXTI_line == 16) { return PVD_PVM_IRQn; }
	if (EXTI_line < 19) { return COMP_IRQn; }
	return PVD_PVM_IRQn;
}


/*!< init / enable / disable */
void config_EXTI(uint8_t EXTI_line, uint32_t flags) {
	EXTI_reset(EXTI_line);
    EXTI->RTSR |=	((flags >> 0) & 0b1UL) << EXTI_line;
    EXTI->FTSR |=	((flags >> 1) & 0b1UL) << EXTI_line;
    EXTI->IMR |=	((flags >> 2) & 0b1UL) << EXTI_line;
    EXTI->EMR |=	((flags >> 3) & 0b1UL) << EXTI_line;
}

void config_EXTI_GPIO(GPIO_t* EXTI_port, uint8_t EXTI_pin, uint32_t GPIO_pull_flags, uint32_t EXTI_flags) {
	config_GPIO(EXTI_port, EXTI_pin, GPIO_input | GPIO_pull_flags);
	config_EXTI(EXTI_pin, EXTI_flags);
	EXTI->EXTICR[EXTI_pin >> 2U] |= GPIO_to_int(EXTI_port) << ((EXTI_pin & 0b11U) << 3U);
}
