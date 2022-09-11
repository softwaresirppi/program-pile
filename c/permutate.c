#include <stdio.h>
#include <string.h>
#define SWAP(a, b) a ^= b; b ^= a; a ^= b;

// [start and end)
// hello
// 012345
// start = 0
// end = 5
// [start end]
/*void permutate(char* string, char* start, char* end){
  printf("LOG %s %ld-%ld\n", string, start - string, end - string);
  if(start == end) printf("RES %s\n", string);
  else for(char* i = start; i != end + 1; i++) {
  printf("LOG %s %ld-%ld\n", string, start - string, end - string);
      SWAP(*start, *i);
      permutate(string, start + 1, end);
      SWAP(*start, *i);
  }
} 

void permute(char* string, size_t start, size_t end){
  if(start == end) printf("%s\n", string);
  else for(size_t i = 0; i <= end; i++){
      SWAP(string[start], string[i]);
      permute(string, start + 1, end);
      SWAP(string[start], string[i]);
  }
  }

void permute(char *a, int l, int r){
if (l == r)
    printf("%s\n", a);
 else 
    for (int i = l; i <= r; i++)
    {
        SWAP(a[l], a[i]);
        permute(a, l+1, r);
        SWAP(a[l], a[i]); //backtrack
    }

}

#define MAX_LEN 32
int main(){
  char x[] = "abc";
  permute(x, 0, strlen(x) - 1);
} */
#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) { char t = *a; *a = *b; *b = t; }

void permute(char *a, int i, int n) {
   if (i == (n-1)) printf("%s\n", a);
   else {
     for (int j = i; j < n; j++) {
       swap((a+i), (a+j));
       permute(a, i+1, n);
       swap((a+i), (a+j));
     }
  }
}

int main(){
  char s[64];
  scanf("%s", s);
  permute(s, 0, strlen(s));
}
