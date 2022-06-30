#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "longest_substring.h"

static void first_test(void** state)
{
    (void)state;

    int result = lengthOfLongestSubstring("abcabcbb");
    assert_int_equal(result, 3);
}

static void second_test(void** state)
{
    (void)state;

    int result = lengthOfLongestSubstring("");
    assert_int_equal(result, 0);
}

static void third_test(void** state)
{
    (void)state;

    int result = lengthOfLongestSubstring("pwwkew");
    assert_int_equal(result, 3);
}

static void fourth_test(void** state)
{
    (void)state;

    int result = lengthOfLongestSubstring("bbbbb");
    assert_int_equal(result, 1);
}

static void fifth_test(void** state)
{
    (void)state;

    int result = lengthOfLongestSubstring("ohvhjdml");
    assert_int_equal(result, 6);
}

static void sixth_test(void** state)
{
    (void)state;

    int result = lengthOfLongestSubstring("ohomm");
    assert_int_equal(result, 3);
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test),
                                       cmocka_unit_test(fourth_test),
                                       cmocka_unit_test(fifth_test),
                                       cmocka_unit_test(sixth_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
