#include "stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int bracketsChecker(char* str, bool* res)
{
    Stack* stack = newStack();
    for (unsigned long i = 0; i < strlen(str); i++) {
        if ((str[i] == '(') || (str[i] == '[') || (str[i] == '{')) {
            push(stack, str[i]);
        } else if ((str[i] == ')') || (str[i] == ']') || (str[i] == '}')) {
            if (!isEmpty(stack)) {
                char popped = pop(stack);
                if (((str[i] == ')') && (popped != '(')) || ((str[i] == ']') && (popped != '[')) || ((str[i] == '}') && (popped != '{'))) {
                    *res = false;
                }
            } else {
                *res = false;
            }
        }
    }
    *res = *res && isEmpty(stack);
    deleteStack(stack);
    return 0;
}


int main(void)
{
    int n = 0;
    scanf("%d\n", &n);

    char* input = calloc(n + 1, sizeof(char));
    fgets(input, n + 1, stdin);

    bool res = true;
    bracketsChecker(input, &res);

    printf("%d\n", res);
    free(input);
    return 0;
}