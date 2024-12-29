#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <ctype.h>

char* vowels = "aeiou";
bool isVowel(char x){
	x = tolower(x);
	bool _isVowel = false;
	for(int i = 0; i < strlen(vowels); i++)
		if(x == vowels[i])
			_isVowel = true;
	return _isVowel;
}

char* strins(char* x, char* patch, int pos){
	memmove(x + pos + strlen(patch), x + pos, strlen(x) - pos);
	memcpy(x + pos, patch, strlen(patch));
	return x;
}

void memswap(uint8_t *to, uint8_t *from, size_t size){
	if(to == from) return;
	while(size){
		*from ^= *to;
		*to ^= *from;
		*from ^= *to;
		size--;
		from++;
		to++;
	}
}

void memprint(uint8_t *x, size_t size){
	while(size){
		printf("(%p)->[%x:%c]\n", x, *x, *x);
		size--;
		x++;
	}
}

typedef void (*ChunkHandler)(size_t, char*, char*);

void chunkTraverse(char* str, ChunkHandler chunkHandler){
	size_t chunkCounter = 0;
	for(int chunkStart = 0, chunkEnd = 0; str[chunkEnd++] != '\0';){
		//printf("chunk range %d:%c-%d:%c [ cond = %d\n", chunkStart, str[chunkStart], chunkEnd, str[chunkEnd], isVowel(str[chunkEnd - 1]) ^ isVowel(str[chunkEnd]));
		char before = str[chunkEnd - 1], after = str[chunkEnd];
		if(isVowel(before) ^ isVowel(after) || after == '\0'){
			//printf("Gotcha! %lu:%c  ... %lu:%c\n", chunkStart, *(str + chunkStart), chunkEnd, *(str + chunkEnd));
			chunkHandler(chunkCounter, str + chunkStart, str + chunkEnd);
			chunkStart = chunkEnd;
			chunkCounter++;
		}
	}
}

// Atleast strings of length one
size_t chunkLength(char* str){
	size_t length = 0;
	void accumulate(size_t n, char* a, char* b){
		length++;
		//printf("%c-%c\t+1... %lu\n", *a, *b, length);
	}
	chunkTraverse(str, accumulate);
	return length;
}

void chunksExtract(char* str, size_t maxChunkLength, char chunks[][maxChunkLength]){
	void handle(size_t n, char* a, char* b){
		if(b - a > maxChunkLength) return;
		memcpy(chunks[n], a, b - a);
		chunks[n][b - a] = '\0';
	}
	chunkTraverse(str, handle);
}

void mangle(size_t chunkLength, size_t nChunks, char chunks[nChunks][chunkLength], unsigned int strength){
	for(int i = 0; i < strength; i++){
		size_t swapWith;
		do {
			swapWith = rand() % nChunks;
		} while (isVowel(chunks[swapWith][0]) != isVowel(chunks[i][0]));
		memswap(chunks[swapWith], chunks[i], chunkLength);
	}
}


#define MAXCHUNKLEN 16

void test(){
	char bchunks[7][8];
	chunksExtract("avanthikaa", 8, bchunks);
	assert(strcmp(bchunks[0], "a") == 0);
	assert(strcmp(bchunks[1], "v") == 0);
	assert(strcmp(bchunks[2], "a") == 0);
	assert(strcmp(bchunks[3], "nth") == 0);
	assert(strcmp(bchunks[4], "i") == 0);
	assert(strcmp(bchunks[5], "k") == 0);
	assert(strcmp(bchunks[6], "aa") == 0);

	char chunks[7][8];
	chunksExtract("rocketman", 8, chunks);
	assert(strcmp(chunks[0], "r") == 0);
	assert(strcmp(chunks[1], "o") == 0);
	assert(strcmp(chunks[2], "ck") == 0);
	assert(strcmp(chunks[3], "e") == 0);
	assert(strcmp(chunks[4], "tm") == 0);
	assert(strcmp(chunks[5], "a") == 0);
	assert(strcmp(chunks[6], "n") == 0);

	assert(chunkLength("Rocketman") == 7);
	assert(chunkLength("avanTHikaasri") == 9);
	assert(chunkLength("abcdefgh") == 4);

	assert(isVowel('a'));
	assert(isVowel('A'));
	assert(isVowel('e'));
	assert(isVowel('E'));
	assert(isVowel('i'));
	assert(isVowel('o'));
	assert(isVowel('u'));
	assert(!isVowel('k'));
	assert(!isVowel(' '));
	assert(!isVowel('\0'));

	char um[16] = "Fuckaufbau";
	char to[16] = "oof";
	memswap(to, um, 16);
	assert(strcmp(to, "Fuckaufbau") == 0);
	assert(strcmp(um, "oof") == 0);
	printf("--ALL CLEAR--\n");
}

int main(){
	//test();
	srand(time(0));
	char name[32];
	scanf("%s", name);
	size_t nchunks = chunkLength(name);
	char chunks[nchunks][MAXCHUNKLEN];
	chunksExtract(name, MAXCHUNKLEN, chunks);
	for(int i = 0; i < nchunks; i++)
		printf("%s", chunks[i]);
	printf("\n");
	mangle(MAXCHUNKLEN, nchunks, chunks, 2);
	for(int i = 0; i < nchunks; i++)
		printf("%s", chunks[i]);
}
