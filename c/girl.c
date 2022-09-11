#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER 64
#define O_FACTOR 3
#define K_FACTOR 4
#define H_FACTOR 2
#define M_FACTOR 6
#define SILENT_FACTOR 2
// PATTERN:
// o+k+
// h+m+

#define repeat(n) for(int i = 0; i < n; i++)

void girlChat(char* prefix){
	if(rand() % SILENT_FACTOR) return;
	printf("%s", prefix);
	if(rand() % 2) {
		repeat(rand() % O_FACTOR) printf("o");
		repeat(rand() % K_FACTOR) printf("k");
	} else {
		repeat(rand() % H_FACTOR) printf("h");
		repeat(rand() % M_FACTOR) printf("m");
	}
	printf("\n");
}

int main(){
	srand(time(0));
	char chat[BUFFER];
	while(1){
		printf("Me: ");
		scanf(" %[^\n]s", chat);
		girlChat("HER: ");
	}
}
