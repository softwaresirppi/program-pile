#include <stdio.h>
#include <stdlib.h>

#define NODE struct Node
NODE {
	int data;
	struct Node *next;
};

int main(){
	NODE * head = 0;
	NODE * curr = 0;
	NODE * prev = 0;
	int n;
	int val;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &val);
		curr = malloc(sizeof(NODE));
		curr->data = val;
		if(!head) head = curr;
		if(prev) prev->next = curr;
		prev = curr;
	}
	while(head){
		printf("%d ", head->data);
		head = head->next;
	}
}
