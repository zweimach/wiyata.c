#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "string_to_integer.h"

static void first_test(void** state)
{
    (void)state;

    int result = myAtoi("42");
    assert_int_equal(result, 42);
}

static void second_test(void** state)
{
    (void)state;

    int result = myAtoi("   -42");
    assert_int_equal(result, -42);
}

static void third_test(void** state)
{
    (void)state;

    int result = myAtoi("4193 with words");
    assert_int_equal(result, 4193);
}

static void fourth_test(void** state)
{
    (void)state;

    int result = myAtoi("words and 987");
    assert_int_equal(result, 0);
}

static void fifth_test(void** state)
{
    (void)state;

    int result = myAtoi("-91283472332");
    assert_int_equal(result, -2147483648);
}

static void sixth_test(void** state)
{
    (void)state;

    int result = myAtoi("- 100");
    assert_int_equal(result, 0);
}

static void seventh_test(void** state)
{
    (void)state;

    int result = myAtoi("-+12");
    assert_int_equal(result, 0);
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test),
                                       cmocka_unit_test(fourth_test),
                                       cmocka_unit_test(fifth_test),
                                       cmocka_unit_test(sixth_test),
                                       cmocka_unit_test(seventh_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
