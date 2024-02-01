#include "binary_trees.h"

/**
 * binary_tree_height - Calcola l'altezza di un albero binario
 * @tree: puntatore al nodo radice dell'albero di cui calcolare l'altezza
 *
 * Return: l'altezza dell'albero. Se tree è NULL, restituisce 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left >= right)
		return (1 + left);
	return (1 + right);
}

/**
 * binary_tree_level - Esegue una funzione su un livello specifico di un albero binario
 * @tree: puntatore alla radice dell'albero
 * @level: livello dell'albero su cui eseguire la funzione
 * @func: funzione da eseguire
 *
 * Return: void
 */
void binary_tree_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		binary_tree_level(tree->left, level - 1, func);
		binary_tree_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - Attraversa un albero binario usando la visita
 * @tree: puntatore al nodo radice dell'albero da attraversare
 * @func: puntatore a una funzione da chiamare per ogni nodo.
 * Il valore nel nodo deve essere passato come parametro a questa funzione
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree == NULL || func == NULL)
		return;
	height = binary_tree_height(tree);
	for (i = 1; i <= height; i++)
		binary_tree_level(tree, i, func);
}
