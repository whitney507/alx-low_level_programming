#include "./hash_tables.h"

/**
 * hash_table_print - Prints a hash table in test filee order.
 * @ht: Pointer to the hash table
 *
 * Description: value pairs are printed in
 * the order they appear test file  array
 *
 * Return: list of hast table values
 * or nothing if list is null
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *new;
	unsigned long int i;
	unsigned char comma_flag = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i] != NULL)
		{
			if (comma_flag == 1)
				printf(", ");

			new = ht->array[i];
			while (new != NULL)
			{
				printf("'%s': '%s'", new->key, new->value);
				new = new->next;
				if (new != NULL)
					printf(", ");
			}
			comma_flag = 1;
		}
	}
	printf("}\n");
}
