/**
  ******************************************************************************
  * @file    can.c
  * @brief   This file provides code for the configuration
  *          of the CAN instances.
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

/* Includes ------------------------------------------------------------------*/
#include "can.h"

/* USER CODE BEGIN 0 */
  int16_t pwmValue[4];
  int16_t pwm2Value[4];
/* USER CODE END 0 */

CAN_HandleTypeDef hcan;

/* CAN init function */
void MX_CAN_Init(void)
{

  /* USER CODE BEGIN CAN_Init 0 */

  /* USER CODE END CAN_Init 0 */

  /* USER CODE BEGIN CAN_Init 1 */

  /* USER CODE END CAN_Init 1 */
  hcan.Instance = CAN1;
  hcan.Init.Prescaler = 6;
  hcan.Init.Mode = CAN_MODE_NORMAL;
  hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan.Init.TimeSeg1 = CAN_BS1_3TQ;
  hcan.Init.TimeSeg2 = CAN_BS2_2TQ;
  hcan.Init.TimeTriggeredMode = DISABLE;
  hcan.Init.AutoBusOff = ENABLE;
  hcan.Init.AutoWakeUp = DISABLE;
  hcan.Init.AutoRetransmission = ENABLE;
  hcan.Init.ReceiveFifoLocked = DISABLE;
  hcan.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN_Init 2 */


  /* USER CODE END CAN_Init 2 */

}

void HAL_CAN_MspInit(CAN_HandleTypeDef* canHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(canHandle->Instance==CAN1)
  {
  /* USER CODE BEGIN CAN1_MspInit 0 */

  /* USER CODE END CAN1_MspInit 0 */
    /* CAN1 clock enable */
    __HAL_RCC_CAN1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**CAN GPIO Configuration
    PA11     ------> CAN_RX
    PA12     ------> CAN_TX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* CAN1 interrupt Init */
    HAL_NVIC_SetPriority(USB_LP_CAN1_RX0_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USB_LP_CAN1_RX0_IRQn);
  /* USER CODE BEGIN CAN1_MspInit 1 */

  /* USER CODE END CAN1_MspInit 1 */
  }
}

