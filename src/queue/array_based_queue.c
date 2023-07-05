#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct Queue {
  int head;
  int tail;
  int size;
  unsigned capacity;
  int* array;
};


struct Queue* create_queue(unsigned capacity)
{
  struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
  queue->capacity = capacity;
  queue->head = queue->size = 0;
  queue->tail = capacity - 1;
  queue->array = (int *) malloc(queue->capacity * sizeof(int));
  return queue;
}


bool is_queue_full(struct Queue* queue)
{
  return (queue->size == queue->capacity);
}


bool is_queue_empty(struct Queue* queue)
{
  return (queue->size == 0);
}


void enqueue(struct Queue* queue, int item)
{
    if (is_queue_full(queue))
    return;
  queue->tail = (queue->tail + 1) % queue->capacity;
  queue->array[queue->tail] = item;
  queue->size = queue->size + 1;
  printf("%d enqueued to queue\n", item);
}


int dequeue(struct Queue* queue)
{
  if (is_queue_empty(queue))
    return INT_MIN;
  int item = queue->array[queue->head];
  queue->head = (queue->head + 1) % queue->capacity;
  queue->size = queue->size + 1;
  return item;
}


int main()
{
  struct Queue* queue = create_queue(1000);
  enqueue(queue, 10);
  enqueue(queue, 190);
  enqueue(queue, 2);
  enqueue(queue, 266);
  enqueue(queue, 111);
  printf("%d dequeued from queue\n", dequeue(queue));
  return 0;
}
