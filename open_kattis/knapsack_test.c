#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "knapsack.h"

static void first_test(void** state)
{
    (void)state;

    enum { ITEM_COUNT = 5 };
    struct Item* items[ITEM_COUNT] = {
        item_new(2, 3),
        item_new(2, 1),
        item_new(4, 3),
        item_new(5, 4),
        item_new(3, 2),
    };
    unsigned expected[] = {4, 3, 1};
    struct Result* result = knapsack(ITEM_COUNT, items, 7);

    assert_int_equal(result->total_value, 10);
    assert_int_equal(result->item_count, 3);
    for (unsigned i = 0; i < result->item_count; i++) {
        assert_int_equal(result->items[i], expected[i]);
    }

    for (int i = 0; i < ITEM_COUNT; i++) {
        item_free(items[i]);
    }
    result_free(result);
}

static void second_test(void** state)
{
    (void)state;

    enum { ITEM_COUNT = 3 };
    struct Item* items[ITEM_COUNT] = {
        item_new(1, 5),
        item_new(10, 5),
        item_new(100, 5),
    };
    unsigned expected[] = {2};
    struct Result* result = knapsack(ITEM_COUNT, items, 5);

    assert_int_equal(result->total_value, 100);
    assert_int_equal(result->item_count, 1);
    for (unsigned i = 0; i < result->item_count; i++) {
        assert_int_equal(result->items[i], expected[i]);
    }

    for (int i = 0; i < ITEM_COUNT; i++) {
        item_free(items[i]);
    }
    result_free(result);
}

static void third_test(void** state)
{
    (void)state;

    enum { ITEM_COUNT = 4 };
    struct Item* items[ITEM_COUNT] = {
        item_new(5, 4),
        item_new(4, 3),
        item_new(3, 2),
        item_new(2, 1),
    };
    unsigned expected[] = {3, 2, 1};
    struct Result* result = knapsack(ITEM_COUNT, items, 6);

    assert_int_equal(result->total_value, 9);
    assert_int_equal(result->item_count, 3);
    for (unsigned i = 0; i < result->item_count; i++) {
        assert_int_equal(result->items[i], expected[i]);
    }

    for (int i = 0; i < ITEM_COUNT; i++) {
        item_free(items[i]);
    }
    result_free(result);
}

int main(void)
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
