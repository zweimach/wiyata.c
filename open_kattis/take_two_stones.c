#include <stdio.h>

#include "take_two_stones.h"

char const* take_two_stones(int stones)
{
    if (stones % 2 == 0) {
        return "Bob";
    }
    return "Alice";
}
