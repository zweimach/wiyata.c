#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "reverse_integer.h"

static void first_test(void** state)
{
    (void)state;

    int result = reverse(123);
    assert_int_equal(result, 321);
}

static void second_test(void** state)
{
    (void)state;

    int result = reverse(-123);
    assert_int_equal(result, -321);
}

static void third_test(void** state)
{
    (void)state;

    int result = reverse(120);
    assert_int_equal(result, 21);
}

static void fourth_test(void** state)
{
    (void)state;

    int result = reverse(0);
    assert_int_equal(result, 0);
}

static void fifth_test(void** state)
{
    (void)state;

    int result = reverse(12345);
    assert_int_equal(result, 54321);
}

static void sixth_test(void** state)
{
    (void)state;

    int result = reverse(1534236469);
    assert_int_equal(result, 0);
}

int main(void)
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test),
                                       cmocka_unit_test(fourth_test),
                                       cmocka_unit_test(fifth_test),
                                       cmocka_unit_test(sixth_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
