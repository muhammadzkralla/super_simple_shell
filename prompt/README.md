<h1 align = "center"> Prompt </h1>

## Introduction
This program waits for the user to enter any prompt and type it back on the terminal unless the user types `exit`, it terminates the program.

## Compilation
In order to run the program, I ran this command : <br>
```bash
gcc -Wall -Werror -Wextra -pedantic get_line.c -o get_line.o
```

These flags are used to include more warnings and treat them as errors as well as forcing ISO C.

## Outputs
`./get_line.o` <br>
```text
$ prompt1
prompt1
$ prompt2
prompt2
$ prompt3
prompt3
$ prompt4 -l -a arg
prompt4 -l -a arg
$ exit
```
