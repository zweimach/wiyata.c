#include <math.h>

#include "rocket_equation.h"

unsigned rocket_equation(unsigned n, unsigned a[n])
{
    unsigned s = 0;
    for (unsigned i = 0; i < n; i++)
        s += floor((double)a[i] / 3) - 2;
    return s;
}

unsigned rocket_equation_part_two(unsigned n, unsigned a[n])
{
    int s = 0;
    for (int i = 0, t = a[i]; i < n; i++, t = a[i])
        while ((t = floor((double)t / 3) - 2) >= 0)
            s += t;
    return s;
}
