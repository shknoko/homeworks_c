#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "compare.h"

int main(void)
{
    int n = 0;
    int k = 0;

    if (scanf("%d %d", &n, &k) != 2) {
        return 1;
    }

    if (n < 0 || k < 0) {
        return 1;
    }

    int* first = calloc(n, sizeof(int));
    int* second = calloc(k, sizeof(int));

    if (first == NULL || second == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &first[i]) != 1) {
            free(first);
            free(second);
            return 1;
        }
    }

    for (int i = 0; i < k; i++) {
        if (scanf("%d", &second[i]) != 1) {
            free(first);
            free(second);
            return 1;
        }
    }

    int res = compare(first, second, n, k);
    if (res == 2) {
        printf("первое больше\n");
    } else if (res == 1) {
        printf("второе больше\n");
    } else {
        printf("числа равны\n");
    }

    free(first);
    free(second);
    return 0;
}