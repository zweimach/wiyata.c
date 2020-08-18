#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fizzbuzz.h"

char const* fizzbuzz(int x, int y, int n)
{
    char* result = malloc(n * 10 * sizeof(char));
    result[0] = '\0';

    for (int m = 1; m <= n; m++) {
        if (m % x == 0 && m % y == 0) {
            strcat(result, "FizzBuzz\n");
        } else if (m % x == 0) {
            strcat(result, "Fizz\n");
        } else if (m % y == 0) {
            strcat(result, "Buzz\n");
        } else {
            char str[4];
            sprintf(str, "%d\n", m);
            strcat(result, str);
        }
    }
    return result;
}
