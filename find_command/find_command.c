#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

extern char **environ;

/**
 * _strcmpdir - compares strings to find dir.
 *
 * @s1: string.
 * @s2: string.
 *
 * Return: if match and any other number if otherwise.
 **/
int _strcmpdir(char *s1, char *s2)
{
	int i = 0;

	for (; (*s2 != '\0' && *s1 != '\0') && *s1 == *s2; s1++)
	{
		if (i == 3)
			break;
		i++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
 * find_command - finds command to execute in path routes.
 *
 * @command: first position of getline input.
 *
 * Return: string of folder for command to be executed.
 **/
char *find_command(char *command)
{
	DIR *folder;
	struct dirent *entry;
	char *cmd, comp, **str  = malloc(sizeof(char) * 1024);
	char **split = malloc(sizeof(char) * 1024);
	int i;

	while (*environ != NULL)
	{
		if (!(_strcmpdir(*environ, "PATH")))
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
					cmd = entry->d_name;
					comp = _strcmpdir(cmd, command);
					if (comp == 0)
					{
						return (*split);
					}
					if (cmd == NULL)
					{
						perror("Error");
					}
				}
			}
		}
		environ++;
	}
	return ("Error: Not Found");
}

/**
 * main - prints the environmen with the third parameter of the main function
 * and the global variable environ.
 *
 * Return: Always 0.
 */
int main()
{
	char *command = find_command("ls");
	printf("\n\n\nPath to \"ls\" command : %s\n\n\n", command); 
	return (0);
}
