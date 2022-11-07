/**
  ******************************************************************************
  * @file    can.h
  * @brief   This file contains all the function prototypes for
  *          the can.c file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CAN_H__
#define __CAN_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include "tim.h"
/* USER CODE END Includes */

extern CAN_HandleTypeDef hcan;

/* USER CODE BEGIN Private defines */
/*** CAN ID ***/
#define MOTORGROUP0ID 0x640 // data array motor[0]
#define MOTORGROUP1ID 0x660 // data array motor[1]
/*** CAN RX MAST ***/
/*** X = the ID bit that must be equal ***/
/*** ? = the ID bit that can varies ***/
#define CAN_RX_MASK_EXACT 0x7FF        /*** XXX XXXX XXXX ***/
#define CAN_RX_MASK_EXACT_7DIGIT 0x7F0 /*** XXX XXXX ???? ***/
#define CAN_RX_MASK_EXACT_5DIGIT 0x7C0 /*** XXX XX?? ???? ***/
/* USER CODE END Private defines */

void MX_CAN_Init(void);

/* USER CODE BEGIN Prototypes */
void Can_TX(void);
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);
void can_filter_on(CAN_HandleTypeDef* hcan);
void can_filter_off(CAN_HandleTypeDef* hcan);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __CAN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
