#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "take_two_stones.h"

static void first_test(void **state)
{
    (void)state;

    const char *result = take_two_stones(2);
    assert_string_equal(result, "Bob");
}

static void second_test(void **state)
{
    (void)state;

    const char *result = take_two_stones(3);
    assert_string_equal(result, "Alice");
}

int main()
{
    const struct CMUnitTest tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
