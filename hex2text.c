#include <stdio.h>
#include <ctype.h>

int hexval(char hex_char){
  hex_char = toupper(hex_char);
  if(hex_char >= 'A' && hex_char <= 'F') return hex_char - 'A' + 10;
  else if(hex_char >= '0' && hex_char <= '9') return hex_char & 0b00001111;
  fprintf(stderr, "INVALID HEX CODE %c\n", hex_char);
  return -1;
}

int main(){
  char hex[2] = {};
  int value;
  while(1){
    scanf(" %c %c", hex, hex + 1);
    if(hex[0] == 'x' || hex[1] == 'x') break;
    //printf("hexes %c %c\nvalues %d %d\n", hex[0], hex[1], hexval(hex[0]), hexval(hex[0]));
    value = hexval(hex[0]) * 16 + hexval(hex[1]);
    //printf("Value: %d:%c\n", value, (char)value);
    printf("%c", (char)value);
  }
}
