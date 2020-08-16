#include <stdio.h>
#include <stdlib.h>

#include "number_fun.h"

char const **number_fun(unsigned n, unsigned input[n][3])
{
    enum { a, b, c };
    char **result = malloc(sizeof(char *) * n);

    for (int i = 0; i < n; i++) {
        unsigned *op = input[i];
        result[i] = malloc(sizeof(char) * 12);
        if (op[a] + op[b] == op[c] || op[a] - op[b] == op[c]
            || op[a] * op[b] == op[c] || (float)op[a] / op[b] == op[c])
            sprintf(result[i], "Possible");
        else if (op[b] + op[a] == op[c] || op[b] - op[a] == op[c]
                 || op[b] * op[a] == op[c] || (float)op[b] / op[a] == op[c])
            sprintf(result[i], "Possible");
        else
            sprintf(result[i], "Impossible");
    }
    return (char const **)result;
}
