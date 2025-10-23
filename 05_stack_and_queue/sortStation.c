#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int getPriority(char operation) 
{
    if (operation == '*' || operation == '/') {
        return 2;
    } else if (operation == '+' || operation == '-') {
        return 1;
    }
    return 0;
}

int sortStation(char* str, char* res) 
{
    unsigned lastUsedResIndex = 0;
    Stack* stack = newStack();
    for (unsigned long i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) {
            if (lastUsedResIndex > 0 && res[lastUsedResIndex - 1] != ' ') {
                res[lastUsedResIndex] = ' ';
                lastUsedResIndex++;
            }
            res[lastUsedResIndex] = str[i];
            lastUsedResIndex++;
        } else if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/')) {
            while (!isEmpty(stack)) {
                char peeked = peek(stack);
                if (peeked == '(') {
                    break;
                }
                if (getPriority(peeked) >= getPriority(str[i])) {
                    if (lastUsedResIndex > 0 && res[lastUsedResIndex - 1] != ' ') {
                        res[lastUsedResIndex] = ' ';
                        lastUsedResIndex++;
                    }
                    res[lastUsedResIndex] = pop(stack);
                    lastUsedResIndex++;
                } else {
                    break;
                }
            }
            push(stack, str[i]);
        } else if (str[i] == '(') {
            push(stack, str[i]);
        } else if (str[i] == ')') {
            char popped = pop(stack);
            while (popped != '(') {
                if (lastUsedResIndex > 0 && res[lastUsedResIndex - 1] != ' ') {
                    res[lastUsedResIndex] = ' ';
                    lastUsedResIndex++;
                }
                res[lastUsedResIndex] = popped;
                lastUsedResIndex++;

                if (!isEmpty(stack)) {
                    popped = pop(stack);
                } else {
                    deleteStack(stack);
                    return 1;
                }
            }
        }
    }
    while (!isEmpty(stack)) {
        char popped = pop(stack);
        if (popped == '(') {
            deleteStack(stack);
            return 1;
        }
        if (lastUsedResIndex > 0 && res[lastUsedResIndex - 1] != ' ') {
            res[lastUsedResIndex] = ' ';
            lastUsedResIndex++;
        }
        res[lastUsedResIndex] = popped;
        lastUsedResIndex++;
    }
    deleteStack(stack);
    return 0;
}

int main(void) {
    int n = 0;
    scanf("%d\n", &n);

    char* input = calloc(n + 1, sizeof(char));
    fgets(input, n + 1, stdin);

    char* res = calloc(n + 1, sizeof(char));
    res[n] = '\0';

    if (sortStation(input, res) == 0) {
        printf("%s\n", res);
    } else {
        printf("Входная строка некорректна");
    }

    free(input);
    free(res);
    return 0;
}