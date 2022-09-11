#include <stdio.h>
#include <stdlib.h>

int main(){
	int a, b, moves;
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d %d", &a, &b);
		moves = abs(a - b);
		if(a > b) moves /= 2;
		if(a > b && (a - b) % 2) moves += 2;
		printf("%d\n", moves);
	}
}
