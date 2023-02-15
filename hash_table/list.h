#include "cell.h"
#include "utils.h"

#ifndef __LIST_H__
#define __LIST_H__

typedef struct list_t {
    // points to the first element in the list
    CELL head;
    size_t size;
} List, * LIST;

void list_init(LIST *);

LIST list_create();

void list_print(LIST);

void list_insert(LIST, CELL);

void list_delete(LIST, CELL);

CELL list_search(LIST, int);

void list_free(LIST);

int list_count(LIST);

#endif __LIST_H__ // __LIST_H__