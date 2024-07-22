<h1 align = "center"> Fork + Wait + Execve </h1>

## Introduction
This program executes the command `ls -l /tmp` from five different child processes, all created from the same parent process using `fork()`, `wait()`, and `execve()` system calls.

## Compilation
In order to run the program, I ran this command : <br>
```bash
gcc -Wall -Werror -Wextra -pedantic demo.c -o demo.o
```

These flags are used to include more warnings and treat them as errors as well as forcing ISO C.

## Outputs
`./demo.o` <br>
```text
FATHER ID : 5966

CHILD ID : 5967

total 44
drwxrwxrwt 2 root root 4096 Jul 21 14:40 VMwareDnD
drwx------ 4 root root 4096 Jul 21 14:40 snap-private-tmp
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-ModemManager.service-m1Sy8g
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-colord.service-a7of5Z
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-power-profiles-daemon.service-m9BPcU
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-switcheroo-control.service-UWbkCj
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-logind.service-GF4gVX
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-oomd.service-c2p8hQ
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-resolved.service-1nNpI4
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-timesyncd.service-31pHPO
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-upower.service-TklJLy


FATHER ID : 5966

CHILD ID : 5968

total 44
drwxrwxrwt 2 root root 4096 Jul 21 14:40 VMwareDnD
drwx------ 4 root root 4096 Jul 21 14:40 snap-private-tmp
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-ModemManager.service-m1Sy8g
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-colord.service-a7of5Z
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-power-profiles-daemon.service-m9BPcU
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-switcheroo-control.service-UWbkCj
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-logind.service-GF4gVX
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-oomd.service-c2p8hQ
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-resolved.service-1nNpI4
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-timesyncd.service-31pHPO
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-upower.service-TklJLy


FATHER ID : 5966

CHILD ID : 5969

total 44
drwxrwxrwt 2 root root 4096 Jul 21 14:40 VMwareDnD
drwx------ 4 root root 4096 Jul 21 14:40 snap-private-tmp
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-ModemManager.service-m1Sy8g
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-colord.service-a7of5Z
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-power-profiles-daemon.service-m9BPcU
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-switcheroo-control.service-UWbkCj
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-logind.service-GF4gVX
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-oomd.service-c2p8hQ
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-resolved.service-1nNpI4
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-timesyncd.service-31pHPO
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-upower.service-TklJLy


FATHER ID : 5966

CHILD ID : 5970

total 44
drwxrwxrwt 2 root root 4096 Jul 21 14:40 VMwareDnD
drwx------ 4 root root 4096 Jul 21 14:40 snap-private-tmp
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-ModemManager.service-m1Sy8g
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-colord.service-a7of5Z
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-power-profiles-daemon.service-m9BPcU
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-switcheroo-control.service-UWbkCj
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-logind.service-GF4gVX
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-oomd.service-c2p8hQ
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-resolved.service-1nNpI4
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-timesyncd.service-31pHPO
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-upower.service-TklJLy


FATHER ID : 5966

CHILD ID : 5971

total 44
drwxrwxrwt 2 root root 4096 Jul 21 14:40 VMwareDnD
drwx------ 4 root root 4096 Jul 21 14:40 snap-private-tmp
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-ModemManager.service-m1Sy8g
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-colord.service-a7of5Z
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-power-profiles-daemon.service-m9BPcU
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-switcheroo-control.service-UWbkCj
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-logind.service-GF4gVX
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-oomd.service-c2p8hQ
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-resolved.service-1nNpI4
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-systemd-timesyncd.service-31pHPO
drwx------ 3 root root 4096 Jul 21 14:40 systemd-private-049da1ffae2e46e2aa32434d9dcb39ec-upower.service-TklJLy
```
