#include <stdbool.h>
#include <stdlib.h>

#include "reorder.h"

char const* reorder(unsigned n, unsigned const a[n], unsigned m)
{
    unsigned r = 0;

    for (unsigned i = 0; i < n; i++) {
        r += a[i];
    }
    return r == m ? "YES" : "NO";
}
