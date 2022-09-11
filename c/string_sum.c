#include <stdio.h>
#include <ctype.h>

int main(){
  char buff[32];
  scanf("%s", buff);
  int sum = 0;
  for(int i = 0; buff[i]; i++){
    if(isdigit(buff[i])){
      sum += buff[i] - '0';
    }
    //  printf("%c %d", buff[i], buff[i] - '0');
  }
  printf("%d", sum);
  return 0;
}
