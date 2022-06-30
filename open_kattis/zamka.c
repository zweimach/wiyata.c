#include <stdlib.h>

#include "zamka.h"

unsigned sum_of_digits(unsigned value)
{
    if (value == 0) {
        return 0;
    }
    return (value % 10) + sum_of_digits(value / 10);
}

unsigned* zamka(unsigned min, unsigned max, unsigned target)
{
    unsigned index = 0;
    unsigned* arr = malloc(sizeof(unsigned) * max);
    unsigned* result = malloc(sizeof(unsigned) * 2);

    for (unsigned i = min; i <= max; i++) {
        unsigned sod = sum_of_digits(i);
        if (sod == target) {
            arr[index] = i;
            index++;
        }
    }
    result[0] = arr[0], result[1] = arr[index - 1];
    free(arr);
    return result;
}
