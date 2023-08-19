#include <setjmp.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <cmocka.h>

#include "number_of_islands.h"

static void first_test(void** state)
{
    (void)state;

    int row = 4, col[4] = {5, 5, 5, 5};
    char* input[4] = {"11110", "11010", "11000", "00000"};
    assert_int_equal(numIslands(input, row, col), 1);
}

static void second_test(void** state)
{
    (void)state;

    int row = 4, col[4] = {5, 5, 5, 5};
    char* input[4] = {"11000", "11000", "00100", "00011"};
    assert_int_equal(numIslands(input, row, col), 3);
}

static void third_test(void** state)
{
    (void)state;

    int row = 5, col[5] = {5, 5, 5, 5, 5};
    char* input[5] = {"11011", "11011", "00100", "00100", "10011"};
    assert_int_equal(numIslands(input, row, col), 5);
}

int main(void)
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
