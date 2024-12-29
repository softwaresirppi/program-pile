#include <stdio.h>
#include <string.h>
#define TYPECHK(type) printf(#type " is %lu bytes long\n", sizeof(type));
void main(){
	TYPECHK(void);
	TYPECHK(_Bool);
	TYPECHK(char);
	TYPECHK(int);
	TYPECHK(long);
	TYPECHK(short);
	TYPECHK(signed char);
	TYPECHK(unsigned char);
	TYPECHK(float);
	TYPECHK(double);
	TYPECHK(long double);
}
