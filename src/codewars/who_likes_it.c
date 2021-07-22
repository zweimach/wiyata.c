#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* likes(size_t n, char const* const names[n])
{
    unsigned size = 0;

    for (unsigned i = 0; i < (n > 3 ? 2 : n); i++) {
        size += strlen(names[i]);
    }

    char* result = calloc(30 + size, sizeof(char));

    switch (n) {
    case 0:
        sprintf(result, "%s likes this", "no one");
        break;
    case 1:
        sprintf(result, "%s likes this", names[0]);
        break;
    case 2:
        sprintf(result, "%s and %s like this", names[0], names[1]);
        break;
    case 3:
        sprintf(result,
                "%s, %s and %s like this",
                names[0],
                names[1],
                names[2]);
        break;
    default:
        sprintf(result,
                "%s, %s and %lu others like this",
                names[0],
                names[1],
                n - 2);
        break;
    }
    return result;
}
