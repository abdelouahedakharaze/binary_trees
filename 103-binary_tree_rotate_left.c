#include "binary_trees.h"

/**
 * binary_tree_rotate_left - esegue una rotazione sinistra su un albero binario
 * @tree: puntatore alla radice dell'albero da ruotare
 *
 * Return: un puntatore alla nuova radice dell'albero dopo la rotazione
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree == NULL)
		return (NULL);

	tree->parent = tree->right;

	if (tree->right)
	{
		tree->right = tree->right->left;
		tree->parent->left = tree;
		tree->parent->parent = NULL;

		if (tree->right)
			tree->right->parent = tree;

		return (tree->parent);
	}

	return (tree);
}
