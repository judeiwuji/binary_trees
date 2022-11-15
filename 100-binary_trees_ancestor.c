#include "binary_trees.h"

/**
 * trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: a pointer to the first node
 * @second: second is a pointer to the second node
 * Return: (binary_tree_t*)
 */
binary_tree_t *trees_ancestor(const binary_tree_t *first,
							  const binary_tree_t *second)
{
	binary_tree_t *node;

	if (first)
	{
		node = first->parent;
		while (node)
		{
			if (node == second->parent || node == second)
				return (node);
			node = node->parent;
		}
	}
	return (NULL);
}

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

	if (first == NULL && second == NULL)
		return (NULL);

	node = trees_ancestor(first, second);
	if (node)
		return (node);
	return (trees_ancestor(second, first));
}
