
#include <stdio.h>
#include <stdlib.h>

struct Job {
    char id;
    int deadline;
    int profit;
};

int compare(const void *a, const void *b) {
    struct Job *x = (struct Job *)a;
    struct Job *y = (struct Job *)b;

    return y->profit - x->profit;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid input\n");
        return 0;
    }

    struct Job jobs[n];

    for (int i = 0; i < n; i++) {
        scanf(" %c %d %d",
              &jobs[i].id,
              &jobs[i].deadline,
              &jobs[i].profit);

        if (jobs[i].deadline <= 0 || jobs[i].profit < 0) {
            printf("Invalid job details\n");
            return 0;
        }
    }

    qsort(jobs, n, sizeof(struct Job), compare);

    int maxDeadline = 0;

    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    int slots[n + 1];

    for (int i = 0; i <= n; i++)
        slots[i] = -1;

    int totalProfit = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int lastSlot = jobs[i].deadline < n
                       ? jobs[i].deadline : n;

        for (int j = lastSlot; j >= 1; j--) {
            if (slots[j] == -1) {
                slots[j] = i;
                totalProfit += jobs[i].profit;
                count++;
                break;
            }
        }
    }

    printf("Scheduled Jobs: ");

    for (int i = 1; i <= n; i++) {
        if (slots[i] != -1)
            printf("%c ", jobs[slots[i]].id);
    }

    printf("\nJobs Completed: %d\n", count);
    printf("Maximum Profit: %d\n", totalProfit);

    return 0;
}
