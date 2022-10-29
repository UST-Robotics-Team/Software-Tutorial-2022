# Advanced Notes: Omni Wheel 
Author: Joyce Li [![HackMD Version](https://img.shields.io/badge/Made%20with-Markdown-1f425f.svg)](https://hackmd.io/@yJufOWStQfqucBBAvN7_qA/HJpGNFaXF)

[TOC]

## What is an omniwheel?
![](https://i.imgur.com/AlYSzcP.png)

Omniwheels are wheels with small discs (called rollers) around the circumference which are perpendicular to the turning direction. The effect is that the wheel can be driven with full force, as well as sliding laterally.
![](https://i.imgur.com/jEEtTZ9.png)
Robots built with omni wheels are able to move in any direction without steering the robot itself.


## How does it work?
### Simplest Case: wheelbase moving forward
Suppose you want a three wheel omni wheelbase to move forward with speed 1m/s, how much force should each wheel give?
![](https://i.imgur.com/L2buKDy.png =400x)


> To people who don't know what vectors are: you may just treat it as decomposing a diagonal line to get its x and y respectively (but with directions).
> ![](https://i.imgur.com/W3IaM3p.png)

#### Decomposing magnitude of each wheel in x and y direction
![](https://i.imgur.com/cTo6Ker.png =400x)

##### X-direction
$F_x = 0$
$A_x = A$
$B_x = B \cdot \cos60$
$C_x = C \cdot \cos60$
##### Y-direction
$F_y = F = 1$
$A_y = 0$
$B_y = B \cdot \cos30$
$C_y = C \cdot \cos30$

$F_x = A_x - B_x - C_x$
$A - B \cdot \cos60 - C \cdot \cos60 = 0$

$F_y = C_y - B_y$
$C \cdot \cos30 - B \cdot \cos30 = 1$


Moreover, the robot is not spinning, therefore the torque is 0 , and A + B + C = 0
Solving the equations:
1. $A - B \cdot \cos60 - C \cdot \cos60 = 0$
2. $C \cdot \cos30 - B \cdot \cos30 = 1$
3. $A + B + C = 0$

$A = 0$
$B = -\frac{1}{\sqrt{3}} = -0.577$
$C = \frac{1}{\sqrt{3}} = 0.577$

## Things to work on
We have shown you how to calculate the speed of each wheel in order to move the wheelbase forward. Could you find out the general equation for F in any direction and magnitude? (i.e. speed of wheel A, B, C in relation to F<sub>x</sub> and F<sub>y</sub>)
![](https://i.imgur.com/i0zmUac.png =400x)

Suggested answer: https://physics.stackexchange.com/questions/57401/omni-directional-motion-resolving-three-or-more-vectors
