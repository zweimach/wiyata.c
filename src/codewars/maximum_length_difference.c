#include <stdlib.h>
#include <string.h>

#include "maximum_length_difference.h"

#define FOR_MAX_MIN(array, length, max, min)  \
    for (unsigned i = 1; i < (length); i++) { \
        int c = strlen((array)[i]);           \
        if (c > (max))                        \
            (max) = c;                        \
        if (c < ((min)))                      \
            (min) = c;                        \
    }

int mxdiflg(char const** firstArray,
            size_t firstArrayLength,
            char const** secondArray,
            size_t secondArrayLength)
{
    if (firstArrayLength == 0 || secondArrayLength == 0)
        return -1;

    int fst[] = {(int)strlen(firstArray[0]), fst[0]};
    FOR_MAX_MIN(firstArray, firstArrayLength, fst[0], fst[1]);

    int snd[] = {(int)strlen(secondArray[0]), snd[0]};
    FOR_MAX_MIN(secondArray, secondArrayLength, snd[0], snd[1]);

    int result = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int c = abs(fst[i] - snd[j]);
            if (c > result)
                result = c;
        }
    }

    return result;
}
