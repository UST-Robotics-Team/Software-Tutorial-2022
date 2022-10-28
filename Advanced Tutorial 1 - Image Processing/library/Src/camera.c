#include "camera/camera.h"

#include "camera/OV7725_regs.h"
#include "camera/sccb.h"

typedef struct {
	uint8_t address;
	uint8_t value;
} RegisterInfo;

// @formatter:off
// clang-format off

static RegisterInfo init_config[] = {
	{REG_CLKRC, 0x00},													 /*clock config*/
	{REG_COM7, COM7_SELECT_QVGA | COM7_FORMAT_RGB565 | COM7_OUTPUT_RGB}, /*QVGA RGB565 */
	{REG_HSTART, 0x3f},
	{REG_HSIZE, 0x50},
	{REG_VSTRT, 0x03},
	{REG_VSIZE, 0x78},
	{REG_HREF, 0x00},
	{REG_HOutSize, 0x50},
	{REG_VOutSize, 0x78},
	{REG_EXHCH, 0x00},

	/*DSP control*/
	{REG_TGT_B, 0x7f},
	{REG_FixGain, 0x09},
	{REG_AWB_Ctrl0, 0xe0},
	{REG_DSP_Ctrl1, 0xff},
	{REG_DSP_Ctrl2, 0x20},
	{REG_DSP_Ctrl3, 0x00},
	{REG_DSP_Ctrl4, 0x00},

	/*AGC AEC AWB*/
	{REG_COM8, 0xf0},
	{REG_COM4, 0x81}, /*Pll AEC CONFIG*/
	{REG_COM6, 0xc5},
	{REG_COM9, 0x21},
	{REG_BDBase, 0xFF},
	{REG_BDMStep, 0x01},
	{REG_AEW, 0x34},
	{REG_AEB, 0x3c},
	{REG_VPT, 0xa1},
	{REG_EXHCL, 0x00},
	{REG_AWBCtrl3, 0xaa},
	{REG_COM8, 0xff},
	{REG_AWBCtrl1, 0x5d},

	{REG_EDGE1, 0x0a},
	{REG_DNSOff, 0x01},
	{REG_EDGE2, 0x01},
	{REG_EDGE3, 0x01},

	{REG_MTX1, 0x5f},
	{REG_MTX2, 0x53},
	{REG_MTX3, 0x11},
	{REG_MTX4, 0x1a},
	{REG_MTX5, 0x3d},
	{REG_MTX6, 0x5a},
	{REG_MTX_Ctrl, 0x1e},

	{REG_BRIGHT, 0x00},
	{REG_CNST, 0x25},
	{REG_USAT, 0x65},
	{REG_VSAT, 0x65},
	{REG_UVADJ0, 0x81},
	{REG_SDE, 0x06},

	/*GAMMA config*/
	{REG_GAM1, 0x0c},
	{REG_GAM2, 0x16},
	{REG_GAM3, 0x2a},
	{REG_GAM4, 0x4e},
	{REG_GAM5, 0x61},
	{REG_GAM6, 0x6f},
	{REG_GAM7, 0x7b},
	{REG_GAM8, 0x86},
	{REG_GAM9, 0x8e},
	{REG_GAM10, 0x97},
	{REG_GAM11, 0xa4},
	{REG_GAM12, 0xaf},
	{REG_GAM13, 0xc5},
	{REG_GAM14, 0xd7},
	{REG_GAM15, 0xe8},
	{REG_SLOP, 0x20},

	{REG_HUECOS, 0x80},
	{REG_HUESIN, 0x80},
	{REG_DSPAuto, 0xff},
	{REG_DM_LNL, 0x00},
	{REG_BDBase, 0x99},
	{REG_BDMStep, 0x03},
	{REG_LC_RADI, 0x00},
	{REG_LC_COEF, 0x13},
	{REG_LC_XC, 0x08},
	{REG_LC_COEFB, 0x14},
	{REG_LC_COEFR, 0x17},
	{REG_LC_CTR, 0x05},

	{REG_COM3, 0xd0}, /*Horizontal mirror image*/

	{REG_COM5, 0xf5}, // auto lower frame rate in dark
	// {REG_COM5, 0x31}, // keep frame rate but lower quality in dark
};
// @formatter:on
// clang-format on
const uint8_t INIT_REG_NUM = sizeof(init_config) / sizeof(init_config[0]);

