#ifndef SHELL_H
#define SHELL_H

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
void copy_file(const char *source, const char *destination);
int is_directory(const char *path);

#endif /* SHELL_H */
