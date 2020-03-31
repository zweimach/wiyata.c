#include <stdio.h>

#include "batter_up.h"

double batter_up(int batters[], int n)
{
    int r = 0, u = 0;

    for (int i = 0; i < n; i++) {
        if (batters[i] >= 0) {
            r += batters[i];
            u++;
        }
    }
    return (double)r / u;
}
