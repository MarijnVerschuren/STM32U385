#include "EXTI.h"
#include "GPIO.h"
#include "NVIC.h"
#include "TIM.h"
#include "base.h"
#include "periph.h"
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

void TIM1_UP_handler(void) {
	TIM1->SR &= ~0b1UL;
	__asm volatile("nop");
}


/*!<
 * app
 * */
int main(void) {
	sys_init();

	config_GPIO(GPIOA, 15, GPIO_output | GPIO_open_drain);

	config_EXTI_GPIO(GPIOA, 0, GPIO_pull_up, EXTI_FALLING | EXTI_IRQ);
	NVIC_set_IRQ_priority(EXTI0_IRQn, 0);
	NVIC_enable_IRQ(EXTI0_IRQn);

	config_TIM(TIM1, 0, 96*100);	// 1/100 MHz
	start_TIM_update_irq(TIM1);
	NVIC_set_IRQ_priority(TIM1_UP_IRQn, 1);
	NVIC_enable_IRQ(TIM1_UP_IRQn);
	start_TIM(TIM1);

	// TODO zig!
	//app();

	for (;;) {
		delay_ms(200);
		GPIO_toggle(GPIOA, 15);
	}
}
