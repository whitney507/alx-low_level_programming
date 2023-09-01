#include "main.h"
/**
 * print_binary - print abinary form of number
 * @n: unsigned long, number that will be printed in binary
 */
void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);
	(n & 1) ? _putchar('1') : _putchar('0');
}
