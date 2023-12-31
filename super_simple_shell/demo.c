#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


/**
 * strcmp-prototype
 * Return: 0 if same string
 */
int _strcmp(const char* s1, const char* s2)
{
    while(*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

/**
 * str_length - Calculates the total string length
 * Return: String length
 */
int _strlen(char str[]) {
    int count;

    for (count = 0; str[count] != '\0'; ++count);

    return count;
}

/**
  *_strdup - returns a pointer to a newly alloctaed
  *space in memory which contains a copy of the string
  *passed.
  *@str: pointer to string being duplicated.
  *
  *Return: NULL if str is NULL.
  *pointer to duplicated string on success.
  *NULL if memory was insufficient.
  */
char *_strdup(char *str)
{
	char *nstr;
	unsigned int len, i;

	/* check is str is null */
	if (str == NULL)
	{
		return (NULL);
	}

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}

	nstr = malloc(sizeof(char) * (len + 1));

	/*check if malloc was successful*/
	if (nstr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		nstr[i] = str[i];
	}
	nstr[len] = '\0';
	return (nstr);

}

/**
 * str_split - Splits a string
 * @str: The string that will be splited
 *
 * Return: On success, it returns the new array
 * of strings. On failure, it returns NULL
 */
char **str_split(char *str, int *number_of_words)
{
    char *piece, **str_arr = NULL, *str_cpy = NULL;
    int i = 0;

    if (str == NULL)
    {
        return (NULL);
    }
    str_cpy = _strdup (str);
    piece = strtok(str_cpy, " ");
    while (piece != NULL)
    {
        if ((*piece) == '\n')
        {
            piece = strtok(NULL, " ");
            continue;
        }
        (*number_of_words)++;
        piece = strtok(NULL, " ");
    }

    str_arr = (char **)malloc(sizeof(char *) * (*number_of_words));
    piece = strtok(str, " ");
    for (i = 0; piece != NULL; i++)
    {
        if ((*piece) == '\n')
        {
            piece = strtok(NULL, " ");
            continue;
        }
        str_arr[i] = (char *)malloc(sizeof(char) * (_strlen(piece) + 1));
        str_arr[i] = _strdup(piece);
        piece = strtok(NULL, " ");
    }

    if (str_cpy)
        free (str_cpy);

    return (str_arr);
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
		printf("zkrallah$ ");
                if (getline(&buffer, &len, stdin) == -1)
                {
                        return (0);
                }

		if (_strlen(buffer) == 1 && buffer[0] == '\n')
		{
			continue;
		}

                int nwords = 0;
                char **arr = str_split (buffer, &nwords);
                char *argv[nwords + 1];
                for (int i = 0; i < nwords; i++){
                    if (arr[i][_strlen(arr[i]) - 1] == '\n')
                    {
                        arr[i][_strlen(arr[i]) - 1] = '\0';
                    }
                    argv[i] = arr[i];
                }
                argv[nwords] = NULL;

                pid_t child_pid = 1;
                int status;

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

                if (child_pid == 0)
                {
                    if (execve(argv[0], argv, NULL) == -1)
                    {
                        perror("Error");
                    }
                }



    }

	return (0);
}
