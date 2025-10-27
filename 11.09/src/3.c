#include <stdio.h>
#include <stdlib.h>

int reverseArray(unsigned a, unsigned b, int *array);

int reverseArray(unsigned a, unsigned b, int *array)
{
    if (b < a) {
        return 1;
    }

    for (unsigned i = 0; i < (b - a + 1) / 2; i++) {
        int temp = array[a + i];
        array[a + i] = array[b - i];
        array[b - i] = temp;
    }

    return 0;
}

int main(void)
{
    unsigned m = 0;
    unsigned n = 0;
    scanf("%u%u", &m, &n);

    int* array = calloc(n + m, sizeof(int));

    for (unsigned i = 0; i < n + m; i++) {
        scanf("%d", &array[i]);
    }

    if (((m != 0) && (n != 0))) {
        if ((reverseArray(0, m - 1, array) != 0) || (reverseArray(m, m + n - 1, array) != 0) || (reverseArray(0, m + n - 1, array) != 0)) {
            return 1;
        }
    }

    for (unsigned i = 0; i < n + m; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    free(array);

    return 0;
}
