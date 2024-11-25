// Find all the roots of a quadratic equation ax2+bx+c=0

#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, d;
    scanf("%lf %lf %lf", &a, &b, &c);
    d = b*b - 4*a*c;
    if (d >= 0) {
        printf("Roots: %.2lf %.2lf\n", (-b + sqrt(d)) / (2*a), (-b - sqrt(d)) / (2*a));
    } else {
        printf("No real roots\n");
    }
    return 0;
}
