#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_inorder - Esegue una traversata in ordine di un albero binario
 * @tree: Puntatore al nodo radice dell'albero da attraversare
 * @func: Puntatore a una funzione da chiamare per ogni nodo
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
