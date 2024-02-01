#include "binary_trees.h"

/**
 * avl_insert_full - Inserisce un valore
 *
 * @tree: puntatore alla radice
 * @parent: genitore del nodo
 * @value: il valore
 * Return: puntatore al nuovo nodo
 */
avl_t *avl_insert_full(avl_t *tree, avl_t *parent, int value)
{
    avl_t *new_node;

    if (tree == NULL)
    {
        new_node = binary_tree_node(parent, value);
        if (parent->n > new_node->n)
            parent->left = new_node;
        else
            parent->right = new_node;
        return (new_node);
    }
    else if (value == tree->n)
        return (NULL);
    else if (value < tree->n)
        return (avl_insert_full(tree->left, tree, value));
    else
        return (avl_insert_full(tree->right, tree, value));
}

/**
 * val_balancer - Ribalancia un albero AVL se necessario
 *
 * @root: puntatore alla radice dell'albero
 * @tree: puntatore al nodo da riequilibrare
 * @value: valore inserito
 * Return: 0
 */
void val_balancer(avl_t **root, avl_t *tree, int value)
{
    int new_balance;

    new_balance = binary_tree_balance(tree);
    if (new_balance > 1)
    {
        if (tree->left->n > value)
        {
            if (*root == tree)
                *root = tree->left;
            binary_tree_rotate_right(tree);
        }
        else
        {
            if (*root == tree)
                *root = tree->left->right;
            binary_tree_rotate_left(tree->left);
            binary_tree_rotate_right(tree);
        }
    }
    if (new_balance < -1)
    {
        if (tree->right->n < value)
        {
            if (*root == tree)
                *root = tree->right;
            binary_tree_rotate_left(tree);
        }
        else
        {
            if (*root == tree)
                *root = tree->right->left;
            binary_tree_rotate_right(tree->right);
            binary_tree_rotate_left(tree);
        }
    }
}

/**
 * avl_insert - Inserisce il valore in un AVL
 *
 * @tree: puntatore doppio alla radice
 * @value: il valore
 * Return: puntatore al nuovo nodo
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new_node, *predecessor;

    if (tree == NULL)
        return (NULL);
    if (*tree == NULL)
    {
        new_node = binary_tree_node(NULL, value);
        *tree = new_node;
        return (new_node);
    }
    new_node = avl_insert_full(*tree, NULL, value);

    if (new_node == NULL)
        return (NULL);

    predecessor = new_node->parent;

    while (predecessor != NULL)
    {
        val_balancer(tree, predecessor, value);
        predecessor = predecessor->parent;
    }

    return (new_node);
}
