#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Adjacency matrix representation of the graph
int in_degree[MAX_VERTICES] = {0}; // Array to store in-degrees of vertices
int queue[MAX_VERTICES], front = 0, rear = 0; // Queue for BFS

void kahnTopologicalSort(int n) {
    int count = 0;

    // Add all vertices with in-degree 0 to the queue
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    printf("Topological Sort: ");
    while (front < rear) {
        int u = queue[front++]; // Remove vertex from the queue
        printf("%d ", u);
        count++;

        // For each neighboring vertex of u, decrease in-degree
        for (int v = 0; v < n; v++) {
            if (graph[u][v] == 1) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    queue[rear++] = v; // If in-degree becomes 0, add to the queue
                }
            }
        }
    }

    if (count != n) {
        printf("\nCycle detected! No topological sort exists.\n");
    }
}

int main() {
    int n, e, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1; // Create the directed edge u -> v
        in_degree[v]++;  // Increment the in-degree of vertex v
    }

    kahnTopologicalSort(n);

    return 0;
}
