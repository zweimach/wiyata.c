#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592653589793

double *herman(int r)
{
    double *result = malloc(2 * sizeof(double));

    result[0] = r * PI * r;
    result[1] = (r + r) * r;
    return result;
}
