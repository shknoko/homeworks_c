#include <stdio.h>
#include <assert.h>

int main(void)
{
    int x;
    scanf("%d", &x);

    assert(x > -216 && x < 216); // при выходе за отрезок [-216; 216] возникает переполнение

    int xPow2 = x * x;

    printf("%d\n", (xPow2 + x) * (xPow2 + 1) + 1);
    return 0;
}