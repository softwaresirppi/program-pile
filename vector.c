#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define INITIAL_CAPACITY 8
#define Vector struct Vector

Vector {
  uint8_t* units;
  size_t unitSize;
  size_t n;
};

Vector vector_new(size_t unitSize){
  return (Vector) {
    malloc(unitSize * INITIAL_CAPACITY),
    unitSize,
    INITIAL_CAPACITY
  };
}

void vector_del(Vector vector){
  free(vector.units);
}

bool vector_is_out_of_bounds(Vector vector, size_t index){
  if(index >= 0 && index < vector.n) return 0;
  fprintf(stderr, "Out of bounds. Tried to access at %lu in a vector of %lu elements", index, vector.n);
  return 1;
}

void* vector_grab(Vector vector, size_t index){
  if(vector_is_out_of_bounds(vector, index)) return 0;
  return vector.units + index * vector.unitSize;
}

void* vector_insert(Vector vector, size_t index){
  memmove(vector.units + (index + 1) * vector.unitSize, vector.units + index * vector.unitSize, (vector.n - index) * vector.unitSize);
  return vector_grab(vector, index);
}


#define CHAR *(char*)
int main(){
  Vector vector = vector_new(sizeof(char));
  for(int i = 0; i < 8; i++)
  CHAR vector_grab(vector, i) = 'A' + i;

  for(int i = 0; i < 8; i++)
    printf("%c ", CHAR vector_grab(vector, i));
}
