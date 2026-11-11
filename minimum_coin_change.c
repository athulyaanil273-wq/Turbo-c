
#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

int main() {
    int n, amount;

    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid input\n");
        return 0;
    }

    int coins[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);

        if (coins[i] <= 0) {
            printf("Invalid coin denomination\n");
            return 0;
        }
    }

    scanf("%d", &amount);

    if (amount < 0 || amount > 1000000) {
        printf("Invalid amount\n");
        return 0;
    }

    int *dp = malloc((amount + 1) * sizeof(int));

    if (dp == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i <= amount; i++)
        dp[i] = INF;

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INF) {
                int candidate = dp[i - coins[j]] + 1;

                if (candidate < dp[i])
                    dp[i] = candidate;
            }
        }
    }

    if (dp[amount] == INF)
        printf("Minimum coins required: -1\n");
    else
        printf("Minimum coins required: %d\n", dp[amount]);

    free(dp);
    return 0;
}
