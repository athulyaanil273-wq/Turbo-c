
#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];

int hasCycle(int vertices) {
    int parent[MAX];
    int queue[MAX];

    for (int i = 0; i < vertices; i++) {
        parent[i] = -1;
        visited[i] = 0;
    }

    for (int start = 0; start < vertices; start++) {
        if (visited[start])
            continue;

        int front = 0, rear = 0;

        queue[rear++] = start;
        visited[start] = 1;

        while (front < rear) {
            int current = queue[front++];

            for (int i = 0; i < vertices; i++) {
                if (graph[current][i]) {
                    if (!visited[i]) {
                        visited[i] = 1;
                        parent[i] = current;
                        queue[rear++] = i;
                    }
                    else if (parent[current] != i) {
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}

int main() {
    int v, e, u, w;

    scanf("%d %d", &v, &e);

    if (v <= 0 || v > MAX || e < 0 ||
        e > v * (v - 1) / 2) {
        printf("Invalid input\n");
        return 0;
    }

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &w);

        if (u < 0 || u >= v || w < 0 || w >= v || u == w) {
            printf("Invalid edge\n");
            return 0;
        }

        graph[u][w] = 1;
        graph[w][u] = 1;
    }

    if (hasCycle(v))
        printf("Cycle detected\n");
    else
        printf("No cycle detected\n");

    return 0;
}
