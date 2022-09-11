#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


char faces[6][16] = {
	"   \n o \n   ",
	"o  \n   \n  o",
	"o  \n o \n  o",
	"o o\n   \no o",
	"o o\n o \no o",
	"o o\no o\no o",
};
int main(){
	srand(time(0));
	int dice = (rand() % 6);
	printf("%s", faces[dice]);
}
