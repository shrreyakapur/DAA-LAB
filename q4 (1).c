#include <stdio.h>

int kadane(int arr[], int n) {
    int max = arr[0];
    int end = arr[0];
    for (int i = 1; i < n; i++) {
        end = end + arr[i];
        if (max < end) max = end;
        if (end < 0) end = 0;
    }
    return max;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int max_sum = kadane(arr, n);
    printf("Maximum sum of subarray: %d\n", max_sum);
    return 0;
}
