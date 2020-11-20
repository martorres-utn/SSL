#include <stdio.h>
#include <stdlib.h>
#include "VariableManager.h"
#include "BST.h" //BSTNode BST_FindChild BST_Insert BST_RemoveAll

static BSTNode *root = NULL; //binary search tree

static int VariableManager_Hash(const char * key)
{
    int hash = 0;
    for(size_t pos = 0; key[pos] != '\0' ; pos++)
        hash += key[pos] * (pos + 1); //TODO: revisar colisiones posibles y cómo resolver.
    return hash;
}

bool VariableManager_GetValue(const char * varName, int *varValue)
{
    int hash = VariableManager_Hash(varName);
    
    BSTNode *found = BST_FindChild(root, hash);

    if(found != NULL)
    {
        (*varValue) = (*found).data.value;
        return true;
    }
        
    return false;
}

void VariableManager_SetValue(const char * varName, int  varValue)
{
    int hash = VariableManager_Hash(varName);
    
    BSTNode *f = BST_FindChild(root, hash);

    if(f != NULL)
        (*f).data.value = varValue;
    else
        BST_Insert(&root, hash, varValue);
}

void VariableManager_RemoveAll()
{
    BST_RemoveAll(root);
}