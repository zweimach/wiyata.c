#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "cold_puter_science.h"

static void first_test(void** state)
{
    (void)state;

    int input[] = {5, -10, 15};
    unsigned result = cold_puter_science(3, input);
    assert_int_equal(result, 1);
}

static void second_test(void** state)
{
    (void)state;

    int input[] = {-14, -5, -39, -5, -7};
    unsigned result = cold_puter_science(5, input);
    assert_int_equal(result, 5);
}

int main(void)
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
