#include "shell.h"

/**
 * copy_file - Copies source into destination
 *
 * @source: the source we are copying
 * @destination: the destination we are copying into
 *
 * Return: void
 */
void copy_file(char *source, char *destination) {
	int src_fd, dest_fd;
	char buffer[BUF_SIZE];
	ssize_t bytes_read, bytes_written;

	src_fd = open(source, O_RDONLY);
	if (src_fd == -1)
	{
		perror("open source");
		exit(1);
	}

	if (access(destination, F_OK) != -1)
	{
		fprintf(stderr, "Error: Destination file '%s' already exists\n", destination);
		close(src_fd);
		exit(1);
	}

	dest_fd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (dest_fd == -1)
	{
		perror("open destination");
		close(src_fd);
		exit(1);
	}

	while ((bytes_read = read(src_fd, buffer, BUF_SIZE)) > 0)
	{
		bytes_written = write(dest_fd, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			perror("write");
			close(src_fd);
			close(dest_fd);
			exit(1);
		}
	}

	if (bytes_read == -1)
	{
		perror("read");
	}

	close(src_fd);
	close(dest_fd);
}

/**
 * is_directory - Checks if path is not a file
 *
 * @path: path to check
 *
 * Return: 0 if directory
 */
int is_directory(char *path)
{
	struct stat statbuf;
	if (stat(path, &statbuf) != 0)
	{
		return 0;
	}

	return S_ISDIR(statbuf.st_mode);
}
