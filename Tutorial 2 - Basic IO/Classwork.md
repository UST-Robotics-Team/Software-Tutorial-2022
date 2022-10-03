# **Classwork**

[![HackMD Version](https://img.shields.io/badge/Made%20with-Markdown-1f425.svg)](https://hackmd.io/@ATKTC/HyH3u_9R5)

## TFT library

***
## Skeleton code

Get the skeleton code [here]() and drag it into your directory. Comment out the lcd include first, we are not using it for now. Also, add the function prototypes in `main.c` for the declaration of the functions.

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

- When `BTN1` is held, `LED1` should be on.
- When `BTN2` is held, `LED2` should be flashing (toggle in 50ms).
- When both `BTN1` and `BTN2` are held, the following sequence is conducted:
  - `LED1` and `LED3` are on while `LED2` are flashing.
  - After 1 second, `LED1` and `LED3` are flashing while `LED2` are on.
  - After 1 second, repeat from step 1.
* Keyword: Finite State Machine FSM

## **Task 2** :TFT

- Print the time elapsed with the format of `mm:ss:sssZ` where `sssZ` means millisecond. e.g. `00:23:109`
- Print a 50px $\times$ 50px square directly under the elapsed time where its color changes when 1 second passed.
* Keywords: `HAL_GetTick`

You may find these defines in `lcd.h` useful:

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
***
***

# **Homework**

## **Edge Triggering vs Level Triggering**

Consider 2 uses for **a** button:
***
### **Q1 Level Triggering** 

- While the button is down, print `Hello, (Your name)` on TFT 
*  While it is not, flash the LED. 
* Two actions should not happen simultaneously.
* Hints:
  - In this case every time the loop comes around, we are concerned with the **current state** (or level) of the buttons GPIO Pin
  - The implementation of the button reading here should be obvious and simple
***
### **Q2 Edge Triggering** 

- We wanted to print `Hello, (Your name)` for 1 second when the button is clicked (<200 ms), so holding the button does nothing. 
* When the button is released, we want to flash the LED for 1 second. 
* The process repeats. i.e. it will print text again if you click the button. 
* Keywords:
  - The event of a signal going from low to high is called the ___rising edge___ and the opposite is the ___falling edge___
  - The `gpio_read()` macro gives us the current state, but edge triggering also requires knowledge of the **past state** as well as some logic

* Hints: How can we design some code that can call a function _only_ when the button is first clicked? (Rising edge)
***
### **Bonus**

- Create a sprite in the middle of the screen. (Can be in any shape other than simple rectangle) 
- It will move to the left for one `CHAR_WIDTH` when `BTN1` is clicked and released, 
* move to the right for one `CHAR_WIDTH` when `BTN2` is clicked and released. 
- **Long press (> 300ms)** and release `BTN1` for it to move up for one `CHAR_HEIGHT`. 
* **Long press** and release `BTN2` for it to move down for one `CHAR_HEIGHT`. 

***

## How to submit
Please refer to this markdown document [Link](https://github.com/UST-Robotics-Team/Software-Tutorial-2022/blob/main/Homework_demo.md)
