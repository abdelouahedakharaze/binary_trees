#include "binary_trees.h"

/**
 * bal - Calcola il fattore di bilanciamento di un AVL
 * @tree: Albero da attraversare
 * Return: Fattore di bilanciamento
 */
void bal(avl_t **tree)
{
    int bval;

    if (tree == NULL || *tree == NULL)
        return;
    if ((*tree)->left == NULL && (*tree)->right == NULL)
        return;
    bal(&(*tree)->left);
    bal(&(*tree)->right);
    bval = binary_tree_balance((const binary_tree_t *)*tree);
    if (bval > 1)
        *tree = binary_tree_rotate_right((binary_tree_t *)*tree);
    else if (bval < -1)
        *tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * successor - Ottiene il successore successivo, cioè il nodo minimo nel sottoalbero destro
 * @node: Albero da controllare
 * Return: Il valore minimo di questo albero
 */
int successor(bst_t *node)
{
    int left = 0;

    if (node == NULL)
    {
        return (0);
    }
    else
    {
        left = successor(node->left);
        if (left == 0)
        {
            return (node->n);
        }
        return (left);
    }
}

/**
 * remove_type - Funzione che rimuove un nodo in base ai suoi figli
 * @root: Nodo da rimuovere
 * Return: 0 se non ha figli, altrimenti il nuovo valore del nodo
 */
int remove_type(bst_t *root)
{
    int new_value = 0;

    if (!root->left && !root->right)
    {
        if (root->parent->right == root)
            root->parent->right = NULL;
        else
            root->parent->left = NULL;
        free(root);
        return (0);
    }
    else if ((!root->left && root->right) || (!root->right && root->left))
    {
        if (!root->left)
        {
            if (root->parent->right == root)
                root->parent->right = root->right;
            else
                root->parent->left = root->right;
            root->right->parent = root->parent;
        }
        if (!root->right)
        {
            if (root->parent->right == root)
                root->parent->right = root->left;
            else
                root->parent->left = root->left;
            root->left->parent = root->parent;
        }
        free(root);
        return (0);
    }
    else
    {
        new_value = successor(root->right);
        root->n = new_value;
        return (new_value);
    }
}

/**
 * bst_remove - Rimuove un nodo da un albero BST
 * @root: Radice dell'albero
 * @value: Valore del nodo da rimuovere
 * Return: L'albero modificato
 */
bst_t *bst_remove(bst_t *root, int value)
{
    int type = 0;

    if (root == NULL)
        return (NULL);
    if (value < root->n)
        bst_remove(root->left, value);
    else if (value > root->n)
        bst_remove(root->right, value);
    else if (value == root->n)
    {
        type = remove_type(root);
        if (type != 0)
            bst_remove(root->right, type);
    }
    else
        return (NULL);
    return (root);
}

/**
 * avl_remove - Rimuove un nodo da un albero AVL
 * @root: Radice dell'albero
 * @value: Valore del nodo da rimuovere
 * Return: L'albero modificato
 */
avl_t *avl_remove(avl_t *root, int value)
{
    avl_t *root_a = (avl_t *)bst_remove((bst_t *)root, value);

    if (root_a == NULL)
        return (NULL);
    bal(&root_a);
    return (root_a);
}
