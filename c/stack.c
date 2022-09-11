#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define TYPE int

#define Stack struct Stack
Stack {
  TYPE *items;
  int capacity; // max possible size
  int top; // index of top item
};

Stack make_stack(){
  Stack stack;
  stack.items = (TYPE*) malloc(sizeof(TYPE) * (stack.capacity = 8));
  stack.top  = -1;
  return stack;
}

void free_stack(Stack stack){
  free(stack.items);
}

bool is_empty(Stack stack){
  return stack.top == -1;
}

void resize(Stack *stack, int new_size){
    stack->items = realloc(stack->items, sizeof(TYPE) * new_size);
    stack->capacity = new_size;
}

void push(Stack *stack, TYPE value){
  if(stack->top + 1 == stack->capacity)
    resize(stack, stack->capacity * 2);
  stack->items[++(stack->top)] = value;
}

TYPE pop(Stack *stack){
  if(stack->top * 2 == stack->capacity)
    resize(stack, stack->capacity / 2);
  return stack->items[stack->top--];
}
