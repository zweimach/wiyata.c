#include <string.h>

#include "reversed_binary_numbers.h"

int reversed_binary_numbers(int n)
{
    int r = 0, t = 1;
    char bin[30];

    memset(bin, 0, 30);
    for (int i = 0; n > 0; i++, n /= 2) {
        bin[i] = (n % 2) + 48;
    }
    for (int j = 29; j >= 0; j--) {
        if (bin[j] != 0) {
            r = r + (bin[j] - 48) * t;
            t *= 2;
        }
    }
    return r;
}
