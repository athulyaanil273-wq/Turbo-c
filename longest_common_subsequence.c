
#include <stdio.h>
#include <string.h>

#define MAX 1001

int main() {
    char str1[MAX], str2[MAX];
    int dp[MAX][MAX];

    scanf("%1000s", str1);
    scanf("%1000s", str2);

    int m = strlen(str1);
    int n = strlen(str2);

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1])
                           ? dp[i - 1][j]
                           : dp[i][j - 1];
            }
        }
    }

    printf("%d\n", dp[m][n]);

    return 0;
}
