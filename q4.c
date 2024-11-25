//  Determine if a number is even or odd

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("%s\n", n % 2 == 0 ? "Even" : "Odd");
    return 0;
}
