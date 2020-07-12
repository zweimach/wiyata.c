#include <stdio.h>
#include <stdlib.h>

#include "oddities.h"

const char *oddities(int x)
{
    char *result = malloc(sizeof(char) * 12);

    if (x % 2 == 0) {
        sprintf(result, "%d is even", x);
    } else {
        sprintf(result, "%d is odd", x);
    }
    return result;
}
