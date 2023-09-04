#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: file name
 * @text_content: The string to add to the end of the file.
 *
 * Return: 1 (success), -1 (fail)
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, _write, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_WRONLY | O_APPEND);
	_write = write(fd, text_content, len);

	if (fd == -1 || _write == -1)
		return (-1);

	close(fd);

	return (1);
}
