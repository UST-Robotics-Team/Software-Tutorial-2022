# Extra of Tutorial 1 - Advanced C [![HackMD Version](https://img.shields.io/badge/Made%20with-Markdown-1f425f.svg)](https://hackmd.io/@Oil/ByBhQq8QF)

Original Author: Chalex (cwchanbm@connect.ust.hk)

Modified by: Li Ka Yau Elwin (kyeliaa@connect.ust.hk)

## Table of Content

[TOC]

## Pointer

### Addresses
When you declare a variable, the compiler stores it at a memory location.

Given a variable named `var`, we can determine its memory address with `&var`.

```c=
#include <stdio.h>

int main() {
    int var = 5;
    printf("value of var : %d\n", var);
    printf("address of var : %p\n", &var);
    return 0;
}
```

If you run the code above, you'll get something like this:

```
value of var : 5
address of var : 0x7ffe36dfeab8
```

### What is a Pointer?
**pointer** : A variable for storing addresses of a specific type.  
You use `*` to declare pointer variables.

```c=
// all of these are equivalent
int* p0;
int * p1;
int *p2;
```
```c=
int num;
int* addr = &num;
/**
 *  The integer pointer variable 'addr' contains 
 *  the address of the integer variable 'num'.
 * /
```

You can access the variable pointed by the pointer (called **dereferencing**). This is done by putting `*` in front of the pointer.
![pointer](pointer.png)

```c
#include <stdio.h>

int num = 10;
int* addr = &num;

int main(void) {
    printf("value of `num` : %d\n", num);
    printf("value of `*addr` : %d\n", *addr);
    return 0;
}
```

Output:
```
value of `num` : 10
value of `*addr` : 10
```


#### Sample Code
```c
#include <stdio.h>

int num = 1;
int* addr = &num;

int main(void) {
    printf("&num = %p \n", &num);
    printf("addr = %p \n", addr);
    printf("num = %d \n", num);
    num += 1;
    printf("*addr = %d \n", *addr);
    *addr += 1;
    printf("num = %d \n", num);
    return 0;
}
```

Output:
```
&num = 0x1086fe010 
addr = 0x1086fe010 
num = 1 
*addr = 2 
num = 3 
```

### Pointers As Arguments of Functions
You can pass pointers as arguments of functions just like other variables.
```c
int add(int* a, int* b) {
    return *a + *b;
}
```
because you pass addresses as parameters, you can change the pointed variables within functions.
```c
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// a becomes b, b becomes a
``` 

## Enumeration
**Enumeration** (aka Enum): User-defined data type for assigning names to constants, so the code becomes more legible.
> We will use `UPPER_SNAKE_CASE` most of the time for enums.

```c
enum week {
    SUNDAY, 
    MONDAY, 
    TUESDAY, 
    WEDNESDAY, 
    THURSDAY, 
    FRIDAY, 
    SATURDAY
};
/**
 * SUNDAY corresponds to 0
 * MONDAY corresponds to 1
 * ...
 * SATURDAY corresponds to 6
 * /
```

#### Sample Code
```c
#include <stdio.h> 

enum week {
    SUNDAY, 
    MONDAY = 0, 
    TUESDAY = 3
};
  
int main() { 
   printf("%d, %d, %d\n", sunday, monday, tuesday); 
   return 0; 
}
```

Output:
```
0, 0, 3
```

You can also declare enum variables.

```c
// creating an enum variable called `day` of type `week`

enum week {
    SUNDAY, 
    MONDAY, 
    TUESDAY
} day;

/*--- OR ---*/

enum week {
    SUNDAY, 
    MONDAY, 
    TUESDAY
};
enum week day;
```

#### Sample Code
```c
#include <stdio.h> 
  
enum week {
    SUNDAY, 
    MONDAY = 3, 
    TUESDAY
}; 
  
int main() { 
    enum week day; 
    day = tuesday; 
    printf("%d\n", day); 
    return 0;
}
```

Output:
```
4
```

Enums are useful when we want to define multiple variables which can be grouped together.

## Struct
**struct**: User-defined data type for combining data items with different types into one.

```c
struct USTMember {
    char name[20];
    int ID;
    int age;
} student;
/**
 *  `USTMember` is an optional structure tag.
 *  `student` is a variable name of type `struct USTMember`.
 *  Declaring variables after the struct is optional.
 */
```
You can access members of the structure using the dot operator `.`. For example: `Student.ID` or `Student.age`.

#### Sample Code
```c
#include <stdio.h>
#include <string.h>

struct USTMember {
    char name[20];
    int ID;
    int age;
};

void print_info(struct USTMember student) {
    printf("Student Name : %s\n", student.name);
    printf("Student ID : %d\n", student.ID);
    printf("Student Age : %d\n", student.age);   
}

int main() {
    struct USTMember student; /* variable `student` of type `USTMember` */
    strcpy(student.name, "John");
    student.ID = 1010;
    student.age = 18;
    
    print_info(student);
    return 0;
}
```

To access members of pointers to struct, use `->` instead of `.`.

```c
struct USTMember* student;
student->ID = 1010;
student->age = 18;
```
___
## Union
**union**: Data-type which stores data items with different types in the same memory location.

```c
union Data {
   int i;
   float f;
   char s[15];
} data;
/**
 *  `Data` is an optional union tag.
 *  `data` is a variable of type `union Data`.
 *  Declaring variables after the union is optional.
 * /
```

