<h1 align = "center"> Find Command </h1>

## Introduction
This program finds the path of the passed command, for example the path of the `ls` command is `usr/bin/ls`. <br>
Feel free to change the `ls` command and search for any other one, or modify the file to accept the command as `argc argv`.

## Compilation
In order to run the program, I ran this command : <br>
```bash
gcc -Wall -Werror -Wextra -pedantic find_command.c -o find_command.o
```

These flags are used to include more warnings and treat them as errors as well as forcing ISO C.

## Outputs
`./find_command.o` <br>
```text
Path to "ls" command : /usr/bin
```
