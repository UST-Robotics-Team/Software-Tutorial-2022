# Tutorial 3 - Advanced IO [Homework] 2022  [![HackMD Version](https://img.shields.io/badge/Made%20with-Markdown-1f425f.svg)](https://hackmd.io/@ytyk668/HynxsVJZo)

#### Main Author: Caner Demirer

#### Edited by: Katie (tyyeungah@connect.ust.hk)

In this homework you will design and implement a "pinball machine". The setup consists of a development board (which has 2 buttons and 4 LEDs), a servo, and a tiny 3D-printed "paddle" attached to the servo. You need to use PWM to control the servo to achieve the desired functionality described below. 

The main goal is to have a controller that works and feels like a pinball machine.

![](https://is5-ssl.mzstatic.com/image/thumb/PurpleSource126/v4/f0/6c/33/f06c3301-e1d8-5d59-f9cb-fc20ef899a84/3a673c74-5075-4411-b982-23dde810c0bb_Williams_Pinball_Indiana_Jones_Pinball_12.9.png/576x768bb.png)

## Details
At the beginning, there will be **3** "marbles" dropped from the top of the "machine". You have to prevent the "marbles" from reaching the bottom by controlling the "paddles" right above the bottom of the "machine". If the "marble"'s level is lower than 5, the "marble" will be lossed.

The target is to get double the amount of marbles. 

There are **three types of movements**: 
 - Single Move
 - Double Move (Chargeable)
      - The number of "marbles" will increase by 2 when the Special Move is activated.
 - Special Move (Designed by you)
 

There are only two "paddles": The left one and the right one. The control of "paddles" will alternate. i.e. The left and right "paddle" take turns for moving. (i.e. the servo turns from left to right first and the next move will be from right to left, or vise versa)

The "paddles" can reach "marbles" from level 5-10. After a "marble" is hit by the "paddles", its level will increase at a constant speed for 1 sec before it starts to drop again.

When there is nothing to do, the "paddle" stays at Resting Angle of either side. All movements start at one side's Resting Angle and end at the other side's Resting Angle.


#### Button Arrangement
[Single Move] [Double Move] [Special Move]

A move request is made when the corresponding button is pressed. Notice that there are only 2 buttons on the board, you guys can decide how to use 2 button to do 3 buttons task.
> The Special Move can only be triggered by button(s)

#### Single Move
A Single Move needs to move slower then the Double Move.

> It starts at 0deg, moves towards the target and ends at 180deg (of the opposite side).

#### Double Move
It consists of 2 stages. First, it start at 0 deg and pausing at 40deg (charging for 2 seconds) until the player releases the Double Move button. (If it is at 180 deg then it will pausing at 140 deg)

While performing the Double Move, you should also use LEDs to indicate the charging status as shown:

| State | LED Status | Duration |
| ----- |:---------- | -------- |
| 1     | [0][0][0][0]  | 0.0~0.499s     |
| 2     | [1][0][0][0]  | 0.5~0.999s     |
| 3     | [1][1][0][0]  | 1~1.499s     |
| 4     | [1][1][1][0]  | 1.5~1.999s     |
| 5     | [1][1][1][1]  | >=2.0s     |

> Note: **[0]** = LED off, **[1]**: LED on.

**Non fully-charged Double Move**
If the player had already released the button while the Double Move was not charged enough, then there won't be any charging nor pausing. It then move for only one time. 
*Notice that the Double Move need to move faster then the Single Move.*

**A fully-charged Double Move** is a Double Move that has been charged for at least 2 seconds. After the button being released. It then move for 2 times. 
*Notice that the Double Move need to move faster then the Single Move.*

**Display**
* The level of the top of the pinball machine is defined as 50.
* "Paddles" are located at level 5.
* Level of each "marbles" should be displayed and changed accordingly at a constant speed.
* List the levels of all marbles out like below. 
```
eg
marble 1:
marble 2:
marble 3:
...
```

## Marking scheme [Point(s)]
The task is split into several checkpoints. To get the points of a checkpoint, you need to satisfy the requirements of both that checkpoint and all checkpoints above it. 

*  The levels of "marbles" change at a constant speed. [1]
*  The "marbles" will be lossed when it reached the bottom of the "machine" (i.e. level 0-5) in tft [1]
*  Having the "paddle" oscillate from side to side based on button clicks [3]
*  Having 2 stages at Double Move mode. [3]
*  Having correct LED blinking action when holding the button.[4] 
*  Having correct Non fully-charged Double Move [2]
>Originally there are 3 marbles
After a fully-charged double move is activated
The number of marbles will increase by 2,
which will become 5
The goal is to have number of marbles larger than or equal to doubled the original amount of marbles (6)
as there may be some chance that one may loss some marbles during the “game”
*  Having correct Fully-charged Double Move [3]
*  Display a Winning message when the goal is achieved (ie having the amount of "marbles" doubled). [1]

## Bonus
You can design your own Special Move:
**A Special Move** is a custom Move that must be designed by yourself, the only requirements are:
- It looks cool. At least not similar to Single and Double Move. [3]
- Use some LEDs. [2]

## Rules to obey
- Single Move can be use at any time.
- 2 Single Move can unlock a chance to use Double Move. When Double Move is used, the counter for it will minus 2.
- When any "marble" is lossed or 2 Fully-chraged Double Move is used, it will auto-triggered Special Move. The counter for it will minus 2.
- The number of "marbles" will increase by 2 when a Fully-charged Double Move is activated.
