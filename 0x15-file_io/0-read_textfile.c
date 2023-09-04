#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints
 * to the POSIX standard output
 * @filename: the file name
 * @letters: number of letters to be read and printed
 * 0 when function fails or filename is NULL
 * Return: actual number of letters or 0 if fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	t = read(fd, buf, letters);
	if (t == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}

	w = write(STDOUT_FILENO, buf, t);
	if (w == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}
	free(buf);
	close(fd);
	return (w);
}
