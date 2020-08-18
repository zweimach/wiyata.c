#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "quadrant_selection.h"

static void first_test(void** state)
{
    (void)state;

    unsigned result = quadrant_selection(10, 6);
    assert_int_equal(result, 1);
}

static void second_test(void** state)
{
    (void)state;

    unsigned result = quadrant_selection(9, -13);
    assert_int_equal(result, 4);
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
