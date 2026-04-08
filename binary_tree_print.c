#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Printing function from Holberton School */
/**
 * print_t - Traverse tree printing nodes with positions
 * @tree: Tree node
 * @offset: Offset
 * @depth: Depth
 * @s: String
 */
static void print_t(const binary_tree_t *tree, int offset, int depth, char *s)
{
	char b[6];
	int width, left, right, is_left;
	int i;

	if (!tree)
		return;
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = (is_left ? (offset - width) / 2 : offset + 2);
	right = (is_left ? (offset + width) / 2 : offset + width - 1);
	sprintf(s + left, "%s", b);
	if (depth)
	{
		for (i = left + width / 2; i < right; i++)
			sprintf(s + i, "-");
		if (is_left)
		{
			sprintf(s + (left + width / 2), "|");
			print_t(tree->left, left + width / 2 - 1, depth - 1, s - 256);
			print_t(tree->right, left + width / 2 + 1, depth - 1, s + 256);
		}
		else
		{
			sprintf(s + (right), "|");
			print_t(tree->left, right - 1, depth - 1, s - 256);
			print_t(tree->right, right + 1, depth - 1, s + 256);
		}
	}
}

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node of the tree to print
 *
 * Return: void
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char *s;
	size_t height;

	if (!tree)
		return;
	height = 0;
	s = malloc(sizeof(char) * 255);
	if (!s)
		return;
	memset(s, 32, 255);
	print_t(tree, 0, height, s);
	printf("%s\n", s);
	free(s);
}
