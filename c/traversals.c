#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define TYPE int

#define Stack struct stack_t
Stack {
  int top;
  TYPE data[128];
};
void push(Stack *stack, TYPE element) {
  stack->data[stack->top++] = element;
}
TYPE pop(Stack *stack) {
  if(stack->top == -1) return -1;
  return stack->data[--stack->top];
}

#define Queue struct queue_t
Queue {
  int front;
  int rear;
  int data[128];
};
void enqueue(Queue *queue, TYPE element){
  queue->data[queue->rear++] = element;
}
TYPE dequeue(Queue *queue) {
  return queue->data[queue->front++];
}

void scanBoolean(bool * boolean){
  int x;
  scanf("%d", &x);
  *boolean = x;
}

int main(void){
  int n;
  printf("How many nodes? ");
  scanf("%d", &n);
  bool matrix[n][n];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      scanBoolean(&matrix[i][j]);
  int start;
  printf("Where to start? ");
  scanf("%d", &start);

  printf("Depth first traversal:\n");
  Stack stack = {};
  bool visited[n];
  memset(visited, 0, sizeof(bool) * n);

  push(&stack, start);
  while(stack.top > 0) {
    // Pop
    int x = pop(&stack);
    if(visited[x]) continue;
    // Visit
    printf("%d -> ", x);
    visited[x] = true;
    // Push the neighbors
    for(int i = 0; i < n; i++)
      if(matrix[x][i])
        push(&stack, i);
  }

  printf("\nBredth first traversal:\n");
  Queue queue = {};
  memset(visited, 0, sizeof(bool) * n);

  enqueue(&queue, start);
  while(queue.front != queue.rear) {
    // Dequeue
    int x = dequeue(&queue);
    if(visited[x]) continue;
    // Visit
    printf("%d -> ", x);
    visited[x] = true;
    // Enqueue the neighbors
    for(int i = 0; i < n; i++)
      if(matrix[x][i])
        enqueue(&queue, i);
  }
}
