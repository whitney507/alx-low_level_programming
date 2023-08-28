#include "lists.h"
/**
 * sum_listint - find sum of elements in a linked list
 * @head:pointer to first node in  linkedlist
 * Return: sum of elements in linked list
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *temp = head;

	while (temp)
	{
		sum += temp->n;
		temp = temp->next;
	}
	return (sum);
}
