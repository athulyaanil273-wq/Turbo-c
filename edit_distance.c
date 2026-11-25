
#include <stdio.h>
#include <string.h>

#define MAX 1000

int min(int a, int b, int c) {
    int result = a < b ? a : b;
    return result < c ? result : c;
}

int main() {
    char str1[MAX + 1], str2[MAX + 1];
    int dp[MAX + 1][MAX + 1];

    printf("Enter first string: ");
    scanf("%1000s", str1);

    printf("Enter second string: ");
    scanf("%1000s", str2);

    int m = strlen(str1);
    int n = strlen(str2);

    for (int i = 0; i <= m; i++)
        dp[i][0] = i;

    for (int j = 0; j <= n; j++)
        dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(
                    dp[i - 1][j],     // Deletion
                    dp[i][j - 1],     // Insertion
                    dp[i - 1][j - 1]  // Replacement
                );
            }
        }
    }

    printf("Minimum Edit Distance: %d\n", dp[m][n]);

    return 0;
}
