#include "perang_dunia_ketiga.h"

int perang_dunia_ketiga(int laser_powers[], int invasions)
{
    int remains = 0;
    int min_power = 1;

    for (int i = 0; i < invasions; i++) {
        while (min_power - laser_powers[i] < 0) {
            min_power *= 2;
        }
        if (laser_powers[i] > 0) {
            remains += min_power - laser_powers[i];
        }
        min_power = 1;
    }

    return remains;
}
