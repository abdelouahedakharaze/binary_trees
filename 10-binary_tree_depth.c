#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_depth - Calcola la profondità di un nodo in un albero binario
 * @tree: Puntatore al nodo di cui calcolare la profondità
 *
 * Return: Profondità del nodo, 0 se tree è NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		tree = tree->parent;
		depth++;
	}

	return (depth);
}
