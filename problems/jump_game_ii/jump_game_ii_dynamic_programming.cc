#include "jump_game_ii.h"

#include <algorithm>
#include <climits>
#include <vector>

int jump(std::vector<int> &nums) {
    const int n = static_cast<int>(nums.size());
    if (n <= 1) {
        return 0;
    }

    // dp[i] = minimum jumps needed from index i to reach the end
    std::vector<int> dp(n, INT_MAX);
    dp[n - 1] = 0;

    for (int i = n - 2; i >= 0; --i) {
        if (nums[i] == 0) {
            continue;
        }
        const int maxReach = std::min(i + nums[i], n - 1);
        int minJumps = INT_MAX;
        for (int j = i + 1; j <= maxReach; ++j) {
            minJumps = std::min(minJumps, dp[j]);
        }
        if (minJumps != INT_MAX) {
            dp[i] = 1 + minJumps;
        }
    }

    return dp[0];
}
