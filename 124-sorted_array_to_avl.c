#include "binary_trees.h"

/**
 * sorted_array_to_avl_recursive - conversione ricorsiva di un array in AVL
 *
 * @array: puntatore all'array
 * @first_index: indice iniziale della sotto-array
 * @final_index: indice finale della sotto-array
 * Return: puntatore alla radice
 */
avl_t *sorted_array_to_avl_recursive(int *array, int first_index,
int final_index)
{
    avl_t *root;
    int half;

    if (final_index < first_index)
        return (NULL);

    half = (final_index + first_index) / 2;
    /* creazione dell'albero binario con radice = half */
    root = binary_tree_node(NULL, array[half]);
    if (!root)
        return (NULL);
    /* ordinamento di ogni ramo */
    root->left = sorted_array_to_avl_recursive(array, first_index, half - 1);
    root->right = sorted_array_to_avl_recursive(array, half + 1, final_index);
    if (root->left)
        root->left->parent = root;
    if (root->right)
        root->right->parent = root;
    return (root);
}

/**
 * sorted_array_to_avl - costruisce un albero AVL da un array
 *
 * @array: puntatore al primo elemento dell'array da convertire
 * @size: numero di elementi nell'array
 * Return: puntatore alla radice dell'albero AVL creato
 * o NULL in caso di errore
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size < 1)
        return (NULL);
    return (sorted_array_to_avl_recursive(array, 0, size - 1));
}
