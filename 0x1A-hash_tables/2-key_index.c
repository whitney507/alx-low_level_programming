#include "hash_tables.h"
/**
 * key_index - Get index for saving a key in hashtable.
 * @key: The key to get the index of.
 * @size: size of the hash table.
 *
 * Return: The index of the key.
 *
 * Description: Uses the djb2 algorithm in
 *   index computation.
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
