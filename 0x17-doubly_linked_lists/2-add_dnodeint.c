#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning
 * of a dlistint_t list
 *
 * @h: pointer to the head of the list
 * @val: value of the element
 * Return: the address of the new element
 */
dlistint_t *add_dnodeint(dlistint_t **h, const int val)
{
	dlistint_t *newNode;
	dlistint_t *current;

	newNode = malloc(sizeof(dlistint_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = val;
	newNode->prev = NULL;
	current = *h;

	if (current != NULL)
	{
		while (current->prev != NULL)
			current = current->prev;
	}

	newNode->next = current;

	if (current != NULL)
		current->prev = newNode;

	*h = newNode;

	return (newNode);
}
