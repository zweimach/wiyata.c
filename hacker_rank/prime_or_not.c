#include "prime_or_not.h"

int isPrime(long n)
{
    if (n != 2 && n % 2 == 0) {
        return 2;
    }
    for (long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return i;
        }
    }
    return 1;
}
