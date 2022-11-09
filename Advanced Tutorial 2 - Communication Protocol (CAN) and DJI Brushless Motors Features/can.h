/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    can.h
  * @brief   This file contains all the function prototypes for
  *          the can.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#ifndef __CAN_H__
#define __CAN_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern CAN_HandleTypeDef hcan1;

extern CAN_HandleTypeDef hcan2;

/* USER CODE BEGIN Private defines */
typedef struct{
	uint16_t    ecd;
	int16_t     speed_rpm;
	int16_t     given_current;
	uint8_t     temperate;
	int16_t		last_ecd;
}   motor_measure_t;
typedef enum{
	motor1 = 0,
	motor2 = 1,
	motor3 = 2,
	motor4 = 3,
}   motor_return;
typedef enum{
	CAN_GROUP_ID = 0x200,
	CAN_3508_M1_ID = 0x201,
	CAN_3508_M2_ID = 0x202,
	CAN_3508_M3_ID = 0x203,
	CAN_3508_M4_ID = 0x204,
}can_msg_id_e;
typedef struct{
    int16_t     speed_rpm; //speed rpm = number of turns per 1 min
    int16_t     given_current;//given current for the motor
    uint8_t     temperature;//temperature of the motor
}   motor_status;
#define CAN1_DEVICE_NUM     4
#define FIRST_GROUP_ID      0x200
#define MOTOR_SPEED_MAX     16384
#define CAN_DATA_SIZE       8
#define CAN1_RX_ID_START    0x201
#define MOTOR_ID            2
extern motor_status motor1_stat,motor2_stat,motor3_stat,motor4_stat;
/* USER CODE END Private defines */
void MX_CAN1_Init(void);
void MX_CAN2_Init(void);

/* USER CODE BEGIN Prototypes */
void can_filter_enable(CAN_HandleTypeDef* hcan);
void can_filter_disable(CAN_HandleTypeDef* hcan);
void can_transmit(CAN_HandleTypeDef* hcan, uint16_t id, int16_t msg1, int16_t msg2, int16_t msg3, int16_t msg4);
void can_trigger_motor(int16_t motor1,int16_t motor2,int16_t motor3,int16_t motor4);
void CAN_cmd_motor(int16_t motor1, int16_t motor2, int16_t motor3,
		int16_t motor4, CAN_HandleTypeDef *hcan);
void can_filter_init();
void can_init();
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);
const motor_measure_t *get_rotate_motor_measure(uint8_t i);
void  UpdateMotorStatus();
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __CAN_H__ */

