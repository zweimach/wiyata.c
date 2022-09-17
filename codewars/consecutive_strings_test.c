#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "consecutive_strings.h"

static void first_test(void** state)
{
    (void)state;

    char* input[] =
        {"zone", "abigail", "theta", "form", "libe", "zas", "theta", "abigail"};
    char* result = longestConsec(input, 8, 2);
    assert_string_equal(result, "abigailtheta");
    free(result);
}

static void second_test(void** state)
{
    (void)state;

    char* input[] = {"ejjjjmmtthh",
                     "zxxuueeg",
                     "aanlljrrrxx",
                     "dqqqaaabbb",
                     "oocccffuucccjjjkkkjyyyeehh"};
    char* result = longestConsec(input, 5, 1);
    assert_string_equal(result, "oocccffuucccjjjkkkjyyyeehh");
    free(result);
}

static void third_test(void** state)
{
    (void)state;

    char* input[] = {0};
    char* result = longestConsec(input, 0, 3);
    assert_string_equal(result, "");
    free(result);
}

static void fourth_test(void** state)
{
    (void)state;

    char* input[] = {"itvayloxrp",
                     "wkppqsztdkmvcuwvereiupccauycnjutlv",
                     "vweqilsfytihvrzlaodfixoyxvyuyvgpck"};
    char* result = longestConsec(input, 3, 2);
    assert_string_equal(
        result,
        "wkppqsztdkmvcuwvereiupccauycnjutlvvweqilsfytihvrzlaodfixoyxvyuyvgpck");
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
