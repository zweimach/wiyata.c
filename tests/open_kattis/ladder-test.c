#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "ladder.h"

static void first_test(void **state)
{
    (void)state;

    unsigned result = ladder(500, 70);
    assert_int_equal(result, 533);
}

static void second_test(void **state)
{
    (void)state;

    unsigned result = ladder(1000, 10);
    assert_int_equal(result, 5759);
}

int main()
{
    const struct CMUnitTest tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}