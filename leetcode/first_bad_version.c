#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "first_bad_version.h"

int BAD_VERSION;

int CALL_COUNT = 0;

bool isBadVersion(int version)
{
    return ++CALL_COUNT, BAD_VERSION <= version;
}

int firstBadVersion(int n)
{
    if (n == 1) {
        return 1;
    }
    int floor = 1;
    int ceil = n;
    while (floor < ceil) {
        int distance = ceil - floor;
        int guess = floor + (distance / 2);
        if (!isBadVersion(guess)) {
            if (isBadVersion(guess + 1)) {
                return guess + 1;
            }
            floor = guess + 1;
            continue;
        }
        if (!isBadVersion(guess - 1)) {
            return guess;
        }
        ceil = guess;
    }
    return 0;
}
