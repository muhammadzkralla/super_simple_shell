<h1 align = "center"> Fork </h1>

## Introduction
These two programs illustrate the usage of the fork function. <br><br>

Notice in the first program that the `Before fork` statement is typed once as it was called before we fork the current process and create a child process, after that, each statement is printed twice as it was called once by the parent process, and another time by the child process each one printing its own process id. The first three statements afterh the `Before fork` one are printed by the parent process, and the second three statements are printed by the child process. <br>
Notice that `My pid` represents the parent process id and `pid` represents the child process id. Also notice that the output of the `fork()` is `zero` in the child process. <br><br>

The second program does the same thing like the first one but it highlights that when the output of the `fork()` function is `zero`, then the current process is the child process not the parent one.

## Compilation
In order to run the program, I ran this command : <br>
```bash
gcc -Wall -Werror -Wextra -pedantic fork.c -o fork.o
gcc -Wall -Werror -Wextra -pedantic fork2.c -o fork2.o
```

These flags are used to include more warnings and treat them as errors as well as forcing ISO C.


## Outputs

`./fork.o` <br>
```text
Before fork
After fork
My pid is 5589
pid is 5590
After fork
My pid is 5590
pid is 0
```

`./fork2.o` <br>
```text
My pid is 5614
(5614) 5615, I am your father
My pid is 5615
(5615) Nooooooooo!
```
