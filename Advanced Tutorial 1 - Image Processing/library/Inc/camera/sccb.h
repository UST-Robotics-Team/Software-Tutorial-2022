#ifndef __SCCB_H
#define __SCCB_H

#include "OV7725_defines.h"
#include "main.h"

#define SCL_H PIN_HIGH(OV7725_SCL)
#define SCL_L PIN_LOW(OV7725_SCL)

#define SDA_H PIN_HIGH(OV7725_SDA)
#define SDA_L PIN_LOW(OV7725_SDA)

#define SCL_READ HAL_GPIO_ReadPin(OV7725_SCL_PORT, OV7725_SCL_PIN)
#define SDA_READ HAL_GPIO_ReadPin(OV7725_SDA_PORT, OV7725_SDA_PIN)

typedef enum {
	SCCB_FAIL,
	SCCB_OK,
} SCCBState;

void SCCB_GPIO_init(void);
SCCBState SCCB_send_byte(uint16_t addr, uint8_t byte);
SCCBState SCCB_read_byte(uint8_t addr, uint8_t* buf, uint16_t len);

#endif