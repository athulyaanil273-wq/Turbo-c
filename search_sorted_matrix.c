
#include <stdio.h>

int main() {
    int n, m, target;

    scanf("%d %d", &n, &m);

    if (n <= 0 || m <= 0 || n > 100 || m > 100) {
        printf("Invalid matrix size\n");
        return 0;
    }

    int matrix[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    scanf("%d", &target);

    int row = 0;
    int col = m - 1;
    int found = 0;

    while (row < n && col >= 0) {
        if (matrix[row][col] == target) {
            printf("Element found at position: %d %d\n",
                   row, col);
            found = 1;
            break;
        }
        else if (matrix[row][col] > target) {
            col--;
        }
        else {
            row++;
        }
    }

    if (!found) {
        printf("Element not found\n");
    }

    return 0;
}
