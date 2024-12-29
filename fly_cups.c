#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Its equivalent to the (sum_of_nat(i) - 1) % cups WHERE i is >= 2
int fly_pos(int i, int cups){
  return (((i + 4) * (i + 1)) / 2) % cups;
}

int main(){
  int cups;
  scanf("%d", &cups);
  bool infected[cups];
  bool isSuccessful = 1;
  memset(infected, 0, cups * sizeof(bool));
  infected[0] = 1;
  int pos = 0, gap = 1;
  for(int i = 0; i < cups; i++)
    infected[fly_pos(i, cups)] = 1;
  for(int i = 0; i < cups; i++)
    if(!infected[i])
      isSuccessful = 0;

  printf("%s", isSuccessful ? "Yes" : "No");
}
