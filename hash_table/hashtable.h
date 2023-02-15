#include <stdio.h>
#include <math.h>
#include "list.h"

#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

/**
 * @brief Structure for basic modulo based hashtable
 * 
 */
typedef struct hash_table_t {
    LIST * collision;
    size_t size;
    int hash; // for modulo
} HashTable, *HASHTABLE;

HASHTABLE hashtable_init(int);

void hashtable_free(HASHTABLE);

void hashtable_print(HASHTABLE);

unsigned long long encode_word(char *);

int hashtable_hash(HASHTABLE, unsigned long long);

void hashtable_insert(HASHTABLE, CELL);

CELL hashtable_search(HASHTABLE, char *);

void hashtable_delete(HASHTABLE, CELL);

int hashtable_count(HASHTABLE);

#endif __HASHTABLE_H__ //__HASHTABLE_H__