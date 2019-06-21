#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "autori.h"

static void test_two_names(void **state)
{
    (void)state;

    const char *result = autori("Knuth-Morris-Pratt");
    assert_string_equal(result, "KMP");
    free((void *)result);
}

static void test_three_names(void **state)
{
    (void)state;

    const char *result = autori("Mirko-Slavko");
    assert_string_equal(result, "MS");
    free((void *)result);
}

int main()
{
    const struct CMUnitTest tests[] = {cmocka_unit_test(test_two_names),
                                       cmocka_unit_test(test_three_names)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
