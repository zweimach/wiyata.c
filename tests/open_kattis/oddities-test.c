#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "oddities.h"

static void first_test(void** state)
{
    (void)state;

    char const* result = oddities(10);
    assert_string_equal(result, "10 is even");
    free((void*)result);
}

static void second_test(void** state)
{
    (void)state;

    char const* result = oddities(-5);
    assert_string_equal(result, "-5 is odd");
    free((void*)result);
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
