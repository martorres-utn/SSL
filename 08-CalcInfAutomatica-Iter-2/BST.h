#pragma once

#include <stdbool.h>

//BST : binary search tree
typedef struct BSTDataStruct BSTData;
struct BSTDataStruct
{
	int key;
	int value;
};

typedef struct BSTNodeStruct BSTNode;
struct BSTNodeStruct
{
	BSTNode *left;
	BSTNode *right;
	BSTData data;
};

BSTNode * BST_Insert(BSTNode **root, int key, int value);
void BST_Remove(BSTNode **root, BSTNode **parent, BSTNode *child);
void BST_RemoveAll(BSTNode *root);
BSTNode * BST_FindChild(BSTNode *root, int key);
BSTNode * BST_FindChildAndParent(BSTNode **currentNode, int key, BSTNode **parentNode);
void BST_Print(BSTNode *root);