#include "shell.h"

/**
 * main-prototype
 *
 * Return: Always 0
 */
int main(void)
{
	char *buffer = malloc(BUF_SIZE);
	size_t len = BUF_SIZE;

	while (1)
	{
		printf("zkrallah$ ");
		if (getline(&buffer, &len, stdin) == -1)
		{
			exit(98);
		}

		if (_strlen(buffer) == 1 && buffer[0] == '\n')
		{
			continue;
		}
		else if (_strcmp(buffer, "exit\n") == 0)
		{
			exit(0);
		}
		else if (_strcmp(buffer, "env\n") == 0)
		{
			unsigned int j;
			j = 0;

			while(environ[j])
			{
				printf("%s\n", environ[j++]);
			}

			continue;
		}

		int nwords = 0;
		char **arr = str_split (buffer, &nwords);
		char *argv[nwords + 1];
		for (int i = 0; i < nwords; i++)
		{
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
			if (_strcmp(argv[0], "cd") == 0)
			{
				if (chdir(argv[1]) != 0)
				{
					perror("chdir failed");
				}

				exit(0);
			}
			else if (_strcmp(argv[0], "stop") == 0)
			{
				if (kill(atoi(argv[1]), SIGSTOP) == -1)
				{
					perror("Error sending SIGSTOP");
				}

				exit(0);
			}
			else if (_strcmp(argv[0], "bg") == 0)
			{
				if (kill(atoi(argv[1]), SIGCONT) == -1)
				{
					perror("Error sendinf SIGCONT");
				}

				exit(0);
			}
			else if (_strcmp(argv[0], "zcopy") == 0)
			{
				char *target_path = _strcpy(argv[2]);
				if (is_directory(target_path))
				{
					char *slash = str_concat(target_path, "/");
					char *full_path = str_concat(slash, argv[1]);
					target_path = _strcpy(full_path);
				}

				copy_file(argv[1], target_path);
				exit(0);
			}
			else if (_strcmp(argv[0], "zmove") == 0)
			{
				char *target_path = _strcpy(argv[2]);
				if (is_directory(target_path))
				{
					char *slash = str_concat(target_path, "/");
					char *full_path = str_concat(slash, argv[1]);
					target_path = _strcpy(full_path);
				}

				move_file(argv[1], target_path);
				exit(0);
			}
			else if (_strcmp(argv[0], "ztype") == 0)
			{
				if (nwords != 2)
				{
					fprintf(stderr, "Usage: %s command\n", argv[0]);
				}
				else
				{
					char result_path[BUF_SIZE];
					int found = type(argv[1], result_path, BUF_SIZE);

					if (found == 0)
					{
						printf("%s is %s\n", argv[1], result_path);
					}
					else
					{
						printf("%s not found\n", argv[1]);
					}
				}

				exit(0);
			}
			else if (_strcmp(argv[0], "zfree") == 0)
			{
				if (nwords != 1)
				{
					fprintf(stderr, "Usage: %s\n", argv[0]);
				}
				else
				{
					zfree();
				}

				exit(0);
			}
			else if (_strcmp(argv[0], "zuptime") == 0)
			{
				if (nwords != 1)
				{
					fprintf(stderr, "Usage: %s\n", argv[0]);
				}
				else
				{
					zuptime();
				}

				exit(0);
			}
			else if (_strcmp(argv[0], "help") == 0)
			{
				printf("Supported commands :\n");
				printf("- All the system binaries and external commands inside the PATH variable.\n");
				printf("- Internal commands and other:\n");
				printf("    1- cd\n");
				printf("    2- bg\n");
				printf("    3- stop (SIGSTOP)\n");
				printf("    4- cd\n");
				printf("    5- phist\n");
				printf("- My own implementation of some system binaries :\n");
				printf("    1- zcopy\n");
				printf("    2- zmove\n");
				printf("    3- zuptime\n");
				printf("    4- zfree\n");
				printf("    5- zuptime\n");

				exit(0);
			}
			else if (_strcmp(argv[0], "phist") == 0)
			{
				if (nwords != 1)
				{
					fprintf(stderr, "Usage: %s\n", argv[0]);
				}
				else
				{
					phist();
				}

				exit(0);
			}
			else
			{
				run(argv);
			}
		}

 	}

    return (0);
}
