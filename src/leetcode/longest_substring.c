#include <string.h>

#include "longest_substring.h"

int str_drop_at(int n, char str[n], char c);

int lengthOfLongestSubstring(char* s)
{
    char* str = s;
    int max = 0;

    for (int i = 0, pos = 0, drop = 0; i < strlen(s);
         i++, pos++, max = max < pos ? pos : max) {
        if ((drop = str_drop_at(pos, str, s[i]))) {
            str += drop;
            pos -= drop;
        }
    }
    return max;
}

int str_drop_at(int n, char str[n], char c)
{
    for (int i = 0; i < n; i++) {
        if (str[i] == c) {
            return i + 1;
        }
    }
    return 0;
}
