#include "lists.h"

/**
 * get_dnodeint_at_index - returns
 * * nth node of a dlistint_t linked list
 *
 * @h: pointer to the head of the list
 * @idx: index of the nth node
 * Return: nth node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *h, unsigned int idx)
{
	unsigned int i;

	if (h == NULL)
		return (NULL);

	while (h->prev != NULL)
		h = h->prev;

	i = 0;

	while (h != NULL)
	{
		if (i == idx)
			break;
		h = h->next;
		i++;
	}

	return (h);
}
