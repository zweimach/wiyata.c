#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "take_two_stones.h"

static void first_test(void** state)
{
    (void)state;

    char const* result = take_two_stones(2);
    assert_string_equal(result, "Bob");
}

static void second_test(void** state)
{
    (void)state;

    char const* result = take_two_stones(3);
    assert_string_equal(result, "Alice");
}

int main(void)
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
