#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(){
	time_t start = time(0);
	sleep(5);
	time_t end = time(0);
	printf("Elapsed is %ld", end - start);
}
