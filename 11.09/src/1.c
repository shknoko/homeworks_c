#include <stdio.h>
#include <assert.h>

int main(void) {
    int x;
    scanf("%d", &x);

    assert(x > -216 && x < 216); // при выходе за отрезок [-216; 216] возникает переполнение

    printf("%d\n", (x * x + x) * (x * x + 1) + 1);
    return 0;
}