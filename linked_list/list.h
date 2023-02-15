#include "cell.h"
#include "utils.h"

/// @brief List structure for a double liked list
typedef struct {
    cell_t * head;
    size_t size;
} list_t;

void list_init(list_t **);

list_t * list_create();

void list_print(list_t*);

void list_insert(list_t*, cell_t *);

void list_delete(list_t*, cell_t *);

cell_t * list_search(list_t*, int);

void list_free(list_t*);