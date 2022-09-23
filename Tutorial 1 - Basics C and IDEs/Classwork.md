# Software Tutorial 1 - Classwork [![HackMD Version](https://img.shields.io/badge/Made%20with-Markdown-1f425f.svg)](https://hackmd.io/Fpr8vuHJS1WGAyE3t-Omfg?view#ex-1)

## <a id="ex-1"></a>Identify Errors

The following code includes several errors. Identify the errors and correct them such that the code can be compiled.
```c=
#include <stdioh>

void main() {
  printf("Hello, World!\n")
  printf("Welcome to the first software tutorial!\n");
  
  return 0;
```

Your correct code should give the following output:
```shell=
Hello, World!
Welcome to the first software tutorial!
```

## <a id="ex-2"></a>Swapping Contents

Implement your code such that the values of `a` and `b` are swapped. 

```c=
#include <stdio.h>

int main() {
    float a = 4.0f, b= 3.7f, c;
    printf("before swapping, a = %f, b = %f\n", a, b);
  // your code starts here
  
  // your code ends here
    printf("after swapping, a = %f, b = %f\n", a, b);
    return 0;
}
```

## <a id="ex-3"></a>Introduce Yourself

Add a print statement below such that `GPA` and `year` are printed.

```c
#include <stdio.h>

int main() {
  /**
   * By adding const here, your gpa freezes and will always be 4.3!
   * Adding const makes the variable *constant* throughout the program.
   */
  const float GPA = 4.3f;
  
  /**
   * If const was added here, you'll always be a year 1 student,
   * so you can't graduate!
   */
  int year = 1;
  
  // your code starts here
  
  // your code ends here
  return 0;
}
```

### Example Output
```shell
I am a year 1 stduent with GPA 4.3.
```

## <a id="ex-4"></a>Introduce Yourself (Interactive)
This time you are required to implement an interactive program. The program should ask for your current GPA and current year, save the information into the corresponding variables, then print the variables on a new line. 

### Example Output
```shell=
What is your GPA: 4.0
What is your year: 2
I am a year 2 stduent with GPA 4.0.
```

`What is your GPA:` and `What is your year:` should be printed by your program.

### Reminder
* You can make the program based on the first `Introduce Yourself`.
  * But should you keep the constness of `GPA`?
* `scanf` reads the console input and save the information to variables
  * [More notes on `scanf`...](https://hackmd.io/@Oil/r1WwNPIXK#Console-Input)
    
## <a id="ex-5"></a>Matrix Addition

A matrix is a rectangular arrangement of numbers into rows and columns. Each number in a matrix refers to a matrix element.

To perform matrix addition, you need to have two matrices of the same size. Then you can sum up the entries respectively.

### Example:

![](https://i.imgur.com/aBG1uXI.gif)


We call the matrix above a $3 \times 2$ matrix with entries $a_1$ to $a_6$.

Now, given another $3 \times 2$ matrix $B$:

![](https://i.imgur.com/tuV4RII.gif)

Since the size of A and B are the same, we can perform matrix addition:

![](https://i.imgur.com/mD8yiR7.gif)

### Task

Implement the code to perform $3 \times 2$ matrix addition.

```c=
#include <stdio.h>

void display_matrix(int matrix[][2], int num_row) {
  for (int r = 0; r < num_row; r++) {
    for (int c = 0; c < 2; c++) {
      printf("\t%d", matrix[r][c]);
    }
    printf("\n");
  }
}

int main() {
  int matrix_A[3][2] = {
    {0, 1},
    {2, 3},
    {4, 5}
  };
  
  int matrix_B[3][2] = {
    {0, 1},
    {2, 3},
    {4, 5}
  };
  
  int result[3][2] = {0};
  
  // your code starts here
  
  // your code ends here
  
  printf("A = \n");
  display_matrix(matrix_A, 3);
  printf("\nB = \n");
  display_matrix(matrix_B, 3);
  printf("\nA + B = \n");
  display_matrix(result, 3);
  return 0;
}
```

## <a id="ex-6"></a>First Word

In the tutorial, we mentioned that `\0` is a special charater that indicates the end of a char array. In this question, you are required to print the first word found in the char array. That is, you should only print up to the first ` ` (space character). You should remove / not display the characters afterwards.


### Example

Input: `Danny is lonely.`
Output: `Danny`

Input: `Chalex is handsome.`
Output: `Chalex`

### Skeleton Code
```c=
#include <stdio.h>
// #include <string.h> // uncomment this line if needed 

int main() {
  char input[] = "Welcome to HKUST Robotics Team Software Tutorial";
  printf("Before trimming: %s\n", input);

  // your code starts here
  
  // your code ends here
  
  printf("After trimming: %s\n", input);
  return 0;
}
```

### Tips

* Think of how C prints a char array.

## <a id="ex-7"></a>Area of circle

Construct a function called `circleArea` to calculate the area of a circle using `float`s. Modify the following code:

```c
#include <stdio.h>
#include <stdbool.h>

// your function starts here
  
// your function ends here

int main() {
  printf("%f", circleArea(5.0f));
  return 0;
}
```
