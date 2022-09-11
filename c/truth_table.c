#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>


void memprint(uint8_t *x, size_t size){
	while(size){
		printf("(%p)->[%x:%c]\n", x, *x, *x);
		size--;
		x++;
	}
}
typedef bool(*BoolFunc)(bool, bool);
void truthTable(char* name, BoolFunc f){
	printf("%s\n", name);
	for(uint8_t x = 0; x < 2; x++){
		for(uint8_t y = 0; y < 2; y++){
			printf("|%d|%d|%d|\n", x, y, f(x, y));
		}
	}
}

bool and(bool a, bool b){
  return a && b;
}

int main(){
  truthTable("And", and);
}
