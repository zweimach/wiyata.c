#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "perang_dunia_ketiga.h"

static void test_two_invasions(void **state)
{
    (void)state;

    int input[] = {7, 31};
    int result = perang_dunia_ketiga(input, 2);
    assert_int_equal(result, 2);
}

static void test_three_invasions(void **state)
{
    (void)state;

    int input[] = {4, 8, 2};
    int result = perang_dunia_ketiga(input, 3);
    assert_int_equal(result, 0);
}

static void test_many_invasions(void **state)
{
    (void)state;

    {
        int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int result = perang_dunia_ketiga(input, 10);
        assert_int_equal(result, 20);
    }

    {
        int input[] = {7, 7, 7, 7, 2, 4, 4, 4, 7, 7, 7, 7};
        int result = perang_dunia_ketiga(input, 12);
        assert_int_equal(result, 8);
    }
}

int main()
{
    const struct CMUnitTest tests[] = {cmocka_unit_test(test_two_invasions),
                                       cmocka_unit_test(test_three_invasions),
                                       cmocka_unit_test(test_many_invasions)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
