#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int min(int x, int y) {
  if(x < y) return x;
  return y;
}
int max(int x, int y) {
  if(x > y) return x;
  return y;
}

bool inrange(int x, int from, int to) {
  return x >= from && x < to;
}

void drown(int rows, int cols, int map[rows][cols], int row, int col){
  fprintf(stderr, "Pouring on %dx%d\n", row, col);
  if(!map[row][col] ||
    !inrange(row, 0, rows) ||
    !inrange(col, 0, cols)) {
    fprintf(stderr, "Lets take a break i guess\n");
    return;
  }
  map[row][col] = 0;
  drown(rows, cols, map, row + 1, col);
  drown(rows, cols, map, row - 1, col);
  drown(rows, cols, map, row, col + 1);
  drown(rows, cols, map, row, col - 1);
}


int main(int n, char **args) {
  int rows;
  int cols;
  if(n != 3) {
    printf("Um fuck you");
    return -69;
  }
  printf("%sx%s\n", args[1], args[2]);
  sscanf(args[1], "%d", &rows);
  sscanf(args[2], "%d", &cols);
  int map[rows][cols];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      scanf(" %d", &map[i][j]);
    }
  }
  int islands = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if(map[i][j]) {
        drown(rows, cols, map, i, j);
        for (int i = 0; i < rows; i++) {
          for (int j = 0; j < cols; j++) {
            fprintf(stderr, "%d ", map[i][j]);
          }
          fprintf(stderr, "\n");
        }
        islands++;
      }
    }
  }
  printf("ISLANDS: %d\n", islands);
}
