#include "binary_trees.h"

/**
 * binary_tree_rotate_right - esegue una rotazione a destra su un albero binario
 * @tree: Puntatore alla radice dell'albero
 *
 * Return: Puntatore alla nuova radice dell'albero dopo la rotazione
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *albero)
{
	binary_tree_t *sinistro, *genitore = albero;

	if (!albero)
		return (NULL);

	sinistro = genitore->left;
	if (!sinistro)
		return (albero);

	if (sinistro->right)
		sinistro->right->parent = genitore;

	genitore->left = sinistro->right;
	sinistro->right = genitore;
	sinistro->parent = genitore->parent;
	genitore->parent = sinistro;

	if (sinistro->parent && sinistro->parent->left == genitore)
		sinistro->parent->left = sinistro;
	else if (sinistro->parent)
		sinistro->parent->right = sinistro;

	return (sinistro);
}
