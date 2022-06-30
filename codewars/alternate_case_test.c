#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include <cmocka.h>

#include "alternate_case.h"

static void first_test(void** state)
{
    (void)state;

    char* input = calloc(2, sizeof(char));
    char* result = alternateCase(input);
    assert_string_equal(result, "");
    free(input);
}

static void second_test(void** state)
{
    (void)state;

    char* input = malloc(sizeof(char) * 4);
    sprintf(input, "abc");
    char* result = alternateCase(input);
    assert_string_equal(result, "ABC");
    free(input);
}

static void third_test(void** state)
{
    (void)state;

    char* input = malloc(sizeof(char) * 4);
    sprintf(input, "ABC");
    char* result = alternateCase(input);
    assert_string_equal(result, "abc");
    free(input);
}

static void fourth_test(void** state)
{
    (void)state;

    char* input = malloc(sizeof(char) * 13);
    sprintf(input, "Hello World!");
    char* result = alternateCase(input);
    assert_string_equal(result, "hELLO wORLD!");
    free(input);
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