volatile CameraState cam_state = CAM_NOT_INITED;
static CamColorMode cam_colormode = CAM_RGB565;
static CamFrameSize cam_framesize = QQQVGA_60x80;
static CamFrameRate cam_framerate = CAM_50FPS;
static volatile double cam_zoomscale = 1.0f;

static const uint8_t cam_color_mode[] = {(COM7_OUTPUT_YUV | COM7_BT656_ENABLE), (COM7_OUTPUT_RGB | COM7_FORMAT_RGB565)};

static const struct {
	uint8_t clkrc, pll;
} cam_rates[NUM_CAM_FRAMERATE] = {
	{CLKRC_RESERVED(CLKRC_PRESCALER(0)), COM4_RESERVED(COM4_PLL(3))},
	{CLKRC_RESERVED(CLKRC_PRESCALER(0)), COM4_RESERVED(COM4_PLL(2))},
	{CLKRC_RESERVED(CLKRC_PRESCALER(0)), COM4_RESERVED(COM4_PLL(1))},
	{CLKRC_RESERVED(CLKRC_PRESCALER(2)), COM4_RESERVED(COM4_PLL(3))},
	{CLKRC_RESERVED(CLKRC_PRESCALER(1)), COM4_RESERVED(COM4_PLL(1))},
	{CLKRC_RESERVED(CLKRC_PRESCALER(4)), COM4_RESERVED(COM4_PLL(3))},
	{CLKRC_RESERVED(CLKRC_PRESCALER(2)), COM4_RESERVED(COM4_PLL(1))},
	{CLKRC_RESERVED(CLKRC_PRESCALER(4)), COM4_RESERVED(COM4_PLL(1))},
};

#define IMG_WIDTH  cam_sizes[cam_framesize].width
#define IMG_HEIGHT cam_sizes[cam_framesize].height

