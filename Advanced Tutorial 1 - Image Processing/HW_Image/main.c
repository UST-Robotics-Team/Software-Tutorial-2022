#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "qdbmp.h"

int main(void) {

    // START CODE HERE (you may test other 8-bit grayscale bmp)
    BMP* imageIn = BMP_ReadFile("bicycle.bmp");
    // END CODE HERE

    BMP_CHECK_ERROR(stdout, -1);

    int height = BMP_GetHeight(imageIn);
    int width  = BMP_GetWidth(imageIn);

    BMP* imageOut = BMP_Create(width, height, 8);
    for (int i=0; i<256; i++) {
    	BMP_SetPaletteColor(imageOut, i, i, i, i);
    }

    // START CODE HERE
    
    // END CODE HERE

    BMP_WriteFile(imageOut, "output.bmp");

    BMP_Free(imageIn);
    BMP_Free(imageOut);
    return 0;
}