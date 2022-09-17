#include <setjmp.h>
#include <stdarg.h>
#include <stdlib.h>

#include <cmocka.h>

#include "first_bad_version.h"

static void first_test(void** state)
{
    (void)state;

    CALL_COUNT = 0;
    BAD_VERSION = 4;
    int result = firstBadVersion(5);
    assert_int_equal(result, BAD_VERSION);
    assert_int_equal(CALL_COUNT, 2);
}

static void second_test(void** state)
{
    (void)state;

    CALL_COUNT = 0;
    BAD_VERSION = 1;
    int result = firstBadVersion(1);
    assert_int_equal(result, BAD_VERSION);
    assert_int_equal(CALL_COUNT, 0);
}

static void third_test(void** state)
{
    (void)state;

    CALL_COUNT = 0;
    BAD_VERSION = 99;
    int result = firstBadVersion(100);
    assert_int_equal(result, BAD_VERSION);
    assert_int_equal(CALL_COUNT, 12);
}

static void fourth_test(void** state)
{
    (void)state;

    CALL_COUNT = 0;
    BAD_VERSION = 2;
    int result = firstBadVersion(2);
    assert_int_equal(result, BAD_VERSION);
    assert_int_equal(CALL_COUNT, 2);
}

static void fifth_test(void** state)
{
    (void)state;

    CALL_COUNT = 0;
    BAD_VERSION = 2147483647;
    int result = firstBadVersion(2147483647);
    assert_int_equal(result, BAD_VERSION);
    assert_int_equal(CALL_COUNT, 60);
}

int main(void)
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test),
                                       cmocka_unit_test(fourth_test),
                                       cmocka_unit_test(fifth_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
