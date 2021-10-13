#include <stdio.h>
#include <stdlib.h>

#include "how_much.h"

char* howmuch(int m, int n)
{
    if (m > n) {
        m = m - n;
        n = m + n;
        m = n - m;
    }

    int* fs = malloc(sizeof(int) * (n - m));
    int fslen = 0;
    for (int i = m; i <= n; i++) {
        if (i % 7 == 2 && i % 9 == 1) {
            fs[fslen] = i;
            fslen += 1;
        }
    }

    int bufflen = snprintf(NULL, 0, "%d", n);
    char* result = calloc(sizeof(char), (3 * bufflen + 13) * fslen + 3);
    bufflen = sprintf(result, "[");
    for (int i = 0; i < fslen; i++) {
        int f = fs[i], b = (f - 2) / 7, c = (f - 1) / 9;
        bufflen += sprintf(result + bufflen, "[M: %d B: %d C: %d]", f, b, c);
    }
    sprintf(result + bufflen, "]");

    free(fs);
    return result;
}
