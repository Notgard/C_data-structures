#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_SIZE 256+1

#ifndef __CELL_H__
#define __CELL_H__

/// @brief Node structure for a double linked list
typedef struct cell_t {
    char key[MAX_SIZE];
    struct cell_t * prev;
    struct cell_t * next;
} Cell, *CELL;

CELL cell_init();
CELL cell_create(char *);
void cell_print(CELL);

#endif //__CELL_H__