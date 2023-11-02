#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_delete -  deletes a sorted hash table.
 * @ht: Pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *current_node, *tmp;

	if (ht == NULL)
		return;

	current_node = ht->shead;
	while (current_node)
	{
		tmp = current_node->snext;
		free(current_node->key);
		free(current_node->value);
		free(current_node);
		current_node = tmp;
	}

	free(head->array);
	free(head);
}

/**
 * shash_table_print - prints a sorted hash table in order.
 * @ht: Pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current_node;

	if (ht == NULL)
		return;

	current_node = ht->shead;
	printf("{");
	while (current_node != NULL)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		current_node = current_node->snext;
		if (current_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse order.
 * @ht: Pointer.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current_node;

	if (ht == NULL)
		return;

	current_node = ht->stail;
	printf("{");
	while (current_node != NULL)
	{
		printf("'%s': '%s'",current_node->key, current_node->value);
		current_node = current_node->sprev;
		if (current_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_set - It adds an element to a sorted hash table.
 * @ht: Pointer .
 * @key: A key to add .
 * @value: Value associated with key.
 *
 * Return: on failure - 0.
 *         On sucess - 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *tmp;
	char *value_node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_node = strdup(value);
	if (value_node == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->shead;
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = value_node;
			return (1);
		}
		tmp = tmp->snext;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
	{
		free(value_node);
		return (0);
	}
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(value_node);
		free(new_node);
		return (0);
	}
	new_node->value = value_node;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	if (ht->shead == NULL)
	{
		new_node->sprev = NULL;
		new_node->snext = NULL;
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new_node->sprev = NULL;
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		tmp = ht->shead;
		while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
			tmp = tmp->snext;
		new_node->sprev = tmp;
		new_node->snext = tmp->snext;
		if (tmp->snext == NULL)
			ht->stail = new_node;
		else
			tmp->snext->sprev = new_node;
		tmp->snext = new_node;
	}

	return (1);
}

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: size of new sorted hash table.
 *
 * Return: for error - NULL.
 *         on sucess - a pointer to the new sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *hash;
	unsigned long int i;

	hash = malloc(sizeof(shash_table_t));
	if (hash == NULL)
		return (NULL);

	hash->size = size;
	hash->array = malloc(sizeof(shash_node_t *) * size);
	if (hash->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		hash->array[i] = NULL;
	hash->shead = NULL;
	hash->stail = NULL;

	return (ht);
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse order.
 * @ht: Pointer to  sorted hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current_node;

	if (ht == NULL)
		return;

	current_node = ht->stail;
	printf("{");
	while (current_node != NULL)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		current_node = current_node->sprev;
		if (current_node != NULL)
			printf(", ");
	}
	printf("}\n");

}

