#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <cmocka.h>

#include "reverse_list_recursively.h"

static void first_test(void** state)
{
    (void)state;

    int* result = revR((int[]){2, 5, 1}, 3);
    assert_true(!memcmp(result, (int[]){1, 5, 2}, 3 * sizeof(int)));
}

static void second_test(void** state)
{
    (void)state;

    int* result = revR((int[]){1, 2}, 2);
    assert_true(!memcmp(result, (int[]){2, 1}, 2 * sizeof(int)));
}

static void third_test(void** state)
{
    (void)state;

    int* result = revR((int[]){1, 2, 3, 4, 5, 6}, 6);
    assert_true(!memcmp(result, (int[]){6, 5, 4, 3, 2, 1}, 6 * sizeof(int)));
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
