#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "counting_valleys.h"

static void first_test(void** state)
{
    (void)state;

    int result = countingValleys(8, "UDDDUDUU");
    assert_int_equal(result, 1);
}

static void second_test(void** state)
{
    (void)state;

    int result = countingValleys(12, "DDUUDDUDUUUD");
    assert_int_equal(result, 2);
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
