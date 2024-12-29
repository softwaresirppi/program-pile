#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int length(int x, int radix) {
	return floor(log(x) / log(radix)) + 1;
}

char* encode(int x, char* digits) {
	int radix = strlen(digits);
	char *output = calloc(length(x, radix), sizeof(int));
	int writer = length(x, radix);
	while(x) {
		output[--writer] = digits[x % radix];
		x /= radix;
	}
	return output;
}

int decode(char* code, char* digits) {
	int radix = strlen(digits);
	int n = strlen(code);

	int positional_power = 1;
	int value = 0;
	for(int i = n - 1; i >= 0; i--) {
		value += code[i] * positional_power;
		printf("%c * %d = %d\n", code[i], positional_power, value);
		positional_power *= radix;
	}
	return value;
}

int main() {
	char* b8 = encode(143, "01234567");
	printf("%s\n", b8);
	int x = decode(b8, "01234567");
	printf("%d", x);
}
