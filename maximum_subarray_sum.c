
#include <stdio.h>

int main() {
    int n;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size!\n");
        return 1;
    }

    int arr[n];

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxSum = arr[0];
    int currentSum = arr[0];

    int start = 0, end = 0, tempStart = 0;

    for (int i = 1; i < n; i++) {

        if (arr[i] > currentSum + arr[i]) {
            currentSum = arr[i];
            tempStart = i;
        } else {
            currentSum += arr[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
    }

    printf("\nMaximum Subarray Sum: %d\n", maxSum);

    printf("Subarray: ");

    for (int i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
