#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "pot.h"

static void first_test(void** state)
{
    (void)state;

    int input[] = {212, 1253};
    long result = pot(input, 2);
    assert_int_equal(result, 1953566);
}

static void second_test(void** state)
{
    (void)state;

    int input[] = {23, 17, 43, 52, 22};
    long result = pot(input, 5);
    assert_int_equal(result, 102);
}

static void third_test(void** state)
{
    (void)state;

    int input[] = {213, 102, 45};
    long result = pot(input, 3);
    assert_int_equal(result, 10385);
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
