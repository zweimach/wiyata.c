#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#include "best_time_to_buy_and_sell_stock.h"

#define maximum(a, b) ((a) > (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize)
{
    while (pricesSize > 2) {
        if (prices[0] < prices[1]) {
            break;
        }
        prices++;
        pricesSize--;
    }
    while (pricesSize > 2) {
        if (prices[pricesSize - 1] != 0) {
            break;
        }
        pricesSize--;
    }
    int max = 0, min = INT_MAX, idx = 0, profit = 0;
    for (int i = 0; i < pricesSize - 1; i++) {
        if (prices[i] < min) {
            min = prices[i];
            idx = i;
        }
    }
    for (int i = idx + 1; i < pricesSize; i++) {
        if (prices[i] > max) {
            max = prices[i];
        }
    }
    profit = maximum(profit, max - min);
    max = 0, min = INT_MAX;
    for (int i = pricesSize - 1; i > 0; i--) {
        if (prices[i] > max) {
            max = prices[i];
            idx = i;
        }
    }
    for (int i = 0; i < idx; i++) {
        if (prices[i] < min) {
            min = prices[i];
        }
    }
    profit = maximum(profit, max - min);
    return profit;
}
