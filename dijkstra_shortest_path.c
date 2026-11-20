
#include <stdio.h>
#include <limits.h>

#define MAX 100

void dijkstra(int graph[MAX][MAX], int n, int source) {
    int dist[MAX], visited[MAX] = {0};

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INT_MAX, u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] > 0 &&
                dist[u] != INT_MAX &&
                dist[u] <= INT_MAX - graph[u][v] &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("To %d: Unreachable\n", i);
        else
            printf("To %d: %d\n", i, dist[i]);
    }
}

int main() {
    int graph[MAX][MAX] = {0};
    int n, e, u, v, w, source;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    if (n < 1 || n > MAX || e < 0 || e > n * (n - 1) / 2) {
        printf("Invalid graph dimensions.\n");
        return 1;
    }

    printf("Enter edges (u v weight):\n");

    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &u, &v, &w);

        if (u < 0 || u >= n || v < 0 || v >= n ||
            u == v || w <= 0) {
            printf("Invalid edge.\n");
            return 1;
        }

        graph[u][v] = w;
        graph[v][u] = w;
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    if (source < 0 || source >= n) {
        printf("Invalid source vertex.\n");
        return 1;
    }

    dijkstra(graph, n, source);

    return 0;
}
