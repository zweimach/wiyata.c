#include <stdbool.h>
#include <stdlib.h>

#include "report_repair.h"

static int const SUM = 2020;

int compare(void const* p1, void const* p2)
{
    return *(int*)(p1) - *(int*)(p2);
}

unsigned report_repair(unsigned n, unsigned input[n])
{
    unsigned x = 0, y = 0;

    qsort(input, n, sizeof(unsigned), compare);
    for (unsigned i = 0; i < n; i++) {
        x = input[i];
        y = SUM - x;
        if (bsearch(&y, input, n, sizeof(unsigned), compare)) {
            break;
        }
    }
    return x * y;
}

unsigned report_repair_part_two(unsigned n, unsigned input[n])
{
    bool found = false;
    unsigned x = 0, y = 0, z = 0;

    qsort(input, n, sizeof(unsigned), compare);
    for (unsigned i = 0; i < n; i++) {
        x = input[i];
        for (unsigned j = i + 1; j < n; j++) {
            y = input[j];
            z = SUM - x - y;
            if (bsearch(&z, input, n, sizeof(unsigned), compare)) {
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    return x * y * z;
}
