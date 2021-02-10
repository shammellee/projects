#include <stdlib.h>   // malloc, calloc, realloc, free, atoi, EXIT_SUCCESS, EXIT_FAILURE
#include <string.h>   // strcmp, strcpy, strcat
#include <stdbool.h>  // bool, true, false
#include <stdio.h>    // printf, fprintf, sprintf, scanf, fgets, stdin, stdout, stderr

#include "binary_search_tree.h"

const int INPUT_LENGTH_MAX = 11;

int main(void)
{
  BSTNode* root = NULL;
  BSTNode* found;
  char input[INPUT_LENGTH_MAX];
  int number;

  bst_insert(&root, 15);
  bst_insert(&root, 10);
  bst_insert(&root, 20);
  bst_insert(&root, 25);
  bst_insert(&root, 8);
  bst_insert(&root, 12);

  while(1)
  {
    printf("Enter a number to search for (q/x to exit): ");

    fgets(input, INPUT_LENGTH_MAX, stdin);

    if('q' == *input || 'x' == *input)
    {
      printf("Exiting...\n");
      break;
    }

    sscanf(input, "%d", &number);

    if(true == bst_search(root, number))
    {
      found = bst_find(root, number);

      printf("\e[32mFound %d\e[0m\n", number);

      if(NULL != found)
      {
        printf("left: ");
        bst_print(found->left);
        printf("right: ");
        bst_print(found->right);
      }
    }
    else
    {
      printf("\e[31m%d not found\e[0m\n", number);
    }
  }

  return EXIT_SUCCESS;
}

