#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))


int main(void)
{
    int substrCount = 0;
    int nS = 0;
    int nS1 = 0;
    scanf("%d%d\n", &nS, &nS1);

    char *s = malloc((nS + 1) * sizeof(char));
    char *s1 = malloc((nS1 + 1) * sizeof(char));

    fgets(s, nS + 1, stdin);
    getchar();
    fgets(s1, nS1 + 1, stdin);

    for (int i = 0; i < nS; i++) {
        int strike = 0;

        for (int o = i; o < MIN(nS, i + nS1); o++) {
            if (s1[o - i] != s[o]) {
                break;
            }
            strike++;
        }

        if (strike == nS1) {
            substrCount++;
        }
    }

    printf("%d\n", substrCount);

    free(s);
    free(s1);

    return 0;
}