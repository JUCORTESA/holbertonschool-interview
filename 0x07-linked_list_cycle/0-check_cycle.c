#include "lists.h"
/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: pointer to head of list
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */
int check_cycle(listint_t *list)
{
	listint_t *single, *twice;

	if (list == NULL)
		return (0);
	single = list;
	twice = list;
	while ((single != NULL) && (twice != NULL) && (twice->next != NULL))
	{
		single = single->next;
		twice = twice->next->next;
		if (single == twice)
			return (1);
	}
	return (0);
}
