
#include <stdio.h>

#define MAX 1000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);
    return i;
}

int quickSelect(int arr[], int low, int high, int target) {
    while (low <= high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == target)
            return arr[pivotIndex];

        if (pivotIndex < target)
            low = pivotIndex + 1;
        else
            high = pivotIndex - 1;
    }

    return -1;
}

int main() {
    int n, k;
    int arr[MAX];

    printf("Enter array size: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    if (scanf("%d", &k) != 1 || k < 1 || k > n) {
        printf("Invalid k value.\n");
        return 1;
    }

    // Convert kth largest into ascending-order index.
    int target = n - k;

    int result = quickSelect(arr, 0, n - 1, target);

    printf("%dth largest element: %d\n", k, result);

    return 0;
}
