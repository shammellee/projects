#include <stdlib.h>  // malloc, calloc, realloc, free
#include <string.h>  // strcpy, strcat
#include <stdio.h>   // printf

void fail(void) {printf("memory could not be allocated"); exit(EXIT_FAILURE);}

int main(void)
{
  char * message = malloc(6 * sizeof(char));

  if(NULL == message) fail();

  strcpy(message, "Hello");

  int * numbers = calloc(2, sizeof(int));

  if(NULL == numbers) fail();

  numbers[0] = 1;
  numbers[1] = 2;

  message = realloc(message, 14 * sizeof(char));

  if(NULL == message) fail();

  strcat(message, ", World!");

  printf("message: %s\n", message);
  printf("numbers: %d, %d\n", numbers[0], numbers[1]);

  free(message);
  free(numbers);

  return EXIT_SUCCESS;
}

