#include "sort.h"

int selectionSort(int* array, int n)
{
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        int minIndex = i;

        for (int o = i + 1; o < n; o++) {
            if (array[o] < array[minIndex]) {
                minIndex = o;
            }
        }

        if (minIndex != i) {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
            swaps++;
        }
    }

    return swaps;
}