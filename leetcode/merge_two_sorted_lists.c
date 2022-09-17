#include <limits.h>
#include <stdlib.h>

#include "merge_two_sorted_lists.h"

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if (!list1 && !list2) {
        return NULL;
    }
    if (!list1) {
        return list2;
    }
    if (!list2) {
        return list1;
    }
    struct ListNode *result = NULL, *n1 = list1, *n2 = list2;
    while (n1 || n2) {
        int val;
        int v1 = list_node_val(n1, INT_MAX);
        int v2 = list_node_val(n2, INT_MAX);
        if (v1 <= v2) {
            val = v1;
            n1 = n1->next;
        } else {
            val = v2;
            n2 = n2->next;
        }
        result = list_node_append(result, val);
    }
    return result;
}

struct ListNode* list_node_append(struct ListNode* l, int val)
{
    struct ListNode* n = calloc(sizeof(struct ListNode), 1);
    n->val = val;
    if (!l) {
        return n;
    }
    struct ListNode* p = l;
    while (p->next) {
        p = p->next;
    }
    p->next = n;
    return l;
}

struct ListNode* list_node_new(int n, int l[n])
{
    struct ListNode* result = NULL;
    for (int i = 0; i < n; i++) {
        result = list_node_append(result, l[i]);
    }
    return result;
}

void list_node_free(struct ListNode* l)
{
    while (l) {
        struct ListNode* p = l->next;
        free(l);
        l = p;
    }
}
