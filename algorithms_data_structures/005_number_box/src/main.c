#include <stdio.h>
#include <stdlib.h>

#include "nbox.h"

int main() 
{
    const unsigned int INPUT_LENGTH_MAX = 3;
    const unsigned int INPUT_MIN        = 2;
    const unsigned int INPUT_MAX        = 9;

    unsigned int n = 0;
    char input[INPUT_LENGTH_MAX];

    while(1)
    {
      printf("Enter box size (%d-%d): ", INPUT_MIN, INPUT_MAX);
      fgets(input, INPUT_LENGTH_MAX, stdin);
      sscanf(input, "%u", &n);

      if((n < INPUT_MIN) || (n > INPUT_MAX))
      {
        printf("\x1b[33mEnter a number between %u and %u.\x1b[0m\n", INPUT_MIN, INPUT_MAX);
      }
      else
      {
        nbox box = box_create(n);
        box_print(n, box);
        box_destroy(n, box);
      }
      fflush(stdin);
    }

    return EXIT_SUCCESS;
}

