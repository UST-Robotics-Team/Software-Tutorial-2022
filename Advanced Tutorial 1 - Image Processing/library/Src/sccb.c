#include "camera/sccb.h"

#include "tim.h"

#include "stm32f4xx.h"
#define SCCB_TIMER htim6

void SCCB_GPIO_init(void) {
	GPIO_InitTypeDef GPIO_InitStructure = {0};

	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_InitStructure.Pin = OV7725_SDA_PIN;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_MEDIUM;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;
	HAL_GPIO_Init(OV7725_SDA_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = OV7725_SCL_PIN;
	HAL_GPIO_Init(OV7725_SCL_PORT, &GPIO_InitStructure);
	HAL_TIM_Base_Init(&SCCB_TIMER);
	HAL_TIM_Base_Start(&SCCB_TIMER);
}

static inline void delay_us(uint16_t us) {
	__HAL_TIM_SET_COUNTER(&SCCB_TIMER, 0);
	while (__HAL_TIM_GET_COUNTER(&SCCB_TIMER) < us)
		;
}

static inline void SCCB_delay(void) {
	// volatile uint16_t i = 400;
	// while (i--)
	// 	;
	delay_us(12); // min 12us
}

static inline SCCBState SCCB_start(void) {
	SDA_H;
	SCL_H;
	SCCB_delay();
	if (!SDA_READ)
		return SCCB_FAIL; // If SDA is low, bus is busy
	SDA_L;
	SCCB_delay();
	if (SDA_READ)
		return SCCB_FAIL; // If SDA is high, bus error
	SDA_L;
	SCCB_delay();
	return SCCB_OK;
}

static inline void SCCB_stop(void) {
	SCL_L;
	SCCB_delay();
	SDA_L;
	SCCB_delay();
	SCL_H;
	SCCB_delay();
	SDA_H;
	SCCB_delay();
}

static inline void SCCB_ack(void) {
	SCL_L;
	SCCB_delay();
	SDA_L;
	SCCB_delay();
	SCL_H;
	SCCB_delay();
	SCL_L;
	SCCB_delay();
}

static inline void SCCB_noAck(void) {
	SCL_L;
	SCCB_delay();
	SDA_H;
	SCCB_delay();
	SCL_H;
	SCCB_delay();
	SCL_L;
	SCCB_delay();
}

static inline SCCBState SCCB_waitAck(void) {
	SCL_L;
	SCCB_delay();
	SDA_H;
	SCCB_delay();
	SCL_H;
	SCCB_delay();
	if (SDA_READ) {
		SCL_L;
		return SCCB_FAIL;
	}
	SCL_L;
	return SCCB_OK;
}

static inline void SCCB_TxByte(uint8_t SendByte) {
	volatile uint8_t i = 8;
	while (i--) {
		SCL_L;
		SCCB_delay();
		if (SendByte & 0x80) {
			SDA_H;
		} else {
			SDA_L;
		}
		SendByte <<= 1;
		SCCB_delay();
		SCL_H;
		SCCB_delay();
	}
	SCL_L;
}

static inline uint8_t SCCB_RxByte(void) {
	volatile uint8_t i = 8;
	uint8_t ReceiveByte = 0;

	SDA_H;
	while (i--) {
		ReceiveByte <<= 1;
		SCL_L;
		SCCB_delay();
		SCL_H;
		SCCB_delay();
		if (SDA_READ) {
			ReceiveByte |= 0x01;
		}
	}
	SCL_L;
	return ReceiveByte & 0xFF;
}

SCCBState SCCB_send_byte(uint16_t WriteAddress, uint8_t SendByte) {
	if (!SCCB_start()) {
		return SCCB_FAIL;
	}
	SCCB_TxByte(OV7725_ADDR); // device address
	if (!SCCB_waitAck()) {
		SCCB_stop();
		return SCCB_FAIL;
	}
	SCCB_TxByte((uint8_t)(WriteAddress & 0x00FF));
	SCCB_waitAck();
	SCCB_TxByte(SendByte);
	SCCB_waitAck();
	SCCB_stop();
	return SCCB_OK;
}

SCCBState SCCB_read_byte(uint8_t addr, uint8_t* buf, uint16_t len) {
	if (!SCCB_start()) {
		return SCCB_FAIL;
	}
	SCCB_TxByte(OV7725_ADDR); // device address
	if (!SCCB_waitAck()) {
		SCCB_stop();
		return SCCB_FAIL;
	}
	SCCB_TxByte(addr);
	SCCB_waitAck();
	SCCB_stop();

	if (!SCCB_start()) {
		return SCCB_FAIL;
	}
	SCCB_TxByte(OV7725_ADDR + 1);
	if (!SCCB_waitAck()) {
		SCCB_stop();
		return SCCB_FAIL;
	}
	while (len) {
		*buf = SCCB_RxByte();
		if (len == 1) {
			SCCB_noAck();
		} else {
			SCCB_ack();
		}
		buf++;
		len--;
	}
	SCCB_stop();
	return SCCB_OK;
}
