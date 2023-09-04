#include "main.h"

/**
 * create_file -  function that creates a file
 * @filename: name of the file that should be created
 * @text_content: a NULL terminated string to write to the file
 *
 * Return: 1 (success), or -1 (fail)
 */

int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
	return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (text_content != NULL)
	{
	for (len = 0; text_content[len];)
	len++;
	w = write(fd, text_content, len);
	}
	if (fd == -1 || w == -1)
	return (-1);
	close(fd);
	return (1);

}
