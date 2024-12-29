#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLAMP(x, min, max) if(x < min) x = min; if(x > max) x = max

typedef struct List {
	void *blocks;
	size_t blockSize;
	unsigned int N;
	unsigned int n;
} List;

////////////////////
//Bread functions//
//////////////////
List* listMake(unsigned int N, size_t blockSize){
	if(N == 0) N = 8;
	List *list = malloc(sizeof(List));
	list->blocks = calloc(N, blockSize);
	list->blockSize = blockSize;
	list->N = N;
	list->n = 0;
	return list;
}

void listFree(List *list) {
	free(list->blocks);
	free(list);
}

void listResize(List *list, unsigned int N){
	list->blocks = realloc(list->blocks, N * list->blockSize);
	list->N = N;
}

////////////////////
//Cream functions//
//////////////////
unsigned int listLength(List *list){
	return list->n;
}

// O(1): For getting and setting the ith block
void *listAt(List *list, unsigned int i) {
	CLAMP(i, 0, list->n);
	return list->blocks + i * list->blockSize;
}

// O(n): Makes room at ith block and lets you insert there
void *listInsert(List *list, unsigned int i){
	if(list->n == list->N)
		listResize(list, list->N * 2);
	
	CLAMP(i, 0, list->n);
	if(i < list->n)
		memmove(list->blocks + (i + 1) * list->blockSize,
		  list->blocks + i * list->blockSize,
		  (list->n - i) * list->blockSize);
	
	list->n++;
	return listAt(list, i);
}

// O(n): Deletes ith block by copying-back the following blocks
void listDelete(List *list, unsigned int i){
	memmove(list->blocks + (i) * list->blockSize,
	  list->blocks + (i + 1) * list->blockSize,
	  (list->n - i) * list->blockSize);
	list->n--;
}

/*
int example(void){
	List list = listMake(0, sizeof(char));
	*(char*) listInsert(&list, 0) = 'a';
	for(int i = 0; i < 25; i++)
		*(char*) listInsert(&list, listLength(&list)) = *(char*) listAt(&list, listLength(&list) - 1) + 1;
	for(int i = 0; i < listLength(&list); i++)
		printf("%c ", *(char *) listAt(&list, i));
} */
