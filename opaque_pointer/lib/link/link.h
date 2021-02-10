#ifndef LINKED_LIST_H
#define LINKED_LIST_H
typedef void * Data;
typedef struct _linked_list LinkedList;

LinkedList * ll_get();
void ll_remove(LinkedList * _l);
void ll_add_node(LinkedList * const _l, Data _d);
Data ll_remove_node(LinkedList * const _l);
#endif // LINKED_LIST_H

