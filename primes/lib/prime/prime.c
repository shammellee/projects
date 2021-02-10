#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "prime.h"

void get_primes(int n, int * p)
{
  if(n < 0)
  {
    return;
  }

  for(int i = 1; i < n; i++)
  {
    if(i == 1)
    {
      continue;
    }

    if(i == 2)
    {
      *p = i;
      p++;
      continue;
    }

    if(i > 2 && i % 2 == 0)
    {
      continue;
    }

    double m = floor(sqrt((double) i));

    for(int j = 3; j < 1 + m; j+=2)
    {
      if(i % j == 0)
      {
        goto end;
      }
    }

    *p = i;
    p++;
    end:
    continue;
  }
}

