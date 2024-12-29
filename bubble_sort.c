#include <stdio.h>
#define N 5

int main(){
  int x[5] = {11, 1, 9, 4, 2};
  for(size_t i = 0; i < N; i++){
    for(size_t j = 0; j < N-i-1; j++){
      if(x[j] > x[j+1]){
	x[j] ^= x[j+1];
	x[j+1] ^= x[j];
	x[j] ^= x[j+1];
      }
    }
  }
  for(size_t i = 0; i < N; i++) printf("%d, ", x[i]);
}
