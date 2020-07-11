#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "to_lower.h"

int to_lower(char ***str_list, int cases, int data)
{
    int result = 0;

    for (int i = 0; i < cases; i++) {
        bool true_case = true;
        for (int j = 0; j < data; j++) {
            for (int k = 1; k < strlen(str_list[i][j]); k++) {
                if (!islower(str_list[i][j][k])) {
                    true_case = false;
                }
            }
        }
        if (true_case) {
            result++;
        }
    }
    return result;
}
