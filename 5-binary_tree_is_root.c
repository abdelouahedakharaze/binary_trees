#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_root - Verifica se un nodo è una radice
 * @node: Puntatore al nodo da verificare
 *
 * Return: 1 se il nodo è una radice, altrimenti 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
