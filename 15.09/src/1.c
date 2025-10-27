#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int bracketsChecker(char* string, bool* result)
{

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