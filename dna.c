#include <stdio.h>
#include <math.h>

void circle(int radius, char left, char right) {
  for(int x = -radius; x <= radius; x++){
    for(int y = -radius; y <= radius; y++) {
      int circleness = x * x + y * y - radius * radius;
      if(-radius <= circleness && circleness <= radius)
        printf("%c", y > 0 ? left : right);
      else if(circleness < 0)
        printf("-", x, y);
      else
        printf(" ");
    }
    printf("\n");
  }
}

void dna(int radius, int n) {
  for(int i = 0; i < n; i++)
    if(i & 1)
      circle(radius, 'X', 'O');
    else
      circle(radius, 'O', 'X');
}

int main() {
  dna(5, 5);
}
