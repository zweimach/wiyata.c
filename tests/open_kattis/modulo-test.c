#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "modulo.h"

static void first_test(void **state)
{
    (void)state;

    unsigned input[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    unsigned result = modulo(input);
    assert_int_equal(result, 10);
}

static void second_test(void **state)
{
    (void)state;

    unsigned input[10] = {42, 84, 252, 420, 840, 126, 42, 84, 420, 126};
    unsigned result = modulo(input);
    assert_int_equal(result, 1);
}

static void third_test(void **state)
{
    (void)state;

    unsigned input[10] = {39, 40, 41, 42, 43, 44, 82, 83, 84, 85};
    unsigned result = modulo(input);
    assert_int_equal(result, 6);
}

int main()
{
    const struct CMUnitTest tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
