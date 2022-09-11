#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double del;
    printf("What are the coefficients of x^2, x and a constant ");
    scanf("%lf %lf %lf", &a, &b, &c);
    del = b * b - 4 * a * c;
    if (del > 0) {
        double rootA = (-b + sqrt(del)) / (2 * a);
        double rootB = (-b - sqrt(del)) / (2 * a);
        printf("The roots are %.2lf and %.2lf", rootA, rootB);
    } else if (del == 0) {
        double rootA = -b / (2 * a);
        printf("The root is %.2lf;", rootA);
    } else {
        double real = -b / (2 * a);
        double img = sqrt(-del) / (2 * a);
        printf("The imaginary roots are %.2lf%+.2lfi and %.2f%+.2fi", real, img, real, -img);
    }
    return 0;
} 
