#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "faktor.h"

static void first_test(void** state)
{
    (void)state;

    unsigned result = faktor(38, 24);
    assert_int_equal(result, 875);
}

static void second_test(void** state)
{
    (void)state;

    unsigned result = faktor(1, 100);
    assert_int_equal(result, 100);
}

static void third_test(void** state)
{
    (void)state;

    unsigned result = faktor(10, 10);
    assert_int_equal(result, 91);
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
