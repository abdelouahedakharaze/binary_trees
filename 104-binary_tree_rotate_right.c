#include "binary_trees.h"

/**
 * binary_tree_rotate_right - esegue una rotazione a destra
 * @tree: puntatore al nodo radice dell'albero da ruotare
 *
 * Return: un puntatore al nuovo nodo radice dell'albero
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (tree == NULL)
		return (NULL);

	tree->parent = tree->left;

	if (tree->left)
	{
		tree->left = tree->left->right;
		tree->parent->right = tree;
		tree->parent->parent = NULL;

		if (tree->left)
			tree->left->parent = tree;

		return (tree->parent);
	}

	return (tree);
}
