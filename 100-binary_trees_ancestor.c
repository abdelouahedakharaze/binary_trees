#include "binary_trees.h"

/**
 * binary_trees_ancestor - Trova l'antenato comune più basso di due nodi
 * @first: Puntatore al primo nodo
 * @second: Puntatore al secondo nodo
 *
 * Return: Puntatore all'antenato comune più basso, o NULL se non trovato
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *temp1 = first;
	const binary_tree_t *temp2 = second;

	while (temp1)
	{
		temp2 = second;
		while (temp2)
		{
			if (temp1 == temp2)
				return ((binary_tree_t *)temp1);
			temp2 = temp2->parent;
		}
		temp1 = temp1->parent;
	}

	return (NULL);
}
