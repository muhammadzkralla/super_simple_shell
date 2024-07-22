<h1 align = "center"> Print Env </h1>

## Introduction
This program prints all the environment variables using two methods, the `environ` global variable, and the `char **env` argument.

## Compilation
In order to run the program, I ran this command : <br>
```bash
gcc -Wall -Werror -Wextra -pedantic print_env.c -o print_env.o
```

These flags are used to include more warnings and treat them as errors as well as forcing ISO C.

## Outputs
`./print_env` <br>
```text
Using the third parameter : 


SHELL=/bin/bash
SESSION_MANAGER=local/zkrallah-VirtualBox:@/tmp/.ICE-unix/1948,unix/zkrallah-VirtualBox:/tmp/.ICE-unix/1948
QT_ACCESSIBILITY=1
COLORTERM=truecolor
XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
SSH_AGENT_LAUNCHER=gnome-keyring
XDG_MENU_PREFIX=gnome-
...



**************************************************************************



Using the global variable environ : 


SHELL=/bin/bash
SESSION_MANAGER=local/zkrallah-VirtualBox:@/tmp/.ICE-unix/1948,unix/zkrallah-VirtualBox:/tmp/.ICE-unix/1948
QT_ACCESSIBILITY=1
COLORTERM=truecolor
XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
...
```
