#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <signal.h>

extern char **environ;

/**
 * _strcmp - Compares two strings
 *
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 *
 * Return: 0 if same string
 */
int _strcmp(const char* s1, const char* s2)
{
    while(*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

/**
 * _strlen - Calculates the length of a given string
 *
 * @str: string to calculate the length of
 *
 * Return: String length
 */
int _strlen(char str[]) {
    int count;

    for (count = 0; str[count] != '\0'; ++count);

    return count;
}

/**
  * _strcpy - Copies the passed string
  *
  * @str: pointer to string being duplicated
  *
  * Return: duplicated string or NULL
  */
char *_strcpy(char *str)
{
    if (str == NULL)
    {
        return (NULL);
    }

    char *new_str;
    int sz = _strlen(str);

    new_str = malloc(sizeof(char) * (sz + 1));
    if (new_str == NULL)
    {
        return (NULL);
    }

    for (int i = 0; i < sz; i++)
    {
        new_str[i] = str[i];
    }
    new_str[sz] = '\0';
    return (new_str);

}

/**
 * str_split - Splits the string passed to array of string
 *
 * @str: The string to be split
 *
 * Return: Array of string or NULL
 */
char **str_split(char *str, int *number_of_words)
{
    char *piece, **str_arr = NULL, *str_cpy = NULL;
    int i = 0;

    if (str == NULL)
    {
        return (NULL);
    }
    str_cpy = _strcpy(str);
    piece = strtok(str_cpy, " ");
    while (piece != NULL)
    {
        if ((*piece) == '\n')
        {
            piece = strtok(NULL, " ");
            continue;
        }
        (*number_of_words)++;
        piece = strtok(NULL, " ");
    }

    str_arr = (char **) malloc(sizeof(char *) * (*number_of_words));
    piece = strtok(str, " ");
    for (i = 0; piece != NULL; i++)
    {
        if ((*piece) == '\n')
        {
            piece = strtok(NULL, " ");
            continue;
        }
        str_arr[i] = (char *) malloc(sizeof(char) * (_strlen(piece) + 1));
        str_arr[i] = _strcpy(piece);
        piece = strtok(NULL, " ");
    }

    if (str_cpy)
        free (str_cpy);

    return (str_arr);
}

/**
 * str_concat - concatenate strings
 *
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 *
 * Return: strings
 */
char *str_concat(char *s1, char *s2)
{
    if (s1 == NULL)
        s1 = "";

    if (s2 == NULL)
        s2 = "";

    char *s;
    int len1, len2, i, j, k;


    len1 = _strlen(s1);
    len2 = _strlen(s2);

    s = malloc(((len1) + (len2) + 1) * sizeof(char));

    if (s == NULL)
        return (NULL);

    for (j = 0; j < len1; j++)
    {
        s[j] = s1[j];
    }

    for (i = len1, k = 0; k <= len2; i++, k++)
    {
        s[i] = s2[k];
    }
    return (s);
}

/**
 * _str_cmp_four_char - compares first four chars of string
 *
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 *
 * Return: if match and any other number if otherwise
 **/
int _str_cmp_four_char(char *s1, char *s2)
{
    int i, size1, size2, size;
    size1 = _strlen(s1);
    size2 = _strlen(s2);

    if(size1 < size2)
    {
        size = size1;
    }
    else
    {
        size = size2;
    }

    for (i = 0; i < size && *s1 == *s2; s1++)
    {
        if (i == 3)
            break;
        i++;
        s2++;
    }

    return (*s1 - *s2);
}

/**
 * get_path - finds the path of the command passed
 *
 * @command: user input
 *
 * Return: the path of the command passed
 **/
char *get_path(char *command)
{
    DIR *folder;
    struct dirent *entry;
    char *cmd, comp, **str  = malloc(sizeof(char) * 1024);
    char **split = malloc(sizeof(char) * 1024);
    int i;

    while (*environ != NULL)
    {
        if (!(_str_cmp_four_char(*environ, "PATH")))
        {
            *str = *environ;
            for (i = 0; i < 9; i++, split++, str++)
            {
                *split = strtok(*str, ":='PATH'");
                folder = opendir(*split);
                if (folder == NULL)
                {
                    perror("Unable to read directory");
                }
                while ((entry = readdir(folder)))
                {
                    cmd = entry -> d_name;
                    if (cmd == NULL)
                    {
                        perror("Error: cmd null");
                    }

                    comp = _str_cmp_four_char(cmd, command);
                    if (comp == 0)
                    {
                        return (*split);
                    }
                }
            }
        }
        environ++;
    }
    return ("Error: Not Found");
}

/**
 * run - Executes the passed command
 *
 * @line: the command passed by the user
 *
 * Return: void
 */

void run(char **line)
{

    if ((access(line[0], F_OK) == 0))
    {

        if (execve(line[0], line, NULL) == -1)
        {
            perror("PERMISSION OK AND ERROR");
            exit(0);
        }
    }
    else
    {
        char *full_path, *path, *slash;

        path = get_path(*line);
        slash = str_concat(path, "/");
        full_path = str_concat(slash, *line);

        line[0] = full_path;
        
        if (execve(line[0], line, NULL) == -1)
        {
            perror("PERMISSION DENIED AND ERROR");
	    exit(0);
        }
    }
}

/**
 * main-prototype
 *
 * Return: Always 0
 */
int main(void)
{
	char *buffer = malloc(1024);
	size_t len = 1024;

	while (1)
	{
		printf("zkrallah$ ");
		if (getline(&buffer, &len, stdin) == -1)
		{
			exit(98);
		}

		if (_strlen(buffer) == 1 && buffer[0] == '\n')
		{
			continue;
		}
		else if (_strcmp(buffer, "exit\n") == 0)
		{
			exit(0);
		}
		else if (_strcmp(buffer, "env\n") == 0)
		{
			unsigned int j;
			j = 0;

			while(environ[j])
			{
				printf("%s\n", environ[j++]);
			}

			continue;
		}

		int nwords = 0;
		char **arr = str_split (buffer, &nwords);
		char *argv[nwords + 1];
		for (int i = 0; i < nwords; i++)
		{
			if (arr[i][_strlen(arr[i]) - 1] == '\n')
			{
				arr[i][_strlen(arr[i]) - 1] = '\0';
			}

			argv[i] = arr[i];
		}

		argv[nwords] = NULL;

		pid_t child_pid = 1;
		int status;

		if (child_pid != 0)
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				printf("error");
				return (1);
			}

			wait(&status);
		}

		if (child_pid == 0)
		{
			if (_strcmp(argv[0], "cd") == 0)
			{
				if (chdir(argv[1]) != 0)
				{
					perror("chdir failed");
					exit(0);
				}

			}
			else if (_strcmp(argv[0], "stop") == 0)
			{
				if (kill(atoi(argv[1]), SIGSTOP) == -1)
				{
					perror("Error sending SIGSTOP");
				}

				exit(0);
			}
			else if (_strcmp(argv[0], "bg") == 0)
			{
				if (kill(atoi(argv[1]), SIGCONT) == -1)
				{
					perror("Error sendinf SIGCONT");
				}

				exit(0);
			}
			else
			{
				run(argv);
			}
		}

 	}

    return (0);
}
