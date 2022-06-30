#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "herman.h"

static void first_test(void** state)
{
    (void)state;

    double* result = herman(1);
    assert_float_equal(result[0], 3.141593, 0);
    assert_float_equal(result[1], 2.000000, 0);
}

static void second_test(void** state)
{
    (void)state;

    double* result = herman(21);
    assert_float_equal(result[0], 1385.442360, 0);
    assert_float_equal(result[1], 882.000000, 0);
}

static void third_test(void** state)
{
    (void)state;

    double* result = herman(42);
    assert_float_equal(result[0], 5541.769441, 0);
    assert_float_equal(result[1], 3528.000000, 0);
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
