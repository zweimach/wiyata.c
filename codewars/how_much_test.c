#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "how_much.h"

static void first_test(void** state)
{
    (void)state;

    char* result = howmuch(1, 100);
    assert_string_equal(result, "[[M: 37 B: 5 C: 4][M: 100 B: 14 C: 11]]");
    free(result);
}

static void second_test(void** state)
{
    (void)state;

    char* result = howmuch(0, 200);
    assert_string_equal(
        result,
        "[[M: 37 B: 5 C: 4][M: 100 B: 14 C: 11][M: 163 B: 23 C: 18]]");
    free(result);
}

static void third_test(void** state)
{
    (void)state;

    char* result = howmuch(1000, 1100);
    assert_string_equal(result, "[[M: 1045 B: 149 C: 116]]");
    free(result);
}

static void fourth_test(void** state)
{
    (void)state;

    char* result = howmuch(10000, 9950);
    assert_string_equal(result, "[[M: 9991 B: 1427 C: 1110]]");
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
