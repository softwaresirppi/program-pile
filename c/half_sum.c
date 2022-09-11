#include <stdio.h>

int sum(int* start, int* end){
  int result = 0;
  while(start != end){
    result += *start;
    start++;
  };
  return result;
}



int main(){
  int n;
  scanf("%d", &n);
  int x[n];
  for(int i = 0; i < n; i++) scanf("%d", x + i);
  printf("%d\n%d", sum(x, x + n/2), sum(x + n/2, x + n));
}
