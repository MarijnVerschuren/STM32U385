//
// Created by marijn on 9/9/24.
//

#ifndef STM32U385_MEMORY_MAP_H
#define STM32U385_MEMORY_MAP_H


/*!<
 * core hardware memory map
 * */
#define SCS_BASE					(0xE000E000UL)
#define ITM_BASE					(0xE0000000UL)
#define DWT_BASE					(0xE0001000UL)
#define TPI_BASE					(0xE0040000UL)
#define CORE_DEBUG_BASE				(0xE000EDF0UL)
/*!< core hardware peripherals */
#define SYS_TICK_BASE				(SCS_BASE +  0x0010UL)
#define NVIC_BASE					(SCS_BASE +  0x0100UL)
#define SCB_BASE					(SCS_BASE +  0x0D00UL)


/*!<
 * extended hardware memory map
 * */
#define FLASH_MEMORY_BASE			0x08000000UL
#define SRAM_BASE					0x20000000UL
#define PERIPH_BASE					0x40000000UL
#define SEC_PERIPH_BASE				0x50000000UL	/* TODO SEC */
// TODO: BIT BAND, OTP?

#define APB1PERIPH_BASE				PERIPH_BASE
#define APB2PERIPH_BASE				(PERIPH_BASE + 0x00012C00UL)
#define APB3PERIPH_BASE				(PERIPH_BASE + 0x00040400UL)

#define AHB1PERIPH_BASE				(PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE				(PERIPH_BASE + 0x02020000UL)



/*!<
 * APB1 peripheral map
 * */



/*!<
 * APB2 peripheral map
 * */


/*!<
 * APB3 peripheral map
 * */



/*!<
 * AHB1 peripheral map
 * */
#define RCC_BASE					(AHB1PERIPH_BASE + 0x10C00UL)
#define EXTI_BASE					(AHB1PERIPH_BASE + 0x12000UL)



/*!<
 * AHB2 peripheral map
 * */
#define GPIOA_BASE					(AHB2PERIPH_BASE + 0x00000UL)
#define GPIOB_BASE					(AHB2PERIPH_BASE + 0x00400UL)
#define GPIOC_BASE					(AHB2PERIPH_BASE + 0x00800UL)
#define GPIOD_BASE					(AHB2PERIPH_BASE + 0x00C00UL)
#define GPIOE_BASE					(AHB2PERIPH_BASE + 0x01000UL)
#define GPIOF_BASE					(AHB2PERIPH_BASE + 0x01400UL)
#define GPIOG_BASE					(AHB2PERIPH_BASE + 0x01800UL)
#define GPIOH_BASE					(AHB2PERIPH_BASE + 0x01C00UL)



/*!<
 * Misc peripheral map
 * */
#define UID_BASE					0x1FFF7A10UL
#define FLASHSIZE_BASE				0x1FFF7A22UL
#define PACKAGE_BASE				0x1FFF7BF0UL
#define DBGMCU_BASE					0xE0042000UL



/*!<
 * core peripheral register maps
 * */
/*!< SYS TICK TODO */
/*!< NVIC TODO */
#define NVIC_ISER		0x000
#define NVIC_ICER		0x080
#define NVIC_ISPR		0x100
#define NVIC_ICPR		0x180
#define NVIC_IABR		0x200
#define NVIC_ITNS		0x280
#define NVIC_IP			0x300
#define NVIC_STIR		0xE00

/*!< SCB */
// #define SCB_CPUID		0x00U
// #define SCB_ICSR		0x04U
// #define SCB_VTOR		0x08U
// #define SCB_AIRCR		0x0CU
// #define SCB_SCR			0x10U
// #define SCB_CCR			0x14U
// #define SCB_SHP			0x18U
// #define SCB_SHCSR		0x24U
// #define SCB_CFSR		0x28U
// #define SCB_HFSR		0x2CU
// #define SCB_DFSR		0x30U
// #define SCB_MMFAR		0x34U
// #define SCB_BFAR		0x38U
// #define SCB_AFSR		0x3CU
// #define SCB_PFR			0x40U
// #define SCB_DFR			0x48U
// #define SCB_ADR			0x4CU
// #define SCB_MMFR		0x50U
// #define SCB_ISAR		0x60U
// #define SCB_CPACR		0x88U


/*!<
 * peripheral register maps
 * */
/*!< PWR */
// #define PWR_CR			0x00U
// #define PWR_CSR			0x04U

