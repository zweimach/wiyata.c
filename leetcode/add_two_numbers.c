#include <stdbool.h>
#include <stdlib.h>

#include "add_two_numbers.h"

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* result = NULL;
    bool carry = false;

    for (struct ListNode *n1 = l1, *n2 = l2; n1 || n2 || carry;
         n1 = list_node_next(n1), n2 = list_node_next(n2)) {
        int val = list_node_val(n1) + list_node_val(n2);

        if (carry) {
            val += 1;
            carry = false;
        }
        if (val > 9) {
            val %= 10;
            carry = true;
        }
        result = list_node_append(result, val);
    }
    return result;
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

struct ListNode* list_node_append(struct ListNode* l, int val)
{
    struct ListNode* n = malloc(sizeof(struct ListNode));

    *n = (struct ListNode){.next = NULL, .val = val};
    if (!l) {
        l = n;
    } else {
        struct ListNode* p = l;

        while (p->next) {
            p = p->next;
        }
        p->next = n;
    }
    return l;
}
