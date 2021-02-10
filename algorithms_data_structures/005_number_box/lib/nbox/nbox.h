#ifndef __NBOX_H__
#define __NBOX_H__

#include <stdio.h>
#include <stdlib.h>

typedef int ** nbox;

nbox box_create(int n);
void box_clear(int n, nbox box);
void box_fill(int n, nbox box);
void box_print(int n, nbox box);
void box_destroy(int n, nbox box);
int box_get_size(int n);

#endif // __NBOX_H__

