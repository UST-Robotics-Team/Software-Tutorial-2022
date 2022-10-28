# Integrate the camera library into your code [![made-with-HackMD](https://img.shields.io/badge/Made%20with-HackMD-1f425f.svg)](https://hackmd.io/@leowong12138/SksooMuwF)

Author: Leo

1. Open .ioc file to configure the timer

   > Activate TIM6 and set the prescaler value to `84-1`
   > Regenerate the code
   > ![](https://i.imgur.com/dVFQpCr.png)

2. Delete `MX_SPI1_Init()`, `MX_I2C2_Init()` in main if they exist.

3. Copy all the files in the library into corresponding folders `Inc` and `Src`. Noted that `tim.h`, `tim.c` and `main.c` are for reference only. If you have regenerated the code, there should be no need to copy these files.

4. Include `camera/camera.h` in `main.c`. You may look at the sample `main.c` to see how to use the library. Normally, what you will get is a `uint16_t` 1D array that stores the RGB value in RGB565 format. You may also call `cam_set_colormode(CAM_GRAYSCALE);` to get a grayscale image.

:::warning
The library will adapt a rolling update method. i.e. It will continuously update to provide more functionality or fix minor bugs. Please check the commit message as well as commit history periodically to receive the latest update.
