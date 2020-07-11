#include <stdio.h>
#include <math.h>

#include "pot.h"

long pot(int p[], int n)
{
    unsigned a, b;
    long x = 0;

    for (int i = 0; i < n; i++) {
        a = p[i] / 10;
        b = p[i] % 10;
        x = x + powl(a, b);
    }
    return x;
}
