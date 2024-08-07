#include "shell.h"


/**
 * id_valid - Detects whether the string is a valid PID or not
 *
 * @str: the dir name
 *
 * Return: 0 if valid
 */
int is_valid(char *str) {
	while(*str)
	{
		if (!isdigit(*str))
		{
			return -1;
		}

		str++;
	}

	return 0;
}
/**
 * phist - Prints the last 10 processed from proc dir
 *
 * Return: void
 */
void phist()
{
	struct dirent *entry;
	DIR *proc = opendir("/proc");
	if (proc == NULL)
	{
		perror("opendir");
		exit(EXIT_FAILURE);
	}

	int pids[BUF_SIZE];
	int count = 0;

	while ((entry = readdir(proc)) != NULL)
	{
		if (is_valid(entry->d_name) == 0 && count < BUF_SIZE)
		{
			pids[count++] = atoi(entry->d_name);
		}
	}

	closedir(proc);

	// bubble sort because C things :)
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (pids[i] > pids[j])
			{
				int temp = pids[i];
				pids[i] = pids[j];
				pids[j] = temp;
			}
		}
	}

	printf("Last 10 processes:\n");
	int start = count > 10 ? count - 10 : 0;
	for (int i = start; i < count; i++)
	{
		printf("%d\n", pids[i]);
	}
}
