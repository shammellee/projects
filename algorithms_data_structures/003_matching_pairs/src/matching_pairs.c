/*
pair_t * get_pair(const unsigned long _t)
On success, get_pair() searches the array `nums` and returns a pair_t type
consisting of `first` and `second` int members whose sum equals `_t`. If
no such numbers exist in `nums`, NULL is returned.

nums: [14, 13, 6, 7, 8, 10, 1, 2]
get_pair(10) -> [8, 2]
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <assert.h>

char * app_path = NULL;

int nums[] = { 14, 13, 6, 7, 8, 10, 1, 2 };

typedef struct
{
  int first, second;
} pair_t;

pair_t * get_pair(const unsigned long _t)
{
  const int SET_SIZE = (int) sizeof(nums)/sizeof(nums[0]);
  pair_t *  _p_p     = NULL;
  int *     _end_p   = nums + SET_SIZE;
  int *     _match_p;
  int       _second;

  for(int i = 0; i < SET_SIZE; i++)
  {
    int _first = nums[i];

    if(_first >= (int) _t) continue;

    _match_p = (nums + i) + 1;
    _second  = ((int) _t) - _first;

    while(_match_p != _end_p)
    {
      if(_second == *_match_p)
      {
        _p_p = (pair_t *) malloc(sizeof(pair_t));

        assert(_p_p);

        _p_p->first  = _first;
        _p_p->second = *_match_p;

        break;
      }

      _match_p++;
    }
  }

  return _p_p;
}

void usage()
{
  printf("Usage: %s [2...%lu]\n", app_path, ULONG_MAX);
}

int main(int argc, char** argv)
{
  app_path = argv[0];

  if(1 == argc)
  {
    usage();

    return EXIT_FAILURE;
  }

  if(!isdigit(argv[1][0]))
  {
    usage();

    return EXIT_FAILURE;
  }

  const unsigned long _t = strtoul(argv[1], NULL, 10);

  if(
   1 >= _t
   || errno == ERANGE
   )
  {
    usage();

    return EXIT_FAILURE;
  }

  pair_t * _p = get_pair(_t);

  if(!_p)
  {
    printf("No pairs found adding up to %lu\n", _t);
  }
  else
  {
    printf("first: %d, second: %d\n", _p->first, _p->second);
  }

  if(_p) free(_p);

  return EXIT_SUCCESS;
}


