#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include <cmocka.h>

#include "n-th_power.h"

static void first_test(void** state)
{
    (void)state;

    int result = index(0, 0, 0);
    assert_int_equal(result, -1);
}

static void second_test(void** state)
{
    (void)state;

    int result = index((int[]){1, 2, 3, 4}, 4, 2);
    assert_int_equal(result, 9);
}

static void third_test(void** state)
{
    (void)state;

    int result = index((int[]){1, 3, 10, 100}, 4, 3);
    assert_int_equal(result, 1000000);
}

int main()
{
    struct CMUnitTest const tests[] = {
        cmocka_unit_test(first_test),
        cmocka_unit_test(second_test),
        cmocka_unit_test(third_test),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
