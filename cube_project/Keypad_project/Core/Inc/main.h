/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32u3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);
void MX_USB_PCD_Init(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ROW2_Pin GPIO_PIN_3
#define ROW2_GPIO_Port GPIOE
#define ROW0_Pin GPIO_PIN_1
#define ROW0_GPIO_Port GPIOE
#define COL2_Pin GPIO_PIN_7
#define COL2_GPIO_Port GPIOD
#define COL0_Pin GPIO_PIN_5
#define COL0_GPIO_Port GPIOD
#define STATUS_Pin GPIO_PIN_15
#define STATUS_GPIO_Port GPIOA
#define ROW3_Pin GPIO_PIN_4
#define ROW3_GPIO_Port GPIOE
#define ROW1_Pin GPIO_PIN_2
#define ROW1_GPIO_Port GPIOE
#define COL1_Pin GPIO_PIN_6
#define COL1_GPIO_Port GPIOD
#define BAT_SENS_NEN_Pin GPIO_PIN_13
#define BAT_SENS_NEN_GPIO_Port GPIOC
#define OLED_NEN_Pin GPIO_PIN_5
#define OLED_NEN_GPIO_Port GPIOE
#define SDMMC_RESET_Pin GPIO_PIN_10
#define SDMMC_RESET_GPIO_Port GPIOA
#define OLED_NSS_Pin GPIO_PIN_12
#define OLED_NSS_GPIO_Port GPIOB
#define SPI1_NSS_Pin GPIO_PIN_4
#define SPI1_NSS_GPIO_Port GPIOA
#define OLED_RST_Pin GPIO_PIN_0
#define OLED_RST_GPIO_Port GPIOB
#define OLED_DC_Pin GPIO_PIN_1
#define OLED_DC_GPIO_Port GPIOB
#define BKUP_MEM_NWP_Pin GPIO_PIN_7
#define BKUP_MEM_NWP_GPIO_Port GPIOE
#define BKUP_MEM_NRST_Pin GPIO_PIN_15
#define BKUP_MEM_NRST_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
