#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "deck.c"

typedef struct {
	unsigned int vertices;
	bool** adjacent;
} Graph;

Graph* make_graph(unsigned int vertices) {
	Graph* graph = malloc(sizeof(Graph));
	graph->vertices = vertices;
	graph->adjacent = calloc(vertices, sizeof(bool*));
	for(unsigned int i = 0; i < vertices; i++) {
		graph->adjacent[i] = calloc(vertices, sizeof(bool));
	}
	return graph;
}

void add_edge(Graph* graph, unsigned int a, unsigned int b) {
	graph->adjacent[a][b] = true;
	graph->adjacent[b][a] = true;
}

void add_arrow(Graph* graph, unsigned int from, unsigned int to) {
	graph->adjacent[from][to] = true;
}

#define DEEP true
#define BROAD false
void traverse(Graph* graph, unsigned int start, bool isDeep, void(*f)(unsigned int)) {
	Deck* deck = deck_make(graph->vertices);
	bool* visited = calloc(graph->vertices, sizeof(bool));
	push_back(deck, start);
	while(deck->length != 0) {
		unsigned int vertex;
		pop_back(deck, &vertex);
		if(visited[vertex]) continue;
		visited[vertex] = true;
		f(vertex);
		for(unsigned int i = 0; i < graph->vertices; i++) {
			if(graph->adjacent[vertex][i]) {
				if(isDeep) push_back(deck, i);
				else push_front(deck, i);
			}
		}
	}
}

void f(unsigned int vertex) {
	printf("%u->", vertex);
}

int main() {
	Graph* graph = make_graph(8);
	add_edge(graph, 0, 1);
	add_edge(graph, 1, 2);
	add_edge(graph, 2, 3);
	add_edge(graph, 3, 4);
	add_edge(graph, 4, 5);
	add_edge(graph, 5, 6);
	add_edge(graph, 6, 7);
	add_edge(graph, 7, 0);
	add_edge(graph, 7, 1);
	add_edge(graph, 1, 3);
	add_edge(graph, 3, 5);
	add_edge(graph, 5, 7);
	traverse(graph, 0, DEEP, f);
	printf("\n");
	traverse(graph, 0, BROAD, f);
}
