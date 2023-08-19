#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include <cmocka.h>

#include "reverse_linked_list.h"

static void first_test(void** state)
{
    (void)state;

    struct ListNode* input = list_node_create(1, 2, 3, 4, 5);
    struct ListNode* expected = list_node_create(5, 4, 3, 2, 1);
    struct ListNode* result = reverseList(input);
    assert_non_null(result);
    for (struct ListNode *r = result, *e = expected; e;
         r = r->next, e = e->next) {
        assert_int_equal(r->val, e->val);
    }
    list_node_free(expected);
    list_node_free(result);
}

static void second_test(void** state)
{
    (void)state;

    struct ListNode* input = list_node_create(1, 2);
    struct ListNode* expected = list_node_create(2, 1);
    struct ListNode* result = reverseList(input);
    assert_non_null(result);
    for (struct ListNode *r = result, *e = expected; e;
         r = r->next, e = e->next) {
        assert_int_equal(r->val, e->val);
    }
    list_node_free(expected);
    list_node_free(result);
}

static void third_test(void** state)
{
    (void)state;

    struct ListNode* input = NULL;
    struct ListNode* result = reverseList(input);
    assert_null(result);
}

int main()
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
