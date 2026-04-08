#include "binary_trees.h"

/**
 * _binary_tree_height - Helper function to measure the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The height of the tree
 */
static int _binary_tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (-1);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_height = _binary_tree_height(tree->left);
	right_height = _binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);

	return (right_height + 1);
}

/**
 * _binary_tree_size - Helper function to measure the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The size of the tree (number of nodes)
 */
static int _binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + _binary_tree_size(tree->left) + _binary_tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, size, expected_nodes;

	if (tree == NULL)
		return (0);

	height = _binary_tree_height(tree);
	size = _binary_tree_size(tree);
	expected_nodes = (1 << (height + 1)) - 1;

	return (size == expected_nodes ? 1 : 0);
}
