#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Verifica se un nodo è una foglia.
 * @node: Puntatore al nodo da verificare.
 *
 * Return: 1  una foglia, 0 altrimenti. Se il nodo è NULL, restituisce 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_height - Misura l'altezza di un albero binario.
 * @tree: Puntatore al nodo radice dell'albero.
 *
 * Return: L'altezza dell'albero. Se tree è NULL, restituisce 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL || binary_tree_is_leaf(tree))
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left >= right)
		return (1 + left);
	return (1 + right);
}

/**
 * binary_tree_is_perfect - Verifica se un albero binario è perfetto.
 * @tree: Puntatore al nodo radice dell'albero da verificare.
 *
 * Return: 1 se è perfetto, 0 altrimenti. Se tree è NULL, restituisce 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *l, *r;

	if (tree == NULL)
		return (0);
	l = tree->left;
	r = tree->right;
	if (binary_tree_is_leaf(tree))
		return (1);
	if (l == NULL || r == NULL)
		return (0);
	if (binary_tree_height(l) == binary_tree_height(r))
	{
		if (binary_tree_is_perfect(l) && binary_tree_is_perfect(r))
			return (1);
	}
	return (0);
}
