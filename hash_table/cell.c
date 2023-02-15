#include <stdlib.h>
#include <stdio.h>
#include "cell.h"

CELL cell_init() {
    return (CELL)NULL;
}

CELL cell_create(char * cell_value) {
    CELL cell = (CELL)malloc(sizeof(Cell));
    strcpy(cell->key, cell_value);
    cell->prev = cell_init();
    cell->next = cell_init();
    return cell;
}

void cell_print(CELL cell) {
    printf("%s ", cell->key);
}