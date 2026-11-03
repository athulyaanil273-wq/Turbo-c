
#include <stdio.h>

int search(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        // Check if the left half is sorted
        if (arr[left] <= arr[mid]) {

            if (target >= arr[left] && target < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }

        // Otherwise, the right half is sorted
        else {
            if (target > arr[mid] && target <= arr[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n, target;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size!\n");
        return 1;
    }

    int arr[n];

    printf("Enter rotated sorted array: ");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target: ");
    scanf("%d", &target);

    int result = search(arr, n, target);

    printf("Index: %d\n", result);

    return 0;
}
