#include "jump_game.h"

#include <algorithm>
#include <vector>

bool canJump(std::vector<int> &nums) {
    const int n = static_cast<int>(nums.size());
    if (n == 0) {
        return true;
    }

    std::vector<bool> dp(n, false);
    dp[n - 1] = true;

    for (int i = n - 2; i >= 0; --i) {
        const int maxJump = std::min(i + nums[i], n - 1);
        for (int j = i + 1; j <= maxJump; ++j) {
            if (dp[j]) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[0];
}
