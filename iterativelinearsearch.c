// Iterative Linear Search

#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    int result = linearSearch(arr, n, target);
    printf("Element found at index: %d\n", result);
    return 0;
}

