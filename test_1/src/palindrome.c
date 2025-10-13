#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool palindromeChecker(char *string, int strLen);
char *removeWhitespaces(char *string, int strLen);

char *removeWhitespaces(char *string, int strLen)
{
    char *newString = malloc(strLen * sizeof(char));
    int p = 0;
    for (int i = 0; i < strLen; i++) {
        if (string[i] != ' ') {
            newString[p] = string[i];
            p++;
        }
    }

    newString = realloc(newString, (p - 1) * sizeof(char));
    return newString;
}

bool palindromeChecker(char *string, int strLen)
{
    int fromAnotherBorder = strLen - 1;
    for (int i = 0; i < strLen / 2; i++) {
        fromAnotherBorder = strLen - i - 1;
        if (string[i] != string[fromAnotherBorder]) {
            return false;
        }
    }
    return true;
}

int main(void) 
{
    int n = 0;
    scanf("%d\n", &n);

    char string[n + 1];
    fgets(string, n + 1, stdin);

    char *cleanString = removeWhitespaces(string, strlen(string));

    printf("%d\n", palindromeChecker(cleanString, strlen(cleanString)));

    free(cleanString);
    return 0;
}