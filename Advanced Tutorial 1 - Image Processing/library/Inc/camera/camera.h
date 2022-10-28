#ifndef __OV7725_H
#define __OV7725_H
#include "OV7725_defines.h"

#include <stdint.h>

#define FIFO_OE_H PIN_HIGH(OV7725_OE)
#define FIFO_OE_L PIN_LOW(OV7725_OE)

#define FIFO_WRST_H PIN_HIGH(OV7725_WRST)
#define FIFO_WRST_L PIN_LOW(OV7725_WRST)

#define FIFO_RRST_H PIN_HIGH(OV7725_RRST)
#define FIFO_RRST_L PIN_LOW(OV7725_RRST)

#define FIFO_RCLK_H PIN_HIGH(OV7725_RCLK)
#define FIFO_RCLK_L PIN_LOW(OV7725_RCLK)

#define FIFO_WE_H PIN_HIGH(OV7725_WE)
#define FIFO_WE_L PIN_LOW(OV7725_WE)

#define FIFO_PREPARE \
	do {             \
		FIFO_RRST_L; \
		FIFO_RCLK_L; \
		FIFO_RCLK_H; \
		FIFO_RRST_H; \
		FIFO_RCLK_L; \
		FIFO_RCLK_H; \
	} while (0)

typedef enum CamColorMode {
	CAM_GRAYSCALE,
	CAM_RGB565,

	NUM_CAM_COLORMODE,
} CamColorMode;

typedef enum CamFrameSize {
	QVGA_320x240,
	QVGA_240x320,
	QQVGA_160x120,
	QQVGA_120x160,
	QQQVGA_80x60,
	QQQVGA_60x80,
	QQQQVGA_40x30,
	QQQQVGA_30x40,

	NUM_CAM_FRAMESIZE,
} CamFrameSize;

typedef enum CamFrameRate {
	CAM_150FPS,
	CAM_112FPS,
	CAM_75FPS,
	CAM_50FPS,
	CAM_37FPS,
	CAM_30FPS,
	CAM_25FPS,
	CAM_15FPS,

	NUM_CAM_FRAMERATE,
} CamFrameRate;

typedef enum CamLightMode {
	CAM_LIGHT_AUTO,
	CAM_LIGHT_SUNNY,
	CAM_LIGHT_CLOUDY,
	CAM_LIGHT_OFFICE,
	CAM_LIGHT_HOME,
	CAM_LIGHT_NIGHT,

	NUM_CAM_LIGHTMODE,
} CamLightMode;

typedef enum CamEffect {
	CAM_FX_NORMAL,
	CAM_FX_BW,
	CAM_FX_BLUE,
	CAM_FX_SEPIA,
	CAM_FX_RED,
	CAM_FX_GREEN,
	CAM_FX_NEGATIVE,

	NUM_CAM_FX,
} CamEffect;

typedef enum CameraState {
	CAM_NOT_INITED,
	CAM_INIT_ERROR,
	CAM_NOT_FOUND,
	CAM_CONFIGURED,
	CAM_CAPTURING,
	CAM_FRAME_READY,
	CAM_MISSED_FRAME,

	NUM_CAM_STATE,
} CameraState;

static const struct {
	uint16_t width, height;
} cam_sizes[NUM_CAM_FRAMESIZE] = {
	{320, 240}, {240, 320}, {160, 120}, {120, 160}, {80, 60}, {60, 80}, {40, 30}, {30, 40},
};

// init
void camera_GPIO_init(void);
CameraState camera_init(void);

// setters
void cam_set_state(CameraState state);
void cam_set_colormode(CamColorMode mode);
void cam_set_framesize(CamFrameSize size);				  // FIXME
void cam_set_frameoffset(uint16_t off_x, uint16_t off_y); // FIXME
void cam_set_window(uint16_t off_x, uint16_t off_y, CamFrameSize size);
void cam_set_framerate(CamFrameRate rate);
void cam_set_zoomscale(float ratio);
void cam_set_sharpness(uint8_t strength, uint8_t thresh, uint8_t upperlim, uint8_t lowerlim);
void cam_set_lightmode(CamLightMode mode);

/**
 * @brief Change the brightness of the camera sensor [-4,4]
 *
 * @param brightness
 */
void cam_set_brightness(int8_t brightness);
/**
 * @brief Change the saturation of the camera sensor [-4, 4]
 *
 * @param sat
 */
void cam_set_saturation(int8_t sat);
/**
 * @brief Change the contrast of the camera sensor [-4. 4]
 *
 * @param contrast
 */
void cam_set_contrast(int8_t contrast);
void cam_set_effect(CamEffect effect);

// getters
CameraState cam_get_state(void);
uint8_t cam_is_initialized(void);
uint8_t cam_is_frame_ready(void);
CamColorMode cam_get_colormode(void);
CamFrameSize cam_get_framesize(void);
float cam_get_zoomscale(void);
void cam_get_rgb565(uint16_t* image);
void cam_rgb2printable(uint16_t* image, uint16_t* printable);

#endif
