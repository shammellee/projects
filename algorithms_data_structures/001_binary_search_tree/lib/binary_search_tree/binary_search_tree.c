#include <stdio.h>

#include "binary_search_tree.h"

BSTNode* bst_create(int value)
{
  BSTNode* node = malloc(sizeof(BSTNode));

  node->value = value;
  node->left  = NULL;
  node->right = NULL;

  return node;
}

BSTNode* bst_find(BSTNode* root, int value)
{
  if(NULL == root) return NULL;
  else if(value == root->value) return root;
  else if(value < root->value) return bst_find(root->left, value);
  else return bst_find(root->right, value);
}

bool bst_search(BSTNode* root, int value)
{
  if(NULL == root) return false;
  else if(value == root->value) return true;
  else if(value < root->value) return bst_search(root->left, value);
  else return bst_search(root->right, value);
}

void bst_insert(BSTNode** root, int value)
{
  if(NULL == *root) *root = bst_create(value);
  else if(value <= (*root)->value) bst_insert(&(*root)->left, value);
  else bst_insert(&(*root)->right, value);
}

void bst_print(BSTNode* node)
{
  if(NULL != node)
  {
    printf("%d\n", node->value);
  }
  else
  {
    printf("NULL\n");
  }
}

