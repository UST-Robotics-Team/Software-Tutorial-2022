# Homework for Tutorial 1 - Basics of C [![made-with-Markdown](https://img.shields.io/badge/Made%20with-Markdown-1f425f.svg)](https://hackmd.io/@leowong12138/H1Sp3bn-j) 

Author: Li Ka Yau Elwin  
Modified by: Wong Lok Yin Leo and Tsang Hong Ting Dennis

[View it on HackMD!](https://hackmd.io/@leowong12138/H1Sp3bn-j)  
Make sure to check the [FAQ](#faq) below!

## Table of Contents

[TOC]

## Number System Converter
There are so many number systems. The most common ones we use are the decimal (base 10), binary (base 2), and hexadecimal systems (base 16).

Write a Number System Converter which converts a number from one system to another. You just have to handle 3 systems: decimal, binary, and hexadecimal. The converter should be able to convert from/to any of the three systems.

### Example
Here is an example that converts 123123123 from decimal to hexadecimal:

```c
Please enter a set of number:
>123123123  // A number from user input
Please enter the current number system:
>10 // Indicates the above number is in decimal
Please enter the number system you want the set of number be converted to:
>16 // The system to convert to.
Output=756B5B3
```

**Explanation**: Unlike decimal, hexadecimal has 16 digits, allowing us to express numbers in an alternative format. We use A-F to represent the six digits after 9. So A would be 10, B would be 11, and so on. We can express 123123123 as $7 \times 16^6 + 5 \times 16^5 + 6 \times 16^4 + 11 \times 16^3 + 5 \times 16^2 + 11 \times 16^1 + 3 \times 16^0$, which we write as 756B5B3.

### Example - Error
However, if the user entered a wrong number system, an error message should be printed:

```c
Please enter a set of number:
>9999 // A number from user input
Please enter the current number system:
>2 // Indicates the above number is in binary
Error! That set of number is not a binary number.
```

**Explanation**: In binary, the only digits are 0 and 1.

```c
Please enter a set of number:
>9999 // A number from user input
Please enter the current number system:
>3 // Unsupported number system
Error! The number system is not supported.
```

**Explanation**: We won't handle numbers in the base-3 system.

## Mean, Mode and Median
Write a program to find the mean, mode, and median of a set of numbers.

The **mean** is the average value of a set of numbers.  
E.g. Mean of {1, 2, 3, 3, 1, 2} = (1 + 2 + 3 + 3 + 1 + 2) / 6 = 2

The **mode** is the number which appears most frequently in the set of numbers. There can be more than one mode.

* Case 1: Only one mode.  
  E.g. Mode of {1, 2, 1, 3, 1, 2} = 1
* Case 2: Multiple modes as not all numbers have the same frequency.  
  E.g. Mode of {1, 2, 3, 1, 2} = 1, 2
* Case 3: No mode as all numbers have the same frequency.  
  E.g. Mode of {1, 1, 2, 2, 3, 3} = No mode

The **median** is the 50th percentile of a set of numbers. In a sorted list, the median is the number which appears in the middle. If there is an even list of numbers, take the average of the two middle numbers.
E.g. Median of {1, 1, 3, 4, 5} = 3
E.g. Median of {1, 1, 2, 3, 4, 5} = (2 + 3) / 2 = 2.5

### Assumption
The set of numbers are guaranteed to be integral.

0 < Total amount of numbers < 100 

### Example
The execution of the program should look like this:

```c
Enter a number to append to the number set. Enter "\" to stop appending.
>1
>2
>4
>9
>0
>2
>\
Mean=3
Mode=2
Median=2
```

For mean and median, refer to the [floating point FAQ](#how-should-i-print-floating-point-answers) for instructions on how to print the answer.

## Simple Calculator
A simple calculator can do simple mathematical operations: Addition, Subtraction, Multiplication, and Division.

Write a simple calculator program. The input format follows `<number><operator><number>`, without spaces in between numbers and operators.

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

* `<number>`: An integral or floating point value.
* `<operator>`: One of `+`, `-`, `*`, `/`.

### Notes

* For division, a floating point value should be printed instead of an integer.
  * Care needs to be taken when using C's division operator `/`. In C, `15 / 2` returns `7` as both the left and right operands are `int`s.
  * However, for this question, `7.5` should be returned.
* Refer to the [floating point FAQ](#how-should-i-print-floating-point-answers) for instructions on how to print the answer.

### Example
```c
Input:
>9.0
>/
>2
Output:
4.5
```

## Challenge Question 1 - Score Attack
Let's say a string is given to you containing only A's, B's, and C's, e.g. AACCBBCCCAAA. The objective is to eliminate all letters. Each turn, you can eliminate any consecutive letters that have the same value. For example, we can eliminate A, BB, and CCC; but not AC, BBC, and CAA.

One mark will be given for each letter eliminated. For example, if we eliminated BB in the above example, 2 marks will be given.

In addition, you can get a combo score by eliminating 5 or more letters at a time, determined by a **combo multiplier**. For instance, after eliminating BB, the remaining string will become AACCCCCAAA. If we eliminate CCCCC, $5 \times 1.5 = 7.5$ marks will be given. The combo multiplier table is shown below:

| Letters Eliminated | Combo Multiplier |
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
| 30+                | 4.0            |

If the eliminated length is greater than 30, the combo multiplier will still be 4.0.

Your task is to write a program to find the maximum score obtainable by eliminating letters in the above fashion.

### Example
```c
Please enter a string:
>ACBACBABBABAACABAAABCB
Maximum Score:
32
```

## FAQ
### Libraries
The following C libraries are allowed:
* <stdio.h>
* <string.h>
* <stdbool.h>
* <stdint.h>

All other libraries are disallowed.

### How should I print floating point answers?
* All floating point answers should be rounded to 1 decimal place.
  * e.g. 1.07 → 1.1, 4.40506 → 4.4
* If the rounded value is an integer (e.g. 3.0, -2.0, 42.0), then chop off the `.0` and print the integer part (e.g. 3, -2, 42).

### How do I submit homework?
This year we'll be adopting the ZINC platform as our grading system. Setup is unfortunately still in progress, and we are working hard on it. Please be patient and stay tuned for further announcements. Meanwhile, you can create a private repo using our [public homework template](https://github.com/UST-Robotics-Team/SoftwareTutorialHW) and store your code there.
