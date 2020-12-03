#include "search_algos.h"
/**
 * search - searches for a value in a sorted array of integers
 * @array: array to search in
 * @left: left index
 * @right: right index
 * @value: target value to be searched
 * Return: if target located the 1st index, otherwise -1
 */
int search(int *array, size_t left, size_t right, int value)
{
	int mid;
	size_t i;

	mid = ((right - left) / 2) + left;

	printf("Searching in array: ");

	for (i = left; i <= right; i++)
	{
		if (i < right)
			printf("%i, ", array[i]);
		else
			printf("%i\n", array[i]);
	}

	if (array[mid] == value && array[mid - 1] != value)
		return (mid);

	if (left == right)
		return (-1);

	if (array[mid] >= value)
		return (search(array, left, mid, value));

	if (array[mid] < value)
		return (search(array, mid + 1, right, value));

	return (-1);
}
/**
 * advanced_binary - permorms binary searching, but shows the first ocurrence.
 * @array: array to search in
 * @size: size of the array
 * @value: target value to be searched
 * Return: if target located the 1st index, otherwise -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t left = 0;
	size_t right = size - 1;

	if (array == NULL)
		return (-1);

	return (search(array, left, right, value));
}
