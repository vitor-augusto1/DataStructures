#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Stack {
  int top;
  unsigned capacity;
  int* array;
};


struct Stack* create_new_stack(unsigned capacity)
{
  struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (int*) malloc(stack->capacity * sizeof(int));
  return stack;
}


int is_stack_full(struct Stack* stack)
{
  return stack->top == stack->capacity - 1;
}


int is_stack_empty(struct Stack* stack)
{
  return stack->top == -1;
}


void push_to_stack(struct Stack* stack, int new_item)
{
  if (is_stack_full(stack)) {
    printf("Stack is full...\n");
    return;
  }
  stack->array[++stack->top] = new_item;
  printf("The number %d was pushed into the stack...\n\n", new_item);
}


int pop_item(struct Stack* stack)
{
  if (is_stack_empty(stack)) {
    printf("Stack is empty...\n");
    return INT_MIN;
  }
  return stack->array[stack->top--];
}


int return_top_item(struct Stack* stack)
{
  if (is_stack_empty(stack)) {
    printf("Stack is empty...\n");
    return INT_MIN;
  }
  return stack->array[stack->top];
}


void print_stack(struct Stack* stack)
{
  int i;
  for (i = 0; i <= stack->top; i++)
    printf("%d, \n", stack->array[i]);
}


int main(void)
{
  struct Stack* stack = create_new_stack(100);
  push_to_stack(stack, 10);
  push_to_stack(stack, 770);
  push_to_stack(stack, 30);
  print_stack(stack);
  printf("The number %d was popped out from stack...\n", pop_item(stack));
  print_stack(stack);
  pop_item(stack);
  pop_item(stack);
  pop_item(stack);
  push_to_stack(stack, 30);
  push_to_stack(stack, 49);
  push_to_stack(stack, 51);
  push_to_stack(stack, 46);
  push_to_stack(stack, 550);
  push_to_stack(stack, 550);
  push_to_stack(stack, 480);
  return 0;
}
