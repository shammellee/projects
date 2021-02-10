#include <stdio.h>

#include "link.h"

int main(void)
{
  LinkedList * l = ll_get();

  ll_add_node(l, "Jaden");
  ll_add_node(l, "Gus");
  ll_add_node(l, "Shammel");
  ll_add_node(l, "Sabrina");
  ll_add_node(l, "Lexi");

  ll_remove_node(l);  // Remove first node
  ll_remove_node(l);  // Remove next node
  ll_remove(l);       // Remove remaining nodes and linked list

  return 0;
}

