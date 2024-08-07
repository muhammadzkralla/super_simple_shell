#include "shell.h"

/**
 * move_file - Moves source into destination
 *
 * @source: the source we are moving
 * @destination: the destination we are moving into
 *
 * Return: void
 */
void move_file(char *source, char *destination)
{
	copy_file(source, destination);

	if (unlink(source) == -1)
	{
		perror("unlink");
		exit(EXIT_FAILURE);
	}
}
