#ifndef __OV7725_DEFINES_H
#define __OV7725_DEFINES_H

/* Pin definitions */
#define OV7725_SCL_PORT CAM_SCL_GPIO_Port
#define OV7725_SCL_PIN	CAM_SCL_Pin
#define OV7725_SDA_PORT CAM_SDA_GPIO_Port
#define OV7725_SDA_PIN	CAM_SDA_Pin

// FIFO output enable
#define OV7725_OE_PORT CAM_OE_GPIO_Port
#define OV7725_OE_PIN  CAM_OE_Pin

// FIFO write reset
#define OV7725_WRST_PORT CAM_WRST_GPIO_Port
#define OV7725_WRST_PIN	 CAM_WRST_Pin

// FIFO read reset
#define OV7725_RRST_PORT CAM_RRST_GPIO_Port
#define OV7725_RRST_PIN	 CAM_RRST_Pin

// FIFO read clock
#define OV7725_RCLK_PORT CAM_RCLK_GPIO_Port
#define OV7725_RCLK_PIN	 CAM_RCLK_Pin

// FIFO write enable
#define OV7725_WE_PORT CAM_WEN_GPIO_Port
#define OV7725_WE_PIN  CAM_WEN_Pin

// 8bit data pin
#define OV7725_DATA_PORT CAM_D0_GPIO_Port
#define OV7725_D0_PIN	 CAM_D0_Pin
#define OV7725_D1_PIN	 CAM_D1_Pin
#define OV7725_D2_PIN	 CAM_D2_Pin
#define OV7725_D3_PIN	 CAM_D3_Pin
#define OV7725_D4_PIN	 CAM_D4_Pin
#define OV7725_D5_PIN	 CAM_D5_Pin
#define OV7725_D6_PIN	 CAM_D6_Pin
#define OV7725_D7_PIN	 CAM_D7_Pin

// OV7725 vsync interrupt
#define OV7725_VSYNC_PORT CAM_VSYNC_GPIO_Port
#define OV7725_VSYNC_PIN  CAM_VSYNC_Pin

#define OV7725_VSYNC_EXTI_IRQ CAM_VSYNC_EXTI_IRQn

// OV7725 address
#define OV7725_ADDR 0x42

/* Useful Macros */
#define PIN_HIGH(gpio) \
	{ gpio##_PORT->BSRR = gpio##_PIN; }
#define PIN_LOW(gpio) \
	{ gpio##_PORT->BSRR = (uint32_t)gpio##_PIN << 16; }

#endif