#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int first(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[low], &arr[i - 1]);
    return i - 1;
}

int last(int arr[], int low, int high) {
    swap(&arr[low], &arr[high]);
    return first(arr, low, high);
}

int mid(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    swap(&arr[low], &arr[mid]);
    return first(arr, low, high);
}

int random(int arr[], int low, int high) {
    int random = low + rand() % (high - low);
    swap(&arr[low], &arr[random]);
    return first(arr, low, high);
}

void quicksort(int arr[], int low, int high, int pivot_type) {
    if (low < high) {
        int pi;
        if (pivot_type == 0) pi = first(arr, low, high);
        else if (pivot_type == 1) pi = last(arr, low, high);
        else if (pivot_type == 2) pi = mid(arr, low, high);
        else pi = random(arr, low, high);
        quicksort(arr, low, pi - 1, pivot_type);
        quicksort(arr, pi + 1, high, pivot_type);
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    srand(time(0));
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Original array:\n");
    print_array(arr, n);

    for (int i = 0; i < 4; i++) {
        int temp_arr[6];
        for (int j = 0; j < n; j++) temp_arr[j] = arr[j];
        quicksort(temp_arr, 0, n - 1, i);
        printf("Sorted array with pivot type %d:\n", i);
        print_array(temp_arr, n);
    }
    
    return 0;
}
