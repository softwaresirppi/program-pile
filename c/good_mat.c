#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(){
  int dim;
  scanf("%d", &dim);
  int x[dim][dim];
  int a = 0, b = 0;
  for(int i = 0; i < dim; i++)
    for(int j = 0; j < dim; j++){
      scanf("%d", &x[i][j]);
      if(i + j == dim - 1) b += x[i][j];
      if(i == j) a+=x[i][j];
    }
  printf("%d\n", a - b);
  if((a - b) % 2 == 0)
    printf("Good Matrix");
  else
    printf("Not a Good Matrix");
}
