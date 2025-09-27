#include <stdio.h>
#include <stdlib.h>

int *reverse_array(int a, int b, int *array);

int *reverse_array(int a, int b, int *array)
{
    // если a = 0, то считается, что переворачиваем весь массив
    // если b = 0, то считается, что переворачиваем первую часть
    // если ни a, ни b не равны 0, то считается, что переворачиваем вторую часть длиной b

    int shift = 0;

    if (b == 0) {
        b = a;
        a = 0;
    }
    else if (a != 0 && b != 0) {
        shift = a;
        a = 0;
    }

    for (int i = a; i < b / 2; i++) {
        int temp = array[shift + i];
        array[shift + i] = array[shift + a + b - i - 1];
        array[shift + a + b - i - 1] = temp;
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

    array = reverse_array(m, 0, array);
    array = reverse_array(m, n, array);
    array = reverse_array(0, m + n, array);

    for (int i = 0; i < n + m; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    free(array);

    return 0;
}