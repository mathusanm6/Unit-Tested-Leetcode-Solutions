#include "best_time_to_buy_and_sell_stock_ii.h"

#include <algorithm>
#include <vector>

int maxProfit(const std::vector<int>& prices) {
    int hold = -prices[0];
    int nextHold = 0;
    int sell = 0;
    int nextSell = 0;
    for (const int price : prices) {
        nextHold = std::max(hold, sell - price);
        nextSell = std::max(sell, hold + price);
        hold = nextHold;
        sell = nextSell;
    }
    return sell;
}
