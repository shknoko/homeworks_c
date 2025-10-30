#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool bracketsChecker(char* string, bool* result)
{
    int balance = 0;
    unsigned long len = strlen(string);

    for (unsigned long i = 0; i < len; i++) {
        if (string[i] == '(') {
            balance++;
        } else if (string[i] == ')') {
            balance--;
            if (balance < 0) {
                *result = false;
            }
        }
    }

    if (balance != 0) {
        *result = false;
    }

    return ;
}

int main(void)
{
    int n = 0;
    scanf("%d\n", &n);

    char* input = calloc(n + 1, sizeof(char));
    fgets(input, n + 1, stdin);

    bool result = true;

    bracketsChecker(input, &result);
    printf("%d\n", result);

    free(input);
    return 0;
}