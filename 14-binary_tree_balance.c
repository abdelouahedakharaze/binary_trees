#include "binary_trees.h"

/**
 * _binary_tree_height - Calcola l'altezza di un albero binario
 * @tree: Puntatore al nodo radice dell'albero
 *
 * Return: Altezza dell'albero, 0 se tree è NULL
 */
size_t _binary_tree_height(const binary_tree_t *tree)
{
	size_t r_height, l_height;

	if (!tree)
		return (0);
	r_height = _binary_tree_height(tree->right);
	l_height = _binary_tree_height(tree->left);
	return (1 + ((r_height >= l_height) ? r_height : l_height));
}

/**
 * binary_tree_balance - Calcola il fattore di bilanciamento di un albero
 * @tree: Puntatore al nodo radice dell'albero
 *
 * Return: Fattore di bilanciamento dell'albero, 0 se tree è NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return ((int)_binary_tree_height(tree->left) - (int)_binary_tree_height(tree->right));
}
