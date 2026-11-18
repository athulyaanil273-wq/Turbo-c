
#include <stdio.h>

#define MAX 100

int main() {
    int v, e;
    int graph[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int queue[MAX];
    int order[MAX];

    scanf("%d %d", &v, &e);

    if (v <= 0 || v > MAX || e < 0 ||
        e > v * (v - 1) / 2) {
        printf("Invalid input\n");
        return 0;
    }

    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);

        if (u < 0 || u >= v || w < 0 || w >= v ||
            u == w || graph[u][w]) {
            printf("Invalid edge\n");
            return 0;
        }

        graph[u][w] = 1;
        indegree[w]++;
    }

    int front = 0, rear = 0;
    int count = 0;

    // Add vertices with zero indegree
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    // Process vertices using BFS
    while (front < rear) {
        int current = queue[front++];
        order[count++] = current;

        for (int i = 0; i < v; i++) {
            if (graph[current][i]) {
                indegree[i]--;

                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    if (count != v) {
        printf("Topological sorting not possible\n");
    } else {
        printf("Topological Order: ");

        for (int i = 0; i < count; i++)
            printf("%d ", order[i]);

        printf("\n");
    }

    return 0;
}
