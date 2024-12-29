#include <stdio.h>
#include <stdbool.h>
#include <math.h>
// wtf
bool isPerfect(float x){
  if(x == 1) return false;
  return sqrt(x) == (int)sqrt(x);
}

int main(){
  /*
  printf("    |");
  for(int i = 1; i <= 32; i++) printf("%4d|", i);
  printf("\n");
   for(int i = 1; i <= 32; i++){
      printf("%4d|", i);
    for(int j = 1; j <= 32; j++){
      if(isPerfect(i + j)) printf("\x1b[7m");
      printf("%4.2f", sqrt(i + j));
      printf("\x1b[0m|");
    }
  printf("\n");
  } */
  printf("\n");
  int c = 0;
  for(int i = 1; i <= 32; i++){
    c = 0;
    for(int j = 1; j <= 32; j++){
      if(isPerfect(i + j))
      printf("(%d + %d)\n", (c++, i), j);
    }
    printf("COUNT %d\n", c);
  }
}
