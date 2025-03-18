#include <stdio.h>
#include <time.h>

void simple_merge(int a[], int n, int l, int mid, int h) {
    int i = l, j = mid + 1, k = l;
    int c[n];

    while (i <= mid && j <= h) {
        if (a[i] < a[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = a[j++];
        }
    }


    while (i <= mid) {
        c[k++] = a[i++];
    }


    while (j <= h) {
        c[k++] = a[j++];
    }


    for (i = l; i <= h; i++) {
        a[i] = c[i];
    }
}

void merge_sort(int a[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, h);
        simple_merge(a, h + 1, l, mid, h);
    }
}

int main() {
    clock_t start, end;
    int i, n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    start = clock();
    merge_sort(a, 0, n - 1);
    end = clock();

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    float time = (float)(end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds in ns\n", time);

    return 0;
}


