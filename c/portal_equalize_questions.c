#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int setLength[n];
	int total = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &setLength[i]);
		total += setLength[i];
	}

	int equilibrium = total / n;
	int garbageQuestions = 0;
	int recycleQuestions = 0;

	for(int i = 0; i < n; i++) {
		int diff = setLength[i] - equilibrium;
		if(diff < 0) recycleQuestions -= diff;
		garbageQuestions += diff;

	}
	printf("%d %d", garbageQuestions, recycleQuestions);
}
