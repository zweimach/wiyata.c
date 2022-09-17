#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "sorted_yes_no_how.h"

static void first_test(void** state)
{
    (void)state;

    char* result = isSortedAndHow((int[]){1, 2}, 2);
    assert_string_equal(result, "yes, ascending");
    free(result);
}

static void second_test(void** state)
{
    (void)state;

    char* result = isSortedAndHow((int[]){15, 7, 3, -8}, 4);
    assert_string_equal(result, "yes, descending");
    free(result);
}

static void third_test(void** state)
{
    (void)state;

    char* result = isSortedAndHow((int[]){4, 2, 30}, 3);
    assert_string_equal(result, "no");
    free(result);
}

static void fourth_test(void** state)
{
    (void)state;

    char* result = isSortedAndHow((int[]){-100, -1, 0, 1, 100}, 5);
    assert_string_equal(result, "yes, ascending");
    free(result);
}

int main()
{
    struct CMUnitTest const tests[] = {
        cmocka_unit_test(first_test),
        cmocka_unit_test(second_test),
        cmocka_unit_test(third_test),
        cmocka_unit_test(fourth_test),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
