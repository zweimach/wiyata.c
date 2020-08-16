#include "cold_puter_science.h"

unsigned cold_puter_science(unsigned n, int input[n])
{
    unsigned result = 0;

    for (int i = 0; i < n; i++) {
        if (input[i] < 0) {
            result += 1;
        }
    }
    return result;
}
