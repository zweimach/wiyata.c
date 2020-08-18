#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "r2.h"

static void first_test(void** state)
{
    (void)state;

    int result = r2(11, 15);
    assert_int_equal(result, 19);
}

static void second_test(void** state)
{
    (void)state;

    int result = r2(4, 3);
    assert_int_equal(result, 2);
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
