#include "shell.h"

/**
 * type - Performs the type command.
 *
 * @command: the entered command
 * @result_path: the result of the search
 * @result_size: the size of the result buffer
 *
 * Return: 0 on success.
 */
int type(char *command, char *result_path, size_t result_size)
{
	char *path_dir = get_path(command);

	if (!path_dir || _strcmp(path_dir, "Error: Not Found") == 0) {
		fprintf(stderr, "Error: %s not found in PATH.\n", command);
		return -1;
	}

	snprintf(result_path, result_size, "%s/%s", path_dir, command);

	return 0;
}
