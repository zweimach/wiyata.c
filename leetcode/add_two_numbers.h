#ifndef WIYATA_LEETCODE_ADD_TWO_NUMBER
#define WIYATA_LEETCODE_ADD_TWO_NUMBER

#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

struct ListNode* list_node_new(int n, int l[n]);

void list_node_free(struct ListNode* l);

struct ListNode* list_node_append(struct ListNode* l, int val);

#define list_node_next(l) ((l) && (l)->next ? (l)->next : NULL)

#define list_node_val(l) ((l) ? (l)->val : 0)

#define list_node_create(...)                            \
    list_node_new(sizeof((int[]){__VA_ARGS__})           \
                      / sizeof((int[]){__VA_ARGS__}[0]), \
                  (int[]){__VA_ARGS__})

#endif /* WIYATA_LEETCODE_ADD_TWO_NUMBER */
