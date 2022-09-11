#include <stdio.h>
#include <stdlib.h>
#define length(arr, elType) sizeof(arr) / sizeof(elType)
#define CELLWIDTH "16"
#define MINICELLWIDTH "3"
// Problem definition
const char* columns[] = {"Radius", "Area", "Circumference"};
const size_t inputColumns[] = {0};
void generateRow(double* row){
	row[1] = 3.14 * row[0] * row[0];
	row[2] = 2 * 3.14 * row[0];
}

void buildTable(size_t n, double table[n][length(columns, char*)]){
	for(size_t i = 0; i < n; i++){
		printf("For %luth Row\n", i);
		// Inputting
		for(size_t j = 0; j < length(inputColumns, char*); j++){
			printf("Whats %s? ", columns[inputColumns[j]]);
			scanf("%lf", &table[i][inputColumns[j]]);
		}
		// Generating
		generateRow(table[i]);
	}
}

void printTable(size_t n, double table[n][length(columns, char*)]){
	printf("%" MINICELLWIDTH "s|", "Sn");
	for(size_t i = 0; i < length(columns, char*); i++)
		printf("%-" CELLWIDTH "s|", columns[i]);
	for(size_t i = 0; i < n; i++){
		printf("\n%" MINICELLWIDTH "lu|", i);
		for(size_t j = 0; j < length(columns, char*); j++){
			printf("%" CELLWIDTH ".4lf|", table[i][j]);
		}
	}

}

int main(){
	size_t n;
	printf("How many rows? ");
	scanf("%lu", &n);
	double table[n][length(columns, char*)];
	buildTable(n, table);
	printTable(n, table);
}
