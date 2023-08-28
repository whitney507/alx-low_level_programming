#include "lists.h"
/**
 * listint_len - returns the number of elements in a linked list
 * @h: pointer to first node in a linked list
 * Return: number of nodes in a linked list
 */
size_t listint_len(const listint_t *h)
{
	size_t node = 0;

	while (h)
	{
		node++;
		h = h->next;
	}
	return (node);
}
