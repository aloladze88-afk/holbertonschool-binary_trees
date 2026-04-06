#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of a node
 * @parent: pointer to the parent node
 * @value: value to store in the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	binary_tree_t *old_left;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	old_left = parent->left;
	parent->left = new_node;

	if (old_left != NULL)
	{
		new_node->left = old_left;
		old_left->parent = new_node;
	}

	return (new_node);
}
