#include <bits/stdc++.h>
using namespace std;
// x = 0110
// for i=3...0
// ((1 << i) & x) >> i
void printBin(int x){
	for(int i = sizeof(x) * 8 - 1; i >= 0; i--){
		printf("%d", abs(((1 << i) & x) >> i));
		if(i % 4 == 0) printf(" ");
	}
}

int main(){
	int x = 0, other = 0;
	char cmd;
	do {
		system("clear");
		printBin(x);
		printf(": %+d %u 0x%x\n", x, x, x);
		scanf("%c", &cmd);
		if(cmd == '=')
			scanf("%d", &x);
		else if(cmd == '&' && scanf("%d", &other))
			x &= other;
		else if(cmd == '|' && scanf("%d", &other))
			x |= other;
		else if(cmd == '^' && scanf("%d", &other))
			x ^= other;
		else if(cmd == '1' && scanf("%d", &other))
			x = (1 << other) | x;
		else if(cmd == '0' && scanf("%d", &other))
			x = ~(1 << other) & x;
		else if(cmd == 't' && scanf("%d", &other))
			x = (1 << other) ^ x;
		else if(cmd == '~')
			x = ~x;
		else if(cmd == '+')
			x++;
		else if(cmd == '-')
			x--;
		else if(cmd == '<')
			x <<= 1;
		else if(cmd == '>')
			x >>= 1;

	} while(cmd != 'x');
}
