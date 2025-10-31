#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int len = 0;
    int* tempArray = malloc(100 * sizeof(int));

    while (scanf("%d", &tempArray[len]) == 1) {
        len += 1;
    }

    int* array = realloc(tempArray, len * sizeof(int));
    int cnt = selectionSort(array, len);

    free(array);
    return cnt;
}