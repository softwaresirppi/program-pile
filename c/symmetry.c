#include <stdio.h>
#include <stdlib.h>

int main(){
  int rows, columns;
  scanf("%d %d", &rows, &columns);
  int *matrix = (int*) malloc(sizeof(int) * rows * columns);

  for(int i = 0; i < rows; i++)
    for(int j = 0; j < columns; j++)
      scanf("%d", matrix + i + columns * j);


  for(int i = 0; i < rows; i++)
    for(int j = 0; j < columns; j++)
      if(*(matrix + i + columns * j) != *(matrix + j + columns * i)){
        printf("Not Symmetry");
        return 0;
      }
  printf("Symmetry");
  return 0;
}
