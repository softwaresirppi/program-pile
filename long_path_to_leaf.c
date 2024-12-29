#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
  int n;
  int to;
  scanf("%d", &n);
  int *depth = calloc(n, sizeof(int));
  int maxdepth = 0;
  for(int i = 0; i < n; i++){
    scanf("%d", &to);
    if(to == -1)
      depth[i] = 0;
    else
      depth[i] = depth[to - 1] + 1;
    if(depth[i] > maxdepth)
      maxdepth = depth[i];
  }
  printf("%d", maxdepth + 1);
}
