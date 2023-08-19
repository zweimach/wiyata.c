#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "number_fun.h"

static void first_test(void** state)
{
    (void)state;

    unsigned input[6][3] = {
        {1, 2, 3},
        {2, 24, 12},
        {5, 3, 1},
        {9, 16, 7},
        {7, 2, 14},
        {12, 4, 2},
    };
    char const* expect[] = {
        "Possible",
        "Possible",
        "Impossible",
        "Possible",
        "Possible",
        "Impossible",
    };
    char const** result = number_fun(6, input);
    for (int i = 0; i < 6; i++) {
        assert_string_equal(result[i], expect[i]);
    }
    for (int i = 0; i < 6; i++) {
        free((void*)result[i]);
    }
    free((void*)result);
}

int main(void)
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
