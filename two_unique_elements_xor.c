
#include <stdio.h>

int main() {
    int n, xorResult = 0;

    scanf("%d", &n);

    if (n < 2 || n > 100000 || n % 2 != 0) {
        printf("Invalid input\n");
        return 0;
    }

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        xorResult ^= arr[i];
    }

    // Find the rightmost set bit
    int setBit = xorResult & -xorResult;

    int num1 = 0, num2 = 0;

    // Divide elements into two groups
    for (int i = 0; i < n; i++) {
        if (arr[i] & setBit)
            num1 ^= arr[i];
        else
            num2 ^= arr[i];
    }

    printf("Unique elements: %d %d\n", num1, num2);

    return 0;
}
