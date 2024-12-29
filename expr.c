#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <math.h>

// GRAMMAR:
// Expr = Term + Expr | Term - Expr
// Term = Value * Term | Value / Term | -Term | +Term
// Value = Base 10 | Cell | (Expr)
// CELL = base26 base10
double parseExpression(char* text, int* cursor, int rows, int columns, int** cells);

void panic(char* error, ...){
  va_list args;
  va_start(args, error);
  printf("ERROR: ");
  vprintf(error, args);
  printf("\n");
  va_end(args);
  exit(69);
}

int parseSign(char* text, int* cursor) {
  if(text[*cursor] == '+' && ++(*cursor))
    return 1;
  if(text[*cursor] == '-' && ++(*cursor))
    return -1;
  panic("INVALID sign at %s", text);
}

int parseBase26(char* text, int* cursor) {
  int end = *cursor;
  while(text[end] && isalpha(text[end]))
    end++;
  int start = *cursor;
  if(start == end) panic("INVALID Base26 number at %s", text);

  int value = 0;
  for(int i = start; i < end; i++)
    value += ((text[i] & 0b1111) - 1) * (int)pow(26, end - 1 - i);
  *cursor = end;
  return value;
}

int parseBase10(char* text, int* cursor){
  int end = *cursor;
  while(text[end] && isdigit(text[end]))
    end++;
  int start = *cursor;
  if(start == end) panic("INVALID Base26 number at %s", text);

  int value = 0;
  for(int i = start; i < end; i++)
    value += (text[i] & 0b1111) * (int)pow(10, end - 1 - i);
  *cursor = end;
  return value;
}

int parseCell(char* text, int* cursor, int rows, int columns, int** cells) {
  int row = parseBase26(text, cursor);
  int column = parseBase10(text, cursor);
  if(!(row < rows && column < columns)) panic("INVALID cell reference at %s", text);
  return cells[row][column];
}

int parseValue(char* text, int* cursor, int rows, int columns, int** cells) {
  if(text[*cursor] && text[*cursor] == '(' && ++(*cursor)){
    double value = parseExpression(text, cursor, rows, columns, cells);
    if(text[*cursor] == ')' && ++(*cursor)) return value;
    panic("UNCLOSED bracket");
  }
  if(text[*cursor] && isdigit(text[*cursor])) return parseBase10(text, cursor);
  if(text[*cursor] && isalpha(text[*cursor])) return parseCell(text, cursor, rows, columns, cells);
  panic("INVALID value at %s", text);
}


double parseTerm(char* text, int* cursor, int rows, int columns, int** cells) {
  if(text[*cursor] == '+' && ++(*cursor))
    return parseTerm(text, cursor, rows, columns, cells);
  if(text[*cursor] == '-' && ++(*cursor))
    return -parseTerm(text, cursor, rows, columns, cells);

  int first = parseValue(text, cursor, rows, columns, cells);
  if(text[*cursor] == '*' && ++(*cursor))
    return (double)first * (double)parseTerm(text, cursor, rows, columns, cells);
  if(text[*cursor] == '/' && ++(*cursor))
    return (double)first / (double)parseTerm(text, cursor, rows, columns, cells);
  return first;
}

double parseExpression(char* text, int* cursor, int rows, int columns, int** cells) {
  double first = parseTerm(text, cursor, rows, columns, cells);
  if(text[*cursor] == '+' && ++(*cursor))
    return first + parseExpression(text, cursor, rows, columns, cells);
  if(text[*cursor] == '-' && ++(*cursor))
    return first - parseExpression(text, cursor, rows, columns, cells);
  return first;
}

int main() {
  // Initializing the spreadsheet cells
  int rows = 3, columns = 3;
  int** cells = calloc(rows, sizeof(int*));
  for(int i = 0; i < rows; i++) cells[i] = calloc(columns, sizeof(int*));
  for(int i = 0; i < rows; i++)
    for(int j = 0; j < columns; j++)
      cells[i][j] = i * j;
  // dumping it out
  printf("SPREADSHEET:\n");
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < columns; j++)
      printf("%8d", cells[i][j]);
    printf("\n");
  }
  // Evaluating an expression in this context
  char expression[32];
  printf("EXPRESSION: ");
  scanf("%31s", expression);
  int cursor = 0;
  double value = parseExpression(expression, &cursor, rows, columns, cells);
  printf("VALUE: %lf TILL %d\n", value, cursor);
}
