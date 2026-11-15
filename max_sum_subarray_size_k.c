// PROBLEM STATEMENT : Given an array of integers and a number K, find the maximum sum of any contiguous subarray of exactly K elements.
#include <stdio.h>
#include <limits.h>

int main() {
    int n, k;

    scanf("%d", &n);

    if (n <= 0 || n > 100000) {
        printf("Invalid array size\n");
        return 0;
    }

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    if (k <= 0 || k > n) {
        printf("Invalid window size\n");
        return 0;
    }

    long long currentSum = 0;

    // Calculate sum of first K elements
    for (int i = 0; i < k; i++) {
        currentSum += arr[i];
    }

    long long maxSum = currentSum;

    // Slide the window
    for (int i = k; i < n; i++) {
        currentSum += arr[i] - arr[i - k];

        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }

    printf("Maximum subarray sum: %lld\n", maxSum);

    return 0;
}
