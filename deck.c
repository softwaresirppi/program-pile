
#include <stdlib.h>
#include <stdio.h>

// Todo:  Make it generic with Object type (primitives, pointer to something)
// Make it grow dynamically
typedef unsigned int TYPE;
typedef struct {
	unsigned int start; // inclusive
	unsigned int end; // exclusive
	int length;
	int capacity;
	TYPE *memory;
} Deck;

#define DECK_FOR(element, deck) TYPE element; \
	for(unsigned int i = deck->start; i != deck->end; i = (i + 1) % deck->capacity, element = deck->memory[i])

Deck* deck_make(unsigned int size) {
	Deck* deck = malloc(sizeof(Deck));
	deck->start = 0;
	deck->end = 0;
	deck->length = 0;
	deck->capacity = size;
	deck->memory = calloc(size, sizeof(TYPE));
	return deck;
}

void deck_free(Deck* deck) {
	free(deck->memory);
	free(deck);
}

int push_back(Deck* deck, TYPE element) {
	if(deck->length == deck->capacity) return -1;
	deck->length++;
	deck->memory[deck->end] = element;
	deck->end = (deck->end + 1) % deck->capacity;
	return 0;
}

int push_front(Deck* deck, TYPE element) {
	if(deck->length == deck->capacity) return -1;
	deck->length++;
	deck->start = (deck->start - 1) % deck->capacity;
	deck->memory[deck->start] = element;
	return 0;
}

int pop_back(Deck* deck, TYPE* popped) {
	if(deck->length == 0) return -1;
	deck->length--;
	deck->end = (deck->end - 1) % deck->capacity;
	*popped = deck->memory[deck->end];
	return 0;
}

int pop_front(Deck* deck, TYPE* popped) {
	if(deck->length == 0) return -1;
	deck->length--;
	*popped = deck->memory[deck->start];
	deck->start = (deck->start + 1) % deck->capacity;
	return 0;
}

