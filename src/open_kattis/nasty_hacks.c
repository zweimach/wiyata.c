#include <stdio.h>
#include <stdlib.h>

#include "nasty_hacks.h"

char const** nasty_hacks(unsigned n, unsigned input[n][3])
{
    enum { r, e, c };
    char** result = malloc(sizeof(char*) * n);

    for (unsigned i = 0; i < n; i++) {
        result[i] = malloc(sizeof(char) * 18);
        if (input[i][r] + input[i][c] < input[i][e])
            sprintf(result[i], "advertise");
        else if (input[i][r] + input[i][c] > input[i][e])
            sprintf(result[i], "do not advertise");
        else
            sprintf(result[i], "does not matter");
    }
    return (char const**)result;
}
