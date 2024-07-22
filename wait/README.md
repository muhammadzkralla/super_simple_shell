<h1 align = "center"> Wait </h1>

## Introduction
Illustrate the usage of the `wait` function that suspends execution of the calling process until one of its children terminates so, in this program the `wait for me` part is printed first as it will never be printed unless called from the child process as we check if the `child_pid` is `zero` or not before we print it and it only happens when we are inside a child process, otherwise, print the `it's all better now` part which will be called from the parent process after waiting for the child process to finish.

## Compilation
In order to run the program, I ran this command : <br>
```bash
gcc -Wall -Werror -Wextra -pedantic wait.c -o wait.o
```

These flags are used to include more warnings and treat them as errors as well as forcing ISO C.

## Outputs

`./wait.o` <br>
```text
Wait for me, wait for me
Oh, it's all better now
```
