#include <stdio.h>


int getDayIndexb(int d, int m, int y) 
{ 
    static int t[] = { 0, 3, 2, 5, 0, 3,
                       5, 1, 4, 6, 2, 4 }; 
    y -= m < 3; 
    return ( y + y / 4 - y / 100 + 
             y / 400 + t[m - 1] + d) % 7; 
}

int getDayIndex(int d, int m, int y){
	d += m < 3 ? y-- : y - 2;
	return (23*m/9 + d + 4 + y/4- y/100 + y/400)%7;
}

char* days[] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday",
};

int main(){
	unsigned int d, m, y;
	scanf("%u %u %u", &y, &m, &d);
	printf("%s", days[getDayIndex(d, m, y)]);
}
