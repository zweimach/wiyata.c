#ifndef WIYATA_LEETCODE_ADD_TWO_NUMBER_H
#define WIYATA_LEETCODE_ADD_TWO_NUMBER_H

#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* add_two_numbers(struct ListNode* l1, struct ListNode* l2);

struct ListNode* list_node_new(int n, int l[n]);

void list_node_free(struct ListNode* l);

struct ListNode* list_node_append(struct ListNode* l, int val);

bool list_node_valid(struct ListNode* l);

struct ListNode* list_node_next(struct ListNode* l);

int list_node_val(struct ListNode* l);

#define list_node_create(...)                            \
    list_node_new(sizeof((int[]){__VA_ARGS__})           \
                      / sizeof((int[]){__VA_ARGS__}[0]), \
                  (int[]){__VA_ARGS__})

#endif /* WIYATA_LEETCODE_ADD_TWO_NUMBER_H */
