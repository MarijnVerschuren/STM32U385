#include "EXTI.h"
#include "GPIO.h"
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
	__asm("nop");
}


/*!<
 * app
 * */
int main(void) {
	config_GPIO(GPIOA, 15, GPIO_output | GPIO_open_drain);
	config_EXTI_GPIO(GPIOA, 0, EXTI_TRIG_FALLING | EXTI_GEN_IRQ);

	start_EXTI(0);

	for (;;) {
		for (volatile uint32_t i = 0; i < 0x7FFFF; i++) { __asm("nop"); }
		GPIO_toggle(GPIOA, 15);
	}
}
