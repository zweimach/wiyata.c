#ifndef WIYATA_LEETCODE_MERGE_TWO_SORTED_LISTS
#define WIYATA_LEETCODE_MERGE_TWO_SORTED_LISTS

#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);

struct ListNode* list_node_append(struct ListNode* l, int val);

struct ListNode* list_node_new(int n, int l[n]);

void list_node_free(struct ListNode* l);

#define list_node_val(l, v) ((l) ? (l)->val : (v))

#define list_node_create(...)                            \
    list_node_new(sizeof((int[]){__VA_ARGS__})           \
                      / sizeof((int[]){__VA_ARGS__}[0]), \
                  (int[]){__VA_ARGS__})

#endif /* WIYATA_LEETCODE_MERGE_TWO_SORTED_LISTS */
