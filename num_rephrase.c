#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void addsplit(int depth, int x){
  if(depth <= 0 || x < 2) {
    printf("%d", x);
    return;
  }
  int salt = rand() % x;
  //int salt = 1;
  int a = x - salt;
  int b = salt;
  addsplit(depth - 1, a);
  printf(" + ");
  addsplit(depth - 1, b);
}

int main(){
  int x;
  scanf("%d", &x);
  srand(time(0));
  addsplit(3, x);
}
