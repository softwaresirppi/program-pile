#include <stdio.h>
#include <stdlib.h>

int search(int n, int array[n], int element){
  for(int i = 0; i < n; i++)
    if(array[i] == element)
      return i;
  return -1;
}

int main(){
  int n;
  int *stops = 0;
  int nstops;
  int queries;
  int from, from_pos;
  int to, to_pos;
  int count;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    count = 0;
    scanf("%d %d", &nstops, &queries);
    if(stops) free(stops);
    stops = (int*) malloc(sizeof(int) * nstops);
    for(int j = 0; j < nstops; j++){
      scanf("%d", stops + j);
    }
    for(int j = 0; j < queries; j++){
      scanf("%d %d", &from, &to);
      int *searching = &from;
      for(int k = 0; k < nstops; k++){
        if(searching && stops[k] == *searching){
          if(searching == &from) searching = &to;
          else {
            count++;
            searching = 0;
          }
        }
      }
    }
    printf("%d\n", count);
  }
}
