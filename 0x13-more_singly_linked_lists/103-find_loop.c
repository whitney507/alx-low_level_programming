#include "lists.h"
/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search for
 * Return: address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *prev = head;
	listint_t *forw = head;

	if (!head)
		return (NULL);

	while (prev && forw  && forw->next)
	{
		forw = forw->next->next;
		prev = prev->next;

		if (forw == prev)
		{
			prev = head;
			while (prev != forw)
			{
				prev = prev->next;
				forw = forw->next;
			}
			return (forw);
		}
	}
	return (NULL);
}
