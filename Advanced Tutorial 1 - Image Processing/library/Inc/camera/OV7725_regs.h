#ifndef __OV7725_REGS_H
#define __OV7725_REGS_H

// Definitions of OV7725 Register addresses
#define OV7725_ADDR 0x42
#define OV7725_ID	0x21

// @formatter:off
// clang-format off
#define REG_GAIN      0x00
#define REG_BLUE	  0x01
#define REG_RED		  0x02
#define REG_GREEN	  0x03

// automatically updated base on chip output format
#define REG_BAVG	  0x05 // U / B
#define REG_GAVG	  0x06 // Y / G
#define REG_RAVG	  0x07 // V / R
#define REG_AECH	  0x08 // MSBs for exposure value [15:8]

#define REG_COM2	  0x09
    #define COM2_SOFT_SLEEP (1<<4)
    #define COM2_ODRIVE(X)  ((X) & 0x3) // output drive capability

#define REG_PID		  0x0A
#define REG_VER		  0x0B

#define REG_COM3	  0x0C
    #define COM3_VFLIP                (1<<7)
	#define COM3_HMIRROR              (1<<6)
	#define COM3_SWAP_BR              (1<<5)
	#define COM3_SWAP_YUV             (1<<4)
	#define COM3_SWAP_ENDIAN          (1<<3)
	#define COM3_DISABLE_TRISTATE_CLK (1<<2)
	#define COM3_DISABLE_TRISTATE_DAT (1<<1)
	#define COM3_ENABLE_TEST_PATTERN  (1<<0) 

#define REG_COM4	  0x0D
    #define COM4_PLL(X)        (((X) & 0x3) << 6)
	#define COM4_AEC_WINDOW(X) (((X) & 0x3) << 4)
	#define COM4_RESERVED(X)   (((X) & 0xF) | 0x1)

#define REG_COM5	  0x0E
    #define COM5_AUTOFRAMERATE_ENABLE          (1<<7)
	#define COM5_AUTOFRAMERATE_SPEED           (1<<6)
	#define COM5_AUTOFRAMERATE_MAX(X)          (((X) & 0x3) << 4)
	#define COM5_AUTOFRAMERATE_ACTIVE_POINT(X) (((X) & 0x3) << 2)
	#define COM5_DISABLE_AEC_MAX_STEP          (1<<0)

#define REG_COM6	  0x0F
    #define COM6_ENABLE_AUTOWINDOW_FORMAT_CHANGE (1<<0)
	#define COM6_RESERVED(X)                     (((X) & 0x1) | 0x42)

#define REG_AEC		  0x10 // LSBs for exposure value [7:0]
#define REG_CLKRC	  0x11
    #define CLKRC_RESERVED(X)  ((X) | 0x80)
	#define CLKRC_NO_PRESCALER (1<<6)
	#define CLKRC_PRESCALER(X) ((X) & 0x1F)

#define REG_COM7	  0x12
    #define COM7_REGISTER_RESET  (1<<7)
	#define COM7_SELECT_QVGA     (1<<6)
	#define COM7_SELECT_VGA      (0<<6)
	#define COM7_BT656_ENABLE    (1<<5)
	#define COM7_RAW_ENABLE      (1<<4) // must enable before outputting RAW
	#define COM7_FORMAT_GBR422   (0<<2)
	#define COM7_FORMAT_RGB565   (1<<2)
	#define COM7_FORMAT_RGB555   (2<<2)
	#define COM7_FORMAT_RGB444   (3<<2)
	#define COM7_OUTPUT_YUV      (0<<0)
	#define COM7_OUTPUT_PROC_RAW (1<<0) // Bayer
	#define COM7_OUTPUT_RGB      (2<<0)
	#define COM7_OUTPUT_RAW      (3<<0) // bayer
	#define COM7_RESERVED(X)     ((X) & 0x7F)

#define REG_COM8	  0x13
    #define COM8_ENABLE_FAST_AGCAEC       (1<<7)
	#define COM8_AEC_UNLIMITED_STEP_SIZE  (1<<6)
	#define COM8_AEC_STEP_SIZE_LIM_VBLANK (0<<6)
	#define COM8_ENABLE_BANDING_FILTER    (1<<5)
	#define COM8_ENABLE_AEC_BELOW_BANDING (1<<4)
	#define COM8_ENABLE_FINE_AEC          (1<<3)
	#define COM8_ENABLE_AGC               (1<<2)
	#define COM8_ENABLE_AWB               (1<<1)
	#define COM8_ENABLE_AEC               (1<<0)

