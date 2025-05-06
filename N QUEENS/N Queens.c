#include <stdio.h>
#include <math.h>

int x[20], count = 1;

int place(int k, int j) {
    int i;
    for (i = 1; i < k; i++) {
        if (x[i] == j || abs(x[i] - j) == abs(i - k))
            return 0;
    }
    return 1;
}

void queens(int k, int n) {
    int i, j;
    for (j = 1; j <= n; j++) {
        if (place(k, j)) {
            x[k] = j;
            if (k == n) {
                printf("\n%d solution", count);
                count++;
                for (i = 1; i <= n; i++)
                    printf("\n\t%d row <--> %d column", i, x[i]);
                printf("\n");
            } else {
                queens(k + 1, n);
            }
        }
    }
}

int main() {
    int n, k = 1;
    printf("\nEnter the number of queens to be placed: ");
    scanf("%d", &n);
    queens(k, n);
    return 0;
}
