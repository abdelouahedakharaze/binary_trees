#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_size - Misura la dimensione di un albero binario
 * @tree: Puntatore al nodo radice dell'albero di cui misurare la dimensione
 *
 * Return: Dimensione dell'albero, 0 se tree è NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);

	return (size + 1);
}
