#include <stdio.h>

int main(){
  int rows, columns;
  scanf("%d %d", &rows, &columns);
  int matrix[rows][columns];

  for(int i = 0; i < rows; i++)
    for(int j = 0; j < columns; j++)
      scanf("%d", &matrix[i][j]);


  for(int i = 0; i < rows; i++)
    for(int j = 0; j < columns; j++)
      if(matrix[i][j] == (i != j)){
        printf("Not Identity");
        return 0;
      }
  printf("Identity");
  return 0;
}
