#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "string_to_integer.h"

int myAtoi(char* s)
{
    int result = 0, count = 0;
    bool neg = false, overflow = false;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ' && count == 0) {
            continue;
        } else if (s[i] == '+' && count == 0) {
            count = 1;
        } else if (s[i] == '-' && count == 0) {
            neg = true;
            count = 1;
        } else if (isdigit(s[i])) {
            int n = s[i] - '0';
            if (result * 10L + n > INT32_MAX) {
                overflow = true;
            } else {
                result = result * 10 + n;
            }
            count += 1;
        } else {
            break;
        };
    }
    if (neg && overflow) {
        return INT32_MIN;
    } else if (neg && !overflow) {
        return result * -1;
    } else if (!neg && overflow) {
        return INT32_MAX;
    } else {
        return result;
    }
}
