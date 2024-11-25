// Recursive Linear Search

#include <stdio.h>

int recursiveLinearSearch(int arr[], int n, int target, int index) {
    if (index >= n) {
        return -1;
    }
    if (arr[index] == target) {
        return index;
    }
    return recursiveLinearSearch(arr, n, target, index + 1);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    int result = recursiveLinearSearch(arr, n, target, 0);
    printf("Element found at index: %d\n", result);
    return 0;
}
