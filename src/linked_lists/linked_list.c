#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
  int data;
  struct Node* next;
};

// Function to print the Linked List
void printList(struct Node* node)
{
  while (node != NULL) {
    printf(" %d ", node->data);
    node = node->next;
  }
  printf("\n");
}


// Function to return new nodes
struct Node *create_new_node(int value)
{
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}


// Insert new node at the list's head
struct Node *insert_at_head(struct Node **head, struct Node *node_to_insert)
{
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}


// Insert the new node after an existent node
void insert_after_node(struct Node *existent_node, struct Node *newnode)
{
    newnode->next = existent_node->next;
    existent_node->next = newnode;
}


// Finding a node
struct Node *find_node(struct Node *head, int value)
{
    struct Node *tmp = head;
    while (tmp != NULL) {
        if (tmp->data == value) return tmp;
        tmp = tmp->next;
    }
    return NULL;
}


int main()
{
  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;

  struct Node* new_node = create_new_node(32);

  head = (struct Node*) malloc(sizeof(struct Node));
  second = (struct Node*) malloc(sizeof(struct Node));
  third = (struct Node*) malloc(sizeof(struct Node));


  head->data = 1;
  head->next = third;

  for (int i = 0; i < 25; i++) {
      struct Node* tmp = create_new_node(i);
      insert_at_head(&head, tmp);
  }
  second->data = 2;
  second->next = new_node;

  third->data = 3;
  third->next = second;

  struct Node *tmp1 = find_node(head, 32);
  printf("Number %d found\n", tmp1->data);

  printList(head);

  return 0;
}
