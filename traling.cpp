#include <stdio.h>
#include <string.h>
#include <ctype.h>

char production[10][10];
char trail[10][10];
int n;

void findTrailing(char nt, int row) {
    for (int i = 0; i < n; i++) {
        if (production[i][0] == nt) {
            int len = strlen(production[i]);

            // Case 1: if RHS ends with a terminal
            if (!isupper(production[i][len - 1]))
                trail[row][strlen(trail[row])] = production[i][len - 1];

            // Case 2: if RHS ends with a non-terminal
            else if (isupper(production[i][len - 1]))
                findTrailing(production[i][len - 1], row);

            // Case 3: if RHS ends with ')'
            else if (production[i][len - 1] == ')')
                trail[row][strlen(trail[row])] = ')';
        }
    }
}

int main() {
    int i, j;
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter the productions (use -> format, e.g., E->E+T):\n");
    for (i = 0; i < n; i++) {
        scanf("%s", production[i]);
    }

    for (i = 0; i < n; i++)
        trail[i][0] = '\0';

    for (i = 0; i < n; i++) {
        findTrailing(production[i][0], i);
    }

    printf("\nTRAILING sets:\n");
    for (i = 0; i < n; i++) {
        printf("TRAILING(%c) = { ", production[i][0]);
        for (j = 0; j < strlen(trail[i]); j++)
            printf("%c ", trail[i][j]);
        printf("}\n");
    }

    return 0;
}

