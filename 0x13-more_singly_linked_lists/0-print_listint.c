#include "lists.h"
/**
 * print_listint-prints all the elements in the linked list
 * @h : pointer to first node in the linked list
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t node = 0;

	while (h)
	{
		printf("%d\n", h->n);
		node++;
		h = h->next;
	}
	return (node);
}
