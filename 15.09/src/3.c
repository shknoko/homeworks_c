#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 0;
    int counter = 0;
    scanf("%d\n", &n);

    int *array = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < n; i++) {
        if (!array[i]) {
            counter++;
        }
    }

    printf("%d\n", counter);

    free(array);
    return 0;
}