#include "circularList.h"
#include <stdio.h>

int main(void)
{
    int n = 0, m = 0;
    scanf("%d%d", &n, &m);

    List* list = newList();
    int listLen = n;

    for (int i = 1; i <= n; i++) {
        if (!insert(list, i, i - 1)) {
            deleteList(list);
            return 1;
        }
    }

    int currentIndex = m - 1;
    while (listLen > 1) {
        if (!del(list, currentIndex)) {
            deleteList(list);
            return 1;
        }
        listLen--;
        currentIndex = (currentIndex + m - 1) % listLen;
    }

    int res = -1;
    if (!find(list, 0, &res)) {
        deleteList(list);
        return 1;
    }

    printf("%d", res);
    deleteList(list);
    return 0;
}