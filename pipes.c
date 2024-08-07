#include "shell.h"

/**
 * run_with_pipes - Handles commands with pipes
 *
 * @cmds: the list of strings (commands) to be piped
 * @num_cmds: the number of commands
 *
 * Return: void
 */
void run_with_pipes(char ***cmds, int num_cmds)
{
	// allocate fds for pipes and use one i for all loops for efficiency
	int pipefds[2 * (num_cmds - 1)];
	pid_t pid;
	int i;

	// Create pipes
	for (i = 0; i < num_cmds - 1; i++)
	{
		if (pipe(pipefds + i * 2) < 0)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
	}

	for (i = 0; i < num_cmds; i++)
	{
		pid = fork();

		if (pid == 0)
		{
			// Redirect input from previous command's pipe
			if (i != 0)
			{
				if (dup2(pipefds[(i - 1) * 2], 0) < 0)
				{
					perror("dup2 input");
					exit(EXIT_FAILURE);
				}
			}

			// Redirect output to next command's pipe
			if (i != num_cmds - 1)
			{
				if (dup2(pipefds[i * 2 + 1], 1) < 0)
				{
					perror("dup2 output");
					exit(EXIT_FAILURE);
				}
			}

			// Close all pipe file descriptors
			for (int j = 0; j < 2 * (num_cmds - 1); j++)
			{
				close(pipefds[j]);
			}

			// Execute command
			run(cmds[i]);
		}
	}

	// Close all pipe file descriptors in parent
	for (i = 0; i < 2 * (num_cmds - 1); i++)
	{
		close(pipefds[i]);
	}

	// Wait for all children
	for (i = 0; i < num_cmds; i++)
	{
		wait(NULL);
	}
}
