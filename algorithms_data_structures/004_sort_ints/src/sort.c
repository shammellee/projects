/*
This program does an in-place sort on a list made up of the integers zero, one,
or two.

[2, 0, 2, 1, 0, 1] -> [0, 0, 1, 1, 2, 2]
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int nums[] = {2, 0, 2, 1, 0, 1};

  int counts[3] = {0};
  int numsize   = (int) sizeof(nums)/sizeof(nums[0]);
  int countsize = (int) sizeof(counts)/sizeof(counts[0]);
  int index     = 0;

  for(int i = 0; i < numsize; i++)
  {
    counts[nums[i]]++;
  }

  for(int i = 0; i < countsize; i++)
  {
    int _c = counts[i];

    if(0 == _c) continue;

    for(int j = 0; j < _c; j++, index++)
    {
      nums[index] = i;
    }
  }

  for(int i = 0; i < numsize; i++)
  {
    printf("%d ", nums[i]);
  }

  return EXIT_SUCCESS;
}

