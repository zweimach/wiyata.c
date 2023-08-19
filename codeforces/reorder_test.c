#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "reorder.h"

static void first_test(void** state)
{
    (void)state;

    char const* result = reorder(3, (unsigned[]){2, 5, 1}, 8);
    assert_string_equal(result, "YES");
}

static void second_test(void** state)
{
    (void)state;

    char const* result = reorder(4, (unsigned[]){0, 1, 2, 3}, 4);
    assert_string_equal(result, "NO");
}

int main(void)
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
