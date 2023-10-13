#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at
 * a given position
 *
 * @head: pointer to the head of the list
 * @index: index of the new node
 * @val: value of the new node
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **head,
		unsigned int index, int val)
{
	dlistint_t *newNode;
	dlistint_t *current;
	unsigned int i;

	newNode = NULL;
	if (index == 0)
		newNode = add_dnodeint(head, val);
	else
	{
		current = *head;
		i = 1;
		if (current != NULL)
			while (current->prev != NULL)
				current = current->prev;
		while (current != NULL)
		{
			if (i == index)
			{
				if (current->next == NULL)
					newNode = add_dnodeint_end(head, val);
				else
				{
					newNode = malloc(sizeof(dlistint_t));
					if (newNode != NULL)
					{
						newNode->n = val;
						newNode->next = current->next;
						newNode->prev = current;
						current->next->prev = newNode;
						current->next = newNode;
					}
				}
				break;
			}
			current = current->next;
			i++;
		}
	}

	return (newNode);
}
