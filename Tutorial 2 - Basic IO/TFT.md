# **Tutorial 2: Basic IO - TFT**

Originally by Binay Gurung

Modified by Leo Wong

Further Modified by: Christopher Kwan (ktckwan@connect.ust.hk)
***

[![HackMD Version](https://img.shields.io/badge/Made%20with-Markdown-1f425.svg)](https://hackmd.io/@ATKTC/SkKJ7ECJi)


## **Printing something**
> When learning programming, most of the integrated development environment (IDE) you will/might have used will have a console for output and will often be used for debugging for you to keep track of certain variables and to trace-out truth tables or so forth.

>  In different programming languages, you can print/show your variable's value in the program using print function.

### For Example

In C,

```c
int c = 25;
printf("The value of c-squared is : %d",c*c);
//Output will come as "The value of c-squared is : 625"
```

In Python,

```py
c = 25
print("The value of c-squared is: ",c*c) # c**2
#Output will come as "The value of c-squared is : 625"
```

In Java,

```java
int c = 25;
System.out.println("The value of c-squared is ",c*c);
//Output will come as "The value of c-squared is : 625"
```

In our embedded system, usually we do not have a console to output our variable values to when debugging. 

However, with the help of TFT (a small LCD monitor), you will be able to **"print out"** the values of your variable on a **monitor**.

***
## **Initialize TFT**

### Function Prototype

```c
void tft_init(TFT_ORIENTATION orientation, uint16_t bg_color, uint16_t text_color, uint16_t text_color_sp, uint16_t highlight_color);
```

### **Parameters**

- orientation - ***Orientation of the monitor***
- bg_color - ***Background color***
- text_color - ***Text color***
- text_color_sp - ***Special Text color*** - `[]`
- highlight_color - ***Highlight color*** - `{}`

The parameters have already been defined for you in `lcd.h` header-file. It is defined as follows:

### * **Orientation**

```c
typedef enum {
    PIN_ON_TOP,
    PIN_ON_LEFT,
    PIN_ON_BOTTOM,
    PIN_ON_RIGHT
} TFT_ORIENTATION;
```

### * **Colors**

You may choose one of the following colours according to your own desire for the **TFT**.
Of course! You may also define new color yourself. The following are RGB565 format

```c
#define WHITE           (RGB888TO565(0xFFFFFF))
#define BLACK           (RGB888TO565(0x000000))
#define DARK_GREY       (RGB888TO565(0x555555))
#define GREY            (RGB888TO565(0xAAAAAA))
#define RED             (RGB888TO565(0xFF0000))
#define DARK_RED        (RGB888TO565(0x800000))
#define ORANGE          (RGB888TO565(0xFF9900))
#define YELLOW          (RGB888TO565(0xFFFF00))
#define GREEN           (RGB888TO565(0x00FF00))
#define DARK_GREEN      (RGB888TO565(0x00CC00))
#define BLUE            (RGB888TO565(0x0000FF))
#define BLUE2           (RGB888TO565(0x202060))
#define SKY_BLUE        (RGB888TO565(0x11CFFF))
#define CYAN            (RGB888TO565(0x8888FF))
#define PURPLE          (RGB888TO565(0x00AAAA))
#define PINK            (RGB888TO565(0xC71585))
#define GRAYSCALE(S)    (2113*S)
```

### **Example:**

```c
/*
 * Initialisation Example
 *
 * Orientation : Pin_on_top
 * Background color : black
 * Text color : white
 * Special Text color : red
 * Highlight color : dark green
 */

tft_init(PIN_ON_TOP, BLACK, WHITE, RED, DARK_GREEN);
```

### **Print String**

```c
void tft_prints(uint8_t x, uint8_t y, const char* fmt, ...);
```

- **x**: nth horizontal column ranging from 0 to 15 (16 columns)
- **y**: nth vertical row, ranging from 0 to 9 (10 rows)
- **fmt**: string with format templates (same as C's printf)
- **...** : variable to replace the placeholder in the string (same as C's printf)

### **Example**

```c
int a = 10;
tft_prints(0, 0, "The value of a is %d", a);
// The value of a is 10

tft_prints(0, 1, "The |underlined| word");
// "underlined" is underlined by a pair of |

tft_prints(0, 2, "Escape [this `[`]]");
// Escape this []
// first pair of [] changes text inside to special text color
// use ` (backtick) to escape the character right after
```

### **Print Pixel**

```c
void tft_print_pixel(uint16_t color, uint32_t x, uint32_t y);
```

- **color** : colour of your pixel (Use the #define colours)
- **x** : n-th horizontal pixel, ranging from 0 to 127
- **y** : n-th vertical pixel , ranging from 0 to 159

### **Update**

```c
uint8_t tft_update(uint32_t period);
uint8_t tft_update2(uint32_t period);

// update the screen to print text and colors
```

- **period** : period of update in ms

### **Miscellaneous**

```c
void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);

void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);

void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color)
```

### **Example of using TFT**

```c
while(1){
    /*This is referring to your main while(1) loop,
      Do not create another while(1)*/
    if(tft_update(50) == 0){
        tft_prints(0, 0, "Hello World"); // normal
        tft_prints(0, 1, "[Hello World]");  // This is a special text with differnt color
        tft_prints(0, 2, "{Hello World}");  // This is a higlighted text
        tft_prints(0, 3, "|Hello World|");  // This is a underlined text
    }
}
```

***
## **At last, Do forget to include the library in your program**
```c
#include "xxx.h"
``` 
FYI: There are some functions it will be useful.

***
***
## **[Classwork](https://hackmd.io/@9xfAx11hQqOSlg1CQi2Azg/HyH3u_9R5)**  and **[Homework](https://hackmd.io/@9xfAx11hQqOSlg1CQi2Azg/HyH3u_9R5)** #_#.
***
***