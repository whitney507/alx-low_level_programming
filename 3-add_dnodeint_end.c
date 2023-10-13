#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end
 * of a dlistint_t list
 *
 * @h: pointer to the head of the list
 * @val: value of the element
 * Return: the address of the new element
 */
dlistint_t *add_dnodeint_end(dlistint_t **h, const int val)
{
	dlistint_t *current;
	dlistint_t *newNode;

	newNode = malloc(sizeof(dlistint_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = val;
	newNode->next = NULL;

	current = *h;

	if (current != NULL)
	{
		while (current->next != NULL)
			current = current->next;
		current->next = newNode;
	}
	else
	{
		*h = newNode;
	}

	newNode->prev = current;

	return (newNode);
}
