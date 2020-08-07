#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "trik.h"

static void first_test(void **state)
{
    (void)state;

    char const *const input = "AB";
    unsigned result = trik(input);
    assert_int_equal(result, 3);
}

static void second_test(void **state)
{
    (void)state;

    char const *const input = "CBABCACCC";
    unsigned result = trik(input);
    assert_int_equal(result, 1);
}

int main()
{
    const struct CMUnitTest tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
