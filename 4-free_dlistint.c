#include "lists.h"

/**
 * free_dlistint - frees  dlistint_t list
 *
 * @h: pointer to the head of the list
 * Return: nothing
 */
void free_dlistint(dlistint_t *h)
{
	dlistint_t *temp;

	if (h != NULL)
		while (h->prev != NULL)
			h = h->prev;

	while ((temp = h) != NULL)
	{
		h = h->next;
		free(temp);
	}
}
