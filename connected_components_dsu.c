
#include <stdio.h>

#define MAX 1000

int parent[MAX];
int rank[MAX];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

void unionSets(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA == rootB)
        return;

    if (rank[rootA] < rank[rootB]) {
        parent[rootA] = rootB;
    }
    else if (rank[rootA] > rank[rootB]) {
        parent[rootB] = rootA;
    }
    else {
        parent[rootB] = rootA;
        rank[rootA]++;
    }
}

int main() {
    int v, e;

    scanf("%d %d", &v, &e);

    if (v <= 0 || v > MAX || e < 0 ||
        e > v * (v - 1) / 2) {
        printf("Invalid input\n");
        return 0;
    }

    for (int i = 0; i < v; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);

        if (u < 0 || u >= v || w < 0 || w >= v || u == w) {
            printf("Invalid edge\n");
            return 0;
        }

        unionSets(u, w);
    }

    int components = 0;

    for (int i = 0; i < v; i++) {
        if (find(i) == i)
            components++;
    }

    printf("Connected Components: %d\n", components);

    return 0;
}
