#include <stdio.h>

int main(){
	int a = 54;
	int b = 62;
	a ^= b;
	b ^= a;
	a ^= b;
	printf("%d %d", a, b);
}
