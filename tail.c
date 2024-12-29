#include <stdio.h>

int main(int argsn, char** args){
  int n;
  char c;
  FILE *fp = fopen(args[1], "r");
  scanf("%d", &n);

  int i = 0, lines = 0;
  do {
    fseek(fp, -i++ - 1, SEEK_END);
    if(fgetc(fp) == '\n') lines++;
  } while(lines <= n && ftell(fp));

  while((c = fgetc(fp)) != EOF){
    printf("%c", c);
  }
}
