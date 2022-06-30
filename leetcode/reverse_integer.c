#include <stdint.h>

#include "reverse_integer.h"

int reverse(int x)
{
    if (x == 0 || x < INT32_MIN || x > INT32_MAX)
        return 0;

    int result = 0;
    while (x != 0) {
        if (result * 10L < INT32_MIN || result * 10L > INT32_MAX)
            return 0;
        result = result * 10 + (x % 10);
        x = (x / 10) | 0;
    }
    return result;
}
