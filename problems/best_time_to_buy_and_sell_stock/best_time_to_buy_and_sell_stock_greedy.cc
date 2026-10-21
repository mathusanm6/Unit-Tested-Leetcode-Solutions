#include "best_time_to_buy_and_sell_stock.h"

#include <algorithm>
#include <limits>
#include <vector>

int maxProfit(const std::vector<int>& prices) {
    int minPrice = std::numeric_limits<int>::max();
    int bestPrice = 0;
    for (const int price : prices) {
        bestPrice = std::max(bestPrice, price - minPrice);
        minPrice = std::min(minPrice, price);
    }
    return bestPrice;
}
