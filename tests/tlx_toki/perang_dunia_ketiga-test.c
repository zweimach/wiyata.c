#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>

#include <cmocka.h>

#include "perang_dunia_ketiga.h"

static void test_two_invasions(void** state)
{
    (void)state;

    unsigned input[] = {7, 31};
    unsigned result = perang_dunia_ketiga(2, input);
    assert_int_equal(result, 2);
}

static void test_three_invasions(void** state)
{
    (void)state;

    unsigned input[] = {4, 8, 2};
    unsigned result = perang_dunia_ketiga(3, input);
    assert_int_equal(result, 0);
}

static void test_many_invasions(void** state)
{
    (void)state;

    {
        unsigned input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        unsigned result = perang_dunia_ketiga(10, input);
        assert_int_equal(result, 20);
    }

    {
        unsigned input[] = {7, 7, 7, 7, 2, 4, 4, 4, 7, 7, 7, 7};
        unsigned result = perang_dunia_ketiga(12, input);
        assert_int_equal(result, 8);
    }
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(test_two_invasions),
                                       cmocka_unit_test(test_three_invasions),
                                       cmocka_unit_test(test_many_invasions)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
