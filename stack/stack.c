#include "stack.h"

stack_t* stack_create(size_t init_capacity)
{
    stack_t* stack = malloc(sizeof(stack_t));

    stack->size = 0;
    stack->capacity = init_capacity;
    stack->data = malloc(stack->capacity * sizeof(int));

    return stack;
}

/**
 * 1 if stack is empty, 0 otherwise
*/
int is_empty(stack_t * stack) {
    return stack->size == 0;
}

int is_full(stack_t * stack) {
    return stack->size == stack->capacity;
}

void stack_push(stack_t* stack, int elem)
{
    if (++stack->size > stack->capacity)
    {
        if (!stack->capacity) stack->capacity = 1;
        stack->capacity *= 2;
        stack->data = realloc(stack->data, stack->capacity * sizeof(int));
    }

    stack->data[stack->size - 1] = elem;
}

int stack_pop(stack_t* stack)
{
    if (stack->size > 0)
    {
        stack->size--;
        return stack->data[stack->size];
    }
    return 0;
}

int stack_peek(stack_t* stack)
{
    if (stack->size > 0)
        return stack->data[stack->size - 1];
    else
        return -1;
}

void print_stack(stack_t * stack) {
    int i;
    printf("Stack contents: \n[ ");
    for(i = 0; i < stack->size; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("]\n");
}

void stack_swap(stack_t * stack, int offset) {
    int top = stack->data[stack->size - 1];
    int bottom = stack->data[stack->size - offset];
    stack->data[stack->size - 1] = bottom;
    stack->data[stack->size - offset] = top;
}

void stack_delete(stack_t* stack)
{
    free(stack->data);
    free(stack);
}
