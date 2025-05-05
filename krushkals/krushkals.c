#include <stdio.h>

#define INF 999

int main() {
    int i, j, n, v, k, min, u;
    int c[20][20], s[20], d[20];

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix (use 999 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    printf("\nEnter the source vertex: ");
    scanf("%d", &v);

    // Initialize
    for (i = 1; i <= n; i++) {
        s[i] = 0;
        d[i] = c[v][i];
    }

    d[v] = 0;
    s[v] = 1;

    for (k = 2; k <= n; k++) {
        min = INF;
        u = -1;

        // Find the unvisited node with the smallest distance
        for (i = 1; i <= n; i++) {
            if (s[i] == 0 && d[i] < min) {
                min = d[i];
                u = i;
            }
        }

        if (u == -1) break;  // No reachable node remaining

        s[u] = 1;

        // Relaxation step
        for (i = 1; i <= n; i++) {
            if (!s[i] && d[i] > d[u] + c[u][i]) {
                d[i] = d[u] + c[u][i];
            }
        }
    }

    // Output
    printf("\nThe shortest distances from vertex %d:\n", v);
    for (i = 1; i <= n; i++) {
        printf("%d --> %d = %d\n", v, i, d[i]);
    }

    return 0;
}
