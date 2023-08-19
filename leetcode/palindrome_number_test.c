#include <setjmp.h>
#include <stdarg.h>
#include <stdlib.h>

#include <cmocka.h>

#include "palindrome_number.h"

static void first_test(void** state)
{
    (void)state;

    assert_true(isPalindrome(121));
}

static void second_test(void** state)
{
    (void)state;

    assert_false(isPalindrome(-121));
}

static void third_test(void** state)
{
    (void)state;

    assert_false(isPalindrome(10));
}

int main(void)
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
