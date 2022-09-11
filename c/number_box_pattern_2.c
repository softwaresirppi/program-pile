#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <math.h>
#include <stdint.h>

void printRange(int start, int count, int step){
  int x = start;
  for(int i = 0; i < count; i++, x += step)
    printf("%d ", x);
}

void line(int n, int diffs){
  printRange(n, diffs, -1);
  printRange(n - diffs, n * 2 + 1 - 2 * diffs, 0);
  printRange(n - diffs + 1, diffs, 1);
  printf("\n");
}


int main(){
  int n = 0;
  scanf("%d", &n);
  for(int i = 0; i < n/2; i++)
    line(n, i);
  for(int i = n/2; i >= 0; i--)
    line(n, i);
}
