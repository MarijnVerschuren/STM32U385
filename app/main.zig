const c = @cImport({
    @cInclude("EXTI.h");
    @cInclude("GPIO.h");
    @cInclude("NVIC.h");
    @cInclude("TIM.h");
    @cInclude("base.h");
    @cInclude("periph.h");
    @cInclude("sys.h");
});



export fn main() noreturn {
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

    while(true) {
		delay_ms(100);
		GPIO_toggle(GPIOA, 15);
	}
}