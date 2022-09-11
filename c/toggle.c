#include <stdio.h>
#include <ctype.h>
void toggleCases(char* x){
	for(size_t i = 0; x[i]; i++){
		if(!islower(x[i]) && !isupper(x[i])) continue;
		x[i] ^= 0b00100000;
	}
}

int main(){
	char x[] = "Slim Shady";
	toggleCases(x);
	for(int i = 0; x[i]; i++) printf("%c", x[i]);
}
