#include <stdio.h>
#include <string.h>

#include "hash_table.h"

int main()
{
  ht_hash_table * ht = ht_new();
  ht_del_hash_table(ht);
}

