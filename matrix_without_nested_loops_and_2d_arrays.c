#include <stdio.h>    
#include <stdint.h>    
#define MAX 3

size_t getMatrixIndex(size_t row, size_t col){
	return col + row * (MAX);
}
void main(){
	uint8_t a[MAX * MAX];
	uint8_t b[MAX * MAX]; // 3 x 3
	int row, col;
	printf("Whats the matrix a? ");
	for(row = 0, col = 0; row < MAX && col < MAX; col++){
		scanf("%hhd", &a[getMatrixIndex(row, col)]);
		if(col == MAX - 1){
			row++;
			col = -1;
		}
	}
	printf("Whats the matrix b? ");
	for(row = 0, col = 0; row < MAX && col < MAX; col++){
		scanf("%hhd", &b[getMatrixIndex(row, col)]);
		if(col == MAX - 1){
			row++;
			col = -1;
		}
	}
	printf("Adding them both: \n");
	for(row = 0, col = 0; row < MAX && col < MAX; col++){
		printf("%hhd\t", b[getMatrixIndex(row, col)] + a[getMatrixIndex(row, col)]);
		if(col == MAX - 1){
			row++;
			col = -1;
			printf("\n");
		}
	}
}
