#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "nasty_hacks.h"

static void first_test(void** state)
{
    (void)state;

    unsigned input[3][3] = {{0, 100, 70}, {100, 130, 30}, {-100, -70, 40}};
    char const* expect[] = {"advertise", "does not matter", "do not advertise"};
    char const** result = nasty_hacks(3, input);
    for (int i = 0; i < 3; i++) {
        assert_string_equal(result[i], expect[i]);
    }
    for (int i = 0; i < 3; i++) {
        free((void*)result[i]);
    }
    free((void*)result);
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
