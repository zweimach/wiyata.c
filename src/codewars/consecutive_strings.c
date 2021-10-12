#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "consecutive_strings.h"

char* longestConsec(char* strarr[], int n, int k)
{
    unsigned start = 0, max = 0;
    unsigned* lenarr = malloc(sizeof(unsigned) * n);

    for (int i = 0; i < n; i++) {
        lenarr[i] = strlen(strarr[i]);
    }
    for (int i = 0; i < n; i++) {
        unsigned total = 0;
        if (n - i < k)
            break;
        for (int j = 0; j < k; j++) {
            total += lenarr[i + j];
        }
        if (total > max) {
            max = total;
            start = i;
        }
    }
    free(lenarr);

    if (max < 1) {
        return calloc(sizeof(char), 1);
    }

    char* longest = calloc(sizeof(char), max + 1);
    for (int i = 0, buffer_length = 0; i < k; i++) {
        buffer_length +=
            sprintf(longest + buffer_length, "%s", strarr[start + i]);
    }
    return longest;
}
