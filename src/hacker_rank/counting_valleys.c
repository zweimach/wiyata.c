#include "counting_valleys.h"

int countingValleys(int steps, char path[steps])
{
    unsigned valleys = 0;
    int pos = 0;
    for (unsigned i = 0; i < steps; i++) {
        if (path[i] == 'U' && pos == -1) {
            valleys += 1;
            pos += 1;
        } else if (path[i] == 'U') {
            pos += 1;
        } else if (path[i] == 'D') {
            pos -= 1;
        }
    }
    return valleys;
}
