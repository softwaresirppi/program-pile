#include "list.c"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	List *l = listMake(16, sizeof(char*));
	*(char**) listInsert(l, 0) = "FUCK";
	*(char**) listInsert(l, 0) = "THE";
	*(char**) listInsert(l, 0) = "WHAT";
	for (int i = 0; i < listLength(l); i++) {
		printf("%s\n", *(char**) listAt(l, i));
	}
	listFree(l);
}
