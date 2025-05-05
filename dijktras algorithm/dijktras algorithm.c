#include <stdio.h>

int cost[10][10], n, t[10][2], sum;

void kruskal(int cost[10][10], int n);
int find(int parent[10], int i);

int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use 999 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    kruskal(cost, n);

    printf("\nEdges of the Minimum Spanning Tree:\n");
    for (i = 0; i < n - 1; i++) {
        printf("(%d, %d)\n", t[i][0], t[i][1]);
    }
    printf("Sum of the Minimum Spanning Tree: %d\n", sum);

    return 0;
}

void kruskal(int cost[10][10], int n) {
    int parent[10];
    int min, u = -1, v = -1;
    int count = 0, k = 0;

    sum = 0;

    // Initialize parent array
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    while (count < n - 1) {
        min = 999;
        u = -1;
        v = -1;

        // Find minimum edge across sets
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (find(parent, i) != find(parent, j) && cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (u != -1 && v != -1) {
            int root_u = find(parent, u);
            int root_v = find(parent, v);

            if (root_u != root_v) {
                parent[root_u] = root_v;
                t[k][0] = u;
                t[k][1] = v;
                sum += min;
                k++;
                count++;
            }

            // Avoid re-picking the same edge again
            cost[u][v] = cost[v][u] = 999;
        }
    }
}

int find(int parent[10], int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}
