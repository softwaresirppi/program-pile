#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_MAX_LEN 32

int main(){
  int n; scanf("%d", &n);
  char words[n][WORD_MAX_LEN];
  for(int i = 0; i < n; i++) scanf("%s", words[i]);
  
  int comparator(const void* a, const void* b){
    return strcmp(a, b);
  }
  qsort(words, n, WORD_MAX_LEN, comparator);
  for(int i = 0; i < n; i++) printf("%d %s\n", i, words[i]);
}
