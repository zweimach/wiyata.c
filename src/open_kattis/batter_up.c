#include "batter_up.h"

double batter_up(int n, int const batters[n])
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
