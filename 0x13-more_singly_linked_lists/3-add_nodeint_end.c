#include "lists.h"
/**
 * add_nodeint_end - add a node at the end of the list
 * @head: pointer to the first node in the list
 * @n: data to be added in the new node
 * Return: pointer to new node or NULL incase it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newnode;
	listint_t *temp = *head;

	newnode = malloc(sizeof(listint_t));

			if (!newnode)
			return (NULL);

			newnode->n = n;
			newnode->next = NULL;

			if (*head == NULL)
			{
			*head = newnode;
			return (*head);
			}

			while (temp->next)
			temp = temp->next;

			temp->next = newnode;
			return (*head);
			}
