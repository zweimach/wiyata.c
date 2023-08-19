#include <setjmp.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include <cmocka.h>

#include "flood_fill.h"

static void first_test(void** state)
{
    (void)state;

    int row = 3, col[3] = {3, 3, 3};
    int* input[3] = {
        (int[]){1, 1, 1},
        (int[]){1, 1, 0},
        (int[]){1, 0, 1},
    };
    int* expected[3] = {
        (int[]){2, 2, 2},
        (int[]){2, 2, 0},
        (int[]){2, 0, 1},
    };
    int ret_row;
    int* ret_col = NULL;
    int** result = floodFill(input, row, col, 1, 1, 2, &ret_row, &ret_col);

    assert_int_equal(row, ret_row);
    assert_int_equal(col[0], ret_col[0]);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col[0]; j++) {
            assert_int_equal(result[i][j], expected[i][j]);
        }
        free(result[i]);
    }
    free(result);
    free(ret_col);
}

static void second_test(void** state)
{
    (void)state;

    int row = 2, col[3] = {3, 3, 3};
    int* input[3] = {
        (int[]){0, 0, 0},
        (int[]){0, 0, 0},
    };
    int* expected[3] = {
        (int[]){0, 0, 0},
        (int[]){0, 0, 0},
    };
    int ret_row;
    int* ret_col = NULL;
    int** result = floodFill(input, row, col, 0, 0, 0, &ret_row, &ret_col);

    assert_int_equal(row, ret_row);
    assert_int_equal(col[0], ret_col[0]);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col[0]; j++) {
            assert_int_equal(result[i][j], expected[i][j]);
        }
        free(result[i]);
    }
    free(result);
    free(ret_col);
}

static void third_test(void** state)
{
    (void)state;

    int row = 10, col[10] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    int* input[10] = {
        (int[]){8, 4, 5, 3, 2, 2, 2, 6, 9, 5},
        (int[]){3, 1, 3, 7, 4, 8, 9, 0, 1, 6},
        (int[]){0, 7, 1, 7, 5, 2, 2, 8, 6, 9},
        (int[]){9, 1, 0, 5, 8, 8, 0, 5, 5, 9},
        (int[]){3, 4, 9, 5, 4, 8, 0, 2, 7, 5},
        (int[]){5, 1, 1, 8, 1, 6, 5, 9, 7, 8},
        (int[]){9, 7, 9, 4, 5, 3, 4, 1, 8, 2},
        (int[]){5, 1, 6, 3, 5, 4, 8, 9, 0, 8},
        (int[]){8, 8, 6, 1, 0, 8, 0, 6, 9, 9},
        (int[]){4, 1, 8, 7, 3, 6, 9, 6, 6, 1},
    };
    int* expected[10] = {
        (int[]){8, 4, 5, 3, 2, 2, 2, 6, 9, 5},
        (int[]){3, 1, 3, 7, 4, 8, 9, 0, 1, 6},
        (int[]){0, 7, 1, 7, 5, 2, 2, 8, 6, 9},
        (int[]){9, 1, 0, 5, 8, 8, 0, 5, 5, 9},
        (int[]){3, 4, 9, 5, 4, 8, 0, 2, 7, 5},
        (int[]){5, 1, 1, 8, 1, 6, 5, 9, 7, 8},
        (int[]){9, 7, 9, 4, 5, 3, 4, 1, 8, 2},
        (int[]){5, 1, 6, 3, 5, 4, 8, 9, 0, 8},
        (int[]){9, 9, 6, 1, 0, 8, 0, 6, 9, 9},
        (int[]){4, 1, 8, 7, 3, 6, 9, 6, 6, 1},
    };
    int ret_row;
    int* ret_col = NULL;
    int** result = floodFill(input, row, col, 8, 0, 9, &ret_row, &ret_col);

    assert_int_equal(row, ret_row);
    assert_int_equal(col[0], ret_col[0]);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col[0]; j++) {
            assert_int_equal(result[i][j], expected[i][j]);
        }
        free(result[i]);
    }
    free(result);
    free(ret_col);
}

int main(void)
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
