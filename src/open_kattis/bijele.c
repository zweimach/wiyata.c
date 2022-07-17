#include "bijele.h"

int* bijele(int const input[6])
{
    static int const pieces[6] = {1, 1, 2, 2, 2, 8};
    static int result[6] = {0};

    for (unsigned i = 0; i < 6; i++) {
        result[i] = pieces[i] - input[i];
    }
    return result;
}
