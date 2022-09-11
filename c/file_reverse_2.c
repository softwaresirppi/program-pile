#include <stdio.h>
// A for apple
// B for ball
int main(int n, char** args){
  FILE* front = fopen(args[1], "r+");
  FILE* back = fopen(args[1], "r+");
  fseek(back, -2, SEEK_END);
  char f, b;
  while(ftell(front) != ftell(back)){
    f = fgetc(front);
    b = fgetc(back);
    fseek(front, -1, SEEK_CUR);
    fseek(back, -1, SEEK_CUR);
    fputc(b, front);
    fputc(f, back);
    fseek(back, -2, SEEK_CUR);
  }
}
