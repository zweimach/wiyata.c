#include <stdio.h>
#include <math.h>

int planina(int n)
{
    int i = 2;

    for (int j = 0; j < n; j++) {
        i = i + powl(2, j);
    }
    return i * i;
}
