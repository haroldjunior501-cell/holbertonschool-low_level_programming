#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to POSIX standard output
 * @filename: the name of the file to read
 * @letters: the number of letters to read and print
 *
 * Return: actual number of letters read and printed, 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buf;
	ssize_t r;
	ssize_t w;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}

	r = read(fd, buf, letters);
	close(fd);
	if (r == -1)
	{
		free(buf);
		return (0);
	}

	w = write(STDOUT_FILENO, buf, r);
	free(buf);

	if (w != r)
		return (0);

	return (w);
}
