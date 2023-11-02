#include "hash_tables.h"

/**
 * hash_djb2 - Hash function that implementins djb2 algorithm
 *
 * @str: The string
 *
 * Return: The hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int i;

	hash = 5381;
	while ((i = *str++) != 0)
		hash = ((hash << 5) + hash) + i; /* hash* 33 + i */
	return (hash);
}
