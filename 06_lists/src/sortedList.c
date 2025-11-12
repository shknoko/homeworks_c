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
        if (op == 0) {
            deleteList(list);
            return 0;
        } else if (op == 1) {
            unsigned index = 0;
            int val = 0;
            scanf("%d", &val);

            if (indexOf(list, val, &index) != 2) {
                insert(list, val, index);
            }
        } else if (op == 2) {
            int val = 0;
            scanf("%d", &val);

            unsigned index = 0;
            if (!indexOf(list, val, &index)) {
                pop(list, index, &val);
            }
        } else if (op == 3) {
            printList(list, 0, -1);
        }
    }

    deleteList(list);
    return 0;
}
