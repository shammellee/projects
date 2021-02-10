#ifndef GRAPH_H
#define GRAPH_H

typedef enum _graph_error {
  GRAPH_ERROR_NONE                = 1 << 0
  ,GRAPH_ERROR_ALLOCATING_GRAPH   = 1 << 1
  ,GRAPH_ERROR_ALLOCATING_CONNS   = 1 << 2
  ,GRAPH_ERROR_ALLOCATING_NODES   = 1 << 3
  ,GRAPH_ERROR_ELEMENT_EXISTS     = 1 << 4
  ,GRAPH_ERROR_REALLOCATING_NODES = 1 << 5
  ,GRAPH_ERROR_REALLOCATING_CONNS = 1 << 6
  ,GRAPH_ERROR_NODE_NOT_EXISTS    = 1 << 7
  ,GRAPH_ERROR_CONNECT_SELF       = 1 << 8
} graph_error_t;

typedef struct _graph graph_t;

graph_t *
graph_new();

int
graph_add(graph_t * const graph, void * const data);

int
graph_connect(graph_t * const graph, const int src_id, const int dest_id);

int
graph_disconnect(graph_t * graph, const int src_id, const int dest_id);

int
graph_is_connected(graph_t * const graph, const int src_id, const int dest_id);

void *
graph_find(graph_t * const graph, const int id);

int
graph_remove(graph_t * const graph, const int id);

void
graph_print(graph_t * const graph);

void
graph_destroy(graph_t * graph);

graph_error_t
graph_get_error(graph_t * const _g);

#endif  // GRAPH_H

