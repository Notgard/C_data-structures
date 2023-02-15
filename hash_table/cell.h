#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#ifndef __CELL_H__
#define __CELL_H__

/// @brief Node structure for a double linked list
typedef struct cell_t {
    int32_t key;
    struct cell_t * prev;
    struct cell_t * next;
} Cell, *CELL;

CELL cell_init();
CELL cell_create(int);
void cell_print(CELL);

#endif __CELL_H__ //__CELL_H__