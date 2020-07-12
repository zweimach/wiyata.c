#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "oddities.h"

static void first_test(void **state)
{
    (void)state;

    const char *result = oddities(10);
    assert_string_equal(result, "10 is even");
    free((void *)result);
}

static void second_test(void **state)
{
    (void)state;

    const char *result = oddities(-5);
    assert_string_equal(result, "-5 is odd");
    free((void *)result);
}

int main()
{
    const struct CMUnitTest tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
