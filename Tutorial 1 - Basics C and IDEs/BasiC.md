# Tutorial 1 - Basics of C  [![HackMD Version](https://img.shields.io/badge/Made%20with-Markdown-1f425f.svg)](https://hackmd.io/@Oil/r1WwNPIXK)

Original Author: Daniel Cheung (dcheungaa@connect.ust.hk)

Updated by: Ho Yu Yat (yyhoai@connect.ust.hk), Lau Ka Kit, Danny (kkdlau@connect.ust.hk)

Further Modified by: Li Ka Yau Elwin (kyeliaa@connect.ust.hk), Leung Ka Chun, Wesley (kcleungax@connect.ust.hk)

## Table of Content

[TOC]

## Suggested Learning Materials
https://youtu.be/KnvbUiSxvbM

Watch #1 - #27 (except #18). For those who are comfortable, please also watch #28-#30, it will be benificial to you in your next round of training.

Previous tutorial videos
https://www.youtube.com/playlist?list=PLSeKkpqgEm4-tTUrEm-hYbDg-iegYMoUj

## Introduction to C, a procedural language

C is an old language. It was very popular then, and is still popular now, because of how robust it can run. It is a **low level** language, meaning there is little between it and machine code (0s and 1s). It also means that we often have to manage the memory (RAM) by ourselves, the programmers.

C is also a procedural language, /the type of program where we have to say a list of instructions to the computer one by one and it follows line by line. A specific way to write the list of instructions to do something, is what we call an **algorithm**.

## Where do I write my code?

