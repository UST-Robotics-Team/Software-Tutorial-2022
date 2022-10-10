# Tutorial 3 - Advanced IO(PWM) [![HackMD Version](https://img.shields.io/badge/Made%20with-Markdown-1f425f.svg)](https://hackmd.io/@ytyk668/HysNzr5p9)

Author Details (TL:DR;)
Authors: Kelvin Leonardo

Modified by: Law a.k.a. Johnny Lo a.k.a. Lo King Lam

Stolen by: Amber
Stolen again by: Katie

Contact: Katie (tyyeungah@connect.ust.hk)

## Concept of PWM
### Why do we need PWM signal?
For controlling the DC motor and servo motor.

The Solution: 

**Pulse Width Modulation(PWM)** - We'll take a look into the total amount of *on-off time* of a signal. And utilize this data, rather than just the current state, to convey useful information.

## How to Generate PWM Signals?

Using Timers. 

The above term will be explained in detail in the following notes. So no need to worry.

### There are two main components of PWM generation:
1. The output frequency
2. The on-time (The time of "HIGH voltage")
    - (***Duty Cycle***) which is **on-time** to **period** ratio
    - in Second
    
![123](https://i.imgur.com/kcznbWB.png)
REF: elec 1100 lecture10 (2022, Deparment of Electronic and Computer Engineering, HKUST)
![](https://i.imgur.com/jnZB3Kd.jpg)
![](https://i.imgur.com/7Iyfnpg.jpg)

The data-sheet will usually provide the frequency and on-time (pulse) to use. The SG90 servo uses 50 Hz and 1-2ms on-time.

We will also use PWM signal to control a DC motor, which duty cycle implies the output power of the DC motor. For example letting the motor to spin at a lower speed.

## The output frequency (in second)

#### General concept frequency:
$f = \frac{1}{Period}$
#### Frequency of clock (MCU_Clock):
The timer of clock (in our borad we are using 84MHz)
#### Frequency of PWM:
The output (or desired frequency) for the motors
#### Prescaler value(PSC):
a 16-bit unsigned integer
#### Auto-reloaded counter(ARR):
a 16-bit unsigned integer

![](https://imgur.com/YF8xjhF.png)

#### The Prescaler value of the upper picture is 1
As you can see, when there are 2 peaks in the **MCU_Clock**, 1 peak in **Clock after Prescaler** is generated. So the prescaler value must be 2 right? No! As we are programmers, we always count from 0. So, the **Prescaler value = 1.**

#### The Auto-reloaded counter of the upper picture is 36
As you can see, when there are 37 peaks in **Clock after Prescaler**, the **Auto-reloaded counter** increases by 1, when the value is > 36, 1 peak in Counter overflow is generated and the counter is reset to 0. Again, we are programmers, so the **Auto-reloaded counter = 36.**

On the above picture you can see that the **prescaler value** and **auto-reload counter** help reduce the frequency of the **MCU_Clock** and generate a lower frequency. 

The **Prescaler value** and **Auto-reload value** are limited to a 16-bit unsigned integer only. Thus, the maximum value of both values is $2^{16} - 1 = 65535$.

The purpose of having both of them is that our MCU runs at a high frequency. If we were to work with servos (assume they require 50Hz) and use only the Prescaler or only the Auto-Reload, we won't be able to reduce to the targeted frequency. That's why we need both.

The difference between the two is that **Prescaler value** is just aiming to reduce the frequency, while **auto-reload counter** also aims as a counter.

After all, how do we get the output frequency???

$Freqency\:Output = \frac{Frequency \: of\:clock}{(Prescaler\:Value+1) \cdot (Auto-reloaded\: counter+1)}$

### Classwork 1
:::info 
If we need a frequency output of 50Hz, what are the 3 possible combinations of prescaler value and auto-reload value? (Given that the clock frequency is 84MHz)
:::

## The On-time(duty cycle)

#### Duty cycle:
According to the figure below, the number on the left-hand side is the duty cycle, it means the percentage of time that a signal is given as "high"(or 5V). $i.e. \frac{On-Time}{Period}$


![](https://i.imgur.com/Y8cyv7H.png)

By only looking at the picture, you may not understand what is happening. It maybe easier for us - programmers to understand through actual code.
```c
#include <stdbool.h>
#include <stdio.h>
int main() {
    int ARR = 1000; // Auto-reloaded counter
    int CCRx = 250; // Compare Register
    bool is_high;
    for (int i = 0; i < ARR; i++) {
    	if (i < CCRx) {
    		is_high = true;
    	} else {
    		is_high = false;
    	}
        // Or prefered shorthand
        // is_high = (i < CCRx);
    }
}
```

`CCRx` means **Compare Register**. x means the number of channels that we are using.

When the auto-reload counter is smaller than `CCRx`, the output PWM will give a HIGH value.

The ARR (auto-reload counter) from the previous paragraph is used as a downscaler of clock frequency. But in here, it acts as a denominator and `CCRx` acts as an numerator.

$Duty\:Cycle = \frac{CCR(Compare\:Value)+1}{ARR(auto-reload\:counter)+1} = \frac{On-time}{Period}$
 
### How to choose the value of auto-reload counter and prescaler value

From the formula:

$Freqency\:Output = \frac{Frequency \: of\:clock}{(Prescaler\:Value+1) \cdot (Auto-reloaded\:counter+1)}$

There are many combinations of prescaler value and auto-reload counter that can generate the same frequency output. How can we choose a better value?

As you may notice, the ARR acts as an denominator in the **Duty Cycle formula**, therefore if we want to output a short **on-time**, we need to have larger denominator. Notice that both of the CCR and ARR has to be an 16-bit unsign integer. 

As a result, **Larger Auto-reload Value and Smaller Prescaler value would be better when outputing a short on-time.**

### Classwork 2
:::info
If we need a frequency output of **50Hz** and on-time of **0.5ms**, what are the possible combinations of prescaler value, auto-reload value and compare value? (Given that the clock frequency is 84MHz)
:::

# How to output signal in IDE?

Each pin can use specific timers and timer channels. You can check the configuration of the board from CubeMX to find out which timer and channel to use.

:::danger
 # Important !!!!!!
 
 - Each timer will only have one prescaler value and auto-reload counter. 
- Each timer will have several channels that can output different on-time(compare value). (CCR1, CCR2 ...)

Which means those different channels will share same prescaler value and auto-reload counter, but have different on-time. So when using motor with different freqency, you may need different timer.
:::

## Define the PWM features in the IDE
There are 4 steps in setting up the PWM output channel and the pin to use.

1. In catergories, click **Timers** then choose the timer you want to use.

    Setup the **Mode** same as the figure shown.
    
    ![](https://i.imgur.com/53oLWQH.png)

2. Set the **Parameter Settings** same as the figure shown 

    ![](https://i.imgur.com/aNtON0o.png)
3. **IMPORTANT:** Enable the global interupt of the timer.

    ![](https://i.imgur.com/z2MDit3.png)

4. Assign the GPIO pin to be the specific timer and channel. E.g Assign the PC7 pin to output the pwm signal of TIM3_CH2.

    ![](https://i.imgur.com/MzvaMDI.png)

## Start Coding!!!
There are 4 steps in coding:

1. Initialize the Timer for PWM
``` c
MX_TIM1_Init();
.
.
.
MX_TIM8_Init();
```
2. Set the Prescaler value, Auto-reload counter
``` c
TIM1->ARR = 1234;    //set the timer1 auto-reload counter
TIM1->PSC = 5678;    //set the timer1 prescaler value
```
Hint: The clock of the board is running at around 84MHz.

3. Start the Timer

``` c
HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
```
4. Change the Compare Value as your robot needs it in the homework/classwork function
``` c
TIM1->CCR1 = 321; //set the compare value of timer1 channel1
TIM1->CCR2 = 678; //set the compare value of timer1 channel2
```

### Use the skeleton code!!
We have provided the skeleton code for testing, so just delete `main.c` (or just copy and paste the content in skeleton `main.c`) and drag the file `tutorial3_pwm.c` into the src file.

:::danger
You may lose all your stuff done in **main.c**. So before replacing **main.c**, you can rename it to main.c.old for backup.
:::

### Classwork 3
:::info
In class activity: control servo motor to turn to $-90^\circ$ -> $0^\circ$ -> $90^\circ$ (using delay only)

In this servo motor the on-time is using 400 µs at ($-90^\circ$) to 2400 µs at ($90^\circ$) [calculate $0^\circ$ yourself]

We are using TIM5 and Channel 1

Bonus: once the user press button, it will turn at different angle
:::
