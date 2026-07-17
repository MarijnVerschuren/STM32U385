.syntax unified
.cpu cortex-m33
.fpu softvfp
.thumb


// objects
.global IVT


.section .vector, "a", %progbits
.type IVT, %object
IVT:
.word	_stack_end
.word	reset_handler
.word	NMI_handler
.word	hard_fault_handler
.word	mem_fault_handler
.word	bus_fault_handler
.word	exception_handler
.word	secure_fault_handler
.word	0
.word	0
.word	0
.word	SVC_handler
.word	debug_handler
.word	0
.word	pending_SV_handler
.word	sys_tick_handler
//.word	WWDG_handler
//.word	PVD_PVM_handler
//.word	RTC_handler
//.word	RTC_sec_handler
//.word	TAMP_handler
//.word	RAMCFG_handler
//.word	FLASH_handler
//.word	FLASH_sec_handler
//.word	GTZC_handler
//.word	RCC_handler
//.word	RCC_sec_handler
//.word	EXTI0_handler
//.word	EXTI1_handler
//.word	EXTI2_handler
//.word	EXTI3_handler
//.word	EXTI4_handler
//.word	EXTI5_handler
//.word	EXTI6_handler
//.word	EXTI7_handler
//.word	EXTI8_handler
//.word	EXTI9_handler
//.word	EXTI10_handler
//.word	EXTI11_handler
//.word	EXTI12_handler
//.word	EXTI13_handler
//.word	EXTI14_handler
//.word	EXTI15_handler
//.word	IWDG_handler
//.word	AES_sec_handler
//.word	GPDMA1_CH0_handler
//.word	GPDMA1_CH1_handler
//.word	GPDMA1_CH2_handler
//.word	GPDMA1_CH3_handler
//.word	GPDMA1_CH4_handler
//.word	GPDMA1_CH5_handler
//.word	GPDMA1_CH6_handler
//.word	GPDMA1_CH7_handler
//.word	ADC1_handler
//.word	DAC1_handler
//.word	FDCAN1_CH0_handler
//.word	FDCAN1_CH1_handler
//.word	TIM1_BRK_handler
//.word	TIM1_UP_handler
//.word	TIM1_TRG_COM_handler
//.word	TIM1_CC_handler
//.word	TIM2_handler
//.word	TIM3_handler
//.word	TIM4_handler
//.word	0
//.word	TIM6_handler
//.word	TIM7_handler
//.word	0
//.word	0
//.word	I3C1_ERR_handler
//.word	I3C1_handler
//.word	I2C1_handler
//.word	I2C1_ERR_handler
//.word	I2C2_handler
//.word	I2C2_ERR_handler
//.word	SPI1_handler
//.word	SPI2_handler
//.word	USART1_handler
//.word	0
//.word	USART3_handler
//.word	UART4_handler
//.word	UART5_handler
//.word	LPUART1_handler
//.word	LPTIM1_handler
//.word	LPTIM2_handler
//.word	TIM15_handler
//.word	TIM16_handler
//.word	TIM17_handler
//.word	COMP_handler
//.word	USB_FS_handler
//.word	CRS_handler
//.word	0
//.word	OCTOSPI1_handler
//.word	0
//.word	SDMMC1_handler
//.word	0
//.word	GPDMA1_CH8_handler
//.word	GPDMA1_CH9_handler
//.word	GPDMA1_CH10_handler
//.word	GPDMA1_CH11_handler
//.word	0
//.word	0
//.word	0
//.word	0
//.word	I2C3_handler
//.word	I2C3_ERR_handler
//.word	SAI1_handler
//.word	0
//.word	TSC_handler
//.word	AES_handler
//.word	RNG_handler
//.word	FPU_handler
//.word	HASH_handler
//.word	PKA_handler
//.word	LPTIM3_handler
//.word	SPI3_handler
//.word	I3C2_ERR_handler
//.word	I3C2_handler
//.word	0
//.word	0
//.word	0
//.word	0
//.word	0
//.word	ICACHE_handler
//.word	0
//.word	0
//.word	LPTIM4_handler
//.word	0
//.word	ADF1_handler
//.word	ADC2_handler
//.word	0
//.word	0
//.word	0
//.word	0
//.word	0
//.word	0
//.word	0
//.word	0
//.word	0
//.word	PWR_handler
//.word	PWR_sec_handler
.size IVT, .-IVT



/*!<
 * functions
 * */
.section .text.default_handler, "ax", %progbits
default_handler:
	bkpt #1
	b default_handler
.size default_handler, .-default_handler



