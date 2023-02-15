#include "node.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256+1

#ifndef __TREE_H__
#define __TREE_H__

//struct node_t;
typedef struct tree_t {
    struct node_t * root;
} Bst, *BST;

BST bst_init();
void bst_free(BST);
void bst_insert(struct node_t *, BST);
void bst_print(BST, int);
struct node_t * bst_search(BST, char[MAX_SIZE]);
int bst_count_nodes(BST);

#endif //__TREE_H__