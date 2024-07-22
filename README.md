<hi align = "center"> Super Simple Shell </h1>

## Introduction
This is a shell terminal built by me with C lang. The terminal can run all the Linux external commands or system binaries with any number of arguments or flags/options like `ls -l /tmp`, `cat`, `pwd`, `cp`, `mv`, `vim`, `nano`, `emacs`, `grep`...and all the other binaries, as well as some internal commands like `cd <path> or cd ..`, `bg <PID>`, `env` and sending a `SIGSTOP` signal to a certain process. <br> 

The `simple_shell.c` file is a collection of all the codes inside the directories in this repository, if you want to understand how this file works, you can open each directory and understand them one by one, each directory has its own `README.md` file explaining what the code does and showing the sample output.

## Compilation
In order to run the program, I ran this command : <br>
```bash
gcc -Wall -Werror -Wextra -pedantic simple_shell.c -o simple_shell.o
```

These flags are used to include more warnings and treat them as errors as well as forcing ISO C.

## Outputs

Here's some examples of the command you can do with my terminal after runnging it : <br><br>

`./simple_shell.o` <br>
```text
zkrallah$ ls
README.md  command_to_av  find_command	fork+wait+execve  pid_max.sh  process_id  simple_shell.c  super_simple_shell
av	   execute	  fork		get_env		  print_env   prompt	  simple_shell.o  wait
zkrallah$ ls -l
total 84
-rw-rw-r-- 1 zkrallah zkrallah   756 Jul 22 22:12 README.md
drwxrwxr-x 2 zkrallah zkrallah  4096 Jul 22 18:02 av
drwxrwxr-x 2 zkrallah zkrallah  4096 Jul 22 19:19 command_to_av
drwxrwxr-x 2 zkrallah zkrallah  4096 Jul 22 19:04 execute
drwxrwxr-x 2 zkrallah zkrallah  4096 Jul 22 21:53 find_command
drwxrwxr-x 2 zkrallah zkrallah  4096 Jul 22 17:54 fork
drwxrwxr-x 2 zkrallah zkrallah  4096 Jul 22 18:34 fork+wait+execve
drwxrwxr-x 2 zkrallah zkrallah  4096 Jul 22 19:17 get_env
-rwxrwxr-x 1 zkrallah zkrallah    41 Jul 12  2023 pid_max.sh
drwxrwxr-x 2 zkrallah zkrallah  4096 Jul 22 19:22 print_env
drwxrwxr-x 2 zkrallah zkrallah  4096 Jul 22 19:09 process_id
drwxrwxr-x 2 zkrallah zkrallah  4096 Jul 22 19:16 prompt
-rw-rw-r-- 1 zkrallah zkrallah  6982 Jul 22 22:19 simple_shell.c
-rwxrwxr-x 1 zkrallah zkrallah 17080 Jul 22 22:19 simple_shell.o
drwxrwxr-x 2 zkrallah zkrallah  4096 Jul 22 19:27 super_simple_shell
drwxrwxr-x 2 zkrallah zkrallah  4096 Jul 22 18:26 wait
zkrallah$ ls -a /tmp/
.	     VMwareDnD
..	     snap-private-tmp
.ICE-unix    systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-ModemManager.service-m1Sy8g
.Test-unix   systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-colord.service-a7of5Z
.X0-lock     systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-power-profiles-daemon.service-m9BPcU
.X1-lock     systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-switcheroo-control.service-UWbkCj
.X1024-lock  systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-logind.service-GF4gVX
.X1025-lock  systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-oomd.service-c2p8hQ
.X11-unix    systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-resolved.service-1nNpI4
.XIM-unix    systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-timesyncd.service-31pHPO
.font-unix   systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-upower.service-TklJLy
zkrallah$ cd av
zkrallah$ pwd
/home/zkrallah/Desktop/super_simple_shell/av
zkrallah$ ls
README.md  av.c  av.o
zkrallah$ cp av.c copied_file
zkrallah$ ls
README.md  av.c  av.o  copied_file
zkrallah$ rm -r copied_file
zkrallah$ ls
README.md  av.c  av.o
zkrallah$ cd ..
zkrallah$ ls
README.md  command_to_av  find_command	fork+wait+execve  pid_max.sh  process_id  simple_shell.c  super_simple_shell
av	   execute	  fork		get_env		  print_env   prompt	  simple_shell.o  wait
zkrallah$ mv README.md DONTREADME.md
zkrallah$ ls
DONTREADME.md  command_to_av  find_command  fork+wait+execve  pid_max.sh  process_id  simple_shell.c  super_simple_shell
av	       execute	      fork	    get_env	      print_env   prompt      simple_shell.o  wait
zkrallah$ mv DONTREADME.md README.md
zkrallah$ ls
README.md  command_to_av  find_command	fork+wait+execve  pid_max.sh  process_id  simple_shell.c  super_simple_shell
av	   execute	  fork		get_env		  print_env   prompt	  simple_shell.o  wait
zkrallah$ exit
```

