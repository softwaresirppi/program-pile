#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define BUFFER 64
#define DELIM " "
int main(){
	char raw[BUFFER]; fgets(raw, BUFFER, stdin);
	char* token = strtok(raw, DELIM);
	long high = LONG_MIN;
	do{
		long value = strtol(token, NULL, 10);
		if(value > high) high = value;
	}while(token = strtok(NULL, DELIM));
	printf("The greatest number is %ld\n", high);
}
