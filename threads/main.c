#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * entry_point(void * value)
{
  int * num = (int *) value;

  printf("the value of value is %d\n", *num);
  printf("hello from the second thread :)\n");

  return NULL;
}

int main(int argc, char **argv)
{
  pthread_t thread;
  int num = 123;

  printf("hello from the first thread :D\n");

  pthread_create(&thread, NULL, entry_point, &num);
  pthread_join(thread, NULL);

  return EXIT_SUCCESS;
}

