#include "lists.h"

/**
 * sum_dlistint - returns sum of all the data (n)
 * of a doubly linked list
 *
 * @h: pointer to the head of the list
 * Return: sum of the data
 */
int sum_dlistint(dlistint_t *h)
{
	int sum;

	sum = 0;

	if (h != NULL)
	{
		while (h->prev != NULL)
			h = h->prev;

		while (h != NULL)
		{
			sum += h->n;
			h = h->next;
		}
	}

	return (sum);
}
