
#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n, p[MAX + 1];
    long long dp[MAX][MAX];

    printf("Enter number of matrices: ");
    if (scanf("%d", &n) != 1 || n < 1 || n >= MAX) {
        printf("Invalid number of matrices.\n");
        return 1;
    }

    printf("Enter %d dimensions:\n", n + 1);

    for (int i = 0; i <= n; i++) {
        if (scanf("%d", &p[i]) != 1 || p[i] <= 0) {
            printf("Invalid dimension.\n");
            return 1;
        }
    }

    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;

            for (int k = i; k < j; k++) {
                long long cost = dp[i][k] +
                    dp[k + 1][j] +
                    (long long)p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    printf("Minimum multiplication operations: %lld\n",
           dp[1][n]);

    return 0;
}
