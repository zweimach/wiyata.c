#include <stdio.h>
#include <stdlib.h>

#include "sorted_yes_no_how.h"

enum Method {
    UNORD = -1,
    UNDEF,
    ASC,
    DESC,
};

enum Ord {
    LT = -1,
    EQ = 0,
    GT = 1,
};

char* isSortedAndHow(int* array, int arrayLength)
{
    char* result = calloc(sizeof(char), 16);
    enum Method method = UNDEF;

    for (int i = 1; i < arrayLength; i++) {
        enum Ord next = array[i] < array[i - 1]   ? LT
                        : array[i] > array[i - 1] ? GT
                                                  : EQ;
        if (method == UNDEF) {
            method = next == LT ? DESC : ASC;
        } else if (next == GT && method == ASC) {
            continue;
        } else if (next == LT && method == DESC) {
            continue;
        } else if (next == EQ) {
            continue;
        } else {
            method = UNORD;
            break;
        }
    }

    switch (method) {
    case ASC:
        sprintf(result, "yes, ascending");
        break;
    case DESC:
        sprintf(result, "yes, descending");
        break;
    case UNORD:
        sprintf(result, "no");
        break;
    default:
        break;
    }
    return result;
}
