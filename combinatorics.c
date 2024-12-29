#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "search.c"


#define ORDERED 0b1
#define DUPED 0b10
void permute(int n, int* items, int from, int writer, int* order, uint8_t how) {
	if(from == n) {
		for(int i = 0; i < writer; i++)
			printf("%d ", items[order[i]]);
		printf("\n");
	} else for(int i = 0; i < n; i++) {
		if(!(how & ORDERED))
			if(writer - 1 >= 0 && i < order[writer - 1]) continue;
		if(!(how & DUPED))
			if(linear_search(writer, order, i) >= 0) continue;
		order[writer++] = i;
		permute(n, items, from + 1, writer, order, how);
		writer--;
	}
}

int main() {
	int x[] = {1, 2, 3};
	int order[3];
	permute(3, x, 0, 0, order, ORDERED | DUPED);
}
