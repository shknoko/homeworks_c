#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 0;
    scanf("%d\n", &n);

    char *string = malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        scanf("%d\n", string[i]);
    }

    int balance = 0;

    for (int charNum = 0; charNum < n; charNum++) {
        if (string[charNum] == '(') {
            balance++;
        } else if (string[charNum] == ')') {
            balance--;
            if (balance < 0) {
                printf("Баланс скобок не соблюдён\n");
                free(string);
                return 0;
            }
        }
    }

    if (balance != 0) {
        printf("Баланс скобок не соблюдён\n");
        free(string);
        return 0;
    }

    printf("Баланс скобок соблюдён\n");
    free(string);
    return 0;
}