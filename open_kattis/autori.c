#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "autori.h"

char const* autori(char const* names)
{
    char* result = calloc(strlen(names) + 1, sizeof(char));

    for (unsigned i = 0; i < strlen(names); i++) {
        if (isupper(names[i])) {
            char capital[] = {names[i], 0};
            strcat(result, capital);
        }
    }
    return result;
}
