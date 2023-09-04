#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 1024

/**
 * _close - closes file descriptor and print error if it fails
 * @fd: file descriptor to be closed
 *
 * Return: 0 (success),or -1 (fails)
 */
int _close(int fd)
{
	if (!close(fd))
		return (0);
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	return (-1);

}

/**
 * _read - read and print an error message if it fails
 * @filename: name of the file to be read.
 * @fd: file descriptor to read.
 * @buf: the buffer
 * @count: number of bytes
 *
 * Return: number of bytes, or -1 (fails)
 */
ssize_t _read(const char *filename, int fd, char *buf, size_t count)
{
	ssize_t bytes_read = read(fd, buf, count);

	if (bytes_read > -1)
		return (bytes_read);
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
	return (-1);
}

/**
 * _write - write on a file and prints error message if it fails
 * @filename: name of the file
 * @fd: the file descriptor
 * @buf: the buffer
 * @count: number of bytes
 *
 * Return: number of bytes,or -1 (fails)
 */
ssize_t _write(const char *filename, int fd, const char *buf, size_t count)
{
	ssize_t bytes_written = write(fd, buf, count);

	if (bytes_written > -1)
		return (bytes_written);
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
	return (-1);
}

/**
 * main - copies a files contents to another file
 * @argc: the argument count
 * @argv: the argument values
 *
 * Return: Always 1
 */
int main(int argc, const char *argv[])
{
	int from, to;
	ssize_t bytes_read;
	char buffer[BUFSIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	from = open(argv[1], O_RDONLY);
	if (from < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (to < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		_close(from);
		exit(99);
	}
	while ((bytes_read = _read(argv[1], from, buffer, BUFSIZE)))
	{
		if (bytes_read < 0)
		{
			_close(from);
			_close(to);
			exit(98);
		}
		if (_write(argv[2], to, buffer, bytes_read) < 0)
		{
			_close(from);
			_close(to);
			exit(99);
		}
	}
	if ((_close(from) | _close(to)) < 0)
		exit(100);
	return (0);
}
