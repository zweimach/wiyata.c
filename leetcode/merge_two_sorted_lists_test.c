#include <setjmp.h>
#include <stdarg.h>
#include <stdlib.h>

#include <cmocka.h>

#include "merge_two_sorted_lists.h"

static void first_test(void** state)
{
    (void)state;

    struct ListNode* list1 = list_node_create(1, 2, 4);
    struct ListNode* list2 = list_node_create(1, 3, 4);
    struct ListNode* expected = list_node_create(1, 1, 2, 3, 4, 4);

    struct ListNode* result = mergeTwoLists(list1, list2);
    for (struct ListNode *r = result, *e = expected; r && e;
         r = r->next, e = e->next) {
        assert_int_equal(r->val, e->val);
    }

    list_node_free(list1);
    list_node_free(list2);
    list_node_free(expected);
    list_node_free(result);
}

static void second_test(void** state)
{
    (void)state;

    struct ListNode* list1 = NULL;
    struct ListNode* list2 = NULL;

    struct ListNode* result = mergeTwoLists(list1, list2);
    assert_null(result);
}

static void third_test(void** state)
{
    (void)state;

    struct ListNode* list1 = NULL;
    struct ListNode* list2 = list_node_create(0);
    struct ListNode* expected = list_node_create(0);

    struct ListNode* result = mergeTwoLists(list1, list2);
    for (struct ListNode *r = result, *e = expected; e;
         r = r->next, e = e->next) {
        assert_int_equal(r->val, e->val);
    }

    list_node_free(expected);
    list_node_free(result);
}

int main(void)
{
    struct CMUnitTest const tests[] = {cmocka_unit_test(first_test),
                                       cmocka_unit_test(second_test),
                                       cmocka_unit_test(third_test)};

    return cmocka_run_group_tests(tests, NULL, NULL);
}
