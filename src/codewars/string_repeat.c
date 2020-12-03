#include <stdlib.h>
#include <string.h>

#include "string_repeat.h"

char* repeat_str(size_t count, const char* src)
{
    size_t size = strlen(src) * count;
    char* result = malloc(size * sizeof(char) + 1);

    result[0] = '\0';
    while (strlen(result) < size) {
        strncat(result, src, strlen(src));
    }
    return result;
}
