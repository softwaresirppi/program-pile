#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int printWord(char *x){
  int chars = 0;
  while(*x && !isspace(*x)){
    printf("%c", *x++);
    chars++;
  }
  return chars;
}

void printWordsRev(char *str){
  int length = strlen(str);
    for(int i = length - 1; i;i--)
      if(isspace(str[i]))
        if(printWord(str + i + 1))
        printf(" ");
    printWord(str);
}
foo();

int main(){
    FILE* file = fopen("text", "r");
    char buffer[64];
    while(fgets(buffer, 64, file)){
      printWordsRev(buffer);
      printf("\n");
    }
}
