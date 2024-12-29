// BLACKLIST
// for, while, goto, {*<self_function>(*)*}

#include <stdio.h>
#include <signal.h>

unsigned int count;
char string[64];

void handle(int num){
	printf("%s\n", string);
	if(--count > 0) raise(SIGUSR1);
}
int main(){
	fprintf(stderr, "How many times you wanna repeat? ");
	scanf("%u", &count);
	fprintf(stderr, "Whats the string you want me to repeat? ");
	scanf(" %[^\n]s", string);
	signal(SIGUSR1, handle);
	raise(SIGUSR1);
}