/*!<
 * weak definitions
 * */
.weak NMI_handler
.thumb_set NMI_handler,				default_handler
.weak hard_fault_handler
.thumb_set hard_fault_handler,		default_handler
.weak mem_fault_handler
.thumb_set mem_fault_handler,		default_handler
.weak bus_fault_handler
.thumb_set bus_fault_handler,		default_handler
.weak exception_handler
.thumb_set exception_handler,		default_handler
.weak secure_fault_handler
.thumb_set secure_fault_handler,	default_handler
.weak SVC_handler
.thumb_set SVC_handler,				default_handler
.weak debug_handler
.thumb_set debug_handler,			default_handler
.weak pending_SV_handler
.thumb_set pending_SV_handler,		default_handler
.weak sys_tick_handler
.thumb_set sys_tick_handler,		default_handler
.weak WWDG_handler
.thumb_set WWDG_handler,			default_handler
.weak PVD_PVM_handler
.thumb_set PVD_PVM_handler,			default_handler
.weak RTC_handler
.thumb_set RTC_handler,				default_handler
.weak RTC_sec_handler
.thumb_set RTC_sec_handler,			default_handler
.weak TAMP_handler
.thumb_set TAMP_handler,			default_handler
.weak RAMCFG_handler
.thumb_set RAMCFG_handler,			default_handler
.weak FLASH_handler
.thumb_set FLASH_handler,			default_handler
.weak FLASH_sec_handler
.thumb_set FLASH_sec_handler,		default_handler
.weak GTZC_handler
.thumb_set GTZC_handler,			default_handler
.weak RCC_handler
.thumb_set RCC_handler,				default_handler
.weak RCC_sec_handler
.thumb_set RCC_sec_handler,			default_handler
.weak EXTI0_handler
.thumb_set EXTI0_handler,			default_handler
.weak EXTI1_handler
.thumb_set EXTI1_handler,			default_handler
.weak EXTI2_handler
.thumb_set EXTI2_handler,			default_handler
.weak EXTI3_handler
.thumb_set EXTI3_handler,			default_handler
.weak EXTI4_handler
.thumb_set EXTI4_handler,			default_handler
.weak EXTI5_handler
.thumb_set EXTI5_handler,			default_handler
.weak EXTI6_handler
.thumb_set EXTI6_handler,			default_handler
.weak EXTI7_handler
.thumb_set EXTI7_handler,			default_handler
.weak EXTI8_handler
.thumb_set EXTI8_handler,			default_handler
.weak EXTI9_handler
.thumb_set EXTI9_handler,			default_handler
.weak EXTI10_handler
.thumb_set EXTI10_handler,			default_handler
.weak EXTI11_handler
.thumb_set EXTI11_handler,			default_handler
.weak EXTI12_handler
.thumb_set EXTI12_handler,			default_handler
.weak EXTI13_handler
.thumb_set EXTI13_handler,			default_handler
.weak EXTI14_handler
.thumb_set EXTI14_handler,			default_handler
.weak EXTI15_handler
.thumb_set EXTI15_handler,			default_handler
.weak IWDG_handler
.thumb_set IWDG_handler,			default_handler
.weak AES_sec_handler
.thumb_set AES_sec_handler,			default_handler
.weak GPDMA1_CH0_handler
.thumb_set GPDMA1_CH0_handler,		default_handler
.weak GPDMA1_CH1_handler
.thumb_set GPDMA1_CH1_handler,		default_handler
.weak GPDMA1_CH2_handler
.thumb_set GPDMA1_CH2_handler,		default_handler
.weak GPDMA1_CH3_handler
.thumb_set GPDMA1_CH3_handler,		default_handler
.weak GPDMA1_CH4_handler
.thumb_set GPDMA1_CH4_handler,		default_handler
.weak GPDMA1_CH5_handler
.thumb_set GPDMA1_CH5_handler,		default_handler
.weak GPDMA1_CH6_handler
.thumb_set GPDMA1_CH6_handler,		default_handler
.weak GPDMA1_CH7_handler
.thumb_set GPDMA1_CH7_handler,		default_handler
.weak ADC1_handler
.thumb_set ADC1_handler,			default_handler
.weak DAC1_handler
.thumb_set DAC1_handler,			default_handler
.weak FDCAN1_CH0_handler
.thumb_set FDCAN1_CH0_handler,		default_handler
.weak FDCAN1_CH1_handler
.thumb_set FDCAN1_CH1_handler,		default_handler
.weak TIM1_BRK_handler
.thumb_set TIM1_BRK_handler,		default_handler
.weak TIM1_UP_handler
.thumb_set TIM1_UP_handler,			default_handler
.weak TIM1_TRG_COM_handler
.thumb_set TIM1_TRG_COM_handler,	default_handler
.weak TIM1_CC_handler
.thumb_set TIM1_CC_handler,			default_handler
.weak TIM2_handler
.thumb_set TIM2_handler,			default_handler
.weak TIM3_handler
.thumb_set TIM3_handler,			default_handler
.weak TIM4_handler
.thumb_set TIM4_handler,			default_handler
.weak TIM6_handler
.thumb_set TIM6_handler,			default_handler
.weak TIM7_handler
.thumb_set TIM7_handler,			default_handler
.weak I3C1_ERR_handler
.thumb_set I3C1_ERR_handler,		default_handler
.weak I3C1_handler
.thumb_set I3C1_handler,			default_handler
.weak I2C1_handler
.thumb_set I2C1_handler,			default_handler
.weak I2C1_ERR_handler
.thumb_set I2C1_ERR_handler,		default_handler
.weak I2C2_handler
.thumb_set I2C2_handler,			default_handler
.weak I2C2_ERR_handler
.thumb_set I2C2_ERR_handler,		default_handler
.weak SPI1_handler
.thumb_set SPI1_handler,			default_handler
.weak SPI2_handler
.thumb_set SPI2_handler,			default_handler
.weak USART1_handler
.thumb_set USART1_handler,			default_handler
.weak USART3_handler
.thumb_set USART3_handler,			default_handler
.weak UART4_handler
.thumb_set UART4_handler,			default_handler
.weak UART5_handler
.thumb_set UART5_handler,			default_handler
.weak LPUART1_handler
.thumb_set LPUART1_handler,			default_handler
.weak LPTIM1_handler
.thumb_set LPTIM1_handler,			default_handler
.weak LPTIM2_handler
.thumb_set LPTIM2_handler,			default_handler
.weak TIM15_handler
.thumb_set TIM15_handler,			default_handler
.weak TIM16_handler
.thumb_set TIM16_handler,			default_handler
.weak TIM17_handler
.thumb_set TIM17_handler,			default_handler
.weak COMP_handler
.thumb_set COMP_handler,			default_handler
.weak USB_FS_handler
.thumb_set USB_FS_handler,			default_handler
.weak CRS_handler
.thumb_set CRS_handler,				default_handler
.weak OCTOSPI1_handler
.thumb_set OCTOSPI1_handler,		default_handler
.weak SDMMC1_handler
.thumb_set SDMMC1_handler,			default_handler
.weak GPDMA1_CH8_handler
.thumb_set GPDMA1_CH8_handler,		default_handler
.weak GPDMA1_CH9_handler
.thumb_set GPDMA1_CH9_handler,		default_handler
.weak GPDMA1_CH10_handler
.thumb_set GPDMA1_CH10_handler,		default_handler
.weak GPDMA1_CH11_handler
.thumb_set GPDMA1_CH11_handler,		default_handler
.weak I2C3_handler
.thumb_set I2C3_handler,			default_handler
.weak I2C3_ERR_handler
.thumb_set I2C3_ERR_handler,		default_handler
.weak SAI1_handler
.thumb_set SAI1_handler,			default_handler
.weak TSC_handler
.thumb_set TSC_handler,				default_handler
.weak AES_handler
.thumb_set AES_handler,				default_handler
.weak RNG_handler
.thumb_set RNG_handler,				default_handler
.weak FPU_handler
.thumb_set FPU_handler,				default_handler
.weak HASH_handler
.thumb_set HASH_handler,			default_handler
.weak PKA_handler
.thumb_set PKA_handler,				default_handler
.weak LPTIM3_handler
.thumb_set LPTIM3_handler,			default_handler
.weak SPI3_handler
.thumb_set SPI3_handler,			default_handler
.weak I3C2_ERR_handler
.thumb_set I3C2_ERR_handler,		default_handler
.weak I3C2_handler
.thumb_set I3C2_handler,			default_handler
.weak ICACHE_handler
.thumb_set ICACHE_handler,			default_handler
.weak LPTIM4_handler
.thumb_set LPTIM4_handler,			default_handler
.weak ADF1_handler
.thumb_set ADF1_handler,			default_handler
.weak ADC2_handler
.thumb_set ADC2_handler,			default_handler
.weak PWR_handler
.thumb_set PWR_handler,				default_handler
.weak PWR_sec_handler
.thumb_set PWR_sec_handler,			default_handler
