# **Classwork**

## Skeleton code

Remember to add the function prototypes in `main.c` for the declaration of the functions, as follow:

```c
/* main.c */
/* USER CODE BEGIN PFP */
void gpio_classwork(void);
void tft_classwork(void);
/* USER CODE END PFP */
```
***
***
## **Task 1** :GPIO

- When `BTN1` is held, `LED1` should be on. **(@1)**
- When `BTN2` is held, `LED2` should be flashing (toggle in 50ms).**(@1)**
- When both `BTN1` and `BTN2` are held, the following sequence is conducted:**(@2)**
  - `LED1` and `LED3` are on while `LED2` are flashing.
  - After 1 second, `LED1` and `LED3` are flashing while `LED2` are on.
  - After 1 second, repeat from step 1.
* Keyword: Finite State Machine FSM

* ![](https://i.imgur.com/zF0Q2Lg.gif)
    * LED1 RED
    * LED2 GREEN
    * LED3 BLUE
    * BTN1 RED one
    * BTN2 GREEN one
    * Order: BTN2 -> BTN1 -> BTN1 & BTN2


## **Task 2** :TFT

- Print the time elapsed with the format of `mm:ss:sssZ` where `sssZ` means millisecond. e.g. `00:23:109` **(@2)**
- Print a 50px $\times$ 50px square directly under the elapsed time where its color changes when 1 second passed.**(@2)**
* Keywords: `HAL_GetTick`
* Hints:
    * $1234 \mod 10 = 4$
    * Integer division ${{1234}\over{10}} = 123$
    * $\text{1 min = 60 second, 1 second = 1000 milisecond}$
* ![](https://i.imgur.com/2K6QaHR.gif)
    * The actual size of square printed on TFT should be larger than this one
> Dont use`__forceinline static void fillRect(int16_t x, int16_t y, int16_t w, int16_t h,
        uint16_t color) ` as it seems to cause error

***
***

# **Homework**
Before start doing hw, You may find these defines in `lcd.h` useful:

```c
#define CHAR_WIDTH 8
#define CHAR_HEIGHT 16

#define MAX_WIDTH 128
#define MAX_HEIGHT 160

#define CHAR_MAX_X_VERTICAL 16
#define CHAR_MAX_Y_VERTICAL 10

#define CHAR_MAX_X_HORIZONTAL 20
#define CHAR_MAX_Y_HORIZONTAL 8

#define CHAR_MAX_X 20  // max between CHAR_MAX_X_VERTICAL and CHAR_MAX_X_HORIZONTAL
#define CHAR_MAX_Y 10  // max between CHAR_MAX_Y_VERTICAL and CHAR_MAX_Y_HORIZONTAL
```

## **Edge Triggering vs Level Triggering**

Consider 2 uses for **a** button: (choose BTN1 or BTN2)

### **Q1 Level Triggering** 

- While the button is down, print `Hello, (Your name)` on TFT **(@1)**
*  While it is not, flash the LED (at least one LED). **(@1)**
* Two actions should not happen simultaneously.
* Hints:
  - In this case every time the loop comes around, we are concerned with the **current state** (or level) of the buttons GPIO Pin
  - The implementation of the button reading here should be obvious and simple

![](https://i.imgur.com/qSrTmjr.gif)
    * The green button and the green LED
***
### **Q2 Edge Triggering** 

- We wanted to print `Hello, (Your name)` for 1 second when the button is clicked (<200 ms), but only once, so holding the button does nothing more. **(@1)**
* When the button is released, we want to flash the LED for 1 second, but again only once. **(@1)** 
* The process repeats. i.e. it will print text again if you click the button. **(@1)**
* Keywords:
  - The event of a signal going from low to high is called the ___rising edge___ and the opposite is the ___falling edge___
  - The `gpio_read()` macro gives us the current state, but edge triggering also requires knowledge of the **past state** as well as some logic

* Hints: How can we design some code that can call a function _only_ when the button is first clicked? (Rising edge)

***
### **Bonus**

- Create a sprite in the middle of the screen. (Can be in any shape other than simple rectangle) **(@1)**
- It will move to the left for one `CHAR_WIDTH` when `BTN1` is clicked and released, 
* move to the right for one `CHAR_WIDTH` when `BTN2` is clicked and released. **(@2 for both short press)**
- **Long press (> 300ms)** and release `BTN1` for it to move up for one `CHAR_HEIGHT`.
* **Long press** and release `BTN2` for it to move down for one `CHAR_HEIGHT`. **(@4 for both long press)**
***
# FAQ
***
# Check the Homework in Hall9 LAB
