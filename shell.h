#ifndef SHELL_H
#define SHELL_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <signal.h>
#include <libgen.h>
#include <fcntl.h>
#include <sys/sysinfo.h>
#include <ctype.h>

#define BUF_SIZE 1024

extern char **environ;

/* String utilities */
int _strcmp(const char *s1, const char *s2);
int _strlen(char str[]);
char *_strcpy(char *str);
char **str_split(char *str, int *number_of_words);
char *str_concat(char *s1, char *s2);
int _str_cmp_four_char(char *s1, char *s2);

/* Path utilities */
char *get_path(char *command);

/* Command runner */
void run(char **line);

/* Copy file */
void copy_file(char *source, char *destination);
int is_directory(char *path);

/* move file */
void move_file(char *source, char *destination);

/* type file */
int type(char *command, char *result_path, size_t result_size);

/* free file */
void zfree();

/* uptime file */
unsigned long idle_time();
void zuptime();

/* phist file */
int is_valid(char *str);
void phist();

#endif /* SHELL_H */
