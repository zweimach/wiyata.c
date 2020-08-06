#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "quick_brown_fox.h"

static void first_test(void **state)
{
    (void)state;
    char const *input[] = {"The quick brown fox jumps over the lazy dog.",
                           "ZYXW, vu TSR Ponm lkj ihgfd CBA.",
                           ".,?!'\" 92384 abcde FGHIJ"};
    char const *expect[] = {"pangram",
                            "missing eq",
                            "missing klmnopqrstuvwxyz"};
    char const **result = quick_brown_fox(3, input);
    for (int i = 0; i < 3; i++) {
        assert_string_equal(result[i], expect[i]);
    }
    for (int i = 0; i < 3; i++) {
        free((void *)result[i]);
    }
    free((void *)result);
}

int main()
{
    const struct CMUnitTest tests[] = {cmocka_unit_test(first_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
