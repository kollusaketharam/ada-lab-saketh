#include <stdio.h>

int cost[10][10], n, t[10][2], sum;

void prims(int cost[10][10], int n);

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

    prims(cost, n);

    printf("\nEdges of the Minimum Spanning Tree:\n");
    for (i = 0; i < n - 1; i++) {
        printf("(%d, %d)\n", t[i][0], t[i][1]);
    }

    printf("Sum of the Minimum Spanning Tree: %d\n", sum);

    return 0;
}

void prims(int cost[10][10], int n) {
    int i, j, u, v, k = 0;
    int min, source = 0;
    int parent[10], dist[10], selected[10];

    // Initialize arrays
    for (i = 0; i < n; i++) {
        dist[i] = cost[source][i];
        selected[i] = 0;
        parent[i] = source;
    }

    selected[source] = 1;
    sum = 0;

    for (i = 0; i < n - 1; i++) {
        min = 999;
        u = -1;

        // Find the vertex with minimum edge cost not yet selected
        for (j = 0; j < n; j++) {
            if (!selected[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u != -1) {
            t[k][0] = u;
            t[k][1] = parent[u];
            k++;
            sum += cost[u][parent[u]];
            selected[u] = 1;

            // Update distances
            for (v = 0; v < n; v++) {
                if (!selected[v] && cost[u][v] < dist[v]) {
                    dist[v] = cost[u][v];
                    parent[v] = u;
                }
            }
        }
    }
}
