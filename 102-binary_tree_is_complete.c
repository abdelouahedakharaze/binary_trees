#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_is_leaf - verifica se un nodo è una foglia
 * @node: puntatore al nodo da verificare
 *
 * Return: 1 se il nodo è una foglia, 0 altrimenti.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_height - calcola l'altezza di un albero binario
 * @tree: puntatore al nodo radice dell'albero di cui calcolare l'altezza
 *
 * Return: l'altezza dell'albero. Se tree è NULL, restituisci 0
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
 * binary_tree_is_perfect - verifica se un albero binario è perfetto
 * @tree: puntatore al nodo radice dell'albero da verificare
 *
 * Return: 1 se è perfetto, 0 altrimenti. Se tree è NULL, restituisci 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *l, *r;

	if (tree == NULL)
		return (1);
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

/**
 * binary_tree_is_complete - verifica se un albero binario è completo
 * @tree: puntatore al nodo radice dell'albero da verificare
 *
 * Return: 1 se è completo, 0 altrimenti. Se tree è NULL, restituisci 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t l_height, r_height;
	binary_tree_t *l, *r;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	l = tree->left;
	r = tree->right;
	l_height = binary_tree_height(l);
	r_height = binary_tree_height(r);
	if (l_height == r_height)
	{
		if (binary_tree_is_perfect(l) && binary_tree_is_complete(r))
			return (1);
	}
	else if (l_height == r_height + 1)
	{
		if (binary_tree_is_complete(l) && binary_tree_is_perfect(r))
			return (1);
	}
	return (0);
}
