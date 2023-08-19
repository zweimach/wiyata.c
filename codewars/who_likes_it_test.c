#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <cmocka.h>

#include "who_likes_it.h"

static void first_test(void** state)
{
    (void)state;

    char const* const names[] = {0};
    char* expected = "no one likes this";
    char* submitted = likes(0, names);
    assert_string_equal(expected, submitted);
    free(submitted);
}

static void second_test(void** state)
{
    (void)state;

    char const* const names[1] = {"Peter"};
    char* expected = "Peter likes this";
    char* submitted = likes(1, names);
    assert_string_equal(expected, submitted);
    free(submitted);
}

static void third_test(void** state)
{
    (void)state;

    char const* const names[2] = {"Jacob", "Alex"};
    char* expected = "Jacob and Alex like this";
    char* submitted = likes(2, names);
    assert_string_equal(expected, submitted);
    free(submitted);
}

static void fourth_test(void** state)
{
    (void)state;

    char const* const names[3] = {"Max", "John", "Mark"};
    char* expected = "Max, John and Mark like this";
    char* submitted = likes(3, names);
    assert_string_equal(expected, submitted);
    free(submitted);
}

static void fifth_test(void** state)
{
    (void)state;

    char const* const names[4] = {"Alex", "Jacob", "Mark", "Max"};
    char* expected = "Alex, Jacob and 2 others like this";
    char* submitted = likes(4, names);
    assert_string_equal(expected, submitted);
    free(submitted);
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
