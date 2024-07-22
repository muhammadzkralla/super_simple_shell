<h1 align = "center"> Av </h1>

## Introduction
This program prints the arguments passed to the executable when running it separated by new lines.

## Compilation
In order to run the program, I ran this command : <br>
```bash
gcc -Wall -Werror -Wextra -pedantic av.c -o av.o
```

These flags are used to include more warnings and treat them as errors as well as forcing ISO C.

## Outputs
`./av.o first second third fourth` <br>
```text
first
second
third
fourth
```