#define REG_COM9	  0x14
    #define COM9_HISTOGRAM_AECAGC   (1<<7)
	#define COM9_MAX_AGC(X)         (((X) <= 4) ? ((X) << 4) : (0))
	#define COM9_DROP_CORRUPT_VSYNC (1<<2)
	#define COM9_DROP_CORRUPT_HREF  (1<<1)
	#define COM9_RESERVED(X)        (((X) & 0x09 ) | 0x08)

#define REG_COM10	  0x15
    #define COM10_OUTPUT_NEGATIVE       (1<<7)
	#define COM10_HSYNC_NOT_HREF        (1<<6)
	#define COM10_NO_PCLK_DURING_HBLANK (1<<5)
	#define COM10_REVERSE_PCLK          (1<<4)
	#define COM10_REVERSE_HREF          (1<<3)
	#define COM10_VSYNC_FALLING_PCLK    (0<<2)
	#define COM10_VSYNC_RISING_PCLK     (1<<2)
	#define COM10_NEGATIVE_VSYNC        (1<<1)
	#define COM10_ONLY_8MSBS            (1<<0)

#define REG_REG16	  0x16
	#define REG16_BIT_SHIFT_TEST (1<<7)

#define REG_HSTART	  0x17
#define REG_HSIZE	  0x18
#define REG_VSTRT	  0x19
#define REG_VSIZE	  0x1A
#define REG_PSHFT	  0x1B
#define REG_MIDH	  0x1C
#define REG_MIDL	  0x1D
#define REG_LAEC	  0x1F
#define REG_COM11	  0x20
	#define COM11_ENABLE_SINGLE_FRAME  (1<<1)
	#define COM11_SINGLE_FRAME_TRIGGER (1<<0)
	#define COM11_RESERVED(X)          (((X) & (~0x3)) | 0x10)

#define REG_BDBase	  0x22
#define REG_BDMStep	  0x23
#define REG_AEW		  0x24
#define REG_AEB		  0x25
#define REG_VPT		  0x26
#define REG_REG28	  0x28
#define REG_HOutSize  0x29
#define REG_EXHCH	  0x2A
#define REG_EXHCL	  0x2B
#define REG_VOutSize  0x2C
#define REG_ADVFL	  0x2D
#define REG_ADVFH	  0x2E
#define REG_YAVE	  0x2F
#define REG_LumHTh	  0x30
#define REG_LumLTh	  0x31
#define REG_HREF	  0x32
#define REG_DM_LNL	  0x33
#define REG_DM_LNH	  0x34
#define REG_ADoff_B	  0x35
#define REG_ADoff_R	  0x36
#define REG_ADoff_Gb  0x37
#define REG_ADoff_Gr  0x38
#define REG_Off_B	  0x39
#define REG_Off_R	  0x3A
#define REG_Off_Gb	  0x3B
#define REG_Off_Gr	  0x3C
#define REG_COM12	  0x3D
#define REG_COM13	  0x3E
	#define COM13_BLC_ENABLE           (1<<7)
	#define COM13_ADC_BLC_ENABLE       (1<<6)
	#define COM13_ANA_BLC_ENABLE       (1<<5)
	#define COM13_ABLC_GAINTRIG_ENABLE (1<<2)
	#define COM13_RESERVED(X)          (((X) & 0xE4) | 0x02)
	#define COM13_DEFAULT              COM13_RESERVED(COM13_BLC_ENABLE|COM13_ADC_BLC_ENABLE|COM13_ANA_BLC_ENABLE)

#define REG_COM14	  0x3F
	#define COM14_USE_R_FOR_B            (0)
	#define COM14_USE_Gr_FOR_Gb          COM14_USE_R_FOR_B
	#define COM14_USE_B_FOR_R            (1)
	#define COM14_USE_Gb_FOR_Gr          COM14_USE_R_FOR_B
	#define COM14_USE_BR_INDEPENDENTLY   (3)
	#define COM14_USE_GbGr_INDEPENDENTLY COM14_USE_BR_INDEPENDENTLY	
	#define COM14_AD_OFFSET(X)           (((X) << 2) & 0xC)
	#define COM14_ANALOG_OFFSET(X)       (((X) << 0) & 0x3)
	#define COM14_RESERVED(X)            (((X) & 0xF))

