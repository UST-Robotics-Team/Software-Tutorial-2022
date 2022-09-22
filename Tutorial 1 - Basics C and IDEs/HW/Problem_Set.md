# Homework for Tutorial 1 - Basics of C [![made-with-Markdown](https://img.shields.io/badge/Made%20with-Markdown-1f425f.svg)](https://hackmd.io/@Oil/H1nE_uU7t) 

Original Author: Li Ka Yau Elwin

Updated by: Leung Ka Chun Wesley

## Table of Content

Number System Converter

Mean, Mode and Median

Simple Calculator

Challenging Question - Score Attack

> :warning: **Warning**:
> Please use ALL the functions provided to complete the assignment as it will be graded.

## Number System Converter

There are so many number systems. Commonly we will have decimal, binary and hexadecimal systems.

You are now required to write a Number System Converter which users can convert a set of number from one system to another. 
For example:

```c
Please enter a set of number:
>123123123 //a set of number the user inputted
Please enter the current number system:
>10 //indicate that the above number set is a decimal number
Please enter the number system you want the set of number be converted to:
>16 //meaning that the number "123123123" will be converted from decimal to hexadecimal.
Output = 756B5B3
```

You just have to handle 3 systems: decimal, binary and hexadecimal, which the converter can convert the set of number in between these three systems.

However, if the user entered a garbage value, an error message should be outputted:

```c
Please enter a set of number:
>9999 //a set of number the user inputted
Please enter the current number system:
>2 //indicate that the above number set is a binary number
Error! That set of number is not a binary number.
```

> :warning: **Warning**:
> You are not allowed to use <math.h> in this question.
> Use the BinaryToDecimal, BinaryToHexadecimal, DecimalToBinary, DecimalToHexadecimal, HexadecimalToBinary and HexadecimalToDecimal functions in NumberSystemConverter.c to complete this assignment.

## Mean, Mode and Median

Mean is the average value of a set of numbers. 
E.g. Mean of {1, 2, 3, 3, 1, 2} = (1 + 2 + 3 + 3 + 1 + 2) / 6 = 2

Mode is the number which appears most frequently in the set of numbers.
E.g. Mode of {1, 2, 1, 3, 1, 2} = 1
E.g. Mode of {1, 2, 3, 1, 2} = 1, 2
E.g. Mode of {1, 1, 2, 2, 3, 3} = No mode

Median is the number with its index middle among a set of numbers in ascending order.
E.g. Median of {1, 1, 3, 4, 5} = 3
E.g. Median of {1, 1, 2, 3, 4, 5} = (2 + 3) / 2 = 2.5

You are required to write a program to find out the mean, mode and median of a set of integer numbers. The interface of the execution of the program should be like this:

```c
Enter a number to append to the number set. Enter '/' to stop appending.
>1
>2
>4
>9
>0
>2
>/
Mean = 3
Mode = 2
Median = 2
```

```c
Enter a number to append to the number set. Enter '/' to stop appending.
>1
>1
>2
>2
>3
>4
>/
Mean = 2.16667
Mode = 1, 2
Median = 2
```

If the number of occurences are the same for all integers in the set, there should be no mode in the set:

```c
Enter a number to append to the number set. Enter '/' to stop appending.
>1
>2
>/
Mean = 1.5
Mode = No mode
Median = 1.5
```

> :warning: **Warning**:
> Only integer need to be handled. However, you should also handle multi-digits instead of single digits. E.g. the set of number may contain numbers equal to or larger than 10.
> Use the mean, mode, and median functions in MeanModeMedian.c to complete this assignment.

## Simple Calculator

A simple calculator can only do simple mathematical operations (i.e. Addition, Subtraction, Multiplication and Division.)

Write a program of a Simple Calculator with input format for users:
`<number><operator><number>`
with spaces are unnecessary in between.

For example:

Input:
`2`
`+`
`3`

Output:
`5`

Input:
`1`
`-`
`3`

Output:
`-2`

Input:
`3`
`*`
`4`

Output:
`12`

Input:
`9.0`
`/`
`2`

Output:
`4.5`

### Assumption

* `<number>`: It can be an integral / floating point value.
* When we perform integer devision, unlike C programming, it should return a floating point value instead of an integer.
  * For example, in C, `15 / 2` returns `7` as left operand and right operand are both integer.
  * However, for this question, `7.5` should be returned.

> :warning: **Warning**:
> Use the calculate function in SimpleCalculator.c to complete this assignment.

## Challenging Question - Score Attack

Let say a string is given to you which only involve 'A', 'B' and 'C'. E.g. 'AACCBBCCCAAA'.

What you need to do, is to write a program to eliminate the linking letters. Everytime you eliminated a letter, one mark will be given. For example, if we eliminated the 'BB' in the above example, 2 marks will be given. 

However, scores can be multiplicated when you can eliminate 5 or above letters in a row. For instances, after eliminating 'BB', the remaining string will become 'AACCCCCAAA'. So if we eliminate 'CCCCC', 5 x 1.5 = 7.5 scores will be given. The table of multiplication is shown below:

| Letters Eliminated | Multiplication |
| ------------------ | -------------- |
| 5                  | 1.5            |
| 6                  | 1.6            |
| 7                  | 1.7            |
| 8                  | 1.8            |
| 9                  | 1.9            |
| 10                 | 2.0            |
| 11                 | 2.1            |
| 12                 | 2.2            |
| 13                 | 2.3            |
| 14                 | 2.4            |
| 15                 | 2.5            |
| 16                 | 2.6            |
| 17                 | 2.7            |
| 18                 | 2.8            |
| 19                 | 2.9            |
| 20                 | 3.0            |
| 21                 | 3.1            |
| 22                 | 3.2            |
| 23                 | 3.3            |
| 24                 | 3.4            |
| 25                 | 3.5            |
| 26                 | 3.6            |
| 27                 | 3.7            |
| 28                 | 3.8            |
| 29                 | 3.9            |
| 30                 | 4.0            |

If the length of eliminated letters `> 30`, the multiplication should remain the same (i.e `= 4.0`).

You task is to write a program to eliminate all the letters, in addition to get the highest score you can get.

Example:
```c
>AACCCCCAAA
7.5
```

If there exist any character other then 'A', 'B', and 'C', output "Score Attack Error":

```c
>qwertyABC
Score Attack Error
```

> :warning: **Warning**:
> Use the scoreattack function in ScoreAttack.c to complete this assignment.

Add oil ;)