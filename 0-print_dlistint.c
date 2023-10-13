#include "lists.h"

/**
 * print_dlistint - prints all the elements of a
 * dlistint_t list
 *
 * @head: pointer to the head of the list
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *head)
{
	int c;

	c = 0;

	if (head == NULL)
		return (c);

	while (head->prev != NULL)
		head = head->prev;

	while (head != NULL)
	{
		printf("%d\n", head->n);
		c++;
		head = head->next;
	}

	return (c);
}
