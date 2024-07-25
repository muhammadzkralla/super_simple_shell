#include "shell.h"

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
