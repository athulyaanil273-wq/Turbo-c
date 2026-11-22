
#include <stdio.h>

#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, capacity;
    int weight[MAX], value[MAX];
    int dp[MAX + 1][MAX + 1];

    printf("Enter number of items: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of items.\n");
        return 1;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    if (capacity < 0 || capacity > MAX) {
        printf("Invalid capacity.\n");
        return 1;
    }

    printf("Enter weight and value of each item:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weight[i], &value[i]);

        if (weight[i] <= 0 || value[i] < 0) {
            printf("Invalid item details.\n");
            return 1;
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } 
            else if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            } 
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("Maximum value: %d\n", dp[n][capacity]);

    return 0;
}
