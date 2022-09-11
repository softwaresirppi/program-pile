#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
  int n;
  scanf("%d", &n);
  int* array = (int*) malloc(sizeof(int) * n);

  int min = INT_MAX, max = INT_MIN;
  for(int i = 0; i < n; i++){
    scanf("%d", array + i);
    if(array[i] < min) min = array[i];
    if(array[i] > max) max = array[i];
  }
  printf("%d", max - min);
}
