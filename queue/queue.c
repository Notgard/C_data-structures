#include "queue.h"

#include "stdio.h"

Queue* queue_create()
{
    Queue* queue = malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

void queue_push(Queue* queue, int elem)
{
    QueueNode* node = malloc(sizeof(QueueNode));
    node->data = elem;
    node->ptr_next = NULL;

    if (!queue->size)
    {
        queue->front = node;
        queue->rear = node;
    }

    else
    {
        QueueNode* prev_rear = queue->rear;
        queue->rear = node;
        prev_rear->ptr_next = node;
    }

    queue->size++;
}

int queue_pop(Queue* queue)
{
    if (queue->size == 0) return 0;

    if (queue->size == 1)
    {
        int elem = queue->front->data;
        free(queue->front);
        queue->front = NULL;
        queue->rear = NULL;
        queue->size = 0;
        return elem;
    }

    // size > 1
    int elem = queue->front->data;
    QueueNode* prev_front = queue->front;
    queue->front = queue->front->ptr_next;
    queue->size--;
    free(prev_front);
    return elem;
}

void queue_print(Queue* queue)
{
    QueueNode* curr_node = queue->front;

    while (curr_node)
    {
        printf("%d ", curr_node->data);
        curr_node = curr_node->ptr_next;
    }
    printf("\n");
}

void queue_delete(Queue* queue)
{
    QueueNode* curr_node = queue->front;

    while (curr_node)
    {
        QueueNode* next_node = curr_node->ptr_next;
        free(curr_node);
        curr_node = next_node;
    }

    free(queue);
}
