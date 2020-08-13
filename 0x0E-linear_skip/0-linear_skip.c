#include "search.h"
/**
 * search - search through the linked list in order to get the value.
 * @prev: prev pointer
 * @actual: actual pointer
 * @value: value to search
 * Return: Node where the value is located or NULL if the value couldn't be find
 */
skiplist_t *search(skiplist_t *prev, skiplist_t *actual, int value)
{
	while (prev && prev->index <= actual->index)
	{
		printf("Value checked at index [%lu] = [%i]\n", prev->index,
		       prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: list to search the value
 * @value: value to search
 * Return: Node where the value is or NULL if the value couldn't be find
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *actual;

	if (!list)
		return (NULL);
	actual = list;
	while (actual)
	{
		prev = actual;
		if (actual->express)
			actual = actual->express;
		else
		{
			while (actual->next)
				actual = actual->next;
			break;
		}
		printf("Value checked at index [%li] = [%i]\n", actual->index, actual->n);
		if (actual->n >= value)
			return (search(prev, actual, value));
	}
	return (search(prev, actual, value));
}
