#include "candy.h"

#include <algorithm>
#include <numeric>
#include <vector>

int candy(std::vector<int>& ratings) {
    const int n = static_cast<int>(ratings.size());
    std::vector<int> candies(n, 1);

    // 1. Left-to-right pass
    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // 2. Right-to-left pass
    for (int i = n - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = std::max(candies[i], candies[i + 1] + 1);
        }
    }

    return std::accumulate(candies.begin(), candies.end(), 0);
}
