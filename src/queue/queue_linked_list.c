#include <stdio.h>
#include <stdlib.h>

struct QNode {
  int key;
  struct QNode* next;
};


struct Queue {
  struct QNode *head, *tail;
};


struct QNode* new_node(int k)
{
  struct QNode* temp = (struct QNode*) malloc(sizeof(struct QNode));
  temp->key = k;
  temp->next = NULL;
  return temp;
}


struct Queue* create_queue()
{
  struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
  queue->head = queue->tail = NULL;
  return queue;
}
