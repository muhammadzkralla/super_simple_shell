#include "shell.h"

/**
 * run - Executes the passed command
 *
 * @line: the command passed by the user
 *
 * Return: void
 */
void run(char **line)
{
	int in_redirect = 0, out_redirect = 0, err_redirect = 0;
	char *input_file = NULL, *output_file = NULL, *error_file = NULL;
	char **args = line;
	char *arg;
	int fd;

	for (int i = 0; args[i] != NULL; i++)
	{
		arg = args[i];
		if (strcmp(arg, "<") == 0)
		{
			in_redirect = 1;
			input_file = args[i + 1];
			args[i] = NULL;
		}
		else if (strcmp(arg, ">") == 0)
		{
			out_redirect = 1;
			output_file = args[i + 1];
			args[i] = NULL;
		}
		else if (strcmp(arg, "2>") == 0)
		{
			err_redirect = 1;
			error_file = args[i + 1];
			args[i] = NULL;
		}
	}

	if (in_redirect)
	{
		fd = open(input_file, O_RDONLY);
		if (fd == -1)
		{
			perror("Failed to open input file");
			exit(EXIT_FAILURE);
		}

		dup2(fd, STDIN_FILENO);
		close(fd);
	}

	if (out_redirect)
	{
		fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
		if (fd == -1)
		{
			perror("Failed to open output file");
			exit(EXIT_FAILURE);
		}

		dup2(fd, STDOUT_FILENO);
		close(fd);
	}

	if (err_redirect)
	{
		fd = open(error_file, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
		if (fd == -1)
		{
			perror("Failed to open error file");
			exit(EXIT_FAILURE);
		}

		dup2(fd, STDERR_FILENO);
		close(fd);
	}

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