#### Sample Code
```c
#include <stdio.h>
#include <string.h>
 
union Data {
   int i;
   float f;
   char s[15];
};
 
int main() {
   union Data data; /* variable `data` of type Data */ 

   data.i = 1;
   data.f = 3.14;
   strcpy(data.s, "Robotics team");

   printf("data.i : %d\n", data.i);
   printf("data.f : %f\n", data.f);
   printf("data.str : %s\n", data.s);

   return 0;
}
```

Output:
```
data.i : 1868722002
data.f : 70078190219652804681100427264.000000
data.str : Robotics team
```
Note that prior to printing the data members, the final value set is `"Robotics team"` to the `char s[15]` member.

The result would be chaotic because all data members are stored in the same memory. The printed values will correspond to "Robotics team" in their own data type.

## Typedef
**typedef**: Keyword for users to give a data type a new name.

```c
typedef int INTEGER;

INTEGER a, b;
/**
 * identifier `INTEGER` is treated as `int`
 * so `a` and `b` would be treated as `int`.
 * /
```

`typedef` can also be used to simplify user-defined data types.

```c
typedef struct USTMember {
    char name[20];
    int ID;
    int age;
} Student;

// The following are equivalent:
struct USTMember john;
Student john;
```

```c=
typedef enum Day{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Satuarday,
    Sunday
} day;

// The following are equivalent
enum Day today = Monday;
day today = Monday;
```

## Preprocessor

**Preprocessor**: An instruction that takes action before compilation. It may expand source code, include/exclude source code, or optimise code in a particular way.

**Preprocessor directives**: Lines which start with `#`, which will be processed by the preprocessor.

### 4 Types of Preprocessor Directives
1. **File Inclusion**  
Tells the compiler to include a file using the `#include` directive.

    - **standard / header file**: files provided by the (standard) library. Contains pre-defined functions like `printf()`. These files are included with `<>`.
    Example: `#include <stdio.h>`
    - **user-defined file**: header files defined/written by the user. It's a good practice to divide up functions into separate files and include only when needed. These files are included with `""`.
    Example: `#include "mylibrary.h"`

2. **Macro**  
Associates a name with a piece of code. During preprocessing, the compiler will replace all encounters of the name with the corresponding code. Macros are defined with the `#define` directive.

	```c
	#define SIZE 5
	
	//  All occurrences of `SIZE` will be replaced by `5`.
	int array[SIZE];
	for (int i = 0; i < SIZE; i++) {
		scanf(" %d", &array[i]);
	}
	for (int i = 0; i < SIZE; i++) { 
	    printf("%d \n", array[i]); 
	}
	```

	Macros can take arguments and can be used like functions.

	**Sample Code**

	```c
	#include <stdio.h>
	
	#define PI 3.14159265
	#define CIRCLE_AREA(r) (r*r*PI)
	
	int main() {
	    float radius = 10.0, area;
	    
	    area = CIRCLE_AREA(radius);
	    printf("Area of the circle : %ld", area);
	    
	    return 0;
	}
	```

3. **Conditional Compilation**  
Tells C to compile a specific portion of the program or to skip compilation of some specific part of the program based on conditions, enclosed with `#ifdef`, and `#endif`.

	```c
	#ifdef macro_name
	    // code to be compiled if a macro named
	    // `macro_name` is defined.
	    // if it's not defined, compiler will just 
	    // skip this chunk of code.
	#endif
	```
	You can also use `#if`,`#elif` and `#else` for conditional compilation.
	
	```c
	#if defined macro_name
	    // code to be compiled if a macro named
	    // `macro_name` is defined.
	#elif defined another_macro
	    // code to be compiled if the macro 
	    // above is not defined.
	    // and a macro named `another_macro` is defined.
	#else
	    // code to be compiled if above two macros
	    // are not defined.
	#endif
	```
4. **Others**

- `#undef`: used to undefine existing macros.

	```c
	#define X 10
	// after this, X will be replaced with 10
	#undef X
	// after this, X is not defined
	#define X 20
	// after this, X will be replaced with 20
	```
	
- `#pragma`: a subset of special commands for the compiler. Some pragma directives are unique to certain compilers.
	Examples:
	
	```
	#pragma once
	#pragma GCC optimize ("O3")
	#pragma forceinline
	```

## Other Keywords

**`static`** : variables / functions with this keyword can only be accessed within the scope they're declared in. 

```c
static int x = 0;
```

Their values will persist throughout the scope of a function or block.

**`extern`** : variables need to be declared with this keyword when they are accessed from external files.

#### Sample Code
```c
// library.c
int a = 100;
```
```c
// main.c
#include <stdio.h>

extern int a;

int main() {
    printf("a = ", a);
    return 0;
}
```


**`inline`** : functions defined with this keyword would expand to their definition within the code when they are called.

> ### What's good about inline functions?
> Inline functions expand their definition where called. This may help save cpu memory resources and time.

> Inline functions are cool, but if you inline a *huge* function it could increase code size unnecessarily. So usually we only use this keyword on small and light functions.


## Sources
- Pointers: 
  - https://www.tutorialspoint.com/cprogramming/c_pointers.htm
  - https://www.programiz.com/c-programming/c-pointers
- Enumeration: 
  - https://www.geeksforgeeks.org/enumeration-enum-c/
- Structure: 
  - https://www.tutorialspoint.com/cprogramming/c_structures.htm
- Union:
  - https://www.tutorialspoint.com/cprogramming/c_unions.htm
- Typedef:
  - https://www.tutorialspoint.com/cprogramming/c_typedef.htm
- Preprocessor:
  - https://www.tutorialspoint.com/cprogramming/c_preprocessors.htm
  - https://www.geeksforgeeks.org/cc-preprocessors/
  - https://docs.microsoft.com/en-us/cpp/preprocessor/preprocessor?view=vs-2019
