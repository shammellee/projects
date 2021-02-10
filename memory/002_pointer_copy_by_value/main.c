#include <stdio.h>    // printf, fprintf(), sprintf(), scanf(), sscanf(), fgets(), stdin, stdout, stderr
#include <stdlib.h>   // General utilities: malloc(), calloc(), realloc(), free(), atoi(), exit(), EXIT_SUCCESS, EXIT_FAILURE

void test1(int ** _p_number);
void test2(int * _p_number);

int main(int argc, char** argv)
{
  int ** my_value_1 = malloc(sizeof(int *));
  int * my_value_2  = (int *) calloc(1, sizeof(int));

  *my_value_1 = my_value_2;

  printf("** before: %p: %d\n", *my_value_1, **my_value_1);
  test1(my_value_1);
  printf("** after: %p: %d\n", *my_value_1, **my_value_1);

  *my_value_2 = 0;

  printf("* before: %p: %d\n", my_value_2, *my_value_2);
  test2(my_value_2);
  printf("* after: %p: %d\n", my_value_2, *my_value_2);

  free(my_value_1);
  free(my_value_2);
  my_value_1 = NULL;
  my_value_2 = NULL;

  return EXIT_SUCCESS;
}

void test1(int ** _pp_number)
{
  int * my_value = (int *) calloc(1, sizeof(int));

  *my_value = 111;

  *_pp_number = my_value;

  free(my_value);
  my_value = NULL;
}

void test2(int * _p_number)
{
  *_p_number = 222;
}

