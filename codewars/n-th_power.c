#include <math.h>

#include "n-th_power.h"

int index(int* array, int size, int n)
{
    if (n >= size) {
        return -1;
    }
    return pow(array[n], n);
}
