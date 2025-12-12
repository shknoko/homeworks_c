#include "compare.h"

int compare(int* first, int* second, int n, int k)
{
    int startFirst = 0;
    while (startFirst < n && first[startFirst] == 0) {
        startFirst++;
    }

    int startSecond = 0;
    while (startSecond < k && second[startSecond] == 0) {
        startSecond++;
    }

    int len1 = n - startFirst;
    int len2 = k - startSecond;

    if (len1 > len2) {
        return 2;
    } else if (len2 > len1) {
        return 1;
    }

    for (int i = 0; i < len1; i++) {
        if (first[startFirst + i] > second[startSecond + i]) {
            return 2;
        } else if (second[startSecond + i] > first[startFirst + i]) {
            return 1;
        }
    }

    return 0;
}