static void FIFO_GPIO_init(void) {
	GPIO_InitTypeDef GPIO_InitStructure;

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();

	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStructure.Pin = OV7725_OE_PIN;
	HAL_GPIO_Init(OV7725_OE_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = OV7725_WRST_PIN;
	HAL_GPIO_Init(OV7725_WRST_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = OV7725_RRST_PIN;
	HAL_GPIO_Init(OV7725_RRST_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = OV7725_RCLK_PIN;
	HAL_GPIO_Init(OV7725_RCLK_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = OV7725_WE_PIN;
	HAL_GPIO_Init(OV7725_WE_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = OV7725_D0_PIN | OV7725_D1_PIN | OV7725_D2_PIN | OV7725_D3_PIN | OV7725_D4_PIN
							 | OV7725_D5_PIN | OV7725_D6_PIN | OV7725_D7_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(OV7725_DATA_PORT, &GPIO_InitStructure);

	FIFO_OE_L;
	FIFO_WE_H;
}

static void VSYNC_GPIO_init(void) {
	GPIO_InitTypeDef GPIO_InitStructure;
	__HAL_RCC_GPIOB_CLK_ENABLE();

	GPIO_InitStructure.Pin = OV7725_VSYNC_PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(OV7725_VSYNC_PORT, &GPIO_InitStructure);

	HAL_NVIC_SetPriority(OV7725_VSYNC_EXTI_IRQ, 0, 3);
	HAL_NVIC_EnableIRQ(OV7725_VSYNC_EXTI_IRQ);
}

void camera_GPIO_init(void) {
	SCCB_GPIO_init();
	FIFO_GPIO_init();
	VSYNC_GPIO_init();
}

static CameraState camera_init_internal(void) {
	uint8_t dev_id = 0;

	if (SCCB_send_byte(REG_COM7, COM7_REGISTER_RESET) == SCCB_FAIL) {
		return CAM_NOT_FOUND;
	}

	if (SCCB_read_byte(REG_VER, &dev_id, 1) == SCCB_FAIL) {
		return CAM_NOT_FOUND;
	}

	if (dev_id == OV7725_ID) {
		for (volatile uint16_t i = 0; i < INIT_REG_NUM; ++i) {
			if (SCCB_send_byte(init_config[i].address, init_config[i].value) == SCCB_FAIL) {
				return CAM_INIT_ERROR;
			}
		}
	} else {
		return CAM_NOT_FOUND;
	}
	return CAM_CONFIGURED;
}

CameraState camera_init(void) {
	volatile uint8_t retry = 0;
	while (camera_init_internal() != CAM_CONFIGURED) {
		++retry;
		if (retry > 5) {
			return CAM_NOT_INITED;
		}
	}

	cam_set_effect(CAM_FX_NORMAL);
	cam_set_lightmode(CAM_LIGHT_HOME);
	cam_set_saturation(0);
	cam_set_brightness(0);
	cam_set_contrast(2);
	// cam_set_frameoffset((240 - 120) / 2, (320 - 160) / 2);
	// cam_set_framesize(QQVGA_120x160);
	cam_set_window(IMG_WIDTH / 2, IMG_HEIGHT / 2, cam_framesize);

	return CAM_CONFIGURED;
}
void cam_set_state(CameraState state) { cam_state = state; }

void cam_set_colormode(CamColorMode mode) {
	// if (SCCB_send_byte(REG_COM7, cam_color_mode[mode]))
	// 	;
	cam_set_effect(CAM_FX_BW);
	cam_colormode = mode;
}

void cam_set_framesize(CamFrameSize size) {
	uint8_t width = cam_sizes[size].width;
	uint8_t height = cam_sizes[size].height;
	uint8_t lsb = ((width & 0x03) | ((height & 0x01) << 2));
	uint8_t reg_val = 0;

	// select QVGA RGB
	SCCB_send_byte(REG_COM7, COM7_FORMAT_RGB565 | COM7_OUTPUT_RGB);

	SCCB_read_byte(REG_HREF, &reg_val, 1);
	SCCB_send_byte(REG_HSIZE, width >> 2);	 // set width
	SCCB_send_byte(REG_VSIZE, height >> 1);	 // set height
	SCCB_send_byte(REG_HREF, reg_val | lsb); // set all lsb of widthe and height

	SCCB_read_byte(REG_EXHCH, &reg_val, 1);
	SCCB_send_byte(REG_HOutSize, width >> 2);  // set output width
	SCCB_send_byte(REG_VOutSize, height >> 1); // set output height
	SCCB_send_byte(REG_EXHCH, reg_val | lsb);
	cam_framesize = size;
}

void cam_set_frameoffset(uint16_t off_x, uint16_t off_y) {
	uint8_t reg_val = 0, temp = 0;

	SCCB_read_byte(REG_HSTART, &reg_val, 1); // read offset
	temp = (reg_val + (off_x >> 2));
	SCCB_send_byte(REG_HSTART, temp);

	SCCB_read_byte(REG_VSTRT, &reg_val, 1);
	temp = (reg_val + (off_y >> 1));
	SCCB_send_byte(REG_VSTRT, temp);

	SCCB_read_byte(REG_HREF, &reg_val, 1);
	temp = (reg_val | ((off_x & 0x03) << 4) | ((off_y & 0x01) << 6));
	SCCB_send_byte(REG_HREF, temp);

	SCCB_send_byte(REG_DSPAuto, 0xff);
}

void cam_set_window(uint16_t off_x, uint16_t off_y, CamFrameSize size) {
	uint8_t reg_raw, cal_temp;
	uint16_t width = cam_sizes[size].width;
	uint16_t height = cam_sizes[size].height;

	SCCB_send_byte(REG_COM7, COM7_SELECT_QVGA | COM7_FORMAT_RGB565 | COM7_OUTPUT_RGB);

	SCCB_read_byte(REG_HSTART, &reg_raw, 1);
	// MSB 8 bit stored in HSTART, LSB 2 bit stored in HREF
	cal_temp = (reg_raw + (off_x >> 2));
	SCCB_send_byte(REG_HSTART, cal_temp);

	SCCB_read_byte(REG_VSTRT, &reg_raw, 1);
	// MSB 8 bit stored in VSTART, LSB 1 bit stored in HREF
	cal_temp = (reg_raw + (off_y >> 1));
	SCCB_send_byte(REG_VSTRT, cal_temp);

	// horizontal sensor width, MSB 8 bit stored in HSIZE, LSB 2bit stored in HREF
	SCCB_send_byte(REG_HSIZE, width >> 2);
	// vertical sensor height, MSB 8 bit stored in VSIZE, LSB 1 bit stored in HREF
	SCCB_send_byte(REG_VSIZE, height >> 1);

	SCCB_read_byte(REG_HREF, &reg_raw, 1);
	// store width LSB, height LSB, offset x LSB, offset y LSB in HREF
	cal_temp = (reg_raw | (width & 0x03) | ((height & 0x01) << 2) | ((off_x & 0x03) << 4) | ((off_y & 0x01) << 6));
	SCCB_send_byte(REG_HREF, cal_temp);

	// output size
	SCCB_send_byte(REG_HOutSize, width >> 2);
	SCCB_send_byte(REG_VOutSize, height >> 1);
	SCCB_read_byte(REG_EXHCH, &reg_raw, 1);
	cal_temp = (reg_raw | (width & 0x03) | ((height & 0x01) << 2));

	SCCB_send_byte(REG_EXHCH, cal_temp);

	cam_framesize = size;
}

void cam_set_framerate(CamFrameRate rate) {
	if (!SCCB_send_byte(REG_COM4, cam_rates[rate].pll))
		return;
	if (!SCCB_send_byte(REG_CLKRC, cam_rates[rate].clkrc))
		return;
	cam_framerate = rate;
}

void cam_set_zoomscale(float ratio) {
	SCCB_send_byte(REG_DSPAuto, 0xf0);									// disable auto scaling
	SCCB_send_byte(REG_SCAL1, (uint8_t)(ratio * SCAL1_ZOOM_RATIO_1_1)); // horizontal zoom
	SCCB_send_byte(REG_SCAL2, (uint8_t)(ratio * SCAL2_ZOOM_RATIO_1_1)); // vertical zoom
	cam_zoomscale = ratio;
}

void cam_set_sharpness(uint8_t strength, uint8_t thresh, uint8_t upperlim, uint8_t lowerlim) {
	SCCB_send_byte(REG_EDGE0, EDGE0_STRENGTH(strength));
	SCCB_send_byte(REG_EDGE1, EDGE1_THRESHOLD(thresh));
	SCCB_send_byte(REG_EDGE2, upperlim);
	SCCB_send_byte(REG_EDGE3, lowerlim);
}

void cam_set_lightmode(CamLightMode mode) {
	switch (mode) {
		case CAM_LIGHT_AUTO:				// Auto
			SCCB_send_byte(REG_COM8, 0xff); // AWB on
			SCCB_send_byte(REG_COM5, 0x65);
			SCCB_send_byte(REG_ADVFL, 0x00);
			SCCB_send_byte(REG_ADVFH, 0x00);
			break;
		case CAM_LIGHT_SUNNY:				// sunny
			SCCB_send_byte(REG_COM8, 0xfd); // AWB off
			SCCB_send_byte(REG_BLUE, 0x5a);
			SCCB_send_byte(REG_RED, 0x5c);
			SCCB_send_byte(REG_COM5, 0x65);
			SCCB_send_byte(REG_ADVFL, 0x00);
			SCCB_send_byte(REG_ADVFH, 0x00);
			break;
		case CAM_LIGHT_CLOUDY:				// cloudy
			SCCB_send_byte(REG_COM8, 0xfd); // AWB off
			SCCB_send_byte(REG_BLUE, 0x58);
			SCCB_send_byte(REG_RED, 0x60);
			SCCB_send_byte(REG_COM5, 0x65);
			SCCB_send_byte(REG_ADVFL, 0x00);
			SCCB_send_byte(REG_ADVFH, 0x00);
			break;
		case CAM_LIGHT_OFFICE:				// office
			SCCB_send_byte(REG_COM8, 0xfd); // AWB off
			SCCB_send_byte(REG_BLUE, 0x84);
			SCCB_send_byte(REG_RED, 0x4c);
			SCCB_send_byte(REG_COM5, 0x65);
			SCCB_send_byte(REG_ADVFL, 0x00);
			SCCB_send_byte(REG_ADVFH, 0x00);
			break;
		case CAM_LIGHT_HOME:				// home
			SCCB_send_byte(REG_COM8, 0xfd); // AWB off
			SCCB_send_byte(REG_BLUE, 0x96);
			SCCB_send_byte(REG_RED, 0x40);
			SCCB_send_byte(REG_COM5, 0x65);
			SCCB_send_byte(REG_ADVFL, 0x00);
			SCCB_send_byte(REG_ADVFH, 0x00);
			break;

		case CAM_LIGHT_NIGHT:				// night
			SCCB_send_byte(REG_COM8, 0xff); // AWB on
			SCCB_send_byte(REG_COM5, 0xe5);
			break;
		default: break;
	}
}

void cam_set_brightness(int8_t brightness) {
	uint8_t _sign = (brightness >= 0) ? 0x06 : 0x0E;
	uint8_t _brightness;

	switch (brightness) {
		case 4: _brightness = 0x48; break;
		case 3:
		case -4: _brightness = 0x38; break;
		case 2:
		case -3: _brightness = 0x28; break;
		case 1:
		case -2: _brightness = 0x18; break;
		case 0: _brightness = 0x00; break;
		case -1: _brightness = 0x08; break;
		default: _brightness = _sign = 0; break;
	}

	SCCB_send_byte(REG_BRIGHT, _brightness);
	SCCB_send_byte(REG_SIGN, _sign);
}

void cam_set_saturation(int8_t sat) {
	if (sat >= -4 && sat <= 4) {
		SCCB_send_byte(REG_USAT, (sat + 4) << 4);
		SCCB_send_byte(REG_VSAT, (sat + 4) << 4);
	}
}

void cam_set_contrast(int8_t contrast) {
	if (contrast >= -4 && contrast <= 4)
		SCCB_send_byte(REG_CNST, (0x30 - (4 - contrast) * 4));
}

void cam_set_effect(CamEffect effect) {
	switch (effect) {
		case CAM_FX_NORMAL: // normal
			SCCB_send_byte(REG_SDE, 0x06);
			SCCB_send_byte(REG_UFix, 0x80);
			SCCB_send_byte(REG_VFix, 0x80);
			break;

		case CAM_FX_BW: // Black and white
			SCCB_send_byte(REG_SDE, 0x26);
			SCCB_send_byte(REG_UFix, 0x80);
			SCCB_send_byte(REG_VFix, 0x80);
			break;

		case CAM_FX_BLUE: // blue
			SCCB_send_byte(REG_SDE, 0x1e);
			SCCB_send_byte(REG_UFix, 0xa0);
			SCCB_send_byte(REG_VFix, 0x40);
			break;

		case CAM_FX_SEPIA: // Sepia
			SCCB_send_byte(REG_SDE, 0x1e);
			SCCB_send_byte(REG_UFix, 0x40);
			SCCB_send_byte(REG_VFix, 0xa0);
			break;

		case CAM_FX_RED: // red
			SCCB_send_byte(REG_SDE, 0x1e);
			SCCB_send_byte(REG_UFix, 0x80);
			SCCB_send_byte(REG_VFix, 0xc0);
			break;

		case CAM_FX_GREEN: // green
			SCCB_send_byte(REG_SDE, 0x1e);
			SCCB_send_byte(REG_UFix, 0x60);
			SCCB_send_byte(REG_VFix, 0x60);
			break;

		case CAM_FX_NEGATIVE: // negative
			SCCB_send_byte(REG_SDE, 0x46);
			break;

		default: break;
	}
}
CameraState cam_get_state(void) { return cam_state; }
uint8_t cam_is_frame_ready(void) { return cam_state >= CAM_FRAME_READY; }
uint8_t cam_is_initialized(void) { return cam_state >= CAM_CONFIGURED; }
CamColorMode cam_get_colormode(void) { return cam_colormode; }
CamFrameSize cam_get_framesize(void) { return cam_framesize; }
float cam_get_zoomscale(void) { return cam_zoomscale; }

#pragma GCC push_options
#pragma GCC optimize("O0")
static __forceinline void read_fifo_pixel(uint16_t* rgb565) {
	*rgb565 = 0;
	FIFO_RCLK_L;
	*rgb565 = (OV7725_DATA_PORT->IDR << 2) & 0xFF00;
	FIFO_RCLK_H;
	FIFO_RCLK_L;
	*rgb565 |= (OV7725_DATA_PORT->IDR >> 6) & 0x00FF;
	FIFO_RCLK_H;
}

void cam_get_rgb565(uint16_t* image) {
	FIFO_PREPARE;
	uint16_t pixel = 0;
	for (uint16_t i = 0; i < IMG_WIDTH * IMG_HEIGHT; ++i) {
		read_fifo_pixel(&pixel);
		image[i] = pixel;
	}
	cam_state = CAM_CAPTURING;
}

void cam_rgb2printable(uint16_t* image, uint16_t* printable) {
	for (uint16_t i = 0; i < IMG_WIDTH * IMG_HEIGHT; ++i) {
		printable[i] = __REVSH(image[i]);
	}
}
#pragma GCC pop_options

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == OV7725_VSYNC_PIN) {
		if (cam_state == CAM_CAPTURING) {
			FIFO_WRST_L;
			FIFO_WE_H;

			cam_state = CAM_FRAME_READY;

			FIFO_WE_H;
			FIFO_WRST_H;
		} else if (cam_state == CAM_FRAME_READY) {
			FIFO_WE_L;
			cam_state = CAM_MISSED_FRAME;
		}
	}
}