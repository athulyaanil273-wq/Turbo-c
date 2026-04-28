#include <stdio.h>
#define MAX 20

struct edge {
    int u, v, w;
};

struct edge edges[MAX];
struct edge mst[MAX];
int parent[MAX];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int unionSet(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int n, e, i, j, count = 0;
    int totalCost = 0;
    struct edge temp;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v w):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
        parent[i] = 0;

    for (i = 0; i < e && count < n - 1; i++) {
        int u = find(edges[i].u);
        int v = find(edges[i].v);
        if (unionSet(u, v)) {
            mst[count++] = edges[i];
            totalCost += edges[i].w;
        }
    }

    printf("Edges in MST:\n");
    for (i = 0; i < count; i++) {
        printf("%d - %d : %d\n", mst[i].u, mst[i].v, mst[i].w);
    }

    printf("Total cost of MST: %d\n", totalCost);
    return 0;
}
