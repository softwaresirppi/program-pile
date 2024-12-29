#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

void handler(int num){
	static int count = 0;
	printf("%u\n", rand());
	if(++count > 3 && rand() % 2) printf("Im saying it for the %dth time, ", count);
	printf("Dont interrupt me, bich!\n");
}

int main(){
	srand(time(0));
	signal(SIGINT, handler);
	while(1) {
		printf("Wassup bruh. how have you been?\n");
		sleep(rand() % 3 + 1);
	}
}
