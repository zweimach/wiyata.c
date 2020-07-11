#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "reversed_binary_numbers.h"

static void first_test(void **state)
{
    (void)state;

    int result = reversed_binary_numbers(11);
    assert_int_equal(result, 13);
}

static void second_test(void **state)
{
    (void)state;

    int result = reversed_binary_numbers(47);
    assert_int_equal(result, 61);
}

static void third_test(void **state)
{
    (void)state;

    long result = reversed_binary_numbers(8);
    assert_int_equal(result, 1);
}

int main()
{
    const struct CMUnitTest tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
