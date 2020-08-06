#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "fizzbuzz.h"

static void first_test(void **state)
{
    (void)state;

    const char *result = fizzbuzz(2, 3, 7);
    assert_string_equal(result, "1\nFizz\nBuzz\nFizz\n5\nFizzBuzz\n7\n");
    free((void *)result);
}

static void second_test(void **state)
{
    (void)state;

    const char *result = fizzbuzz(3, 5, 7);
    assert_string_equal(result, "1\n2\nFizz\n4\nBuzz\nFizz\n7\n");
    free((void *)result);
}

int main()
{
    const struct CMUnitTest tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}