#include <stdbool.h>
#include <string.h>

#include "trik.h"

unsigned trik(char const* const input)
{
    unsigned result;
    bool cups[] = {true, false, false};

    for (unsigned i = 0; i < strlen(input); i++) {
        bool temp = false;
        if (input[i] == 'A') {
            temp = cups[0];
            cups[0] = cups[1];
            cups[1] = temp;
        } else if (input[i] == 'B') {
            temp = cups[1];
            cups[1] = cups[2];
            cups[2] = temp;
        } else if (input[i] == 'C') {
            temp = cups[0];
            cups[0] = cups[2];
            cups[2] = temp;
        }
    }
    for (unsigned i = 0; i < 3; i++) {
        if (cups[i]) {
            result = i + 1;
        }
    }
    return result;
}
