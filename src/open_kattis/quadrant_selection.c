#include "quadrant_selection.h"

unsigned quadrant_selection(int x, int y)
{
    if (x < 0) {
        return (y < 0) ? 3 : 2;
    } else {
        return (y < 0) ? 4 : 1;
    }
}
