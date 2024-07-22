#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - exercise: fork + wait + execve
 *
 * Return: Certain command on five different processes.
 */
int main(void)
{
	pid_t child_pid = 1;
	int status;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};


	for (int i = 0; i < 5; i++){
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
	}

	if (child_pid == 0)
	{
		printf("\n\nFATHER ID : %u\n\nCHILD ID : %u\n\n", getppid(), getpid());
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
		}
	}


	return (0);
}
