#include <stdio.h>
#include <string.h>

void naivePatternMatch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main() {
    char text[100], pattern[100];

    printf("Enter the text: ");
    gets(text);
    printf("Enter the pattern: ");
    gets(pattern);

    naivePatternMatch(text, pattern);
    printf("false");

    return 0;
}
