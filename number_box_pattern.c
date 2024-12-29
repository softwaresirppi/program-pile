#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <math.h>
#include <stdint.h>

void printRange(int start, int end){
  if(start < end)
    for(int i = start; i < end; i++)
      printf("%d ", i);
  else
    for(int i = start; i > end; i--)
      printf("%d ", i);
}

void print(int x, int n){
  for(int i = 0; i < n; i++)
    printf("%d ", x);
}

// i is the number of times it gets changed each side
void line(int length, int diffs){
  printRange(ceil(length/2.0), ceil(length/2.0) - diffs);
  print(ceil(length/2.0) - diffs  ,length - 2 * diffs);
  printRange(ceil(length/2.0) - diffs + 1, ceil(length/2.0) + 1);
  printf("\n");
}


int main(){
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n/2; i++)
    line(n, i);
  for(int i = n/2; i >= 0; i--)
    line(n, i);
}
