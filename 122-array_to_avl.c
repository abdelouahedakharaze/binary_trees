#include "binary_trees.h"

/**
 * array_to_avl - costruisce un albero AVL da un array
 * @array: puntatore al primo elemento dell'array da convertire
 * @size: numero di elementi nell'array
 * Return: Puntatore alla radice
 */
avl_t *array_to_avl(int *array, size_t size)
{
    size_t i;
    avl_t *root = NULL;

    if (!array || size == 0)
        return (NULL);

    root = avl_insert(&root, array[0]);
    for (i = 1; i < size; i++)
        avl_insert(&root, array[i]);

    return (root);
}
