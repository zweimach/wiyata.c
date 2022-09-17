#include <stdbool.h>

#include "palindrome_number.h"

bool isPalindrome(int x)
{
    if (x < 0) {
        return false;
    }
    long n = 0, m = x;
    while (m != 0) {
        int rem = m % 10;
        m = (m / 10) | 0;
        n = (n * 10) + rem;
    }
    return n == x;
}
