#include <string.h>

#include "alternate_case.h"

char* alternateCase(char* string)
{
    for (int i = 0; i < strlen(string); i++) {
        if ((string[i] > 96) && (string[i] < 123))
            string[i] = string[i] - 32;
        else if ((string[i] > 64) && (string[i] < 91))
            string[i] = string[i] + 32;
    }
    return string;
}
