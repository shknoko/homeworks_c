#include "list.h"
#include <stdio.h>

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

            if (indexOf(list, val, &index) != 2) {
                insert(list, val, index);
            }

            break;
        case 2:
            scanf("%d", &val);

            if (!indexOf(list, val, &index)) {
                pop(list, index, &val);
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
