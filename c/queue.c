#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TYPE int

#define Queue struct Queue
Queue {
  TYPE* items;
  int capacity;
  int front;
};

Queue make_queue(){
  Queue queue;
  queue.items = (TYPE*) malloc(sizeof(TYPE) * (queue.capacity = 8));
  queue.front = -1;
  return queue;
}

void free_queue(Queue queue){
  free(queue.items);
}

bool is_empty(Queue queue){
  return queue.front == -1;
}

void resize(Queue *queue, int new_size){
    queue->items = realloc(queue->items, sizeof(TYPE) * new_size);
    queue->capacity = new_size;
}

void enqueue(Queue *queue, TYPE value){
  if(queue->front++ == queue->capacity)
    resize(queue, queue->capacity * 2);
  if(queue->front)
    memmove(queue->items + 1, queue->items, sizeof(int) * queue->front);
  queue->items[0] = value;
}

TYPE dequeue(Queue *queue){
  if(queue->front * 2 == queue->capacity)
    resize(queue, queue->capacity / 2);
  return queue->items[queue->front--];
}

int main(){
  Queue queue = make_queue();
  int scanned;
  int buffer;
  printf("JOIN YOUR LINE...\n");
  do {
    scanned = scanf("%d", &buffer);
    if(scanned) enqueue(&queue, buffer);
  } while(scanned);
  while(!is_empty(queue)){
    printf("%d ", dequeue(&queue));
  }
}
