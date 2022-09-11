#include <stdio.h>

char* quadrants[2][2] = {	
	 {"Third", "Second"},
	 {"Fourth", "First"},
};
int main(){
	int x, y;
	scanf("%d %d", &x, &y);
	printf("The coordinate point (%d, %d) lies in the %s quadrant", x, y, quadrants[x > 0][y > 0]);
}