void HAL_CAN_MspDeInit(CAN_HandleTypeDef* canHandle)
{

  if(canHandle->Instance==CAN1)
  {
  /* USER CODE BEGIN CAN1_MspDeInit 0 */

  /* USER CODE END CAN1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_CAN1_CLK_DISABLE();

    /**CAN GPIO Configuration
    PA11     ------> CAN_RX
    PA12     ------> CAN_TX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_11|GPIO_PIN_12);

    /* CAN1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(USB_LP_CAN1_RX0_IRQn);
  /* USER CODE BEGIN CAN1_MspDeInit 1 */

  /* USER CODE END CAN1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

//Function declaration are done by HAL library.
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan){
  CAN_RxHeaderTypeDef rx_header;
  uint8_t rx_data[8]; // each data 1 byte
  HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rx_header, rx_data);
  switch (rx_header.StdId)
  {
  case MOTORGROUP0ID:
		for(int i = 0; i<4; i++){
		//TIM3 CCR1  = gp0speed[0]'s value
			//pwmValue[i] = 13762 is not working
	  	  //int16_t, pwmValue here is correctly decoded
		  pwmValue[i] =  (rx_data[2*i]<<8)|rx_data[(2*i)+1];

		  //gp0Speed[0] is not correctly decoded
		  gp0speed[i] =  mapping(pwmValue[i], -32768, 32767, ESC_MAX_REVERSE, ESC_MAX_FORWARD);

		  drive_motor(i,gp0speed[i]);
		}
    break;
  case MOTORGROUP1ID:
		for(int i = 0; i<4; i++){
		  pwm2Value[i] = (int16_t) (rx_data[2*i]<<8|rx_data[2*i+1]);
		  gp1speed[i] = mapping(pwm2Value[i], -32768, 32767, ESC_MAX_REVERSE, ESC_MAX_FORWARD);
		  drive_motor(i+4,gp1speed[i]);
		}
    break;
  default:
    break;
  }
}
void Can_TX(void)
{
  CAN_TxHeaderTypeDef TxHeader;
  uint8_t data[8];
  uint32_t TxMailbox;
  TxHeader.DLC = 8;
  TxHeader.StdId = 0x641;
  TxHeader.IDE = CAN_ID_STD;
  TxHeader.RTR = CAN_RTR_DATA;
	data[0] = gp0speed[0] >> 8;
	data[1] = gp0speed[0];
	data[2] = gp0speed[1] >> 8;
	data[3] = gp0speed[1];
	data[4] = gp0speed[2] >> 8;
	data[5] = gp0speed[2];
	data[6] = gp0speed[3] >> 8;
	data[7] = gp0speed[3];
  HAL_CAN_AddTxMessage(&hcan, &TxHeader, data, &TxMailbox);
  if(HAL_CAN_AddTxMessage(&hcan, &TxHeader, data, &TxMailbox) != HAL_OK)
  {
    Error_Handler();
  }
  while(HAL_CAN_IsTxMessagePending(&hcan, TxMailbox));
  TxHeader.DLC = 8;
   TxHeader.StdId = 0x661;
   TxHeader.IDE = CAN_ID_STD;
   TxHeader.RTR = CAN_RTR_DATA;
 	data[0] = gp1speed[0] >> 8;
 	data[1] = gp1speed[0];
 	data[2] = gp1speed[1] >> 8;
 	data[3] = gp1speed[1];
 	data[4] = gp1speed[2] >> 8;
 	data[5] = gp1speed[2];
 	data[6] = gp1speed[3] >> 8;
 	data[7] = gp1speed[3];
   HAL_CAN_AddTxMessage(&hcan, &TxHeader, data, &TxMailbox);
   if(HAL_CAN_AddTxMessage(&hcan, &TxHeader, data, &TxMailbox) != HAL_OK)
   {
     Error_Handler();
   }
   while(HAL_CAN_IsTxMessagePending(&hcan, TxMailbox));
}
void can_filter_on(CAN_HandleTypeDef* hcan){
  CAN_FilterTypeDef can_filter;
  can_filter.FilterActivation = ENABLE;
  // Just pick anything between 0 to 13
  can_filter.FilterBank = 0;// 14 bank in F1 board, other having CAN1 CAN2 have total 0 to 27 CAN banks.
  can_filter.FilterFIFOAssignment = CAN_RX_FIFO0;
  // Mask and ID, both 16bit for standard frame. 
  can_filter.FilterIdHigh = MOTORGROUP0ID << 5; // First 16 bit. Any question plz refer to notes.
  can_filter.FilterIdLow = 0x0000;
  can_filter.FilterMaskIdHigh = CAN_RX_MASK_EXACT_5DIGIT << 5;
  can_filter.FilterMaskIdLow = 0x0000;
  //MaskMode: ID = must match or  not match.
  can_filter.FilterMode = CAN_FILTERMODE_IDMASK;
  can_filter.FilterScale = CAN_FILTERSCALE_32BIT;// The id in the mask will be 32 bit wide.
  can_filter.SlaveStartFilterBank = 0; //This parameter is useless in F1 board.

  HAL_CAN_ConfigFilter(hcan, &can_filter);
}
void can_filter_off(CAN_HandleTypeDef* hcan){
  CAN_FilterTypeDef can_filter;
  can_filter.FilterActivation = ENABLE;
  can_filter.FilterBank = 0;
  can_filter.FilterFIFOAssignment = CAN_RX_FIFO0;
  can_filter.FilterIdHigh = 0x0000;
  can_filter.FilterIdLow = 0x0000;
  can_filter.FilterMaskIdHigh =0x0000;
  can_filter.FilterMaskIdLow = 0x0000;
  can_filter.FilterMode = CAN_FILTERMODE_IDMASK;
  can_filter.FilterScale = CAN_FILTERSCALE_32BIT;
  can_filter.SlaveStartFilterBank = 0;

  HAL_CAN_ConfigFilter(hcan, &can_filter);
}

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
