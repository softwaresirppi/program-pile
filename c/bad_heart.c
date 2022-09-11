#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define FILL_CHAR '!'

// line renderer for a filled circle
void cline(int y, int radius, char positive, char negative, int startOffset){
	//for(int i = 0; i < sin(y * 0.523599) * 1.5; i++)
	//	printf("%c", negative);
	for(int x = -radius + startOffset; x < radius; x++)
		printf("%c ", x * x + y * y <= radius * radius ? positive : negative);
}

bool centered_line(int offset, int totalLength, char positive, char negative){
	if(offset >= totalLength /2) return false;
	for(int i = 0; i < totalLength; i++){
		if(i == offset ) {
			printf("S");
			continue;
		} else if(i == totalLength - offset - 1){
			printf("S");
			continue;
		}
		printf("%c ", i > offset - 1 && i < totalLength - offset ? positive : negative);
	}
	return true;
}

int main(){
	printf(ANSI_COLOR_RED);
	int r = 7;
	for(int y = -r; y < 0; y++){
		cline(y, r, FILL_CHAR , ' ', 0);
		cline(y, r, FILL_CHAR, ' ', r/4);
		printf("\n");
	}
	for(int y = 0; y <= 2 * r; y++){
		printf("  ");
		centered_line(y, 4 * r - 2 , FILL_CHAR, ' ');
		printf("\n");
	}
}
