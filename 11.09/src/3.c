#include <stdio.h>

int main(void) {
    int n, m, max;
    short int a;
    scanf("%d%d", &m, &n);

    if (m > n) {
        max = m;
        a = 0;
    }
    else { 
        max = n;
        a = 1;
    }

    int start[max];
    int end[max];

    for (int i = 0; i < max; i++) {
        if (a == 1) {
            if (i < m) {
                scanf("%d", &start[i]);
            }
            else {
                start[i] = 0;
            }
        }
        else {
            scanf("%d", &start[i]);
        }
    }

    for (int i = 0; i < max; i++) {
        if (a == 0) {
            if (i < n) {
                scanf("%d", &end[i]);
            }
            else {
                end[i] = 0;
            }
        }
        else {
            scanf("%d", &end[i]);
        }
    }

    int temp;
    for (int i = 0; i < max; i++) {
        temp = start[i];
        start[i] = end[i];
        end[i] = temp;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", start[i]);
    }
    printf("\n");

    for (int i = 0; i < m; i++) {
        printf("%d ", end[i]);
    }
    printf("\n");

    return 0;
}