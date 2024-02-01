#include "binary_trees.h"

/**
 * count_nodes - Conta i nodi all'interno di un albero
 * @radice: Nodo radice
 *
 * Return: Numero di nodi
 */
int count_nodes(binary_tree_t *radice)
{
	if (!radice)
		return (0);

	return (1 + count_nodes(radice->left) + count_nodes(radice->right));
}

/**
 * is_complete - Verifica se un albero è completo
 * @radice: Puntatore alla radice dell'albero
 * @indice: Indice del nodo in valutazione
 * @n: Numero totale di nodi
 *
 * Return: 1 se l'albero è completo, 0 altrimenti
 */
int is_complete(binary_tree_t *radice, int indice, int n)
{
	if (!radice)
		return (0);

	if (indice >= n)
		return (0);
	if (!radice->left && !radice->right)
		return (1);
	if (radice->right && !radice->left)
		return (0);
	if (radice->left && !radice->right)
		return (is_complete(radice->left, indice * 2 + 1, n));

	return (is_complete(radice->left, indice * 2 + 1, n) &&
		is_complete(radice->right, indice * 2 + 2, n));
}

/**
 * binary_tree_is_complete - Verifica se un albero binario è completo
 * @albero: Puntatore alla radice dell'albero
 *
 * Return: 1 se l'albero è completo, 0 altrimenti
 */
int binary_tree_is_complete(const binary_tree_t *albero)
{
	int nodi;
	binary_tree_t *radice;

	if (!albero)
		return (0);

	radice = (binary_tree_t *)albero;
	nodi = count_nodes(radice);

	return (is_complete(radice, 0, nodi));
}
