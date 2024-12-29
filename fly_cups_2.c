#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(){
  int cups;
  scanf("%d", &cups);
  bool *infected = (bool*) malloc(sizeof(bool) * cups);
  bool isSuccessful = 1;
  memset(infected, 0, cups * sizeof(bool));
  infected[0] = 1;
  for(int i = 0, pos = 0, gap = 0; i < cups; i++){
    pos = (pos + 1 + gap++) % cups;
    infected[pos] = 1;
  }
  for(int i = 0; i < cups; i++)
    if(!infected[i])
      isSuccessful = 0;

  printf("%s", isSuccessful ? "YES" : "NO");
  free(infected);
}
