#include <stdio.h>

int main(){
	unsigned int month; scanf("%u", &month);
	printf("days in %dth month is %d\n", month, 30 + ((month + (month > 7)) % 2 == 1) - (month == 2) * 2);
	//     ^1st			     ^2nd   ^3rd
}
