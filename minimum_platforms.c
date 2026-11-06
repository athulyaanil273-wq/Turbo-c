//Problem statement:

// Given the arrival and departure times of trains at a railway station, find the minimum number of platforms required so that no train has to wait
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;

    scanf("%d", &n);

    int arrival[n], departure[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arrival[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &departure[i]);

    qsort(arrival, n, sizeof(int), compare);
    qsort(departure, n, sizeof(int), compare);

    int platforms = 1;
    int maxPlatforms = 1;

    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            platforms++;
            i++;
        } else {
            platforms--;
            j++;
        }

        if (platforms > maxPlatforms)
            maxPlatforms = platforms;
    }

    printf("Minimum platforms required: %d\n", maxPlatforms);

    return 0;
}
