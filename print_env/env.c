#include <unistd.h>
#include <stdio.h>

extern char **environ;

/**
 * main - prints the environmen with the third parameter of the main function
 * and the global variable environ.
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{

	printf("\nUsing the third parameter : \n\n\n");

	unsigned int i;
	i = 0;

	while (env[i] != NULL)
	{
        	printf("%s\n", env[i]);
        	i++;
	}

	printf("\n\n\n**************************************************************************\n\n\n");

	printf("\nUsing the global variable environ : \n\n\n");

	unsigned int j;
	j = 0;

	while(environ[j])
	{
		printf("%s\n", environ[j++]);
	}
	return (0);

}
