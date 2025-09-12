#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned int n, m, max;
    unsigned int a;
    scanf("%u%u", &m, &n);

    if (m > n) {
        max = m;
        a = 0;
    }
    else { 
        max = n;
        a = 1;
    }


    int *start = malloc(max * sizeof(int));
    int *end = malloc(max * sizeof(int));

    for (unsigned int i = 0; i < max; i++) {
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

    for (unsigned int i = 0; i < max; i++) {
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
    for (unsigned int i = 0; i < max; i++) {
        temp = start[i];
        start[i] = end[i];
        end[i] = temp;
    }

    for (unsigned int i = 0; i < n; i++) {
        printf("%d ", start[i]);
    }
    printf("\n");

    for (unsigned int i = 0; i < m; i++) {
        printf("%d ", end[i]);
    }
    printf("\n");

    free(start);
    free(end);

    return 0;
}