#include "binary_trees.h"

/**
  *binary_tree_height - measures the height of a binary tree
  *@tree: is a pointer to the root of the tree
  *Return: Height of tree.
  */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_binary_tree_height;
	size_t right_binary_tree_height;

	if (tree == NULL)
		return (0);

	left_binary_tree_height = binary_tree_height(tree->left);
	right_binary_tree_height = binary_tree_height(tree->right);

	if (left_binary_tree_height > right_binary_tree_height)
		return (left_binary_tree_height + 1);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	return (right_binary_tree_height + 1);
}

/**
  *binary_tree_is_perfect - measures if the tree is perfect
  *@tree: is a pointer to the root of the tree
  *Return: 1 if true, 0 otherwise
  */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (binary_tree_is_perfect(tree->left) &&
		 binary_tree_is_perfect(tree->right) &&
		(binary_tree_height(tree->left) == binary_tree_height(tree->right)));
}

/**
 * check_swap - check for max numbers at parent node
 *
 * @arg_node: parent node
 * @arg_child: child node
 * Return: no return
 */
void check_swap(heap_t **arg_node, heap_t **arg_child)
{
	heap_t *node, *child, *node_child, *node_left, *node_right, *parent;
	int left_right;

	node = *arg_node, child = *arg_child;
	if (child->n > node->n)
	{
		if (child->left)
			child->left->parent = node;
		if (child->right)
			child->right->parent = node;
		if (node->left == child)
			node_child = node->right, left_right = 0;
		else
			node_child = node->left, left_right = 1;
		node_left = child->left, node_right = child->right;
		if (left_right == 0)
		{
			child->right = node_child;
			if (node_child)
				node_child->parent = child;
			child->left = node;
		}
		else
		{
			child->left = node_child;
			if (node_child)
				node_child->parent = child;
			child->right = node;
		}
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = child;
			else
				node->parent->right = child;
		}
		parent = node->parent, child->parent = parent;
		node->parent = child, node->left = node_left;
		node->right = node_right, *arg_node = child;
	}
}

/**
 * heap_insert - a function that inserts a value into a Max Binary Heap
 * @root: a double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 *
 * Return: a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	if (binary_tree_is_perfect(*root) || !binary_tree_is_perfect((*root)->left))
	{
		if ((*root)->left)
		{
			new_node = heap_insert(&((*root)->left), value);
			check_swap(root, &((*root)->left));
			return (new_node);
		}
		else
		{
			new_node = (*root)->left = binary_tree_node(*root, value);
			check_swap(root, &((*root)->left));
			return (new_node);
		}
	}

	if ((*root)->right)
	{
		new_node = heap_insert(&((*root)->right), value);
		check_swap(root, (&(*root)->right));
		return (new_node);
	}
	else
	{
		new_node = (*root)->right = binary_tree_node(*root, value);
		check_swap(root, &((*root)->right));
		return (new_node);
	}

	return (NULL);
}
