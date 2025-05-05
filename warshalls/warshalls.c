#include <stdio.h>

#define V 4

void warshall(int graph[V][V]) {
    int reach[V][V], i, j, k;

    // Initialize reach matrix same as input graph matrix
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            reach[i][j] = graph[i][j];

    // Apply Warshall's Algorithm
    for (k = 0; k < V; k++)
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);

    // Print the transitive closure
    printf("Transitive Closure of the given graph:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++)
            printf("%d ", reach[i][j]);
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };

    warshall(graph);

    return 0;
}
