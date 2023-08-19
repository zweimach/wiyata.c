#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "death_knight_hero.h"

static void first_test(void** state)
{
    (void)state;

    char const* input[3] = {"DCOOO", "DODOCD", "COD"};
    int result = death_knight_hero(3, input);
    assert_int_equal(result, 2);
}

static void second_test(void** state)
{
    (void)state;

    char const* input[3] = {"DCOOO", "DODOCOOOD", "COD"};
    int result = death_knight_hero(3, input);
    assert_int_equal(result, 3);
}

int main(void)
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
