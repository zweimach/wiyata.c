#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "prime_or_not.h"

static void first_test(void** state)
{
    (void)state;

    int result = isPrime(2);
    assert_int_equal(result, 1);
}

static void second_test(void** state)
{
    (void)state;

    int result = isPrime(1024);
    assert_int_equal(result, 2);
}

static void third_test(void** state)
{
    (void)state;

    int result = isPrime(31);
    assert_int_equal(result, 1);
}

static void fourth_test(void** state)
{
    (void)state;

    int result = isPrime(997);
    assert_int_equal(result, 1);
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test),
                                       cmocka_unit_test(fourth_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
