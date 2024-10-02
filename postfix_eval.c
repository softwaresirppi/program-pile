#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// cool code
int evaluate(char** expression, int n) {
  int *stack = calloc(n, sizeof(int)), top = -1;
  for(int i = 0; i < n; i++)
    if(!strcmp(expression[i], "+")) stack[top] += stack[top--];
    else if(!strcmp(expression[i], "-")) stack[top] -= stack[top--];
    else if(!strcmp(expression[i], "*")) stack[top] *= stack[top--];
    else if(!strcmp(expression[i], "/")) stack[top] /= stack[top--];
    else stack[++top] = atoi(expression[i]);
  return stack[top];
}

int main() {
  char* expression[] = {"2", "2", "*", "3", "3", "*", "+"};
  printf("value: %d", evaluate(expression, 7));
}
