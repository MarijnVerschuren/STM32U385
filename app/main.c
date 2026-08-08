#include "EXTI.h"
#include "GPIO.h"
#include "base.h"
#include "periph.h"
#include "NVIC.h"
#include "sys.h"


/*!<
 * defines
 * */


/*!<
 * IRQ
 * */
void EXTI0_handler(void) {
	EXTI->FPR |= 0b1UL;
	__asm volatile("nop");
}


/*!<
 * app
 * */
int main(void) {
	config_GPIO(GPIOA, 15, GPIO_output | GPIO_open_drain);

	config_EXTI_GPIO(GPIOA, 0, GPIO_pull_up, EXTI_FALLING | EXTI_IRQ);

	NVIC_set_IRQ_priority(EXTI0_IRQn, 0);
	NVIC_enable_IRQ(EXTI0_IRQn);

	for (;;) {
		for (volatile uint32_t i = 0; i < 0x7FFFF; i++) { __asm("nop"); }
		GPIO_toggle(GPIOA, 15);
		//NVIC_set_IRQ_pending(EXTI0_IRQn);
	}
}
