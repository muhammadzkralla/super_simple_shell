#include <stdio.h>
#include <stdlib.h>

/**
 *strcmp-prototype
 *Return: 0 if same string
 */

int strcmp(const char* s1, const char* s2)
{
    while(*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

/**
 *main-prototype
 *Return: 0
 */
int main(void)
{
	char *buffer = malloc(1024);
	size_t len = 1024;

	while (1)
	{
		printf("$ ");
                if (getline(&buffer, &len, stdin) == -1 || strcmp(buffer, "exit\n") == 0)
                {
                        return (0);
                }
                printf("%s", buffer);
	}

	return (0);
}
