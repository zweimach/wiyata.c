#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "quick_brown_fox.h"

char const **quick_brown_fox(int n, char const *input[n])
{
    char **result = malloc(sizeof(char *) * n);

    for (int i = 0; i < n; i++) {
        bool pangram[] = {[25] = false};
        bool missing = false;
        for (int j = 0; j < strlen(input[i]); j++) {
            if (isalpha(input[i][j])) {
                pangram[toupper(input[i][j]) - 65] = true;
            }
        }
        for (int c = 0; c < 26; c++) {
            if (!pangram[c]) {
                missing = true;
            }
        }
        if (missing) {
            result[i] = malloc(sizeof(char) * (9 + 26));
            sprintf(result[i], "missing ");
            for (int m = 0; m < 26; m++) {
                if (!pangram[m]) {
                    sprintf(result[i], "%s%c", result[i], m + 97);
                }
            }
        } else {
            result[i] = malloc(sizeof(char) * 9);
            sprintf(result[i], "pangram");
        }
    }
    return (char const **)result;
}
