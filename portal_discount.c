#include <stdio.h>
#include <math.h>

int clamp(int x, int lower, int upper){
    return x < lower ? lower : (x > upper) ? upper : x;
}
void main(){
    switch(1){}
    if(0){}
    int x, n, discountPercent;
    scanf("%d %d", &x, &n);
    discountPercent = clamp(ceil((n + ((n < 50) * - n)) / 100.0) * 10, 0, 50);
    float cost = x * n;
    float discount = (cost / 100.0) * discountPercent;
    printf("%.2f", cost - discount);
}
