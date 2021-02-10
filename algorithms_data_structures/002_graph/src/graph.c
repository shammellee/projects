#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

#define INITIAL_CONNECTION_SIZE 8

static const int NODE_MAX_SIZE_INITIAL = 8;

typedef struct _graph_edge graph_edge_t;

typedef struct _graph_node
{
  void * data;
} graph_node_t;

typedef struct _graph_node_ref
{
  int                      id;
  struct _graph_node_ref * next;
} graph_node_ref_t;

struct _graph
{
  int                 max_nodes;
  int                 next_id;
  graph_node_t **     nodes;
  graph_node_ref_t ** connections;
  graph_error_t       error;
};

static graph_node_ref_t *
graph_node_ref_new()
{
  printf("new ref\n");
  graph_node_ref_t * _r = (graph_node_ref_t *) malloc(sizeof(graph_node_ref_t));

  _r->id   = -1;
  _r->next = NULL;

  return _r;
}

static int
graph_tune(graph_t * _g);

graph_t *
graph_new()
{
  graph_t * _g    = (graph_t *) malloc(sizeof(graph_t));

  _g->max_nodes   = NODE_MAX_SIZE_INITIAL;
  _g->next_id     = 0;
  _g->nodes       = (graph_node_t **) malloc(_g->max_nodes * sizeof(graph_node_t *));
  _g->connections = (graph_node_ref_t **) malloc(_g->max_nodes * sizeof(graph_node_ref_t *));
  _g->error       = GRAPH_ERROR_NONE;

  if(!_g)
  {
    return NULL;
  }

  if(!_g->connections)
  {
    _g->error = GRAPH_ERROR_ALLOCATING_CONNS;

    return NULL;
  }

  if(!_g->nodes)
  {
    _g->error = GRAPH_ERROR_ALLOCATING_NODES;

    return NULL;
  }

  for(int i = 0; i < _g->max_nodes; i++)
  {
    _g->nodes[i]       = NULL;
    _g->connections[i] = NULL;
  }

  return _g;
}

int
graph_add(graph_t * const _g, void * const _data)
{
  int *              _n    = &_g->next_id;
  graph_node_t *     _node = (graph_node_t *) malloc(sizeof(graph_node_t));
  graph_node_ref_t * _ref  = graph_node_ref_new();

  _node->data          = _data;
  _g->nodes[*_n]       = _node;
  _g->connections[*_n] = _ref;

  if(0 != graph_tune(_g))
  {
    return -1;
  }

  return _g->next_id++;
}

int
graph_node_exists(graph_t * const _g, const int _id)
{
  return (
    _id >= 0
    && _id < _g->next_id
    && _g->nodes[_id]
  );
}

static int
_graph_query_nodes_exist(graph_t * const _g, const int _src_id, const int _dest_id)
{
  return (
    graph_node_exists(_g, _src_id)
    && graph_node_exists(_g, _dest_id)
    && _g->connections[_src_id]
  );
}

int
graph_is_connected(graph_t * const _g, const int _src_id, const int _dest_id)
{
  if(!_graph_query_nodes_exist(_g, _src_id, _dest_id))
  {
    _g->error = GRAPH_ERROR_NODE_NOT_EXISTS;

    return -1;
  }

  graph_node_ref_t * _ref = _g->connections[_src_id];

  while(-1 != _ref->id)
  {
    if(_dest_id == _ref->id) return 1;

    _ref = _ref->next;
  }

  return 0;
}

void *
graph_find(graph_t * const _g, const int _id)
{
  if(!graph_node_exists(_g, _id)) return NULL;

  return _g->nodes[_id]->data;
}

int
graph_remove(graph_t * const _g, const int _id)
{
  (void) _g;
  (void) _id;

  return -1;
}

void
graph_print(graph_t * const _g)
{
  for(int i = 0; i < _g->next_id; i++)
  {
    if(_g->nodes[i])
    {
      char * _s = graph_find(_g, i);
      printf("%s: ", _s);

      if(_g->connections[i]->next)
      {
        graph_node_ref_t * _dest = _g->connections[i];

        while(_dest->next)
        {
          printf("%s ", graph_find(_g, _dest->id));

          _dest = _dest->next;
        }
      }
      printf("\n");
    }
  }
}

