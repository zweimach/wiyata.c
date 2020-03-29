#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "restoran_chanek.h"

static void test_three_foods(void **state)
{
    (void)state;

    int input[] = {3, 2, 2};
    int result = restoran_chanek(input, 1, 3);
    assert_int_equal(result, 7);
}

static void test_four_foods(void **state)
{
    (void)state;

    int input[] = {9, 3, 4, 7};
    int result = restoran_chanek(input, 2, 2);
    assert_int_equal(result, 23);
}

static void test_many_foods(void **state)
{
    (void)state;

    int input[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3,
                   4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    int result = restoran_chanek(input, 5, 5);
    assert_int_equal(result, 75);
}

int main()
{
    const struct CMUnitTest tests[] = {cmocka_unit_test(test_three_foods),
                                       cmocka_unit_test(test_four_foods),
                                       cmocka_unit_test(test_many_foods)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}