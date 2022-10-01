# 2022 Robotics Team Software Tutorial HW 1 test cases

The following are some test cases used by ZINC. You can try these on your computer and upload your solution after you have tested thoroughly. Hidden test cases will be conducted after the deadline of the homework submission.

# How to test your code?
To test your code on your local machine, you can either input manually in the terminal or redirect the input into the program.

To redirect the input into your program for testing, you first create a text file named `input.txt` (actually any name would do), type all your input, and save. After that, you can feed the input to your program in the terminal as shown below.

### On Linux/MacOS
```bash
./main < input.txt
# or
cat input.txt | ./main
```

### On Windows (powershell)
```powershell
cat input.txt | ./main
```

# Test cases
You may see different output displayed on your terminal depending on whether you run your program interactively or by redirecting output. If running interactively, you would need to type your input when prompted. On the other hand, if running by redirecting input, you should see the printed statements mushed together.

## Number System Converter

### Test case 1

Input
```
123123123
10
16
```

Output (interactive)
```
Please enter a set of number:
>123123123
Please enter the current number system:
>10
Please enter the number system you want the set of number be converted to:
>16
Output=756B5B3
```

Output (redirected)
```
Please enter a set of number:
>Please enter the current number system:
>Please enter the number system you want the set of number be converted to:
>Output=756B5B3
```

### Test case 2

Input
```
3G
16
```

Output (interactive)
```
Please enter a set of number:
>3G
Please enter the current number system:
>16
Error! That set of number is not a hexadecimal number.
```

Output (redirected)
```
Please enter a set of number:
>Please enter the current number system:
>Error! That set of number is not a hexadecimal number.
```

## Mean, Mode and Median

### Test case 1

Input
```
1
2
4
9
0
2
\
```
Output (interactive)
```
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

Output (redirected)
```
Enter a number to append to the number set. Enter "\" to stop appending.
>>>>>>>Mean=3
Mode=2
Median=2
```

### Test case 2

Input
```
10
10
20
20
30
30
50
50
\
```

Output (interactive)
```
Enter a number to append to the number set. Enter "\" to stop appending.
>10
>10
>20
>20
>30
>30
>50
>50
>\
Mean=27.5
Mode=No mode
Median=25
```

Output (redirected)
```
Enter a number to append to the number set. Enter "\" to stop appending.
>>>>>>>>>Mean=27.5
Mode=No mode
Median=25
```

## Simple Calculator

### Test case 1

Input
```
963
+
254
```

Output (interactive)
```
Input:
>963
>+
>254
Output:
1217
```

Output (redirected)
```
Input:
>>>Output:
1217
```

### Test case 2

Input
```
-2.36
+
4.22
```

Output (interactive)
```
Input:
>-2.36
>+
>4.22
Output:
1.9
```

Output (redirected)
```
Input:
>>>Output:
1.9
```

### Test case 3

Input
```
179
-
233
```

Output (interactive)
```
Input:
>179
>-
>233
Output:
-54
```

Output (redirected)
```
Input:
>>>Output:
-54
```

### Test case 4

Input
```
362
*
663
```

Output (interactive)
```
Input:
>362
>*
>663
Output:
240006
```

Output (redirected)
```
Input:
>>>Output:
240006
```
