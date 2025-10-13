#include <stdio.h>

int fibonacci(int n);

int fibonacci(int n)
{
    if (n <= 1) {
        return n == 1 ? 1 : 0;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void)
{
    unsigned sum = 0;

    for (int i = 0; i < 1000000; i++) {
        if (fibonacci(i) % 2 == 0) {
            sum += fibonacci(i);
        }
        if (fibonacci(i) >= 1000000) {
            break;
        }
    }

    printf("%u\n", sum);
    return 0;
}