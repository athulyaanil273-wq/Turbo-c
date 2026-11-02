
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0)
        return 0;

    int arr[n], result[n], stack[n];
    int top = -1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        result[i] = -1;
    }

    for (int i = 0; i < n; i++) {

        while (top != -1 && arr[i] > arr[stack[top]]) {
            result[stack[top]] = arr[i];
            top--;
        }

        stack[++top] = i;
    }

    printf("Next Greater Elements:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");

    return 0;
}
