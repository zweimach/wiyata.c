#include <stdio.h>

int tarifa(int x, int n, int* p)
{
    int total = x * (n + 1);

    for (int i = 0; i < n; i++) {
        total = total - p[i];
    }
    return total;
}
