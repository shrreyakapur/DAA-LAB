// Recursive Binary Search

#include <stdio.h>

int recursiveBinarySearch(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        return mid;
    }
    if (arr[mid] < target) {
        return recursiveBinarySearch(arr, mid + 1, right, target);
    }
    return recursiveBinarySearch(arr, left, mid - 1, target);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    int result = recursiveBinarySearch(arr, 0, n - 1, target);
    printf("Element found at index: %d\n", result);
    return 0;
}
