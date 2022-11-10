# Advanced Tutorial 2 - Communication Protocol (CAN) and RoboMaster motor features [![made-with-HackMD](https://img.shields.io/badge/Made%20with-HackMD-1f425f.svg)](https://hackmd.io/@bktbkt/ry3MgWcRc)
Authors: Dennis, Amber

Modified by: Chalex

Further modified by: Brian


## Table of Content

[TOC]
### What is CAN
* CAN, Controller area network, is an electronic communication bus defined by the ISO 11898 standards. Those standards define how communication happens, how wiring is configured and how messages are constructed, among other things. Collectively, this system is referred to as a CAN bus.
* All nodes can “hear” all transmissions. There is no way to send a message to just a specific node.The CAN hardware, however, provides local filtering so that each node may react only on the interesting messages. 

### Principle of CAN
Differential Signal
![](https://i.imgur.com/PfL9kJR.png)
#### The way data is sent on the CAN Bus is through differential signalling. We use both the line CAN high and CAN low to transmit the data at the same time.
##### Reccesive level - represent logical 1
##### Dominant level - represent logical 0

There are four types of CAN frames:
* Data Frame
* Remote Frame
* Error Frame 
* Overload Frame
### Data frame
Base frame format (11-bit identifer)
![](https://i.imgur.com/xi9v8vW.png)
Extended frame format (29-bit identifier)
![](https://i.imgur.com/Ok3YeQc.png)
The CAN standard requires that the implementation must accept the base frame format and may accept extended frame format. But must tolerate the extended frame format.

A CAN data frame can be divided into 8 parts:
1. Start of frame (SOF)
2. arbitration (consists of 2 parts)
* CAN-ID: 11- or 29-bit identifier 
* a remote transmission(RTR) bit.
3. control
4. data
5. cyclical redundancy check (CRC)
6. acknowledge (ACK) 
7. end of frame (EOF).

Normally, we will only focusing on three parts: CAN-ID, Control and Data.

**CAN ID**: indicating where the data frame should be sent to and who should receiving it.

**Control**: Inform the length of data in bytes (0-8).

**Data**: Containing Actual data value, e.g. current for motor.


### STM32 CAN config
**CAN1(master)** and
![](https://i.imgur.com/lKbY7qi.png) 
**CAN2(slave)**
![](https://i.imgur.com/twTFcth.png)

**Clock Config**
![](https://i.imgur.com/Edq20yk.png)
Just make sure the clock config are the same.

### CAN functions
#### Initialize CAN
We have create the can object for you. For below example, we are using can1 port and the hcan1 object.
```c
CAN_HandleTypeDef hcan1;
CAN_HandleTypeDef hcan2;
----------------------------
void can_init() {
	can_filter_enable(&hcan1);
	HAL_CAN_Start(&hcan1);
	HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
}
```
CAN object have been defined for you with the help of STM32HAL library. You only need to use this can_init() function to start CAN.

#### Sending CAN message
The id of the message have been set for you as 0x200.

If we want to run the motor, we have have to add message to our CAN transceiver(Tx). We can use this function
```c
void CAN_cmd_motor(int16_t motor1, int16_t motor2, int16_t motor3,
		int16_t motor4, CAN_HandleTypeDef *hcan)
    // for motors, value range from -16384 to 16384
```
Assuming we are using 4 motor, we can assign different current value to each motor. As we are using CAN1 port, we are going to pass the address of hcan1(&hcan1) in to the function. The current value to be sent to the motor can be seen as the torque of the motor.

#### Retrieving CAN message
We have created 4 variable(Assuming we are using four motor) for you to use, 
motor1_stat, motor2_stat, motor3_stat, motor4_stat, all are objects of the struct as shown below.
```c
typedef struct{
    int16_t     speed_rpm; //speed rpm = number of turns per 1 min
    int16_t     given_current;//given current for the motor
    uint8_t     temperature;//temperature of the motor
}   motor_status;
```
To retreive data from CAN bus, use the interrupt function below. Whenever a message is arrived to the CAN receiver(Rx), it will help you collect it.
```c
HAL_CAN_RxFifo0MsgPendingCallback(&hcan1);
```
Parameter: address of the can object. 
As we are using CAN1 port on our board, we are giving the address of the CAN1 object to this function.

To assign the received data to varaible motor1_stat etc. Use...
```c
void UpdateMotorStatus()
```


### Example code
The code below shows you how to retrieve and send CAN message at the same time. This will rotate your motor in clockwise.
```c
//In main.c
can_init();
while (1) {
    	if (tft_update(10) == 0) {
			tft_prints(0,0,"m1_spd: %d", motor1_stat.speed_rpm);
			tft_prints(0,1,"m1_temp: %d", motor1_stat.temperature);
			tft_prints(0,2,"m1_cur: %d", motor1_stat.given_current);
		}
        /* USER CODE END WHILE */
    	HAL_CAN_RxFifo0MsgPendingCallback(&hcan1);
    	UpdateMotorStatus();
        /* USER CODE BEGIN 3 */
        // goto tutorial2_hw.c to do your classwork and homework
		if(!btn_read(BTN1)){
			CAN_cmd_motor(1000, 1000, 1000, 1000,&hcan1); //rotate clockwise, parameter list(motor1,motor2,motor3,motor4)
		}
		if(btn_read(BTN1)){
			CAN_cmd_motor(0, 0, 0, 0,&hcan1); //remember to set it back to 0 once you don't want to run the motor.
		}
		if(!btn_read(BTN2)){
			CAN_cmd_motor(-1000, -1000, -1000, -1000,&hcan1); //rotate in anti clockwise.
		}
		if(btn_read(BTN2)){
			CAN_cmd_moor(0, 0, 0, 0,&hcan1); 
		}
        // led blinky - useful for indicating the condition of the board
        if (HAL_GetTick() - last_ticks >= 100) {
            led_toggle(LED4);
            last_ticks = HAL_GetTick();
        }
    }
```

## RM motor features

### Introduction
RoboMaster Motor(RM motor), is the black cylindrical box as shown in the photo below:
![](https://stormsend1.djicdn.com/tpc/uploads/photos/1928/large_fcfcea55-88e3-4521-a81e-fa7ea136ac0d.jpg)
and we need a motor driver to convert the signal to what the motor "understand" which is called a RM-ESC:
![](https://product1.djicdn.com/uploads/sku/cover/08aa5010-64ec-447d-a568-1d2eb597f345@medium.png)

### Wiring and power supply
![](https://i.imgur.com/HSK66yp.png)
- Both [1] and [2] will attached to the RM motor.
- Connect the [5] to a 24V cells
- [7] is CAN port [8] is PWM port
    - should only choose **1 port** to use

### Potential Damage
1. Collision
    * Dropping
    * Somehow your robot has the RM motor or ESC exposed to external objects and your robot crashed into them
2. Overheating
    * Cause
        1. Overdriving (Forcing the motor to provide excessive amount of torque)
        2. Short circuit
            * 24V power wire is shorted and so the motor is provided with too much current
            * Heating effect (Hopefully you have learnt high school physics)
    * Results
        1. Non Permanant Damage
            * Just some warmth
        2. Permanant Damage
            * Electrical component gets damaged
            * More serious cases: **Sparks** and **Smoke**
##### Note
> Please check the temperature of both ESC and RM motor if something weird happened. E.g. Your motor didn't drive when it should, Irrigating smell
### Prevention
1. Make sure that the ESC is tightly tied to the robot internally
2. Ensure there is nothing that blocks the rotation motion of the RM motor (E.g. Loose screws)
    * Turn off the 24V power supply
    * Remove the obstacle if you can or else find a mech member to deal with it
    
2. Overheating
    - Irritating Smell (Smells like celery)
    - Cool down in whatever way you can (Preferably use compressed air in the lab to cool it down)

**Always turn off 24V power supply first when accidents happen**

### Configuration of RM ID
Steps:
1. Find a hard rod with a small end (We use tweezers most of the time)
2. Poke the SET Button[4] in the upper image to set the CAN ID
    - Number of times to press the SET Button = CAN ID + 1
    - The first press is to tell the RM ESC to enter CAN ID configuration mode
3. Watch the LED blink and make sure the CAN ID is correct
    - ID = LED blink time - 1

### Callibarion of the RM motor

#### Background
RM motors can only be controlled when the ESC knows the condition of the motor.
(E.g. Current and inductance)
Even though the RM motor is a commercialized product, 
it is extremely difficult for every single motors to be identical.
Thus, we need to let the ESC to know the actual condition of the RM motor through callibration.

#### Procedures
1. Again, find a hard rod with a small end
2. Press the SET Button for a long time and it will enter the callibration mode
3. Wait untill the LED blinks green quickly.
4. The motor will start spinning but no worries, just wait untill it stops.
5. Please ensure that there is no obstacle bothering the RM motor spinning motion.

### What does the LED signal mean?
TLDR: Any LED signal except for a green blinking LED is not a good sign.
![](https://i.imgur.com/5lHllL5.png)
![](https://i.imgur.com/OcNbReB.png)
![](https://i.imgur.com/saNpZGB.png)

### Electrical Structure of a RM control system
![](https://i.imgur.com/ROzjtKy.png)

### Common Errors
> Arranged in order of occurence
#### *24V power*


| Symptom                | Meaning                           | Solution                                                                                                           |
| ---------------------- |:--------------------------------- |:------------------------------------------------------------------------------------------------------------------ |
| No LED Light at all    | No input power source             | 1. Check if the wire is plugged in or not <br>  2. Check if the fuse is burnt <br> 3. Ask hardware people for help |
| Solid red LED          | No CAN signal from the RM Motor   | Check the 7-pin wire connected to the RM Motor                                                                    |
| Red LED blinking twice | The 3-phase cable is not connected. | Check the connection between RM-Motor and ESC (3-phase cable)                                                              |

#### *Signal*
> Do these when you are sure it's not the power's problem
*CAN:*


| Possible Problem | Diagnosis                                                                                                                                                                                                                                                                                           | Solution                                        |
|:---------------- |:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |:----------------------------------------------- |
| Wrong CAN ID     | Check Check Check                                                                                                                                                                                                                                                                                   | Reinitialize the correct CAN ID                 |
| Wrong CAN Bus    | See if any motors are not moving the way you want                                                                                                                                                                                                                                                   | Send message to the right bus instead           |
| Wrong CAN Port   | Again, Check Check Check                                                                                                                                                                                                                                                                            | I mean, just don't plug it into the wrong hole |
| Broken CAN wire  | 1. Find a hardware member <br> 2. Check with a [DMM in beep mode](https://cdn.sparkfun.com/assets/learn_tutorials/1/01_Multimeter_Tutorial-09.jpg?__hstc=250566617.4b44870ec4a577029c49e44b73bd3bee.1627603200060.1627603200061.1627603200062.1&__hssc=250566617.1.1627603200063&__hsfp=3390389424) | Just get a new wire                             |

*PWM:*


| Possible Problem                                     | Diagnosis                                                                                                                                                                                                                                                                                           | Solution                            |
|:---------------------------------------------------- |:--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |:----------------------------------- |
| Incorrect frequency/ on time initialized in the code | 1. Check with Osciloscope <br> 2. Check your code                                                                                                                                                                                                                                                   | Change it back lol                  |
| False soldering for the pwm pins on the mainboard    | Find a hardware member for help                                                                                                                                                                                                                                                                     | Hardware member should deal with it |
| Broken PWM Wire                                      | 1. Find a hardware member <br> 2. Check with a [DMM in beep mode](https://cdn.sparkfun.com/assets/learn_tutorials/1/01_Multimeter_Tutorial-09.jpg?__hstc=250566617.4b44870ec4a577029c49e44b73bd3bee.1627603200060.1627603200061.1627603200062.1&__hssc=250566617.1.1627603200063&__hsfp=3390389424) | Just get a new wire                 |
| Broken ESC (Basically never happened)                | When you are a **100%** sure you did everything correctly and the motor is not working properly <br>Swap with an ESC that works and see if it's actually faulty                                                                                                                                     | Just get a new ESC                  |




#### CAN vs PWM
Both PWM and CAN can be used to contorl the motor. 
##### PWM:
Advantange:

- Easier to use and implement

Disadvantage:

- PWM can only output signal and can't get the feedback data back. As in real-life condition, the motor cannot be exactly identical (As said from above). If we just output a signal without getting feedback, the speed of motor may not be the same. Therefore, the wheelbase may not move as you want it to be.

##### CAN:
Advantange:

- Can take encoder feedback so we can perform better control for the motors. (Details: [PID_control_method](https://www.youtube.com/watch?v=JFTJ2SS4xyA))

Disadvantage:

- A bit annoying to implement(requires more work)
- Hard to debug when there are problems
    - Could be because of:
        - CAN IC
        - CAN wire
        - Hardware soldering
        - CAN port
        - Code
        - or EVERYTHING

:::    danger
Please tell me (Amber) that you want to use which control method and say which group you are from and how many wheels you plan to use. So that I can finish the motor configuration for you.
:::

# Driving RM through pwm
We need to keep the RM pwm at the resting on-time which is around 1465~1500(us), it may be different among different set of ESC and board (Please try the value between the range and find one suitable on your machine)

The frequency for controling rm is from 50Hz ~ 500Hz (personally i use 50Hz to do the testing)

If the LED light appears at blink 3 times that means the pwm signal you input isn't low enough, you can try other value, untill it blink at green light(and blink same number as it can id), and then it will stay at rest. Then you can turn the pwm value to other value to perform the work.

The on-time to the speed graph is shown at below.

![](https://i.imgur.com/hSHeZe6.png)

# How many motors for the wheelbase?

- You can choose to use whatever kind of wheelbase(straight wheels or omni-wheels) **Completely optional!!!**
- Straight wheels requires 2 or 4 motors, Omni-wheels requires 3 or more motors
- Omni-wheel robots can walk in **all direction without rotating** which may make your game flow smoother by a lot.(Depends on the game flow, omni-wheel may not be the best solution for all situations)
- For more detail. Please refer to: [Omni-wheel: theory and control](https://hackmd.io/@yJufOWStQfqucBBAvN7_qA/HJpGNFaXF)
<br>
<br>
<br>
Reference: https://rm-static.djicdn.com/tem/17348/RoboMaster%20C620%20Brushless%20DC%20Motor%20Speed%20Controller%20V1.01.pdf










