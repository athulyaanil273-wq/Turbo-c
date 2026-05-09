#include <stdio.h>
#include <time.h>

void insertionSort(int a[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[100];
    while (i <= mid && j <= high) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= high)
        temp[k++] = a[j++];
    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int a[100], b[100], n, i;
    clock_t start, end;
    double time_insert, time_merge;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i]; // Copy same input for Merge Sort
    }

    start = clock();
    insertionSort(a, n);
    end = clock();
    time_insert = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    mergeSort(b, 0, n - 1);
    end = clock();
    time_merge = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSorted array using Insertion Sort:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n\nSorted array using Merge Sort:\n");
    for (i = 0; i < n; i++)
        printf("%d ", b[i]);

    printf("\n\nInsertion Sort Time: %f seconds", time_insert);
    printf("\nMerge Sort Time: %f seconds\n", time_merge);

    return 0;
}
