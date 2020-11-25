#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "add_two_numbers.h"

static void first_test(void** state)
{
    (void)state;

    struct ListNode* input[] = {list_node_create(2, 4, 3),
                                list_node_create(5, 6, 4)};
    struct ListNode* expected = list_node_create(7, 0, 8);
    struct ListNode* result = add_two_numbers(input[0], input[1]);
    for (struct ListNode *r = result, *e = expected; e;
         r = r->next, e = e->next) {
        assert_int_equal(r->val, e->val);
    }
    list_node_free(input[0]);
    list_node_free(input[1]);
    list_node_free(expected);
    list_node_free(result);
}

static void second_test(void** state)
{
    (void)state;

    struct ListNode* input[] = {list_node_create(0), list_node_create(0)};
    struct ListNode* expected = list_node_create(0);
    struct ListNode* result = add_two_numbers(input[0], input[1]);
    for (struct ListNode *r = result, *e = expected; e;
         r = r->next, e = e->next) {
        assert_int_equal(r->val, e->val);
    }
    list_node_free(input[0]);
    list_node_free(input[1]);
    list_node_free(expected);
    list_node_free(result);
}

static void third_test(void** state)
{
    (void)state;

    struct ListNode* input[] = {list_node_create(9, 9, 9, 9, 9, 9, 9),
                                list_node_create(9, 9, 9, 9)};
    struct ListNode* expected =
        list_node_new(8, (int[]){8, 9, 9, 9, 0, 0, 0, 1});
    struct ListNode* result = add_two_numbers(input[0], input[1]);
    for (struct ListNode *r = result, *e = expected; e;
         r = r->next, e = e->next) {
        assert_int_equal(r->val, e->val);
    }
    list_node_free(input[0]);
    list_node_free(input[1]);
    list_node_free(expected);
    list_node_free(result);
}

static void fourth_test(void** state)
{
    (void)state;

    struct ListNode* input[] = {list_node_create(1, 9, 9, 9, 9, 9, 9, 9, 9),
                                list_node_create(9)};
    struct ListNode* expected = list_node_create(0, 0, 0, 0, 0, 0, 0, 0, 0, 1);
    struct ListNode* result = add_two_numbers(input[0], input[1]);
    for (struct ListNode *r = result, *e = expected; e;
         r = r->next, e = e->next) {
        assert_int_equal(r->val, e->val);
    }
    list_node_free(input[0]);
    list_node_free(input[1]);
    list_node_free(expected);
    list_node_free(result);
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test),
                                       cmocka_unit_test(fourth_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
