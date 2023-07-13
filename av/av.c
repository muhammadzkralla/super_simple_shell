#include <stdio.h>
#include <stdlib.h>
/**
 *main-prototype
 *@ac:argument 1
 *@av:argument 2
 *Return: 0
 */
#include <stdio.h>

int main(__attribute__((unused))int ac, char **av)
{
    int i;
    
    for (i = 1; av[i] != NULL; i++)
    {
        printf("%s\n", av[i]);
    }
    return (0);
}

