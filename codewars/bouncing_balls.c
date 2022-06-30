#include "bouncing_balls.h"

int bouncingBall(double h, double bounce, double window)
{
    if (h < 0 || bounce <= 0 || bounce >= 1 || window >= h)
        return -1;
    int result = 1;
    while ((h = h * bounce) > window)
        result += 2;
    return result;
}
