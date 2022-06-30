#include <stdio.h>

#include "herman.h"

static double const PI = 3.141592653589793;

double* herman(int r)
{
    static double result[2];

    result[0] = r * PI * r;
    result[1] = (r + r) * r;
    return result;
}
