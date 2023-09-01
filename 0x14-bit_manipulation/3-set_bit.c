#include "main.h"
/**
 * set_bit -set the value of bit to 1 within the specified index
 * @n: unsigned long that changes
 * @index: position at which @n changes
 * Return: 1 for success or -1 for failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63 || !n)
		return (-1);
	(*n |= 1 << index);
	return (1);
}
