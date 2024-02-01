#include "binary_trees.h"

/**
 * aux_sort - Crea l'albero utilizzando l'elemento centrale dell'array
 * @parent: Nodo padre del nodo da creare
 * @array: Array ordinato
 * @begin: Posizione iniziale dell'array
 * @last: Posizione finale dell'array
 * Return: Albero creato
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
    avl_t *root;
    binary_tree_t *aux;
    int mid = 0;

    if (begin <= last)
    {
        mid = (begin + last) / 2;
        aux = binary_tree_node((binary_tree_t *)parent, array[mid]);
        if (aux == NULL)
            return (NULL);
        root = (avl_t *)aux;
        root->left = aux_sort(root, array, begin, mid - 1);
        root->right = aux_sort(root, array, mid + 1, last);
        return (root);
    }
    return (NULL);
}

/**
 * sorted_array_to_avl - Crea un albero AVL da un array ordinato
 * @array: Array ordinato
 * @size: Dimensione dell'array ordinato
 * Return: Albero AVL creato dall'array ordinato
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return (NULL);
    return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}
