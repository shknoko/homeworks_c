#include <stdio.h>
#include <assert.h>

int division(int x, int y);

int division(int x, int y) {
    int res = 0;

    assert(y != 0); // проверка деления на 0

    if (x >= 0 && y > 0) {
        while (x >= y) {
            x -= y;
            res++;
        }
    }
    else if (x >= 0 && y < 0) {
        while (x > y) {
            x += y;
            res--;
        }

        if (y >= x) {
            x -= y;
            res++;
        }
    }
    else if (x < 0 && y > 0) {
        while (x < y) {
            x += y;
            res--;
        }

        if (x >= y) {
            x += y;
            res++;
        }
    }
    else if (x < 0 && y < 0) {
        while (x <= y) {
            x -= y;
            res++;
        }
    }

    return res;
}

int main(void) {
    int first_int, second_int;

    scanf("%d%d", &first_int, &second_int);
    printf("%d", division(first_int, second_int));

    return 0;
}