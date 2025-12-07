#include <stdio.h>

#include "list.h"

bool add(List* list, int val)
{
    unsigned index = 0;
    if (indexOf(list, val, &index) != 2) {
        insert(list, val, index);
        return true;
    }

    return false;
}

bool rm(List* list, int val)
{
    unsigned index = -1;
    int res = indexOf(list, val, &index);

    if (!res) {
        pop(list, index, &val);
    } else if (res == 2) {
        return false;
    }

    return true;
}

int main(void)
{
    int op = 0;
    List* list = newList();
    if (list == NULL) {
        return 1;
    }

    while (scanf("%d", &op) == 1) {
        unsigned index = 0;
        int val = 0;

        switch (op) {
        case 0:
            deleteList(list);
            return 0;
        case 1:
            scanf("%d", &val);

            if (!add(list, val)) {
                deleteList(list);
                return 1;
            }

            break;
        case 2:
            scanf("%d", &val);

            if (!rm(list, val)) {
                deleteList(list);
                return 1;
            }

            break;
        case 3:
            printList(list, 0, -1);
            break;
        }
    }

    deleteList(list);
    return 0;
}
