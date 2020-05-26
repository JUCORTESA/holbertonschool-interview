#include "lists.h"
/**
 * is_palindrome - function in C that
 * checks if a singly linked list is a palindrome
 * @head: pointer to the head of the linked_list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	int i = 0, j, palindrome[4096];
	listint_t *aux;

	if (!(*head))
		return (1);

	aux = *head;
    /** save numbers of linked list in array and compare array in reverse */
	while (aux != NULL)
	{
		palindrome[i] = aux->n;
		aux = aux->next;
		i++;
	}
	i--;

	for (j = 0; j <= i / 2; j++)
	{
		if (palindrome[j] != palindrome[i - j])
			return (0);
	}
	return (1);
}