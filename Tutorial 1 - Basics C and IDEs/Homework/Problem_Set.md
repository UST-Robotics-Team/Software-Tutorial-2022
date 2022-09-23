# Homework for Tutorial 1 - Basics of C [![made-with-Markdown](https://img.shields.io/badge/Made%20with-Markdown-1f425f.svg)](https://hackmd.io/@Oil/H1nE_uU7t) 

Author: Li Ka Yau Elwin

## Table of Content


[TOC]

:::info
All floating point answer should be at most 1 d.p., e.g. 1.07 = 1.0, 4.40506 = 4.4 
:::

## Number System Converter

There are so many number systems. Commonly we will have decimal, binary and hexadecimal systems.

You are now required to write a Number System Converter which users can convert a set of number from one system to another. 
For example:

### Ouput Format
```c
Please enter a set of number:
>123123123 //a set of number the user inputted
Please enter the current number system:
>10 //indicate that the above number set is a decimal number
Please enter the number system you want the set of number be converted to:
>16 //meaning that the number "123123123" will be converted from decimal to hexadecimal.
Output=756B5B3
```

You just have to handle 3 systems: decimal, binary and hexadecimal, which the converter can convert the set of number in between these three systems.

However, if the user a wrong number system, an error message should be outputted:
### Ouput Format
```c=
Please enter a set of number:
>9999 //a set of number the user inputted
Please enter the current number system:
>2 //indicate that the above number set is a binary number
Error! That set of number is not a binary number.
```

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

You are required to write a program to find out the mean, mode and median of a set of numbers. The interface of the execution of the program should be like this:
### Ouput Format
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

### Ouput Format
```c
Input:
>9.0
>/
>2
Output:
4.5
```
## Challenging Question 1 - Score Attack

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

If the length of eliminated length `> 30`, the multiplication should remain the same (i.e `= 4.0`).

You task is to write a program to eliminate all the letters, in addition to get the highest score you can get.

### Ouput Format
```c
Please enter a string:
>ACBACBABBABAACABAAABCB
Maximum Scores:
32

```

# How to submit the Homework
This is the first year we adopt ZINC as our grading system. Setup is unfortunately still in progress, and we are working hard on it. Please be patient and stay tuned for any further announcement. Meanwhile, if you would, you can create a private repo using our public Homework template and store your code there.
