#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = n - 1; -n < i; i--){
        for(int j = 0; j < 2; j++)
            for(int k = -(n - 1); k <= n - 1; k++)
                printf(abs(k) <= abs(i)? "*" : " ");
        printf("\n");
    }
}
