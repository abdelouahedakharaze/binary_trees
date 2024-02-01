#include "binary_trees.h"

/**
 * isBST - Confronta il nodo per verificare se è un dato
 *
 * @albero: puntatore al nodo radice dell'albero da controllare
 * @min: valore minimo
 * @max: valore massimo
 *
 * Return: 1 se ha successo, 0 altrimenti
 */
int isBST(const binary_tree_t *albero, int min, int max)
{
	if (albero == NULL)
		return (1);

	if (albero->n < min || albero->n > max)
		return (0);

	return (
		isBST(albero->left, min, albero->n - 1) &&
		isBST(albero->right, albero->n + 1, max)
	);
}

/**
 * binary_tree_is_bst - verifica se un albero binario è un valido albero di ricerca binario
 *
 * @albero: puntatore al nodo radice dell'albero da controllare
 * Return: 1 se ha successo, 0 altrimenti
 */
int binary_tree_is_bst(const binary_tree_t *albero)
{
	if (albero == NULL)
		return (0);

	return (isBST(albero, INT_MIN, INT_MAX));
}
