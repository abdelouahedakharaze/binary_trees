#include "binary_trees.h"
#include <stdio.h>

/**
 * is_greater_than - check if all values in the tree are greater than a value
 * @tree: pointer to the tree to check
 * @val: value to check against
 *
 * Return: 1 if true, 0 if false
 */
int is_greater_than(const binary_tree_t *tree, int val)
{
	int left, right;

	if (tree == NULL)
		return (1);
	if (tree->n > val)
	{
		left = is_greater_than(tree->left, val);
		right = is_greater_than(tree->right, val);
		if (left && right)
			return (1);
	}
	return (0);
}

/**
 * is_less_than - check if all values in the tree are less than a specific value
 * @tree: pointer to the tree to check
 * @val: value to check against
 *
 * Return: 1 if true, 0 if false
 */
int is_less_than(const binary_tree_t *tree, int val)
{
	int left, right;

	if (tree == NULL)
		return (1);
	if (tree->n < val)
	{
		left = is_less_than(tree->left, val);
		right = is_less_than(tree->right, val);
		if (left && right)
			return (1);
	}
	return (0);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid binary search tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (is_less_than(tree->left, tree->n) && is_greater_than(tree->right, tree->n))
	{
		if (!tree->left || binary_tree_is_bst(tree->left))
		{
			if (!tree->right || binary_tree_is_bst(tree->right))
				return (1);
		}
	}
	return (0);
}