#define REG_COM15     0x40
	#define COM15_AD_ADD_128_OFFSET (1<<3)
	#define COM15_RESERVED(X)       (((X) & 0xF7))

#define REG_COM16	  0x41
	#define COM16_BLC_2LSB(X) ((X) & 0x2)
	#define COM16_RESERVED(X) ((X) & 0xFC)

#define REG_TGT_B	  0x42
#define REG_TGT_R	  0x43
#define REG_TGT_Gb	  0x44
#define REG_TGT_Gr	  0x45
#define REG_LC_CTR	  0x46
	#define LC_CTR_USE_SEPARATE_COEF (1<<2)
	#define LC_CTR_ENABLE            (1<<0)  
#define REG_LC_XC	  0x47
	#define LC_XC_POSITIVE  (0<<7)
	#define LC_XC_NEGATIVE  (1<<7)
	#define LC_XC_X_COOR(X) ((X) & 0x7F) 
#define REG_LC_YC	  0x48
	#define LC_YC_POSITIVE  (0<<7)
	#define LC_YC_NEGATIVE  (1<<7)
	#define LC_YC_Y_COOR(Y) ((Y) & 0x7F)
#define REG_LC_COEF	  0x49
#define REG_LC_RADI	  0x4A
#define REG_LC_COEFB  0x4B
#define REG_LC_COEFR  0x4C
#define REG_FixGain	  0x4D
	#define FixGain_Gb(X) (((X) & 0x3) << 6)
	#define FixGain_Gr(X) (((X) & 0x3) << 4)
	#define FixGain_B(X)  (((X) & 0x3) << 2)
	#define FixGain_R(X)  (((X) & 0x3) << 0)
#define REG_AREF1	  0x4F
#define REG_AREF6	  0x54
#define REG_UFix	  0x60
#define REG_VFix	  0x61
#define REG_AWBb_blk  0x62
#define REG_AWB_Ctrl0 0x63
#define REG_DSP_Ctrl1 0x64
	#define DSP_Ctrl1_FIFO_ENABLE             (1<<7)
	#define DSP_Ctrl1_UVADJ_ENABLE            (1<<6)
	#define DSP_Ctrl1_SDE_ENABLE              (1<<5)
	#define DSP_Ctrl1_COLOR_MATRIX_ENABLE     (1<<4)
	#define DSP_Ctrl1_INTERPOLATION_ENABLE    (1<<3)
	#define DSP_Ctrl1_GAMMA_ENABLE            (1<<2)
	#define DSP_Ctrl1_BLACK_DEFECT_CORRECTION (1<<1)
	#define DSP_Ctrl1_WHITE_DEFECT_CORRECTION (1<<0)
#define REG_DSP_Ctrl2 0x65
    #define DSP_Ctrl2_VERT_DOWNSAMPLE_EN (1<<3)
	#define DSP_Ctrl2_HORZ_DOWNSAMPLE_EN (1<<2)
	#define DSP_Ctrl2_VERT_ZOOM_EN       (1<<1)
	#define DSP_Ctrl2_HORZ_ZOOM_EN       (1<<0)
	#define DSP_Ctrl2_RESERVED(X)        ((X) & 0xF)
