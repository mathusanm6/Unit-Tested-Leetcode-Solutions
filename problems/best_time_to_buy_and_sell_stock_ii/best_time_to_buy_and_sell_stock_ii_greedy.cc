#include "best_time_to_buy_and_sell_stock_ii.h"

#include <algorithm>
#include <cstddef>
#include <vector>

int maxProfit(const std::vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }

    int maxProfit = 0;
    for (size_t i = 1; i < prices.size(); ++i) {
        maxProfit += std::max(0, prices[i] - prices[i - 1]);
    }
    return maxProfit;
}
