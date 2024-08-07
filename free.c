#include "shell.h"

/**
 * zfree - Prints memory data
 *
 * Return: void
 */
void zfree() {
	FILE *file = fopen("/proc/meminfo", "r");
	if (file == NULL) {
		perror("Could not open /proc/meminfo");
		exit(EXIT_FAILURE);
	}

	char line[256];
	long total_mem = 0, free_mem = 0, used_mem = 0;
	long total_swap = 0, free_swap = 0, used_swap = 0;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		if (strncmp(line, "MemTotal:", 9) == 0)
		{
			sscanf(line, "MemTotal: %ld kB", &total_mem);
		}
		else if (strncmp(line, "MemFree:", 8) == 0)
		{
			sscanf(line, "MemFree: %ld kB", &free_mem);
		}
		else if (strncmp(line, "Buffers:", 8) == 0)
		{
			long buffers;
			sscanf(line, "Buffers: %ld kB", &buffers);
			used_mem = total_mem - free_mem - buffers;
		}
		else if (strncmp(line, "Cached:", 7) == 0)
		{
			long cached;
			sscanf(line, "Cached: %ld kB", &cached);
			used_mem = total_mem - free_mem - cached;
		}
		else if (strncmp(line, "SwapTotal:", 10) == 0) {
			sscanf(line, "SwapTotal: %ld kB", &total_swap);
		}
		else if (strncmp(line, "SwapFree:", 9) == 0)
		{
			sscanf(line, "SwapFree: %ld kB", &free_swap);
			used_swap = total_swap - free_swap;
		}
	}

	fclose(file);

	printf("Mem Total: %ld kB\n", total_mem);
	printf("Mem Used: %ld kB\n", used_mem);
	printf("Mem Free: %ld kB\n", free_mem);
	printf("Swap Total: %ld kB\n", total_swap);
	printf("Swap Used: %ld kB\n", used_swap);
	printf("Swap Free: %ld kB\n", free_swap);
}
