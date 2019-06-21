#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "autori.h"

const char *autori(const char *names)
{
    char *result = calloc(0, strlen(names));

    for (int i = 0; i < strlen(names); i++) {
        if (isupper(names[i])) {
            char capital[] = {names[i], 0};
            strcat(result, capital);
        }
    }
    return result;
}
