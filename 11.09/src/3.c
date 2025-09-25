#include <stdio.h>
#include <stdlib.h>

int *reverse_first_part(int a, int *array);
int *reverse_second_part(int a, int b, int *array);
int *reverse_full_array(int sum, int *array);

int *reverse_first_part(int a, int *array)
{
    for (int i = 0; i < a / 2; i++) {
        int temp = array[i];
        array[i] = array[a - i - 1];
        array[a - i - 1] = temp;
    }

    return array;
}

int *reverse_second_part(int a, int b, int *array)
{
    for (int i = 0; i < b / 2; i++) {
        int temp = array[a + i];
        array[a + i] = array[a + b - i - 1];
        array[a + b - i - 1] = temp;
    }

    return array;
}

int *reverse_full_array(int sum, int *array)
{
    for (int i = 0; i < sum / 2; i++) {
        int temp = array[i];
        array[i] = array[sum - i - 1];
        array[sum - i - 1] = temp;
    }

    return array;
}

int main(void)
{
    unsigned int m = 0;
    unsigned int n = 0;
    scanf("%u%u", &m, &n);

    int *array = malloc((n + m) * sizeof(int));

    for (int i = 0; i < n + m; i++) {
        scanf("%d", &array[i]);
    }

    array = reverse_first_part(m, array);
    array = reverse_second_part(m, n, array);
    array = reverse_full_array(m + n, array);

    for (int i = 0; i < n + m; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    free(array);

    return 0;
}