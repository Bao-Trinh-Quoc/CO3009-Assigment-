/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI15_10_IRQn
#define CONTROL_TRAFFIC0_0_Pin GPIO_PIN_0
#define CONTROL_TRAFFIC0_0_GPIO_Port GPIOA
#define CONTROL_TRAFFIC0_1_Pin GPIO_PIN_1
#define CONTROL_TRAFFIC0_1_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define CONTROL_TRAFFIC1_0_Pin GPIO_PIN_4
#define CONTROL_TRAFFIC1_0_GPIO_Port GPIOA
#define LED_RED_Pin GPIO_PIN_5
#define LED_RED_GPIO_Port GPIOA
#define CONTROL_TRAFFIC1_1_Pin GPIO_PIN_0
#define CONTROL_TRAFFIC1_1_GPIO_Port GPIOB
#define BUTTON1_Pin GPIO_PIN_10
#define BUTTON1_GPIO_Port GPIOB
#define SERVER_BUTTON2_Pin GPIO_PIN_6
#define SERVER_BUTTON2_GPIO_Port GPIOC
#define SERVER_BUTTON3_Pin GPIO_PIN_8
#define SERVER_BUTTON3_GPIO_Port GPIOC
#define BUTTON2_Pin GPIO_PIN_8
#define BUTTON2_GPIO_Port GPIOA
#define BUTTON3_Pin GPIO_PIN_9
#define BUTTON3_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SERVER_BUTTON0_Pin GPIO_PIN_10
#define SERVER_BUTTON0_GPIO_Port GPIOC
#define SERVER_BUTTON1_Pin GPIO_PIN_11
#define SERVER_BUTTON1_GPIO_Port GPIOC
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define BUTTON0_Pin GPIO_PIN_4
#define BUTTON0_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#define TIMER_TICK 10
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
