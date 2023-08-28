#include "lists.h"
/**
 * get_nodeint_at_index - returna the node at index
 * @head: pointer to the first node in the linked list
 * @index: position of node to return
 * Return: pointer to node or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	size_t k = 0;
		listint_t *temp = head;

	while (temp && k < index)
	{
		temp = temp->next;
		k++;
	}
	return (temp ? temp : NULL);
}
