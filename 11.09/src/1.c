#include <stdio.h>
#include <assert.h>

int main(void) {
    int x;
    scanf("%d", &x);

    assert(x > -216 && x < 216); // при выходе за отрезок [-216; 216] возникает переполнение

    int x_pow_2 = x * x;

    printf("%d\n", (x_pow_2 + x) * (x_pow_2 + 1) + 1);
    return 0;
}