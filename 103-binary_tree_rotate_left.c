#include "binary_trees.h"

/**
 * binary_tree_rotate_left - esegue una rotazione a sinistra
 * @albero: Puntatore alla radice
 *
 * Return: Puntatore alla nuova radice dopo la rotazione a sinistra
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *albero)
{
	binary_tree_t *destro, *genitore = albero;

	if (!albero)
		return (NULL);

	destro = genitore->right;
	if (!destro)
		return (albero);

	if (destro->left)
		destro->left->parent = genitore;

	genitore->right = destro->left;
	destro->left = genitore;
	destro->parent = genitore->parent;
	genitore->parent = destro;

	if (destro->parent && destro->parent->left == genitore)
		destro->parent->left = destro;
	else if (destro->parent)
		destro->parent->right = destro;

	return (destro);
}
