#include <stdio.h>
#include <stdlib.h>

#include "prime.h"

int main(int argc, char * argv[])
{
  if(1 == argc)
  {
    printf("Usage: %s <integer > 2>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int n = atoi(argv[1]);

  if(n <= 2)
  {
    printf("n must be > 2\n");

    return EXIT_FAILURE;
  }

  int * primes = calloc((size_t) n, (size_t) sizeof(int));

  get_primes(n, primes);

  if(*primes == 0)
  {
    printf("No primes\n");

    return EXIT_SUCCESS;
  }

  printf("Primes from 2 to %d\n", n);

  while(*primes != 0)
  {
    printf("%d ", *primes);
    primes++;
  }

  printf("\b");

  return EXIT_SUCCESS;
}
