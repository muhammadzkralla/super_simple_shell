<h1 align = "center"> Command To Av </h1>

## Introduction
This program prints the arguments passed to the executable when running it separated by new lines WITHOUT USING `argc argv`.

## Compilation
In order to run the program, I ran this command : <br>
```bash
gcc -Wall -Werror -Wextra -pedantic command_to_av.c -o comman_to_av.o
```

These flags are used to include more warnings and treat them as errors as well as forcing ISO C.

## Outputs
`./command_to_av` <br>
```text
Type the string : one two three four five
You typed : one two three four five
word 0: one
word 1: two
word 2: three
word 3: four
word 4: five
```
