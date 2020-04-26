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
	listint_t *aux;
	listint_t *new;

	if (head == NULL)
		return (NULL);

	/* Create and a new node */
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;

	/* If new is smaller*/
	if (*head == NULL)
	{
		new->next = *head;
		*head = new;
	}
	/* else: new is the highest, therefore at the end */
	else
	{
		aux = *head;
		while (aux->next != NULL && (aux->next->n < number))
			aux = aux->next;
		new->next = aux->next;
		aux->next = new;
	}
	return (new);
}
