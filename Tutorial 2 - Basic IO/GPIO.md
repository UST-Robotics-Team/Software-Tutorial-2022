# **Tutorial 2: Basic IO - GPIO**

[![HackMD Version](https://img.shields.io/badge/Made%20with-Markdown-1f425.svg)](https://hackmd.io/@ATKTC/BygTkzV0yo)

Original authors: Joseph Lam, Binay Gurung, Anshuman Medhi (Grand grand seniors)

Contact: mhlamaf@ust.hk, bgurung@ust.hk, amedhi@dontemailme.com and lywongav@connect.ust.hk
Modified by: Alex Chan, Leo Wong

Further Modified by: Christopher Kwan (ktckwan@connect.ust.hk)

***

## **Basics**

### **Fundamental Program Structure Example: Do something every 100ms**
```c
int main(void)
{
    // Initialize Everything Here, this is like setup() in Arduino
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();     //Initialize most GPIOs on board
    MX_DMA_Init();      //Initialize DMA

    // the following is like loop() in Arduino also
    //Run code in an infinite loop: this is like loop() in Arduino
    while (1) {
      static uint32_t last_ticks = 0;	//This variable keeps its stored value through every iteration
        //Everything inside this if-statements gets called every 100ms
      if((HAL_GetTick() - last_ticks) >= 100){
            //Write your code here....
            // sth ....
            // bruh....
          last_ticks = HAL_GetTick();
      }
    }
}
```

* The **`HAL_GetTick`** function is the main thing to use for timing control in software. It counts up by one every millisecond(ms).
***
### **Data Types**
In embedded system programming, Data type  `int`, `long`, `long long`, `float`, `double` are not suggested to use. Instead, use the followings:

| Short form | Full name          | Meaning                  |
| :--------: | :----------------- | :----------------------- |
| `uint8_t`  | unsigned char      | unsigned 8 bits integer  |
|  uint16_t  | unsigned short     | unsigned 16 bits integer |
|  uint32_t  | unsigned long      | unsigned 32 bits integer |
|  uint64_t  | unsigned long long | unsigned 64 bits integer |
|   int8_t   | signed char        | signed 8 bits integer    |
|  int16_t   | signed short       | signed 16 bits integer   |
|  int32_t   | signed long        | signed 32 bits integer   |
|  int64_t   | signed long long   | signed 64 bits integer   |

Both full name and short form work.

**Note:** 
* `float` and `double` should only be used when necessary as floating point calculation normally takes more time.

***
***

## **What is GPIO?**
>A **general-purpose input/output (GPIO)** is an digital signal pin on an integrated circuit or electronic circuit board whose behavior — including whether it acts as an input or output — is controllable by the user at run time.

>In short, GPIO is for ***outputting and reading HIGH [1] and LOW [0] values***. (Sometimes we will use GPIO for analogue values but don't worry about that for now)

### **GPIO Configuration**

* Every pin on the MCU can be used as GPIO, they are divided into a blocks of 16 pins due to internal structure
  * Each block is named by letters: `GPIOA`, `GPIOB`, `GPIOC`...
    * Each pin within the block is numbered from 0: `GPIO_PIN_0`, `GPIO_PIN_1`, `GPIO_PIN_2`...
* So every pin is referred to by a pair of values: the port and the pin: `GPIOE, GPIO_PIN_3` or when humans are talking we say `PE3`

***
### **`Macro`s for GPIO**
We will often use `#define` to give more meaningful names to the ports and pins, for ease of use:

```c
/* main.h */
#define UP_BTN_GPIO_Port     GPIOE
#define UP_BTN_Pin           GPIO_PIN_3
#define LED1_GPIO_Port       GPIOE
#define LED1_Pin             GPIO_PIN_4
#define LED2_GPIO_Port       GPIOE
#define LED2_PIN             GPIO_PIN_5
#define LED3_GPIO_Port       GPIOE
#define LED3_PIN             GPIO_PIN_6
```

* These defines are generated when you generate the HAL library from STM32CubeMX. You may change it at anytime to suit your need.
***
### **Initialization of GPIO (HAL Library Style)**

Any hardware that you want to use must be first initialized. This is basically setting it up so it can work they way you want it to.
* HAL library help you initialize the GPIO when the code is generated from STM32CudeMX. Inside the function `MX_GPIO_Init`
```c
/* gpio.c */
// ...

/*Configure GPIO pin Output Level */
/*
 * This initialized 4 LED pins to LOW 0
 *
 * Notice that all pins need to be in the SAME port in order
 * to use the | bitwise-or operator to chain up the pins.
 */
HAL_GPIO_WritePin(GPIOA, LED4_Pin|LED3_Pin|LED2_Pin|LED1_Pin, GPIO_PIN_RESET);

/*Configure GPIO pins : PAPin PAPin PAPin PAPin */
  GPIO_InitStruct.Pin = LED4_Pin|LED3_Pin|LED2_Pin|LED1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;     // Output Push-pull mode
  GPIO_InitStruct.Pull = GPIO_NOPULL;             // No pull-up or pull-down
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;    // Let's not worry that for now
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

/*Configure GPIO pins : PAPin PAPin */
  GPIO_InitStruct.Pin = UP_BTN_Pin|DOWN_BTN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;         // Input mode
  GPIO_InitStruct.Pull = GPIO_PULLUP;             // Pull-up
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
```

#### *  ___Various `GPIO Mode` and `GPIO Pull`___ options

```c
/* stm32f4xx_hal_gpio.h */
// Modes
#define  GPIO_MODE_INPUT        MODE_INPUT                /*!< Input Floating Mode                   */
#define  GPIO_MODE_OUTPUT_PP    (MODE_OUTPUT | OUTPUT_PP) /*!< Output Push Pull Mode                 */
#define  GPIO_MODE_OUTPUT_OD    (MODE_OUTPUT | OUTPUT_OD) /*!< Output Open Drain Mode                */
#define  GPIO_MODE_AF_PP        (MODE_AF | OUTPUT_PP)     /*!< Alternate Function Push Pull Mode     */
#define  GPIO_MODE_AF_OD        (MODE_AF | OUTPUT_OD)     /*!< Alternate Function Open Drain Mode    */

#define  GPIO_MODE_ANALOG       MODE_ANALOG

// Pull
#define  GPIO_NOPULL        0x00000000U   /*!< No Pull-up or Pull-down activation  */
#define  GPIO_PULLUP        0x00000001U   /*!< Pull-up activation                  */
#define  GPIO_PULLDOWN      0x00000002U   /*!< Pull-down activation                */
```

* It seems there are various modes and pulls in the initialization, right? In Gerneal, you actually only need to know 4 of them - `GPIO_MODE_INPUT`, `GPIO_MODE_OUTPUT_PP`, `GPIO_PULLUP`, `GPIO_PULLDOWN`.
***
### ___Input___ : `GPIO_MODE_INPUT`
- `GPIO_PULLUP` and `GPIO_PULLDOWN`- The GPIO Pin can be used to read the logical value of the pin
  - The point is to deal with the secret 3rd state of binary digital signals: **_floating pins_**. 
  * What happens when a pin is connected to nothing at all?
    - Noise will cause you to read a mostly random value
    - Therefore, The pull-up or pull-down gives a "_weak_" connection from the pin to either a high or low voltage. It gives a defined value to a floating pin while being weak enough to be easily overriden by any external signal.

### **Pull-up & Pull-down**
![when the GPIO is connected to a pull up resistor](https://i.imgur.com/iS3Od90.jpg)] ![when the GPIO is connected to a pull down resistor](https://i.imgur.com/sd7FdFC.jpg)

> One of the two set-ups here will read a high voltage when the button is on and low voltage when the button is off, while the other one is the opposite, can you tell me which is which and why?
> * keywords : short circuit, potential divider
***
### ___Output___   :  `GPIO_MODE_OUPUT_OD` and `GPIO_MODE_OUTPUT_PP`

- `GPIO_MODE_OUPUT_OD` and `GPIO_MODE_OUTPUT_PP` - The GPIO Pin can be used to output a digital signal using a pair of switches (see figure below)
  - **Push-pull(PP)** uses the 2 switches to connect the pin to either high voltage or low voltage, it pushes or pulls the voltage to the level assigned
  - **Open-drain(OD)** is similar  but does not use the upper switch, thus it outputs a low voltage or completely disconnects the pin
- `GPIO_MODE_AF_PP & OD` are the same but are for when the pin output is to be controlled by another bit of hardware, don't worry about it for now

Inside the MCU lives a pair of switches, ie.`transistors`:<br>
![](https://i.imgur.com/UerwY9k.png)
***
### **Reading GPIO Input in the Program**

The `HAL_GPIO_ReadPin` function reads the GPIO input.

```c
/* stm32f4xx_hal_gpio.h */
GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

// usage
uint8_t state = HAL_GPIO_ReadPin(BTN1_GPIO_Port, BTN1_Pin); // returns 0 or 1
```

* The `HAL_GPIO_ReadPin` functions returns 1 or 0 of that respective pin of the parameter.
***
#### Readability:

* Writing `HAL_GPIO_ReadPin(XXX_GPIO_Port, XXX_Pin)` every time may seem tidious. However with the help of magical c prepocessor, we can make it easier
```c
/* main.h */
#define gpio_read(gpio) HAL_GPIO_ReadPin(gpio##_GPIO_Port, gpio##_Pin)

// usage
uint8_t state = gpio_read(BTN1);
```

#### **Writing GPIO Output in the Program**

The following macros can be found in `main.h`

* The `gpio_set(gpio)` macro sets the GPIO pin to be 1.

* The `gpio_reset(gpio)` macro resets the GPIO pin to 0.

* The `gpio_toggle(gpio)` macro toggles the GPIO pin. (i.e. changes the GPIO pin state to 1 if it was originally 0 and vice versa)

#### **Examples:**

```c
// Turns off the LED
gpio_set(LED1);

// Turns on the LED
gpio_reset(LED1);

// Toggles the LED
gpio_toggle(LED1);
```

### **Full Example (Flickering the LED1 for every 500 ticks)**

```c
/* main.c */
int main(void) {

    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();

    volatile uint32_t last_ticks = HAL_GetTick();

    while (1) {

        if (HAL_GetTick() - last_ticks > 500) {
            last_ticks = HAL_GetTick();
            gpio_toggle(LED1); // flickering the LED1
        }
    }
    return 0;
}
```

***

### **Simplest uses for GPIO**

* ### There are **3 LEDs and 2 Buttons** on the board.

![LEDs](https://i.imgur.com/zgXchIn.jpg) 
![Buttons](https://imgur.com/gfiXdj9.jpg)

## **_Thinking Time_**:

### **What should the GPIO Mode and Pull be for each of the above and why?**

### There are few step before using GPIO pins in your program:

1. Find which GPIO you want to use in `main.h` (if you can't find one, define it yourself)
2. Initialize the GPIO Pin once in `gpio.h`. Remember which mode and pull you need for the pin 
3. Use the GPIO Functions to read or write the digital signals 

### **Button Example**

```c
// Initialising all gpio
MX_GPIO_Init();
// Remember the onboard button must be used with a pull up resistor

uint8_t pressed = btn_read(BTN1);
// Remember the onboard button will give a low signal when clicked, and a high signal otherwise
```

***
***
## We have **[Classwork](https://hackmd.io/@9xfAx11hQqOSlg1CQi2Azg/HyH3u_9R5)**  and **[Homework](https://hackmd.io/@9xfAx11hQqOSlg1CQi2Azg/HyH3u_9R5)** @_@.
***
***

