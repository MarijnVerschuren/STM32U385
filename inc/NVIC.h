//
// Created by marijn on 9/19/24.
//

#ifndef STM32U385_NVIC_H
#define STM32U385_NVIC_H
#include "periph.h"


/*!<
 * types
 * */
typedef enum {
	/*!<	[ARM cortex-M33 interrupts]		*//*!<==================================*/
	reset_IRQn					= -15,		/*!< reset                              */
	NMI_IRQn					= -14,		/*!< non maskable interrupt             */
	hard_fault_IRQn				= -13,		/*!< hard fault                         */
	mem_fault_IRQn				= -12,		/*!< memory management                  */
	bus_fault_IRQn				= -11,		/*!< pre-fetch, memory access fault     */
	exception_IRQn				= -10,		/*!< usage fault                        */
	secure_fault_IRQn			= -9,		/*!< secure fault                       */
	SVC_IRQn					= -5,		/*!< supervisor call                    */
	debug_IRQn					= -4,		/*!< debug monitor                      */
	pending_SV_IRQn				= -2,		/*!< pend request for system service    */
	sys_tick_IRQn				= -1,		/*!< sys tick                           */
	/*!<	[STM32U385 interrupts]			*//*!<==================================*/
	WWDG_IRQn					= 0,		/*!< window watchdog                    */
	PVD_PVM_IRQn				= 1,		/*!< PVD / PVM, EXTI[16, 19-22]         */
	RTC_IRQn					= 2,		/*!< RTC non-secure                     */
	RTC_sec_IRQn				= 3,		/*!< RTC secure                         */
	TAMP_IRQn					= 4,		/*!< tamper                             */
	RAMCFG_IRQn					= 5,		/*!< RAM configuration                  */
	FLASH_IRQn					= 6,		/*!< flash non-secure                   */
	FLASH_sec_IRQn				= 7,		/*!< flash secure                       */
	GTZC_IRQn					= 8,		/*!< GTZC                               */
	RCC_IRQn					= 9,		/*!< RCC non-secure                     */
	RCC_sec_IRQn				= 10,		/*!< RCC secure                         */
	EXTI0_IRQn					= 11,		/*!< EXTI0                              */
	EXTI1_IRQn					= 12,		/*!< EXTI1                              */
	EXTI2_IRQn					= 13,		/*!< EXTI2                              */
	EXTI3_IRQn					= 14,		/*!< EXTI3                              */
	EXTI4_IRQn					= 15,		/*!< EXTI4                              */
	EXTI5_IRQn					= 16,		/*!< EXTI5                              */
	EXTI6_IRQn					= 17,		/*!< EXTI6                              */
	EXTI7_IRQn					= 18,		/*!< EXTI7                              */
	EXTI8_IRQn					= 19,		/*!< EXTI8                              */
	EXTI9_IRQn					= 20,		/*!< EXTI9                              */
	EXTI10_IRQn					= 21,		/*!< EXTI10                             */
	EXTI11_IRQn					= 22,		/*!< EXTI11                             */
	EXTI12_IRQn					= 23,		/*!< EXTI12                             */
	EXTI13_IRQn					= 24,		/*!< EXTI13                             */
	EXTI14_IRQn					= 25,		/*!< EXTI14                             */
	EXTI15_IRQn					= 26,		/*!< EXTI15                             */
	IWDG_IRQn					= 27,		/*!< independent watchdog               */
	AES_sec_IRQn				= 28,		/*!< AES secure                         */
	GPDMA1_CH0_IRQn				= 29,		/*!< GPDMA1_CH0                         */
	GPDMA1_CH1_IRQn				= 30,		/*!< GPDMA1_CH1                         */
	GPDMA1_CH2_IRQn				= 31,		/*!< GPDMA1_CH2                         */
	GPDMA1_CH3_IRQn				= 32,		/*!< GPDMA1_CH3                         */
	GPDMA1_CH4_IRQn				= 33,		/*!< GPDMA1_CH4                         */
	GPDMA1_CH5_IRQn				= 34,		/*!< GPDMA1_CH5                         */
	GPDMA1_CH6_IRQn				= 35,		/*!< GPDMA1_CH6                         */
	GPDMA1_CH7_IRQn				= 36,		/*!< GPDMA1_CH7                         */
	ADC1_IRQn					= 37,		/*!< ADC1                               */
	DAC1_IRQn					= 38,		/*!< DAC1                               */
	FDCAN1_CH0_IRQn				= 39,		/*!< FDCAN1_IT0                         */
	FDCAN1_CH1_IRQn				= 40,		/*!< FDCAN1_IT1                         */
	TIM1_BRK_IRQn				= 41,		/*!< TIM1 break, transition/index error */
	TIM1_UP_IRQn				= 42,		/*!< TIM1 update                        */
	TIM1_TRG_COM_IRQn			= 43,		/*!< TIM1 trig/commut, dir change, idx  */
	TIM1_CC_IRQn				= 44,		/*!< TIM1 capture compare               */
	TIM2_IRQn					= 45,		/*!< TIM2                               */
	TIM3_IRQn					= 46,		/*!< TIM3                               */
	TIM4_IRQn					= 47,		/*!< TIM4                               */
	TIM6_IRQn					= 49,		/*!< TIM6                               */
	TIM7_IRQn					= 50,		/*!< TIM7                               */
	TIM12_IRQn					= 51,		/*!< TIM12                              */
	I3C1_EV_IRQn				= 53,		/*!< I3C1 event                         */
	I3C1_ER_IRQn				= 54,		/*!< I3C1 error                         */
	I2C1_EV_IRQn				= 55,		/*!< I2C1 event                         */
	I2C1_ER_IRQn				= 56,		/*!< I2C1 error                         */
	I2C2_EV_IRQn				= 57,		/*!< I2C2 event                         */
	I2C2_ER_IRQn				= 58,		/*!< I2C2 error                         */
	SPI1_IRQn					= 59,		/*!< SPI1                               */
	SPI2_IRQn					= 60,		/*!< SPI2                               */
	USART1_IRQn					= 61,		/*!< USART1                             */
	USART3_IRQn					= 63,		/*!< USART3                             */
	UART4_IRQn					= 64,		/*!< UART4                              */
	UART5_IRQn					= 65,		/*!< UART5                              */
	LPUART1_IRQn				= 66,		/*!< LPUART1                            */
	LPTIM1_IRQn					= 67,		/*!< LPTIM1                             */
	LPTIM2_IRQn					= 68,		/*!< LPTIM2                             */
	TIM15_IRQn					= 69,		/*!< TIM15                              */
	TIM16_IRQn					= 70,		/*!< TIM16                              */
	TIM17_IRQn					= 71,		/*!< TIM17                              */
	COMP_IRQn					= 72,		/*!< COMP1/2                            */
	USB_FS_IRQn					= 73,		/*!< USB FS                             */
	CRS_IRQn					= 74,		/*!< clock recovery system              */
	OCTOSPI1_IRQn				= 76,		/*!< octo-SPI1                          */
	SDMMC1_IRQn					= 78,		/*!< SDMMC1                             */
	GPDMA1_CH8_IRQn				= 80,		/*!< GPDMA1_CH8                         */
	GPDMA1_CH9_IRQn				= 81,		/*!< GPDMA1_CH9                         */
	GPDMA1_CH10_IRQn			= 82,		/*!< GPDMA1_CH10                        */
	GPDMA1_CH11_IRQn			= 83,		/*!< GPDMA1_CH11                        */
	I2C3_EV_IRQn				= 88,		/*!< I2C3 event                         */
	I2C3_ER_IRQn				= 89,		/*!< I2C3 error                         */
	SAI1_IRQn					= 90,		/*!< SAI1                               */
	TSC_IRQn					= 92,		/*!< TSC                                */
	AES_IRQn					= 93,		/*!< AES                                */
	RNG_IRQn					= 94,		/*!< RNG                                */
	FPU_IRQn					= 95,		/*!< FPU                                */
	HASH_IRQn					= 96,		/*!< HASH                               */
	PKA_IRQn					= 97,		/*!< PKA                                */
	LPTIM3_IRQn					= 98,		/*!< LPTIM3                             */
	SPI3_IRQn					= 99,		/*!< SPI3                               */
	I3C2_EV_IRQn				= 100,		/*!< I3C2 event                         */
	I3C2_ER_IRQn				= 101,		/*!< I3C2 error                         */
	TIM8_BRK_IRQn				= 102,		/*!< TIM8 break, transition, idx error  */
	TIM8_UP_IRQn				= 103,		/*!< TIM8 update                        */
	TIM8_TRG_IRQn				= 104,		/*!< TIM8 trigger, dir change, index    */
	TIM8_CC_IRQn				= 105,		/*!< TIM8 capture compare               */
	ICACHE_IRQn					= 107,		/*!< instruction cache                  */
	LCD_IRQn					= 109,		/*!< LCD                                */
	LPTIM4_IRQn					= 110,		/*!< LPTIM4                             */
	ADF1_IRQn					= 112,		/*!< AFD1                               */
	ADC2_IRQn					= 113,		/*!< ADC2                               */
	FDCAN2_IT0_IRQn				= 114,		/*!< FDCAN2 interrupt 0                 */
	FDCAN2_IT1_IRQn				= 115,		/*!< FDCAN2 interrupt 1                 */
	I2C4_EV_IRQn				= 116,		/*!< I2C4 event                         */
	I2C4_ER_IRQn				= 117,		/*!< I2C4 error                         */
	SPI4_IRQn					= 119,		/*!< SPI4                               */
	PWR_IRQn					= 123,		/*!< PWR non-secure                     */
	PWR_sec_IRQn				= 124		/*!< PWR secure                         */
} IRQn_t;									/*!<====================================*/


/*!<
 * init
 * */
extern void NVIC_enable_IRQ(IRQn_t irqn);
extern void NVIC_disable_IRQ(IRQn_t irqn);
extern void NVIC_set_IRQ_priority(IRQn_t irqn, uint8_t priority);	// TODO: <0 IRQns!!!
extern void NVIC_set_IRQ_pending(IRQn_t irqn);

// static inline uint32_t NVIC_get_priority_grouping(void) {
// 	return ((uint32_t)((SCB->AIRCR & (7UL << 8U)) >> 8U));
// }
//
// static inline uint32_t NVIC_encode_priority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority) {
//   uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);   /* only values 0..7 are used          */
//   uint32_t PreemptPriorityBits;
//   uint32_t SubPriorityBits;
//
//   PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(4U)) ? (uint32_t)(4U) : (uint32_t)(7UL - PriorityGroupTmp);
//   SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(4U)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(4U));
//
//   return (
//            ((PreemptPriority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
//            ((SubPriority     & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL)))
//          );
// }


#endif //STM32U385_NVIC_H
