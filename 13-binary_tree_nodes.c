#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_nodes - Conta i nodi con almeno un figlio in un albero binario
 * @tree: Puntatore al nodo radice dell'albero
 *
 * Return: Numero di nodi con almeno un figlio nell'albero, 0 se tree è NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}

