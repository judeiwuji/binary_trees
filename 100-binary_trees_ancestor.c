#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: a pointer to the first node
 * @second: second is a pointer to the second node
 * Return: (binary_tree_t*)
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	binary_tree_t *node;

	if (first == NULL || second == NULL)
		return (NULL);

	node = first->parent;
	while (node)
	{
		if (node == second->parent || node == second)
			return (node);
		node = node->parent;
	}
	node = second->parent;
	while (node)
	{
		if (node == first->parent || node == first)
			return (node);
		node = node->parent;
	}
	return (NULL);
}
