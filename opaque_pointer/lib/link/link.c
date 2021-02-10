#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "link.h"

static void ll_deallocate(void * _object);

typedef struct _node
{
  Data data;
  struct _node * next;
} Node;

struct _linked_list
{
  Node * head;
};

LinkedList * ll_get()
{
  LinkedList * _l = (LinkedList *) malloc(sizeof(LinkedList));

  _l->head = NULL;

  return _l;
}

void ll_remove(LinkedList * _l)
{
  while(_l->head != NULL)
  {
    ll_remove_node(_l);
  }

  ll_deallocate(_l);
}

void ll_add_node(LinkedList * const _l, Data _d)
{
  if(0 == strcmp("", _d)) return;

  Node * _n = (Node *) malloc(sizeof(Node));
  _n->data  = _d;

  if(_l->head == NULL)
  {
    _l->head = _n;
    _n->next = NULL;
  }
  else
  {
    // Insert new node before first node (unshift, prepend)
    _n->next = _l->head;
    _l->head = _n;
  }

  printf("Adding %s\n", _d);
}

Data ll_remove_node(LinkedList * const _l)
{
  if(_l->head == NULL) return NULL;

  Node * _n = _l->head;
  Data _d   = _n->data;
  _l->head  = _l->head->next;

  printf("Removing %s\n", _d);
  ll_deallocate(_n);

  return _d;
}

static void ll_deallocate(void * _object)
{
  if(NULL != _object)
  {
    free(_object);
    _object = NULL;
  }
}

