#include <string.h>

#include "death_knight_hero.h"

int death_knight_hero(int n, char const* abilities[n])
{
    int wins = n;

    for (int i = 0; i < n; i++) {
        for (unsigned j = 0; j < strlen(abilities[i]); j++) {
            if (abilities[i][j] == 'C' && abilities[i][j + 1] == 'D') {
                wins--;
            }
        }
    }
    return wins;
}
