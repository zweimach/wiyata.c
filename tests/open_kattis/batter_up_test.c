#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "batter_up.h"

static void first_test(void** state)
{
    (void)state;

    int input[] = {3, 0, 2};
    double result = batter_up(input, 3);
    assert_float_equal(result, 1.6666666666666667, 0);
}

static void second_test(void** state)
{
    (void)state;

    int input[] = {1, -1, 4};
    double result = batter_up(input, 3);
    assert_float_equal(result, 2.5, 0);
}

static void third_test(void** state)
{
    (void)state;

    int input[] = {-1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 1};
    double result = batter_up(input, 11);
    assert_float_equal(result, 0.14285714285714285, 0);
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
