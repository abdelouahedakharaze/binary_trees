#include "binary_trees.h"

/**
 * bst_search - Cerca un valore in un Albero di Ricerca Binaria
 *
 * @tree: Puntatore al nodo radice dell'Albero di Ricerca Binaria da cercare
 * @value: Valore da cercare nell'albero
 * Return: Puntatore al nodo contenente un valore uguale a value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL || tree->n == value)
		return ((binary_tree_t *) tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}
