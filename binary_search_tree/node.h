#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256+1

#ifndef __NODE_H__
#define __NODE_H__

struct tree_t;
typedef struct node_t {
    char word[MAX_SIZE];
    struct tree_t * left;
    struct tree_t * right;
    struct tree_t * father;

} Node, *NODE;


NODE node_init(char * word);
void node_free(NODE);

#endif // __NODE_H__
