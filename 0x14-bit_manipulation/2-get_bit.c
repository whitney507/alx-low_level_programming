#include "main.h"
/**
 * get_bit - return the value of a bit within the given index
 * @n: unsigned long, value to be returned
 * @index: position at which index to be be returned
 * Return: -1 return error or value of bit within specifid index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 63)
		return (-1);
	return ((n >> index) & 1);
}
