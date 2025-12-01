#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../src/compare.h"

void testEqualNumbers()
{
    int a[6] = { 1, 0, 1, 1, 1, 0 };
    int b[6] = { 1, 0, 1, 1, 1, 0 };
    assert(compare(a, b, 6, 6) == 0);
}

void testFirstBigger()
{
    int a[6] = { 1, 0, 1, 1, 1, 1 };
    int b[6] = { 1, 0, 1, 1, 1, 0 };
    assert(compare(a, b, 6, 6) == 2);
}

void testSecondBigger()
{
    int a[6] = { 0, 0, 1, 1, 1, 0 };
    int b[6] = { 1, 0, 1, 1, 1, 0 };
    assert(compare(a, b, 6, 6) == 1);
}

void testLeadingZeros()
{
    int a[9] = { 0, 0, 0, 1, 0, 1, 1, 1, 0 };
    int b[8] = { 0, 0, 1, 0, 1, 1, 1, 0 };
    assert(compare(a, b, 9, 8) == 0);
}

void testZero()
{
    int a[1] = { 0 };
    int b[1] = { 0 };
    assert(compare(a, b, 1, 1) == 0);
}

void testNotEqualLen()
{
    int a[1] = { 0 };
    int b[6] = { 1, 0, 1, 1, 1, 0 };
    assert(compare(a, b, 1, 6) == 1);
}

int main()
{
    testEqualNumbers();
    testFirstBigger();
    testSecondBigger();
    testLeadingZeros();
    testZero();
    testNotEqualLen();
    return 0;
}
