#include <math.h>
#include <stdio.h>

#include "ladder.h"

static double const PI = 3.14159265358979323846;

static double sind(unsigned angle)
{
    return sin(fmod((angle), 360) * PI / 180);
}

unsigned ladder(unsigned wall_height, unsigned safe_angle)
{
    return ceil(wall_height / sind(safe_angle));
}
