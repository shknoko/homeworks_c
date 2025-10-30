#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

bool substrCount(char* s, char* s1, int lenS, int lenS1, int* counter)
{
    for (int i = 0; i < lenS; i++) {
        int matchLen = 0;

        for (int o = i; o < MIN(lenS, i + lenS1); o++) {
            if (s1[o - i] != s[o]) {
                break;
            }
            matchLen++;
        }

        if (matchLen == lenS1) {
            (*counter)++;
        }
    }

    return false;
}

int main(void)
{
    int counter = 0;
    int lenS = 0;
    int lenS1 = 0;
    scanf("%d%d\n", &lenS, &lenS1);

    char* s = malloc((lenS + 1) * sizeof(char));
    char* s1 = malloc((lenS1 + 1) * sizeof(char));

    fgets(s, lenS + 1, stdin);
    getchar();
    fgets(s1, lenS1 + 1, stdin);

    substrCount(s, s1, lenS, lenS1, &counter);

    printf("%d\n", counter);

    free(s);
    free(s1);

    return 0;
}