#include <stdio.h>
#include "list.h"

/// @brief Initilises and allocates memory to a linked list passed by reference 
/// @param list the defined linked list
void list_init(LIST * list) {
    *list = NULL;
    *list = (LIST)malloc(sizeof(List));
    (*list)->size = 0;
    if(*list == NULL) {
        printf("\nERROR: Memory allocation did not complete successfully!"); 
    }
}

/// @brief Allocates memory and returns a linked list
/// @return the linked list
LIST list_create() {
    LIST l = (LIST)malloc(sizeof(List));
    l->size = 0;
    l->head = cell_init();
    return l;
}

/// @brief Prints the given linked list
/// @param list the linked list
void list_print(LIST list) {
    CELL c;
    printf("[ ");
    for(c = list->head; c != NULL; c = c->next) {
        cell_print(c);
    }
    printf("]\n");
}

/// @brief This insert moves the inserted cell as the head, and the head as the next cell (FILO)
/// @param list the linked list
/// @param cell the node to insert
void list_insert(LIST list, CELL cell) {
    cell->next = list->head;
    //if list not empty, puts inserted cell as before the head
    if(list->head != NULL)
        list->head->prev = cell;
    list->head = cell;
    cell->prev = NULL;
    list->size++;
}

/// @brief // Deletes element from linked list by re-ordering the prev and next attributes
/// @param list will set the head as cell->next if the deleted cell is the head (no predecessors)
/// @param cell the cell to be deleted, will be modified to change the orders of the predecossor and successor
void list_delete(LIST list, CELL cell) {
    if(cell == cell_init()) {
        error("Cell not found in linked list!\n");
        return ; // if cell doesnt exist, send error and exit function
    }
    if(cell->prev != NULL) //if cell isnt head, rechain the double linked list
        cell->prev->next = cell->next;
    else //if cell is the head, set head as the next element after cell
        list->head = cell->next;
    if(cell->next != NULL) //if cell isnt last element, rechain double linked list
        cell->next->prev = cell->prev;
    //if cell was last element, prev next would be set as NULL in the first if
    // we would only care if the list had a tail attribute
    list->size--;
}

/// @brief Returns the cell if found, else NULL
/// @param list the linked list to search
/// @param value value to search in list
/// @return 
CELL list_search(LIST list, char * value) {
    CELL c = cell_init();
    for(c = list->head; c != NULL && strcmp(c->key, value); c = c->next);
    return c;
}

/// @brief Frees linked list from memory
/// @param list the linked list to free
void list_free(LIST list) {
    if(list != NULL) {
        for(CELL c = list->head; c != NULL; c = c->next) {
            free(c);
        }
        free(list);
    }
}

/// @brief Counts the amount of items in a linked list
/// @param list 
/// @return total amount of items in a list
int list_count(LIST list) {
    int count = 0;
    if(list == (LIST)NULL) return count;
    for(CELL c = list->head; c != NULL; c = c->next, count++);
    return count;
}