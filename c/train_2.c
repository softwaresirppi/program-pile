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

typedef struct {
	int localId;
	char[2] type;
} Seat;

Seat createSeat(int globalId){
	return (Seat){getLocal(globalId), localSeatArrangement[getLocal(globalId)]};
}
Seat printSeat(Seat seat){
	printf("%d%s", seat.id);
}

char* localPairTable[] = {
	{2, "UB"},
	{1, "MB"},
	{0, "LB"},
	{6, "SL"},
	{5, "UB"},
	{4, "MB"},
	{3, "LB"},
	{7, "SU"},
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
