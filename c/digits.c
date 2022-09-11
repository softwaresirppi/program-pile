#include <stdio.h>
#include <math.h>
// finding number of digits
int main(){
  int x;
  scanf("%d", &x);
  FILE *null = fopen("/dev/null", "w");
  int n = fprintf(null, "%d", x);
  printf("%d", n);
}
