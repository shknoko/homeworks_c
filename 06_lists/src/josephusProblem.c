#include "circularList.h"
#include <stdio.h>

bool josephus(int n, int m, int* res)
{
    if (n <= 0 || m <= 0) {
        return false;
    }

    List* list = newList();
    int listLen = n;

    for (int i = 1; i <= n; i++) {
        if (!insert(list, i, i - 1)) {
            deleteList(list);
            return false;
        }
    }

    int currentIndex = (m - 1) % n;
    while (listLen > 1) {
        if (!del(list, currentIndex)) {
            deleteList(list);
            return false;
        }
        listLen--;
        currentIndex = (currentIndex + m - 1) % listLen;
    }

    int last = -1;
    if (!find(list, 0, &last)) {
        deleteList(list);
        return false;
    }

    deleteList(list);
    *res = last;
    return true;
}

int main(void)
{
    int n = 0, m = 0;
    scanf("%d%d", &n, &m);

    int res = -1;
    if (!josephus(n, m, &res)) {
        return 1;
    }

    printf("%d\n", res);
    return 0;
}