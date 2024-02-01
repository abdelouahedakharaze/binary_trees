#include "binary_trees.h"

/**
 * min_finder - Trova il nodo con il valore minimo
 * @root: Puntatore all'albero
 * Return: Il valore minimo
 */

bst_t *min_finder(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_remove - Rimuove un nodo da un Albero di Ricerca Binaria
 *
 * @root: Puntatore al nodo radice dell'albero da cui rimuovere un nodo
 * @value: Valore da rimuovere dall'albero
 * Return: Puntatore al nuovo nodo radice dell'albero
 * dopo aver rimosso il valore desiderato
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *parent;

	if (root == NULL)
		return (NULL);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			temp = root;
			parent = root->parent;
			root = root->right;
			root->parent = parent;
			free(temp);
		}
		else if (root->right == NULL)
		{
			temp = root;
			parent = root->parent;
			root = root->left;
			root->parent = parent;
			free(temp);
		}
		else
		{
			temp = min_finder(root->right);
			root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
		}
	}
	return (root);
}
