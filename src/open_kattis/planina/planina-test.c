#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "planina.h"

static void first_test(void **state)
{
    (void)state;

    int result = planina(2);
    assert_int_equal(result, 25);
}

static void second_test(void **state)
{
    (void)state;

    int result = planina(5);
    assert_int_equal(result, 1089);
}

int main()
{
    const struct CMUnitTest tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
