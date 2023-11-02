#include "hash_tables.h"

/**
 * hash_table_get - Retrieve the value associated with a key in a hash table.
 * @ht: Pointer.
 * @key: Key
 * Return:  NULL if no key is found or.
 *  value associated with key in ht if key is found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *new;
	unsigned long int pos;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	pos = key_index((const unsigned char *)key, ht->size);
	if (pos >= ht->size)
		return (NULL);

	new = ht->array[pos];
	while (new && strcmp(new->key, key) != 0)
		new = new->next;

	return ((new == NULL) ? NULL : new->value);
}
