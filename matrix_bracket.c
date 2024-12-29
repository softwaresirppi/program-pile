#include <stdio.h>
#include <stdbool.h>

char pieces[2][2][4] = {
	// LEFT RIGHT
	{"┍", "┑"}, // TOP
	{"┕", "┙"}, // BOTTOM
};

void main(){
	int max = 3;
	int a[3][3] = {1,2,3,4,5,6,7,8,9};
	for(int i = 0; i < max; i++){
		printf("%s", i == 0 || i == max - 1 ? pieces[(bool)i][0] : "|");
		for(int j = 0; j < max; j++) printf("%d\t", a[i][j]);
		printf("%s", i == 0 || i == max - 1 ? pieces[(bool)i][1] : "|");
		printf("\n");
	}
}
