#include <stdio.h>
#include <stdlib.h>

extern char **environ;

/**
 * _getenv - Retrieves the value of an environment variable.
 *
 * @name: The name of the environment variable to find.
 *
 * Return: A pointer to the value of the environment variable, or NULL if not found.
 */
char *_getenv(const char *name)
{
	int i, j;
	int status;

	for (i = 0; environ[i] != NULL; i++)
	{
		status = 1;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (name[j] != environ[i][j])
			{
				status = 0;
				break;
			}
		}

		if (status)
		{
			return (&environ[i][j + 1]);
		}
	}

	return (NULL);
}

/**
 * main-prototype
 *
 * Return: Always 0.
 */
int main () {

   printf("\nUsing the getenv funtion\n\n");

   printf("PATH : %s\n", getenv("PATH"));
   printf("HOME : %s\n", getenv("HOME"));
   printf("ROOT : %s\n", getenv("ROOT"));

   printf("\n\n**********************************\n\n");

   printf("\nUsing the _getenv function\n\n");

   printf("PATH : %s\n", _getenv("PATH"));
   printf("HOME : %s\n", _getenv("HOME"));
   printf("ROOT : %s\n", _getenv("ROOT"));


   return(0);
}
