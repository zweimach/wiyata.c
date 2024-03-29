#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include <cmocka.h>

#include "stuck_in_a_time_loop.h"

static void first_test(void** state)
{
    (void)state;

    enum { input = 5 };
    char expect[input][17];
    char const** result = stuck_in_a_time_loop(input);
    for (unsigned i = 0; i < input; i++) {
        sprintf(expect[i], "%u Abracadabra", i + 1);
        assert_string_equal(result[i], expect[i]);
    }
    for (unsigned i = 0; i < input; i++) {
        free((void*)result[i]);
    }
    free((void*)result);
}

static void second_test(void** state)
{
    (void)state;

    enum { input = 10 };
    char expect[input][17];
    char const** result = stuck_in_a_time_loop(input);
    for (unsigned i = 0; i < input; i++) {
        sprintf(expect[i], "%u Abracadabra", i + 1);
        assert_string_equal(result[i], expect[i]);
    }
    for (unsigned i = 0; i < input; i++) {
        free((void*)result[i]);
    }
    free((void*)result);
}

int main(void)
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
