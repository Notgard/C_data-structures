#ifndef _STACK_H_
#define _STACK_H_

#include "stdlib.h"
#include <stdio.h>

typedef struct
{
    int* data;
    size_t size;
    size_t capacity;
} stack_t;

stack_t* stack_create(size_t init_capacity);

void stack_push(stack_t* stack, int elem);

int stack_pop(stack_t* stack);

int stack_peek(stack_t* stack);

int is_empty(stack_t * stack);

int is_full(stack_t * stack);

void print_stack(stack_t * stack);

void stack_swap(stack_t * stack, int offset);

void stack_delete(stack_t* stack);

#endif
