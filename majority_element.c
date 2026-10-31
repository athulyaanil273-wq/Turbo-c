
#Given an array of n integers, find the element that appears more than n/2 times.
#Boyre-Moore Algorithm

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int candidate = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {

        if (count == 0) {
            candidate = arr[i];
        }

        if (arr[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    printf("Majority Element: %d\n", candidate);

    return 0;
}
