#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BST.h"

BSTNode * BST_CreateNewNode(int key, int value, BSTNode *parent, BSTNode *left, BSTNode *right);

BSTNode * BST_Insert(BSTNode **root, int key, int value)
{
    if((*root) == NULL)
    {
        return ((*root) = BST_CreateNewNode(key, value, NULL, NULL, NULL));
    }
    
    if(key < (*root)->data.key)
    {
        BSTNode *leftLeaf = BST_Insert(&(*root)->left, key, value);
        if((*root)->left == NULL)
			(*root)->left = leftLeaf;
        return leftLeaf;
    }

    if(key > (*root)->data.key)
    {
        BSTNode *rightLeaf = BST_Insert(&(*root)->right, key, value);
		if((*root)->right == NULL)
        	(*root)->right = rightLeaf;
        return rightLeaf;
    }

    return NULL;
}

void BST_Remove(BSTNode **root, BSTNode **parent, BSTNode *child)
{
	if(child == NULL)
		return;

	if(child->left == NULL && child->right == NULL) //leaf
	{
		if((*parent) == NULL)
		{
			if(child == (*root)) //root case
				(*root) = NULL;
		}
		else
		{
			if((*parent)->left == child)
				(*parent)->left = NULL;
			else if((*parent)->right == child)
				(*parent)->right = NULL;
		}
		printf("freed %p child (leaf) with key %i value %i\n", child, child->data.key, child->data.value);
		free(child);
		return;
	}
	else if(child->left == NULL && child->right != NULL)//1 child at right
	{
		if((*parent) == NULL)
		{
			//root case
			//child->data = child->right->data; //copy r descendant value to target value //redundant value in descendant
			//BST_Remove(&child, child->right);

			if(child == (*root)) //root case
				(*root) = child->right;
			free(child);
		}
		else
		{
			if((*parent)->left == child)
				(*parent)->left = child->right;
			else if((*parent)->right == child)
				(*parent)->right = child->right;
			printf("freed %p child (with right children) with key %i value %i\n", child, child->data.key, child->data.value);
			free(child);
			return;
		}

	}
	else if(child->left != NULL && child->right == NULL) //1 child at left
	{
		if((*parent) == NULL)
		{
			if(child == (*root)) //root case
				(*root) = child->left;
			free(child);
		}
		else
		{
			if((*parent)->left == child)
				(*parent)->left = child->left;
			else if((*parent)->right == child)
				(*parent)->right = child->left;
			printf("freed %p child (with left children) with key %i value %i\n", child, child->data.key, child->data.value);
			free(child);
			return;
		}
	}
	else if(child->left != NULL && child->right != NULL)//2 childs
	{
		child->data = child->right->data; //copy r descendant value to target value //redundant value in descendant
		BST_Remove(&(*root), &child, child->right);
	}
}

BSTNode * BST_FindChild(BSTNode *root, int key)
{
	//finds a node in the tree according to a key
	if(root == NULL)
		return NULL;
	else if(key == root->data.key)
		return root;
	else if(key < root->data.key && root->left != NULL)
		return BST_FindChild(root->left, key);
	else if(key > root->data.key && root->right != NULL)
		return BST_FindChild(root->right, key);
	return NULL;
}

BSTNode * BST_FindChildAndParent(BSTNode **currentNode, int key, BSTNode **parentNode)
{
	//finds a node in the tree according to a key
	if((*currentNode) == NULL)
		return NULL;
	else if(key == (*currentNode)->data.key)
	{
		return (*currentNode);
	}
	else if(key < (*currentNode)->data.key && (*currentNode)->left != NULL)
	{
		BSTNode *found = BST_FindChildAndParent(&(*currentNode)->left, key, &(*parentNode));
		if(found != NULL && (*parentNode) == NULL)
			(*parentNode) = (*currentNode);
		return found;
	}
	else if(key > (*currentNode)->data.key && (*currentNode)->right != NULL)
	{
		BSTNode *found = BST_FindChildAndParent(&(*currentNode)->right, key, &(*parentNode));
		if(found != NULL && (*parentNode) == NULL)
			(*parentNode) = (*currentNode);
		return found;
	}
	return NULL;
}

void BST_Print(BSTNode *root)
{
	if(root != NULL)
	{
		BST_Print(root->left);
		BST_Print(root->right);
		printf("p[%p] k[%i] v[%i]\n", root, root->data.key, root->data.value);
	}
}

void BST_RemoveAll(BSTNode *root)
{
	if(root != NULL)
	{
		BST_RemoveAll(root->left);
		BST_RemoveAll(root->right);
		printf("removeall - p[%p] k[%i] v[%i]\n", root, root->data.key, root->data.value);
		root->left = NULL;
		root->right = NULL;
		free(root);
	}
}

BSTNode * BST_CreateNewNode(int key, int value, BSTNode *parent, BSTNode *left, BSTNode *right)
{
	BSTNode *newNode = (BSTNode*)malloc(sizeof(BSTNode)); //crate new one
    newNode->data.key = key;
	newNode->data.value = value;
	newNode->left = left;
	newNode->right = right;
	printf("created %p with key %i and value %i\n", newNode, key, value);
	return newNode;
}