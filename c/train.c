#include <stdio.h>
// in a single compartment
char* localSeatArrangement[] ={
	"LB",
	"MB",
	"UB",
	"LB",
	"MB",
	"UB",
	"SL",
	"SU",
};

int getLocal(int x) {return (x - 1) % 8;}

int findLocalPair(int x){
	int pairLocal = getLocal(x);
	if (pairLocal < 3) pairLocal += 3;
	else if (pairLocal > 3 && pairLocal < 6) pairLocal -= 3;
	else if (pairLocal == 6) pairLocal += 1;
	else if (pairLocal == 7) pairLocal -= 1;
	return pairLocal;
}

int main(){
	int a;
	scanf("%d", &a);
	printf("%d%s", a - getLocal(a) + findLocalPair(a), localSeatArrangement[getLocal(a)]);
}
