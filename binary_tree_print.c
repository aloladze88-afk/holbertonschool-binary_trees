#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node of the tree to print
 *
 * Return: void
 */
void binary_tree_print(const binary_tree_t *tree)
{
	if (!tree)
		return;

	if (!tree->parent)
		printf("       %03d\n", tree->n);
	else if (tree->parent->left == tree)
		printf("%03d -- %03d\n", tree->parent->n, tree->n);
	else
		printf("%03d ++ %03d\n", tree->parent->n, tree->n);

	binary_tree_print(tree->left);
	binary_tree_print(tree->right);
}
