#include "modulo.h"

unsigned modulo(unsigned const input[10])
{
    unsigned mod[10];
    int count = 10;

    for (int i = 0; i < 10; i++) {
        mod[i] = input[i] % 42;
    }
    for (int j = 0; j < 10; j++) {
        for (int k = j + 1; k < 10; k++) {
            if (mod[j] == mod[k]) {
                count--;
                break;
            }
        }
    }
    return count;
}
