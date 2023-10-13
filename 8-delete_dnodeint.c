#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes node at index of a
 * dlistint_t linked list
 *
 * @h: pointer to the head of the list
 * @idx: index of the node to be deleted
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **h, unsigned int idx)
{
	dlistint_t *current;
	dlistint_t *previous;
	unsigned int i;

	current = *h;

	if (current != NULL)
		while (current->prev != NULL)
			current = current->prev;

	i = 0;

	while (current != NULL)
	{
		if (i == idx)
		{
			if (i == 0)
			{
				*h = current->next;
				if (*h != NULL)
					(*h)->prev = NULL;
			}
			else
			{
				previous->next = current->next;

				if (current->next != NULL)
					current->next->prev = previous;
			}

			free(current);
			return (1);
		}
		previous = current;
		current = current->next;
		i++;
	}

	return (-1);
}
