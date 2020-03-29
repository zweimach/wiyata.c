#include <stdio.h>

#include "take_two_stones.h"

const char *take_two_stones(int stones)
{
    if (stones % 2 == 0) {
        return "Bob";
    }
    return "Alice";
}
