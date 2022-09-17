#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "ones_and_zeros.h"

static void first_test(void** state)
{
    (void)state;

    unsigned bits[] = {0, 0, 0, 1};
    unsigned result = binary_array_to_numbers(bits, 4);
    assert_int_equal(result, 1);
}

static void second_test(void** state)
{
    (void)state;

    unsigned bits[] = {0, 0, 1, 0};
    unsigned result = binary_array_to_numbers(bits, 4);
    assert_int_equal(result, 2);
}

static void third_test(void** state)
{
    (void)state;

    unsigned bits[] = {1, 1, 1, 1};
    unsigned result = binary_array_to_numbers(bits, 4);
    assert_int_equal(result, 15);
}

static void fourth_test(void** state)
{
    (void)state;

    unsigned bits[] = {0, 1, 1, 0};
    unsigned result = binary_array_to_numbers(bits, 4);
    assert_int_equal(result, 6);
}

int main()
{
    struct CMUnitTest const tests[] = {
        cmocka_unit_test(first_test),
        cmocka_unit_test(second_test),
        cmocka_unit_test(third_test),
        cmocka_unit_test(fourth_test),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
