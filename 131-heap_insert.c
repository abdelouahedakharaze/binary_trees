#include "binary_trees.h"

/**
 * heap_insert - inserisce nell'heap
 *
 * @tree: puntatore doppio alla radice
 * @value: il valore da memorizzare
 * Return: puntatore al nodo creato
 */
heap_t *heap_insert(heap_t **tree, int value)
{
    size_t size;
    int doswap = 1;
    heap_t *new, *parent;

    if (tree == NULL)
        return (NULL);

    if (*tree == NULL)
    {
        new = binary_tree_node(NULL, value);
        *tree = new;
        return (new);
    }

    size = bts(*tree);
    parent = heap_nf(*tree, (size - 1) / 2);
    new = binary_tree_node(parent, value);
    if (size % 2 == 1)
        parent->left = new;
    else
        parent->right = new;
    if (new == NULL)
        return (NULL);

    while (doswap == 1 && parent != NULL)
    {
        if (parent->n >= new->n)
            doswap = 0;
        else
        {
            new = heap_r(new, parent);
            parent = new->parent;
        }
    }

    return (new);
}

/**
 * bts - misura l'albero
 *
 * @tree: puntatore alla radice
 * Return: dimensione, altrimenti 0
 */
size_t bts(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (1 + bts(tree->left) + bts(tree->right));
}

/**
 * heap_nf - trova il nodo nell'heap
 *
 * @root: puntatore alla radice
 * @number: indice del nodo da trovare
 * Return: puntatore al nodo
 */
heap_t *heap_nf(heap_t *root, size_t number)
{
    size_t parentn, dir;

    if (number == 0)
        return (root);

    parentn = (number - 1) / 2;
    dir = (number - 1) % 2;

    if (dir == 0)
        return (heap_nf(root, parentn)->left);
    return (heap_nf(root, parentn)->right);
}

/**
 * heap_r - riequilibra l'heap
 * @new: puntatore al nuovo nodo
 * @parent: puntatore al nuovo genitore
 * Return: parent
 */
heap_t *heap_r(heap_t *new, heap_t *parent)
{
    int tmp;

    tmp = new->n;
    new->n = parent->n;
    parent->n = tmp;
    return (parent);
}
