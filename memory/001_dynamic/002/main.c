#include <stdio.h>
#include <stdlib.h>

#define ALPHA_COUNT 26

char * string_alloc(size_t size);
void fill_lowercase(char * string, size_t length);

int main(void)
{
  char * string = string_alloc(ALPHA_COUNT + 1);

  fill_lowercase(string, ALPHA_COUNT + 1);
  printf("%s\n", string);

  #ifndef LEAK
  free(string);
  string = NULL;
  #endif // LEAK

  return EXIT_SUCCESS;
}

char * string_alloc(size_t size)
{
  char * string = malloc(sizeof(char) * size);

  if(NULL == string)
  {
    fprintf(stderr, "Out of memory");
    exit(EXIT_FAILURE);
  }

  for(size_t i = 0; i < size; i++)
  {
    string[i] = '\0';
  }

  return string;
}

void fill_lowercase(char * string, size_t length)
{
  if(length > ALPHA_COUNT) length = ALPHA_COUNT + 1;

  for(size_t i = 0; i < length - 1; i++)
  {
    string[i] = 'a' + i;
  }

  string[length - 1] = '\0';
}

