#include "binary_trees.h"

/**
 * btl - livello ausiliario
 *
 * @tree: puntatore alla radice
 * Return: intero con il livello
 */

int btl(const binary_tree_t *tree)
{
	int h_left, h_right;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	h_left = btl(tree->left);
	h_right = btl(tree->right);
	if (h_left > h_right)
		return (h_left + 1);
	else
		return (h_right + 1);
}

/**
 * bt_balance - calcola il fattore
 *
 * @tree: puntatore alla radice
 * Return: intero con il fattore
 */

int bt_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (btl(tree->left) - btl(tree->right));
}

/**
 * bavl - Controlla il livello
 *
 * @tree: puntatore alla radice
 * @min: valore minimo
 * @max: valore massimo
 * Return: 1 se è AVL, 0 altrimenti
 */

int bavl(const binary_tree_t *tree, int min, int max)
{
	int balance_left, balance_right, balance;

	if (tree == NULL)
		return (1);
	if (tree->n > max || tree->n < min)
		return (0);
	balance = bt_balance(tree);
	if (balance < -1 || balance > 1)
		return (0);
	balance_left = bavl(tree->left, min, tree->n - 1);
	balance_right = bavl(tree->right, tree->n + 1, max);
	if (balance_left == 1 && balance_right == 1)
		return (1);
	return (0);
}

/**
 * binary_tree_is_avl - verifica se un albero binario è un AVL valido
 * @tree: puntatore al nodo radice dell'albero da controllare
 *
 * Return: 1 se l'albero è un AVL valido, altrimenti 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bavl(tree, INT_MIN, INT_MAX));
}
