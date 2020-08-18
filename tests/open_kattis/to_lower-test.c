#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "to_lower.h"

static void test_two_data(void** state)
{
    (void)state;

    char* data_1[4] = {"abc", "Def", "geh", "jed"};
    char* data_2[4] = {"ILK", "Lmn", "Cbba", "IO"};
    char** input[2] = {data_1, data_2};
    int result = to_lower(input, 2, 4);
    assert_int_equal(result, 1);
}

static void test_three_data(void** state)
{
    (void)state;

    char* data_1[3] = {"abc", "Def", "geh"};
    char* data_2[3] = {"ijk", "Lmn", "Cbba"};
    char* data_3[3] = {"zywa", "xyk", "Cbba"};
    char** input[3] = {data_1, data_2, data_3};
    int result = to_lower(input, 3, 3);
    assert_int_equal(result, 3);
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(test_two_data),
                                       cmocka_unit_test(test_three_data)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
