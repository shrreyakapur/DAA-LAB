// Find the largest among three different numbers entered by user.

#include <stdio.h>

int main() {
    int a, b, c, largest;
    scanf("%d %d %d", &a, &b, &c);
    
    largest = a; 
    if (b > largest) largest = b; 
    if (c > largest) largest = c; 
    
    printf("%d\n", largest);
    return 0;
}
