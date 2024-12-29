#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int n, int array[n]){
  int maximum = INT_MIN;
  for(int i = 0; i < n; i++)
    if(array[i] > maximum) maximum = array[i];
  return maximum;
}

int main(){
  int n;
  scanf("%d", &n);
  int *a = 0;
  int *b = 0;
  int na, nb;
  int amax, bmax;
  for(int i = 0; i < n; i++){
    scanf("%d", &na);
    if(a) free(a);
    a = (int*) malloc (sizeof(int) * na);
    for(int i = 0; i < na; i++)
      scanf("%d", a + i);
    scanf("%d", &nb);
    if(b) free(b);
    b = (int*) malloc (sizeof(int) * nb);
    for(int i = 0; i < nb; i++)
      scanf("%d", b + i);
    amax = max(na, a);
    bmax = max(nb, b);
    if(amax > bmax) printf("Ankita\nAnkita\n");
    else if(bmax > amax) printf("Biswas\nBiswas\n");
    else printf("Ankita\nBiswas\n");
  }
}
