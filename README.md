<h1 align = "center"> Super Simple Shell </h1>

## Introduction
This is a shell terminal built by me with C lang. The terminal can run all the Linux external commands or system binaries with any number of arguments or flags/options like `ls -l /tmp`, `cat`, `pwd`, `cp`, `mv`, `vim`, `nano`, `emacs`, `grep`...and all the other binaries, as well as some internal and other commands like `cd <path> or cd ..`, `bg <PID>`, phist, and sending a `SIGSTOP` signal to a certain process. I also implemented some of the system binaries that are already supported but on my own way like `zcopy`, `zmove`, `ztype`, `zfree`, `ztype`, `zuptime`, and `zenv`. This shell also supports piping, and input, output, error redirections.<br> 

The C files in this root directory are a collection of all the codes inside the directories in this repository, if you want to understand how this shell works, you can open each directory and understand them one by one, each directory has its own `README.md` file explaining what the code does and showing the sample output. Once you understand each subprogram in the directories, you will be ready to code your own shell like mine!

## Compilation
In order to run the program, I ran this command : <br>
```bash
gcc -Wall -Werror -Wextra -pedantic -std=c99 *.c -o simple_shell
```

These flags are used to include more warnings and treat them as errors as well as forcing ISO C.

## Outputs

Here's some examples of the command you can do with my terminal after runnging it : <br><br>

run `./simple_shell` and test all the external commands or the system binaries with their flags, arguments, and options. <br>

run `./simple_shell` and see my own implementation for some system binaries : <br>
```text
zkrallah$ help
Supported commands :
- All the system binaries and external commands inside the PATH variable.
- Internal commands and other:
    1- cd
    2- bg
    3- stop (SIGSTOP)
    4- phist
- My own implementation of some system binaries :
    1- zcopy
    2- zmove
    3- ztype
    4- zfree
    5- zuptime
    6- zenv
zkrallah$ zuptime
System uptime: 0 day, 6:40:17
Idle time: 9328467 seconds
zkrallah$ zfree
Mem Total: 2005500 kB
Mem Used: 1171996 kB
Mem Free: 214268 kB
Swap Total: 2201596 kB
Swap Used: 271752 kB
Swap Free: 1929844 kB
zkrallah$ ztype ls
ls is /usr/bin/ls
zkrallah$ zcopy pid_max.sh testing       
zkrallah$ cat testing/pid_max.sh
#!/bin/bash
cat /proc/sys/kernel/pid_max
zkrallah$ zcopy pid_max.sh testing/
Error: Destination file 'testing//pid_max.sh' already exists
zkrallah$ zcopy pid_max.sh copied.sh
zkrallah$ cat copied.sh
#!/bin/bash
cat /proc/sys/kernel/pid_max
zkrallah$ zmove copied.sh renamed.sh
zkrallah$ cat renamed.sh
#!/bin/bash
cat /proc/sys/kernel/pid_max
zkrallah$ zmove renamed.sh pid_max.sh
Error: Destination file 'pid_max.sh' already exists
zkrallah$ zmove renamed.sh testing
zkrallah$ cat testing/renamed.sh
#!/bin/bash
cat /proc/sys/kernel/pid_max
zkrallah$ zenv
SHELL=/bin/bash
SESSION_MANAGER=local/zkrallah-VirtualBox:@/tmp/.ICE-unix/1988,unix/zkrallah-VirtualBox:/tmp/.ICE-unix/1988
QT_ACCESSIBILITY=1
COLORTERM=truecolor
...
```

