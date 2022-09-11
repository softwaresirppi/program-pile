#include <stdio.h>

int main(){
	int empid[7] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};
	int hours[7]; float pay[7];
	for(int i = 0; i < 7; i++){
		printf("%d ", empid[i]);
		scanf("%d %f", &hours[i], &pay[i]);
	}
	for(int i = 0; i < 7; i++){
		printf("%d %.2f\n", empid[i], hours[i] * pay[i]);
	}
}