#define REG_DSP_Ctrl3 0x66
#define REG_DSP_Ctrl4 0x67
#define REG_AWB_bias  0x68
#define REG_AWBCtrl1  0x69
#define REG_AWBCtrl2  0x6A
#define REG_AWBCtrl3  0x6B
#define REG_AWBCtrl4  0x6C
#define REG_AWBCtrl5  0x6D
#define REG_AWBCtrl6  0x6E
#define REG_AWBCtrl7  0x6F
#define REG_AWBCtrl8  0x70
#define REG_AWBCtrl9  0x71
#define REG_AWBCtrl10 0x72
#define REG_AWBCtrl11 0x73
#define REG_AWBCtrl12 0x74
#define REG_AWBCtrl13 0x75
#define REG_AWBCtrl14 0x76
#define REG_AWBCtrl15 0x77
#define REG_AWBCtrl16 0x78
#define REG_AWBCtrl17 0x79
#define REG_AWBCtrl18 0x7A
#define REG_AWBCtrl19 0x7B
#define REG_AWBCtrl20 0x7C
#define REG_AWBCtrl21 0x7D
#define REG_GAM1	  0x7E
#define REG_GAM2	  0x7F
#define REG_GAM3	  0x80
#define REG_GAM4	  0x81
#define REG_GAM5	  0x82
#define REG_GAM6	  0x83
#define REG_GAM7	  0x84
#define REG_GAM8	  0x85
#define REG_GAM9	  0x86
#define REG_GAM10	  0x87
#define REG_GAM11	  0x88
#define REG_GAM12	  0x89
#define REG_GAM13	  0x8A
#define REG_GAM14	  0x8B
#define REG_GAM15	  0x8C
#define REG_SLOP	  0x8D
#define REG_DNSTh	  0x8E
#define REG_EDGE0	  0x8F
	#define EDGE0_STRENGTH(X) (((X) < 16) ? (X) : (16))
#define REG_EDGE1	  0x90
	#define EDGE1_THRESHOLD(X) (((X) < 16) ? (X) : (16))
#define REG_DNSOff	  0x91
#define REG_EDGE2	  0x92
#define REG_EDGE3	  0x93
#define REG_MTX1	  0x94
#define REG_MTX2	  0x95
#define REG_MTX3	  0x96
#define REG_MTX4	  0x97
#define REG_MTX5	  0x98
#define REG_MTX6	  0x99
#define REG_MTX_Ctrl  0x9A
#define REG_BRIGHT	  0x9B
#define REG_CNST	  0x9C
#define REG_UVADJ0	  0x9E
#define REG_UVADJ1	  0x9F
#define REG_SCAL0	  0xA0
	#define SCAL0_VERT_DOWNSAMPLE_1X    (0x0<<2)
	#define SCAL0_VERT_DOWNSAMPLE_2X    (0x1<<2)
	#define SCAL0_VERT_DOWNSAMPLE_4X    (0x2<<2)
	#define SCAL0_VERT_DOWNSAMPLE_8X    (0x3<<2)
	#define SCAL0_HORZ_DOWNSAMPLE_1X    (0x0<<0)
	#define SCAL0_HORZ_DOWNSAMPLE_2X    (0x1<<0)
	#define SCAL0_HORZ_DOWNSAMPLE_4X    (0x2<<0)
	#define SCAL0_HORZ_DOWNSAMPLE_8X    (0x3<<0)
	#define SCAL0_DOWNSAMPLE_2_POW_N(N) (((N) << 2) | (N))
	#define SCAL0_RESERVED(X)           ((X) & 0xF)
#define REG_SCAL1	  0xA1 // horizontal scaling
	#define SCAL1_ZOOM_RATIO_1_1 0x40
#define REG_SCAL2	  0xA2 // vertical scaling 
	#define SCAL2_ZOOM_RATIO_1_1 0x40
#define REG_SDE		  0xA6
	#define SDE_FXEN_NEGATIVE    (1<<6)
	#define SDE_FXEN_GRAYSCALE   (1<<5)
	#define SDE_FXEN_FIXEDV      (1<<4)
	#define SDE_FXEN_FIXEDU      (1<<3)
	#define SDE_FXEN_CNSTBRGHT   (1<<2)
	#define SDE_FXEN_SATURATION  (1<<1)
	#define SDE_FXEN_HUE         (1<<0)
	#define SDE_FXEN_RESERVED(X) ((X) & 0x7F)
#define REG_USAT	  0xA7
#define REG_VSAT	  0xA8
#define REG_HUECOS	  0xA9
#define REG_HUESIN	  0xAA
#define REG_SIGN	  0xAB
#define REG_DSPAuto	  0xAC
	#define DSPAuto_AWB_AUTOTHRESH (1<<7)
	#define DSPAuto_DENOISE_AUTOTHRESH (1<<6)
	#define DSPAuto_SHARP_AUTOSTRENGTH (1<<5)
	#define DSPAuto_UV_AUTOSLOPE (1<<4)
	#define DSPAuto_AUTOSCAL0 (1<<3)
	#define DSPAuto_AUTOSCAL1 (1<<2)
	#define DSPAuto_RESERVED(X) ((X)&0xFC)

// @formatter:on
// clang-format on

#endif