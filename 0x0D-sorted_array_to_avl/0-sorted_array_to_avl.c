#include "binary_trees.h"

/**
  *newNode - inserts a node in the tree
  *@data: value to insert
  *@left: is a pointer to the left node of the node to create
  *@right: is a pointer to the left node of the node to create
  *Return: a pointer to the new node.
  */

avl_t *newNode(int data, avl_t *left, avl_t *right)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (!node)
		return (NULL);
	node->n = data;
	node->parent = NULL;
	node->left = left;
	node->right = right;

	return (node);
}

/**
  *sortedArrayToBST - inserts a node as the left-child of another node
  *@array: is a pointer to the parent node of the node to create
  *@start: is the first index of the array
  *@end: is the last index of the array
  *Return: a pointer to the new node o, or NULL on failure
  */

avl_t *sortedArrayToBST(int *array, int start, int end)
{
	avl_t *root, *left, *right;

	if (start > end)
		return (NULL);

	int mid = (start + end) / 2;

	left = sortedArrayToBST(array, start, mid - 1);
	right = sortedArrayToBST(array, mid + 1, end);

	root = newNode(array[mid], left, right);
	if (left != NULL)
		left->parent = root;
	if (right != NULL)
		right->parent = root;
	return (root);
}
/**
  *sorted_array_to_avl - Function to construct AVL tree
  *from a sorted array
  *@array: is a pointer to the first element of the array to be converted
  *@size: is the number of element in the array
  *Return: aa pointer to the root node of the created AVL tree,
  *or NULL on failure
  */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL)
		return (NULL);

	return (sortedArrayToBST(array, 0, size - 1));
}
