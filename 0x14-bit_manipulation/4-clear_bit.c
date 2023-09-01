#include "main.h"
/**
 * clear_bit - set value of bit to 0 at specified index
 * @n: unsigned long to be  changed
 * @index: position of index to change to zero
 * Return: 1 for sucess or -1 incase offailure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	int delete;

	if (index > 63 || !n)
		return (-1);
	delete = 1 << index;
	*n = (*n & ~delete) | ((0 << index) & delete);
	return (1);
}
