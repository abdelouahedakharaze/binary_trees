#include "binary_trees.h"

/**
 * binary_tree_height_aux - Calcola l'altezza di un albero
 * @albero: Puntatore all'albero
 * Return: Altezza dell'albero
 */
size_t binary_tree_height_aux(const binary_tree_t *albero)
{
	size_t hsinistra = 0, hdestra = 0;

	if (!albero)
		return (0);

	if (albero->left)
		hsinistra = 1 + binary_tree_height_aux(albero->left);

	if (albero->right)
		hdestra = 1 + binary_tree_height_aux(albero->right);

	if (hsinistra > hdestra)
		return (hsinistra);

	return (hdestra);
}

/**
 * print_level_order - Stampa ogni nodo di un dato livello
 * @albero: Puntatore all'albero
 * @livello: Livello dell'albero
 * @func: Puntatore a una funzione per ciascun nodo
 * Return: void
 */
void print_level_order(const binary_tree_t *albero, int livello, void (*func)(int))
{
	if (!albero)
		return;

	if (livello == 1)
		func(albero->n);
	else if (livello > 1)
	{
		print_level_order(albero->left, livello - 1, func);
		print_level_order(albero->right, livello - 1, func);
	}
}

/**
 * binary_tree_levelorder - Attraversamento di un albero in ampiezza
 * @albero: Puntatore al nodo radice dell'albero da attraversare
 * @func: Puntatore a una funzione da chiamare per ogni nodo
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *albero, void (*func)(int))
{
	int altezza = 0;
	int lunghezza = 1;

	if (!albero || !func)
		return;

	altezza = binary_tree_height_aux(albero) + 1;

	while (lunghezza <= altezza)
	{
		print_level_order(albero, lunghezza, func);
		lunghezza++;
	}
}
