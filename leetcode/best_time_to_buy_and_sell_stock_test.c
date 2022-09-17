#include <setjmp.h>
#include <stdarg.h>
#include <stdlib.h>

#include <cmocka.h>

#include "best_time_to_buy_and_sell_stock.h"

static void first_test(void** state)
{
    (void)state;

    assert_int_equal(maxProfit((int[]){7, 1, 5, 3, 6, 4}, 6), 5);
}

static void second_test(void** state)
{
    (void)state;

    assert_int_equal(maxProfit((int[]){7, 6, 4, 3, 1}, 5), 0);
}

static void third_test(void** state)
{
    (void)state;

    assert_int_equal(maxProfit((int[]){20, 19, 13, 10, 4, 2, 18}, 7), 16);
}

static void fourth_test(void** state)
{
    (void)state;

    assert_int_equal(maxProfit((int[]){3, 2, 6, 5, 0, 3}, 6), 4);
}

static void fifth_test(void** state)
{
    (void)state;

    assert_int_equal(maxProfit((int[]){1, 2, 4, 2, 5, 7, 2, 4, 9, 0}, 10), 8);
}

static void sixth_test(void** state)
{
    (void)state;

    assert_int_equal(maxProfit((int[]){2, 4, 1, 7, 11}, 5), 10);
}


int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test),
                                       cmocka_unit_test(fourth_test),
                                       cmocka_unit_test(fifth_test),
                                       cmocka_unit_test(sixth_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
