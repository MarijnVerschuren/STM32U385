const mcu = @cImport({
    @cInclude("EXTI.h");
    @cInclude("GPIO.h");
    @cInclude("NVIC.h");
    @cInclude("TIM.h");
    @cInclude("base.h");
    @cInclude("periph.h");
    @cInclude("sys.h");
});



///////
// IRQ
//
export fn EXTI0_handler() void {
    mcu.EXTI.*.FPR |= 0b1;
    asm volatile ("nop");
}

export fn TIM1_UP_handler() void {
	mcu.TIM1.*.SR &= 0xFFFFFFFE;
    asm volatile ("nop");
}



///////
// app
//
export fn main() noreturn {
    mcu.sys_init();
	// config LED
	mcu.config_GPIO(mcu.GPIOA, 15, mcu.GPIO_output | mcu.GPIO_open_drain);
	// config rotary SW
	mcu.config_EXTI_GPIO(mcu.GPIOA, 0, mcu.GPIO_pull_up, mcu.EXTI_FALLING | mcu.EXTI_IRQ);
	mcu.NVIC_set_IRQ_priority(mcu.EXTI0_IRQn, 0);
	mcu.NVIC_enable_IRQ(mcu.EXTI0_IRQn);
	// config TIM1
	mcu.config_TIM(mcu.TIM1, 0, 96*100);	// 1/100 MHz
	mcu.start_TIM_update_irq(mcu.TIM1);
	mcu.NVIC_set_IRQ_priority(mcu.TIM1_UP_IRQn, 1);
	mcu.NVIC_enable_IRQ(mcu.TIM1_UP_IRQn);

	// start TIM1
	mcu.start_TIM(mcu.TIM1);

    while(true) {
		mcu.delay_ms(40);
		mcu.GPIO_toggle(mcu.GPIOA, 15);
	}
}