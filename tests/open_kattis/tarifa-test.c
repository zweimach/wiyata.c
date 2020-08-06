#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "tarifa.h"

static void first_test(void **state)
{
    (void)state;

    int input[] = {4, 6, 2};
    long result = tarifa(10, 3, input);
    assert_int_equal(result, 28);
}

static void second_test(void **state)
{
    (void)state;

    int input[] = {10, 2, 12};
    long result = tarifa(10, 3, input);
    assert_int_equal(result, 16);
}

static void third_test(void **state)
{
    (void)state;

    int input[] = {15, 10, 20};
    long result = tarifa(15, 3, input);
    assert_int_equal(result, 15);
}

int main()
{
    const struct CMUnitTest tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