run `./simple_shell` and see bg, and stop commands : <br>
```text
zkrallah$ ps -au
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
zkrallah    1926  0.0  0.2 162396  6016 tty2     Ssl+ 10:58   0:00 /usr/libexec/gd
zkrallah    1929  0.0  0.5 223048 11392 tty2     Sl+  10:58   0:00 /usr/libexec/gn
zkrallah    2796  0.0  0.2  11544  5248 pts/0    Ss   10:58   0:00 bash
zkrallah   12899  0.0  0.2  11544  5504 pts/1    Ss   17:46   0:00 bash
zkrallah   12913  105  0.0   2644   896 pts/1    R+   17:47   0:07 ./run
zkrallah   12915  0.0  0.0   2784  1408 pts/0    S+   17:47   0:00 ./simple_shell
zkrallah   12916  0.0  0.1   7064  2944 pts/0    R+   17:47   0:00 /usr/bin/ps -au
zkrallah$ stop 12913
zkrallah$ ps -au
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
zkrallah    1926  0.0  0.2 162396  6016 tty2     Ssl+ 10:58   0:00 /usr/libexec/gd
zkrallah    1929  0.0  0.5 223048 11392 tty2     Sl+  10:58   0:00 /usr/libexec/gn
zkrallah    2796  0.0  0.2  11544  5248 pts/0    Ss   10:58   0:00 bash
zkrallah   12899  0.0  0.2  11544  5504 pts/1    Ss+  17:46   0:00 bash
zkrallah   12913 92.7  0.0   2644   896 pts/1    T    17:47   0:35 ./run
zkrallah   12915  0.0  0.0   2784  1408 pts/0    S+   17:47   0:00 ./simple_shell
zkrallah   12918  0.0  0.1   7064  2944 pts/0    R+   17:48   0:00 /usr/bin/ps -au
zkrallah$ bg 12913
zkrallah$ ps -au
USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
zkrallah    1926  0.0  0.2 162396  6016 tty2     Ssl+ 10:58   0:00 /usr/libexec/gd
zkrallah    1929  0.0  0.5 223048 11392 tty2     Sl+  10:58   0:00 /usr/libexec/gn
zkrallah    2796  0.0  0.2  11544  5248 pts/0    Ss   10:58   0:00 bash
zkrallah   12899  0.0  0.2  11544  5504 pts/1    Ss+  17:46   0:00 bash
zkrallah   12913 74.6  0.0   2644   896 pts/1    R    17:47   0:41 ./run
zkrallah   12915  0.0  0.0   2784  1408 pts/0    S+   17:47   0:00 ./simple_shell
zkrallah   12921  0.0  0.1   7064  2944 pts/0    R+   17:48   0:00 /usr/bin/ps -au
zkrallah$
```

run `./simple_shell` and see cd, and phist commands : <br>
```text
zkrallah$ help
Supported commands :
- All the system binaries and external commands inside the PATH variable.
- Internal commands and other:
    1- cd
    2- bg
    3- stop (SIGSTOP)
    4- cd
    5- phist
- My own implementation of some system binaries :
    1- zcopy
    2- zmove
    3- ztype
    4- zfree
    5- zuptime
    6- zenv
zkrallah$ phist
Last 10 processes:
12645
12659
12790
12791
12798
12891
12894
12899
12996
12998
zkrallah$ pwd
/home/zkrallah/Desktop/super_simple_shell
zkrallah$ cd testing
zkrallah$ pwd
/home/zkrallah/Desktop/super_simple_shell/testing
zkrallah$ cd lol
Invalid directory.
zkrallah$ cd /
zkrallah$ pwd
/
zkrallah$ cd /home/zkrallah/Desktop/super_simple_shell/fork
zkrallah$ pwd
/home/zkrallah/Desktop/super_simple_shell/fork
zkrallah$ cd /home/zkrallah/Desktop/super_simple_shell/av/
zkrallah$ pwd
/home/zkrallah/Desktop/super_simple_shell/av
zkrallah$ cd ..
zkrallah$ pwd
/home/zkrallah/Desktop/super_simple_shell
zkrallah$
```

run `./simple_shell` and see piping, input, output, and error redirections : <br>
```text
zkrallah$ cat > input.txt
Hello World!
zkrallah$ ls
input.txt
zkrallah$ cat input.txt
Hello World!
zkrallah$ wc < input.txt
 1  2 13
zkrallah$ ls > output.txt
zkrallah$ wc < output.txt
 2  2 21
zkrallah$ ls non_existing_file 2> error.txt
zkrallah$ cat error.txt
/usr/bin/ls: cannot access 'non_existing_file': No such file or directory
zkrallah$ sort < input.txt > sorted_output.txt
zkrallah$ cat sorted_output.txt
Hello World!
zkrallah$ ls
error.txt  input.txt  output.txt  sorted_output.txt
zkrallah$ ls | grep .txt        
error.txt
input.txt
output.txt
sorted_output.txt
zkrallah$ ls | grep .txt | wc -l
4
zkrallah$
```

> **Note:** The sample outputs are not the only supported commands, in fact I can not show examples for all the supported commands as all the external commands or system binaries are supporte i.e any program that has its path in the `PATH` environment variable.
