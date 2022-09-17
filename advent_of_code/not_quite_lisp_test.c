#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "not_quite_lisp.h"

static char const* TEST_CASE =
    "()(((()))(()()()((((()(((())(()(()((((((()(()(((())))((()(((()))((())(()(("
    "()()()()(((())(((((((())))()()(()(()(())(((((()()()((())(((((()()))))()(()"
    ")(((())(())((((((())())))(()())))()))))()())()())((()()((()()()()(()(((((("
    "((()()())((()()(((((()(((())((())(()))()((((()((((((((())()((()())(())((()"
    "))())((((()())(((((((((((()()(((((()(()))())(((()(()))())((()(()())())())("
    "()(((())(())())()()(()(()((()))((()))))((((()(((()))))((((()(()(()())())()"
    "(((()((((())((((()(((()()(())()()()())((()((((((()((()()))()((()))()(()()("
    "(())))(((()(((()))((()((()(()))(((()()(()(()()()))))()()(((()(((())())))))"
    "((()(((())()(()(())((()())))((((())))(()(()(()())()((()())))(((()((()(())("
    ")()((()((())(()()((())(())()))()))((()(())()))())(((((((()(()()(()(())()))"
    ")))))(()((((((())((((())((())())(()()))))()(())(()())()())((())(()))))(())"
    ")(()((()))()(()((((((()()()()((((((((()(()(())((()()(()()))(())()())()((()"
    ")))()))()())(((()))(())()(())()))()((()((()(()()())(())()()()((())())))((("
    ")()(()()((()(())()()())(((()(()()))))(())))(()(()())()))()()))))))()))))(("
    "((((())))())))(()(())())(()())))))(()))()))))))()((()))))()))))(()(()((()("
    "))())(()()))))(((())()))())())())(((()(()()))(())()(())(())((((((()()))))("
    "(()(()))))))(()))())(((()()(()))()())()()()())))))))))))))(())(()))(()))(("
    "()(())(()())(())())(()())(())()()(()())))()()()))(())())()))())())(())((()"
    ")))))))(())))(())))))()))))((())(()(((()))))(()))()((()(())))(()())(((((()"
    "))()())()()))))()))))()))())(()(()()()))()))))))((()))))))))))()((()))((()"
    "(())((())()()(()()))()(()))))()()(()))()))(((())))(())()((())(())(()())()("
    "))())))))))())))()((())))()))(()))()()))(((((((()))())(()()))(()()(()))()("
    "()((()())()))))))(((()()()())))(())()))()())(()()))()()))))))))(())))()))("
    ")()))))))()))()())))()(())(())))))()(())()()(()()))))())((()))))()))))(()("
    "((((()))))))))())))())()(())()()))))(())))())()()())()()())()(()))))()))()"
    "))))))))())))((()))()))()))())))()())()()())))())))(()((())()((()))())))))"
    "())()(())((())))))))))))())()())(())())())(()))(()))()))())(()(())())()())"
    "()()(()))))(()(())))))))(())))())(())))))))())()()(())())())))(())))))()))"
    "()(()())()(()))())())))))()()(()))()))))())))))))))()))))()))))))())()())("
    ")()))))()())))())))))))))))()()))))()()(((()))()()(())()))))((()))))(()))("
    "())())))(())()))))))(()))()))))(())())))))()))(()())))))))))))))()))))))))"
    ")()((()())(()())))))))((()))))(())(())))()(()())())))())())(()()()())))())"
    ")))))())))))())()()())))))))))))()()(()))))()())()))((()())(()))))()(())))"
    ")))))))()())())(((())(()))))())()))()))()))))))()))))))(()))))()))))()(())"
    "))(())))(()))())()()(()()))()))(()()))))))))()))(()))())(()()(()(()())()()"
    "))()))))))))(())))))((()()(()))())())))))()))())(()())()()))())))()(()()()"
    "()))((())())))())()(()()))()))))))))(()))(())))()))))(()(()())(()))))()())"
    "())()))()()))())))))))))))())()))))))()))))))))())))))()))))())(()())))(()"
    ")()))())())))))()()(()()())(()())))()()))(((()))(()()()))))()))))()))))((("
    "))))()((((((()()))))))())))))))))))(((()))))))))))))(())())))))())(())))))"
    ")(()))((()))())))()(()((()))()))()))))))))))())()))()(()()))))())))())(())"
    "()(()))()))())(()))()))))(()()))()()(())))))()))(())(()(()()))(()()())))))"
    "(((()))))))()))))))))))))(())(()))))()())())()()((()()))())))))(()))))()))"
    ")))))()()()))))))))())))()(((()()))(())))))(((())())))))((()))()(()))(()))"
    "))(()())))(()))())))))()))))(())(())))()((()))(())())))()()))()))))))))())"
    ")(()()()(()()()(()))())(())()())(((()))(())))))))))(((()())))()()))))))))("
    ")(())(()))()((((())(())(()())))()))(((())()()()))((()))(()))())())))())))("
    "()))())()())())(()(())())()()()(())))())(())))(())))(())()))()))(()((())))"
    ")))))())(()))))))())(()()))()()))()(()(()())))()()(()((()((((((()))(())))("
    ")()()))())()))((()()(()))())((()(()(()))(()()))))()())))()))()())))))))()("
    ")((()())(())))()))(()))(())(()))())(()(())))()()))))))(((()(((()()))()(()("
    "())())((()()))()))()))()))()(()()()(()))((()())()(())))()()))(((())()()())"
    "(())()((()()()()(()(())(()()))()(((((()())))((())))))(()()()))))(((()(()))"
    ")()))((()((()(())()(()((())))((()())()(()))(((()())()()(()))(())(((()((()("
    "))()((())()())(((()()))((()((())(()))(()())(()()()))((()))(())(()((()()())"
    "((()))(())))(())(())(())))(()())))(((((()(()(((((()())((((()(()())(())(()("
    ")(((())((()(((()()(((()()((((((())))())(()((((((()(()))()))()()((()((())))"
    ")()(()()(()((()()))))))(((((()(((((())()()()(())())))))))()))((()()(())))("
    "())(()()()())))))(()((((())))))))()()(((()(()(()(()(()())()()()(((((((((()"
    "()())()(()))((()()()()()(((((((()())()((())()))((((((()(()(()(()())(((()(("
    "(((((()(((())(((((((((())(())())()))((()(()))(((()()())(())(()(()()(((()(("
    "))()))())))(())((((((())(()()())()()(((()(((())(()(((())(((((((()((((((((("
    "()))(())(()(()(()))))((()))()(())())())((()(()((()()))((()()((()(())(())(("
    ")((())(((())(((()()()((((((()()(())((((())()))))(())((()(()((())))(((((()("
    "()()())())((())())))((())((()((()()((((((())(((()()(()())())(()(()))(()(()"
    "))())())()(((((((()(((()(())()()((())((()(()()((()(()()(((((((((((())((())"
    "((((((())((()((((()(()((((()(((((((())()((()))))())()((()((((()(()(((()((("
    ")())))(())())(((()(((())((((((()(((((((((()()(())))(()(((((()((((()())))(("
    "()((()((()(()()(((())((((((((((((()(((())(()(((((()))(()()(()()()()()()((("
    "))(((((((())(((((())))))())()(()()(()(()(((()()(((((())(()((()((()(((()()("
    "(()((((())()))()((((())(())))()())(((())(())(()()((()(((()()((((((((((()()"
    "(()())())(((((((((())((((()))()()((((())(()((((()(((())())(((((((((((()((("
    "(())))(())(()(((()(((()((())(((((()((()()(()(()()((((((()((((()((()(()((()"
    "(()((((((()))))()()(((((()((()(()(())()))(())(((((((()((((()())(()((()((()"
    "(()))())))(())((()))))(((((((()()()())(()))(()()((()())()((()((()()()(()(("
    ")()))(()())(())(((((()(((((((((((()((()(((()(((((((()()((((((()(((((()(()("
    "(()(((((())((((((()))((((())((()()((())(((())()(((((()()(((((()((()(()(((("
    "(((()(((((()((()((()((())(())((())(()))()()))(()()(()(()()(((((((()(((()(("
    "(())()(((((()((((((()())((((())()((()((()(()()())(()))((((()()((((((()((()"
    "(()(()((((()((()((())((((((()(()(())((((((()((((((((((()((())()))()(()(()("
    "((((()()()))((())))()(()((((((((((((((()(((()((((()((())((()((()(((()()(()"
    "(((()((())(()()())))()(()(()(((((()()(()(()((((()(((((())()(()(()))(((((()"
    "()(((()()(())((((((((((((((())((())(((((((((((())()()()(())()(()(()((((((("
    "((())(((()))(()()())(()((((()(())(((((()())(())((((((((())()((((()((((((()"
    ")(()((()(())(((()((((()))(((((((((()()))((((()(())()()()(())(()((())((()()"
    "))()(((())(((((())((((((()()))(((((((((()((((((())))(((((((()((()(()(())))"
    "())(()(()))()(((((()())(()))()(()(())(((()))))())()())))(((((()))())()((()"
    "(()))))((()()()((((((()))()()((((((((())((()(()(((()(()((())((()())(()(((("
    "())(()(((()()()(()(()()))())())((((((((((())())((()))()((())(())(())))())("
    ")(()()(())))())(()))(((()(()()(((()(((())))()(((()(())()((((((())()))()))("
    ")((((((()(()(((((()())))()))))())()()(((()(((((())((()()(()((()((()(()(()("
    "())))(()()()()((()(())(((()((()))((((()))())(())))())(()))()()()())()))((("
    "()()())()((())))(())(()()()()(()())((()(()()((((())))((()((()(())((()(()(("
    "())()(()()(((()())()()())((()))((())(((()()(())))()()))(((()((())()(((((()"
    "())(())((())()())())((((((()(()(((((()))(()(";

static void first_test(void** state)
{
    (void)state;

    int result = not_quite_lisp("(()(()(");
    assert_int_equal(result, 3);
}

static void second_test(void** state)
{
    (void)state;

    int result = not_quite_lisp(TEST_CASE);
    assert_int_equal(result, 138);
}

static void third_test(void** state)
{
    (void)state;

    unsigned result = not_quite_lisp_part_two(")()(");
    assert_int_equal(result, 1);
}

static void fourth_test(void** state)
{
    (void)state;

    unsigned result = not_quite_lisp_part_two(TEST_CASE);
    assert_int_equal(result, 1771);
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test),
                                       cmocka_unit_test(fourth_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}