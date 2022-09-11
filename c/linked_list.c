#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// CORE implementation
struct Node {
  TYPE data;
  struct Node* next;
};

struct Node* make_node(TYPE data){
  struct Node* node = malloc(sizeof(struct Node));
  node->data = data;
  node->next = 0;
  return node;
}

void free_node(struct Node* node){
  free(node);
}

void link_node(struct Node* prev, NODE* next){
  if(prev != next && prev)
    prev->next = next;
}

TYPE deref_node(NODE* node){
  return node->data;
}

NODE* insert_node(NODE* prev, NODE* next, TYPE data){
  NODE* node = make_node(data);
  link_node(prev, node);
  link_node(node, next);
  return node;
}

NODE* delete_node(NODE* prev){
  link_node(prev, prev->next->next);
  free_node(prev->next);
}

void follow_node(NODE* node, void (*follower)(NODE* node)){
  do {
    if(follower) follower(node);
  } while (node = node->next);
}

NODE* nth_node(NODE* node, size_t n){
  while(n--){
    node = node->next;
  }
  return node;
}

// high level functions

void print_nodes(NODE* head){
  void printer(NODE* node){
    printf("%d, ", node->data);
  }
  follow_node(head, printer);
  printf("\n");
}

NODE* tail_node(NODE* node){
  NODE* tail;
  void foo(NODE* node){
    tail = node;
  }
  follow_node(node, foo);
  return tail;
}
