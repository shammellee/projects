#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

char * people[] = {
  "alpha"
  ,"bravo"
  ,"charlie"
  ,"delta"
  ,"echo"
  ,"foxtrot"
  ,"golf"
  ,"hotel"
  ,"india"
  ,"kilo"
  ,"lima"
  ,"mike"
};

int main(void)
{
  graph_t * g   = graph_new();
  int num_items = (int) (sizeof(people)/sizeof(people[0]));

  for(int i = 0; i < num_items; i++)
  {
    graph_add(g, people[i]);
  }

  graph_connect(g, 10, 1);
  graph_connect(g, 10, 2);
  graph_connect(g, 10, 0);

  graph_destroy(g);

  return EXIT_SUCCESS;
}

