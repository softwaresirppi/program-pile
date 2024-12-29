#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>

#define N 8


#define halfAdder bibitAdd
bibitAdd(bool a, bool b, bool* carry, bool* sum){
  *sum = a ^ b;
  *carry = a && b;
}

tribitadd(bool a, bool b, bool c, bool* carry, bool* sum){
  bool sum1, carry1, carry2;
  bibitAdd(a, b, &carry1, &sum1);
  bibitAdd(sum1, c, &carry2, sum);
  *carry = carry1 || carry2;
}

int main() {
  uint8_t x = 0b01100111;
  uint8_t y = 0b01001100;
  uint8_t sum = 0;

  bool carryBit;
  bool sumBit;
  for(uint8_t i = 0; i < N; i++){
    bool xb = x & (1 << i);
    bool yb = y & (1 << i);
    sumBit = xb ^ yb;
    carryBit = xb & yb;
  }
}
