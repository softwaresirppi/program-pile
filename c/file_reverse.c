#include <stdio.h>

int main(){
  FILE *fp = fopen("text", "r");
  char c;
  fseek(fp, -1, SEEK_END);
  do {
    c = fgetc(fp);
    fseek(fp, -2, SEEK_CUR);
    printf("%c", c);
  } while(ftell(fp));
}
