#include <stdio.h>

#include "restoran_chanek.h"

int restoran_chanek(int duration[], int cooks, int foods)
{
    int total = 0;
    for (int i = 0; i < (foods * cooks); i++) {
        total = total + duration[i];
    }
    return total;
}