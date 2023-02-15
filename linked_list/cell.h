#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/// @brief Node structure for a double linked list
typedef struct cell_t {
    int32_t key;
    struct cell_t * prev;
    struct cell_t * next;
} cell_t;

cell_t * cell_init();
cell_t * cell_create(int);
void cell_print(cell_t *);