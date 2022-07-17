#include "cold_puter_science.h"

unsigned cold_puter_science(unsigned n, int const input[n])
{
    unsigned result = 0;

    for (unsigned i = 0; i < n; i++) {
        if (input[i] < 0) {
            result += 1;
        }
    }
    return result;
}
