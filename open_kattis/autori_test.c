#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "autori.h"

static void test_two_names(void** state)
{
    (void)state;

    char const* result = autori("Knuth-Morris-Pratt");
    assert_string_equal(result, "KMP");
    free((void*)result);
}

static void test_three_names(void** state)
{
    (void)state;

    char const* result = autori("Mirko-Slavko");
    assert_string_equal(result, "MS");
    free((void*)result);
}

int main(void)
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(test_two_names),
                                       cmocka_unit_test(test_three_names)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
