#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "string_repeat.h"

static void first_test(void** state)
{
    (void)state;

    char* result = repeat_str(4, "a");
    assert_string_equal(result, "aaaa");
    free((void*)result);
}

static void second_test(void** state)
{
    (void)state;

    char* result = repeat_str(3, "hello ");
    assert_string_equal(result, "hello hello hello ");
    free((void*)result);
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
