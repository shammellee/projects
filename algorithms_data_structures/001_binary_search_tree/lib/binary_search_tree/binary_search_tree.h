#ifndef BST_H
#define BST_H
#include <stdlib.h>   // malloc, calloc, realloc, free, atoi, EXIT_SUCCESS, EXIT_FAILURE
#include <stdbool.h>  // bool, true, false

typedef struct BSTNode
{
  int value;
  struct BSTNode* left;
  struct BSTNode* right;
} BSTNode;

BSTNode* bst_create(int value);
BSTNode* bst_find(BSTNode* root, int value);
bool bst_search(BSTNode* root, int value);
void bst_insert(BSTNode** root, int value);
void bst_print(BSTNode* root);

#endif // BST_H

