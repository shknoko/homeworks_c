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
    unsigned long len = strlen(str);
    for (unsigned long i = 0; i < len; i++) {
        if (isdigit(str[i])) {
            if (lastUsedResIndex > 0 && res[lastUsedResIndex - 1] != ' ') {
                res[lastUsedResIndex] = ' ';
                lastUsedResIndex++;
            }
            while (i < len && isdigit(str[i])) {
                res[lastUsedResIndex] = str[i];
                lastUsedResIndex++;
                i++;
            }
            if (i < len) {
                i--;
            }
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
            char peeked = 0;
            if (!isEmpty(stack)) {
                peeked = peek(stack);
            } else {
                deleteStack(stack);
                return 1;
            }
            while (peeked != '(') {
                if (lastUsedResIndex > 0 && res[lastUsedResIndex - 1] != ' ') {
                    res[lastUsedResIndex] = ' ';
                    lastUsedResIndex++;
                }
                res[lastUsedResIndex] = peeked;
                lastUsedResIndex++;
                pop(stack);

                if (!isEmpty(stack)) {
                    peeked = peek(stack);
                } else {
                    deleteStack(stack);
                    return 1;
                }
            }
            pop(stack);
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
    res[lastUsedResIndex] = '\0';
    deleteStack(stack);
    return 0;
}

int main(void) {
    int n = 0;
    scanf("%d\n", &n);

    char* input = calloc(n + 1, sizeof(char));
    fgets(input, n + 1, stdin);

    char* res = calloc(n + 1, sizeof(char));

    if (sortStation(input, res) == 0) {
        printf("%s\n", res);
    } else {
        printf("Входная строка некорректна");
    }

    free(input);
    free(res);
    return 0;
}
