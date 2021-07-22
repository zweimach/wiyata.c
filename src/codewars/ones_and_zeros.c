#include <math.h>
#include <stdio.h>

#include "ones_and_zeros.h"

unsigned binary_array_to_numbers(unsigned const* bits, size_t count)
{
    int pos = 0;
    unsigned n = 0;

    for (int i = count - 1; i >= 0; i--) {
        n += (bits[i] * (unsigned)pow(2, pos));
        pos += 1;
    }
    return n;
}
