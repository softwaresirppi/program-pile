#include <stdio.h>
#include <string.h>
#define DEBUG 0
int strRemoveAt(char* dest, char* src, int n){
	for(int i = 0; i <= strlen(src); i++)
		if(i > n) dest[i-1] = src[i];
	       	else dest[i] = src[i];
	return n;
}

char getFlamesPrediction(char* a, char* b){
	char flames[] = "FLAMES";
	int count = strlen(a) + strlen(b);
	// Calculalte count
	for(size_t i = 0; a[i] != '\0'; i++)
		for(size_t j = 0; b[j] != '\0'; j++)
			if(b[j] != '-' && a[i] != '-' && b[j] == a[i]){
				count -= 2;
				b[j] = a[i] = '-';
			}
	int offset = 0, total_strikes = strlen(flames);
	for(int strike = 1; strike < total_strikes; strike++)
		strRemoveAt(flames, flames, offset = (offset + count - 1) % strlen(flames));
	return *flames;
}

int main(){
	char a[64], b[64];
	fprintf(stderr, "Enter two names to pReDicT: ");
	scanf("%s %s", a, b);
	printf("%c", getFlamesPrediction(a, b));
}