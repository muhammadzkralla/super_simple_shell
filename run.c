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
