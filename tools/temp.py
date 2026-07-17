


text = """
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

.word	WWDG_handler
.word	PVD_PVM_handler
.word	RTC_handler
.word	RTC_sec_handler
.word	TAMP_handler
.word	RAMCFG_handler
.word	FLASH_handler
.word	FLASH_sec_handler
.word	GTZC_handler
.word	RCC_handler
.word	RCC_sec_handler
.word	EXTI0_handler
.word	EXTI1_handler
.word	EXTI2_handler
.word	EXTI3_handler
.word	EXTI4_handler
.word	EXTI5_handler
.word	EXTI6_handler
.word	EXTI7_handler
.word	EXTI8_handler
.word	EXTI9_handler
.word	EXTI10_handler
.word	EXTI11_handler
.word	EXTI12_handler
.word	EXTI13_handler
.word	EXTI14_handler
.word	EXTI15_handler
.word	IWDG_handler
.word	AES_sec_handler
.word	GPDMA1_CH0_handler
.word	GPDMA1_CH1_handler
.word	GPDMA1_CH2_handler
.word	GPDMA1_CH3_handler
.word	GPDMA1_CH4_handler
.word	GPDMA1_CH5_handler
.word	GPDMA1_CH6_handler
.word	GPDMA1_CH7_handler
.word	ADC1_handler
.word	DAC1_handler
.word	FDCAN1_CH0_handler
.word	FDCAN1_CH1_handler
.word	TIM1_BRK_handler
.word	TIM1_UP_handler
.word	TIM1_TRG_COM_handler
.word	TIM1_CC_handler
.word	TIM2_handler
.word	TIM3_handler
.word	TIM4_handler
.word	0
.word	TIM6_handler
.word	TIM7_handler
.word	0
.word	0
.word	I3C1_ERR_handler
.word	I3C1_handler
.word	I2C1_handler
.word	I2C1_ERR_handler
.word	I2C2_handler
.word	I2C2_ERR_handler
.word	SPI1_handler
.word	SPI2_handler
.word	USART1_handler
.word	0
.word	USART3_handler
.word	UART4_handler
.word	UART5_handler
.word	LPUART1_handler
.word	LPTIM1_handler
.word	LPTIM2_handler
.word	TIM15_handler
.word	TIM16_handler
.word	TIM17_handler
.word	COMP_handler
.word	USB_FS_handler
.word	CRS_handler
.word	0
.word	OCTOSPI1_handler
.word	0
.word	SDMMC1_handler
.word	0
.word	GPDMA1_CH8_handler
.word	GPDMA1_CH9_handler
.word	GPDMA1_CH10_handler
.word	GPDMA1_CH11_handler
.word	0
.word	0
.word	0
.word	0
.word	I2C3_handler
.word	I2C3_ERR_handler
.word	SAI1_handler
.word	0
.word	TSC_handler
.word	AES_handler
.word	RNG_handler
.word	FPU_handler
.word	HASH_handler
.word	PKA_handler
.word	LPTIM3_handler
.word	SPI3_handler
.word	I3C2_ERR_handler
.word	I3C2_handler
.word	0
.word	0
.word	0
.word	0
.word	0
.word	ICACHE_handler
.word	0
.word	0
.word	LPTIM4_handler
.word	0
.word	ADF1_handler
.word	ADC2_handler
.word	0
.word	0
.word	0
.word	0
.word	0
.word	0
.word	0
.word	0
.word	0
.word	PWR_handler
.word	PWR_sec_handler
"""


if __name__ == "__main__":
	for line in text.split("\n"):
		if ".word" not in line: continue
		handler = line[line.find("\t")+1:]
		if handler == "0": continue
		print(f""".weak {handler}\n.thumb_set {handler},\t\t\tdefault_handler""")
		
	