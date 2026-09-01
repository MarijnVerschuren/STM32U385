//
// Created by marijn on 9/1/26.
//

#include "TIM.h"



/*!<
 * static
 * */
static inline uint32_t TIM_to_update_IRQn(TIM_t* tim) {
	switch ((uint32_t)tim) {
	case TIM1_BASE: return TIM1_UP_IRQn;
	case TIM8_BASE: return TIM8_UP_IRQn;
	case TIM12_BASE: return TIM12_IRQn;
	}
	if (((uint32_t)tim) > TIM12_BASE) {
		return (((uint32_t)tim >> 10) & 0x3) + TIM15_IRQn;
	}	return (((uint32_t)tim >> 10) & 0x7) + TIM2_IRQn;
}



/*!<
 * init / enable / disable
 * */
void config_TIM(TIM_t* tim, uint32_t prescaler, uint32_t limit) {
	enable_dev(tim);
	tim->PSC = prescaler;
	tim->ARR = limit;
	tim->EGR = 0x00000001UL;	// update shadow registers
}

void disable_TIM(TIM_t* tim) { disable_dev(tim); }



/*!<
 * actions
 * */
void start_TIM(TIM_t* tim) { tim->CR1 |= 0x1UL; }
void stop_TIM(TIM_t* tim) { tim->CR1 &= ~0x1UL; }

void delay_TIM(TIM_t* tim, uint32_t count) {
	uint32_t start = tim->CNT;
	while (tim->CNT - start < count);
}



/*!<
 * irq
 * */
void start_TIM_update_irq(TIM_t* tim) {
	uint32_t irqn = TIM_to_update_IRQn(tim);
	NVIC_enable_IRQ(irqn);
	tim->DIER |= 0x1UL;
}

void stop_TIM_update_irq(TIM_t* tim) {
	NVIC_disable_IRQ(TIM_to_update_IRQn(tim));
	tim->DIER &= ~0x1UL;
}

