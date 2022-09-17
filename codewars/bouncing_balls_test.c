#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "bouncing_balls.h"

static void first_test(void** state)
{
    (void)state;

    int result = bouncingBall(3, 0.66, 1.5);
    assert_int_equal(result, 3);
}

static void second_test(void** state)
{
    (void)state;

    int result = bouncingBall(30, 0.66, 1.5);
    assert_int_equal(result, 15);
}

static void third_test(void** state)
{
    (void)state;

    int result = bouncingBall(30, 0.75, 1.5);
    assert_int_equal(result, 21);
}

static void fourth_test(void** state)
{
    (void)state;

    int result = bouncingBall(10, 0.6, 10);
    assert_int_equal(result, -1);
}

static void fifth_test(void** state)
{
    (void)state;

    int result = bouncingBall(10, 1, 10);
    assert_int_equal(result, -1);
}

int main()
{
    struct CMUnitTest const tests[] = {
        cmocka_unit_test(first_test),
        cmocka_unit_test(second_test),
        cmocka_unit_test(third_test),
        cmocka_unit_test(fourth_test),
        cmocka_unit_test(fifth_test),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
