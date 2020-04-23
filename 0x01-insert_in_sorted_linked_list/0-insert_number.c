#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert a node in a sorted linked list.
 * @head: pointer to head of list.
 * @number: number we want to insert.
 * Return: node inserted, otherwise NULL
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;

	if (*head == NULL || head == NULL)
		return (NULL);

	new = add_nodeint_end(&head, number);

	if (new->n < (*head)->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
}
