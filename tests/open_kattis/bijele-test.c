#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "bijele.h"

static void first_test(void **state)
{
    (void)state;

    int input[] = {0, 1, 2, 2, 2, 7};
    int expect[] = {1, 0, 0, 0, 0, 1};
    int *result = bijele(input);
    for (unsigned i = 0; i < 6; i++) {
        assert_int_equal(result[i], expect[i]);
    }
}

static void second_test(void **state)
{
    (void)state;

    int input[] = {2, 1, 2, 1, 2, 1};
    int expect[] = {-1, 0, 0, 1, 0, 7};
    int *result = bijele(input);
    for (unsigned i = 0; i < 6; i++) {
        assert_int_equal(result[i], expect[i]);
    }
}

int main()
{
    const struct CMUnitTest tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
