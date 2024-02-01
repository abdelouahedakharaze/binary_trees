#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_preorder - Esegue una traversata pre-ordine di un albero binario
 * @tree: Puntatore al nodo radice dell'albero da attraversare
 * @func: Puntatore a una funzione da chiamare per ogni nodo
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n); /*  funzione fornita con il valore del nodo corrente */
	binary_tree_preorder(tree->left, func); /*  ricorsivamente il  sinistro */
	binary_tree_preorder(tree->right, func); /*  ricorsivamente il  destro */
}
