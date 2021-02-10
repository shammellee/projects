#include "nbox.h"

nbox box_create(int n)
{
  if(n < 1) n = 1;

  const int size = box_get_size(n);
  nbox box       = (nbox) calloc(size, sizeof(int *));

  for(int i = 0; i < size; i++)
  {
    box[i] = (int *) calloc(size, sizeof(int));
  }

  box_fill(n, box);

  return box;
}

void box_clear(int n, nbox box)
{
  if(NULL == box) return;

  const int size = box_get_size(n);

  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      if(NULL != box[i]) box[i][j] = 0;
    }
  }
}

void box_fill(int n, nbox box)
{
  if(NULL == box) return;

  const int size   = box_get_size(n);
  int repeat_cols  = size;
  int center       = size / 2;
  int repeat_start = 0;
  int repeat_end   = size - 1;

  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      if(j >= repeat_start && j <= repeat_end)
      {
        if(i <= center)
        {
          box[i][j] = n - i;
        }
        else {
          box[i][j] = i - center + 1;
        }
      }
      else
      {
        if(j <= center)
        {
          box[i][j] = n - j;
        }
        else {
          box[i][j] = n - ((size - 1) - j);
        }
      }
    }

    if(i < center)
    {
      repeat_cols -= 2;
      repeat_start++;
      repeat_end--;
    }
    else
    {
      repeat_cols += 2;
      repeat_start--;
      repeat_end++;
    }
  }
}

void box_print(int n, nbox box)
{
  if(NULL == box) return;

  const int size = box_get_size(n);

  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      printf("%d", box[i][j]);

      if(j < size - 1) printf(" ");
    }
    printf("\n");
  }
}

void box_destroy(int n, nbox box)
{
  if(NULL == box) return;

  const int size = box_get_size(n);

  for(int i = 0; i < size; i++)
  {
    free(box[i]);
    box[i] = NULL;
  }

  free(box);
  box = NULL;
}

int box_get_size(int n)
{
  return 2 * n - 1;
}

