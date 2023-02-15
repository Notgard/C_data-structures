#include <stdio.h>
#include "cell.h"

cell_t * cell_init() {
    return (cell_t *)NULL;
}

cell_t * cell_create(int value) {
    cell_t * cell = (cell_t *)malloc(sizeof(cell_t));
    cell->key = value;
    cell->prev = cell_init();
    cell->next = cell_init();
    return cell;
}

void cell_print(cell_t * cell) {
    printf("%d ", cell->key);
}