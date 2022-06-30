#include "perang_dunia_ketiga.h"

unsigned perang_dunia_ketiga(unsigned n, unsigned const input[n])
{
    unsigned result = 0;
    long min_power = 1;

    for (unsigned i = 0; i < n; i++) {
        while (min_power - input[i] < 0) {
            min_power *= 2;
        }
        if (input[i] > 0) {
            result += min_power - input[i];
        }
        min_power = 1;
    }
    return result;
}
