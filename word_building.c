#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define LOG(var, fmt) printf(#var " is " #fmt "\n", var);

#define VIEWH 16
#define VIEWW 32

int mod(int x){
        return (x < 0 && (x *= -1), x);
}


int shiftRows(int h, int w, char array[h][w], int units){
	if(mod(units) > h) return -1;
	//int from = units < 0 ? -units : 0;
	int from = mod(units) * (units < 0);
	//int to = units < 0 ? 0 : units;
	int to = mod(units) * (units > 0);
	int shiftedElements = (h - mod(units)) * w;
	//LOG(from, %d);
	//LOG(to, %d);
	//LOG(shiftedElements, %d);
	memmove((char*)array[to], (char*)array[from], shiftedElements);
}

void printRows(size_t h, size_t w, char array[h][w]){
	for(size_t i = 0; i < h; i++){
		printf("%s", array[i]);
		printf("\n");
	}
}

// abcd
// 0123
bool validate(char* a, char* b){
	if(a[0] == '\0') return true;
	return a[strlen(a) - 1] == b[0];
}

// Player system
typedef struct {
	int score;
	char* name;
} Player;

Player createPlayer(char* name){
	return (Player) {0, name};
}

// BUGGY
int main(){
	Player players[] = {
		createPlayer("Crayonie"),
		createPlayer("Eminem"),
	};
	
	char view[VIEWH][VIEWW]; for(size_t i = 0; i < VIEWH; i++) view[i][0] = '\0';

	size_t rounds = 0;
	Player hero;
	while(1){
		// THIS LINE IS BUGGY
		hero = players[rounds % (sizeof(players) / sizeof(Player))];
		system("clear");
		printRows(VIEWH, VIEWW, view);
		shiftRows(VIEWH, VIEWW, view, -1);
		printf("[%d]--- %s\n", rounds, hero.name);
		scanf("%s", view[VIEWH-1]);
		rounds++;
		if(!validate(view[VIEWH - 2], view[VIEWH - 1])){
			hero.score = -1;
		}
	}

	printf("%s fucked up\n", hero.name);
	exit(0);
}