Since some of you may not have installed an **IDE** (Integrated Development Environment) on your computer yet, you may use an online version to write your programs. [**Repl.it C Language**](https://repl.it/languages/c) is a good choice.

Besides, it is also recommanded to install [**VS Code**](https://code.visualstudio.com/download). It is a very nice workplace to write your code. Remember to install appropriate extensions before using or else you cannot compile and run any of your codes.

Later on, we will teach and guide you to install [**CubeIDE**](https://www.st.com/content/st_com/en/products/development-tools/software-development-tools/stm32-software-development-tools/stm32-ides/stm32cubeide.html?dl=mDz41Ame3rsvInWnnBOgtQ%3D%3D%2CcZwAba%2BIy%2FG8DrU77U5EEghQuKOCpNSACfvi2bwE08ZENmt9WBEXUiTFvdmySC1TNkz3H0dEAD1mlAg7m066zK%2F%2FEiRsAU9fsh2Z8qjWUeqproTDa74wIxaZNYl1hc8eF0gQr7rlIcOFvgurma6ZSOcIVxYHcXIdvJ5AxC%2BjWa6UGFNZRkS7jDzol8Tpl0jvo%2FAMwRruaLwkCR%2FMlSU58%2BCO7kAgbbpI9k1Vk9wfiVIDHh0oLoPz8srvZAj96TsE29RwNdrqa5DDOqFkNATwOtfq6CcuEy9pRVfVZ3qne5KLKsG0slrZQbhGh4%2FQj8jZ6HR7SsRXbr3AoEgc4EqypbnffnzAqnjfo6JE9Ir0kfR1TifcvX1rsJBK9ih6p%2Fbw%2BnqV22OC7utWyvidL7rQyLfyuw2MzWI7bH8qtlwMkyfOYFJ2k%2Bdkhpuhbe5jf6GM&uid=Pg30eCicqbj1AXYhNpUwb3QskPXfCpAM#get-software) for the coming lessons such that you can flash your code to the mainboard you are going to use.

### Instructions for [Repl.it C Language](https://repl.it/languages/c)

1. Simply go onto [Repl.it C Language](https://repl.it/languages/c).
2. In the middle section, you will see a sample code already in place, under the file name `main.c`. You can also see all the files on the left column associated with this setup. Do not worry about other files right now, editing `main.c` in the middle column is sufficient for now.
3. After you have completed some code, click "Run" to compile and run the program. The program is then run in the **console** on the right, where you can do inputs and it can display outputs.  If there are any errors in the code, the program will fail to run and display its error message in the console as well. Follow its prompt or maybe search online  to find out how to fix the problem.
4. Click "Save", you will see your URL change to `https://repl.it/repls/SomeRandomWords`, you can access your code with this URL later.

For now, to familiarize yourself to C, try editing the sample program so that instead of displaying "Hello World", it displays your name.

In a later tutorial, we will show you how to install and use Keil,  the IDE we use for the CPU onboard.

## Hello World!

Let us write the most basic program to illustrate the language that is C, a "Hello World!" program that outputs simply: `Hello world!`.

```c=
//main.c

#include <stdio.h>

int main() {
    // This is a comment.
    
    /* This is a multi-lined comment.
     * These gray lines are ignored by the program.
     * It is only for the developer, to remember something,
     * or to tell their peers how the program works.
     */
    
    printf("Hello, World!\n"); // \n means newline
    return 0;
    
    // Console:
    // Hello, World!
    // 
}
```

The program can be dissected as follows:

- `#include <stdio.h>`
  This line tells the program we are using features within a **library** named `stdio.h`, `printf()` to be exact, as it is defined within the library.

- `int main() {}`
  This is a **function definition**. It is the entry-point of the program, that means, the program will start right inside it. **`main()` must exist in every C program.** We write the main code inside this function.
  
- `printf("Hello, World!\n");`
  This is a **function call**, like using a mathematics function, we pass parameters within the parenthesis. This function can output whatever parameter we put in to the **console**, so we want it to write out `Hello, World!`. The function is defined within the library we have included earlier.  **`'\n'` represents a "newline" character**, since we cannot actually store an Enter key in a single line.
  
- `return 0;`
  When we run a C program, it ends with giving us an **exit code** to indicate whether or not there is a problem. By *returning* `0`, we indicate what the program ended successfully.
  
  The `main()` function is a specific case, in that you can only omit the `return` statement. The compiler will automatically add the `return 0;` for you. However, for other functions, you must return something, unlesss the return type is `void`.
  
Some things to take note of:

- C is case-sensitive. Upper-case letters and lower-case letters are entirely different! The following will generate an error:

  ![](https://i.imgur.com/Hk5Z699.png)

- End each statement with a `;` like how you would end a sentence with a full stop in English. Here is an example of an error related to this:

  ![](https://i.imgur.com/0fPkaWg.png)

- Close as many `{` or `(` or `"` as there are with `}` or `)` or `"` and do not mess up the order. It is just like maths, or else, the following error will be generated:

  ![](https://i.imgur.com/xfCwlsq.png)

> [classwork-01](https://hackmd.io/Fpr8vuHJS1WGAyE3t-Omfg?view#ex-1)

## File Types

C programs are stored as plain text in, often, 2 file types, with their conventional usages. Do follow the conventions, as there are practical and real differences you will see later on.

- `.c` **Source files** - These files contain function implementations.

  For example: the hello world program is stored within `main.c` in my case in some arbitrary project folder that I have created for the tutorial.

- `.h` **Header files** - These files contain functions, structs, global variables and macro declarations. *Basically anything declared that can be accessed globally.*

  For example: `stdio.h` is an actual header file stored in your computer, and is installed along with your choice of **C toolchain**. Paths of it of different people would likely be different.
  
  The reason your IDE is able to detect where the libraries are, is because the installation of the toolchain also appended the source directories within your `PATH` (system environment variable), or the installation path is manually selected in your IDE settings.*
  
  To include **compiler-defined** libraries, use `<>`.
  For example:
  ```c
  #include <stdio.h>
  #include <math.h>
  ```
  
  To include **user-defined** libraries, use `""`.
  For example:
  ```c
  #include "my_header_file.h"
  #include "your_header_file.h"
  ```
  
  
## Variables

### Data Types

#### Primitive Types

Variables are containers for values. We use different typed variables to store different typed values, e.g. integer, decimal, text.

These are the **primitive types** in C, the most basic variable types:

|   Type   |                  Description                  | Example Literal |
|:--------:|:---------------------------------------------:|:---------------:|
|  `char`  | 8-bit integer* for storing an ASCII character |      `'a'`      |
|  `int`   |        16-bit/32-bit signed integer**         |       `1`       |
| `float`  | 32-bit, single-precision floating point value |     `3.0f`      |
| `double` | 64-bit, double-precision floating point value |      `5.0`      |

- Whether `char` is signed or unsigned is machine-dependent.
- Size is compiler-dependent and machine-dependent.

There is actually several more common, non-primitive types.

|  Type  |                                    Description                                    | Example |
|:------:|:---------------------------------------------------------------------------------:|:-------:|
| `void` |                                The absence of type                                |      /  |
| `bool` | 8-bit boolean (i.e. true / false). To use this type, you must include <stdbool.h> | `true`    |

#### Signs and Modifiers

Signed integer will use half of the distinct bit combinations for negative numbers and the other for positive. The ranges are as follows:

![Signed range equation](https://latex.codecogs.com/svg.latex?%5Ctext%7BSigned%20Range%7D%20%3D%20%5B-2%5E%7B%5Ctext%7Bbit%7D-1%7D%2C2%5E%7B%5Ctext%7Bbit%7D-1%7D-1%5D)

![Unsigned range equation](http://latex.codecogs.com/svg.latex?%5Ctext%7BUnsigned%20Range%7D%20%3D%20%5B0%2C2%5E%7B%5Ctext%7Bbit%7D%7D-1%5D)

We can add the `signed` and `unsigned` modifiers to `char` and `int` to set the range the variable can hold. Read other modifiers on [C Language](http://c-language.com/c-tutorial/c-type-modifiers/).

For example, in order to store the integer 3,000,000,000 (3 billion), we need at least `unsigned long` or `uint32_t`. A signed `int` or `long` is not viable, as their maximum value is lower than 3 billion.

```c=
#include <stdint.h>

int main() {
    unsigned int var0 = 1; // 32-bit unisgned integer
    
    /**
     * stdint.h defines integer types with different data size.
     * For example: uint8_t, uint16_t, uint32_t and uint64_t.
     */
    uint16_t var1 = 1; // 16-bit unsigned integer
    uint32_t var2 = 2; // 32-bit unisgned integer
    int8_t var3 = 3; // 8-bit signed integer
    
    return 0;
}
```

> :warning: **Warning**:
> Memory is very limited for some computers, such as embedded systems. It's a good practice that save memory as much as possible so that out-of-memory can be avoided. That's why we have `uint8_t`, `uint16_t`, etc.


#### Useful Tips

By including `<stdint.h>`, you obtain macros defined by the compiler that returns the limits of integer types. For instance, `INT_MAX` and `INT_MIN` are the maximum value and minimum value representable by the `int` type.

By including `<float.h>`, you obtain macros defined by the compiler that returns the limits of floating point types. For instance, `FLT_MAX` and `-FLT_MAX` are the maximum value and minimum value representable by the `float` type.

- **Macro**: Code that will be replaced with the defined replacement before compilation. e.g. If a macro is defined as `#define PI 3.14`, then the macro `PI` can be used as `deg = rad / PI * 180;`, which will be translated to `deg = rad / 3.14 * 180;` before compilation.
- The `-` in `-FLT_MAX` is not part of the macro, it is the unary minus operator, i.e. the negative sign.

To test for the bit size for different types on the machines, we can use the `sizeof()` operator. For example: `sizeof(int)` will tell us how big `int` really is on the machine that runs the program. You must include `<stdlib.h>` in order to use it.

#### The Boolean Type

C has since added another type, the boolean type in the C99 standard version of C, as `_Bool`. It has also added the useful alias `bool`, (another name for `_Bool`,) as well as macros `true` and `false` to represent the values for convenience, but these **require the inclusion of `<stdbool.h>`**.

|  Type   |                                                   Description                                                    |
|:-------:|:----------------------------------------------------------------------------------------------------------------:|
| `_Bool` | A boolean value represented in a 1-bit integer. Assigning anything non-`0` to it is set to `1`, considered true. |
| `bool`  |                                `true` evaluates to `1`; `false` evaluates to `0`                                 |

#### Standard Integer Types

It is not convenient that `int` is sometimes 2 byte and sometimes 4. It is more useful if we can control exactly how long `int` is, so we do not have to cater to different machine settings. With `<stdint.h>`, we have just that, more type definitions!

|    Type    |       Description       |
|:----------:|:-----------------------:|
|  `int8_t`  |  signed 8-bit integer   |
| `int16_t`  |  signed 16-bit integer  |
| `int32_t`  |  signed 32-bit integer  |
| `int64_t`  |  signed 64-bit integer  |
| `uint8_t`  | unsigned 8-bit integer  |
| `uint16_t` | unsigned 16-bit integer |
| `uint32_t` | unsigned 32-bit integer |
| `uint64_t` | unsigned 64-bit integer |
|    ...     | other less common types |

> :warning: **Warning**:
> Remember we said, **we had to manage the memory by ourselves**? Since C is low level, we get to have more choices regarding the memory of our variables. The reason we **must not use `int64_t` for every integer** we have, is because we have to **manage the performance as well as memory** use of our program, especially **for micro-controllers, that have little computational resources.**

Smaller variables are always faster and they consume less space than larger ones.

#### `const` Type Qualifier

According to [cppreference](https://en.cppreference.com/w/c/language/const), `const` is a type of qualifier in C, adding a "quality" of being constant to the "variable". A variable with such a qualifier in front is not allowed to be reassigned.

```c
const double PI = 3.141592654;
```

Typically, we name constants using the **UPPER_SNAKE_CASE** convention, which is discussed below.

Superficially, this protects unchangeable variables from changing, by emitting an error during compilation, making it safer. *But in a deeper level, this qualifier can change the program in a lower, more technical level in the compiler, possibly altering performance and space efficiency.*

### Variable Declaration

We must tell the computer that we are about to use a variable with some name before we use it. This action is called **declaration**. And we can only declare a variable with the same name once per scope, (we'll talk about that later). We can declare one with this syntax: `<type> <variable_name>;`. For example:

```c=
int16_t some_integer; // Declaring some_integer as a 16-bit integer
char c; //Declaring c as a character
float f; //Declaring f as a 32-bit, single-precision floating point value
```

### Variable Assignment

When a variable is declared, we can assign a value to the variable using the `=` (assignment operator). The first assignment to a variable is called the **initialization**. We should **always initialize any variable we declare before reading them**, as this is an "undefined behavior", the compiler **may or may not crash** from the consequences if you do so. We assign values like so:

```c=
int some_integer;
some_integer = 42;

char c;
c = 'A';

char d;
d = c;
```

In the above example, we set the value `42` to `some_integer`, which we assume is declared before. We also assigned a character, which **must be quoted with single quotes**, to `c`. `42` and `'A'` are called **literals**, because they are basically the value.

Then, we assigned the value stored in `c`, to `d`, so `d` is now having the value `'A'`. **Be careful, the `=` is not the mathematical "equal", it means "assign the RHS to the LHS"**.

### Combined Declaration and Initialization

We may also combine the initialization to the declaration. The safest way to declare is always to first initialize to some default value.

```c
int16_t some_integer = 42;
char c = 'A';
char d = c;
```

Here is a working program:

```c
//variable.c

#include <stdio.h>
#include <stdint.h>

int main() {
    int16_t some_integer = 42;
    printf("The number is ");
    printf("%d", some_integer); //The left is used for formatting
    return 0;
    
    // Console:
    // The number is 42
}
```

### Casting

Assigning a variable or literal in another type to a variable is possible through **casting**. Saving a lower-bit value to a higher-bit container is often safe, but the converse is always unsafe, because information is lost by losing bits. Below are some examples:

```c
int main(){
    bool b = true;
    int n = b; // compiler casts a boolean to an integer, n would be 1 because true -> 1; false -> 0

    char c = 'c';
    n = c; // compiler casts a character to an integer, by using ASCII conversion, n is now 99

    float f = 0.55f;
    n = f; // compiler casts a float to an integer, by truncating the floating point value, n is now 0, same goes with double

    uint8_t p = 6;
    uint16_t q = p; // compiler casts a 8-bit to a 16-bit, since 16-bit can hold larger values, q is also 6

    q = 678;
    p = q; // compiler casts a 16-bit to a 8-bit, since 8-bit cannot store a number this large, it overflows and goes back to 166 (678 in binary with only last 8 bits)

    int16_t j = -5;
    uint16_t k = j; // compiler casts a signed to unsigned, since it cannot store a negative number, it underflows and goes to 65531 (-5 in binary's two's compliment and converts to unsigned)
  
    return 0;
}
```

The type conversion above is an **implicit casting**, i.e. the compiler itself figures out the converted type. Usually, instead, we would prefer a safer approach, that we specify the converted type in our codes.

```c
float f = 2.5f;
int n = (int)f; //n is now 2
```

### Naming Convention and Rules

There are several ways people name their variables, as illustrated in the names:

- `PascalCase`
- `camelCase`
- `snake_case`
- `UPPER_SNAKE_CASE`
- `kebab-case` (Cannot be used in C)

Depending on the organization or the project, you may be asked to use a certain naming convention. They are always used to differentiate between variables, functions, macros and constants, but different people use different styles.

Secondly, in C and in many other languages, these are some points you must follow in naming a variable, otherwise, you may cause an error during compilation.

- Name should begin with a letter or underscore.
  > :negative_squared_cross_mark: **NOT to do this:**
  > ```c=
  > int 520ilovetimwoo;
  > ```

- After the first character, you may include numbers.
  > :heavy_check_mark: **This is acceptable:**
  > ```c=
  > int ilovetimwoo520;
  > ```

- No reserved keywords. E.g. You can't use `int` or `return` as a name.
  > :negative_squared_cross_mark: **NOT to do this:**
  > ```c=
  > int int;
  > float return;
  > ```

#### **Remember, names are case sensitive.**

**Do make meaning names, do not name a variable a letter**. 
As your code becomes longer, you will forget about what they are. It is also clearer to your peer developers if the names are clear. 
When you are naming a numerical variable, name it a meaningfully, such as `rpm`, `velocity`, `id`, instead of `abc`, `hi`, or `hhh`, which no one would understand what are they about. 
When you are naming a Boolean variable, name it a logical statement, like `is_repeat`,  `found_path`, `has_changed`, etc.

> [classwork-02](https://hackmd.io/Fpr8vuHJS1WGAyE3t-Omfg?view#ex-2)

## Standard Input / Output

A program communicates with the outside using standard input and standard output. The most common ways to input and output in C, are reading and writing to and from the console and files.

### Console Output

We can use the function `printf()` from `<stdio.h>` to print to the console, as shown in the hello world example. According to [cppreference][cppref_printf] (referencing a C++ site here because C++ reference is not publicly available, you have to pay ISO to get a copy), the **signature** of the function is:

```c=
int printf ( const char * format, ... );
```

The function returns the number of characters written.

The first parameter is the **format string**. Ordinary characters can be directly printed, but the **`%` character followed by flag characters** is used to specify a substitute with a value when the string is printed. To specifically print out one `%` character, one must **escape** it using `"%%"`.

The remaining `...` means one or more parameters, specifically the value to be printed, ordered accordingly to the **specifiers** in the format string.

Below is a table for the common used ones:

| Specifier |          Explanation           |
|:---------:|:------------------------------:|
|   `%%`    |    Writes one `%` character    |
|   `%c`    |       Writes a character       |
|   `%d`    |       Writes an integer        |
|   `%x`    |  Writes an integer in base 16  |
|   `%f`    | Writes a floating point number |

The above table is very crude, so please refer to [cppreference][cppref_printf] for the complete explanation.

The following is an example:

```c=
printf("No specifiers.\n");
printf("%d specifier.\n", 1);
printf("%d specifiers for %c%c%c.\n", 4, 'i', 'n', 't');

//Console Output
/*
No specifiers.
1 specifier.
4 specifiers for int.
*/
```

> [classwork-03](https://hackmd.io/Fpr8vuHJS1WGAyE3t-Omfg?view#ex-3)

### Console Input

The function `int scanf(const char*, ...)` reads input from the console and stores it into the given variables. To read variables, specify the data type token and provide the address to the variable. The syntax for `scanf` is similar to `printf`, but an **ampersand** (`&`) is required before the variable name.

```c=
#include <stdio.h>

int main() {
    int user_input = 0;
    // enter an integer and press enter
    scanf("%d", &user_input); // your program will be stop here until enter is pressed
    printf("retrieved value: %d", user_input);
    
    return 0;
}
```

* `int scanf(const char *format, ...)`
    * `const char *format` is a *pointer* to a **const**ant **char**acter. For now, don't worry about what a pointer is. You can think of the parameter as requiring a piece of text. For example: `"Danny"`, `"%d"`.
    * `...` refers to the variables for storing the information. Due to the nature of C (and because of pointers), you should add `&` in front of your variables. For example: `&GPA`.
        * You can pass any number of variables to receive information.
        * e.g. `scanf("%d %c %s", &int_input, &char_input, &str_input);` accepts "123 a haha" and results in `int_input = 123`, `char_input = 'a'`, `str_input = "haha"`.
        * Documentation: [scanf](https://www.cplusplus.com/reference/cstdio/scanf/)

> **Q**: What is the use of `&`?
> 
> **A**: A variable consists of a name, value and address. `&` returns the address of the variable. This topic (pointers) will be taught in depth in later advanced notes which will not be covered in this tutorial.

> [classwork-04](https://hackmd.io/Fpr8vuHJS1WGAyE3t-Omfg?view#ex-4)

## Arrays

Variables are nice, but what if we need to store a hundred integers :thinking_face:?

```c=
int var_0;
int var_1;
int var_2;
int var_3;
.
.
.
int var_99;
```
Although this above method is possible, it is not efficient or feasible. Hence, we use **Array**.

Array is another type of variable. It is a container for multiple values of the same type. Arrays carries type information and can only carry one type of values in one array. Think arrays as cabinets, and each value belong in one drawer in a cabinet.

An array must have a **constant length**, specified either at declaration, or interpreted at initialization.

Refer to [cppreference](https://en.cppreference.com/w/c/language/array) for more details.

### Array Declaration

The following is the syntax for declaration: `<element_type> <array_name>[<size (optional)>];`

The `[]`(square brackets) specifies an array.

The following is an example of declaring a float array with length 10;

```c=
float numbers[10];
```

### Array Initialization

An array can be initialized alongside declaration with values, by using the initializer expression, like so:

```c=
int natural_numberes[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //remaining spaces are filled with 0s
```

If you initialize using the initializer expression, you are not required to specify the array length. It will count the number of elements and set the length as that.

Uninitialized arrays in functions store **garbage values** as initial values. If you want to initialize them as all `0`s, do the following:

```c=
int blank[20] = {0};
```

**Arrays cannot be re-assigned**, so you cannot use the initializer expression after the declaration statement, nor assign them to another array variable.

> :exclamation: **Index**: The first index of an array
> :exclamation: **Boundary Issue**: **Accessing an array out of bounds** is **undefined behavior**, it may not generate any error when used. ([Read more.](https://www.geeksforgeeks.org/accessing-array-bounds-ccpp/))


### Array Access

Array items do not have a name we can call, but they are arranged in an orderly fashion within an array. We can access items using an **index**. We count from 0 in programming, so we can call, e.g. the 0th item in array x. The index can be a variable containing an integer, or simply an integer literal. The following is the syntax of array access: `<array_name>[<index>]`

For example:

```c
int numbers[10];
numbers[0] = 3;
int y = numbers [0]; //y is 3
```

**Accessing outside the array region is an undefined behavior but may not generate any error when used.** Values are retrieved at other memory addresses that do not belong to the array and the values are not guaranteed as the same across machines. Accessing outside of program memory will produce a "SIGSEGV Signal Segmentation Fault" runtime error.

Arrays are usually used with for loops, to iterate over the length of the array for data manipulation.

This example populates the array with natural numbers:

```c
int n[100];

for (int i = 0; i < 100; i++) {
    n[i] = i+1;
}
```

### Character Array

In C, there is no built-in `string` type. As an alternative, we use **character arrays** to represent a string:
```c
char name[] = "Danny";
```

Although the length of `Danny` is `5`, there is an invisible character `'\0'` at the end, which C uses to indicate the end of the character array. Hence, the size of `name` array is actually `6`.

Just like normal arrays, you can initialize char arrays using `{}` (note that here, we have to a xx`'\0'` character by ourselves):
```c
char day[] = {'2', '4', '-', '0', '7', '-', '2', '0', '2', '0', '\0'};
```

And then you can print the character array using a loop:
```c=
int i = 0;
while (day[i] != '\0') {
    // i++ is post-increment,
    // that means it returns the original value of i,
    // before adding 1 to i
    printf("%c", day[i++]);
}

printf("\n");
```

### Multidimensional Arrays

Arrays can have multiple dimensions. The arrays we have explored above are called 1D arrays.

To declare arrays with additional dimensions, just do as follows:

```c
int map[5][10];
```

The above declares a 5-by-10 array.

To access a cell, it can be done as:

```c
map[4][8] = 2;
```

Alternatively, you can consider multidimentional arrays as matrices. 
For example:

```c=
int map[4][3];
map[0][0] = 1;
map[0][1] = 5;
map[0][2] = 2;
map[1][0] = 3;
map[1][1] = 4;
map[1][2] = 9;
map[2][0] = 7;
map[2][1] = 6;
map[2][2] = 4;
map[3][0] = 5;
map[3][1] = 5;
map[3][2] = 3;
```

`map[4][3]` can be written in matrix as below:

![](https://latex.codecogs.com/png.image?%5Cdpi%7B110%7D%20%5Cmathrm%7Bmap%20=%20%7D%5Cbegin%7Bpmatrix%7D1%20&%205%20&%202%20%5C%5C3%20&%204%20&%209%20%5C%5C7%20&%206%20&%204%20%5C%5C5%20&%205%20&%203%20%5C%5C%5Cend%7Bpmatrix%7D)

> [classwork-05](https://hackmd.io/Fpr8vuHJS1WGAyE3t-Omfg?view#ex-5)
> [classwork-06](https://hackmd.io/Fpr8vuHJS1WGAyE3t-Omfg?view#ex-6)
## Operators

Operators help us to perform the most fundamental mathematical or logical operations on variables.

**Operators** can accept different numbers of **operands**. Their names are as follows:

- **Unary** Operators:
  
  Takes a single operand 
  `+x`
  `-x`
  `*x`
  `++x`
  `--x`
  `x++`
  `x--`
  `!x`
  `~x`
  
- **Binary** Operators:

  Takes two operands
  `x + y`
  `x - y`
  `x * y`
  `x / y`
  `x % y`
  `x && y`
  `x || y`
  
- **Ternary** Operator:

  Takes three operands
  `x ? y : z`
  
**Beware that different operators carry different precedences**, meaning values are evaluated from the operator with highest precedence down to the lowest, like how multiplication comes first before addition in maths. 

### Assignment Operators

- `=` assignment (B)
- ...

### Compound Assignment Operators

These operators merge arithmetic and assignment into one operation. For example:

* `+=`: Adds right operand to left operand, and assigns the resultant value to left operand.

```c=
int a = 1;
int b = 2;

a += b; // equal to a = a + b
```

There are more assignment operators (e.g. `-=`, `/=`, `%=`). Read [this](https://www.tutorialspoint.com/cprogramming/c_assignment_operators.htm) for more details.

### Arithmetic Operators

These are your typical mathematical operators:

- `+` addition (B)
- `+` unary plus (UB. no effect, just for symmetry)
- `-` subtraction (B)
- `-` unary minus (UB)
- `*` multiplication (B)
- `/` division (B)
- `%` modulo (B)
- ...

```c=
#include <stdio.h>

int main() {
    printf("addition: %d\n", 2 + 3); // prints 5
    printf("subtraction: %d\n", 20 - 8); // prints 12
    printf("multiplication: %d\n", 500 * 4); // prints 2000
    printf("division (int): %d\n", 5 / 2); // prints 2
    printf("division (float): %f\n", 5.0f / 2.0f); // prints 2.5
    printf("modulo: %d\n", 13 % 5); // prints 3
    
    return 0;
}
```

> :warning: **Warning:** 
> Note the two different divisions in the example above.
In math, 5 / 2 = 2.5. However, in C, both `5` and `2` are integers, so integer division is performed. This means the decimal part is discarded giving `2` as its result.
In contrast to this, `5.0f` and `2.0f` are floats, so floating-point division is performed and the decimal part is retained, giving (about) `2.5` as its result.


### Relational Operators

A relational operator compares the value of two expressions, most of which are self explanatory. These operators take two operators and return `true`/`1` or `false`/`0`.


- `==` equal to (B)
- `!=` not equal to (B)
- `>` greater than (B)
- `>=` greater than or equal to (B)
- `<` less than (B)
- `<=` less than or equal to (B)

> :Warning: **Warning:**
> *Do not mix up `=` and `==`*. One is used for value assignment, the other used to compare whether the values are the same.

### Logical Operators

- `||`: Logical "or". Returns `true` if left or right operands are non-zero.
- `&&`: Logical "and". Returns `true` if left and right operands are non-zero 
- `!` Logical "not". Reverses the truthness of its operand.

These operators accept **boolean represented** values on both sides, and perform logical operations on them to return a boolean value.

> :warning: **Warning:**
> `!` has a higher precedence than `||` and `&&`.

#### Truth Table

|    P    |    Q    | P or Q  | P and Q |  not P  |
|:-------:|:-------:|:-------:|:-------:|:-------:|
| `false` | `false` | `false` | `false` | `true`  |
| `false` | `true`  | `true`  | `false` | `true`  |
| `true`  | `false` | `true`  | `false` | `false` |
| `true`  | `true`  | `true`  | `true`  | `false` |

Read [Operators in C and C++ on Wikipedia](https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B) for more information, including **Bitwise operators**, **compound assignment operators**, **Member and pointer operators**, etc.

> **:bulb:TIPS**:
> Conditions can be chained by logical operators. For example:
> ```c=
> int_a != int_b || !(int_c > int_d)
> ```

### Ternary Operator

The **ternary operator** is also known as **conditional operator**. It is similar to `if...else...`, but is faster to type and is considered as a shortcut for `if`. We will cover more about this after the [If] `if` statement.

## Statements

A statement is a fragment of code in C. All statement types are on [cppreference](https://en.cppreference.com/w/c/language/statements).

### Expression Statements

Expression statements are the lines of code that ends in `;`. Or in other words: an expression statement is **a line of code**. Most statements are expression statements.

For example:
```c=
#include <stdio.h>

int main() {
    int some_integer = 0;
    printf("updated value: %d", some_integer = 100);
    
    return 0;
}
```

`some_integer = 100` is an expression. After execution, the expression statement returns 100. So eventually `updated value: 100` is printed. By making good use of this feature, you can minimize the lines of code.


### Compound Statements (Code Block)

Compound statements consists of one or more lines of code. It defines a **scope**. They are also called **code blocks**.

One in a scope can access variables declared in itself, as well as variables in larger scopes, but not those in smaller scopes inside itself nor neighboring scopes nor any of its parents. Essentially, the access right to a variable is only at its level upwards.

For example:
```c=
#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    printf("a: %d, b: %d\n", a, b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("a: %d, b: %d\n", a, b);
    return 0;
}
```

the code inside `{}` are compound statements.

#### Selection Statements

Selection statements modifies the **control flow** of the program. It uses different sets of code depending on the condition at **runtime**.

##### If Statements

Code blocks are bounded by a set of `{}`, which you have already seen, surrounds the `main()` function.

The if statements takes the following formats:

- `if (<expression>) <statement_true>`
- `if (<expression>) <statement_true> else <statement_false>`

If `expression` evaluates to a `non-zero` value, then `statement_true` is evaluated. Otherwise, `statement_false` is evaluated if provided along with the `else` clause.


Often, `statement_false` is itself another if statement, chaining into an (if, else if, else) structure.

The following is an example:

```c=
uint32_t money = 100;
if (money) {
    printf("I have $%d.\n", money);
} else {
    printf("I have no money.\n");
}

//Console Output: I have $100.

money = money - 100;

if (money) {
    printf("I have $%d.\n", money);
}

//Console Output: (Literally nothing)
```

At the beginning, the value of money is 100. When the program is executing the first if statement, `money` is a non-zero value, so `printf("I have $%d.\n", money);` is executed.

The value of `money` is then substracted by 100, so the value is now equal to `0`. Then when the program runs the second `if` statement, the if-block is skipped.

We can chain multiple if-conditions by writing another if-statement after an `else`.

The following is an example:

```c=
if (x > 85) {
    // if x > 85 evaluates to true, this part is run.
    // otherwise, this part is skipped.
} else if (x == 0) {
    // some other code
    // only runs if (x > 85) is false and if (x == 0) is true
} else {
    // some other code
    // only runs if both (x > 85) and (x == 0) are false
}
```

#### Switch Statements

Switch statements allow a variable to be tested for each case. It contains **jump statements** and **labels**, which we do not recommend using outside of switch statements. They act simply as alternatives to if statements on the superficial level. The format is as follows:

- `switch (<expression>) <statement>`

  The "expression" here must evaluate to some integral value. And the "statement" here is typically a block with case labels.

- `case <integer_constant_expression>: <statement>`
- `default: <statement>`

```c=
switch (x) {//value to compare against with the cases
    case 1:
        //code for when x == 1
        break; //jumps the the end of the switch statement
    case 2:
        //code for when x == 2
    case 3:
        //code carries on from line above and for when x == 3
        break;
    default:
        //code when none of the cases match. The default label is optional
}
```

Each case is compared against the expression in the switch parenthesis, if a match is found, the program **jumps** to that case and start executing line by line, and only exits when encountering `break;` or when the code block ends.

Basically, switch-statements are just if-statements when all their conditions are `x == case`.

### Iteration Statements

Iteration statements are used to repeat a section of code.

#### While loop

This statement will execute repeatedly as long as the condition is met. The format is as follows:

- `while (<expression>) <statement>`

The following is an example:

```c=
int i = 0;
while (i < 10) {
    printf("%d\n", i);
    i++; // you treat i++ as i = i + 1
}
```

The program checks if `i < 10`. If true, then the statements inside `{}` block are executed. After the block is executed, the program loops back to `i < 10` and executes the block again, until the condition is false.

#### Do-while loop

This statement will execute, then repeatedly execute as long as the condition is met. The format is as follows:

- `do <statement> while (<expression>);`

```c=
do {
    //do something
} while (is_repeat);
```

If `is_repeated` is `ture`, the statement will keep looping until `is_repeated` is `false`.

#### For Loop

Often, developers use while loops to execute code while counting. For loops were introduced to simplify this situation, while encasing the **iterator** (the counting number) within the scope. The following example illustrates this.

```c=
//This program prints from 0 to 9
int i = 0;
while (i < 10) {
    printf("%d\n", i);
    i++;
}

//Written more concisely as:
for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
}
```

The for loop format is as follows:

- `for (<init_clause>; <expression (optional)>; <expression (optional)>) <statement>`

The 3 clauses in the parenthesis are usually called:

- **Initialization Expression**

  This expression is run before the statement. Usually, an iterator variable is declared and initialized here.
  
- **Condition**

  This expression is run before every iteration of the loop to determine whether the body of the loop would be run, or whether the loop ends here. Same as before, the body is run when this expression is a non-zero value.
  
- **Final Sxpression**

  This expression is run after every iteration of the loop. Usually, the iterator is incremented or decremented here.
  
This is the for loop version of the number printing program above:

```c=
for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
}
```

Of course, because the body is only a single line, the curly braces are not required. So it can become as so:

```c=
for (int i = 0; i < 10; i++)
    printf("%d\n", i);
```

In fact, you can omit the one of the clauses, or even all of them:

```c=
int i = 0;
for (; i < 10; i++) {
    printf("%d\n", i);
}
```

### Jump Statements

Jump statements alter the flow of the program by literally jumping to a different section of code to execute.

- `break;`

  This statement is only valid in loops and switch statements. It is used to exit the statement, *breaking* the execution.
  
  Example:
  
  ```c=
  for (int i = 0; i < 20; i++) {
      printf("%i = d\n", i);
      if (i == 15) break;
  }
  ```

- `continue;`

  This statement is only valid in loops. It breaks from the current iteration and executes the final expression if the loop is a for loop, then it will move to the condition for comparision immediately, *continuing* the loop.
  
  Example:
  ```c=
  for (int i = 0; i < 50; i++) {
      if (i % 2) continue; // skips the printf...
                           // i++ will run, then i < 50
      printf("i = %d\n", i);
  }
  ```

- `return <expression (optional)>;`

  This statement is only valid in functions. It terminates the function, then *returns* a resulting value to the caller. It is seen in the `main()` function, returning a program termination code to the operating system.
  
  `return;` is treated as returning `void`.

- `goto <identifier>;`

  This statement is used to jump to a certain label to continue program execution. **This statement is highly unrecommended, since it may create an erratic control flow as it can jump from scope to scope, and is harmful to debugging as it is difficult to follow the execution path of the program.**

## Functions

A function is a collection of commands that perform tasks. `printf()` and `scanf()` are examples of functions. Functions provide **abstraction**, i.e. providing a simpler interface to hide complex implementations. We have already defined one before, it is `main()`, the entry point to our program. Functions perform different tasks and may even return values.

### Function Declaration

Being like variables, functions can only be accessed after the compiler knows about it, reading from the top. So to use a function in `main()` for example, it either has to be defined above, or declared above and defined elsewhere.

If a function is declared before, then the compiler knows about its existence, and expect it to be defined some time in the future as it reads from file to file. The definition can be in any place in any file, as long as it is in some place the compiler expects.

If the function is declared, used, but not defined, then the compiler will generate a `reference to function not found` error.

The declaration/prototype is like so:
`<return_type> <function_name>(<parameters...>);`

In `<parameters...>`, each parameter can be simply `<type_specifier>` without a parameter name, since they are not used immediately, though leaving a name may provide more details to how the function can be used.

If your function does not take any parameters (i.e. `<parameters>` is empty), you can type in `void` or leave it as it is.


Here is an example:
```c
// this function accepts zero parameters
int get_current_time(void);

/**
 * The major difference is:
 * without putting void in the parentheses means this function has any number of parameters.
 * That means you pass any parameter into the function, but you cannnot access it.
 * 
 * However, in C++, there are no differences.
 */
int get_current_time2();

// this function accepts two integers
int addition(int a, int b);

// "void" return type means this function doesn't return anything
void robot_move(int pos_x, int pos_y, int pos_z);

/**
 * You can also pass a function as a parameter.
 * The declaration below accepts a function called "operation".
 * The details will be taught in later tutorials.
 */
int calculator(int a, int b, int (*operation)(int, int));
```

> **Example of void parentheses and empty parentheses**:
> 
> ```c=
> #include <stdio.h>
> 
> int test_funcs(void) {
>     return 2;
> }
> 
> int test_funcs2() {
>     return 1;
> }
> int main() {
>     printf("test_funcs: %d\n", test_funcs());
>     printf("test_funcs2: %d\n", test_funcs2(0, 1, 2));
>     return 0;
> }
> ```
> 
> ![](https://i.imgur.com/RrAlq2F.png)
> 
> Although the compiler throws a warning, the program works. However, if you change add extra arguments to `test_funcs`:
> ```c=
> printf("test_funcs: %d\n", test_funcs(0, 1, 2));
> ```
> ![](https://i.imgur.com/Eh1BNfZ.png)
> 
> The program cannot be compiled successfully. For more details about empty parentheses, read **[this](https://wiki.sei.cmu.edu/confluence/display/c/DCL20-C.+Explicitly+specify+void+when+a+function+accepts+no+arguments)**.

### Function Definition

Functions can be used by simply defining one. Declaration is not compulsory.

The most commonly used function definition syntax is as follows:
```c
<return_type> <function_name>(<parameters...>) {
    // your code
}
```

In `<parameters...>`, parameters are separated by a `,` (comma operator). Each parameter consist of `<type_specifier> <parameter_name>`. The type specifier specifies the type of parameter the function accepts, and the parameter name is some arbitrary name, used and only meaningful inside the function.

For example:

```c=
int square(int x) {
    return x*x;
}

int addition(int a, int b) {
    const int sum = a + b; // by adding const before the type, the value of the variable is constant
    printf("%d + %d = %d", a, b, sum); // you can call other functions inside a function too!
    return sum; //return the result
}

int calculator(int a, int b, int (*operation)(int, int)) {
    // we can treat "operation" as a function:
    return operation(a, b);
}
```

Then we can call it by `square(3)` for example, it would return `9` at the calling place.

### Function Call

A function call takes form of: `<function_name>(<parameters...>)`

A C function call/invocation is same as those of mathematical functions, for which they accept parameters as inputs and returns an output as a response, although C functions can also perform simple actions without any response. The parameters provided to a function call can be variables or literals, just anything that carries a value.

For example:

```c=
#include <stdio.h>

int addition(int a, int b) {
    const int sum = a + b; // by adding const before the type, the value of the variable is constant
    return sum; //return the result
}

int main(){
    printf("1 + 2 = %d\t", addition(1, 2));
    return 0;
}
```
[classwork-07](https://hackmd.io/Fpr8vuHJS1WGAyE3t-Omfg?view#ex-7)

## Program Time

There are mainly 3 time periods of a compiled program:

- Compile time

  During compilation. Compiler catches syntax errors and other compile time errors here. If there is an error, the program will not be built.

- Link time

  The compiler links different bits of compiled code after compilation. In future compilations, the compiler will only compile changed files and run the linker again. Linking error may occur if references to objects are not found, or when compiling for embedded systems, memory allocations exceeded maximum memory allowance.

- Runtime

  This is when the program is running. Unless the program is in **debug mode**, errors here may result in the program crashing without any messages. During debugging, fatal runtime errors will trigger a **breakpoint** and an error message and the erroneous line is displayed.
  
## What should I do if I get stuck while programming?

Although programming can be fun, debugging is stressful and exhausting. You may come across some bugs that you cannot solve by yourself. Here are some useful websites to use:

* https://www.google.com/
* https://stackoverflow.com/

The easiest way to debug is to print stuff out, so that you can track (1) how your values change and (2) whether your code reaches a certain line of code (e.g. maybe an if-condition failed).

If you really don't know which lines of code cause bugs, you can comment parts of your code and run the code again to see if the bugs reappear or not.

Enjoy your time debugging!

## Reference Materials

https://www-s.acm.illinois.edu/webmonkeys/book/c_guide/

