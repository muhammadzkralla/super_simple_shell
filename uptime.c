#include "shell.h"

/**
 * idle_time - Get the idle time
 *
 * Return: unsigned long
 */
unsigned long idle_time() {
	FILE *file = fopen("/proc/stat", "r");
	if (!file)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	unsigned long user_time, nice_time, system_time, idle, iowait, irq, softirq, steal;

	if (fscanf(file, "cpu %lu %lu %lu %lu %lu %lu %lu %lu",
               		&user_time, &nice_time, &system_time, &idle, &iowait, &irq, &softirq, &steal) != 8)
	{
		perror("fscanf");
		fclose(file);
		exit(EXIT_FAILURE);
	}

	fclose(file);

	return idle;
}

/**
 * zuptime - Get the uptime and the idle time
 *
 * Return: void
 */
void zuptime() {
	struct sysinfo si;
	if (sysinfo(&si) != 0)
	{
		perror("sysinfo");
		exit(EXIT_FAILURE);
	}

	unsigned long uptime_seconds = si.uptime;

	unsigned long idle = idle_time();

	// Convert uptime to days, hours, minutes, and seconds
	unsigned long days = uptime_seconds / (24 * 3600);
	unsigned long hours = (uptime_seconds % (24 * 3600)) / 3600;
	unsigned long minutes = (uptime_seconds % 3600) / 60;
	unsigned long seconds = uptime_seconds % 60;

	printf("System uptime: %lu day, %lu:%02lu:%02lu\n", days, hours, minutes, seconds);
	printf("Idle time: %lu seconds\n", idle);
}
