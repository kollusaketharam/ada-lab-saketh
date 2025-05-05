#include <stdio.h>
#include <limits.h>

#define N 4

int cost[N][N] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};

int assign(int cost[N][N], int n) {
    int i, j;
    int x[n];
    int y[n];
    int u[n];
    int v[n];
    for (i = 0; i < n; i++) {
        x[i] = -1;
        y[i] = -1;
    }

    for (i = 0; i < n; i++) {
        u[i] = 0;
        v[i] = 0;
    }

    for (i = 0; i < n; i++) {
        int links[n];
        int mins[n];
        int visited[n];
        for (j = 0; j < n; j++) {
            mins[j] = INT_MAX;
            visited[j] = 0;
            links[j] = -1;
        }

        int j = 0;
        while (1) {
            int i1 = x[j];
            int delta = INT_MAX;
            int j1 = -1;

            visited[j] = 1;
            for (int j2 = 0; j2 < n; j2++) {
                if (!visited[j2]) {
                    int cur = cost[i][j2] - u[i] - v[j2];
                    if (cur < mins[j2]) {
                        mins[j2] = cur;
                        links[j2] = j;
                    }
                    if (mins[j2] < delta) {
                        delta = mins[j2];
                        j1 = j2;
                    }
                }
            }

            for (int j2 = 0; j2 < n; j2++) {
                if (visited[j2]) {
                    u[x[j2]] += delta;
                    v[j2] -= delta;
                } else {
                    mins[j2] -= delta;
                }
            }

            j = j1;
            if (x[j] == -1) {
                break;
            }
        }

        while (1) {
            int j1 = links[j];
            x[j] = x[j1];
            j = j1;
            if (x[j] == -1) {
                break;
            }
        }
    }

    int result = 0;
    for (i = 0; i < n; i++) {
        result += cost[i][x[i]];
    }

    return result;
}

int main() {
    int n = N;
    int min_cost = assign(cost, n);
    printf("Minimum cost of assignment: %d\n", min_cost);
    return 0;
}
