<h1 align = "center"> Process ID </h1>

## Introduction
The first program prints the current process ID of the program while the second one prints the parent process ID of the program using `getpid()` and the `getppid()` system calls.

## Compilation
In order to run the program, I ran this command : <br>
```bash
gcc -Wall -Werror -Wextra -pedantic pid.c -o pid.o
gcc -Wall -Werror -Wextra -pedantic ppid.c -o ppid.o
```

These flags are used to include more warnings and treat them as errors as well as forcing ISO C.

## Outputs
`./pid.o` <br>
```text
6992
```

`./ppid.o` <br>
```text
5465
```
