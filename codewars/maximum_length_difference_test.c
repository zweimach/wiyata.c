#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "maximum_length_difference.h"

static void first_test(void** state)
{
    (void)state;

    char const* firstArray[] = {"hoqq",
                                "bbllkw",
                                "oox",
                                "ejjuyyy",
                                "plmiis",
                                "xxxzgpsssa",
                                "xxwwkktt",
                                "znnnnfqknaz",
                                "qqquuhii",
                                "dvvvwz"};
    char const* secondArray[] = {"cccooommaaqqoxii",
                                 "gggqaffhhh",
                                 "tttoowwwmmww"};

    size_t const firstArrayLength = sizeof(firstArray) / sizeof(firstArray[0]);
    size_t const secondArrayLength =
        sizeof(secondArray) / sizeof(secondArray[0]);

    int const expected = 13;
    int const actual =
        mxdiflg(firstArray, firstArrayLength, secondArray, secondArrayLength);

    assert_int_equal(expected, actual);
}

static void second_test(void** state)
{
    (void)state;

    char const* firstArray[] = {"ejjjjmmtthh",
                                "zxxuueeg",
                                "aanlljrrrxx",
                                "dqqqaaabbb",
                                "oocccffuucccjjjkkkjyyyeehh"};
    char const* secondArray[] = {"bbbaaayddqbbrrrv"};

    size_t const firstArrayLength = sizeof(firstArray) / sizeof(firstArray[0]);
    size_t const secondArrayLength =
        sizeof(secondArray) / sizeof(secondArray[0]);

    int const expected = 10;
    int const actual =
        mxdiflg(firstArray, firstArrayLength, secondArray, secondArrayLength);

    assert_int_equal(expected, actual);
}

static void third_test(void** state)
{
    (void)state;

    char const* firstArray[] = {"ccct",
                                "tkkeeeyy",
                                "ggiikffsszzoo",
                                "nnngssddu",
                                "rrllccqqqqwuuurdd",
                                "kkbbddaakkk"};
    char const* secondArray[] = {"tttxxxxxxgiiyyy",
                                 "ooorcvvj",
                                 "yzzzhhhfffaaavvvpp",
                                 "jjvvvqqllgaaannn",
                                 "tttooo",
                                 "qmmzzbhhbb"};

    size_t const firstArrayLength = sizeof(firstArray) / sizeof(firstArray[0]);
    size_t const secondArrayLength =
        sizeof(secondArray) / sizeof(secondArray[0]);

    int const expected = 14;
    int const actual =
        mxdiflg(firstArray, firstArrayLength, secondArray, secondArrayLength);

    assert_int_equal(expected, actual);
}

static void fourth_test(void** state)
{
    (void)state;

    char const** firstArray = NULL;
    char const* secondArray[] = {"cccooommaaqqoxii",
                                 "gggqaffhhh",
                                 "tttoowwwmmww"};

    size_t const firstArrayLength = 0;
    size_t const secondArrayLength =
        sizeof(secondArray) / sizeof(secondArray[0]);

    int const expected = -1;
    int const actual =
        mxdiflg(firstArray, firstArrayLength, secondArray, secondArrayLength);

    assert_int_equal(expected, actual);
}

static void fifth_test(void** state)
{
    (void)state;

    char const* firstArray[] = {"cccooommaaqqoxii",
                                "gggqaffhhh",
                                "tttoowwwmmww"};
    char const** secondArray = NULL;

    size_t const firstArrayLength = sizeof(firstArray) / sizeof(firstArray[0]);
    size_t const secondArrayLength = 0;

    int const expected = -1;
    int const actual =
        mxdiflg(firstArray, firstArrayLength, secondArray, secondArrayLength);

    assert_int_equal(expected, actual);
}

static void sixth_test(void** state)
{
    (void)state;

    char const** firstArray = NULL;
    char const** secondArray = NULL;

    size_t const firstArrayLength = 0;
    size_t const secondArrayLength = 0;

    int const expected = -1;
    int const actual =
        mxdiflg(firstArray, firstArrayLength, secondArray, secondArrayLength);

    assert_int_equal(expected, actual);
}

int main()
{
    struct CMUnitTest const tests[] = {
        cmocka_unit_test(first_test),
        cmocka_unit_test(second_test),
        cmocka_unit_test(third_test),
        cmocka_unit_test(fourth_test),
        cmocka_unit_test(fifth_test),
        cmocka_unit_test(sixth_test),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