`./simple_shell.0` <br>
```text
zkrallah$ ps -au
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
zkrallah    1881  0.0  0.2 162396  6016 tty2     Ssl+ 15:07   0:00 /usr/libexec/gd
zkrallah    1893  0.0  0.7 223048 14464 tty2     Sl+  15:07   0:00 /usr/libexec/gn
zkrallah    5239  0.0  0.3  12612  6656 pts/0    Ss   17:20   0:00 bash
zkrallah    5465  0.0  0.3  12612  6784 pts/1    Ss   17:41   0:00 bash
zkrallah    8349  104  0.0   2644   896 pts/1    R+   22:22   0:05 ./run
zkrallah    8350  0.0  0.0   2776  1280 pts/0    S+   22:22   0:00 ./simple_shell.
zkrallah    8351  0.0  0.1   7064  2944 pts/0    R+   22:23   0:00 /usr/bin/ps -au
zkrallah$ stop 8349
zkrallah$ ps -au
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
zkrallah    1881  0.0  0.2 162396  6016 tty2     Ssl+ 15:07   0:00 /usr/libexec/gd
zkrallah    1893  0.0  0.7 223048 14464 tty2     Sl+  15:07   0:00 /usr/libexec/gn
zkrallah    5239  0.0  0.3  12612  6656 pts/0    Ss   17:20   0:00 bash
zkrallah    5465  0.0  0.3  12612  6784 pts/1    Ss+  17:41   0:00 bash
zkrallah    8349 89.3  0.0   2644   896 pts/1    T    22:22   0:16 ./run
zkrallah    8350  0.0  0.0   2776  1280 pts/0    S+   22:22   0:00 ./simple_shell.
zkrallah    8353  0.0  0.1   7064  2944 pts/0    R+   22:23   0:00 /usr/bin/ps -au
zkrallah$ bg 8349
zkrallah$ ps -au
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
zkrallah    1881  0.0  0.2 162396  6016 tty2     Ssl+ 15:07   0:00 /usr/libexec/gd
zkrallah    1893  0.0  0.7 223048 14464 tty2     Sl+  15:07   0:00 /usr/libexec/gn
zkrallah    5239  0.0  0.3  12612  6656 pts/0    Ss   17:20   0:00 bash
zkrallah    5465  0.0  0.3  12612  6784 pts/1    Ss+  17:41   0:00 bash
zkrallah    8349 60.6  0.0   2644   896 pts/1    R    22:22   0:20 ./run
zkrallah    8350  0.0  0.0   2776  1280 pts/0    S+   22:22   0:00 ./simple_shell.
zkrallah    8355  0.0  0.1   7064  2944 pts/0    R+   22:23   0:00 /usr/bin/ps -au
zkrallah$ exit
```

> **Note:** The sample outputs are not the only supported commands, in fact I can not show examples for all the supported commands as all the external commands or system binaries are supported, in order to see all the supported commands, you can open the `/usr/bin/` directory to see all the supported commands as well as some internal commands that you will not find in the directory.
