#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "zamka.h"

static void first_test(void** state)
{
    (void)state;

    unsigned* result = zamka(1, 100, 4);
    assert_int_equal(result[0], 4);
    assert_int_equal(result[1], 40);
    free(result);
}

static void second_test(void** state)
{
    (void)state;

    unsigned* result = zamka(100, 500, 12);
    assert_int_equal(result[0], 129);
    assert_int_equal(result[1], 480);
    free(result);
}

static void third_test(void** state)
{
    (void)state;

    unsigned* result = zamka(1, 10000, 1);
    assert_int_equal(result[0], 1);
    assert_int_equal(result[1], 10000);
    free(result);
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
