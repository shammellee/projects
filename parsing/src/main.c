#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* const unsigned int BUFFER_SIZE = 64; */

int main(int arg_c, char ** argv)
{
  char input[] = "Rey, Luke, Leia: Anakin, Padme";
  int i = 0;

  char * token = strtok(input, "-");

  printf("%d:[%p] --- %s\n", i, token, token);

  token = strtok(input, ",:");

  printf("%d:[%p] --- %s\n", i, token, token);

  while(token != NULL)
  {
    token = strtok(NULL, ",: ");  // NULL == remember position in string

    printf("%d:[%p] --- %s\n", i, token, token);
  }

  return EXIT_SUCCESS;
}