/*!< FLASH */
// #define FLASH_ACR		0x00U
// #define FLASH_KEYR		0x04U
// #define FLASH_OPTKEYR	0x08U
// #define FLASH_SR		0x0CU
// #define FLASH_CR		0x10U
// #define FLASH_OPTCR		0x14U
// #define FLASH_OPTCR1	0x18U

/*!< RCC */
#define RCC_CR			0x000U
#define RCC_ICSCR1		0x008U
#define RCC_ICSCR2		0x00CU
#define RCC_ICSCR3		0x010U
#define RCC_CRRCR		0x014U
#define RCC_CFGR1		0x01CU
#define RCC_CFGR2		0x020U
#define RCC_CFGR3		0x024U
#define RCC_CFGR4		0x028U
#define RCC_CIER		0x050U
#define RCC_CIFR		0x054U
#define RCC_CICR		0x058U
#define RCC_AHB1RSTR	0x060U
#define RCC_AHB2RSTR1	0x064U
#define RCC_AHB2RSTR2	0x068U
#define RCC_APB1RSTR1	0x074U
#define RCC_APB1RSTR2	0x078U
#define RCC_APB2RSTR	0x07CU
#define RCC_APB3RSTR	0x080U
#define RCC_AHB1ENR1	0x088U
#define RCC_AHB2ENR1	0x08CU
#define RCC_AHB2ENR2	0x090U
#define RCC_AHB1ENR2	0x094U
#define RCC_APB1ENR1	0x09CU
#define RCC_APB1ENR2	0x0A0U
#define RCC_APB2ENR		0x0A4U
#define RCC_APB3ENR		0x0A8U
#define RCC_AHB1SLPENR1	0x0B0U
#define RCC_AHB2SLPENR1	0x0B4U
#define RCC_AHB2SLPENR2	0x0B8U
#define RCC_AHB1SLPENR2	0x0BCU
#define RCC_APB1SLPENR1	0x0C4U
#define RCC_APB1SLPENR2	0x0C8U
#define RCC_APB2SLPENR	0x0CCU
#define RCC_APB3SLPENR	0x0D0U
#define RCC_AHB1STPENR1	0x0D8U
#define RCC_AHB2STPENR1	0x0DCU
#define RCC_APB1STPENR1	0x0ECU
#define RCC_APB1STPENR2	0x0F0U
#define RCC_APB2STPENR	0x0F4U
#define RCC_APB3STPENR	0x0F8U
#define RCC_CCIPR1		0x100U
#define RCC_CCIPR2		0x104U
#define RCC_CCIPR3		0x108U
#define RCC_BDCR		0x110U
#define RCC_CSR			0x114U
#define RCC_SECCFGR		0x130U
#define RCC_PRIVCFGR	0x134U


/*!< SYSCFG */
// #define SYSCFG_MEMRMP	0x00U
// #define SYSCFG_PMC		0x04U
// #define SYSCFG_EXTICR	0x08U
// #define SYSCFG_CFGR2	0x1CU
// #define SYSCFG_CMPCR	0x20U
// #define SYSCFG_CFGR		0x24U

/*!< GPIO */
#define GPIO_MODER		0x00U
#define GPIO_OTYPER		0x04U
#define GPIO_OSPEEDR	0x08U
#define GPIO_PUPDR		0x0CU
#define GPIO_IDR		0x10U
#define GPIO_ODR		0x14U
#define GPIO_BSRR		0x18U
#define GPIO_LCKR		0x1CU
#define GPIO_AFR1		0x20U
#define GPIO_AFR2		0x24U
#define GPIO_BRR		0x28U
#define GPIO_HSLVR		0x2CU
#define GPIO_SECCFGR	0x30U

/*!< EXTI */
// #define EXTI_IMR		0x00U
// #define EXTI_EMR		0x04U
// #define EXTI_RTSR		0x08U
// #define EXTI_FTSR		0x0CU
// #define EXTI_SWIER		0x10U
// #define EXTI_PR			0x14U

/*!< TIM TODO */

/*!< RTC TODO */

/*!< USART */
// #define USART_SR  		0x00U
// #define USART_DR  		0x04U
// #define USART_BRR 		0x08U
// #define USART_CR1 		0x0CU
// #define USART_CR2 		0x10U
// #define USART_CR3 		0x14U
// #define USART_GTPR		0x18U

/*!< IWDG TODO */

/*!< CRC TODO */

/*!< RNG TODO */

/*!< ADC TODO */



#endif // STM32U385_MEMORY_MAP_H
