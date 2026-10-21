#include "best_time_to_buy_and_sell_stock.h"

#include <algorithm>
#include <vector>

int maxProfit(const std::vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }
    int hold = -prices[0];
    int nextHold = 0;
    int sell = 0;
    int nextSell = 0;
    for (const int price : prices) {
        nextHold = std::max(hold, -price);
        nextSell = std::max(sell, hold + price);
        hold = nextHold;
        sell = nextSell;
    }
    return sell;
}
