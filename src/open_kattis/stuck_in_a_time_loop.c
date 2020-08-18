#include <stdio.h>
#include <stdlib.h>

#include "stuck_in_a_time_loop.h"

char const** stuck_in_a_time_loop(int n)
{
    char** result = malloc(sizeof(char*) * n);

    for (unsigned i = 0; i < n; i++) {
        result[i] = malloc(sizeof(char) * 17);
        sprintf(result[i], "%u Abracadabra", i + 1);
    }
    return (char const**)result;
}
