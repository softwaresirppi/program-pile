#include <stdio.h>
#include <string.h>
#define RODS 3
#define DISKS 4
#define SWAP(a, b) if(a != b) {a ^= b; b ^= a; a ^= b;}

// Top first
// ABCD
//
//
//

void move(int rods, int disks, char tower[rods][disks], int from, int to){
  if(tower[to][disks - 1]) fprintf(stderr, "Rod %d is already fill. couldnt move to it.", to);
  memmove(tower[to], &tower[to][1], sizeof(tower[0][0]) * disks);
  tower[to][0] = tower[from][0];
  memmove(&tower[from][1], tower[from], sizeof(tower[0][0]) * disks);
}

towerOfHanoi(int rods, int disks, char tower[rods][disks], int from, int to, int buffer){

}

int main(){
  char tower[RODS][DISKS] = {"ABCD"};
  move(RODS, DISKS, tower, 0,1);
//  move(RODS, DISKS, tower, 0,1);
  for(int i = 0; i < RODS; i++){
    for(int j = 0; j < DISKS; j++)
      printf("%c", tower[i][j]);
    printf("\n");
  }
}
