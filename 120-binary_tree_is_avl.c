#include "binary_trees.h"

/**
 * max - returns the max value
 *
 * @a: value
 * @b: value
 * Return: (int)
 */
int max(int a, int b)
{
	return ((a >= b) ? a : b);
}

/**
 * avl_tree_height - checks if a binary tree is a valid AVL Tree
 *
 * @tree: a pointer to the root node of the tree to check
 * Return: (int)
 */
int avl_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + max(avl_tree_height(tree->left),
					avl_tree_height(tree->right)));
}

/**
 * binary_tree_is_avl_r - checks if a binary tree is a valid AVL Tree
 *
 * @tree: a pointer to the root node of the tree to check
 * Return: (int)
 */
int binary_tree_is_avl_r(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (tree == NULL)
		return (1);

	left_h = avl_tree_height(tree->left);
	right_h = avl_tree_height(tree->right);
	if (abs(left_h - right_h) <= 1 && binary_tree_is_avl_r(tree->left) &&
		binary_tree_is_avl_r(tree->right))
		return (1);
	return (0);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 *
 * @tree: a pointer to the root node of the tree to check
 * Return: (int)
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_is_avl_r(tree));
}
