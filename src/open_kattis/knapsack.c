#include <math.h>
#include <stdlib.h>

#include "knapsack.h"

struct Result* knapsack(unsigned n, struct Item* items[n], unsigned capacity)
{
    unsigned rows = n + 1, cols = capacity + 1;
    unsigned** memo = calloc(rows, sizeof(unsigned*));
    for (unsigned i = 0; i < rows; i++) {
        memo[i] = calloc(cols, sizeof(unsigned));
    }

    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 1; j < cols; j++) {
            struct Item* const it = items[i];
            if (it->weight > j) {
                memo[i + 1][j] = memo[i][j];
            } else {
                memo[i + 1][j] =
                    fmax(memo[i][j], memo[i][j - it->weight] + it->value);
            }
        }
    }

    struct Result* result = result_new(n);
    unsigned left = capacity;
    for (int i = n - 1; i >= 0; i--) {
        if (memo[i + 1][left] != memo[i][left]) {
            result = result_append(result, items[i], i);
            left -= items[i]->weight;
        }
    }

    for (unsigned i = 0; i < rows; i++) {
        free(memo[i]);
    }
    free(memo);
    return result;
}

struct Item* item_new(unsigned value, unsigned weight)
{
    struct Item* it = malloc(sizeof(struct Item));

    if (it) {
        it->value = value;
        it->weight = weight;
    }
    return it;
}

void item_free(struct Item* it)
{
    if (it) {
        free(it);
    }
}

struct Result* result_new(int capacity)
{
    struct Result* r = malloc(sizeof(struct Result));

    if (r) {
        r->total_value = 0;
        r->item_count = 0;
        r->item_capacity = capacity;
        r->items = calloc(capacity, sizeof(unsigned));
    }
    return r;
}

struct Result* result_append(struct Result* r, struct Item* it, unsigned index)
{
    if (it && r && r->items && r->item_capacity > r->item_count) {
        r->items[r->item_count] = index;
        r->item_count += 1;
        r->total_value += it->value;
    }
    return r;
}

void result_free(struct Result* r)
{
    if (r && r->items) {
        free(r->items);
    }
    if (r) {
        free(r);
    }
}
