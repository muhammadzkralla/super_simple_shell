<h1 align = "center"> Get Env </h1>

## Introduction
This program prints the values of the environment variables `PATH`, `HOME`, and `ROOT` using the `environ` global variable and comparing them to that of the `getenv()` function._

## Compilation
In order to run the program, I ran this command : <br>
```bash
gcc -Wall -Werror -Wextra -pedantic get_env.c -o get_env.o
```

These flags are used to include more warnings and treat them as errors as well as forcing ISO C.

## Outputs
`./get_env.o` <br>
```text
Using the getenv funtion

PATH : /home/zkrallah/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin
HOME : /home/zkrallah
ROOT : (null)


**********************************


Using the _getenv function

PATH : /home/zkrallah/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin
HOME : /home/zkrallah
ROOT : (null)
```
