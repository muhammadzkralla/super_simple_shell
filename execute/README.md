<h1 align = "center"> Execute </h1>

## Introduction
This program uses the `execve()` system call to print the output of the `ls -l /usr/` command.

## Compilation
In order to run the program, I ran this command : <br>
```bash
gcc -Wall -Werror -Wextra -pedantic exec.c -o exec.o
```

These flags are used to include more warnings and treat them as errors as well as forcing ISO C.

## Outputs
`./exec.o` <br>
```text
Before execve
total 144
drwxr-xr-x   2 root root 49152 Jul 18 16:59 bin
drwxr-xr-x   2 root root  4096 Aug  9  2022 games
drwxr-xr-x  42 root root 20480 Jun 15 15:15 include
drwxr-xr-x 114 root root  4096 Apr 23 16:30 lib
drwxr-xr-x   2 root root  4096 Aug  9  2022 lib32
drwxr-xr-x   2 root root  4096 Jun 15 15:15 lib64
drwxr-xr-x  23 root root 12288 Jun 15 15:24 libexec
drwxr-xr-x   2 root root  4096 Aug  9  2022 libx32
drwxr-xr-x  10 root root  4096 Aug  9  2022 local
drwxr-xr-x   2 root root 20480 Jul 21 14:40 sbin
drwxr-xr-x 274 root root 12288 Feb 18 20:46 share
drwxr-xr-x  14 root root  4096 Jul 18 17:00 src
```
