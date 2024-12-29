#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <assert.h>
#include <limits.h>

int mod(int x){
	return (x < 0 && (x *= -1), x);
}
int crazymod(int x){
	return (x & INT_MIN) && (x = ~x + 1), x; // if you wanna have fun
}

void main(){
	assert(mod(5) == 5);
	assert(mod(-5) == 5);
	assert(crazymod(5) == 5);
	assert(crazymod(-5) == 5);
}
