#include <assert.h>
#include <stdlib.h>

#include "reverse_linked_list.h"

struct ListNode* reverseList(struct ListNode* head)
{
    if (!head) {
        return NULL;
    }
    struct ListNode* new_head = NULL;
    rev_list(head, &new_head);
    return new_head;
}

void rev_list(struct ListNode* head, struct ListNode** new_head)
{
    if (!head) {
        return;
    }
    if (head->next) {
        rev_list(head->next, new_head);
    }
    if (!(*new_head)) {
        *new_head = head;
        (*new_head)->next = NULL;
        return;
    }
    struct ListNode *p = *new_head, *q = p;
    while ((p = p->next)) {
        q = p;
    }
    q->next = head;
    q->next->next = NULL;
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
