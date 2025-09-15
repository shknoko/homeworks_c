#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* sums_count = malloc(28 * sizeof(int));

    for (int i = 0; i < 10; i++) {
        for (int o = 0; o < 10; o++) {
            for (int k = 0; k < 10; k++) {
                sums_count[i + o + k]++;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < 28; i++) {
        cnt += sums_count[i] * sums_count[i];
    }

    printf("%d\n", cnt);

    return 0;
}