
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0)
        return 0;

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int pos = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[pos] = arr[i];
            pos++;
        }
    }

    while (pos < n) {
        arr[pos] = 0;
        pos++;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}
