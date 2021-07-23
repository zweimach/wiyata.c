#ifndef WIYATA_OPEN_KATTIS_KNAPSACK_H
#define WIYATA_OPEN_KATTIS_KNAPSACK_H

struct Item {
    unsigned value;
    unsigned weight;
};

struct Result {
    unsigned total_value;
    unsigned item_capacity;
    unsigned item_count;
    unsigned* items;
};

struct Result* knapsack(unsigned n, struct Item* items[n], unsigned capacity);

struct Item* item_new(unsigned value, unsigned weight);

void item_free(struct Item* it);

struct Result* result_new(int capacity);

struct Result* result_append(struct Result* r, struct Item* it, unsigned i);

void result_free(struct Result* r);

#endif /* WIYATA_OPEN_KATTIS_KNAPSACK_H */
