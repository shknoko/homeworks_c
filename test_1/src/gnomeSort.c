#include <stdio.h>
#include <stdlib.h>

int *gnomeSort(int *array, int arrayLen);

int *gnomeSort(int *array, int arrayLen) 
{
    int j = 2;
    int i = 1;
    while (i < arrayLen) {
        if (array[i - 1] < array[i]) {
            i = j;
            j++;
        } else {
            int temp = array[i - 1];
            array[i - 1] = array[i];
            array[i] = temp;
            i--;

            if (i == 0) {
                i = j;
                j++;
            }
        }
    }

    return array;
}

int main(void) 
{
    int n = 0;
    scanf("%d", &n);

    int *array = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int *sortedArray = gnomeSort(array, n);

    for (int i = 0; i < n; i++) {
        printf("%d\n", sortedArray[i]);
    }

    free(sortedArray);
    return 0;
}