int
graph_connect(graph_t * const _g, const int _src_id, const int _dest_id)
{
  graph_node_ref_t * _dest = graph_node_ref_new();

  if(_src_id == _dest_id)
  {
    _g->error = GRAPH_ERROR_CONNECT_SELF;

    return -1;
  }

  if(!_graph_query_nodes_exist(_g, _src_id, _dest_id))
  {
    _g->error = GRAPH_ERROR_NODE_NOT_EXISTS;

    return -1;
  }

  _dest->id = _dest_id;

  if(
    -1 == _g->connections[_src_id]->id
    || _g->connections[_src_id]->id >= _dest_id
  )
  {
    _dest->next              = _g->connections[_src_id];
    _g->connections[_src_id] = _dest;

    return 0;
  }

  graph_node_ref_t * _prev, * _ref = _g->connections[_src_id];

  while(
    -1 != _ref->id
    && (_dest_id - _ref->id) > 0
  )
  {
    _prev = _ref;
    _ref  = _ref->next;
  }

  _dest->next = _ref;
  _prev->next = _dest;

  return 0;
}

int
graph_disconnect(graph_t * _g, const int _src_id, const int _dest_id)
{
  if(!graph_is_connected(_g, _src_id, _dest_id))
  {
    _g->error = GRAPH_ERROR_NODE_NOT_EXISTS;

    return -1;
  }

  graph_node_ref_t * _prev, * _curr = _g->connections[_src_id];

  while(-1 != _curr->next->id)
  {
    _prev = _curr;
    _curr = _curr->next;

    if(_dest_id == _curr->id)
    {
      _prev->next = _curr->next;

      return 0;
    }
  }

  _g->error = GRAPH_ERROR_NODE_NOT_EXISTS;

  return -1;
}

static void
graph_node_conn_destroy(graph_t * const _g, graph_node_ref_t * _r)
{
  if(!_r->next)
  {
    printf("%d\n", _r->id);
    /* printf("destroying %s\n", (char *) _g->nodes[_r->id]->data); */
    free(_r);

    return;
  }

  graph_node_conn_destroy(_g, _r->next);
}

void
graph_destroy(graph_t * _g)
{
  if(_g)
  {
    for(int i = 0; i < _g->max_nodes; i++)
    {
      printf("destroy %d\n", i);
      if(_g->connections[i])
      {
        graph_node_conn_destroy(_g, _g->connections[i]);
      }

      if(_g->nodes[i])
      {
        free(_g->nodes[i]);
      }
    }

    free(_g->nodes);
    free(_g->connections);
    free(_g);

    _g = NULL;
  }
}

static int
graph_tune(graph_t * _g)
{
  if(_g->next_id + 1 >= (_g->max_nodes / 2))
  {
    int _new_node_size
        ,_new_conn_size
        ,_offset = _g->max_nodes
        ;

    _g->max_nodes <<= 1;

    _new_node_size = _g->max_nodes * sizeof(graph_node_t *);
    _new_conn_size = _g->max_nodes * sizeof(graph_node_ref_t *);

    graph_node_t **     _nodes       = (graph_node_t **) realloc(_g->nodes, _new_node_size);
    graph_node_ref_t ** _connections = (graph_node_ref_t **) realloc(_g->connections, _new_conn_size);

    if(!_nodes)
    {
      _g->error = GRAPH_ERROR_REALLOCATING_NODES;

      return -1;
    }

    if(!_connections)
    {
      _g->error = GRAPH_ERROR_REALLOCATING_CONNS;

      return -1;
    }

    for(int i = _offset; i < _g->max_nodes; i++)
    {
      _nodes[i]       = NULL;
      _connections[i] = NULL;
    }

    _g->nodes       = _nodes;
    _g->connections = _connections;
  }

  return 0;
}

graph_error_t
graph_get_error(graph_t * const _g)
{
  return _g->error;
}

