#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *sumsCount = malloc(28 * sizeof(int));

    for (int i = 0; i < 10; i++) {
        for (int o = 0; o < 10; o++) {
            for (int k = 0; k < 10; k++) {
                sumsCount[i + o + k]++;
            }
        }
    }

    int ticketsCount = 0;
    for (int i = 0; i < 28; i++) {
        ticketsCount += sumsCount[i] * sumsCount[i];
    }

    printf("%d\n", ticketsCount);

    free(sumsCount);

    return 0;
}