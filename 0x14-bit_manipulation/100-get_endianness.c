#include "main.h"
/**
 * get_endianness - function that checks for endianess
 * Return: 0 if big endian or 1 for little endian
 */
int get_endianness(void)
{
	unsigned int a = 1;
	char *b = (char *)&a;

	if (*b)
		return (1);
	else
		return (0);
}
