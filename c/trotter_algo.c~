#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TYPE char
#define LEFT 0
#define RIGHT 1

struct element_t {
  char data;
  struct element_t* child;
};
#define Element struct element_t


// ABC
// 012
// 
#define LOGZ(list, n) for(int i = 0; i < n; i++) printf("%c", (list + i) - (list[i].child) > 0 ? '<' : '>'); printf("\n"); \
   for(int i = 0; i < n; i++) printf("%c", list[i].data); printf("\n")
#define LOG(list, n) for(int i = 0; i < n; i++) printf("%c -> %c\n", list[i].data, list[i].child ? list[i].child->data : 'F');
void memswap(char* a, char* b, int bytes){
  do{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    a++;
    b++;
  } while (--bytes);
}

void swap(Element* left, Element* right){
  memswap(left, right, sizeof(Element));
  left->child++;
  right->child--;
}

/* bool next_permutation(Element* list, int n){
  int mobile;
    mobile = -1;
    printf("\nLOOP, finding max mobile element...\n");
    for(int i = 0; i < n; i++){
      if(list[i].direction && i < n - 1 && list[i + 1].data < list[i].data)
	mobile = i;
      else if (!list[i].direction && i > 0 && list[i - 1].data < list[i].data)
	 mobile = i;
    }
    LOG;
    if(mobile == -1) return false;
    printf("Swapping..\n");
    memswap(list + mobile, );
    if(directions[mobile]) mobile++;
    else mobile--;
    printf("swapped mob: %d\n", mobile);
    LOG;
    printf("Flipping directions of bigger elements\n");
    for(int i = 0; i < n; i++){
      if(list[i] > list[mobile]){
	printf("flipping %c's direction since its bigger than %c\n", list[i], list[mobile]);
	directions[i] = !directions[i];
      }
      //printf("%d: dir: %d\n", directions[i]);
    }
    LOG;
    return true; 
} */

// Gets the highest mobile element
Element* getMobile(Element* list, int n){
  Element* mobile;
  for(int i = 0; i < n; i++){
    if(list[i].child && list[i].data > list[i].child->data)
      mobile = list + i;
  }
  return mobile;
}

// <<<
// abc
bool next_permutation(Element* list, int n){
  Element* mobile = getMobile(list, n);
  printf("Swapping...\n");
  swap(mobile, mobile->child);
  LOG(list, n);
  printf("Flipping...\n");
  for(int i = 0; i < n; i++)
    if(list[i].data > mobile->data){
      printf("DIFF %d\n", ((list[i].child) - (list + i)));
    }
  return true;
}

int main() {
  Element list[] = {{'a', 0}, {'b', list}, {'c', list + 1}};
  LOG(list, 3);
  for(int i = 0; i < 5; i++)
  next_permutation(list, 3);
  
}
